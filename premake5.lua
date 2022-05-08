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
    staticruntime "on"

    targetdir("bin/%{cfg.buildcfg}/%{prj.name}")
    objdir("bin-int/%{cfg.buildcfg}/%{prj.name}")

    pchheader "pch.hpp"
    pchsource "%{prj.name}/src/pch.cpp"

    prebuildcommands
    {
        "powershell -Command \"Set-Location ..\\; .\\sdk\\download.ps1\""
    }

    files
    {
        "LemonUI.SHV/src/**.hpp",
        "LemonUI.SHV/src/**.cpp"
    }

    includedirs
    {
        "%{IncludeDir.scripthookv}",
        "%{IncludeDir.natives}",
        "%{IncludeDir.ikt}",
        "LemonUI.SHV/src"
    }

    libdirs
    {
        "%{LibrariesDir.scripthookv}"
    }

    links
    {
        "ScriptHookV"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
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
        optimize "on"

project "LemonUI.SHV.Example"
    location "LemonUI.SHV.Example"
    kind "SharedLib"
    targetextension ".asi"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("bin/%{cfg.buildcfg}/%{prj.name}")
    objdir("bin-int/%{cfg.buildcfg}/%{prj.name}")

    pchheader "pch.hpp"
    pchsource "%{prj.name}/src/pch.cpp"

    files
    {
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{IncludeDir.scripthookv}",
        "%{IncludeDir.natives}",
        "%{IncludeDir.ikt}",
        "%{IncludeDir.lemonui}",
        "LemonUI.SHV/src"
    }

    libdirs
    {
        "%{LibrariesDir.scripthookv}",
        "%{LibrariesDir.lemonui}"
    }

    links
    {
        "ScriptHookV",
        "LemonUI.SHV"
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
        optimize "on"