#include "../../../Source//UnitTestUtilities/GuiUnitTestUtilities.h"
#ifdef VCZH_64
#include "../Generated_DarkSkin/Source_x64/DarkSkin.h"
#else
#include "../Generated_DarkSkin/Source_x86/DarkSkin.h"
#endif

using namespace vl;
using namespace vl::stream;
using namespace vl::reflection::description;
using namespace vl::presentation;
using namespace vl::presentation::elements;
using namespace vl::presentation::compositions;
using namespace vl::presentation::controls;
using namespace vl::presentation::unittest;

TEST_FILE
{
	const auto resource = LR"GacUISrc(
<Resource>
  <Instance name="MainWindowResource">
    <Instance ref.Class="gacuisrc_unittest::MainWindow">
      <Window ref.Name="self" Text="GuiLabel" ClientSize="x:320 y:240">
        <Label ref.Name="label" Text="This is a label"/>
      </Window>
    </Instance>
  </Instance>
</Resource>
)GacUISrc";

	TEST_CASE(L"GuiLabel")
	{
		GacUIUnitTest_SetGuiMainProxy([](UnitTestRemoteProtocol* protocol, IUnitTestContext*)
		{
			protocol->OnNextIdleFrame(L"Ready", [=]()
			{
				auto window = GetApplication()->GetMainWindow();
				auto label = FindObjectByName<GuiLabel>(window, L"label");
				TEST_ASSERT(label->GetText() == L"This is a label");
				{
					// such font and measuring only applied in unit test environment
					auto font = label->GetDisplayFont();
					TEST_ASSERT(font.fontFamily == L"GacUI Default Font");
					TEST_ASSERT(font.size == 12);
					auto size = label->GetBoundsComposition()->GetCachedMinSize();
					TEST_ASSERT(size == Size(180, 12)); // 12*(15x1)
				}
				auto labelCT = dynamic_cast<templates::GuiLabelTemplate*>(label->GetControlTemplateObject());
				TEST_ASSERT(labelCT);
				TEST_ASSERT(label->GetTextColor() == labelCT->GetDefaultTextColor());

				label->TextChanged.AttachLambda([=](...) {window->SetText(L"TextChanged"); });
				label->SetText(L"The text is changed");
			});
			protocol->OnNextIdleFrame(L"The text is changed", [=]()
			{
				auto window = GetApplication()->GetMainWindow();
				auto label = FindObjectByName<GuiLabel>(window, L"label");

				label->SetText(L"The color is changed");
				label->SetTextColor(Color(0, 255, 0));
			});
			protocol->OnNextIdleFrame(L"The color is changed", [=]()
			{
				auto window = GetApplication()->GetMainWindow();
				auto label = FindObjectByName<GuiLabel>(window, L"label");
				TEST_ASSERT(label->GetTextColor() == Color(0, 255, 0));

				window->Hide();
			});
		});
		GacUIUnitTest_StartFast_WithResourceAsText<darkskin::Theme>(
			WString::Unmanaged(L"Controls/CoreApplication/GuiLabel"),
			WString::Unmanaged(L"gacuisrc_unittest::MainWindow"),
			resource
			);
	});
}