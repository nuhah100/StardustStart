#pragma once
#pragma region xamlOM_h

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include <rpc.h>
#include <rpcndr.h>

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif /*COM_NO_WINDOWS_H*/

#ifndef __xamlom_h__
#define __xamlom_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
// #pragma once
#endif

/* Forward Declarations */

#ifndef __IVisualTreeServiceCallback_FWD_DEFINED__
#define __IVisualTreeServiceCallback_FWD_DEFINED__
typedef interface IVisualTreeServiceCallback IVisualTreeServiceCallback;

#endif 	/* __IVisualTreeServiceCallback_FWD_DEFINED__ */


#ifndef __IVisualTreeServiceCallback2_FWD_DEFINED__
#define __IVisualTreeServiceCallback2_FWD_DEFINED__
typedef interface IVisualTreeServiceCallback2 IVisualTreeServiceCallback2;

#endif 	/* __IVisualTreeServiceCallback2_FWD_DEFINED__ */


#ifndef __IVisualTreeService_FWD_DEFINED__
#define __IVisualTreeService_FWD_DEFINED__
typedef interface IVisualTreeService IVisualTreeService;

#endif 	/* __IVisualTreeService_FWD_DEFINED__ */


#ifndef __IXamlDiagnostics_FWD_DEFINED__
#define __IXamlDiagnostics_FWD_DEFINED__
typedef interface IXamlDiagnostics IXamlDiagnostics;

#endif 	/* __IXamlDiagnostics_FWD_DEFINED__ */


#ifndef __IBitmapData_FWD_DEFINED__
#define __IBitmapData_FWD_DEFINED__
typedef interface IBitmapData IBitmapData;

#endif 	/* __IBitmapData_FWD_DEFINED__ */


#ifndef __IVisualTreeService2_FWD_DEFINED__
#define __IVisualTreeService2_FWD_DEFINED__
typedef interface IVisualTreeService2 IVisualTreeService2;

#endif 	/* __IVisualTreeService2_FWD_DEFINED__ */


#ifndef __IVisualTreeService3_FWD_DEFINED__
#define __IVisualTreeService3_FWD_DEFINED__
typedef interface IVisualTreeService3 IVisualTreeService3;

#endif 	/* __IVisualTreeService3_FWD_DEFINED__ */

/* header files for imported files */
#include <oaidl.h>
#include <ocidl.h>
#include <inspectable.h>
#include <dxgi1_2.h>

