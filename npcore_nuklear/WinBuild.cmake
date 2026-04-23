# Copyright (C) 2026 Niritech Labs
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or (at your option) any later version.|
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -static -static-libgcc -static-libstdc++")

add_definitions(-DPy_LIMITED_API=0x030C0000)

include(FetchContent)

FetchContent_Declare(
    python_win_sdk 
    URL "https://www.nuget.org/api/v2/package/python/3.12.0"
)
FetchContent_MakeAvailable(python_win_sdk)

FetchContent_Declare(
    tsl_robin_map
    GIT_REPOSITORY https://github.com/Tessil/robin-map.git
    GIT_TAG        v1.3.0
)
FetchContent_MakeAvailable(tsl_robin_map)
add_library(tsl_robin_map INTERFACE)
target_include_directories(tsl_robin_map INTERFACE "${tsl_robin_map_SOURCE_DIR}/include")

set(Python_INCLUDE_DIRS "${python_win_sdk_SOURCE_DIR}/tools/include")
set(Python_LIBRARIES    "${python_win_sdk_SOURCE_DIR}/tools/libs/python3.lib")
set(Python_VERSION "3.12")


if(NOT TARGET Python::Module)
    add_library(Python::Module INTERFACE IMPORTED)
    set_target_properties(Python::Module PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${Python_INCLUDE_DIRS}"
        INTERFACE_LINK_LIBRARIES "${Python_LIBRARIES}"
    )
    add_library(Python::Headers INTERFACE IMPORTED)
    set_target_properties(Python::Headers PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${Python_INCLUDE_DIRS}"
    )
    

    set(Python_Development_FOUND TRUE)
    set(Python_Development_Module_FOUND TRUE)
    set(Python_FOUND TRUE)
endif()

execute_process(
    COMMAND python -m nanobind --cmake_dir
    OUTPUT_VARIABLE NANOBIND_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_VARIABLE NANOBIND_ERROR
)
if(NOT NANOBIND_DIR)
    message(FATAL_ERROR "${NANOBIND_ERROR}")
endif()

set(nanobind_DIR "${NANOBIND_DIR}")

set(Python_EXECUTABLE "/usr/bin/python3")

set(NB_SUFFIX ".pyd" CACHE STRING "" FORCE)
set(NB_SUFFIX_S ".pyd" CACHE STRING "" FORCE)
set(NB_INTERNALS_VERSION "1" CACHE STRING "" FORCE)

set(NB_STABLE_API ON CACHE BOOL "" FORCE)
set(NB_PYTHON_VERSION_MAJOR 3 CACHE STRING "" FORCE)
set(NB_PYTHON_VERSION_MINOR 12 CACHE STRING "" FORCE)

find_package(nanobind CONFIG REQUIRED)

get_filename_component(NUKLEAR_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../libnuklear/build" ABSOLUTE)
add_library(nuklear_lib SHARED IMPORTED)
set_target_properties(nuklear_lib PROPERTIES
    IMPORTED_LOCATION "${NUKLEAR_LIB_DIR}/libnuklear.dll"
    IMPORTED_IMPLIB   "${NUKLEAR_LIB_DIR}/libnuklear.dll.a"
)

nanobind_add_module(Nuklear
    STABLE_ABI
    LTO
    NPNK.cpp
)

target_link_libraries(Nuklear PRIVATE
    nuklear_lib
    tsl_robin_map 
    "${Python_LIBRARY}"
)

target_link_options(Nuklear PRIVATE "-static")




