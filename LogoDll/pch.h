// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <psapi.h>
#include <stdexcept>
#include <ShlObj.h>
#include <filesystem>

// add headers that you want to pre-compile here
#include "framework.h"
#include "winrt_custom.hpp"
#include "xamlOM.h"
#include "windows_ui_xaml_hosting_desktopwindowxamlsource.h"
#include "visualtreewatcher.hpp"

#ifdef _DEBUG
#define Trace(X) do {OutputDebugStringA(X);} while(0);
#endif // _DEBUG
#ifndef _DEBUG
#define Trace(X);
#endif

#endif //PCH_H
