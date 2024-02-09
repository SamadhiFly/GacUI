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
	class GuiHostedController;
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
			using RendererSet = collections::SortedList<elements_remoteprotocol::IGuiRemoteProtocolElementRender*>;
			using FontHeightMap = collections::Dictionary<Tuple<WString, vint>, vint>;
		protected:
			GuiRemoteController*				remote;
			GuiHostedController*				hostedController;
			NativeSize							canvasSize;
			vint								usedElementIds = 0;
			RendererMap							renderers;
			collections::SortedList<vint>		createdRenderers;
			collections::SortedList<vint>		destroyedRenderers;
			RendererSet							renderersAskingForCache;
			Nullable<Rect>						clipperValidArea;

			void								StartRenderingOnNativeWindow() override;
			RenderTargetFailure					StopRenderingOnNativeWindow() override;

			Size								GetCanvasSize() override;
			void								AfterPushedClipper(Rect clipper, Rect validArea) override;
			void								AfterPushedClipperAndBecameInvalid(Rect clipper) override;
			void								AfterPoppedClipperAndBecameValid(Rect validArea, bool clipperExists) override;
			void								AfterPoppedClipper(Rect validArea, bool clipperExists) override;

		public:
			FontHeightMap						fontHeights;
			vuint64_t							renderingBatchId = 0;

			GuiRemoteGraphicsRenderTarget(GuiRemoteController* _remote, GuiHostedController* _hostedController);
			~GuiRemoteGraphicsRenderTarget();

			void								OnControllerConnect();
			void								OnControllerDisconnect();

			GuiRemoteMessages&					GetRemoteMessages();
			vint								AllocateNewElementId();
			void								RegisterRenderer(elements_remoteprotocol::IGuiRemoteProtocolElementRender* renderer);
			void								UnregisterRenderer(elements_remoteprotocol::IGuiRemoteProtocolElementRender* renderer);
			Rect								GetClipperValidArea();
		};

/***********************************************************************
GuiRemoteGraphicsResourceManager
***********************************************************************/

		class GuiRemoteGraphicsResourceManager : public GuiGraphicsResourceManager
		{
		protected:
			GuiRemoteController*				remote;
			GuiRemoteGraphicsRenderTarget		renderTarget;
			GuiHostedController*				hostedController;

		public:
			GuiRemoteGraphicsResourceManager(GuiRemoteController* _remote, GuiHostedController* _hostedController);
			~GuiRemoteGraphicsResourceManager();

			void								Initialize();
			void								Finalize();

			void								OnControllerConnect();
			void								OnControllerDisconnect();

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