#ifdef __cplusplus
extern "C" {
#endif 


    /* interface __MIDL_itf_xamlom_0000_0000 */
    /* [local] */

#pragma region Application Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#pragma warning(push)
#pragma warning(disable:4668) 
#pragma warning(disable:4001) 
// #pragma once
#pragma warning(pop)
// Win32 API definitions
#define E_NOTFOUND HRESULT_FROM_WIN32(ERROR_NOT_FOUND)
#define E_UNKNOWNTYPE MAKE_HRESULT(SEVERITY_ERROR, FACILITY_XAML, 40L)
    _Check_return_ HRESULT InitializeXamlDiagnostic(_In_ LPCWSTR endPointName, _In_ DWORD pid, _In_ LPCWSTR wszDllXamlDiagnostics, _In_ LPCWSTR wszTAPDllName, _In_ CLSID tapClsid);
    _Check_return_ HRESULT InitializeXamlDiagnosticsEx(_In_ LPCWSTR endPointName, _In_ DWORD pid, _In_ LPCWSTR wszDllXamlDiagnostics, _In_ LPCWSTR wszTAPDllName, _In_ CLSID tapClsid, _In_ LPCWSTR wszInitializationData);
    typedef MIDL_uhyper InstanceHandle;

    typedef
        enum VisualMutationType
    {
        Add = 0,
        Remove = (Add + 1)
    } 	VisualMutationType;

    typedef
        enum BaseValueSource
    {
        BaseValueSourceUnknown = 0,
        BaseValueSourceDefault = (BaseValueSourceUnknown + 1),
        BaseValueSourceBuiltInStyle = (BaseValueSourceDefault + 1),
        BaseValueSourceStyle = (BaseValueSourceBuiltInStyle + 1),
        BaseValueSourceLocal = (BaseValueSourceStyle + 1),
        Inherited = (BaseValueSourceLocal + 1),
        DefaultStyleTrigger = (Inherited + 1),
        TemplateTrigger = (DefaultStyleTrigger + 1),
        StyleTrigger = (TemplateTrigger + 1),
        ImplicitStyleReference = (StyleTrigger + 1),
        ParentTemplate = (ImplicitStyleReference + 1),
        ParentTemplateTrigger = (ParentTemplate + 1),
        Animation = (ParentTemplateTrigger + 1),
        Coercion = (Animation + 1),
        BaseValueSourceVisualState = (Coercion + 1)
    } 	BaseValueSource;

    typedef struct SourceInfo
    {
        BSTR FileName;
        unsigned int LineNumber;
        unsigned int ColumnNumber;
        unsigned int CharPosition;
        BSTR Hash;
    } 	SourceInfo;

    typedef struct ParentChildRelation
    {
        InstanceHandle Parent;
        InstanceHandle Child;
        unsigned int ChildIndex;
    } 	ParentChildRelation;

    typedef struct VisualElement
    {
        InstanceHandle Handle;
        SourceInfo SrcInfo;
        BSTR Type;
        BSTR Name;
        unsigned int NumChildren;
    } 	VisualElement;

    typedef struct PropertyChainSource
    {
        InstanceHandle Handle;
        BSTR TargetType;
        BSTR Name;
        BaseValueSource Source;
        SourceInfo SrcInfo;
    } 	PropertyChainSource;

    typedef
        enum MetadataBit
    {
        None = 0,
        IsValueHandle = 0x1,
        IsPropertyReadOnly = 0x2,
        IsValueCollection = 0x4,
        IsValueCollectionReadOnly = 0x8,
        IsValueBindingExpression = 0x10,
        IsValueNull = 0x20,
        IsValueHandleAndEvaluatedValue = 0x40
    } 	MetadataBit;

    typedef struct PropertyChainValue
    {
        unsigned int Index;
        BSTR Type;
        BSTR DeclaringType;
        BSTR ValueType;
        BSTR ItemType;
        BSTR Value;
        BOOL Overridden;
        hyper MetadataBits;
        BSTR PropertyName;
        unsigned int PropertyChainIndex;
    } 	PropertyChainValue;

    typedef struct EnumType
    {
        BSTR Name;
        SAFEARRAY* ValueInts;
        SAFEARRAY* ValueStrings;
    } 	EnumType;

    typedef struct CollectionElementValue
    {
        unsigned int Index;
        BSTR ValueType;
        BSTR Value;
        hyper MetadataBits;
    } 	CollectionElementValue;

    typedef
        enum RenderTargetBitmapOptions
    {
        RenderTarget = 0,
        RenderTargetAndChildren = (RenderTarget + 1)
    } 	RenderTargetBitmapOptions;

    typedef struct BitmapDescription
    {
        unsigned int Width;
        unsigned int Height;
        DXGI_FORMAT Format;
        DXGI_ALPHA_MODE AlphaMode;
    } 	BitmapDescription;

    typedef
        enum ResourceType
    {
        ResourceTypeStatic = 0,
        ResourceTypeTheme = (ResourceTypeStatic + 1)
    } 	ResourceType;

    typedef
        enum VisualElementState
    {
        ErrorResolved = 0,
        ErrorResourceNotFound = (ErrorResolved + 1),
        ErrorInvalidResource = (ErrorResourceNotFound + 1)
    } 	VisualElementState;



    extern RPC_IF_HANDLE __MIDL_itf_xamlom_0000_0000_v0_0_c_ifspec;
    extern RPC_IF_HANDLE __MIDL_itf_xamlom_0000_0000_v0_0_s_ifspec;

#ifndef __IVisualTreeServiceCallback_INTERFACE_DEFINED__
#define __IVisualTreeServiceCallback_INTERFACE_DEFINED__

    /* interface IVisualTreeServiceCallback */
    /* [unique][uuid][object] */


    EXTERN_C const IID IID_IVisualTreeServiceCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)

