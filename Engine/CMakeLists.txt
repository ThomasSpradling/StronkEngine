cmake_minimum_required(VERSION 3.15)
project(Engine)

file(GLOB_RECURSE ENGINE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.cpp
)

add_library(engine STATIC ${ENGINE_SOURCES})

target_include_directories(engine PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/Engine>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(engine PUBLIC
    glfw
    glad
    nlohmann_json
    assimp
    spdlog
    imgui
    ${FRAMEWORKS}
)
