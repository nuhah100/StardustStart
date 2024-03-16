
#include <winrt/base.h>
#include <winrt/Windows.UI.Core.h>
#include <winrt/Windows.UI.Xaml.h>
#include <winrt/Windows.UI.Xaml.Controls.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.UI.Xaml.Media.h>
#include <winrt/Microsoft.UI.Xaml.Controls.h>

#include "pch.h"
#include "AnimatedVisuals.TRex.h"


using namespace winrt::Microsoft::UI::Xaml::Controls;

using namespace winrt;
using namespace winrt::Windows::UI::Core;
using namespace winrt::Windows::UI;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Controls;
using namespace winrt::Windows::UI::Xaml::Media;

FrameworkElement FindChildByName(FrameworkElement element, PCWSTR name) {
    try {
        int childrenCount = Media::VisualTreeHelper::GetChildrenCount(element);

        for (int i = 0; i < childrenCount; i++) {
            auto child = Media::VisualTreeHelper::GetChild(element, i)
                .try_as<FrameworkElement>();
            if (!child) {
                continue;
            }

            if (child.Name() == name) {
                return child;
            }
        }
    }
    catch (winrt::hresult_error const& ex) {
        Trace("Error in FindChildByName...");
    }

    return nullptr;
}


FrameworkElement FindElementRecursive(FrameworkElement element, PCWSTR name, PCWSTR className) {
    try {
        int childrenCount = Media::VisualTreeHelper::GetChildrenCount(element);

        for (int i = 0; i < childrenCount; i++) {
            auto child = Media::VisualTreeHelper::GetChild(element, i)
                .try_as<FrameworkElement>();

            if (!child) {
                continue;
            }

            auto tryClass = winrt::get_class_name(child);

            if (tryClass == className && child.Name() == name)
            {
                return child;
            }


            auto el = FindElementRecursive(child, name, className);
            if (el != NULL)
                return el;
        }
    }
    catch (winrt::hresult_error const& ex) {
        Trace("Error in FindElementRecursive...");
    }

    return NULL;
}

void ApplyCustomizations(FrameworkElement element) {

    if (!element) {
        return;
    }

    auto& rootElement = element;

    try {

        // Get to the parnet
        while (true) {
            auto parent = Media::VisualTreeHelper::GetParent(rootElement)
                .as<FrameworkElement>();
            if (!parent) {
                break;
            }
            rootElement = parent;
        }

        auto startButtonFather = FindElementRecursive(rootElement, L"LaunchListButton", L"Taskbar.ExperienceToggleButton");
        if (startButtonFather == NULL)
        {
            return;
        }

        auto startButton = FindElementRecursive(startButtonFather, L"ExperienceToggleButtonRootPanel", L"Taskbar.TaskListButtonPanel");
        if (startButton == NULL)
        {
            return;
        }

        Microsoft::UI::Xaml::Controls::AnimatedVisualPlayer icon = FindChildByName(startButton, L"Icon").as<Microsoft::UI::Xaml::Controls::AnimatedVisualPlayer>();
        if (icon == NULL)
        {
            return;
        }

        auto iconSource = icon.Source().try_as<AnimatedVisuals::implementation::Trex>();
        
        // if iconSource is nullptr it means the conversion wasn't successfull, therfore the Source is not Trex
        if (iconSource == nullptr) {
            icon.Source(winrt::make<AnimatedVisuals::implementation::Trex>());
            Trace("Made windows logo better!");
        }
    }
    catch (winrt::hresult_error const& ex) {
        Trace("Error when trying to replace logo...");
    }

}