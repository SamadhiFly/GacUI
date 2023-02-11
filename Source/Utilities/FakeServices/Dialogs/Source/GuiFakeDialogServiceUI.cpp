/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

GacGen.exe Resource.xml

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "GuiFakeDialogServiceUIIncludes.h"
/* CodePack:BeginIgnore() */
#ifndef VCZH_DEBUG_NO_REFLECTION
/* CodePack:ConditionOff(VCZH_DEBUG_NO_REFLECTION, GuiFakeDialogServiceUIReflection.h) */
#include "GuiFakeDialogServiceUIReflection.h"
#endif
/* CodePack:EndIgnore() */

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#endif

#define GLOBAL_SYMBOL ::vl_workflow_global::GuiFakeDialogServiceUI::
#define GLOBAL_NAME ::vl_workflow_global::GuiFakeDialogServiceUI::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::GuiFakeDialogServiceUI::Instance()

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_GuiFakeDialogServiceUI)
	vl_workflow_global::GuiFakeDialogServiceUI instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_GuiFakeDialogServiceUI)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	GuiFakeDialogServiceUI& GuiFakeDialogServiceUI::Instance()
	{
		return Getvl_workflow_global_GuiFakeDialogServiceUI().instance;
	}

/***********************************************************************
Closures
***********************************************************************/

	//-------------------------------------------------------------------

	__vwsnf1_GuiFakeDialogServiceUI_gaclib_controls_GuiMessageBoxWindowConstructor___vwsn_gaclib_controls_GuiMessageBoxWindow_Initialize_::__vwsnf1_GuiFakeDialogServiceUI_gaclib_controls_GuiMessageBoxWindowConstructor___vwsn_gaclib_controls_GuiMessageBoxWindow_Initialize_(::gaclib_controls::GuiMessageBoxWindowConstructor* __vwsnctorthis_0)
		:__vwsnthis_0(::vl::__vwsn::This(__vwsnctorthis_0))
	{
	}

	void __vwsnf1_GuiFakeDialogServiceUI_gaclib_controls_GuiMessageBoxWindowConstructor___vwsn_gaclib_controls_GuiMessageBoxWindow_Initialize_::operator()(const ::vl::reflection::description::Value& __vwsn_value_) const
	{
		auto __vwsn_old_ = ::vl::__vwsn::This(__vwsnthis_0->self)->GetStrings();
		auto __vwsn_new_ = ::vl::__vwsn::Unbox<::vl::Ptr<::gaclib_controls::IDialogStringsStrings>>(__vwsn_value_);
		if ((__vwsn_old_.Obj() == __vwsn_new_.Obj()))
		{
			return;
		}
		::vl::__vwsn::This(__vwsnthis_0->self)->SetStrings(__vwsn_new_);
	}

	//-------------------------------------------------------------------

	__vwsnc1_GuiFakeDialogServiceUI_gaclib_controls_GuiMessageBoxWindowConstructor___vwsn_gaclib_controls_GuiMessageBoxWindow_Initialize__vl_reflection_description_IValueSubscription::__vwsnc1_GuiFakeDialogServiceUI_gaclib_controls_GuiMessageBoxWindowConstructor___vwsn_gaclib_controls_GuiMessageBoxWindow_Initialize__vl_reflection_description_IValueSubscription(::gaclib_controls::GuiMessageBoxWindowConstructor* __vwsnctorthis_0)
		:__vwsnthis_0(::vl::__vwsn::This(__vwsnctorthis_0))
	{
		this->__vwsn_bind_cache_0 = static_cast<::vl::presentation::controls::GuiApplication*>(nullptr);
		this->__vwsn_bind_handler_0_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>();
		this->__vwsn_bind_opened_ = false;
		this->__vwsn_bind_closed_ = false;
	}

	void __vwsnc1_GuiFakeDialogServiceUI_gaclib_controls_GuiMessageBoxWindowConstructor___vwsn_gaclib_controls_GuiMessageBoxWindow_Initialize__vl_reflection_description_IValueSubscription::__vwsn_bind_activator_()
	{
		auto __vwsn_bind_activator_result_ = ::gaclib_controls::DialogStrings::Get(::vl::__vwsn::This(__vwsn_bind_cache_0)->GetLocale());
		::vl::__vwsn::EventInvoke(this->ValueChanged)(::vl::__vwsn::Box(__vwsn_bind_activator_result_));
	}

	void __vwsnc1_GuiFakeDialogServiceUI_gaclib_controls_GuiMessageBoxWindowConstructor___vwsn_gaclib_controls_GuiMessageBoxWindow_Initialize__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_0_0()
	{
		this->__vwsn_bind_activator_();
	}

	bool __vwsnc1_GuiFakeDialogServiceUI_gaclib_controls_GuiMessageBoxWindowConstructor___vwsn_gaclib_controls_GuiMessageBoxWindow_Initialize__vl_reflection_description_IValueSubscription::Open()
	{
		if ((! __vwsn_bind_opened_))
		{
			(__vwsn_bind_opened_ = true);
			(__vwsn_bind_cache_0 = [&](){ try{ return ::vl::presentation::controls::GetApplication(); } catch(...){ return static_cast<::vl::presentation::controls::GuiApplication*>(nullptr); } }());
			(__vwsn_bind_handler_0_0 = [&](){ try{ return ::vl::__vwsn::EventAttach(::vl::__vwsn::This(__vwsn_bind_cache_0)->LocaleChanged, ::vl::Func<void()>(this, &__vwsnc1_GuiFakeDialogServiceUI_gaclib_controls_GuiMessageBoxWindowConstructor___vwsn_gaclib_controls_GuiMessageBoxWindow_Initialize__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_0_0)); } catch(...){ return ::vl::Ptr<::vl::reflection::description::IEventHandler>(); } }());
			return true;
		}
		return false;
	}

	bool __vwsnc1_GuiFakeDialogServiceUI_gaclib_controls_GuiMessageBoxWindowConstructor___vwsn_gaclib_controls_GuiMessageBoxWindow_Initialize__vl_reflection_description_IValueSubscription::Update()
	{
		if ((__vwsn_bind_opened_ && (! __vwsn_bind_closed_)))
		{
			this->__vwsn_bind_activator_();
			return true;
		}
		return false;
	}

	bool __vwsnc1_GuiFakeDialogServiceUI_gaclib_controls_GuiMessageBoxWindowConstructor___vwsn_gaclib_controls_GuiMessageBoxWindow_Initialize__vl_reflection_description_IValueSubscription::Close()
	{
		if ((! __vwsn_bind_closed_))
		{
			(__vwsn_bind_closed_ = true);
			if (static_cast<bool>(__vwsn_bind_handler_0_0))
			{
				::vl::__vwsn::EventDetach(::vl::__vwsn::This(__vwsn_bind_cache_0)->LocaleChanged, __vwsn_bind_handler_0_0);
				(__vwsn_bind_handler_0_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			}
			(__vwsn_bind_cache_0 = static_cast<::vl::presentation::controls::GuiApplication*>(nullptr));
			(__vwsn_bind_handler_0_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			return true;
		}
		return false;
	}

	//-------------------------------------------------------------------

	__vwsnc2_GuiFakeDialogServiceUI_gaclib_controls_DialogStrings_Get__gaclib_controls_IDialogStringsStrings::__vwsnc2_GuiFakeDialogServiceUI_gaclib_controls_DialogStrings_Get__gaclib_controls_IDialogStringsStrings()
	{
	}

	::vl::WString __vwsnc2_GuiFakeDialogServiceUI_gaclib_controls_DialogStrings_Get__gaclib_controls_IDialogStringsStrings::Abort()
	{
		return ::vl::WString::Unmanaged(L"Abort");
	}

	::vl::WString __vwsnc2_GuiFakeDialogServiceUI_gaclib_controls_DialogStrings_Get__gaclib_controls_IDialogStringsStrings::Cancel()
	{
		return ::vl::WString::Unmanaged(L"Cancel");
	}

	::vl::WString __vwsnc2_GuiFakeDialogServiceUI_gaclib_controls_DialogStrings_Get__gaclib_controls_IDialogStringsStrings::Continue()
	{
		return ::vl::WString::Unmanaged(L"Continue");
	}

	::vl::WString __vwsnc2_GuiFakeDialogServiceUI_gaclib_controls_DialogStrings_Get__gaclib_controls_IDialogStringsStrings::Ignore()
	{
		return ::vl::WString::Unmanaged(L"Ignore");
	}

	::vl::WString __vwsnc2_GuiFakeDialogServiceUI_gaclib_controls_DialogStrings_Get__gaclib_controls_IDialogStringsStrings::No()
	{
		return ::vl::WString::Unmanaged(L"No");
	}

	::vl::WString __vwsnc2_GuiFakeDialogServiceUI_gaclib_controls_DialogStrings_Get__gaclib_controls_IDialogStringsStrings::OK()
	{
		return ::vl::WString::Unmanaged(L"OK");
	}

	::vl::WString __vwsnc2_GuiFakeDialogServiceUI_gaclib_controls_DialogStrings_Get__gaclib_controls_IDialogStringsStrings::Retry()
	{
		return ::vl::WString::Unmanaged(L"Retry");
	}

	::vl::WString __vwsnc2_GuiFakeDialogServiceUI_gaclib_controls_DialogStrings_Get__gaclib_controls_IDialogStringsStrings::TryAgain()
	{
		return ::vl::WString::Unmanaged(L"Try Again");
	}

	::vl::WString __vwsnc2_GuiFakeDialogServiceUI_gaclib_controls_DialogStrings_Get__gaclib_controls_IDialogStringsStrings::Yes()
	{
		return ::vl::WString::Unmanaged(L"Yes");
	}

}

/***********************************************************************
Class (::gaclib_controls::DialogStrings)
***********************************************************************/

namespace gaclib_controls
{
	::vl::WString DialogStrings::__vwsn_ls_First(const ::vl::collections::LazyList<::vl::WString>& __vwsn_ls_formats)
	{
		{
			auto __vwsn_for_enumerable_ = ::vl::__vwsn::UnboxCollection<::vl::reflection::description::IValueEnumerable>(__vwsn_ls_formats);
			auto __vwsn_for_enumerator_ = ::vl::__vwsn::This(__vwsn_for_enumerable_.Obj())->CreateEnumerator();
			while (::vl::__vwsn::This(__vwsn_for_enumerator_.Obj())->Next())
			{
				auto __vwsn_ls_format = ::vl::__vwsn::Unbox<::vl::WString>(::vl::__vwsn::This(__vwsn_for_enumerator_.Obj())->GetCurrent());
				{
					return __vwsn_ls_format;
				}
			}
		}
		return ::vl::WString::Unmanaged(L"");
	}

	::vl::Ptr<::gaclib_controls::IDialogStringsStrings> DialogStrings::Get(::vl::Locale __vwsn_ls_locale)
	{
		return ::vl::Ptr<::gaclib_controls::IDialogStringsStrings>(new ::vl_workflow_global::__vwsnc2_GuiFakeDialogServiceUI_gaclib_controls_DialogStrings_Get__gaclib_controls_IDialogStringsStrings());
	}

	DialogStrings::DialogStrings()
	{
	}

/***********************************************************************
Class (::gaclib_controls::GuiMessageBoxWindowConstructor)
***********************************************************************/

	void GuiMessageBoxWindowConstructor::__vwsn_gaclib_controls_GuiMessageBoxWindow_Initialize(::gaclib_controls::GuiMessageBoxWindow* __vwsn_this_)
	{
		(this->self = __vwsn_this_);
		(this->ViewModel = ::vl::__vwsn::This(__vwsn_this_)->GetViewModel());
		{
			::vl::__vwsn::This(this->self)->SetClientSize([&](){ ::vl::presentation::Size __vwsn_temp__; __vwsn_temp__.x = static_cast<::vl::vint>(240); __vwsn_temp__.y = static_cast<::vl::vint>(120); return __vwsn_temp__; }());
		}
		(this->__vwsn_precompile_0 = new ::vl::presentation::compositions::GuiTableComposition());
		{
			::vl::__vwsn::This(this->__vwsn_precompile_0)->SetMinSizeLimitation(::vl::presentation::compositions::GuiGraphicsComposition::MinSizeLimitation::LimitToElementAndChildren);
		}
		{
			::vl::__vwsn::This(this->__vwsn_precompile_0)->SetCellPadding(static_cast<::vl::vint>(5));
		}
		{
			::vl::__vwsn::This(this->__vwsn_precompile_0)->SetAlignmentToParent([&](){ ::vl::presentation::Margin __vwsn_temp__; __vwsn_temp__.left = static_cast<::vl::vint>(5); __vwsn_temp__.top = static_cast<::vl::vint>(5); __vwsn_temp__.right = static_cast<::vl::vint>(5); __vwsn_temp__.bottom = static_cast<::vl::vint>(5); return __vwsn_temp__; }());
		}
		{
			::vl::__vwsn::This(this->__vwsn_precompile_0)->SetRowsAndColumns(static_cast<::vl::vint>(3), static_cast<::vl::vint>(2));
			::vl::__vwsn::This(this->__vwsn_precompile_0)->SetRowOption(static_cast<::vl::vint>(0), [&](){ ::vl::presentation::compositions::GuiCellOption __vwsn_temp__; __vwsn_temp__.composeType = ::vl::presentation::compositions::GuiCellOption::ComposeType::MinSize; return __vwsn_temp__; }());
			::vl::__vwsn::This(this->__vwsn_precompile_0)->SetRowOption(static_cast<::vl::vint>(1), [&](){ ::vl::presentation::compositions::GuiCellOption __vwsn_temp__; __vwsn_temp__.composeType = ::vl::presentation::compositions::GuiCellOption::ComposeType::Percentage; __vwsn_temp__.percentage = static_cast<double>(1.0); return __vwsn_temp__; }());
			::vl::__vwsn::This(this->__vwsn_precompile_0)->SetRowOption(static_cast<::vl::vint>(2), [&](){ ::vl::presentation::compositions::GuiCellOption __vwsn_temp__; __vwsn_temp__.composeType = ::vl::presentation::compositions::GuiCellOption::ComposeType::MinSize; return __vwsn_temp__; }());
			::vl::__vwsn::This(this->__vwsn_precompile_0)->SetColumnOption(static_cast<::vl::vint>(0), [&](){ ::vl::presentation::compositions::GuiCellOption __vwsn_temp__; __vwsn_temp__.composeType = ::vl::presentation::compositions::GuiCellOption::ComposeType::MinSize; return __vwsn_temp__; }());
			::vl::__vwsn::This(this->__vwsn_precompile_0)->SetColumnOption(static_cast<::vl::vint>(1), [&](){ ::vl::presentation::compositions::GuiCellOption __vwsn_temp__; __vwsn_temp__.composeType = ::vl::presentation::compositions::GuiCellOption::ComposeType::Percentage; __vwsn_temp__.percentage = static_cast<double>(1.0); return __vwsn_temp__; }());
		}
		(this->__vwsn_precompile_1 = new ::vl::presentation::compositions::GuiCellComposition());
		{
			::vl::__vwsn::This(this->__vwsn_precompile_1)->SetSite(static_cast<::vl::vint>(0), static_cast<::vl::vint>(0), static_cast<::vl::vint>(1), static_cast<::vl::vint>(1));
		}
		(this->__vwsn_precompile_2 = ::vl::Ptr<::vl::presentation::elements::GuiImageFrameElement>(::vl::reflection::description::Element_Constructor<::vl::presentation::elements::GuiImageFrameElement>()));
		{
			::vl::__vwsn::This(this->__vwsn_precompile_1)->SetOwnedElement(::vl::Ptr<::vl::presentation::elements::IGuiGraphicsElement>(this->__vwsn_precompile_2));
		}
		{
			::vl::__vwsn::This(this->__vwsn_precompile_0)->AddChild(static_cast<::vl::presentation::compositions::GuiGraphicsComposition*>(this->__vwsn_precompile_1));
		}
		(this->__vwsn_precompile_3 = new ::vl::presentation::compositions::GuiCellComposition());
		{
			::vl::__vwsn::This(this->__vwsn_precompile_3)->SetSite(static_cast<::vl::vint>(0), static_cast<::vl::vint>(1), static_cast<::vl::vint>(1), static_cast<::vl::vint>(1));
		}
		{
			(this->__vwsn_precompile_4 = new ::vl::presentation::controls::GuiLabel(::vl::presentation::theme::ThemeName::Label));
		}
		(this->__vwsn_precompile_5 = ::vl::__vwsn::This(this->__vwsn_precompile_4)->GetBoundsComposition());
		{
			::vl::__vwsn::This(this->__vwsn_precompile_5)->SetAlignmentToParent([&](){ ::vl::presentation::Margin __vwsn_temp__; __vwsn_temp__.left = static_cast<::vl::vint>(0); __vwsn_temp__.top = static_cast<::vl::vint>(0); __vwsn_temp__.right = static_cast<::vl::vint>(0); __vwsn_temp__.bottom = static_cast<::vl::vint>(0); return __vwsn_temp__; }());
		}
		{
			::vl::__vwsn::This(this->__vwsn_precompile_3)->AddChild(static_cast<::vl::presentation::compositions::GuiGraphicsComposition*>(::vl::__vwsn::This(this->__vwsn_precompile_4)->GetBoundsComposition()));
		}
		{
			::vl::__vwsn::This(this->__vwsn_precompile_0)->AddChild(static_cast<::vl::presentation::compositions::GuiGraphicsComposition*>(this->__vwsn_precompile_3));
		}
		{
			::vl::__vwsn::This(::vl::__vwsn::This(this->self)->GetContainerComposition())->AddChild(static_cast<::vl::presentation::compositions::GuiGraphicsComposition*>(this->__vwsn_precompile_0));
		}
		{
			::vl::__vwsn::This(this->__vwsn_precompile_2.Obj())->SetImage(::vl::__vwsn::This(::vl::__vwsn::Ensure(::vl::__vwsn::SharedPtrCast<::vl::presentation::GuiImageData>(::vl::__vwsn::This(__vwsn_this_)->ResolveResource(::vl::WString::Unmanaged(L"res"), ::vl::WString::Unmanaged(L"Images/None"), true).Obj())).Obj())->GetImage());
		}
		{
			::vl::__vwsn::This(this->__vwsn_precompile_4)->SetText(::vl::__vwsn::This(this->ViewModel.Obj())->GetText());
		}
		{
			::vl::__vwsn::This(this->self)->SetText(::vl::__vwsn::This(this->ViewModel.Obj())->GetTitle());
		}
		{
			auto __vwsn_created_subscription_ = ::vl::Ptr<::vl::reflection::description::IValueSubscription>(new ::vl_workflow_global::__vwsnc1_GuiFakeDialogServiceUI_gaclib_controls_GuiMessageBoxWindowConstructor___vwsn_gaclib_controls_GuiMessageBoxWindow_Initialize__vl_reflection_description_IValueSubscription(this));
			::vl::__vwsn::EventAttach(::vl::__vwsn::This(__vwsn_created_subscription_.Obj())->ValueChanged, vl::Func(::vl_workflow_global::__vwsnf1_GuiFakeDialogServiceUI_gaclib_controls_GuiMessageBoxWindowConstructor___vwsn_gaclib_controls_GuiMessageBoxWindow_Initialize_(this)));
			::vl::__vwsn::This(__vwsn_this_)->AddSubscription(__vwsn_created_subscription_);
		}
	}

	GuiMessageBoxWindowConstructor::GuiMessageBoxWindowConstructor()
		: ViewModel(::vl::Ptr<::vl::presentation::IMessageBoxDialogViewModel>())
		, self(static_cast<::gaclib_controls::GuiMessageBoxWindow*>(nullptr))
		, __vwsn_precompile_0(static_cast<::vl::presentation::compositions::GuiTableComposition*>(nullptr))
		, __vwsn_precompile_1(static_cast<::vl::presentation::compositions::GuiCellComposition*>(nullptr))
		, __vwsn_precompile_2(::vl::Ptr<::vl::presentation::elements::GuiImageFrameElement>())
		, __vwsn_precompile_3(static_cast<::vl::presentation::compositions::GuiCellComposition*>(nullptr))
		, __vwsn_precompile_4(static_cast<::vl::presentation::controls::GuiLabel*>(nullptr))
		, __vwsn_precompile_5(static_cast<::vl::presentation::compositions::GuiBoundsComposition*>(nullptr))
	{
	}

/***********************************************************************
Class (::gaclib_controls::GuiMessageBoxWindow)
***********************************************************************/

	::vl::Ptr<::gaclib_controls::IDialogStringsStrings> GuiMessageBoxWindow::GetStrings()
	{
		return this->__vwsn_prop_Strings;
	}
	void GuiMessageBoxWindow::SetStrings(::vl::Ptr<::gaclib_controls::IDialogStringsStrings> __vwsn_value_)
	{
		if ((this->__vwsn_prop_Strings.Obj() != __vwsn_value_.Obj()))
		{
			(this->__vwsn_prop_Strings = __vwsn_value_);
			::vl::__vwsn::EventInvoke(this->StringsChanged)();
		}
	}

	::vl::Ptr<::vl::presentation::IMessageBoxDialogViewModel> GuiMessageBoxWindow::GetViewModel()
	{
		return this->__vwsn_parameter_ViewModel;
	}

	GuiMessageBoxWindow::GuiMessageBoxWindow(::vl::Ptr<::vl::presentation::IMessageBoxDialogViewModel> __vwsn_ctor_parameter_ViewModel)
		: ::vl::presentation::controls::GuiWindow(::vl::presentation::theme::ThemeName::Window)
		, __vwsn_prop_Strings(::gaclib_controls::DialogStrings::Get(::vl::__vwsn::Parse<::vl::Locale>(::vl::WString::Unmanaged(L"en-US"))))
		, __vwsn_parameter_ViewModel(::vl::Ptr<::vl::presentation::IMessageBoxDialogViewModel>())
	{
		(this->__vwsn_parameter_ViewModel = __vwsn_ctor_parameter_ViewModel);
		auto __vwsn_resource_ = ::vl::__vwsn::This(::vl::presentation::GetResourceManager())->GetResourceFromClassName(::vl::WString::Unmanaged(L"gaclib_controls::GuiMessageBoxWindow"));
		auto __vwsn_resolver_ = ::vl::Ptr<::vl::presentation::GuiResourcePathResolver>(new ::vl::presentation::GuiResourcePathResolver(__vwsn_resource_, ::vl::__vwsn::This(__vwsn_resource_.Obj())->GetWorkingDirectory()));
		::vl::__vwsn::This(this)->SetResourceResolver(__vwsn_resolver_);
		::vl::__vwsn::This(this)->__vwsn_gaclib_controls_GuiMessageBoxWindow_Initialize(this);
	}

	GuiMessageBoxWindow::~GuiMessageBoxWindow()
	{
		this->FinalizeInstanceRecursively(static_cast<::vl::presentation::controls::GuiControlHost*>(this));
	}

/***********************************************************************
Class (::gaclib_controls::IDialogStringsStrings)
***********************************************************************/

}
#undef GLOBAL_SYMBOL
#undef GLOBAL_NAME
#undef GLOBAL_OBJ

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__clang__)
#pragma clang diagnostic pop
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
