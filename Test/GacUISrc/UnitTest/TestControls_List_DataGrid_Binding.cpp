#include "TestControls_List.h"
using namespace gacui_unittest_template;

TEST_FILE
{
	const WString resourceDataGridStringProperty = LR"GacUISrc(
<Resource>
  <Script name="DataGridItemResource"><Workflow><![CDATA[
    module datagriditem;
    using system::*;

    class DataGridItem
    {
      prop Language:string = "" {not observe}
      prop IDE:string = "" {not observe}
      prop Company:string = "" {not observe}

      new(){}
      new(language:string, ide:string, company:string)
      {
        Language=language;
        IDE=ide;
        Company=company;
      }
    }
  ]]></Workflow></Script>
  <Instance name="MainWindowResource">
    <Instance ref.Class="gacuisrc_unittest::MainWindow">
      <ref.Members><![CDATA[
        var items : observe DataGridItem^[] = {
          new DataGridItem^("C++", "Visual Studio", "Microsoft");
          new DataGridItem^("C#", "Visual Studio", "Microsoft");
          new DataGridItem^("F#", "Visual Studio", "Microsoft");
          new DataGridItem^("TypeScript", "Visual Studio Code", "Microsoft");
          new DataGridItem^("Java", "Eclipse", "IBM");
        };
      ]]></ref.Members>
      <Window ref.Name="self" Text="GuiBindableDataGrid" ClientSize="x:640 y:320">
        <BindableDataGrid ref.Name="dataGrid" env.ItemType="DataGridItem^" HorizontalAlwaysVisible="false" VerticalAlwaysVisible="false">
          <att.BoundsComposition-set AlignmentToParent="left:5 top:5 right:5 bottom:5"/>
          <att.ItemSource-eval>self.items</att.ItemSource-eval>
          <att.Columns>
            <_ Text="Language" TextProperty="Language"/>
            <_ Text="IDE" TextProperty="IDE"/>
            <_ Text="Company" TextProperty="Company"/>
          </att.Columns>
        </BindableDataGrid>
      </Window>
    </Instance>
  </Instance>
</Resource>
)GacUISrc";

	const WString resourceDataGridMixedProperty = LR"GacUISrc(
<Resource>
  <Script name="DataGridItemResource"><Workflow><![CDATA[
    module datagriditem;
    using system::*;

    class DataGridItem
    {
      prop Language:string = "" {not observe}
      prop MetaProgramming:bool = false {not observe}
      prop IDEs:int = 0 {not observe}

      new(){}
      new(language:string, metaProgramming:bool, ides:int)
      {
        Language=language;
        MetaProgramming=metaProgramming;
        IDEs=ides;
      }
    }
  ]]></Workflow></Script>
  <Instance name="MainWindowResource">
    <Instance ref.Class="gacuisrc_unittest::MainWindow">
      <ref.Members><![CDATA[
        var items : observe DataGridItem^[] = {
          new DataGridItem^("C++", true, 4);
          new DataGridItem^("C#", false, 3);
          new DataGridItem^("F#", false, 2);
          new DataGridItem^("TypeScript", true, 1);
          new DataGridItem^("Java", false, 3);
        };
      ]]></ref.Members>
      <Window ref.Name="self" Text="GuiBindableDataGrid" ClientSize="x:640 y:320">
        <BindableDataGrid ref.Name="dataGrid" env.ItemType="DataGridItem^" HorizontalAlwaysVisible="false" VerticalAlwaysVisible="false">
          <att.BoundsComposition-set AlignmentToParent="left:5 top:5 right:5 bottom:5"/>
          <att.ItemSource-eval>self.items</att.ItemSource-eval>
          <att.Columns>
            <_ Text="Language" TextProperty="Language"/>
            <_ Text="Meta Programming" TextProperty="MetaProgramming"/>
            <_ Text="IDE Count" TextProperty="IDEs"/>
          </att.Columns>
        </BindableDataGrid>
      </Window>
    </Instance>
  </Instance>
