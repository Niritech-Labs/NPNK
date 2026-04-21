# Copyright (C) 2026 Niritech Labs
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

cmake_minimum_required(VERSION 3.15)
project(npnuklear_backend LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(GLFW_BUILD_X11 OFF CACHE INTERNAL "")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "")
set(GLFW_INSTALL OFF CACHE INTERNAL "")

if (UNIX)
set(GLFW_BUILD_WAYLAND ON CACHE INTERNAL "")
endif()

if (WIN32)
set(GLFW_BUILD_WIN32 ON CACHE INTERNAL "")
endif()
add_subdirectory(glfw-nor)





find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)

execute_process(
    COMMAND ${Python_EXECUTABLE} -m nanobind --cmake_dir
    OUTPUT_VARIABLE NANOBIND_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_VARIABLE NANOBIND_ERROR
)

if(NOT NANOBIND_DIR)
    message(FATAL_ERROR "Nanobind не найден в Python. Ошибка: ${NANOBIND_ERROR}")
endif()

set(nanobind_DIR "${NANOBIND_DIR}")
find_package(nanobind CONFIG REQUIRED)

get_filename_component(NUKLEAR_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../libnuklear/build" ABSOLUTE)


list(APPEND CMAKE_INSTALL_RPATH "$ORIGIN")
set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

if (UNIX)
find_package(OpenGL REQUIRED)
find_package(lunasvg REQUIRED) 
find_package(PkgConfig REQUIRED)
pkg_check_modules(SPNG REQUIRED spng)


nanobind_add_module(NPWayland 
    LTO 
    NPWayland.cpp
)

target_include_directories(NPWayland PRIVATE ${NUKLEAR_INCLUDE_DIR})
target_link_libraries(NPWayland PRIVATE
    nuklear 
    glfw 
    OpenGL::GL   
    lunasvg
    m
    spng
)
set_property(TARGET glfw PROPERTY POSITION_INDEPENT_CODE ON)

nanobind_add_stub(stub
    TARGET NPWayland
    MODULE NPWayland
    OUTPUT NPWayland.pyi
)
add_dependencies(stub NPWayland)
endif()

if (WIN32)
find_package(OpenGL REQUIRED)

include(FetchContent)

FetchContent_Declare(
    spng
    GIT_REPOSITORY https://github.com/randy408/libspng.git
    GIT_TAG        v0.7.4 
)
FetchContent_MakeAvailable(spng)

FetchContent_Declare(
    lunasvg
    GIT_REPOSITORY https://github.com/sammycage/lunasvg.git
    GIT_TAG        v3.1.0
)
FetchContent_MakeAvailable(lunasvg)

nanobind_add_module(NPWindows 
    LTO 
    NPWindows.cpp
)

target_include_directories(NPWindows PRIVATE ${NUKLEAR_INCLUDE_DIR})
target_link_libraries(NPWindows PRIVATE
    nuklear 
    glfw 
    OpenGL::GL   
    lunasvg
    spng
)
set_property(TARGET glfw PROPERTY POSITION_INDEPENT_CODE ON)

nanobind_add_stub(stub
    TARGET NPWindows
    MODULE NPWindows
    OUTPUT NPWindows.pyi
)
add_dependencies(stub NPWindows)
endif()

