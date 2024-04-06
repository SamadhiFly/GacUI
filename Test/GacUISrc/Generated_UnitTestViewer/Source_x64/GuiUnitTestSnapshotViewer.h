﻿/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: GacUI UnitTestSnapshotViewer

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#ifndef VCZH_WORKFLOW_COMPILER_GENERATED_GUIUNITTESTSNAPSHOTVIEWER
#define VCZH_WORKFLOW_COMPILER_GENERATED_GUIUNITTESTSNAPSHOTVIEWER

#include "../../../GacUI.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#endif

namespace vl_workflow_global
{
	struct __vwsnf1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize_;
	struct __vwsnf2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize_;
	class __vwsnc1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription;
	class __vwsnc2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription;
	class __vwsnc3_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerStrings___vwsn_ls_en_US_BuildStrings__gaclib_controls_IUnitTestSnapshotViewerStringsStrings;
}

namespace gaclib_controls
{
	class IUnitTestSnapshotViewerStringsStrings;
	class IUnitTestSnapshotViewerViewModel;
	class UnitTestSnapshotViewerStrings;
	class UnitTestSnapshotViewerWindowConstructor;
	class UnitTestSnapshotViewerWindow;

	class IUnitTestSnapshotViewerStringsStrings : public virtual ::vl::reflection::IDescriptable, public ::vl::reflection::Description<IUnitTestSnapshotViewerStringsStrings>
	{
#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
		friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<IUnitTestSnapshotViewerStringsStrings>;
#endif
	public:
		virtual ::vl::WString WindowTitle() = 0;
	};

	class IUnitTestSnapshotViewerViewModel : public virtual ::vl::reflection::IDescriptable, public ::vl::reflection::Description<IUnitTestSnapshotViewerViewModel>
	{
#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
		friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<IUnitTestSnapshotViewerViewModel>;
#endif
	};

	class UnitTestSnapshotViewerStrings : public ::vl::Object, public ::vl::reflection::Description<UnitTestSnapshotViewerStrings>
	{
		friend class ::vl_workflow_global::__vwsnc3_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerStrings___vwsn_ls_en_US_BuildStrings__gaclib_controls_IUnitTestSnapshotViewerStringsStrings;
#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
		friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<UnitTestSnapshotViewerStrings>;
#endif
	public:
		static ::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerStringsStrings> __vwsn_ls_en_US_BuildStrings(::vl::Locale __vwsn_ls_locale);
		static void Install(::vl::Locale __vwsn_ls_locale, ::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerStringsStrings> __vwsn_ls_impl);
		static ::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerStringsStrings> Get(::vl::Locale __vwsn_ls_locale);
		UnitTestSnapshotViewerStrings();
	};

	class UnitTestSnapshotViewerWindowConstructor : public ::vl::Object, public ::vl::reflection::Description<UnitTestSnapshotViewerWindowConstructor>
	{
		friend class ::vl_workflow_global::__vwsnc1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription;
		friend struct ::vl_workflow_global::__vwsnf1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize_;
#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
		friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<UnitTestSnapshotViewerWindowConstructor>;
#endif
	protected:
		::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerViewModel> ViewModel;
		::gaclib_controls::UnitTestSnapshotViewerWindow* self;
		void __vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize(::gaclib_controls::UnitTestSnapshotViewerWindow* __vwsn_this_);
	public:
		UnitTestSnapshotViewerWindowConstructor();
	};

	class UnitTestSnapshotViewerWindow : public ::vl::presentation::controls::GuiWindow, public ::gaclib_controls::UnitTestSnapshotViewerWindowConstructor, public ::vl::reflection::Description<UnitTestSnapshotViewerWindow>
	{
		friend class ::gaclib_controls::UnitTestSnapshotViewerWindowConstructor;
		friend class ::vl_workflow_global::__vwsnc1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription;
		friend class ::vl_workflow_global::__vwsnc2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription;
		friend struct ::vl_workflow_global::__vwsnf1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize_;
#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
		friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<UnitTestSnapshotViewerWindow>;
#endif
	public:
		::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerStringsStrings> __vwsn_prop_Strings;
		::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerStringsStrings> GetStrings();
		void SetStrings(::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerStringsStrings> __vwsn_value_);
		::vl::Event<void()> StringsChanged;
		::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerViewModel> __vwsn_parameter_ViewModel;
		::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerViewModel> GetViewModel();
		UnitTestSnapshotViewerWindow(::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerViewModel> __vwsn_ctor_parameter_ViewModel);
		~UnitTestSnapshotViewerWindow();
	};

}
/***********************************************************************
Global Variables and Functions
***********************************************************************/

