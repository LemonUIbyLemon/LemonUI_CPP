workspace "LemonUI_CPP"
    architecture "x64"
    startproject "LemonUI.SHV"

    configurations { "Debug", "Release" }

    flags
    {
        "MultiProcessorCompile"
    }

-- Include directories
IncludeDir = {}
IncludeDir["scripthookv"] = "sdk/scripthookv/inc"
IncludeDir["natives"] = "sdk/natives"
IncludeDir["ikt"] = "sdk/ikt"
IncludeDir["lemonui"] = "LemonUI.SHV/"

-- Libraries
LibrariesDir = {}
LibrariesDir["scripthookv"] = "sdk/scripthookv/lib"
LibrariesDir["lemonui"] = "bin/Debug/LemonUI.SHV"

project "LemonUI.SHV"
    location "LemonUI.SHV"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir("bin/%{cfg.buildcfg}/%{prj.name}")
    objdir("bin-int/%{cfg.buildcfg}/%{prj.name}")

    pchheader "pch.h"
    pchsource "LemonUI.SHV/pch.cpp"

    prebuildcommands
    {
        "powershell -Command \"Set-Location ..\\; .\\sdk\\download.ps1\""
    }

    files
    {
        "LemonUI.SHV/**.hpp",
        "LemonUI.SHV/**.cpp"
    }

    includedirs
    {
        "%{IncludeDir.scripthookv}",
        "%{IncludeDir.natives}",
        "%{IncludeDir.ikt}"
    }

    libdirs
    {
        "%{LibrariesDir.scripthookv}"
    }

    links
    {
        "ScriptHookV"
    }

    filter "system:windows"
        systemversion "latest"
    
    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

        defines
        {
            "_DEBUG"
        }

    filter "configurations:Release"
        runtime "Release"
        symbols "off"

project "LemonUI.SHV.Example"
    location "LemonUI.SHV.Example"
    kind "SharedLib"
    targetextension ".asi"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir("bin/%{cfg.buildcfg}/%{prj.name}")
    objdir("bin-int/%{cfg.buildcfg}/%{prj.name}")

    pchheader "pch.h"
    pchsource "LemonUI.SHV.Example/pch.cpp"

    files
    {
        "LemonUI.SHV.Example/**.hpp",
        "LemonUI.SHV.Example/**.cpp"
    }

    includedirs
    {
        "%{IncludeDir.scripthookv}",
        "%{IncludeDir.natives}",
        "%{IncludeDir.ikt}",
        "%{IncludeDir.lemonui}"
    }

    libdirs
    {
        "%{LibrariesDir.scripthookv}",
        "%{LibrariesDir.lemonui}"
    }

    links
    {
        "ScriptHookV.lib",
        "LemonUI.SHV.lib"
    }

    filter "system:windows"
        systemversion "latest"
    
    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

        defines
        {
            "_DEBUG"
        }

    filter "configurations:Release"
        runtime "Release"
        symbols "off"