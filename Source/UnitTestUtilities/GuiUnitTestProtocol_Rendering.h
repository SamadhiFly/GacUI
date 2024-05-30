/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
Unit Test Snapsnot and other Utilities
***********************************************************************/

#ifndef VCZH_PRESENTATION_GUIUNITTESTPROTOCOL_RENDERING
#define VCZH_PRESENTATION_GUIUNITTESTPROTOCOL_RENDERING

#include "GuiUnitTestProtocol_Shared.h"

namespace vl::presentation::unittest
{

/***********************************************************************
UnitTestRemoteProtocol
***********************************************************************/

	using ElementDescVariant = remoteprotocol::ElementDescVariant;
	using UnitTestRenderingCommand = remoteprotocol::RenderingCommand;
	using UnitTestRenderingCommandList = collections::List<UnitTestRenderingCommand>;
	using UnitTestRenderingCommandListRef = Ptr<UnitTestRenderingCommandList>;
	using UnitTestRenderingDom = remoteprotocol::RenderingDom;
	
	template<typename TProtocol>
	class UnitTestRemoteProtocol_Rendering : public TProtocol
	{
		using ElementDescMap = collections::Dictionary<vint, ElementDescVariant>;
		using ImageMetadataMap = collections::Dictionary<vint, remoteprotocol::ImageMetadata>;
		using CommandList = UnitTestRenderingCommandList;
		using CommandListRef = UnitTestRenderingCommandListRef;
	protected:

		remoteprotocol::RenderingTrace			loggedTrace;
		ElementDescMap							lastElementDescs;
		remoteprotocol::ElementMeasurings		measuringForNextRendering;
		regex::Regex							regexCrLf{ L"/n|/r(/n)?" };
		vint									lastFrameId = 0;
		CommandListRef							lastRenderingCommands;

		void ResetCreatedObjects()
		{
			loggedTrace.createdElements = Ptr(new collections::Dictionary<vint, remoteprotocol::RendererType>);
			loggedTrace.createdImages = Ptr(new remoteprotocol::ArrayMap<vint, remoteprotocol::ImageMetadata, &remoteprotocol::ImageMetadata::id>);
			lastElementDescs.Clear();
		}
	public:

		template<typename ...TArgs>
		UnitTestRemoteProtocol_Rendering(TArgs&& ...args)
			: TProtocol(std::forward<TArgs&&>(args)...)
		{
			ResetCreatedObjects();
			loggedTrace.frames = Ptr(new collections::List<remoteprotocol::RenderingFrame>);
		}

	protected:

/***********************************************************************
IGuiRemoteProtocolMessages (Rendering)
***********************************************************************/

		void RequestRendererBeginRendering(const remoteprotocol::ElementBeginRendering& arguments) override
		{
			lastFrameId = arguments.frameId;
			lastRenderingCommands = Ptr(new CommandList);
		}

		void RequestRendererEndRendering(vint id) override
		{
			this->GetEvents()->RespondRendererEndRendering(id, measuringForNextRendering);
			measuringForNextRendering = {};
		}

		void RequestRendererBeginBoundary(const remoteprotocol::ElementBoundary& arguments) override
		{
			lastRenderingCommands->Add(remoteprotocol::RenderingCommand_BeginBoundary{ arguments });
		}

		void RequestRendererEndBoundary() override
		{
			lastRenderingCommands->Add(remoteprotocol::RenderingCommand_EndBoundary{});
		}

		template<typename T>
		void RequestRendererRenderElement(const remoteprotocol::ElementRendering& rendering, const T& element)
		{
			lastRenderingCommands->Add(remoteprotocol::RenderingCommand_Element{ rendering,element.id });
		}

