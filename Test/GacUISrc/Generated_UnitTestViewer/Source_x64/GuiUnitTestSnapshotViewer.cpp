﻿/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: GacUI UnitTestSnapshotViewer

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "GuiUnitTestSnapshotViewerIncludes.h"
/* CodePack:BeginIgnore() */
#ifndef VCZH_DEBUG_NO_REFLECTION
/* CodePack:ConditionOff(VCZH_DEBUG_NO_REFLECTION, GuiUnitTestSnapshotViewerReflection.h) */
#include "GuiUnitTestSnapshotViewerReflection.h"
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

#define GLOBAL_SYMBOL ::vl_workflow_global::GuiUnitTestSnapshotViewer::
#define GLOBAL_NAME ::vl_workflow_global::GuiUnitTestSnapshotViewer::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::GuiUnitTestSnapshotViewer::Instance()

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_GuiUnitTestSnapshotViewer)
	vl_workflow_global::GuiUnitTestSnapshotViewer instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS

		instance.__vwsn_ls_UnitTestSnapshotViewerStrings = ::vl::reflection::description::IValueDictionary::Create();

		([]()
		{
			::gaclib_controls::UnitTestSnapshotViewerStrings::Install(::vl::__vwsn::Parse<::vl::Locale>(::vl::WString::Unmanaged(L"en-US")), ::gaclib_controls::UnitTestSnapshotViewerStrings::__vwsn_ls_en_US_BuildStrings(::vl::__vwsn::Parse<::vl::Locale>(::vl::WString::Unmanaged(L"en-US"))));
		}
		)();
	FINALIZE_GLOBAL_STORAGE_CLASS

		instance.__vwsn_ls_UnitTestSnapshotViewerStrings = nullptr;
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_GuiUnitTestSnapshotViewer)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	GuiUnitTestSnapshotViewer& GuiUnitTestSnapshotViewer::Instance()
	{
		return Getvl_workflow_global_GuiUnitTestSnapshotViewer().instance;
	}

