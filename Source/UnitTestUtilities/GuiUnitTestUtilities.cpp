#include "GuiUnitTestUtilities.h"
#include "../PlatformProviders/Remote/GuiRemoteProtocol.h"
#include "../Resources/GuiParserManager.h"
#include "../Reflection/GuiInstanceCompiledWorkflow.h"

namespace vl::presentation::controls
{
	extern bool GACUI_UNITTEST_ONLY_SKIP_THREAD_LOCAL_STORAGE_DISPOSE_STORAGES;
	extern bool GACUI_UNITTEST_ONLY_SKIP_TYPE_AND_PLUGIN_LOAD_UNLOAD;
}

namespace vl::presentation::unittest
{
	const UnitTestFrameworkConfig*			globalUnitTestFrameworkConfig = nullptr;

	const UnitTestFrameworkConfig& GetUnitTestFrameworkConfig()
	{
		CHECK_ERROR(globalUnitTestFrameworkConfig, L"vl::presentation::unittest::GetUnitTestFrameworkConfig()#GacUIUnitTest_Initialize has not been called.");
		return *globalUnitTestFrameworkConfig;
	}
}

using namespace vl;
using namespace vl::collections;
using namespace vl::filesystem;
using namespace vl::reflection::description;
using namespace vl::glr::json;
using namespace vl::presentation;
using namespace vl::presentation::remoteprotocol;
using namespace vl::presentation::controls;
using namespace vl::presentation::unittest;

class UnitTestContextImpl : public Object, public virtual IUnitTestContext
{
	UnitTestRemoteProtocol*		protocol = nullptr;

public:
	UnitTestContextImpl(UnitTestRemoteProtocol* _protocol)
		: protocol(_protocol)
	{
	}

	UnitTestRemoteProtocol* GetProtocol()
	{
		return protocol;
	}
};

UnitTestMainFunc guiMainProxy;
UnitTestContextImpl* guiMainUnitTestContext = nullptr;

void GacUIUnitTest_Initialize(const UnitTestFrameworkConfig* config)
{
	CHECK_ERROR(config, L"GacUIUnitTest_Initialize()#Argument config should not be null.");
	globalUnitTestFrameworkConfig = config;

	GACUI_UNITTEST_ONLY_SKIP_THREAD_LOCAL_STORAGE_DISPOSE_STORAGES = true;
	GACUI_UNITTEST_ONLY_SKIP_TYPE_AND_PLUGIN_LOAD_UNLOAD = true;

	GetGlobalTypeManager()->Load();
	GetPluginManager()->Load(true, false);
}

void GacUIUnitTest_Finalize()
{
	ResetGlobalTypeManager();
	GetPluginManager()->Unload(true, false);
	DestroyPluginManager();
	ThreadLocalStorage::DisposeStorages();

	GACUI_UNITTEST_ONLY_SKIP_THREAD_LOCAL_STORAGE_DISPOSE_STORAGES = false;
	GACUI_UNITTEST_ONLY_SKIP_TYPE_AND_PLUGIN_LOAD_UNLOAD = false;
	globalUnitTestFrameworkConfig = nullptr;
}

void GacUIUnitTest_SetGuiMainProxy(const UnitTestMainFunc& proxy)
{
	guiMainProxy = proxy;
}

void GacUIUnitTest_LinkGuiMainProxy(const UnitTestLinkFunc& proxy)
{
	auto previousMainProxy = guiMainProxy;
	GacUIUnitTest_SetGuiMainProxy([=](UnitTestRemoteProtocol* protocol, IUnitTestContext* context)
	{
		proxy(protocol, context, previousMainProxy);
	});
}