		void RequestRendererRenderElement(const remoteprotocol::ElementRendering& arguments) override
		{
#define ERROR_MESSAGE_PREFIX L"vl::presentation::unittest::UnitTestRemoteProtocol_Rendering<TProtocol>::RequestRendererRenderElement(const ElementRendering&)#"
			vint index = loggedTrace.createdElements->Keys().IndexOf(arguments.id);
			CHECK_ERROR(index != -1, ERROR_MESSAGE_PREFIX L"Renderer with the specified id has not been created.");

			auto rendererType = loggedTrace.createdElements->Values()[index];
			if (rendererType == remoteprotocol::RendererType::FocusRectangle)
			{
				// FocusRectangle does not has a ElementDesc
				lastRenderingCommands->Add(remoteprotocol::RenderingCommand_Element{ arguments,arguments.id });
				return;
			}

			index = lastElementDescs.Keys().IndexOf(arguments.id);
			CHECK_ERROR(index != -1, ERROR_MESSAGE_PREFIX L"Renderer with the specified id has not been updated after created.");
			lastElementDescs.Values()[index].Apply(Overloading(
				[](remoteprotocol::RendererType)
				{
					CHECK_FAIL(ERROR_MESSAGE_PREFIX L"Renderer with the specified id has not been updated after created.");
				},
				[&](const remoteprotocol::ElementDesc_SolidLabel& solidLabel)
				{
					CalculateSolidLabelSizeIfNecessary(arguments.bounds.Width(), arguments.bounds.Height(), solidLabel);
					RequestRendererRenderElement(arguments, solidLabel);
				},
				[&](const auto& element)
				{
					RequestRendererRenderElement(arguments, element);
				}));
#undef ERROR_MESSAGE_PREFIX
		}

/***********************************************************************
IGuiRemoteProtocolMessages (Elements)
***********************************************************************/

		void RequestRendererCreated(const Ptr<collections::List<remoteprotocol::RendererCreation>>& arguments) override
		{
#define ERROR_MESSAGE_PREFIX L"vl::presentation::unittest::UnitTestRemoteProtocol_Rendering<TProtocol>::RequestRendererCreated(const Ptr<List<RendererCreation>>&)#"
			if (arguments)
			{
				for (auto creation : *arguments.Obj())
				{
					CHECK_ERROR(!loggedTrace.createdElements->Keys().Contains(creation.id), ERROR_MESSAGE_PREFIX L"Renderer with the specified id has been created.");
					loggedTrace.createdElements->Add(creation.id, creation.type);
				}
			}
#undef ERROR_MESSAGE_PREFIX
		}

		void RequestRendererDestroyed(const Ptr<collections::List<vint>>& arguments) override
		{
#define ERROR_MESSAGE_PREFIX L"vl::presentation::unittest::UnitTestRemoteProtocol_Rendering<TProtocol>::RequestRendererDestroyed(const Ptr<List<vint>>&)#"
			if (arguments)
			{
				for (auto id : *arguments.Obj())
				{
					CHECK_ERROR(loggedTrace.createdElements->Keys().Contains(id), ERROR_MESSAGE_PREFIX L"Renderer with the specified id has not been created.");
					loggedTrace.createdElements->Remove(id);
					lastElementDescs.Remove(id);
				}
			}
#undef ERROR_MESSAGE_PREFIX
		}

		template<remoteprotocol::RendererType RendererType, typename TElementDesc>
		void RequestRendererUpdateElement(const TElementDesc& arguments, const wchar_t* emWrongId, const wchar_t* emWrongType)
		{
			vint index = loggedTrace.createdElements->Keys().IndexOf(arguments.id);
			CHECK_ERROR(index != -1, emWrongId);
			CHECK_ERROR(loggedTrace.createdElements->Values()[index] == RendererType, emWrongType);
			lastElementDescs.Set(arguments.id, arguments);
		}

#define REQUEST_RENDERER_UPDATE_ELEMENT2(ARGUMENTS, RENDERER_TYPE)\
			RequestRendererUpdateElement<RENDERER_TYPE>(\
				ARGUMENTS,\
				ERROR_MESSAGE_PREFIX L"Renderer with the specified id has not been created.",\
				ERROR_MESSAGE_PREFIX L"Renderer with the specified id is not of the expected type."\
				)

#define REQUEST_RENDERER_UPDATE_ELEMENT(RENDERER_TYPE) REQUEST_RENDERER_UPDATE_ELEMENT2(arguments, RENDERER_TYPE)