/***********************************************************************
Closures
***********************************************************************/

	//-------------------------------------------------------------------

	__vwsnf1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize_::__vwsnf1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize_(::gaclib_controls::UnitTestSnapshotViewerWindowConstructor* __vwsnctorthis_0)
		:__vwsnthis_0(::vl::__vwsn::This(__vwsnctorthis_0))
	{
	}

	void __vwsnf1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize_::operator()(const ::vl::reflection::description::Value& __vwsn_value_) const
	{
		auto __vwsn_old_ = ::vl::__vwsn::This(__vwsnthis_0->self)->GetText();
		auto __vwsn_new_ = ::vl::__vwsn::Unbox<::vl::WString>(__vwsn_value_);
		if ((__vwsn_old_ == __vwsn_new_))
		{
			return;
		}
		::vl::__vwsn::This(__vwsnthis_0->self)->SetText(__vwsn_new_);
	}

	//-------------------------------------------------------------------

	__vwsnf2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize_::__vwsnf2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize_(::gaclib_controls::UnitTestSnapshotViewerWindowConstructor* __vwsnctorthis_0)
		:__vwsnthis_0(::vl::__vwsn::This(__vwsnctorthis_0))
	{
	}

	void __vwsnf2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize_::operator()(const ::vl::reflection::description::Value& __vwsn_value_) const
	{
		auto __vwsn_old_ = ::vl::__vwsn::This(__vwsnthis_0->self)->GetStrings();
		auto __vwsn_new_ = ::vl::__vwsn::Unbox<::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerStringsStrings>>(__vwsn_value_);
		if ((__vwsn_old_.Obj() == __vwsn_new_.Obj()))
		{
			return;
		}
		::vl::__vwsn::This(__vwsnthis_0->self)->SetStrings(__vwsn_new_);
	}

	//-------------------------------------------------------------------

	__vwsnc1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription::__vwsnc1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription(::gaclib_controls::UnitTestSnapshotViewerWindow* __vwsnctor___vwsn_this_, ::gaclib_controls::UnitTestSnapshotViewerWindowConstructor* __vwsnctorthis_0)
		:__vwsn_this_(__vwsnctor___vwsn_this_)
		, __vwsnthis_0(::vl::__vwsn::This(__vwsnctorthis_0))
	{
		this->__vwsn_bind_cache_0 = static_cast<::gaclib_controls::UnitTestSnapshotViewerWindow*>(nullptr);
		this->__vwsn_bind_handler_0_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>();
		this->__vwsn_bind_opened_ = false;
		this->__vwsn_bind_closed_ = false;
	}

	void __vwsnc1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription::__vwsn_bind_activator_()
	{
		auto __vwsn_bind_activator_result_ = ::vl::__vwsn::This(::vl::__vwsn::This(__vwsn_bind_cache_0)->GetStrings().Obj())->WindowTitle();
		::vl::__vwsn::EventInvoke(this->ValueChanged)(::vl::__vwsn::Box(__vwsn_bind_activator_result_));
	}

	void __vwsnc1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_0_0()
	{
		this->__vwsn_bind_activator_();
	}

	bool __vwsnc1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription::Open()
	{
		if ((! __vwsn_bind_opened_))
		{
			(__vwsn_bind_opened_ = true);
			(__vwsn_bind_cache_0 = [&](){ try{ return __vwsn_this_; } catch(...){ return static_cast<::gaclib_controls::UnitTestSnapshotViewerWindow*>(nullptr); } }());
			(__vwsn_bind_handler_0_0 = [&](){ try{ return ::vl::__vwsn::EventAttach(::vl::__vwsn::This(__vwsn_bind_cache_0)->StringsChanged, ::vl::Func<void()>(this, &__vwsnc1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_0_0)); } catch(...){ return ::vl::Ptr<::vl::reflection::description::IEventHandler>(); } }());
			return true;
		}
		return false;
	}

	bool __vwsnc1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription::Update()
	{
		if ((__vwsn_bind_opened_ && (! __vwsn_bind_closed_)))
		{
			this->__vwsn_bind_activator_();
			return true;
		}
		return false;
	}

	bool __vwsnc1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription::Close()
	{
		if ((! __vwsn_bind_closed_))
		{
			(__vwsn_bind_closed_ = true);
			if (static_cast<bool>(__vwsn_bind_handler_0_0))
			{
				::vl::__vwsn::EventDetach(::vl::__vwsn::This(__vwsn_bind_cache_0)->StringsChanged, __vwsn_bind_handler_0_0);
				(__vwsn_bind_handler_0_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			}
			(__vwsn_bind_cache_0 = static_cast<::gaclib_controls::UnitTestSnapshotViewerWindow*>(nullptr));
			(__vwsn_bind_handler_0_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			return true;
		}
		return false;
	}

	//-------------------------------------------------------------------

	__vwsnc2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription::__vwsnc2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription(::gaclib_controls::UnitTestSnapshotViewerWindowConstructor* __vwsnctorthis_0)
		:__vwsnthis_0(::vl::__vwsn::This(__vwsnctorthis_0))
	{
		this->__vwsn_bind_cache_0 = static_cast<::vl::presentation::controls::GuiApplication*>(nullptr);
		this->__vwsn_bind_handler_0_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>();
		this->__vwsn_bind_opened_ = false;
		this->__vwsn_bind_closed_ = false;
	}

	void __vwsnc2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription::__vwsn_bind_activator_()
	{
		auto __vwsn_bind_activator_result_ = ::gaclib_controls::UnitTestSnapshotViewerStrings::Get(::vl::__vwsn::This(__vwsn_bind_cache_0)->GetLocale());
		::vl::__vwsn::EventInvoke(this->ValueChanged)(::vl::__vwsn::Box(__vwsn_bind_activator_result_));
	}

	void __vwsnc2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_0_0()
	{
		this->__vwsn_bind_activator_();
	}

	bool __vwsnc2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription::Open()
	{
		if ((! __vwsn_bind_opened_))
		{
			(__vwsn_bind_opened_ = true);
			(__vwsn_bind_cache_0 = [&](){ try{ return ::vl::presentation::controls::GetApplication(); } catch(...){ return static_cast<::vl::presentation::controls::GuiApplication*>(nullptr); } }());
			(__vwsn_bind_handler_0_0 = [&](){ try{ return ::vl::__vwsn::EventAttach(::vl::__vwsn::This(__vwsn_bind_cache_0)->LocaleChanged, ::vl::Func<void()>(this, &__vwsnc2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_0_0)); } catch(...){ return ::vl::Ptr<::vl::reflection::description::IEventHandler>(); } }());
			return true;
		}
		return false;
	}

	bool __vwsnc2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription::Update()
	{
		if ((__vwsn_bind_opened_ && (! __vwsn_bind_closed_)))
		{
			this->__vwsn_bind_activator_();
			return true;
		}
		return false;
	}

	bool __vwsnc2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription::Close()
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

	__vwsnc3_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerStrings___vwsn_ls_en_US_BuildStrings__gaclib_controls_IUnitTestSnapshotViewerStringsStrings::__vwsnc3_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerStrings___vwsn_ls_en_US_BuildStrings__gaclib_controls_IUnitTestSnapshotViewerStringsStrings()
	{
	}

	::vl::WString __vwsnc3_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerStrings___vwsn_ls_en_US_BuildStrings__gaclib_controls_IUnitTestSnapshotViewerStringsStrings::WindowTitle()
	{
		return ::vl::WString::Unmanaged(L"Unit Test Snapshot Viewer");
	}

}

/***********************************************************************
Class (::gaclib_controls::IUnitTestSnapshotViewerStringsStrings)
***********************************************************************/

namespace gaclib_controls
{
/***********************************************************************
Class (::gaclib_controls::IUnitTestSnapshotViewerViewModel)
***********************************************************************/

/***********************************************************************
Class (::gaclib_controls::UnitTestSnapshotViewerStrings)
***********************************************************************/

	::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerStringsStrings> UnitTestSnapshotViewerStrings::__vwsn_ls_en_US_BuildStrings(::vl::Locale __vwsn_ls_locale)
	{
		return ::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerStringsStrings>(new ::vl_workflow_global::__vwsnc3_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerStrings___vwsn_ls_en_US_BuildStrings__gaclib_controls_IUnitTestSnapshotViewerStringsStrings());
	}

	void UnitTestSnapshotViewerStrings::Install(::vl::Locale __vwsn_ls_locale, ::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerStringsStrings> __vwsn_ls_impl)
	{
		if (::vl::__vwsn::This(::vl::__vwsn::This(GLOBAL_NAME __vwsn_ls_UnitTestSnapshotViewerStrings.Obj())->GetKeys().Obj())->Contains(::vl::__vwsn::Box(__vwsn_ls_locale)))
		{
			throw ::vl::Exception(((::vl::WString::Unmanaged(L"Localized strings \"gaclib_controls::UnitTestSnapshotViewerStrings\" has already registered for locale \"") + ::vl::__vwsn::ToString(__vwsn_ls_locale)) + ::vl::WString::Unmanaged(L"\".")));
		}
		::vl::__vwsn::This(GLOBAL_NAME __vwsn_ls_UnitTestSnapshotViewerStrings.Obj())->Set(::vl::__vwsn::Box(__vwsn_ls_locale), ::vl::__vwsn::Box(__vwsn_ls_impl));
	}

	::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerStringsStrings> UnitTestSnapshotViewerStrings::Get(::vl::Locale __vwsn_ls_locale)
	{
		if (::vl::__vwsn::This(::vl::__vwsn::This(GLOBAL_NAME __vwsn_ls_UnitTestSnapshotViewerStrings.Obj())->GetKeys().Obj())->Contains(::vl::__vwsn::Box(__vwsn_ls_locale)))
		{
			return ::vl::__vwsn::Unbox<::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerStringsStrings>>(::vl::__vwsn::This(GLOBAL_NAME __vwsn_ls_UnitTestSnapshotViewerStrings.Obj())->Get(::vl::__vwsn::Box(__vwsn_ls_locale)));
		}
		return ::vl::__vwsn::Unbox<::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerStringsStrings>>(::vl::__vwsn::This(GLOBAL_NAME __vwsn_ls_UnitTestSnapshotViewerStrings.Obj())->Get(::vl::__vwsn::Box(::vl::__vwsn::Parse<::vl::Locale>(::vl::WString::Unmanaged(L"en-US")))));
	}

	UnitTestSnapshotViewerStrings::UnitTestSnapshotViewerStrings()
	{
	}

/***********************************************************************
Class (::gaclib_controls::UnitTestSnapshotViewerWindowConstructor)
***********************************************************************/

	void UnitTestSnapshotViewerWindowConstructor::__vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize(::gaclib_controls::UnitTestSnapshotViewerWindow* __vwsn_this_)
	{
		(this->self = __vwsn_this_);
		(this->ViewModel = ::vl::__vwsn::This(__vwsn_this_)->GetViewModel());
		{
			::vl::__vwsn::This(this->self)->SetClientSize([&](){ ::vl::presentation::Size __vwsn_temp__; __vwsn_temp__.x = static_cast<::vl::vint64_t>(1920L); __vwsn_temp__.y = static_cast<::vl::vint64_t>(1080L); return __vwsn_temp__; }());
		}
		{
			auto __vwsn_created_subscription_ = ::vl::Ptr<::vl::reflection::description::IValueSubscription>(new ::vl_workflow_global::__vwsnc1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription(__vwsn_this_, this));
			::vl::__vwsn::EventAttach(::vl::__vwsn::This(__vwsn_created_subscription_.Obj())->ValueChanged, vl::Func(::vl_workflow_global::__vwsnf1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize_(this)));
			::vl::__vwsn::This(__vwsn_this_)->AddSubscription(__vwsn_created_subscription_);
		}
		{
			auto __vwsn_created_subscription_ = ::vl::Ptr<::vl::reflection::description::IValueSubscription>(new ::vl_workflow_global::__vwsnc2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription(this));
			::vl::__vwsn::EventAttach(::vl::__vwsn::This(__vwsn_created_subscription_.Obj())->ValueChanged, vl::Func(::vl_workflow_global::__vwsnf2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize_(this)));
			::vl::__vwsn::This(__vwsn_this_)->AddSubscription(__vwsn_created_subscription_);
		}
	}

	UnitTestSnapshotViewerWindowConstructor::UnitTestSnapshotViewerWindowConstructor()
		: ViewModel(::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerViewModel>())
		, self(static_cast<::gaclib_controls::UnitTestSnapshotViewerWindow*>(nullptr))
	{
	}

/***********************************************************************
Class (::gaclib_controls::UnitTestSnapshotViewerWindow)
***********************************************************************/

	::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerStringsStrings> UnitTestSnapshotViewerWindow::GetStrings()
	{
		return this->__vwsn_prop_Strings;
	}
	void UnitTestSnapshotViewerWindow::SetStrings(::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerStringsStrings> __vwsn_value_)
	{
		if ((this->__vwsn_prop_Strings.Obj() != __vwsn_value_.Obj()))
		{
			(this->__vwsn_prop_Strings = __vwsn_value_);
			::vl::__vwsn::EventInvoke(this->StringsChanged)();
		}
	}

	::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerViewModel> UnitTestSnapshotViewerWindow::GetViewModel()
	{
		return this->__vwsn_parameter_ViewModel;
	}

	UnitTestSnapshotViewerWindow::UnitTestSnapshotViewerWindow(::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerViewModel> __vwsn_ctor_parameter_ViewModel)
		: ::vl::presentation::controls::GuiWindow(::vl::presentation::theme::ThemeName::Window)
		, __vwsn_prop_Strings(::gaclib_controls::UnitTestSnapshotViewerStrings::Get(::vl::__vwsn::Parse<::vl::Locale>(::vl::WString::Unmanaged(L"en-US"))))
		, __vwsn_parameter_ViewModel(::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerViewModel>())
	{
		(this->__vwsn_parameter_ViewModel = __vwsn_ctor_parameter_ViewModel);
		auto __vwsn_resource_ = ::vl::__vwsn::This(::vl::presentation::GetResourceManager())->GetResourceFromClassName(::vl::WString::Unmanaged(L"gaclib_controls::UnitTestSnapshotViewerWindow"));
		auto __vwsn_resolver_ = ::vl::Ptr<::vl::presentation::GuiResourcePathResolver>(new ::vl::presentation::GuiResourcePathResolver(__vwsn_resource_, ::vl::__vwsn::This(__vwsn_resource_.Obj())->GetWorkingDirectory()));
		::vl::__vwsn::This(this)->SetResourceResolver(__vwsn_resolver_);
		::vl::__vwsn::This(this)->__vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize(this);
	}

	UnitTestSnapshotViewerWindow::~UnitTestSnapshotViewerWindow()
	{
		this->FinalizeInstanceRecursively(static_cast<::vl::presentation::controls::GuiControlHost*>(this));
	}

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
