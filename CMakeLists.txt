cmake_minimum_required (VERSION 3.0)
set (CMAKE_CXX_STANDARD 17)

project (GameAnimation)

find_package(OpenGL REQUIRED)

add_definitions(-DXGFX_OPENGL -DGL_SILENCE_DEPRECATION)

# ⤵️ Add to your CMake Project:
add_subdirectory(external/CrossWindow)
add_subdirectory(external/CrossWindow-Graphics)
add_subdirectory(Chapter01)
add_subdirectory(Chapter06)
add_subdirectory(Chapter08)
add_subdirectory(Chapter09)
add_subdirectory(Chapter10)
add_subdirectory(Chapter11)
