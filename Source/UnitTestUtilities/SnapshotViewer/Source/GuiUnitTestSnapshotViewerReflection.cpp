/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: GacUI UnitTestSnapshotViewer

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "GuiUnitTestSnapshotViewerReflection.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#endif

/***********************************************************************
Reflection
***********************************************************************/

namespace vl
{
	namespace reflection
	{
		namespace description
		{
#ifndef VCZH_DEBUG_NO_REFLECTION
			IMPL_CPP_TYPE_INFO(gaclib_controls::IUnitTestSnapshotFileNode)
			IMPL_CPP_TYPE_INFO(gaclib_controls::IUnitTestSnapshotFrame)
			IMPL_CPP_TYPE_INFO(gaclib_controls::IUnitTestSnapshotViewerStringsStrings)
			IMPL_CPP_TYPE_INFO(gaclib_controls::IUnitTestSnapshotViewerViewModel)
			IMPL_CPP_TYPE_INFO(gaclib_controls::UnitTestSnapshotFileNodeType)
			IMPL_CPP_TYPE_INFO(gaclib_controls::UnitTestSnapshotViewerStrings)
			IMPL_CPP_TYPE_INFO(gaclib_controls::UnitTestSnapshotViewerWindow)
			IMPL_CPP_TYPE_INFO(gaclib_controls::UnitTestSnapshotViewerWindowConstructor)

#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
#define _ ,
			BEGIN_INTERFACE_MEMBER(::gaclib_controls::IUnitTestSnapshotFileNode)
				CLASS_MEMBER_BASE(::vl::reflection::IDescriptable)
				CLASS_MEMBER_METHOD(GetChildren, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetFrames, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetName, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetNodeType, NO_PARAMETER)
				CLASS_MEMBER_METHOD(Refresh, NO_PARAMETER)
				CLASS_MEMBER_PROPERTY_READONLY(Children, GetChildren)
				CLASS_MEMBER_PROPERTY_READONLY(Frames, GetFrames)
				CLASS_MEMBER_PROPERTY_READONLY(Name, GetName)
				CLASS_MEMBER_PROPERTY_READONLY(NodeType, GetNodeType)
			END_INTERFACE_MEMBER(::gaclib_controls::IUnitTestSnapshotFileNode)

			BEGIN_INTERFACE_MEMBER(::gaclib_controls::IUnitTestSnapshotFrame)
				CLASS_MEMBER_BASE(::vl::reflection::IDescriptable)
				CLASS_MEMBER_METHOD(GetCommandsAsJsonText, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetDomAsJsonText, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetIndex, NO_PARAMETER)
				CLASS_MEMBER_PROPERTY_READONLY(CommandsAsJsonText, GetCommandsAsJsonText)
				CLASS_MEMBER_PROPERTY_READONLY(DomAsJsonText, GetDomAsJsonText)
				CLASS_MEMBER_PROPERTY_READONLY(Index, GetIndex)
			END_INTERFACE_MEMBER(::gaclib_controls::IUnitTestSnapshotFrame)

			BEGIN_INTERFACE_MEMBER(::gaclib_controls::IUnitTestSnapshotViewerStringsStrings)
				CLASS_MEMBER_BASE(::vl::reflection::IDescriptable)
				CLASS_MEMBER_METHOD(WindowTitle, NO_PARAMETER)
			END_INTERFACE_MEMBER(::gaclib_controls::IUnitTestSnapshotViewerStringsStrings)

			BEGIN_INTERFACE_MEMBER(::gaclib_controls::IUnitTestSnapshotViewerViewModel)
				CLASS_MEMBER_BASE(::vl::reflection::IDescriptable)
				CLASS_MEMBER_METHOD(GetRootNode, NO_PARAMETER)
				CLASS_MEMBER_PROPERTY_READONLY(RootNode, GetRootNode)
			END_INTERFACE_MEMBER(::gaclib_controls::IUnitTestSnapshotViewerViewModel)

			BEGIN_ENUM_ITEM(::gaclib_controls::UnitTestSnapshotFileNodeType)
				ENUM_CLASS_ITEM(File)
				ENUM_CLASS_ITEM(Folder)
			END_ENUM_ITEM(::gaclib_controls::UnitTestSnapshotFileNodeType)

			BEGIN_CLASS_MEMBER(::gaclib_controls::UnitTestSnapshotViewerStrings)
				CLASS_MEMBER_BASE(::vl::reflection::DescriptableObject)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::gaclib_controls::UnitTestSnapshotViewerStrings>(), NO_PARAMETER)
				CLASS_MEMBER_STATIC_METHOD(__vwsn_ls_en_US_BuildStrings, { L"__vwsn_ls_locale" })
				CLASS_MEMBER_STATIC_METHOD(Get, { L"__vwsn_ls_locale" })
				CLASS_MEMBER_STATIC_METHOD(Install, { L"__vwsn_ls_locale" _ L"__vwsn_ls_impl" })
			END_CLASS_MEMBER(::gaclib_controls::UnitTestSnapshotViewerStrings)

