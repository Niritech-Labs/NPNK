//Copyright (C) 2026 Niritech Labs
//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <limits.h>
#include <time.h>

#define GLAD_GL_IMPLEMENTATION
#define NK_GLFW_GL3_IMPLEMENTATION
#define GLFW_EXPOSE_NATIVE_WAYLAND
#define NK_IMPLEMENTATION
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_STANDARD_BOOL
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_INCLUDE_STANDARD_VARARGS

#include <spng.h>
#include <nanobind/nanobind.h>
#include <nanobind/stl/tuple.h>
#include <lunasvg/lunasvg.h> 
#include <vector>
#include "glfw-nor/deps/glad/gl.h"
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>   
#include "../nuklear/nuklear.h"

#include "../nuklear/demo/glfw_opengl3/nuklear_glfw_gl3.h"

#define MAX_VERTEX_BUFFER 512 * 1024
#define MAX_ELEMENT_BUFFER 128 * 1024

namespace nb = nanobind;


class Backend {
private:
    GLFWwindow   *window;
    struct nk_context *nk_ctx;
    struct nk_glfw glfw;
    bool glfw_initialized;
    int width, height;
    struct nk_colorf bg;
    struct nk_font *font;
    struct nk_mouse_button buf;
    bool lbd;

    static void glfw_error_callback(int err, const char *desc) {
        fprintf(stderr, "GLFW error %d: %s\n", err, desc);
    }

public:
    Backend() {
        window = NULL;
        nk_ctx = NULL;
        memset(&glfw, 0, sizeof(glfw));
        glfw_initialized = false;
        width = 0;
        height = 0;
        bg.r = 0.10f;
        bg.g = 0.18f;
        bg.b = 0.24f;
        bg.a = 1.0f;
        lbd = 0;
    }

    ~Backend() {
        if (window) Shutdown();
    }

    void GLFWInit() {
        if (glfw_initialized) return;
        glfwSetErrorCallback(glfw_error_callback);
        if (!glfwInit())
            throw std::runtime_error("Failed to initialize GLFW");
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfw_initialized = true;
    }

    void CreateWindow(int widthps, int heightps, const char* title, bool decorated, bool layerShell) {
        if (window)
            throw std::runtime_error("Window already exists");

        glfwWindowHint(GLFW_DECORATED, decorated);
        if (layerShell) {
            glfwWindowHint(GLFW_WAYLAND_ZWLR_KEYBOARD_ON_FOCUS, GLFW_TRUE);
            glfwWindowHint(GLFW_WAYLAND_USE_ZWLR, GLFW_WAYLAND_ZWLR_LAYER_TOP);
        }

        window = glfwCreateWindow(widthps, heightps, title, nullptr, nullptr);
        if (!window)
            throw std::runtime_error("Failed to create window");

        glfwMakeContextCurrent(window);
        if (!gladLoadGL(glfwGetProcAddress))
            throw std::runtime_error("Failed to load OpenGL");
        glViewport(0, 0, widthps, heightps);

        nk_ctx = nk_glfw3_init(&glfw, window, NK_GLFW3_INSTALL_CALLBACKS);
        if (!nk_ctx)
            throw std::runtime_error("Failed to init Nuklear");

        
    }


    void InitFont(bool nonstdfont,const char* filepath,int bold) {
        {struct nk_font_atlas* atlas;
            nk_glfw3_font_stash_begin(&glfw, &atlas);
            if (nonstdfont) {
                font = nk_font_atlas_add_from_file(atlas, filepath, bold, 0);
            }
            nk_glfw3_font_stash_end(&glfw);
            if (nonstdfont) {
                nk_style_set_font(nk_ctx, &font->handle);
            }
        }
    }

    nk_context* GetNKContext() {
        if (!nk_ctx) throw std::runtime_error("Nuklear not initialized");
        return nk_ctx;
    }

    void NewFrame() {
        if (!nk_ctx) throw std::runtime_error("Nuklear not initialized");
        nk_glfw3_new_frame(&glfw);
    }

    void Render() {
        if (!window) throw std::runtime_error("No window");
        glfwGetWindowSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClearColor(bg.r, bg.g, bg.b, bg.a);
        glClear(GL_COLOR_BUFFER_BIT);
        nk_glfw3_render(&glfw, NK_ANTI_ALIASING_ON, MAX_VERTEX_BUFFER, MAX_ELEMENT_BUFFER);
        glfwSwapBuffers(window);
    }

    void PollEvents() {
        if (!window) throw std::runtime_error("No window");
        glfwPollEvents();
    }

    void WaitEvents() {
        if (!window) throw std::runtime_error("No window");
        glfwWaitEvents();
    }

    bool ShouldClose() {
        if (!window) return true;
        return glfwWindowShouldClose(window) != 0;
    }

    void SetShouldClose(bool value) {
        if (!window) return;
        glfwSetWindowShouldClose(window, value ? GLFW_TRUE : GLFW_FALSE);
    }

    std::tuple<int, int> GetWindowSize() {
        if (!window) return {0, 0};
        int w, h;
        glfwGetWindowSize(window, &w, &h);
        return {w, h};
    }

    void LS_SetExclusiveZone(int zone) {
        if (!window) throw std::runtime_error("No window");
        glfwWaylandZwlrSetExclusiveZone(window, zone);
    }