File GacUIUnitTest_PrepareSnapshotFile(const WString& appName, const WString& extension)
{
#define ERROR_MESSAGE_PREFIX L"GacUIUnitTest_PrepareSnapshotFile(const WString&, const WString&)#"
	Folder snapshotFolder = GetUnitTestFrameworkConfig().snapshotFolder;
	CHECK_ERROR(snapshotFolder.Exists(), ERROR_MESSAGE_PREFIX L"UnitTestFrameworkConfig::snapshotFolder does not point to an existing folder.");

	File snapshotFile = snapshotFolder.GetFilePath() / (appName + extension);
	{
		auto pathPrefix = snapshotFolder.GetFilePath().GetFullPath() + WString::FromChar(FilePath::Delimiter);
		auto snapshotPath = snapshotFile.GetFilePath().GetFullPath();
		CHECK_ERROR(
			snapshotPath.Length() > pathPrefix.Length() && snapshotPath.Left(pathPrefix.Length()) == pathPrefix,
			ERROR_MESSAGE_PREFIX L"Argument appName should specify a file that is inside UnitTestFrameworkConfig::snapshotFolder"
			);
		Folder snapshotFileFolder = snapshotFile.GetFilePath().GetFolder();
		if (!snapshotFileFolder.Exists())
		{
			CHECK_ERROR(snapshotFileFolder.Create(true), ERROR_MESSAGE_PREFIX L"Failed to create the folder to contain the snapshot file specified by argument appName.");
		}
	}

	return snapshotFile;
#undef ERROR_MESSAGE_PREFIX
}

void GacUIUnitTest_WriteSnapshotFileIfChanged(File& snapshotFile, const WString& textLog)
{
#define ERROR_MESSAGE_PREFIX L"GacUIUnitTest_WriteSnapshotFileIfChanged(File&, const WString&)#"
	bool skipWriting = false;
	if (snapshotFile.Exists())
	{
		auto previousLog = snapshotFile.ReadAllTextByBom();
		if (previousLog == textLog)
		{
			skipWriting = true;
		}
	}
	if (!skipWriting)
	{
		bool succeeded = snapshotFile.WriteAllText(textLog, true, stream::BomEncoder::Utf8);
		CHECK_ERROR(succeeded, ERROR_MESSAGE_PREFIX L"Failed to write the snapshot file.");
	}
#undef ERROR_MESSAGE_PREFIX
}

