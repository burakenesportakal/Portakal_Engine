workspace "Portakal"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

    startproject "Sandbox"

    filter "system:windows"
        staticruntime "on"          
        buildoptions { "/utf-8" }   
    filter {} 

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Portakal"
    location "Portakal"
    kind "SharedLib"
    language "C++"

    targetdir("bin/" .. outputDir .. "/%{prj.name}")
    objdir("bin-int/" .. outputDir .. "/%{prj.name}")

    files {
       "%{prj.name}/src/**.h", 
       "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines {
            "PRTKL_PLATFORM_WINDOWS",
            "PRTKL_BUILD_DLL"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "PRTKL_DEBUG"
        symbols "on"

    filter "configurations:Release"
        defines "PRTKL_RELEASE"
        optimize "on"

    filter "configurations:Dist"
        defines "PRTKL_DIST"
        optimize "on"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    
    targetdir("bin/" .. outputDir .. "/%{prj.name}")
    objdir("bin-int/" .. outputDir .. "/%{prj.name}")
    
    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs {
        "Portakal/vendor/spdlog/include",
        "Portakal/src"
    }
    
    links {
        "Portakal"
    }
    
    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"
        defines {
            "PRTKL_PLATFORM_WINDOWS"
        }
        
    filter "configurations:Debug"
        defines "PRTKL_DEBUG"
        symbols "on"
        
    filter "configurations:Release"
        defines "PRTKL_RELEASE"
        optimize "on"
        
    filter "configurations:Dist"
        defines "PRTKL_DIST"
        optimize "on"