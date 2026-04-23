# Copyright (C) 2026 Niritech Labs
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

cmake_minimum_required(VERSION 3.10)
project(Nuklear C)

set(CMAKE_C_STANDARD 99)


if(WIN32)
include(WinBuild.cmake)
endif()
if(UNIX)
include(UnixBuild.cmake)
endif()

