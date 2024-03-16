#pragma region visualtreewatcher_cpp

#include "pch.h"
#include "logo.hpp"

#include <winrt/Windows.UI.Xaml.Hosting.h>

VisualTreeWatcher::VisualTreeWatcher(winrt::com_ptr<IUnknown> site) :
    m_XamlDiagnostics(site.as<IXamlDiagnostics>())
{
    Trace("Constructing VisualTreeWatcher");
    winrt::check_hresult(m_XamlDiagnostics.as<IVisualTreeService3>()->AdviseVisualTreeChange(this));
}


void VisualTreeWatcher::SetXamlDiagnostics(winrt::com_ptr<IXamlDiagnostics> diagnostics)
{
    m_XamlDiagnostics = std::move(diagnostics);
}

VisualTreeWatcher::~VisualTreeWatcher() = default;

HRESULT VisualTreeWatcher::OnVisualTreeChange(ParentChildRelation, VisualElement element, VisualMutationType mutationType) try
{
    try {
        const auto inspectable = FromHandle<wf::IInspectable>(element.Handle);

        auto frameworkElement = inspectable.try_as<wux::FrameworkElement>();
        if (!frameworkElement)
        {
            const auto desktopXamlSource = FromHandle<wuxh::DesktopWindowXamlSource>(element.Handle);
            frameworkElement = desktopXamlSource.Content().try_as<wux::FrameworkElement>();
        }
     
        if (frameworkElement && mutationType == Add)
        {
            ApplyCustomizations(frameworkElement);
        }
    }
    catch (winrt::hresult_error const& ex) {
        Trace("Error in VisualTreeWatcher::OnVisualTreeChange...");
    }
    
    return S_OK;
}
catch (...)
{
    HRESULT hr = winrt::to_hresult();
    // Returning an error prevents (some?) further messages, always return
    // success.
    // return hr;
    return S_OK;
}

HRESULT VisualTreeWatcher::OnElementStateChanged(InstanceHandle, VisualElementState, LPCWSTR) noexcept
{
    return S_OK;
}

void VisualTreeWatcher::UnadviseVisualTreeChange()
{
    Trace("UnadviseVisualTreeChange VisualTreeWatcher");
    winrt::check_hresult(m_XamlDiagnostics.as<IVisualTreeService3>()->UnadviseVisualTreeChange(this));
}

#pragma endregion  // visualtreewatcher_cpp