		void RequestRendererUpdateElement_SolidBorder(const remoteprotocol::ElementDesc_SolidBorder& arguments) override
		{
#define ERROR_MESSAGE_PREFIX L"vl::presentation::unittest::RequestRendererUpdateElement_SolidBorder<TProtocol>::RequestRendererCreated(const ElementDesc_SolidBorder&)#"
			REQUEST_RENDERER_UPDATE_ELEMENT(remoteprotocol::RendererType::SolidBorder);
#undef ERROR_MESSAGE_PREFIX
		}

		void RequestRendererUpdateElement_SinkBorder(const remoteprotocol::ElementDesc_SinkBorder& arguments) override
		{
#define ERROR_MESSAGE_PREFIX L"vl::presentation::unittest::RequestRendererUpdateElement_SinkBorder<TProtocol>::RequestRendererCreated(const ElementDesc_SinkBorder&)#"
			REQUEST_RENDERER_UPDATE_ELEMENT(remoteprotocol::RendererType::SinkBorder);
#undef ERROR_MESSAGE_PREFIX
		}

		void RequestRendererUpdateElement_SinkSplitter(const remoteprotocol::ElementDesc_SinkSplitter& arguments) override
		{
#define ERROR_MESSAGE_PREFIX L"vl::presentation::unittest::RequestRendererUpdateElement_SinkSplitter<TProtocol>::RequestRendererCreated(const ElementDesc_SinkSplitter&)#"
			REQUEST_RENDERER_UPDATE_ELEMENT(remoteprotocol::RendererType::SinkSplitter);
#undef ERROR_MESSAGE_PREFIX
		}

		void RequestRendererUpdateElement_SolidBackground(const remoteprotocol::ElementDesc_SolidBackground& arguments) override
		{
#define ERROR_MESSAGE_PREFIX L"vl::presentation::unittest::RequestRendererUpdateElement_SolidBackground<TProtocol>::RequestRendererCreated(const ElementDesc_SolidBackground&)#"
			REQUEST_RENDERER_UPDATE_ELEMENT(remoteprotocol::RendererType::SolidBackground);
#undef ERROR_MESSAGE_PREFIX
		}

		void RequestRendererUpdateElement_GradientBackground(const remoteprotocol::ElementDesc_GradientBackground& arguments) override
		{
#define ERROR_MESSAGE_PREFIX L"vl::presentation::unittest::RequestRendererUpdateElement_GradientBackground<TProtocol>::RequestRendererCreated(const ElementDesc_GradientBackground&)#"
			REQUEST_RENDERER_UPDATE_ELEMENT(remoteprotocol::RendererType::GradientBackground);
#undef ERROR_MESSAGE_PREFIX
		}

		void RequestRendererUpdateElement_InnerShadow(const remoteprotocol::ElementDesc_InnerShadow& arguments) override
		{
#define ERROR_MESSAGE_PREFIX L"vl::presentation::unittest::RequestRendererUpdateElement_InnerShadow<TProtocol>::RequestRendererCreated(const ElementDesc_InnerShadow&)#"
			REQUEST_RENDERER_UPDATE_ELEMENT(remoteprotocol::RendererType::InnerShadow);
#undef ERROR_MESSAGE_PREFIX
		}

		void RequestRendererUpdateElement_Polygon(const remoteprotocol::ElementDesc_Polygon& arguments) override
		{
#define ERROR_MESSAGE_PREFIX L"vl::presentation::unittest::RequestRendererUpdateElement_Polygon<TProtocol>::RequestRendererCreated(const ElementDesc_Polygon&)#"
			REQUEST_RENDERER_UPDATE_ELEMENT(remoteprotocol::RendererType::Polygon);
#undef ERROR_MESSAGE_PREFIX
		}

/***********************************************************************
IGuiRemoteProtocolMessages (Elements - SolidLabel)
***********************************************************************/