    void LS_SetMargin(int top, int right, int bottom, int left) {
        if (!window) throw std::runtime_error("No window");
        glfwWaylandZwlrSetMargin(window, top, right, bottom, left);
    }

    void LS_SetLayer(int layer) {
        if (!window) throw std::runtime_error("No window");
        static const int layers[] = {
            GLFW_WAYLAND_ZWLR_LAYER_TOP,
            GLFW_WAYLAND_ZWLR_LAYER_OVERLAY,
            GLFW_WAYLAND_ZWLR_LAYER_BOTTOM,
            GLFW_WAYLAND_ZWLR_LAYER_BACKGROUND
        };
        if (layer < 0 || layer >= 4)
            throw std::runtime_error("Invalid layer index (0..3)");
        glfwWaylandZwlrSetLayer(window, layers[layer]);
    }

    void LS_SetAnchor(int anchor) {
        if (!window) throw std::runtime_error("No window");
        static const int anchors[] = {
            GLFW_WAYLAND_ZWLR_ANCHOR_TOP,
            GLFW_WAYLAND_ZWLR_ANCHOR_BOTTOM,
            GLFW_WAYLAND_ZWLR_ANCHOR_LEFT,
            GLFW_WAYLAND_ZWLR_ANCHOR_RIGHT
        };
        if (anchor < 0 || anchor >= 4)
            throw std::runtime_error("Invalid anchor index (0..3)");
        glfwWaylandZwlrSetAnchor(window, anchors[anchor]);
    }

    void SetKeyboardFocus(bool focus) {
        if (!window) throw std::runtime_error("No window");
        glfwWaylandZwlrSetKeyboardFocus(window, focus);
    }

    void Shutdown() {
        if (nk_ctx) {
            nk_glfw3_shutdown(&glfw);
            nk_ctx = nullptr;
        }
        if (window) {
            glfwDestroyWindow(window);
            window = nullptr;
        }
        if (glfw_initialized) {
            glfwTerminate();
            glfw_initialized = false;
        }
    }

    static struct nk_image LoadSVGImage(const char* filename, int width, int height) {
        auto document = lunasvg::Document::loadFromFile(filename);
        if (!document) throw std::runtime_error("Failed to open file");

        auto bitmap = document->renderToBitmap(width, height);
        bitmap.convertToRGBA(); 

        GLuint tex;
        glGenTextures(1, &tex);
        glBindTexture(GL_TEXTURE_2D, tex);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, 
                 GL_RGBA, GL_UNSIGNED_BYTE, bitmap.data());


        return nk_image_id((int)tex);
    }

    static struct nk_image LoadPNGImage(const char* filename) {
        FILE *fp = fopen(filename, "rb");
        if (!fp) throw std::runtime_error("Failed to open file");

        spng_ctx *sctx = spng_ctx_new(0);
        if (!sctx) { 
            fclose(fp); 
            throw std::runtime_error("Failed to create spng context"); 
        }

        spng_set_png_file(sctx, fp);

        struct spng_ihdr ihdr;
        spng_get_ihdr(sctx, &ihdr);


        size_t out_size;
        spng_decoded_image_size(sctx, SPNG_FMT_RGBA8, &out_size);

        std::vector<unsigned char> out_data(out_size);

        int ret = spng_decode_image(sctx, out_data.data(), out_size, SPNG_FMT_RGBA8, SPNG_DECODE_TRNS);
        
        if (ret) {
            spng_ctx_free(sctx);
            fclose(fp);
            throw std::runtime_error("Failed to decode PNG");
        }

        GLuint tex;
        glGenTextures(1, &tex);
        glBindTexture(GL_TEXTURE_2D, tex);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, ihdr.width, ihdr.height, 0, 
                     GL_RGBA, GL_UNSIGNED_BYTE, out_data.data());


        spng_ctx_free(sctx);
        fclose(fp);

        return nk_image_id((int)tex);
    }

};

NB_MODULE(NPWayland, m) {
    nb::class_<Backend>(m, "Window")
        .def(nb::init<>())
        .def("GLFWInit", &Backend::GLFWInit)
        .def("CreateWindow", &Backend::CreateWindow)
        .def("GetNKContext", &Backend::GetNKContext)
        .def("NewFrame", &Backend::NewFrame)
        .def("Render", &Backend::Render)
        .def("PollEvents", &Backend::PollEvents)
        .def("WaitEvents", &Backend::WaitEvents)
        .def("ShouldClose", &Backend::ShouldClose)
        .def("SetShouldClose", &Backend::SetShouldClose)
        .def("GetWindowSize", &Backend::GetWindowSize)
        .def("LS_SetExclusiveZone", &Backend::LS_SetExclusiveZone)
        .def("LS_SetMargin", &Backend::LS_SetMargin)
        .def("LS_SetLayer", &Backend::LS_SetLayer)
        .def("LS_SetAnchor", &Backend::LS_SetAnchor)
        .def("SetKeyboardFocus", &Backend::SetKeyboardFocus)
        .def("Shutdown", &Backend::Shutdown)
        .def("InitFont", &Backend::InitFont)
        .def_static("LoadSVGImage", &Backend::LoadSVGImage)
        .def_static("LoadPNGImage", &Backend::LoadPNGImage);
}


