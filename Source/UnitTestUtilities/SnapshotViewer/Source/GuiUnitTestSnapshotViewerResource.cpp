#include "GuiUnitTestSnapshotViewerIncludes.h"

namespace vl
{
	namespace presentation
	{
		namespace user_resource
		{
			using namespace collections;
			using namespace stream;
			using namespace controls;

			class GuiUnitTestSnapshotViewerResourceReader
			{
			public:
				static const vint parserBufferLength = 830; // 830 bytes before compressing
				static const vint parserBufferBlock = 1024;
				static const vint parserBufferRemain = 830;
				static const vint parserBufferRows = 1;
				static const char* parserBuffer[1];

				static void ReadToStream(vl::stream::MemoryStream& stream)
				{
					DecompressStream(parserBuffer, false, parserBufferRows, parserBufferBlock, parserBufferRemain, stream);
				}
			};

			const char* GuiUnitTestSnapshotViewerResourceReader::parserBuffer[] = {
				"\x63\x00\x00\x00\x00\x00\x00\x00\x63\x00\x00\x00\x3C\x52\x65\x73\x6F\x75\x72\x63\x65\x4D\x65\x74\x61\x64\x61\x74\x61\x20\x4E\x61\x6D\x65\x3D\x22\x47\x75\x69\x55\x6E\x69\x74\x54\x65\x73\x74\x53\x6E\x61\x70\x73\x68\x6F\x74\x56\x69\x65\x77\x65\x72\x22\x20\x56\x65\x72\x73\x69\x6F\x6E\x3D\x22\x31\x2E\x30\x22\x3E\x3C\x44\x65\x70\x65\x6E\x64\x65\x6E\x63\x69\x65\x73\x2F\x3E\x3C\x2F\x52\x65\x73\x6F\x75\x72\x63\x65\x4D\x65\x74\x61\x64\x61\x74\x61\x3E\x05\x00\x00\x00\x00\x00\x00\x00\x10\x00\x00\x00\x00\x00\x00\x00\x10\x00\x00\x00\x4C\x6F\x63\x61\x6C\x69\x7A\x65\x64\x53\x74\x72\x69\x6E\x67\x73\x06\x00\x00\x00\x00\x00\x00\x00\x06\x00\x00\x00\x53\x63\x72\x69\x70\x74\x08\x00\x00\x00\x00\x00\x00\x00\x08\x00\x00\x00\x49\x6E\x73\x74\x61\x6E\x63\x65\x04\x00\x00\x00\x00\x00\x00\x00\x04\x00\x00\x00\x54\x65\x78\x74\x0F\x00\x00\x00\x00\x00\x00\x00\x0F\x00\x00\x00\x43\x6C\x61\x73\x73\x4E\x61\x6D\x65\x52\x65\x63\x6F\x72\x64\x00\x00\x00\x00\x00\x00\x00\x00\x02\x00\x00\x00\x00\x00\x00\x00\x0C\x00\x00\x00\x00\x00\x00\x00\x0C\x00\x00\x00\x47\x61\x63\x47\x65\x6E\x43\x6F\x6E\x66\x69\x67\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x03\x00\x00\x00\x00\x00\x00\x00\x03\x00\x00\x00\x43\x70\x70\x00\x00\x00\x00\x00\x00\x00\x00\x05\x00\x00\x00\x00\x00\x00\x00\x03\x00\x00\x00\x00\x00\x00\x00\x0D\x00\x00\x00\x00\x00\x00\x00\x0D\x00\x00\x00\x43\x70\x70\x43\x6F\x6D\x70\x72\x65\x73\x73\x65\x64\x1D\x00\x00\x00\x00\x00\x00\x00\x1D\x00\x00\x00\x47\x75\x69\x55\x6E\x69\x74\x54\x65\x73\x74\x53\x6E\x61\x70\x73\x68\x6F\x74\x56\x69\x65\x77\x65\x72\x2E\x63\x70\x70\x03\x00\x00\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x04\x00\x00\x00\x4E\x61\x6D\x65\x19\x00\x00\x00\x00\x00\x00\x00\x19\x00\x00\x00\x47\x75\x69\x55\x6E\x69\x74\x54\x65\x73\x74\x53\x6E\x61\x70\x73\x68\x6F\x74\x56\x69\x65\x77\x65\x72\x03\x00\x00\x00\x00\x00\x00\x00\x0D\x00\x00\x00\x00\x00\x00\x00\x0D\x00\x00\x00\x4E\x6F\x72\x6D\x61\x6C\x49\x6E\x63\x6C\x75\x64\x65\x10\x00\x00\x00\x00\x00\x00\x00\x10\x00\x00\x00\x2E\x2E\x2F\x2E\x2E\x2F\x2E\x2E\x2F\x47\x61\x63\x55\x49\x2E\x68\x03\x00\x00\x00\x00\x00\x00\x00\x11\x00\x00\x00\x00\x00\x00\x00\x11\x00\x00\x00\x52\x65\x66\x6C\x65\x63\x74\x69\x6F\x6E\x49\x6E\x63\x6C\x75\x64\x65\x39\x00\x00\x00\x00\x00\x00\x00\x39\x00\x00\x00\x2E\x2E\x2F\x2E\x2E\x2F\x2E\x2E\x2F\x52\x65\x66\x6C\x65\x63\x74\x69\x6F\x6E\x2F\x54\x79\x70\x65\x44\x65\x73\x63\x72\x69\x70\x74\x6F\x72\x73\x2F\x47\x75\x69\x52\x65\x66\x6C\x65\x63\x74\x69\x6F\x6E\x50\x6C\x75\x67\x69\x6E\x2E\x68\x03\x00\x00\x00\x00\x00\x00\x00\x0C\x00\x00\x00\x00\x00\x00\x00\x0C\x00\x00\x00\x53\x6F\x75\x72\x63\x65\x46\x6F\x6C\x64\x65\x72\x06\x00\x00\x00\x00\x00\x00\x00\x06\x00\x00\x00\x53\x6F\x75\x72\x63\x65\x00\x00\x00\x00\x00\x00\x00\x00\x0B\x00\x00\x00\x00\x00\x00\x00\x0B\x00\x00\x00\x50\x72\x65\x63\x6F\x6D\x70\x69\x6C\x65\x64\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x0F\x00\x00\x00\x00\x00\x00\x00\x0F\x00\x00\x00\x43\x6C\x61\x73\x73\x4E\x61\x6D\x65\x52\x65\x63\x6F\x72\x64\x01\x00\x00\x00\x00\x00\x00\x00\x2D\x00\x00\x00\x00\x00\x00\x00\x2D\x00\x00\x00\x67\x61\x63\x6C\x69\x62\x5F\x63\x6F\x6E\x74\x72\x6F\x6C\x73\x3A\x3A\x55\x6E\x69\x74\x54\x65\x73\x74\x53\x6E\x61\x70\x73\x68\x6F\x74\x56\x69\x65\x77\x65\x72\x57\x69\x6E\x64\x6F\x77\x00\x00\x00\x00\x00\x00\x00\x00",
				};

