#pragma once
#pragma region windows_ui_xaml_hosting_desktopwindowxamlsource_h

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

#ifndef __windows2Eui2Examl2Ehosting2Edesktopwindowxamlsource_h__
#define __windows2Eui2Examl2Ehosting2Edesktopwindowxamlsource_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
// #pragma once
#endif

/* Forward Declarations */

#ifndef __IDesktopWindowXamlSourceNative_FWD_DEFINED__
#define __IDesktopWindowXamlSourceNative_FWD_DEFINED__
typedef interface IDesktopWindowXamlSourceNative IDesktopWindowXamlSourceNative;

#endif 	/* __IDesktopWindowXamlSourceNative_FWD_DEFINED__ */


#ifndef __IDesktopWindowXamlSourceNative2_FWD_DEFINED__
#define __IDesktopWindowXamlSourceNative2_FWD_DEFINED__
typedef interface IDesktopWindowXamlSourceNative2 IDesktopWindowXamlSourceNative2;

#endif 	/* __IDesktopWindowXamlSourceNative2_FWD_DEFINED__ */


/* header files for imported files */
#include <oaidl.h>

#ifdef __cplusplus
extern "C" {
#endif 


	/* interface __MIDL_itf_windows2Eui2Examl2Ehosting2Edesktopwindowxamlsource_0000_0000 */
	/* [local] */

#if (NTDDI_VERSION >= NTDDI_WIN10_RS5)


	extern RPC_IF_HANDLE __MIDL_itf_windows2Eui2Examl2Ehosting2Edesktopwindowxamlsource_0000_0000_v0_0_c_ifspec;
	extern RPC_IF_HANDLE __MIDL_itf_windows2Eui2Examl2Ehosting2Edesktopwindowxamlsource_0000_0000_v0_0_s_ifspec;

#ifndef __IDesktopWindowXamlSourceNative_INTERFACE_DEFINED__
#define __IDesktopWindowXamlSourceNative_INTERFACE_DEFINED__

	/* interface IDesktopWindowXamlSourceNative */
	/* [unique][local][uuid][object] */


	EXTERN_C const IID IID_IDesktopWindowXamlSourceNative;

#if defined(__cplusplus) && !defined(CINTERFACE)

#ifdef __CRT_UUID_DECL
	__CRT_UUID_DECL(IDesktopWindowXamlSourceNative, 0x3cbcf1bf, 0x2f76, 0x4e9c, 0x96, 0xab, 0xe8, 0x4b, 0x37, 0x97, 0x25, 0x54);
#endif

	MIDL_INTERFACE("3cbcf1bf-2f76-4e9c-96ab-e84b37972554")
		IDesktopWindowXamlSourceNative : public IUnknown
	{
	public:
		virtual HRESULT STDMETHODCALLTYPE AttachToWindow(
			/* [annotation][in] */
			_In_  HWND parentWnd) = 0;

		virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_WindowHandle(
			/* [retval][out] */ HWND* hWnd) = 0;

	};


#else 	/* C style interface */
#error Only C++ style interface is supported
#endif 	/* C style interface */




#endif 	/* __IDesktopWindowXamlSourceNative_INTERFACE_DEFINED__ */


	/* interface __MIDL_itf_windows2Eui2Examl2Ehosting2Edesktopwindowxamlsource_0000_0001 */
	/* [local] */

#endif // NTDDI_VERSION >= NTDDI_WIN10_RS5
#if (NTDDI_VERSION >= NTDDI_WIN10_19H1)


	extern RPC_IF_HANDLE __MIDL_itf_windows2Eui2Examl2Ehosting2Edesktopwindowxamlsource_0000_0001_v0_0_c_ifspec;
	extern RPC_IF_HANDLE __MIDL_itf_windows2Eui2Examl2Ehosting2Edesktopwindowxamlsource_0000_0001_v0_0_s_ifspec;

#ifndef __IDesktopWindowXamlSourceNative2_INTERFACE_DEFINED__
#define __IDesktopWindowXamlSourceNative2_INTERFACE_DEFINED__

	/* interface IDesktopWindowXamlSourceNative2 */
	/* [unique][local][uuid][object] */


	EXTERN_C const IID IID_IDesktopWindowXamlSourceNative2;

#if defined(__cplusplus) && !defined(CINTERFACE)

#ifdef __CRT_UUID_DECL
	__CRT_UUID_DECL(IDesktopWindowXamlSourceNative2, 0xe3dcd8c7, 0x3057, 0x4692, 0x99, 0xc3, 0x7b, 0x77, 0x20, 0xaf, 0xda, 0x31);
#endif

	MIDL_INTERFACE("e3dcd8c7-3057-4692-99c3-7b7720afda31")
		IDesktopWindowXamlSourceNative2 : public IDesktopWindowXamlSourceNative
	{
	public:
		virtual HRESULT STDMETHODCALLTYPE PreTranslateMessage(
			/* [annotation][in] */
			_In_  const MSG * message,
			/* [retval][out] */ BOOL * result) = 0;

	};


#else 	/* C style interface */
#error Only C++ style interface is supported
#endif 	/* C style interface */




#endif 	/* __IDesktopWindowXamlSourceNative2_INTERFACE_DEFINED__ */


	/* interface __MIDL_itf_windows2Eui2Examl2Ehosting2Edesktopwindowxamlsource_0000_0002 */
	/* [local] */

#endif // NTDDI_VERSION >= NTDDI_WIN10_19H1


	extern RPC_IF_HANDLE __MIDL_itf_windows2Eui2Examl2Ehosting2Edesktopwindowxamlsource_0000_0002_v0_0_c_ifspec;
	extern RPC_IF_HANDLE __MIDL_itf_windows2Eui2Examl2Ehosting2Edesktopwindowxamlsource_0000_0002_v0_0_s_ifspec;

	/* Additional Prototypes for ALL interfaces */

	/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif

#pragma endregion  // windows_ui_xaml_hosting_desktopwindowxamlsource_h