namespace vl_workflow_global
{
	class GuiUnitTestSnapshotViewer
	{
	public:

		::vl::Ptr<::vl::reflection::description::IValueDictionary> __vwsn_ls_UnitTestSnapshotViewerStrings;

		static GuiUnitTestSnapshotViewer& Instance();
	};

/***********************************************************************
Closures
***********************************************************************/

	struct __vwsnf1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize_
	{
		::gaclib_controls::UnitTestSnapshotViewerWindowConstructor* __vwsnthis_0;

		__vwsnf1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize_(::gaclib_controls::UnitTestSnapshotViewerWindowConstructor* __vwsnctorthis_0);

		void operator()(const ::vl::reflection::description::Value& __vwsn_value_) const;
	};

	struct __vwsnf2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize_
	{
		::gaclib_controls::UnitTestSnapshotViewerWindowConstructor* __vwsnthis_0;

		__vwsnf2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize_(::gaclib_controls::UnitTestSnapshotViewerWindowConstructor* __vwsnctorthis_0);

		void operator()(const ::vl::reflection::description::Value& __vwsn_value_) const;
	};

	class __vwsnc1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription : public ::vl::Object, public virtual ::vl::reflection::description::IValueSubscription
	{
	public:
		::gaclib_controls::UnitTestSnapshotViewerWindow* __vwsn_this_;
		::gaclib_controls::UnitTestSnapshotViewerWindowConstructor* __vwsnthis_0;

		__vwsnc1_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription(::gaclib_controls::UnitTestSnapshotViewerWindow* __vwsnctor___vwsn_this_, ::gaclib_controls::UnitTestSnapshotViewerWindowConstructor* __vwsnctorthis_0);

		::gaclib_controls::UnitTestSnapshotViewerWindow* __vwsn_bind_cache_0 = nullptr;
		::vl::Ptr<::vl::reflection::description::IEventHandler> __vwsn_bind_handler_0_0;
		bool __vwsn_bind_opened_ = false;
		bool __vwsn_bind_closed_ = false;
		void __vwsn_bind_activator_();
		void __vwsn_bind_callback_0_0();
		bool Open() override;
		bool Update() override;
		bool Close() override;
	};

	class __vwsnc2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription : public ::vl::Object, public virtual ::vl::reflection::description::IValueSubscription
	{
	public:
		::gaclib_controls::UnitTestSnapshotViewerWindowConstructor* __vwsnthis_0;

		__vwsnc2_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerWindowConstructor___vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize__vl_reflection_description_IValueSubscription(::gaclib_controls::UnitTestSnapshotViewerWindowConstructor* __vwsnctorthis_0);

		::vl::presentation::controls::GuiApplication* __vwsn_bind_cache_0 = nullptr;
		::vl::Ptr<::vl::reflection::description::IEventHandler> __vwsn_bind_handler_0_0;
		bool __vwsn_bind_opened_ = false;
		bool __vwsn_bind_closed_ = false;
		void __vwsn_bind_activator_();
		void __vwsn_bind_callback_0_0();
		bool Open() override;
		bool Update() override;
		bool Close() override;
	};

	class __vwsnc3_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerStrings___vwsn_ls_en_US_BuildStrings__gaclib_controls_IUnitTestSnapshotViewerStringsStrings : public ::vl::Object, public virtual ::gaclib_controls::IUnitTestSnapshotViewerStringsStrings
	{
	public:
		__vwsnc3_GuiUnitTestSnapshotViewer_gaclib_controls_UnitTestSnapshotViewerStrings___vwsn_ls_en_US_BuildStrings__gaclib_controls_IUnitTestSnapshotViewerStringsStrings();

		::vl::WString WindowTitle() override;
	};
}

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__clang__)
#pragma clang diagnostic pop
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

#endif
