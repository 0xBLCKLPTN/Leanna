cmake_minimum_required(VERSION 3.13)
project(LeannaGE VERSION 1.0 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 14)
if(NOT CMAKE_CXX_EXTENSIONS)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_executable(LeannaGE
  core/graphica/window.cpp
)

add_subdirectory(./include/glfw)
target_link_libraries(LeannaGE glfw)

find_package(GLEW REQUIRED)
target_link_libraries(LeannaGE GLEW::GLEW)

find_package(OpenGL REQUIRED)
target_link_libraries(LeannaGE OpenGL::GL)
