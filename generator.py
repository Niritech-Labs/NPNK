from NLUtils.TextUtils import GigaRE
from handleFunctions import *
gre = GigaRE(True)
file = ''
with open('nuklear_pp.h','r') as f:
    file = f.read()
fl = []
enums = gre.FindAndWrap(file,EnumsRE,Enums,None)
fl.append('\n'.join(enums))

structBlacklist = ['nk_allocator','nk_command_custom']
structsPre = gre.FindAndWrap(file,PredefStructsRE,PredefStructs,wrapSkeleton=None,blacklist=structBlacklist,flags=re.MULTILINE | re.DOTALL)
fl.append('\n'.join(structsPre))
structs = gre.FindAndWrap(file,StructsRE,Structs,None,blacklist=structBlacklist,flags=re.MULTILINE | re.DOTALL)
fl.append('\n'.join(structs))
methodBlacklist = ['nk_command_custom','nk_allocator','nk_strto','nk_color_hex_rgb','nk_utf','nk_edit_string','nk_combo(','nk_combobox(']
methods = gre.FindAndWrap(file,MethodsRE,Methods,None,blacklist=methodBlacklist,flags=0)
fl.append('\n'.join(methods))

inner = '''
//Copyright (C) 2024-2026 Niritech Labs
//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_BOOL
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_COMMAND_USERDATA
#define NK_UINT_DRAW_INDEX

#include <nanobind/nanobind.h>
#include <stdint.h>
#include <algorithm>           
#include <type_traits>   
#include <nuklear.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/tuple.h>

namespace nb = nanobind;

template <typename Ret, typename... Args>
auto as_capsule(Ret (*func)(Args...)) {
    return [func](Args... args) {
        return nb::capsule((void*)func(args...));
    };
}


NB_MODULE(npnuklear, m) {
    m.doc() = "Niritech Labs port Nuklear to python with nanobind"; 
'''
outer = """
// NOT AUTOMATIC REALIZATION

using namespace nanobind::literals;
    m.def("nk_combobox", [](nk_context* ctx, std::vector<std::string> items, int selected, int item_height, struct nk_vec2 size) {
        std::vector<const char*> ptrs;
        for (const auto& s : items) ptrs.push_back(s.c_str());
        nk_combobox(ctx, ptrs.data(), (int)ptrs.size(), &selected, item_height, size);
        return selected; 
    });


    m.def("nk_combo", [](nk_context* ctx, std::vector<std::string> items, int selected, int item_height, struct nk_vec2 size) {
        std::vector<const char*> ptrs;
        for (const auto& s : items) ptrs.push_back(s.c_str());
        return nk_combo(ctx, ptrs.data(), (int)ptrs.size(), selected, item_height, size);
    });

    m.def("nk_edit_string_zero_terminated", [](nk_context* ctx, nk_flags flags, std::string buffer, int max, nk_plugin_filter filter) {
        buffer.resize(max); 
        nk_flags res = nk_edit_string_zero_terminated(ctx, flags, buffer.data(), max, filter);
    
    
        buffer.resize(strlen(buffer.c_str())); 
        return std::make_tuple(res, buffer);
    }, "ctx"_a, "flags"_a, "buffer"_a, "max"_a, "filter"_a = nullptr);

    m.def("nk_edit_string", [](nk_context* ctx, nk_flags flags, std::string buffer, int max, nk_plugin_filter filter) {
        buffer.resize(max);
        int current_len = (int)strlen(buffer.c_str()); // Или передавать len из Python
    
        nk_flags res = nk_edit_string(ctx, flags, buffer.data(), &current_len, max, filter);

        buffer.resize(current_len);
        return std::make_tuple(res, buffer);
    }, "ctx"_a, "flags"_a, "buffer"_a, "max"_a, "filter"_a = nullptr);



 
}
"""


body = '\n'.join(fl)
res = inner + body + outer

with open('bindings/np_nuklear.cpp','w') as f:
    f.write(res)

