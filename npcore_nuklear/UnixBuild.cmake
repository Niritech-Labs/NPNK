# Copyright (C) 2026 Niritech Labs
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
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



nanobind_add_module(Nuklear
    LTO 
    NPNK.cpp
)

target_include_directories(Nuklear PRIVATE ${NUKLEAR_INCLUDE_DIR})
target_link_libraries(Nuklear PRIVATE ${NUKLEAR_LIB})



nanobind_add_stub(stub
    TARGET Nuklear
    MODULE Nuklear
    OUTPUT Nuklear.pyi
)

add_dependencies(stub Nuklear)