			BEGIN_CLASS_MEMBER(::gaclib_controls::UnitTestSnapshotViewerWindow)
				CLASS_MEMBER_BASE(::vl::presentation::controls::GuiWindow)
				CLASS_MEMBER_BASE(::gaclib_controls::UnitTestSnapshotViewerWindowConstructor)
				CLASS_MEMBER_CONSTRUCTOR(::gaclib_controls::UnitTestSnapshotViewerWindow*(::vl::Ptr<::gaclib_controls::IUnitTestSnapshotViewerViewModel>), { L"__vwsn_ctor_parameter_ViewModel" })
				CLASS_MEMBER_METHOD(GetImageFromType, { L"nodeType" })
				CLASS_MEMBER_METHOD(GetStrings, NO_PARAMETER)
				CLASS_MEMBER_METHOD(GetViewModel, NO_PARAMETER)
				CLASS_MEMBER_METHOD(SetStrings, { L"__vwsn_value_" })
				CLASS_MEMBER_EVENT(StringsChanged)
				CLASS_MEMBER_FIELD(__vwsn_parameter_ViewModel)
				CLASS_MEMBER_FIELD(__vwsn_prop_Strings)
				CLASS_MEMBER_PROPERTY_EVENT(Strings, GetStrings, SetStrings, StringsChanged)
				CLASS_MEMBER_PROPERTY_READONLY(ViewModel, GetViewModel)
				CLASS_MEMBER_FIELD(imageFile)
				CLASS_MEMBER_FIELD(imageFolder)
			END_CLASS_MEMBER(::gaclib_controls::UnitTestSnapshotViewerWindow)

			BEGIN_CLASS_MEMBER(::gaclib_controls::UnitTestSnapshotViewerWindowConstructor)
				CLASS_MEMBER_BASE(::vl::reflection::DescriptableObject)
				CLASS_MEMBER_CONSTRUCTOR(::vl::Ptr<::gaclib_controls::UnitTestSnapshotViewerWindowConstructor>(), NO_PARAMETER)
				CLASS_MEMBER_METHOD(__vwsn_gaclib_controls_UnitTestSnapshotViewerWindow_Initialize, { L"__vwsn_this_" })
				CLASS_MEMBER_FIELD(__vwsn_precompile_0)
				CLASS_MEMBER_FIELD(__vwsn_precompile_1)
				CLASS_MEMBER_FIELD(__vwsn_precompile_10)
				CLASS_MEMBER_FIELD(__vwsn_precompile_11)
				CLASS_MEMBER_FIELD(__vwsn_precompile_12)
				CLASS_MEMBER_FIELD(__vwsn_precompile_13)
				CLASS_MEMBER_FIELD(__vwsn_precompile_14)
				CLASS_MEMBER_FIELD(__vwsn_precompile_15)
				CLASS_MEMBER_FIELD(__vwsn_precompile_2)
				CLASS_MEMBER_FIELD(__vwsn_precompile_3)
				CLASS_MEMBER_FIELD(__vwsn_precompile_4)
				CLASS_MEMBER_FIELD(__vwsn_precompile_5)
				CLASS_MEMBER_FIELD(__vwsn_precompile_6)
				CLASS_MEMBER_FIELD(__vwsn_precompile_7)
				CLASS_MEMBER_FIELD(__vwsn_precompile_8)
				CLASS_MEMBER_FIELD(__vwsn_precompile_9)
				CLASS_MEMBER_FIELD(ViewModel)
				CLASS_MEMBER_FIELD(self)
				CLASS_MEMBER_FIELD(textListFrames)
				CLASS_MEMBER_FIELD(treeViewFileNodes)
			END_CLASS_MEMBER(::gaclib_controls::UnitTestSnapshotViewerWindowConstructor)

#undef _
			class GuiUnitTestSnapshotViewerTypeLoader : public Object, public ITypeLoader
			{
			public:
				void Load(ITypeManager* manager)
				{
					ADD_TYPE_INFO(::gaclib_controls::IUnitTestSnapshotFileNode)
					ADD_TYPE_INFO(::gaclib_controls::IUnitTestSnapshotFrame)
					ADD_TYPE_INFO(::gaclib_controls::IUnitTestSnapshotViewerStringsStrings)
					ADD_TYPE_INFO(::gaclib_controls::IUnitTestSnapshotViewerViewModel)
					ADD_TYPE_INFO(::gaclib_controls::UnitTestSnapshotFileNodeType)
					ADD_TYPE_INFO(::gaclib_controls::UnitTestSnapshotViewerStrings)
					ADD_TYPE_INFO(::gaclib_controls::UnitTestSnapshotViewerWindow)
					ADD_TYPE_INFO(::gaclib_controls::UnitTestSnapshotViewerWindowConstructor)
				}

				void Unload(ITypeManager* manager)
				{
				}
			};
#endif
#endif

			bool LoadGuiUnitTestSnapshotViewerTypes()
			{
#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
				if (auto manager = GetGlobalTypeManager())
				{
					return manager->AddTypeLoader(Ptr(new GuiUnitTestSnapshotViewerTypeLoader));
				}
#endif
				return false;
			}
		}
	}
}

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__clang__)
#pragma clang diagnostic pop
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
