#define GAC_HEADER_USE_NAMESPACE

#include "../../../Source/Compiler/RemoteProtocol/GuiRemoteProtocolCompiler.h"
#ifdef VCZH_MSVC
#include <Windows.h>
#endif

using namespace vl;
using namespace vl::collections;
using namespace vl::stream;
using namespace vl::filesystem;
using namespace vl::presentation;
using namespace vl::presentation::remoteprotocol;

#if defined VCZH_MSVC
WString GetExePath()
{
	wchar_t buffer[65536];
	GetModuleFileName(NULL, buffer, sizeof(buffer) / sizeof(*buffer));
	vint pos = -1;
	vint index = 0;
	while (buffer[index])
	{
		if (buffer[index] == L'\\' || buffer[index] == L'/')
		{
			pos = index;
		}
		index++;
	}
	return WString::CopyFrom(buffer, pos + 1);
}

WString GetRemoteProtocolPath()
{
#ifdef _WIN64
	return GetExePath() + L"../../../../Source/PlatformProviders/Remote/Protocol/";
#else
	return GetExePath() + L"../../../Source/PlatformProviders/Remote/Protocol/";
#endif
}
#elif defined VCZH_GCC
WString GetRemoteProtocolPath()
{
	return L"../../../Source/PlatformProviders/Remote/Protocol/";
}
#endif

#if defined VCZH_MSVC
int wmain(int argc, wchar_t* argv[])
#elif defined VCZH_GCC
int main(int argc, char* argv[])
#endif
{
	remoteprotocol::Parser parser;
	List<WString> schemaNames;
	Dictionary<WString, Ptr<GuiRpSchema>> schemas;

	File(FilePath(GetRemoteProtocolPath()) / L"Protocols.txt").ReadAllLinesByBom(schemaNames);
	for (auto [schemaName, index] : indexed(schemaNames))
	{
		WString code = File(FilePath(GetRemoteProtocolPath()) / (schemaName + L".txt")).ReadAllTextByBom();
		auto schema = parser.ParseSchema(code, index);
		schemas.Add(schemaName, schema);
	}

	auto mergedSchema = Ptr(new GuiRpSchema);
	for (auto schema : schemas.Values())
	{
		CopyFrom(mergedSchema->declarations, schema->declarations, true);
	}
	File(FilePath(GetRemoteProtocolPath()) / L"Metadata" / L"Protocols.json").WriteAllText(
		GenerateToStream([&](StreamWriter& writer)
		{
			json_visitor::AstVisitor(writer).Print(mergedSchema.Obj());
		}), false, BomEncoder::Utf8);
	return 0;
}