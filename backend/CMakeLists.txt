# Copyright (C) 2026 Niritech Labs
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

set(NB_STABLE_API ON CACHE BOOL "" FORCE)
set(NB_PYTHON_VERSION_MAJOR 3 CACHE STRING "" FORCE)
set(NB_PYTHON_VERSION_MINOR 12 CACHE STRING "" FORCE)


cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0135 NEW)

project(npnuklear_backend LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(GLFW_BUILD_X11 OFF CACHE INTERNAL "")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "")
set(GLFW_INSTALL OFF CACHE INTERNAL "")


if(WIN32)
include(WinBuild.cmake)
endif()
if(UNIX)
include(UnixBuild.cmake)
endif()