			class GuiUnitTestSnapshotViewerResourceLoaderPlugin : public Object, public IGuiPlugin
			{
			public:

				GUI_PLUGIN_NAME(GacGen_GuiUnitTestSnapshotViewerResourceLoader)
				{
					GUI_PLUGIN_DEPEND(GacUI_Res_Resource);
					GUI_PLUGIN_DEPEND(GacUI_Res_TypeResolvers);
#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
					GUI_PLUGIN_DEPEND(GacUI_Instance_Reflection);
					GUI_PLUGIN_DEPEND(GacUI_Compiler_WorkflowTypeResolvers);
#endif
				}

				void Load(bool controllerUnrelatedPlugins, bool controllerRelatedPlugins)override
				{
					if (controllerRelatedPlugins)
					{
						List<GuiResourceError> errors;
						MemoryStream resourceStream;
						GuiUnitTestSnapshotViewerResourceReader::ReadToStream(resourceStream);
						resourceStream.SeekFromBegin(0);
						GetResourceManager()->LoadResourceOrPending(resourceStream, GuiResourceUsage::InstanceClass);
					}
				}

				void Unload(bool controllerUnrelatedPlugins, bool controllerRelatedPlugins)override
				{
				}
			};
			GUI_REGISTER_PLUGIN(GuiUnitTestSnapshotViewerResourceLoaderPlugin)
		}
	}
}