#ifdef __CRT_UUID_DECL
    __CRT_UUID_DECL(IVisualTreeServiceCallback, 0xAA7A8931, 0x80E4, 0x4FEC, 0x8F, 0x3B, 0x55, 0x3F, 0x87, 0xB4, 0x96, 0x6E);
#endif

    MIDL_INTERFACE("AA7A8931-80E4-4FEC-8F3B-553F87B4966E")
        IVisualTreeServiceCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnVisualTreeChange(
            /* [in] */ ParentChildRelation relation,
            /* [in] */ VisualElement element,
            /* [in] */ VisualMutationType mutationType) = 0;

    };


#else 	/* C style interface */
#error Only C++ style interface is supported
#endif 	/* C style interface */




#endif 	/* __IVisualTreeServiceCallback_INTERFACE_DEFINED__ */


#ifndef __IVisualTreeServiceCallback2_INTERFACE_DEFINED__
#define __IVisualTreeServiceCallback2_INTERFACE_DEFINED__

    /* interface IVisualTreeServiceCallback2 */
    /* [unique][uuid][object] */


    EXTERN_C const IID IID_IVisualTreeServiceCallback2;

#if defined(__cplusplus) && !defined(CINTERFACE)

#ifdef __CRT_UUID_DECL
    __CRT_UUID_DECL(IVisualTreeServiceCallback2, 0xBAD9EB88, 0xAE77, 0x4397, 0xB9, 0x48, 0x5F, 0xA2, 0xDB, 0x0A, 0x19, 0xEA);
#endif

    MIDL_INTERFACE("BAD9EB88-AE77-4397-B948-5FA2DB0A19EA")
        IVisualTreeServiceCallback2 : public IVisualTreeServiceCallback
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnElementStateChanged(
            /* [in] */ InstanceHandle element,
            /* [in] */ VisualElementState elementState,
            /* [in] */ __RPC__in LPCWSTR context) = 0;

    };


#else 	/* C style interface */
#error Only C++ style interface is supported
#endif 	/* C style interface */




#endif 	/* __IVisualTreeServiceCallback2_INTERFACE_DEFINED__ */


#ifndef __IVisualTreeService_INTERFACE_DEFINED__
#define __IVisualTreeService_INTERFACE_DEFINED__

    /* interface IVisualTreeService */
    /* [unique][uuid][object] */


    EXTERN_C const IID IID_IVisualTreeService;

#if defined(__cplusplus) && !defined(CINTERFACE)

#ifdef __CRT_UUID_DECL
    __CRT_UUID_DECL(IVisualTreeService, 0xA593B11A, 0xD17F, 0x48BB, 0x8F, 0x66, 0x83, 0x91, 0x07, 0x31, 0xC8, 0xA5);
#endif

    MIDL_INTERFACE("A593B11A-D17F-48BB-8F66-83910731C8A5")
        IVisualTreeService : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AdviseVisualTreeChange(
            /* [in] */ __RPC__in_opt IVisualTreeServiceCallback * pCallback) = 0;

        virtual HRESULT STDMETHODCALLTYPE UnadviseVisualTreeChange(
            /* [in] */ __RPC__in_opt IVisualTreeServiceCallback* pCallback) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetEnums(
            /* [out] */ __RPC__out unsigned int* pCount,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pCount) EnumType** ppEnums) = 0;

        virtual HRESULT STDMETHODCALLTYPE CreateInstance(
            /* [in] */ __RPC__in BSTR typeName,
            /* [in] */ __RPC__in BSTR value,
            /* [retval][out] */ __RPC__out InstanceHandle* pInstanceHandle) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetPropertyValuesChain(
            /* [in] */ InstanceHandle instanceHandle,
            /* [out] */ __RPC__out unsigned int* pSourceCount,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pSourceCount) PropertyChainSource** ppPropertySources,
            /* [out] */ __RPC__out unsigned int* pPropertyCount,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pPropertyCount) PropertyChainValue** ppPropertyValues) = 0;

        virtual HRESULT STDMETHODCALLTYPE SetProperty(
            /* [in] */ InstanceHandle instanceHandle,
            /* [in] */ InstanceHandle value,
            /* [in] */ unsigned int propertyIndex) = 0;

        virtual HRESULT STDMETHODCALLTYPE ClearProperty(
            /* [in] */ InstanceHandle instanceHandle,
            /* [in] */ unsigned int propertyIndex) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetCollectionCount(
            /* [in] */ InstanceHandle instanceHandle,
            /* [out] */ __RPC__out unsigned int* pCollectionSize) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetCollectionElements(
            /* [in] */ InstanceHandle instanceHandle,
            /* [in] */ unsigned int startIndex,
            /* [out][in] */ __RPC__inout unsigned int* pElementCount,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pElementCount) CollectionElementValue** ppElementValues) = 0;

        virtual HRESULT STDMETHODCALLTYPE AddChild(
            /* [in] */ InstanceHandle parent,
            /* [in] */ InstanceHandle child,
            /* [in] */ unsigned int index) = 0;

        virtual HRESULT STDMETHODCALLTYPE RemoveChild(
            /* [in] */ InstanceHandle parent,
            /* [in] */ unsigned int index) = 0;

        virtual HRESULT STDMETHODCALLTYPE ClearChildren(
            /* [in] */ InstanceHandle parent) = 0;

    };