</Resource>
)GacUISrc";
	
	const WString resourceDataGridEnumProperty = LR"GacUISrc(
<Resource>
  <Script name="DataGridItemResource"><Workflow><![CDATA[
    module datagriditem;
    using system::*;

    class DataGridItem
    {
      prop Language:string = "" {not observe}
      prop IDE:string = "" {not observe}
      prop Company:string = "" {not observe}

      new(){}
      new(language:string, ide:string, company:string)
      {
        Language=language;
        IDE=ide;
        Company=company;
      }
    }
  ]]></Workflow></Script>
  <Instance name="MainWindowResource">
    <Instance ref.Class="gacuisrc_unittest::MainWindow">
      <ref.Members><![CDATA[
        var items : observe DataGridItem^[] = {
          new DataGridItem^("C++", "Visual Studio", "Microsoft");
          new DataGridItem^("C#", "Visual Studio", "Microsoft");
          new DataGridItem^("F#", "Visual Studio", "Microsoft");
          new DataGridItem^("TypeScript", "Visual Studio Code", "Microsoft");
          new DataGridItem^("Java", "Eclipse", "IBM");
        };
      ]]></ref.Members>
      <Window ref.Name="self" Text="GuiBindableDataGrid" ClientSize="x:640 y:320">
        <BindableDataGrid ref.Name="dataGrid" env.ItemType="DataGridItem^" HorizontalAlwaysVisible="false" VerticalAlwaysVisible="false">
          <att.BoundsComposition-set AlignmentToParent="left:5 top:5 right:5 bottom:5"/>
          <att.ItemSource-eval>self.items</att.ItemSource-eval>
          <att.Columns>
            <_ Text="Language" TextProperty="Language"/>
            <_ Text="IDE" TextProperty="IDE"/>
            <_ Text="Company" TextProperty="Company"/>
          </att.Columns>
        </BindableDataGrid>
      </Window>
    </Instance>
  </Instance>
</Resource>
)GacUISrc";

	TEST_CATEGORY(L"GuiBindableDataGrid")
	{
		TEST_CASE(L"DisplayStringProperties")
		{
			GacUIUnitTest_SetGuiMainProxy([](UnitTestRemoteProtocol* protocol, IUnitTestContext*)
			{
				protocol->OnNextIdleFrame(L"Ready", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					window->Hide();
				});
			});
			GacUIUnitTest_StartFast_WithResourceAsText<darkskin::Theme>(
				WString::Unmanaged(L"Controls/List/GuiBindableDataGrid/Binding/DisplayStringProperties"),
				WString::Unmanaged(L"gacuisrc_unittest::MainWindow"),
				resourceDataGridStringProperty
				);
		});
		
		TEST_CASE(L"DisplayMixedProperties")
		{
			GacUIUnitTest_SetGuiMainProxy([](UnitTestRemoteProtocol* protocol, IUnitTestContext*)
			{
				protocol->OnNextIdleFrame(L"Ready", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					window->Hide();
				});
			});
			GacUIUnitTest_StartFast_WithResourceAsText<darkskin::Theme>(
				WString::Unmanaged(L"Controls/List/GuiBindableDataGrid/Binding/DisplayMixedProperties"),
				WString::Unmanaged(L"gacuisrc_unittest::MainWindow"),
				resourceDataGridMixedProperty
				);
		});

		TEST_CASE(L"DisplayEmumProperties")
		{
			GacUIUnitTest_SetGuiMainProxy([](UnitTestRemoteProtocol* protocol, IUnitTestContext*)
			{
				protocol->OnNextIdleFrame(L"Ready", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					window->Hide();
				});
			});
			GacUIUnitTest_StartFast_WithResourceAsText<darkskin::Theme>(
				WString::Unmanaged(L"Controls/List/GuiBindableDataGrid/Binding/DisplayEmumProperties"),
				WString::Unmanaged(L"gacuisrc_unittest::MainWindow"),
				resourceDataGridEnumProperty
				);
		});
	});
}