		void CalculateSolidLabelSizeIfNecessary(vint width, vint height, const remoteprotocol::ElementDesc_SolidLabel& arguments)
		{
#define ERROR_MESSAGE_PREFIX L"vl::presentation::unittest::RequestRendererUpdateElement_SolidLabel<TProtocol>::CalculateSolidLabelSizeIfNecessary(vint, vint, const ElementDesc_SolidLabel&)#"

			if (arguments.measuringRequest)
			{
				switch (arguments.measuringRequest.Value())
				{
				case remoteprotocol::ElementSolidLabelMeasuringRequest::FontHeight:
					CHECK_ERROR(arguments.font, ERROR_MESSAGE_PREFIX L"Font is missing for calculating font height.");
					if (!measuringForNextRendering.fontHeights)
					{
						measuringForNextRendering.fontHeights = Ptr(new collections::List<remoteprotocol::ElementMeasuring_FontHeight>);
					}
					{
						remoteprotocol::ElementMeasuring_FontHeight measuring;
						measuring.fontFamily = arguments.font.Value().fontFamily;
						measuring.fontSize = arguments.font.Value().size;
						measuring.height = measuring.fontSize;
						measuringForNextRendering.fontHeights->Add(measuring);
					}
					break;
				case remoteprotocol::ElementSolidLabelMeasuringRequest::TotalSize:
					{
						// font and text has already been verified exist in RequestRendererUpdateElement_SolidLabel
						vint size = arguments.font.Value().size;
						auto text = arguments.text.Value();
						vint textWidth = 0;
						vint textHeight = 0;

						collections::List<vint> lines;
						{
							collections::List<Ptr<regex::RegexMatch>> matches;
							regexCrLf.Split(text, true, matches);

							if (matches.Count() == 0)
							{
								// when there is no text, measure a space
								lines.Add(1);
							}
							else
							{
								auto normalizedLines = 
									From(matches)
										.Select([](auto&& match) { return match->Result().Length(); })
										.Select([](vint length) { return length ? length : 1; })
									;
								if (arguments.multiline)
								{
									// calculate text as multiple lines
									CopyFrom(
										lines,
										normalizedLines
										);
								}
								else
								{
									// calculate text as single line, insert a space between each line
									lines.Add(
										normalizedLines
											.template Aggregate<vint>(-1, [](auto a, auto b) { return a + b + 1; })
										);
								}
							}
						}

						if (arguments.wrapLine)
						{
							// width of the text is 0
							// insert a line break when there is no space horizontally
							textHeight = size * From(lines)
								.Select([columns = width / size](vint length)
								{
									if (columns == 0)
									{
										return length;
									}
									else
									{
										return (length + columns - 1) / columns;
									}
								})
								.template Aggregate<vint>(0, [](auto a, auto b) { return a + b; });
						}
						else
						{
							// width of the text is width of the longest line
							textWidth = size * From(lines).Max();
							textHeight = size * lines.Count();
						}

						if (!measuringForNextRendering.minSizes)
						{
							measuringForNextRendering.minSizes = Ptr(new collections::List<remoteprotocol::ElementMeasuring_ElementMinSize>);
						}
						{
							remoteprotocol::ElementMeasuring_ElementMinSize measuring;
							measuring.id = arguments.id;
							measuring.minSize = { textWidth,textHeight };
							measuringForNextRendering.minSizes->Add(measuring);
						}
					}
					break;
				default:
					CHECK_FAIL(L"Unknown value of ElementSolidLabelMeasuringRequest.");
				}
			}
#undef ERROR_MESSAGE_PREFIX
		}

		void RequestRendererUpdateElement_SolidLabel(const remoteprotocol::ElementDesc_SolidLabel& arguments) override
		{
#define ERROR_MESSAGE_PREFIX L"vl::presentation::unittest::RequestRendererUpdateElement_SolidLabel<TProtocol>::RequestRendererCreated(const ElementDesc_SolidLabel&)#"
			auto element = arguments;
			if (!element.font || !element.text)
			{
				vint index = loggedTrace.createdElements->Keys().IndexOf(element.id);
				CHECK_ERROR(index != -1, ERROR_MESSAGE_PREFIX L"Renderer with the specified id has not been created.");

				auto rendererType = loggedTrace.createdElements->Values()[index];
				CHECK_ERROR(rendererType == remoteprotocol::RendererType::SolidLabel, ERROR_MESSAGE_PREFIX L"Renderer with the specified id is not of the expected type.");

				index = lastElementDescs.Keys().IndexOf(arguments.id);
				if (index != -1)
				{
					auto solidLabel = lastElementDescs.Values()[index].TryGet<remoteprotocol::ElementDesc_SolidLabel>();
					CHECK_ERROR(solidLabel, ERROR_MESSAGE_PREFIX L"Renderer with the specified id is not of the expected type.");
					if (!element.font) element.font = solidLabel->font;
					if (!element.text) element.text = solidLabel->text;
				}
				else
				{
					if (!element.font) element.font = FontProperties();
					if (!element.text) element.text = WString::Empty;
				}
			}
			REQUEST_RENDERER_UPDATE_ELEMENT2(element, remoteprotocol::RendererType::SolidLabel);
#undef ERROR_MESSAGE_PREFIX
		}

/***********************************************************************
IGuiRemoteProtocolMessages (Elements - Image)
***********************************************************************/