#else 	/* C style interface */
#error Only C++ style interface is supported
#endif 	/* C style interface */




#endif 	/* __IVisualTreeService_INTERFACE_DEFINED__ */


#ifndef __IXamlDiagnostics_INTERFACE_DEFINED__
#define __IXamlDiagnostics_INTERFACE_DEFINED__

    /* interface IXamlDiagnostics */
    /* [unique][uuid][object] */


    EXTERN_C const IID IID_IXamlDiagnostics;

#if defined(__cplusplus) && !defined(CINTERFACE)

#ifdef __CRT_UUID_DECL
    __CRT_UUID_DECL(IXamlDiagnostics, 0x18C9E2B6, 0x3F43, 0x4116, 0x9F, 0x2B, 0xFF, 0x93, 0x5D, 0x77, 0x70, 0xD2);
#endif

    MIDL_INTERFACE("18C9E2B6-3F43-4116-9F2B-FF935D7770D2")
        IXamlDiagnostics : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDispatcher(
            /* [retval][out] */ __RPC__deref_out_opt IInspectable * *ppDispatcher) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetUiLayer(
            /* [retval][out] */ __RPC__deref_out_opt IInspectable** ppLayer) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetApplication(
            /* [retval][out] */ __RPC__deref_out_opt IInspectable** ppApplication) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetIInspectableFromHandle(
            /* [in] */ InstanceHandle instanceHandle,
            /* [retval][out] */ __RPC__deref_out_opt IInspectable** ppInstance) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetHandleFromIInspectable(
            /* [in] */ __RPC__in_opt IInspectable* pInstance,
            /* [retval][out] */ __RPC__out InstanceHandle* pHandle) = 0;

        virtual HRESULT STDMETHODCALLTYPE HitTest(
            /* [in] */ RECT rect,
            /* [out] */ __RPC__out unsigned int* pCount,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pCount) InstanceHandle** ppInstanceHandles) = 0;

        virtual HRESULT STDMETHODCALLTYPE RegisterInstance(
            /* [in] */ __RPC__in_opt IInspectable* pInstance,
            /* [retval][out] */ __RPC__out InstanceHandle* pInstanceHandle) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetInitializationData(
            /* [retval][out] */ __RPC__deref_out_opt BSTR* pInitializationData) = 0;

    };


#else 	/* C style interface */
#error Only C++ style interface is supported
#endif 	/* C style interface */




#endif 	/* __IXamlDiagnostics_INTERFACE_DEFINED__ */


#ifndef __IBitmapData_INTERFACE_DEFINED__
#define __IBitmapData_INTERFACE_DEFINED__

    /* interface IBitmapData */
    /* [unique][uuid][object] */


    EXTERN_C const IID IID_IBitmapData;

#if defined(__cplusplus) && !defined(CINTERFACE)

#ifdef __CRT_UUID_DECL
    __CRT_UUID_DECL(IBitmapData, 0xd1a34ef2, 0xcad8, 0x4635, 0xa3, 0xd2, 0xfc, 0xda, 0x8d, 0x3f, 0x3c, 0xaf);
