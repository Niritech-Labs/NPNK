# Copyright (C) 2026 Niritech Labs
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

cmake_minimum_required(VERSION 3.10)
project(Nuklear C)

set(CMAKE_C_STANDARD 99)


add_library(nuklear SHARED nuklear.c)
set_target_properties(nuklear PROPERTIES POSITION_INDEPENDENT_CODE ON)

set_target_properties(nuklear PROPERTIES PUBLIC_HEADER "../nuklear/nuklear.h;../nuklear/demo/glfw_opengl3/nuklear_glfw_gl3.h;../nuklear/demo/glfw_opengl2/nuklear_glfw_gl2.h;../nuklear/demo/glfw_vulkan/nuklear_glfw_vulkan.h")

include(GNUInstallDirs)

install(TARGETS nuklear
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}  
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} 
)
