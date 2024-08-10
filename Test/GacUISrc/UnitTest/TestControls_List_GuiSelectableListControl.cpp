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
using namespace vl::presentation::controls::list;
using namespace vl::presentation::unittest;

TEST_FILE
{
	const auto resourceListControl= LR"GacUISrc(
<Resource>
  <Instance name="MainWindowResource">
    <Instance ref.Class="gacuisrc_unittest::MainWindow">
      <ref.Members><![CDATA[
        var counter : int = 0;
      ]]></ref.Members>
      <ref.Ctor><![CDATA[{
        for (item in range[1, 20])
        {
          list.Items.Add(new TextItem^($"Item $(item)"));
        }
      }]]></ref.Ctor>
      <Window ref.Name="self" Text="GuiSelectableListControl" ClientSize="x:320 y:240">
        <TextList ref.Name="list" HorizontalAlwaysVisible="false" VerticalAlwaysVisible="false">
          <att.BoundsComposition-set PreferredMinSize="x:400 y:300" AlignmentToParent="left:0 top:5 right:0 bottom:0"/>
          <ev.SelectionChanged-eval><![CDATA[{
            self.counter = self.counter + 1;
            var title = $"[$(self.counter)]";
            for (item in list.SelectedItems)
            {
              title = title & $" $(item)";
            }
            self.Text = title;
          }]]></ev.SelectionChanged-eval>
        </TextList>
      </Window>
    </Instance>
  </Instance>
</Resource>
)GacUISrc";

	TEST_CATEGORY(L"GuiSelectableListControl (SingleSelect)")
	{
		TEST_CASE(L"Properties")
		{
			GacUIUnitTest_SetGuiMainProxy([](UnitTestRemoteProtocol* protocol, IUnitTestContext*)
			{
				protocol->OnNextIdleFrame(L"Ready", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");
					TEST_ASSERT(listControl->GetMultiSelect() == false);

					listControl->SetSelected(0, true);
				});
				protocol->OnNextIdleFrame(L"Select 1st", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->SetSelected(1, true);
				});
				protocol->OnNextIdleFrame(L"Select 2nd", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->SetSelected(1, false);
				});
				protocol->OnNextIdleFrame(L"Unselect 2nd", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->SetSelected(2, true);
				});
				protocol->OnNextIdleFrame(L"Select 3rd", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->ClearSelection();
				});
				protocol->OnNextIdleFrame(L"Clear", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					window->Hide();
				});
			});
			GacUIUnitTest_StartFast_WithResourceAsText<darkskin::Theme>(
				WString::Unmanaged(L"Controls/List/GuiSelectableListControl/SingleSelect/Properties"),
				WString::Unmanaged(L"gacuisrc_unittest::MainWindow"),
				resourceListControl
				);
		});

		TEST_CASE(L"SelectItemsByClick")
		{
			GacUIUnitTest_SetGuiMainProxy([](UnitTestRemoteProtocol* protocol, IUnitTestContext*)
			{
				protocol->OnNextIdleFrame(L"Ready", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->SelectItemsByClick(0, false, false, true);
				});
				protocol->OnNextIdleFrame(L"Click 1st", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->SelectItemsByClick(2, true, false, true);
				});
				protocol->OnNextIdleFrame(L"Ctrl+Click 3rd", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->SelectItemsByClick(4, true, false, true);
				});
				protocol->OnNextIdleFrame(L"Ctrl+Click 5th", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->SelectItemsByClick(6, true, true, true);
				});
				protocol->OnNextIdleFrame(L"Ctrl+Shift+Click 7th", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->SelectItemsByClick(5, true, false, true);
				});
				protocol->OnNextIdleFrame(L"Ctrl+Click 6th", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->SelectItemsByClick(1, true, true, true);
				});
				protocol->OnNextIdleFrame(L"Ctrl+Shift+Click 2nd", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->SelectItemsByClick(5, false, false, true);
				});
				protocol->OnNextIdleFrame(L"Click 6th", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->SelectItemsByClick(1, true, true, true);
				});
				protocol->OnNextIdleFrame(L"Ctrl+Shift+Click 2nd", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->ClearSelection();
				});
				protocol->OnNextIdleFrame(L"Clear", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					window->Hide();
				});
			});
			GacUIUnitTest_StartFast_WithResourceAsText<darkskin::Theme>(
				WString::Unmanaged(L"Controls/List/GuiSelectableListControl/SingleSelect/SelectItemsByClick"),
				WString::Unmanaged(L"gacuisrc_unittest::MainWindow"),
				resourceListControl
				);
		});
	});

	TEST_CATEGORY(L"GuiSelectableListControl (MultiSelect)")
	{
		TEST_CASE(L"Properties")
		{
			GacUIUnitTest_SetGuiMainProxy([](UnitTestRemoteProtocol* protocol, IUnitTestContext*)
			{
				protocol->OnNextIdleFrame(L"Ready", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");
					TEST_ASSERT(listControl->GetMultiSelect() == false);
					listControl->SetMultiSelect(true);
					TEST_ASSERT(listControl->GetMultiSelect() == true);

					listControl->SetSelected(0, true);
				});
				protocol->OnNextIdleFrame(L"Select 1st", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->SetSelected(1, true);
				});
				protocol->OnNextIdleFrame(L"Select 2nd", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->SetSelected(1, false);
				});
				protocol->OnNextIdleFrame(L"Unselect 2nd", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->SetSelected(2, true);
				});
				protocol->OnNextIdleFrame(L"Select 3rd", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->ClearSelection();
				});
				protocol->OnNextIdleFrame(L"Clear", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					window->Hide();
				});
			});
			GacUIUnitTest_StartFast_WithResourceAsText<darkskin::Theme>(
				WString::Unmanaged(L"Controls/List/GuiSelectableListControl/MultiSelect/Properties"),
				WString::Unmanaged(L"gacuisrc_unittest::MainWindow"),
				resourceListControl
				);
		});

		TEST_CASE(L"SelectItemsByClick")
		{
			GacUIUnitTest_SetGuiMainProxy([](UnitTestRemoteProtocol* protocol, IUnitTestContext*)
			{
				protocol->OnNextIdleFrame(L"Ready", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");
					listControl->SetMultiSelect(true);

					listControl->SelectItemsByClick(0, false, false, true);
				});
				protocol->OnNextIdleFrame(L"Click 1st", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->SelectItemsByClick(2, true, false, true);
				});
				protocol->OnNextIdleFrame(L"Ctrl+Click 3rd", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->SelectItemsByClick(4, true, false, true);
				});
				protocol->OnNextIdleFrame(L"Ctrl+Click 5th", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->SelectItemsByClick(6, true, true, true);
				});
				protocol->OnNextIdleFrame(L"Ctrl+Shift+Click 7th", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->SelectItemsByClick(5, true, false, true);
				});
				protocol->OnNextIdleFrame(L"Ctrl+Click 6th", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->SelectItemsByClick(1, true, true, true);
				});
				protocol->OnNextIdleFrame(L"Ctrl+Shift+Click 2nd", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->SelectItemsByClick(5, false, false, true);
				});
				protocol->OnNextIdleFrame(L"Click 6th", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->SelectItemsByClick(1, true, true, true);
				});
				protocol->OnNextIdleFrame(L"Ctrl+Shift+Click 2nd", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiTextList>(window, L"list");

					listControl->ClearSelection();
				});
				protocol->OnNextIdleFrame(L"Clear", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					window->Hide();
				});
			});
			GacUIUnitTest_StartFast_WithResourceAsText<darkskin::Theme>(
				WString::Unmanaged(L"Controls/List/GuiSelectableListControl/MultiSelect/SelectItemsByClick"),
				WString::Unmanaged(L"gacuisrc_unittest::MainWindow"),
				resourceListControl
				);
		});
	});
}