void GacUIUnitTest_Start(const WString& appName, Nullable<UnitTestScreenConfig> config)
{
#define ERROR_MESSAGE_PREFIX L"GacUIUnitTest_Start(const WString&, Nullable<UnitTestScreenConfig>)#"
	UnitTestScreenConfig globalConfig;
	if (config)
	{
		globalConfig = config.Value();
	}
	else
	{
		globalConfig.FastInitialize(1024, 768);
	}

	UnitTestRemoteProtocol unitTestProtocol(appName, globalConfig);
	repeatfiltering::GuiRemoteProtocolFilterVerifier verifierProtocol(unitTestProtocol.GetProtocol());
	repeatfiltering::GuiRemoteProtocolFilter filteredProtocol(&verifierProtocol);

	UnitTestContextImpl unitTestContext(&unitTestProtocol);
	guiMainUnitTestContext = &unitTestContext;
	SetupRemoteNativeController(&filteredProtocol);
	GacUIUnitTest_SetGuiMainProxy({});

	{
		File snapshotFile = GacUIUnitTest_PrepareSnapshotFile(appName, WString::Unmanaged(L".json"));

		JsonFormatting formatting;
		formatting.spaceAfterColon = true;
		formatting.spaceAfterComma = true;
		formatting.crlf = true;
		formatting.compact = true;

		auto jsonLog = remoteprotocol::ConvertCustomTypeToJson(unitTestProtocol.GetLoggedTrace());
		auto textLog = JsonToString(jsonLog, formatting);
		{
			remoteprotocol::RenderingTrace deserialized;
			remoteprotocol::ConvertJsonToCustomType(jsonLog, deserialized);
			auto jsonLog2 = remoteprotocol::ConvertCustomTypeToJson(deserialized);
			auto textLog2 = JsonToString(jsonLog2, formatting);
			CHECK_ERROR(textLog == textLog2, ERROR_MESSAGE_PREFIX L"Serialization and deserialization doesn't match.");
		}

		GacUIUnitTest_WriteSnapshotFileIfChanged(snapshotFile, textLog);
	}

	{
		File snapshotFile = GacUIUnitTest_PrepareSnapshotFile(appName, WString::Unmanaged(L"[commands].txt"));

		JsonFormatting formatting;
		formatting.spaceAfterColon = true;
		formatting.spaceAfterComma = true;
		formatting.crlf = false;
		formatting.compact = true;

		auto textLog = stream::GenerateToStream([&unitTestProtocol, &formatting](stream::TextWriter& writer)
		{
			auto&& loggedFrames = unitTestProtocol.GetLoggedFrames();
			for (auto loggedFrame : loggedFrames)
			{
				writer.WriteLine(L"========================================");
				writer.WriteLine(itow(loggedFrame->frameId));
				writer.WriteLine(L"========================================");
				for (auto&& commandLog : loggedFrame->renderingCommandsLog)
				{
					writer.WriteLine(commandLog);
				}
			};
		});

		GacUIUnitTest_WriteSnapshotFileIfChanged(snapshotFile, textLog);
	}

	{
		File snapshotFile = GacUIUnitTest_PrepareSnapshotFile(appName, WString::Unmanaged(L"[diffs].txt"));

		JsonFormatting formatting;
		formatting.spaceAfterColon = true;
		formatting.spaceAfterComma = true;
		formatting.crlf = false;
		formatting.compact = true;

		auto textLog = stream::GenerateToStream([&unitTestProtocol, &formatting](stream::TextWriter& writer)
		{
			Ptr<RenderingDom> dom;
			DomIndex domIndex;
			auto&& loggedFrames = unitTestProtocol.GetLoggedFrames();
			for (auto loggedFrame : loggedFrames)
			{
				writer.WriteLine(L"========================================");
				writer.WriteLine(itow(loggedFrame->frameId));
				writer.WriteLine(L"========================================");

				if (!dom)
				{
					dom = loggedFrame->renderingDom;
					BuildDomIndex(dom, domIndex);

					List<Pair<vint, Ptr<RenderingDom>>> lines;
					lines.Add({ 0,dom });
					for (vint i = 0; i < lines.Count(); i++)
					{
						for (vint j = 0; j < lines[i].key; j++)
						{
							writer.WriteString(L"  ");
						}

						auto line = lines[i].value;
						writer.WriteString(itow(line->id));
						writer.WriteString(L": ");

						auto jsonLog = remoteprotocol::ConvertCustomTypeToJson(line->content);
						writer.WriteLine(JsonToString(jsonLog, formatting));

						if (line->children)
						{
							for (auto child : *line->children.Obj())
							{
								lines.Add({ lines[i].key + 1,child });
							}
						}
					}
				}
				else
				{
					DomIndex nextDomIndex;
					BuildDomIndex(loggedFrame->renderingDom, nextDomIndex);

					RenderingDom_DiffsInOrder diffs;
					DiffDom(dom, domIndex, loggedFrame->renderingDom, nextDomIndex, diffs);
					if (diffs.diffsInOrder)
					{
						for (auto&& diff : *diffs.diffsInOrder.Obj())
						{
							auto jsonLog = remoteprotocol::ConvertCustomTypeToJson(diff);
							writer.WriteLine(JsonToString(jsonLog, formatting));
						}
					}

					dom = loggedFrame->renderingDom;
					domIndex = std::move(nextDomIndex);
				}
			};
		});

		GacUIUnitTest_WriteSnapshotFileIfChanged(snapshotFile, textLog);
	}
#undef ERROR_MESSAGE_PREFIX
}

