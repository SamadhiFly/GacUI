/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
GacUI::Remote Window

Interfaces:
  GuiRemoteController

***********************************************************************/

#ifndef VCZH_PRESENTATION_GUIREMOTEGRAPHICS
#define VCZH_PRESENTATION_GUIREMOTEGRAPHICS

#include "../../GraphicsElement/GuiGraphicsResourceManager.h"
#include "Protocol/Generated/GuiRemoteProtocolSchema.h"

namespace vl::presentation
{
	class GuiRemoteController;
	class GuiRemoteMessages;

	namespace elements_remoteprotocol
	{
		class IGuiRemoteProtocolElementRender;
	}

	namespace elements
	{
/***********************************************************************
GuiRemoteGraphicsRenderTarget
***********************************************************************/

		class GuiRemoteGraphicsRenderTarget : public GuiGraphicsRenderTarget
		{
			using RendererMap = collections::Dictionary<vint, elements_remoteprotocol::IGuiRemoteProtocolElementRender*>;
		protected:
			GuiRemoteController*				remote;
			NativeSize							canvasSize;
			vint								usedElementIds = 0;
			RendererMap							renderers;
			collections::SortedList<vint>		createdRenderers;
			collections::SortedList<vint>		destroyedRenderers;
			Nullable<Rect>						clipper;
			bool								clipperNoValidArea = false;

			void								StartRenderingOnNativeWindow() override;
			RenderTargetFailure					StopRenderingOnNativeWindow() override;

			Size								GetCanvasSize() override;
			void								AfterPushedClipper(Rect clipper, Rect validArea) override;
			void								AfterPushedClipperAndBecameInvalid(Rect clipper) override;
			void								AfterPoppedClipperAndBecameValid(Rect validArea, bool clipperExists) override;
			void								AfterPoppedClipper(Rect validArea, bool clipperExists) override;
		public:
			GuiRemoteGraphicsRenderTarget(GuiRemoteController* _remote);
			~GuiRemoteGraphicsRenderTarget();

			GuiRemoteMessages&					GetRemoteMessages();
			vint								AllocateNewElementId();
			void								RegisterRenderer(elements_remoteprotocol::IGuiRemoteProtocolElementRender* renderer);
			void								UnregisterRenderer(elements_remoteprotocol::IGuiRemoteProtocolElementRender* renderer);
		};

/***********************************************************************
GuiRemoteGraphicsResourceManager
***********************************************************************/

		class GuiRemoteGraphicsResourceManager : public GuiGraphicsResourceManager
		{
		protected:
			GuiRemoteController*				remote;
			GuiRemoteGraphicsRenderTarget		renderTarget;

		public:
			GuiRemoteGraphicsResourceManager(GuiRemoteController* _remote);
			~GuiRemoteGraphicsResourceManager();

			void								Initialize();
			void								Finalize();

			// =============================================================
			// IGuiGraphicsResourceManager
			// =============================================================

			IGuiGraphicsRenderTarget*			GetRenderTarget(INativeWindow* window) override;
			void								RecreateRenderTarget(INativeWindow* window) override;
			void								ResizeRenderTarget(INativeWindow* window) override;
			IGuiGraphicsLayoutProvider*			GetLayoutProvider() override;
		};
	}
}

#endif