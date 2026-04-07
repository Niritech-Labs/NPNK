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
set(GLFW_BUILD_WAYLAND ON CACHE INTERNAL "")

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
#find_package(glad REQUIRED)


find_library(NUKLEAR_LIB nuklear)
find_path(NUKLEAR_INCLUDE_DIR nuklear.h)

find_package(OpenGL REQUIRED)
find_package(Threads REQUIRED) 
find_package(lunasvg REQUIRED) 

nanobind_add_module(npnk_wbackend 
    LTO 
    npnk-backend.cpp
)

target_include_directories(npnk_wbackend PRIVATE ${NUKLEAR_INCLUDE_DIR})
target_link_libraries(npnk_wbackend PRIVATE
    nuklear 
    glfw 
    OpenGL::GL   
    lunasvg
    m
)
set_property(TARGET glfw PROPERTY POSITION_INDEPENT_CODE ON)

nanobind_add_stub(stub
    TARGET npnk_wbackend
    MODULE npnk_wbackend
    OUTPUT npnk_wbackend.pyi
)