		remoteprotocol::ImageMetadata MakeImageMetadata(const remoteprotocol::ImageCreation& arguments)
		{
			CHECK_FAIL(L"Not Implemented!");
		}

		void RequestImageCreated(vint id, const remoteprotocol::ImageCreation& arguments) override
		{
#define ERROR_MESSAGE_PREFIX L"vl::presentation::unittest::UnitTestRemoteProtocol_Rendering<TProtocol>::RequestImageCreated(vint, const vint&)#"
			CHECK_ERROR(!loggedTrace.createdImages->Keys().Contains(arguments.id), ERROR_MESSAGE_PREFIX L"Image with the specified id has been created.");
			this->GetEvents()->RespondImageCreated(id, MakeImageMetadata(arguments));
#undef ERROR_MESSAGE_PREFIX
		}

		void RequestImageDestroyed(const vint& arguments) override
		{
#define ERROR_MESSAGE_PREFIX L"vl::presentation::unittest::UnitTestRemoteProtocol_Rendering<TProtocol>::RequestImageDestroyed(const vint&)#"
			CHECK_ERROR(loggedTrace.createdImages->Keys().Contains(arguments), ERROR_MESSAGE_PREFIX L"Image with the specified id has not been created.");
			loggedTrace.createdImages->Remove(arguments);
#undef ERROR_MESSAGE_PREFIX
		}

		void RequestRendererUpdateElement_ImageFrame(const remoteprotocol::ElementDesc_ImageFrame& arguments) override
		{
#define ERROR_MESSAGE_PREFIX L"vl::presentation::unittest::RequestRendererUpdateElement_ImageFrame<TProtocol>::RequestRendererCreated(const ElementDesc_ImageFrame&)#"
			if (arguments.imageCreation)
			{
				auto&& imageCreation = arguments.imageCreation.Value();
				if (!imageCreation.imageDataOmitted)
				{
					CHECK_ERROR(arguments.imageId && arguments.imageId.Value() != !imageCreation.id, ERROR_MESSAGE_PREFIX L"It should satisfy that (arguments.imageId.Value()id == imageCreation.id).");
					CHECK_ERROR(!loggedTrace.createdImages->Keys().Contains(imageCreation.id), ERROR_MESSAGE_PREFIX L"Image with the specified id has been created.");
					CHECK_ERROR(imageCreation.imageData, ERROR_MESSAGE_PREFIX L"When imageDataOmitted == false, imageData should not be null.");
					if (!measuringForNextRendering.createdImages)
					{
						measuringForNextRendering.createdImages = Ptr(new collections::List<remoteprotocol::ImageMetadata>);
					}
					measuringForNextRendering.createdImages->Add(MakeImageMetadata(imageCreation));
				}
				else
				{
					CHECK_ERROR(!imageCreation.imageData, ERROR_MESSAGE_PREFIX L"When imageDataOmitted == true, imageData should be null.");
				}
			}
			else if (arguments.imageId)
			{
				CHECK_ERROR(loggedTrace.createdImages->Keys().Contains(arguments.imageId.Value()), ERROR_MESSAGE_PREFIX L"Image with the specified id has not been created.");
			}

			auto element = arguments;
			element.imageCreation.Reset();
			REQUEST_RENDERER_UPDATE_ELEMENT2(element, remoteprotocol::RendererType::ImageFrame);
#undef ERROR_MESSAGE_PREFIX
		}

#undef REQUEST_RENDERER_UPDATE_ELEMENT
#undef REQUEST_RENDERER_UPDATE_ELEMENT2
	};
}

#endif