void GacUIUnitTest_Start_WithResourceAsText(const WString& appName, Nullable<UnitTestScreenConfig> config, const WString& resourceText)
{
#define ERROR_MESSAGE_PREFIX L"GacUIUnitTest_Start_WithResourceAsText(const WString&, Nullable<UnitTestScreenConfig>, const WString&)#"
	auto previousMainProxy = guiMainProxy;
	GacUIUnitTest_LinkGuiMainProxy([=](UnitTestRemoteProtocol* protocol, IUnitTestContext* context, const UnitTestMainFunc& previousMainProxy)
	{
		auto resource = GacUIUnitTest_CompileAndLoad(resourceText);
		{
			auto workflow = resource->GetStringByPath(L"UnitTest/Workflow");
			File snapshotFile = GacUIUnitTest_PrepareSnapshotFile(
				appName,
#ifdef VCZH_64
				WString::Unmanaged(L"[x64].txt")
#else
				WString::Unmanaged(L"[x86].txt")
#endif
				);

			bool skipWriting = false;
			if (snapshotFile.Exists())
			{
				auto previousLog = snapshotFile.ReadAllTextByBom();
				if (previousLog == workflow)
				{
					skipWriting = true;
				}
			}
			if (!skipWriting)
			{
				bool succeeded = snapshotFile.WriteAllText(workflow, true, stream::BomEncoder::Utf8);
				CHECK_ERROR(succeeded, ERROR_MESSAGE_PREFIX L"Failed to write the snapshot file.");
			}
		}
		previousMainProxy(protocol, context);
	});
	GacUIUnitTest_Start(appName, config);
#undef ERROR_MESSAGE_PREFIX
}

Ptr<GuiResource> GacUIUnitTest_CompileAndLoad(const WString& xmlResource)
{
#define ERROR_MESSAGE_PREFIX L"GacUIUnitTest_CompileAndLoad(const WString&)#"
	Ptr<GuiResource> resource;
	GuiResourceError::List errors;
	{
		auto resourcePath = (GetUnitTestFrameworkConfig().resourceFolder / L"Resource.xml").GetFullPath();
		auto parser = GetParserManager()->GetParser<glr::xml::XmlDocument>(L"XML");
		auto xml = parser->Parse({ WString::Empty,resourcePath }, xmlResource, errors);
		CHECK_ERROR(xml && errors.Count() == 0, ERROR_MESSAGE_PREFIX L"Failed to parse XML resource.");

		resource = GuiResource::LoadFromXml(xml, resourcePath, GetFolderPath(resourcePath), errors);
		CHECK_ERROR(resource && errors.Count() == 0, ERROR_MESSAGE_PREFIX L"Failed to load XML resource.");
	}

	auto precompiledFolder = resource->Precompile(
#ifdef VCZH_64
		GuiResourceCpuArchitecture::x64,
#else
		GuiResourceCpuArchitecture::x86,
#endif
		nullptr,
		errors
		);
	CHECK_ERROR(precompiledFolder && errors.Count() == 0, ERROR_MESSAGE_PREFIX L"Failed to precompile XML resource.");

	auto compiledWorkflow = precompiledFolder->GetValueByPath(WString::Unmanaged(L"Workflow/InstanceClass")).Cast<GuiInstanceCompiledWorkflow>();
	CHECK_ERROR(compiledWorkflow, ERROR_MESSAGE_PREFIX L"Failed to compile generated Workflow script.");
	CHECK_ERROR(compiledWorkflow->assembly, ERROR_MESSAGE_PREFIX L"Failed to load Workflow assembly.");

	{
		WString text;
		auto& codes = compiledWorkflow->assembly->insAfterCodegen->moduleCodes;
		for (auto [code, codeIndex] : indexed(codes))
		{
			text += L"================================(" + itow(codeIndex + 1) + L"/" + itow(codes.Count()) + L")================================\r\n";
			text += code + L"\r\n";
		}
		resource->CreateValueByPath(
			WString::Unmanaged(L"UnitTest/Workflow"),
			WString::Unmanaged(L"Text"),
			Ptr(new GuiTextData(text))
			);
	}

	GetResourceManager()->SetResource(resource, errors, GuiResourceUsage::InstanceClass);
	CHECK_ERROR(errors.Count() == 0, ERROR_MESSAGE_PREFIX L"Failed to load compiled XML resource.");

	return resource;
#undef ERROR_MESSAGE_PREFIX
}

void GuiMain()
{
	if (guiMainUnitTestContext)
	{
		guiMainProxy(guiMainUnitTestContext->GetProtocol(), guiMainUnitTestContext);
	}
	else
	{
		guiMainProxy(nullptr, nullptr);
	}
	guiMainUnitTestContext = nullptr;
}