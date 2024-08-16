#include "TestControls_List.h"

namespace gacui_unittest_template
{
	void GuiTextList_TestCases(
		const wchar_t* resourceXml,
		WString pathFragment,
		Func<Ptr<IValueList>(GuiWindow*)> getItems,
		Func<void(GuiWindow*, vint, vint)> notifyItemDataModified
	)
	{
		TEST_CASE(L"MakeVisibleItems")
		{
			GacUIUnitTest_SetGuiMainProxy([=](UnitTestRemoteProtocol* protocol, IUnitTestContext*)
			{
				protocol->OnNextIdleFrame(L"Ready", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					Value::From(window).Invoke(L"InitializeItems", (Value_xs(), BoxValue<vint>(5)));
				});
				protocol->OnNextIdleFrame(L"5 Items", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto items = getItems(window);
					items->Insert(0, Value::From(Ptr(new TextItem(L"First Item"))));
				});
				protocol->OnNextIdleFrame(L"Add to Top", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto items = getItems(window);
					items->Add(Value::From(Ptr(new TextItem(L"Last Item"))));
				});
				protocol->OnNextIdleFrame(L"Add to Last", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto items = getItems(window);
					items->RemoveAt(0);
					items->RemoveAt(items->GetCount() - 1);
				});
				protocol->OnNextIdleFrame(L"Remove Added Items", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiSelectableListControl>(window, L"list");
					listControl->SetSelected(2, true);
				});
				protocol->OnNextIdleFrame(L"Select 3rd", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto items = getItems(window);
					items->Set(2, Value::From(Ptr(new TextItem(L"Updated Item"))));
				});
				protocol->OnNextIdleFrame(L"Update 3rd", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiSelectableListControl>(window, L"list");
					listControl->SetSelected(2, true);
				});
				protocol->OnNextIdleFrame(L"Select 3rd", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					window->Hide();
				});
			});
			GacUIUnitTest_StartFast_WithResourceAsText<darkskin::Theme>(
				WString::Unmanaged(L"Controls/List/") + pathFragment + WString::Unmanaged(L"/MakeVisibleItems"),
				WString::Unmanaged(L"gacuisrc_unittest::MainWindow"),
				resourceXml
				);
		});

		TEST_CASE(L"MakeInvisibleItems")
		{
			GacUIUnitTest_SetGuiMainProxy([=](UnitTestRemoteProtocol* protocol, IUnitTestContext*)
			{
				protocol->OnNextIdleFrame(L"Ready", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					Value::From(window).Invoke(L"InitializeItems", (Value_xs(), BoxValue<vint>(20)));
				});
				protocol->OnNextIdleFrame(L"20 Items", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiListControl>(window, L"list");
					listControl->EnsureItemVisible(19);
				});
				protocol->OnNextIdleFrame(L"Scroll to Bottom", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiSelectableListControl>(window, L"list");
					auto items = getItems(window);
					items->Insert(0, Value::From(Ptr(new TextItem(L"First Item"))));
					listControl->SetSelected(0, true);
				});
				protocol->OnNextIdleFrame(L"Add to Top and Select", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiListControl>(window, L"list");
					listControl->EnsureItemVisible(0);
				});
				protocol->OnNextIdleFrame(L"Scroll to Top", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiSelectableListControl>(window, L"list");
					auto items = getItems(window);
					items->Add(Value::From(Ptr(new TextItem(L"Last Item"))));
					listControl->SetSelected(21, true);
				});
				protocol->OnNextIdleFrame(L"Add to Last and Select", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiListControl>(window, L"list");
					listControl->EnsureItemVisible(21);
				});
				protocol->OnNextIdleFrame(L"Scroll to Bottom", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto items = getItems(window);
					items->RemoveAt(0);
					items->RemoveAt(items->GetCount() - 1);
				});
				protocol->OnNextIdleFrame(L"Remove Added Items", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiSelectableListControl>(window, L"list");
					listControl->SetSelected(2, true);
				});
				protocol->OnNextIdleFrame(L"Select 3rd", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto items = getItems(window);
					items->Set(2, Value::From(Ptr(new TextItem(L"Updated Item"))));
				});
				protocol->OnNextIdleFrame(L"Update 3rd", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiSelectableListControl>(window, L"list");
					listControl->SetSelected(2, true);
				});
				protocol->OnNextIdleFrame(L"Select 3rd", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiListControl>(window, L"list");
					listControl->EnsureItemVisible(0);
				});
				protocol->OnNextIdleFrame(L"Scroll to Top", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					window->Hide();
				});
			});
			GacUIUnitTest_StartFast_WithResourceAsText<darkskin::Theme>(
				WString::Unmanaged(L"Controls/List/") + pathFragment + WString::Unmanaged(L"/MakeInvisibleItems"),
				WString::Unmanaged(L"gacuisrc_unittest::MainWindow"),
				resourceXml
				);
		});

		TEST_CASE(L"UpdateVisibleItems (View = Check)")
		{
			GacUIUnitTest_SetGuiMainProxy([=](UnitTestRemoteProtocol* protocol, IUnitTestContext*)
			{
				protocol->OnNextIdleFrame(L"Ready", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiVirtualTextList>(window, L"list");
					listControl->SetView(TextListView::Check);
					Value::From(window).Invoke(L"InitializeItems", (Value_xs(), BoxValue<vint>(5)));
				});
				protocol->OnNextIdleFrame(L"5 Items", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiSelectableListControl>(window, L"list");
					listControl->SetSelected(0, true);
				});
				protocol->OnNextIdleFrame(L"Select 1st", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto items = getItems(window);
					UnboxValue<Ptr<TextItem>>(items->Get(1))->SetText(L"Updated Text");
					notifyItemDataModified(window, 1, 1);
				});
				protocol->OnNextIdleFrame(L"Change 2nd Text", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto items = getItems(window);
					UnboxValue<Ptr<TextItem>>(items->Get(2))->SetChecked(true);
					notifyItemDataModified(window, 2, 1);
				});
				protocol->OnNextIdleFrame(L"Check 3rd", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto items = getItems(window);
					UnboxValue<Ptr<TextItem>>(items->Get(0))->SetText(L"New Text");
					UnboxValue<Ptr<TextItem>>(items->Get(0))->SetChecked(true);
					notifyItemDataModified(window, 0, 1);
				});
				protocol->OnNextIdleFrame(L"Change 1st Text and Check", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					window->Hide();
				});
			});
			GacUIUnitTest_StartFast_WithResourceAsText<darkskin::Theme>(
				WString::Unmanaged(L"Controls/List/") + pathFragment + WString::Unmanaged(L"/UpdateVisibleItems"),
				WString::Unmanaged(L"gacuisrc_unittest::MainWindow"),
				resourceXml
				);
		});

		TEST_CASE(L"UpdateInvisibleItems (View = Radio)")
		{
			GacUIUnitTest_SetGuiMainProxy([=](UnitTestRemoteProtocol* protocol, IUnitTestContext*)
			{
				protocol->OnNextIdleFrame(L"Ready", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiVirtualTextList>(window, L"list");
					listControl->SetView(TextListView::Radio);
					Value::From(window).Invoke(L"InitializeItems", (Value_xs(), BoxValue<vint>(20)));
				});
				protocol->OnNextIdleFrame(L"20 Items", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiSelectableListControl>(window, L"list");
					listControl->SetSelected(0, true);
					listControl->EnsureItemVisible(19);
				});
				protocol->OnNextIdleFrame(L"Select 1st and Scroll to Bottom", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto items = getItems(window);
					UnboxValue<Ptr<TextItem>>(items->Get(0))->SetText(L"New Text");
					UnboxValue<Ptr<TextItem>>(items->Get(0))->SetChecked(true);
					UnboxValue<Ptr<TextItem>>(items->Get(1))->SetText(L"Updated Text");
					UnboxValue<Ptr<TextItem>>(items->Get(2))->SetChecked(true);
					notifyItemDataModified(window, 0, 3);
				});
				protocol->OnNextIdleFrame(L"Change 1st, 2nd, 3rd", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					auto listControl = FindObjectByName<GuiListControl>(window, L"list");
					listControl->EnsureItemVisible(0);
				});
				protocol->OnNextIdleFrame(L"Scroll to Top", [=]()
				{
					auto window = GetApplication()->GetMainWindow();
					window->Hide();
				});
			});
			GacUIUnitTest_StartFast_WithResourceAsText<darkskin::Theme>(
				WString::Unmanaged(L"Controls/List/") + pathFragment + WString::Unmanaged(L"/UpdateInvisibleItems"),
				WString::Unmanaged(L"gacuisrc_unittest::MainWindow"),
				resourceXml
				);
		});
	}
}