#endif

    MIDL_INTERFACE("d1a34ef2-cad8-4635-a3d2-fcda8d3f3caf")
        IBitmapData : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CopyBytesTo(
            /* [in] */ unsigned int sourceOffsetInBytes,
            /* [in] */ unsigned int maxBytesToCopy,
            /* [size_is][out] */ __RPC__out_ecount_full(maxBytesToCopy) byte * pvBytes,
            /* [out] */ __RPC__out unsigned int* numberOfBytesCopied) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetStride(
            /* [out] */ __RPC__out unsigned int* pStride) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetBitmapDescription(
            /* [out] */ __RPC__out BitmapDescription* pBitmapDescription) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetSourceBitmapDescription(
            /* [out] */ __RPC__out BitmapDescription* pBitmapDescription) = 0;

    };


#else 	/* C style interface */
#error Only C++ style interface is supported
#endif 	/* C style interface */




#endif 	/* __IBitmapData_INTERFACE_DEFINED__ */


#ifndef __IVisualTreeService2_INTERFACE_DEFINED__
#define __IVisualTreeService2_INTERFACE_DEFINED__

    /* interface IVisualTreeService2 */
    /* [unique][uuid][object] */


    EXTERN_C const IID IID_IVisualTreeService2;

#if defined(__cplusplus) && !defined(CINTERFACE)

#ifdef __CRT_UUID_DECL
    __CRT_UUID_DECL(IVisualTreeService2, 0x130F5136, 0xEC43, 0x4F61, 0x89, 0xC7, 0x98, 0x01, 0xA3, 0x6D, 0x2E, 0x95);
#endif

    MIDL_INTERFACE("130F5136-EC43-4F61-89C7-9801A36D2E95")
        IVisualTreeService2 : public IVisualTreeService
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPropertyIndex(
            /* [in] */ InstanceHandle object,
            /* [in] */ __RPC__in LPCWSTR propertyName,
            /* [out] */ __RPC__out unsigned int* pPropertyIndex) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetProperty(
            /* [in] */ InstanceHandle object,
            /* [in] */ unsigned int propertyIndex,
            /* [out] */ __RPC__out InstanceHandle* pValue) = 0;

        virtual HRESULT STDMETHODCALLTYPE ReplaceResource(
            /* [in] */ InstanceHandle resourceDictionary,
            /* [in] */ InstanceHandle key,
            /* [in] */ InstanceHandle newValue) = 0;

        virtual HRESULT STDMETHODCALLTYPE RenderTargetBitmap(
            /* [in] */ InstanceHandle handle,
            /* [in] */ RenderTargetBitmapOptions options,
            /* [in] */ unsigned int maxPixelWidth,
            /* [in] */ unsigned int maxPixelHeight,
            /* [out] */ __RPC__deref_out_opt IBitmapData** ppBitmapData) = 0;

    };


#else 	/* C style interface */
#error Only C++ style interface is supported
#endif 	/* C style interface */




#endif 	/* __IVisualTreeService2_INTERFACE_DEFINED__ */


#ifndef __IVisualTreeService3_INTERFACE_DEFINED__
#define __IVisualTreeService3_INTERFACE_DEFINED__

    /* interface IVisualTreeService3 */
    /* [unique][uuid][object] */


    EXTERN_C const IID IID_IVisualTreeService3;

#if defined(__cplusplus) && !defined(CINTERFACE)

#ifdef __CRT_UUID_DECL
    __CRT_UUID_DECL(IVisualTreeService3, 0x0E79C6E0, 0x85A0, 0x4BE8, 0xB4, 0x1A, 0x65, 0x5C, 0xF1, 0xFD, 0x19, 0xBD);
