workspace "Caveman"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release",
        "Distribution"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
project "Caveman"
    location "Caveman"
    kind "SharedLib"
    language "C++"
    staticruntime "off"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-intermediate/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    -- C/C++ | General | Additional Include Directories
    includedirs
    {
        "%{prj.name}/libs/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        -- C/C++ | Preprocessor | Preprocessor Definitions
        defines
        {
            "CM_PLATFORM_WINDOWS",
            "CM_BUILD_DLL",
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Oasis")
        }

    filter "configurations:Debug"
        defines "CM_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "CM_RELEASE"
        symbols "On"

    filter "configurations:Distribution"
        defines "CM_DISTRIBUTION"
        symbols "On"

project "Oasis"
    location "Oasis"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-intermediate/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    -- C/C++ | General | Additional Include Directories
    includedirs
    {
        "Caveman/libs/spdlog/include",
        "Caveman/src"
    }

    links
    {
        "Caveman"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        -- C/C++ | Preprocessor | Preprocessor Definitions
        defines
        {
            "CM_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "CM_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "CM_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Distribution"
        defines "CM_DISTRIBUTION"
        runtime "Release"
        optimize "On"