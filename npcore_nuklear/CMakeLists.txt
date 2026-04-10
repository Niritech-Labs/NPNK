# Copyright (C) 2026 Niritech Labs
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

cmake_minimum_required(VERSION 3.15)
project(npnuklear_bindings LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)


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

find_library(NUKLEAR_LIB 
    NAMES nuklear
    PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../libnuklear/build
    NO_DEFAULT_PATH
)
if(NOT NUKLEAR_LIB)
    message(FATAL_ERROR "libnuklear.so не найдена. Убедитесь, что она установлена.")
endif()



nanobind_add_module(NPNK
    LTO 
    NPNK.cpp
)

target_include_directories(NPNK PRIVATE ${NUKLEAR_INCLUDE_DIR})
target_link_libraries(NPNK PRIVATE ${NUKLEAR_LIB})



nanobind_add_stub(stub
    TARGET NPNK
    MODULE NPNK
    OUTPUT NPNK.pyi
)

add_dependencies(stub NPNK)

install(TARGETS NPNK LIBRARY DESTINATION .)
