cmake_minimum_required(VERSION 3.15)
project(Demo)

file(GLOB_RECURSE DEMO_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.cpp
) 
add_executable(demo ${DEMO_SOURCES})

target_include_directories(demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(demo PRIVATE engine)
