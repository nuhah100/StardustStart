// dllmain.cpp : Defines the entry point for the DLL application.
#undef GetCurrentTime

#include "pch.h"

#include <winrt/base.h>
#include <winrt/Windows.UI.Core.h>
#include <winrt/Windows.UI.Xaml.h>
#include <winrt/Windows.UI.Xaml.Controls.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.UI.Xaml.Media.h>
#include <winrt/Microsoft.UI.Xaml.Controls.h>

using namespace winrt::Microsoft::UI::Xaml::Controls;

using namespace winrt;
using namespace winrt::Windows::UI::Core;
using namespace winrt::Windows::UI;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Controls;
using namespace winrt::Windows::UI::Xaml::Media;

extern "C" IMAGE_DOS_HEADER __ImageBase;

#define LOGO_KEY L"WinLogo2.0"
#define LOGO_GUID L"{49206d41-7273-6561-BBE2-B73D98328FA5}"
const std::wstring dll_name = L"LogoDll.dll";
static constexpr GUID temp = { 0x49206d41, 0x7273, 0x6561, { 0x6c, 0x20, 0x43, 0x68, 0x61, 0x69, 0x21, 0x31 } };

typedef HRESULT(*InitializeXamlDiagnosticsExProto)(_In_ LPCWSTR endPointName, _In_ DWORD pid, _In_opt_ LPCWSTR wszDllXamlDiagnostics, _In_ LPCWSTR wszTAPDllName, _In_opt_ CLSID tapClsid, _In_ LPCWSTR wszInitializationData);

std::wstring VALID_PROCESS_NAMES[] = { L"regsvr32.exe", L"explorer.exe" };

void initXmlDll() {
	wchar_t path[MAX_PATH];
	HMODULE hm = NULL;

	HMODULE xml_dll = LoadLibraryEx(L"Windows.UI.Xaml.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
	if (xml_dll == NULL)
	{
		Trace("Could not load \"Windows.UI.Xaml.dll\" dll.");
		return;
	}

	InitializeXamlDiagnosticsExProto InitializeXamlDiagnosticsExFn = (InitializeXamlDiagnosticsExProto)GetProcAddress(xml_dll, "InitializeXamlDiagnosticsEx");

	if (InitializeXamlDiagnosticsExFn == NULL)
	{
		Trace("Could not find \"InitializeXamlDiagnosticsEx\" function in xaml.dll.");
		return;
	}

	if (GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
		GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
		(LPCSTR)&initXmlDll, &hm) == 0)
	{
		// Return or however you want to handle an error.
		Trace("Didn't find the module address");
		return;
	}

	if (GetModuleFileNameW(hm, path, ARRAYSIZE(path)) == 0)
	{
		// Return or however you want to handle an error.
		Trace("Could not print get the module path.");
		return;
	}

	path[MAX_PATH - 1] = 0;
	path[MAX_PATH - 2] = 0;

	while(InitializeXamlDiagnosticsExFn(L"VisualDiagConnection1", GetCurrentProcessId(), NULL, path, temp, L"") != 0) {
		Sleep(100);
	}

	FreeLibrary(xml_dll);

	Trace("Finished hooking target!")
}

HMODULE GetCurrentModuleHandle() {
	HMODULE module;
	if (!GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
		GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
		L"", &module)) {
		return nullptr;
	}

	return module;
}

struct ExplorerTAP : winrt::implements<ExplorerTAP, IObjectWithSite, winrt::non_agile>
{
	winrt::com_ptr<VisualTreeWatcher> visualTreeWatcher;

    template<typename T>
    static winrt::com_ptr<T> FromIUnknown(IUnknown* pSite)
    {
        winrt::com_ptr<IUnknown> site;
        site.copy_from(pSite);

        return site.as<T>();
    }

	HRESULT STDMETHODCALLTYPE SetSite(IUnknown* pUnkSite) noexcept override
	{
		if (visualTreeWatcher != nullptr) {
			visualTreeWatcher->UnadviseVisualTreeChange();
			visualTreeWatcher = nullptr;
		}

		site.copy_from(pUnkSite);

		if (site) {
			HMODULE hCur = GetCurrentModuleHandle();
			
			if (hCur == NULL) {
				Trace("GetCurrentModuleHandle failed...");
				return S_FALSE;
			}

			FreeLibrary(hCur);

			visualTreeWatcher = winrt::make_self<VisualTreeWatcher>(site);
		}

        return S_OK;
	}

