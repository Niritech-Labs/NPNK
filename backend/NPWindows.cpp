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

//#include <spng.h>
#include <nanobind/nanobind.h>
#include <nanobind/stl/tuple.h>
#include <lunasvg.h> 
#include <vector>
#include "glfw-nor/deps/glad/gl.h"
#include <GLFW/glfw3.h>
#include "../nuklear/nuklear.h"

#include "../nuklear/demo/glfw_opengl3/nuklear_glfw_gl3.h"

#define MAX_VERTEX_BUFFER 512 * 1024
#define MAX_ELEMENT_BUFFER 128 * 1024

namespace nb = nanobind;
using namespace nanobind::literals;


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

    void CreateWindow(int widthps, int heightps, const char* title, bool decorated) {
        if (window)
            throw std::runtime_error("Window already exists");

        glfwWindowHint(GLFW_DECORATED, decorated);
        

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

};

struct nk_image LoadSVGImage(const char* filename, int width, int height) {
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


    struct nk_image img = nk_image_id((int)tex);
    img.w = width;
    img.h = height;
    return img;
}
/*
struct nk_image LoadPNGImage(const char* filename) {
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

    struct nk_image img = nk_image_id((int)tex);
    img.w = ihdr.width;
    img.h = ihdr.height;
    return img;
}*/

/*struct nk_image TransformImage(struct nk_image image, int w, int h, struct nk_rect crop) {
    GLuint sourceTex;

    if (w != image.w || h != image.h) {
        GLuint dstResTex;
        glGenTextures(1, &dstResTex);
        glBindTexture(GL_TEXTURE_2D, dstResTex);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        GLuint srcResFbo, dstResFbo;
        glGenFramebuffers(1, &srcResFbo);
        glGenFramebuffers(1, &dstResFbo);

        glBindFramebuffer(GL_READ_FRAMEBUFFER, srcResFbo);
        glFramebufferTexture2D(GL_READ_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, image.handle.id, 0);

        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, dstResFbo);
        glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, dstResTex, 0);


        glBlitFramebuffer(
            0, 0, image.w, image.h,
            0, 0, w, h,
            GL_COLOR_BUFFER_BIT,
            GL_LINEAR   
        );

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glDeleteFramebuffers(1, &srcResFbo);
        glDeleteFramebuffers(1, &dstResFbo);

        sourceTex = dstResTex;

    }
    else {
        sourceTex = image.handle.id;
    }



    GLuint dstTex;
    glGenTextures(1, &dstTex);
    glBindTexture(GL_TEXTURE_2D, dstTex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, crop.w, crop.h, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    GLuint srcFbo, dstFbo;
    glGenFramebuffers(1, &srcFbo);
    glGenFramebuffers(1, &dstFbo);

    
    glBindFramebuffer(GL_READ_FRAMEBUFFER, srcFbo);
    glFramebufferTexture2D(GL_READ_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, sourceTex, 0);


    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, dstFbo);
    glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, dstTex, 0);

    int y,x;
    if (w != image.w || h != image.h) {
        x = w/2 + crop.x - crop.w/2;
        y = h/2 - crop.y - crop.h/2;  
    }
    else {
        x = image.w/2 + crop.x - crop.w/2;
        y = image.h/2 - crop.y - crop.h/2;  
    } 

 
    glBlitFramebuffer(
        x, y, x + crop.w, y + crop.h,   
        0, 0, crop.w, crop.h,           
        GL_COLOR_BUFFER_BIT,
        GL_NEAREST
    );


    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glDeleteFramebuffers(1, &srcFbo);
    glDeleteFramebuffers(1, &dstFbo);


    return nk_image_id((int)dstTex);
}*/



NB_MODULE(NPWayland, m) {
    auto bk = nb::class_<Backend>(m, "Window");
        bk.def(nb::init<>());
        bk.def("GLFWInit", &Backend::GLFWInit);
        bk.def("CreateWindow", &Backend::CreateWindow,"w"_a,"h"_a,"title"_a,"decorated"_a);
        bk.def("GetNKContext", &Backend::GetNKContext);
        bk.def("NewFrame", &Backend::NewFrame);
        bk.def("Render", &Backend::Render);
        bk.def("PollEvents", &Backend::PollEvents);
        bk.def("WaitEvents", &Backend::WaitEvents);
        bk.def("ShouldClose", &Backend::ShouldClose);
        bk.def("SetShouldClose", &Backend::SetShouldClose);
        bk.def("GetWindowSize", &Backend::GetWindowSize);
        bk.def("Shutdown", &Backend::Shutdown);
        bk.def("InitFont", &Backend::InitFont,"customFont"_a,"path"_a,"bold"_a);

    //m.def("TransformImage", &TransformImage,"image"_a,"w"_a,"h"_a,"crop"_a);
    m.def("LoadSVGImage", &LoadSVGImage,"path"_a,"w"_a,"h"_a);
    //m.def("LoadPNGImage", &LoadPNGImage,"path"_a);
}