#endif

    MIDL_INTERFACE("0E79C6E0-85A0-4BE8-B41A-655CF1FD19BD")
        IVisualTreeService3 : public IVisualTreeService2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ResolveResource(
            /* [in] */ InstanceHandle resourceContext,
            /* [in] */ __RPC__in LPCWSTR resourceName,
            /* [in] */ ResourceType resourceType,
            /* [in] */ unsigned int propertyIndex) = 0;

        virtual HRESULT STDMETHODCALLTYPE GetDictionaryItem(
            /* [in] */ InstanceHandle dictionaryHandle,
            /* [in] */ __RPC__in LPCWSTR resourceName,
            /* [in] */ BOOL resourceIsImplicitStyle,
            /* [out] */ __RPC__out InstanceHandle* resourceHandle) = 0;

        virtual HRESULT STDMETHODCALLTYPE AddDictionaryItem(
            /* [in] */ InstanceHandle dictionaryHandle,
            /* [in] */ InstanceHandle resourceKey,
            /* [in] */ InstanceHandle resourceHandle) = 0;

        virtual HRESULT STDMETHODCALLTYPE RemoveDictionaryItem(
            /* [in] */ InstanceHandle dictionaryHandle,
            /* [in] */ InstanceHandle resourceKey) = 0;

    };


#else 	/* C style interface */
#error Only C++ style interface is supported
#endif 	/* C style interface */




#endif 	/* __IVisualTreeService3_INTERFACE_DEFINED__ */


    /* interface __MIDL_itf_xamlom_0000_0007 */
    /* [local] */

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */ 
#pragma endregion


    extern RPC_IF_HANDLE __MIDL_itf_xamlom_0000_0007_v0_0_c_ifspec;
    extern RPC_IF_HANDLE __MIDL_itf_xamlom_0000_0007_v0_0_s_ifspec;

    /* Additional Prototypes for ALL interfaces */

    unsigned long             __RPC_USER  BSTR_UserSize(__RPC__in unsigned long*, unsigned long, __RPC__in BSTR*);
    unsigned char* __RPC_USER  BSTR_UserMarshal(__RPC__in unsigned long*, __RPC__inout_xcount(0) unsigned char*, __RPC__in BSTR*);
    unsigned char* __RPC_USER  BSTR_UserUnmarshal(__RPC__in unsigned long*, __RPC__in_xcount(0) unsigned char*, __RPC__out BSTR*);
    void                      __RPC_USER  BSTR_UserFree(__RPC__in unsigned long*, __RPC__in BSTR*);

    unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(__RPC__in unsigned long*, unsigned long, __RPC__in LPSAFEARRAY*);
    unsigned char* __RPC_USER  LPSAFEARRAY_UserMarshal(__RPC__in unsigned long*, __RPC__inout_xcount(0) unsigned char*, __RPC__in LPSAFEARRAY*);
    unsigned char* __RPC_USER  LPSAFEARRAY_UserUnmarshal(__RPC__in unsigned long*, __RPC__in_xcount(0) unsigned char*, __RPC__out LPSAFEARRAY*);
    void                      __RPC_USER  LPSAFEARRAY_UserFree(__RPC__in unsigned long*, __RPC__in LPSAFEARRAY*);

    unsigned long             __RPC_USER  BSTR_UserSize64(__RPC__in unsigned long*, unsigned long, __RPC__in BSTR*);
    unsigned char* __RPC_USER  BSTR_UserMarshal64(__RPC__in unsigned long*, __RPC__inout_xcount(0) unsigned char*, __RPC__in BSTR*);
    unsigned char* __RPC_USER  BSTR_UserUnmarshal64(__RPC__in unsigned long*, __RPC__in_xcount(0) unsigned char*, __RPC__out BSTR*);
    void                      __RPC_USER  BSTR_UserFree64(__RPC__in unsigned long*, __RPC__in BSTR*);

    unsigned long             __RPC_USER  LPSAFEARRAY_UserSize64(__RPC__in unsigned long*, unsigned long, __RPC__in LPSAFEARRAY*);
    unsigned char* __RPC_USER  LPSAFEARRAY_UserMarshal64(__RPC__in unsigned long*, __RPC__inout_xcount(0) unsigned char*, __RPC__in LPSAFEARRAY*);
    unsigned char* __RPC_USER  LPSAFEARRAY_UserUnmarshal64(__RPC__in unsigned long*, __RPC__in_xcount(0) unsigned char*, __RPC__out LPSAFEARRAY*);
    void                      __RPC_USER  LPSAFEARRAY_UserFree64(__RPC__in unsigned long*, __RPC__in LPSAFEARRAY*);

    /* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif

#pragma endregion  // xamlOM_h