	HRESULT STDMETHODCALLTYPE GetSite(REFIID riid, void** ppvSite) noexcept override
	{
		return site.as(riid, ppvSite);
	}

private:
	winrt::com_ptr<IUnknown> site;
};


struct TAPFactory : winrt::implements<TAPFactory, IClassFactory>
{
	HRESULT STDMETHODCALLTYPE CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppvObject) override try
	{
		if (pUnkOuter)
		{
			return CLASS_E_NOAGGREGATION;
		}

		*ppvObject = nullptr;

		return winrt::make<ExplorerTAP>().as(riid, ppvObject);
	}
	catch (...)
	{
		return winrt::to_hresult();
	}

	HRESULT STDMETHODCALLTYPE LockServer(BOOL) noexcept override
	{
		return S_OK;
	}
};


_Use_decl_annotations_ STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv) try
{
	if (rclsid == temp)
	{
		*ppv = nullptr;
		Trace("Making TAPFactory!");
		return winrt::make<TAPFactory>().as(riid, ppv);
	}
	else
	{
		return CLASS_E_CLASSNOTAVAILABLE;
	}
}
catch (...)
{
	Trace("Error in DllGetClassObject");
	return winrt::to_hresult();
}

_Use_decl_annotations_ STDAPI DllCanUnloadNow(void)
{
	if (winrt::get_module_lock())
	{
		return S_FALSE;
	}
	else
	{
		return S_OK;
	}
}

void tryLoadLogo() {
	Trace("Tries to load logo...");
	if (SHLoadNonloadedIconOverlayIdentifiers() != S_OK) {
		Trace("SHLoadNonloadedIconOverlayIdentifiers failed...");
	}

	SHChangeNotify(SHCNE_ASSOCCHANGED, SHCNF_IDLIST | SHCNF_FLUSH, nullptr, nullptr);
}

void RegisterServer() {
	wchar_t path[MAX_PATH];
	HMODULE hm = NULL;

	if (!GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
		GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
		(LPCSTR)&initXmlDll, &hm))
	{
		// Return or however you want to handle an error.
		return;
	}

	if (GetModuleFileNameW(hm, path, ARRAYSIZE(path)) == 0)
	{
		// Return or however you want to handle an error.
		Trace("Failed in GetModuleFileNameW in RegisterServer");
		return;
	}

	HKEY key;
	LSTATUS stat;

	stat = RegCreateKeyW(HKEY_LOCAL_MACHINE, L"Software\\Classes\\CLSID\\" LOGO_GUID, &key);
	if (stat != ERROR_SUCCESS) { Trace("Failed to Create CLSID key"); return; }
	stat = RegSetValueW(key, NULL, REG_SZ, (LPCWSTR)LOGO_KEY, wcslen(LOGO_KEY) * 2 + 1);
	if (stat != ERROR_SUCCESS) { Trace("Failed to set CLSID key"); return; }
	Trace("Created a CLSID");

	stat = RegSetKeyValueW(key, L"InprocServer32", NULL, REG_SZ, (LPCWSTR)path, wcslen(path) * 2 + 1);
	if (stat != ERROR_SUCCESS) { Trace("Failed to create InprocServer32"); return; }
	stat = RegSetKeyValueW(key, L"InprocServer32", L"ThreadingModel", REG_SZ, (LPCWSTR)L"Apartment", wcslen(L"Apartment") * 2 + 1);
	if (stat != ERROR_SUCCESS) { Trace("Failed to set InprocServer32"); return; }
	Trace("Create InprocServer32");

	// now to the shell extensions
	stat = RegOpenKeyW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions\\Approved", &key);
	if (stat != ERROR_SUCCESS) { Trace("Failed to open Approved key"); return; }
	stat = RegSetKeyValueW(key, L"", LOGO_GUID, REG_SZ, (LPCWSTR)LOGO_KEY, sizeof(LOGO_KEY) + 1);
	if (stat != ERROR_SUCCESS) { Trace("Failed to set value in Approved key"); return; }
	Trace("Create shell extension!");

	stat = RegCreateKeyW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellIconOverlayIdentifiers\\" LOGO_KEY, &key);
	if (stat != ERROR_SUCCESS) { Trace("Failed to create ShellIconOverlayIdentifiers unique key"); return; }
	stat = RegSetValueW(key, L"", REG_SZ, (LPCWSTR)LOGO_GUID, sizeof(LOGO_GUID) + 1);
	if (stat != ERROR_SUCCESS) { Trace("Failed to set value in ShellIconOverlayIdentifiers"); return; }
	Trace("Create ShellIconOverlayIdentifier!");
}

