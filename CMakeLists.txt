cmake_minimum_required(VERSION 3.15)
project(StronkEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

### Dev
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

### Configure dependencies

# GLFW
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS    OFF)
set(GLFW_BUILD_DOCS     OFF)
add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/glfw)

# GLAD
add_library(glad STATIC ${CMAKE_SOURCE_DIR}/third_party/glad/src/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_SOURCE_DIR}/third_party/glad/include)

# stb
include_directories(${CMAKE_SOURCE_DIR}/third_party/stb)

# glm
if(${CMAKE_SYSTEM_PROCESSOR} MATCHES "^(arm|aarch64)")
    add_compile_definitions(GLM_ENABLE_SIMD_NEON)
else()
    add_compile_definitions(GLM_ENABLE_SIMD_AVX2)
endif()
include_directories(${CMAKE_SOURCE_DIR}/third_party/glm)
add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/glm)

# Assimp
set(ASSIMP_BUILD_TESTS OFF)
set(ASSIMP_WARNINGS_AS_ERRORS OFF)
set(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
set(ASSIMP_INSTALL OFF)
add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/assimp)

# JSON
set(JSON_BuildTests OFF CACHE BOOL "Disable json tests" FORCE)
add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/json)

# spdlog
set(SPDLOG_BUILD_TESTS OFF CACHE BOOL "Disable spdlog tests" FORCE)
add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/spdlog)


# imgui
add_library(imgui STATIC
    ${CMAKE_SOURCE_DIR}/third_party/imgui/imgui.cpp
    ${CMAKE_SOURCE_DIR}/third_party/imgui/imgui_draw.cpp
    ${CMAKE_SOURCE_DIR}/third_party/imgui/imgui_widgets.cpp
)

target_include_directories(imgui PUBLIC ${CMAKE_SOURCE_DIR}/third_party/imgui)

if (APPLE)
    set(FRAMEWORKS "-framework OpenGL" "-framework Cocoa" "-framework IOKit" "-framework CoreVideo")
endif()

option(STRONK_BUILD_DEMO "Build demo" ON)

add_subdirectory(Engine)

if (STRONK_BUILD_DEMO)
    add_subdirectory(Demo)
endif()
