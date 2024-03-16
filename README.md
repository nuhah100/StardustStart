# StardustStart - Windows 11 Start Menu Customization Patch

## Overview

StardustStart is not just another Windows 11 start menu customization tool; it's your ticket to a personalized and animated start button experience. Wave goodbye to the mundane default start button and say hello to a world of animated possibilities!

![Preview Image](Assets\preview.png)

## About

Ever felt like your start button was missing a bit of flair? This is the program for you!

But seriously, The logos are precompiled into the binary, but fear not – if you're feeling creative, venture into the section on compiling animations and unleash your imagination.

### Supported Versions

This tool has bravely faced the challenges of Windows 11 22H2 and 23H2, but it's a rebel and should work on any version of Windows 11.

## Installation

Currently, installation is global for all users on the computer and requires administrative privileges.

### Using the UI

Slide the UI slider like a boss to install/uninstall. Patience, young padawan, it might take a few seconds – just enough time for a dramatic pause.

### Manual Installation

For a scripted deployment, manually perform the following steps:

#### Install

1. Place LogoDLl.dll in a globally accessible directory (e.g., `C:\Windows\System32`).
2. In Command Prompt, run `regsvr32.exe LogoDLl.dll`.

#### Uninstall

1. In Command Prompt, run `regsvr32.exe /u LogoDLl.dll`.
2. Restart explorer.exe.
3. Delete the DLL, and feel the power coursing through your veins.

## Compiling

This tool was crafted with love using Visual Studio 2022. Open the project, compile, and feel the warmth of code enveloping you like a cozy blanket.

## How Does it Work?

### Registration

The tool is not just a DLL; it's a VIP pass to the explorer club. It gets registered as an Icon Overlay, making it the star of the show for all users.

For the behind-the-scenes drama of the registration process, check out [dllmain.cpp](LogoDll/dllmain.cpp). Spoiler: it's epic.

### Patching

In the world of Windows 11, Explorer has a new best friend named `WinUI 3`. But, like any friendship, it comes with its quirks – a security sandbox. To bring this new tech into the Explorer party, they introduced [XAML Islands](https://learn.microsoft.com/en-us/windows/apps/desktop/modernize/xaml-islands). It's like gate-crashing the party but with style.

We use `InitializeXamlDiagnosticsEx` to start a debug session with Explorer, then parse XAML tree to find the `StartButton` element. We replace it with our compiled animation, like magic.
To find the right element, we used [UWPSpy](https://github.com/m417z/UWPSpy).

### Animation

In short, the animation uses an element of class `AnimatedVisualPlayer`. To create a custom animation, we turn to the wizards at [Lottie](https://lottiefiles.com/) and sprinkle in some magic from [LottieGen](https://github.com/CommunityToolkit/Lottie-Windows/tree/main/LottieGen). Voila! WinRT/C++ animation is served.

To create your animation:

1. Get creative with After Effects, Figma, or any software supporting the Lottie format.
2. Run `LottieGen -Language Cppwinrt -InputFile <your_animation.json>`.
3. Add your animations to the `LogoDll` directory.
4. Go to [logo.hpp](LogoDll/logo.hpp#L122C13-L122C13) and replace `icon.Source(winrt::make<AnimatedVisuals::implementation::Trex>());` with your animation. Because who needs a T-Rex when you have your creation?
5. Compile and prepare for the magic to unfold.
6. ???
7. Profit – and maybe a standing ovation.

## Credits

### WinLogo

This code and README were inspired by [this repo](https://github.com/shsh999/WinLogo/tree/master). We salute you, pioneers of logo customization!

### TranslucentTB

This code borrows a few tricks from [TranslucentTB](https://github.com/TranslucentTB/TranslucentTB). Sharing is caring!

### Windhawk

This code is like a mixtape, featuring elements from Windhawk mods, specifically [this mode](https://github.com/ramensoftware/windhawk-mods/blob/main/mods/windows-11-taskbar-styler.wh.cpp). Thanks for the inspiration!