void UnRegisterServer() {
	HKEY key;

	// Unregister CLSID
	if (RegOpenKeyW(HKEY_LOCAL_MACHINE, L"Software\\Classes\\CLSID\\" LOGO_GUID, &key) == ERROR_SUCCESS) {
		RegDeleteTreeW(key, NULL);
		RegCloseKey(key);
	}

	// Unregister ShellIconOverlayIdentifier
	if (RegOpenKeyW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ShellIconOverlayIdentifiers\\" LOGO_KEY, &key) == ERROR_SUCCESS) {
		RegDeleteKeyW(key, NULL);
		RegCloseKey(key);
	}

	// Unregister Approved key
	if (RegOpenKeyW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions\\Approved\\" LOGO_KEY, &key) == ERROR_SUCCESS) {
		RegDeleteKeyW(key, NULL);
		RegCloseKey(key);
	}
}


extern "C" HRESULT __stdcall DllRegisterServer() {
	try {
		RegisterServer();
		tryLoadLogo();
	}
	catch (...) {
		Trace("DllRegisterServer failed...");
		return S_FALSE;
	}

	return S_OK;
}

/**
 * Unregister the DLL as an Icon Overlay and trigger and stop the logo changes, if they are applied.
 */
extern "C" HRESULT __stdcall DllUnregisterServer() {
	try {
		UnRegisterServer();
	}
	catch (...) {
		Trace("UnRegisterServer failed...");
		return S_FALSE;
	}

	return S_OK;
}


LPCWSTR GetPathToRunningExe()
{
	wchar_t szPath[MAX_PATH] = { 0 };
	DWORD dwSize = GetModuleFileNameW(NULL, szPath, ARRAYSIZE(szPath));
	wchar_t* result = NULL;

	if (dwSize > 0)
	{
		size_t count = wcslen(szPath) + 1;
		result = (wchar_t*)malloc(count * sizeof(szPath[0]));

		if (result != NULL)
		{
			if (wcscpy_s(result, count, szPath) != 0)
			{
				Trace("wcscpy_s failed in GetPathToRunningExe");
				free(result); // Free allocated memory in case of failure
				result = NULL;
			}
		}
		else
		{
			Trace("Memory allocation failed in GetPathToRunningExe");
		}
	}
	else
	{
		Trace("GetModuleFileNameW failed in GetPathToRunningExe");
	}

	return result;
}


bool isValidProcess(std::wstring &name) {
	try {
		for (auto& validName : VALID_PROCESS_NAMES) {
			if (name == validName) {
				return true;
			}
		}
	}
	catch (...) {
		// Intentionally left blank.
		Trace("isValidProcess failed...");
	}

	return false;
}

DWORD WINAPI ThreadProc(LPVOID lpParameter) {
	Trace("Starting main thread!");

	initXmlDll();

	tryLoadLogo();

	return ERROR_SUCCESS;
}


BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	UNREFERENCED_PARAMETER(lpReserved);

	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(hModule);
		std::wstring name = GetPathToRunningExe();
		if (name.empty()) {
			return FALSE;
		}

		std::transform(name.begin(), name.end(), name.begin(), towlower);
		name = name.substr(name.rfind(L"\\") + 1);
		if (name.empty()) {
			return FALSE;
		}
		
		if (!isValidProcess(name)) {
			Trace("Process is not valid, exiting...");
			OutputDebugStringW(name.c_str());
			return FALSE;
		}

		if (name == L"regsvr32.exe") {
			Trace("Regsvr has loaded me, exiting nicely...");
			return TRUE;
		}

		Trace("Creating the hooking thread!");
		HANDLE hThread = CreateThread(
			NULL,
			0,
			ThreadProc,
			NULL,
			0,
			NULL
		);
		if (hThread == NULL) {
			return FALSE;
		}

		Trace("Thread was created successfully!");
	}
	else if (ul_reason_for_call == DLL_PROCESS_DETACH) {
		Trace("Time to die!");
	}

	return TRUE;
}