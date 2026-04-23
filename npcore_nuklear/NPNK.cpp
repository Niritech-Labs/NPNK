
//Copyright (C) 2026 Niritech Labs
//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

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


#include <nanobind/nanobind.h>
#include <stdint.h>
#include <algorithm>           
#include <type_traits>   
#include "../nuklear/nuklear.h"
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/tuple.h>
#include <unordered_map>

namespace nb = nanobind;
using namespace nanobind::literals;

template <typename Ret, typename... Args>
auto as_capsule(Ret (*func)(Args...)) {
    return [func](Args... args) {
        return nb::capsule((void*)func(args...));
    };
}

namespace {
    thread_local std::unordered_map<const void*, nb::callable> filter_map;

    nk_bool filter_trampoline(const nk_text_edit* edit, nk_rune unicode) {
        auto it = filter_map.find(static_cast<const void*>(edit));
        if (it != filter_map.end())
            return nb::cast<bool>(it->second(edit, unicode));
        return nk_true;  
    }

    float plot_value_getter_trampoline(void* user, int index) {
        return nb::cast<float>((*static_cast<nb::callable*>(user))(user, index));
    }

    void combo_item_getter_trampoline(void* user, int index, const char** item) {
        static thread_local std::string result;
        result = nb::cast<std::string>((*static_cast<nb::callable*>(user))(user, index));
        *item = result.c_str();
    }
}

NB_MODULE(Nuklear, m) {
    m.doc() = "Niritech Labs port Nuklear to python with nanobind"; 
    nb::enum_<enum nk_heading>(m, "nk_heading")
        .value("NK_UP", NK_UP)
        .value("NK_RIGHT", NK_RIGHT)
        .value("NK_DOWN", NK_DOWN)
        .value("NK_LEFT", NK_LEFT)
        .export_values();

    nb::enum_<enum nk_button_behavior>(m, "nk_button_behavior")
        .value("NK_BUTTON_DEFAULT", NK_BUTTON_DEFAULT)
        .value("NK_BUTTON_REPEATER", NK_BUTTON_REPEATER)
        .export_values();

    nb::enum_<enum nk_modify>(m, "nk_modify", nb::is_flag())
        .value("NK_FIXED", NK_FIXED)
        .value("NK_MODIFIABLE", NK_MODIFIABLE)
        .export_values();

    nb::enum_<enum nk_orientation>(m, "nk_orientation")
        .value("NK_VERTICAL", NK_VERTICAL)
        .value("NK_HORIZONTAL", NK_HORIZONTAL)
        .export_values();

    nb::enum_<enum nk_collapse_states>(m, "nk_collapse_states", nb::is_flag())
        .value("NK_MINIMIZED", NK_MINIMIZED)
        .value("NK_MAXIMIZED", NK_MAXIMIZED)
        .export_values();

    nb::enum_<enum nk_show_states>(m, "nk_show_states", nb::is_flag())
        .value("NK_HIDDEN", NK_HIDDEN)
        .value("NK_SHOWN", NK_SHOWN)
        .export_values();

    nb::enum_<enum nk_chart_type>(m, "nk_chart_type")
        .value("NK_CHART_LINES", NK_CHART_LINES)
        .value("NK_CHART_COLUMN", NK_CHART_COLUMN)
        .value("NK_CHART_MAX", NK_CHART_MAX)
        .export_values();

    nb::enum_<enum nk_chart_event>(m, "nk_chart_event", nb::is_flag())
        .value("NK_CHART_HOVERING", NK_CHART_HOVERING)
        .value("NK_CHART_CLICKED", NK_CHART_CLICKED)
        .export_values();

    nb::enum_<enum nk_color_format>(m, "nk_color_format")
        .value("NK_RGB", NK_RGB)
        .value("NK_RGBA", NK_RGBA)
        .export_values();

    nb::enum_<enum nk_popup_type>(m, "nk_popup_type")
        .value("NK_POPUP_STATIC", NK_POPUP_STATIC)
        .value("NK_POPUP_DYNAMIC", NK_POPUP_DYNAMIC)
        .export_values();

    nb::enum_<enum nk_layout_format>(m, "nk_layout_format")
        .value("NK_DYNAMIC", NK_DYNAMIC)
        .value("NK_STATIC", NK_STATIC)
        .export_values();

    nb::enum_<enum nk_tree_type>(m, "nk_tree_type")
        .value("NK_TREE_NODE", NK_TREE_NODE)
        .value("NK_TREE_TAB", NK_TREE_TAB)
        .export_values();

    nb::enum_<enum nk_tooltip_pos>(m, "nk_tooltip_pos")
        .value("NK_TOP_LEFT", NK_TOP_LEFT)
        .value("NK_TOP_CENTER", NK_TOP_CENTER)
        .value("NK_TOP_RIGHT", NK_TOP_RIGHT)
        .value("NK_MIDDLE_LEFT", NK_MIDDLE_LEFT)
        .value("NK_MIDDLE_CENTER", NK_MIDDLE_CENTER)
        .value("NK_MIDDLE_RIGHT", NK_MIDDLE_RIGHT)
        .value("NK_BOTTOM_LEFT", NK_BOTTOM_LEFT)
        .value("NK_BOTTOM_CENTER", NK_BOTTOM_CENTER)
        .value("NK_BOTTOM_RIGHT", NK_BOTTOM_RIGHT)
        .export_values();

    nb::enum_<enum nk_symbol_type>(m, "nk_symbol_type")
        .value("NK_SYMBOL_NONE", NK_SYMBOL_NONE)
        .value("NK_SYMBOL_X", NK_SYMBOL_X)
        .value("NK_SYMBOL_UNDERSCORE", NK_SYMBOL_UNDERSCORE)
        .value("NK_SYMBOL_CIRCLE_SOLID", NK_SYMBOL_CIRCLE_SOLID)
        .value("NK_SYMBOL_CIRCLE_OUTLINE", NK_SYMBOL_CIRCLE_OUTLINE)
        .value("NK_SYMBOL_RECT_SOLID", NK_SYMBOL_RECT_SOLID)
        .value("NK_SYMBOL_RECT_OUTLINE", NK_SYMBOL_RECT_OUTLINE)
        .value("NK_SYMBOL_TRIANGLE_UP", NK_SYMBOL_TRIANGLE_UP)
        .value("NK_SYMBOL_TRIANGLE_DOWN", NK_SYMBOL_TRIANGLE_DOWN)
        .value("NK_SYMBOL_TRIANGLE_LEFT", NK_SYMBOL_TRIANGLE_LEFT)
        .value("NK_SYMBOL_TRIANGLE_RIGHT", NK_SYMBOL_TRIANGLE_RIGHT)
        .value("NK_SYMBOL_PLUS", NK_SYMBOL_PLUS)
        .value("NK_SYMBOL_MINUS", NK_SYMBOL_MINUS)
        .value("NK_SYMBOL_TRIANGLE_UP_OUTLINE", NK_SYMBOL_TRIANGLE_UP_OUTLINE)
        .value("NK_SYMBOL_TRIANGLE_DOWN_OUTLINE", NK_SYMBOL_TRIANGLE_DOWN_OUTLINE)
        .value("NK_SYMBOL_TRIANGLE_LEFT_OUTLINE", NK_SYMBOL_TRIANGLE_LEFT_OUTLINE)
        .value("NK_SYMBOL_TRIANGLE_RIGHT_OUTLINE", NK_SYMBOL_TRIANGLE_RIGHT_OUTLINE)
        .value("NK_SYMBOL_MAX", NK_SYMBOL_MAX)
        .export_values();

    nb::enum_<enum nk_keys>(m, "nk_keys")
        .value("NK_KEY_NONE", NK_KEY_NONE)
        .value("NK_KEY_SHIFT", NK_KEY_SHIFT)
        .value("NK_KEY_CTRL", NK_KEY_CTRL)
        .value("NK_KEY_DEL", NK_KEY_DEL)
        .value("NK_KEY_ENTER", NK_KEY_ENTER)
        .value("NK_KEY_TAB", NK_KEY_TAB)
        .value("NK_KEY_BACKSPACE", NK_KEY_BACKSPACE)
        .value("NK_KEY_COPY", NK_KEY_COPY)
        .value("NK_KEY_CUT", NK_KEY_CUT)
        .value("NK_KEY_PASTE", NK_KEY_PASTE)
        .value("NK_KEY_UP", NK_KEY_UP)
        .value("NK_KEY_DOWN", NK_KEY_DOWN)
        .value("NK_KEY_LEFT", NK_KEY_LEFT)
        .value("NK_KEY_RIGHT", NK_KEY_RIGHT)
        .value("NK_KEY_TEXT_INSERT_MODE", NK_KEY_TEXT_INSERT_MODE)
        .value("NK_KEY_TEXT_REPLACE_MODE", NK_KEY_TEXT_REPLACE_MODE)
        .value("NK_KEY_TEXT_RESET_MODE", NK_KEY_TEXT_RESET_MODE)
        .value("NK_KEY_TEXT_LINE_START", NK_KEY_TEXT_LINE_START)
        .value("NK_KEY_TEXT_LINE_END", NK_KEY_TEXT_LINE_END)
        .value("NK_KEY_TEXT_START", NK_KEY_TEXT_START)
        .value("NK_KEY_TEXT_END", NK_KEY_TEXT_END)
        .value("NK_KEY_TEXT_UNDO", NK_KEY_TEXT_UNDO)
        .value("NK_KEY_TEXT_REDO", NK_KEY_TEXT_REDO)
        .value("NK_KEY_TEXT_SELECT_ALL", NK_KEY_TEXT_SELECT_ALL)
        .value("NK_KEY_TEXT_WORD_LEFT", NK_KEY_TEXT_WORD_LEFT)
        .value("NK_KEY_TEXT_WORD_RIGHT", NK_KEY_TEXT_WORD_RIGHT)
        .value("NK_KEY_SCROLL_START", NK_KEY_SCROLL_START)
        .value("NK_KEY_SCROLL_END", NK_KEY_SCROLL_END)
        .value("NK_KEY_SCROLL_DOWN", NK_KEY_SCROLL_DOWN)
        .value("NK_KEY_SCROLL_UP", NK_KEY_SCROLL_UP)
        .value("NK_KEY_MAX", NK_KEY_MAX)
        .export_values();

    nb::enum_<enum nk_buttons>(m, "nk_buttons")
        .value("NK_BUTTON_LEFT", NK_BUTTON_LEFT)
        .value("NK_BUTTON_MIDDLE", NK_BUTTON_MIDDLE)
        .value("NK_BUTTON_RIGHT", NK_BUTTON_RIGHT)
        .value("NK_BUTTON_DOUBLE", NK_BUTTON_DOUBLE)
        .value("NK_BUTTON_MAX", NK_BUTTON_MAX)
        .export_values();

    nb::enum_<enum nk_anti_aliasing>(m, "nk_anti_aliasing")
        .value("NK_ANTI_ALIASING_OFF", NK_ANTI_ALIASING_OFF)
        .value("NK_ANTI_ALIASING_ON", NK_ANTI_ALIASING_ON)
        .export_values();

    nb::enum_<enum nk_convert_result>(m, "nk_convert_result", nb::is_flag())
        .value("NK_CONVERT_SUCCESS", NK_CONVERT_SUCCESS)
        .value("NK_CONVERT_INVALID_PARAM", NK_CONVERT_INVALID_PARAM)
        .value("NK_CONVERT_COMMAND_BUFFER_FULL", NK_CONVERT_COMMAND_BUFFER_FULL)
        .value("NK_CONVERT_VERTEX_BUFFER_FULL", NK_CONVERT_VERTEX_BUFFER_FULL)
        .value("NK_CONVERT_ELEMENT_BUFFER_FULL", NK_CONVERT_ELEMENT_BUFFER_FULL)
        .export_values();

    nb::enum_<enum nk_panel_flags>(m, "nk_panel_flags", nb::is_flag())
        .value("NK_WINDOW_BORDER", NK_WINDOW_BORDER)
        .value("NK_WINDOW_MOVABLE", NK_WINDOW_MOVABLE)
        .value("NK_WINDOW_SCALABLE", NK_WINDOW_SCALABLE)
        .value("NK_WINDOW_CLOSABLE", NK_WINDOW_CLOSABLE)
        .value("NK_WINDOW_MINIMIZABLE", NK_WINDOW_MINIMIZABLE)
        .value("NK_WINDOW_NO_SCROLLBAR", NK_WINDOW_NO_SCROLLBAR)
        .value("NK_WINDOW_TITLE", NK_WINDOW_TITLE)
        .value("NK_WINDOW_SCROLL_AUTO_HIDE", NK_WINDOW_SCROLL_AUTO_HIDE)
        .value("NK_WINDOW_BACKGROUND", NK_WINDOW_BACKGROUND)
        .value("NK_WINDOW_SCALE_LEFT", NK_WINDOW_SCALE_LEFT)
        .value("NK_WINDOW_NO_INPUT", NK_WINDOW_NO_INPUT)
        .export_values();

    nb::enum_<enum nk_widget_align>(m, "nk_widget_align", nb::is_flag())
        .value("NK_WIDGET_ALIGN_LEFT", NK_WIDGET_ALIGN_LEFT)
        .value("NK_WIDGET_ALIGN_CENTERED", NK_WIDGET_ALIGN_CENTERED)
        .value("NK_WIDGET_ALIGN_RIGHT", NK_WIDGET_ALIGN_RIGHT)
        .value("NK_WIDGET_ALIGN_TOP", NK_WIDGET_ALIGN_TOP)
        .value("NK_WIDGET_ALIGN_MIDDLE", NK_WIDGET_ALIGN_MIDDLE)
        .value("NK_WIDGET_ALIGN_BOTTOM", NK_WIDGET_ALIGN_BOTTOM)
        .export_values();

    nb::enum_<enum nk_widget_alignment>(m, "nk_widget_alignment", nb::is_flag())
        .value("NK_WIDGET_LEFT", NK_WIDGET_LEFT)
        .value("NK_WIDGET_CENTERED", NK_WIDGET_CENTERED)
        .value("NK_WIDGET_RIGHT", NK_WIDGET_RIGHT)
        .export_values();

    nb::enum_<enum nk_widget_layout_states>(m, "nk_widget_layout_states")
        .value("NK_WIDGET_INVALID", NK_WIDGET_INVALID)
        .value("NK_WIDGET_VALID", NK_WIDGET_VALID)
        .value("NK_WIDGET_ROM", NK_WIDGET_ROM)
        .value("NK_WIDGET_DISABLED", NK_WIDGET_DISABLED)
        .export_values();

    nb::enum_<enum nk_widget_states>(m, "nk_widget_states", nb::is_flag())
        .value("NK_WIDGET_STATE_MODIFIED", NK_WIDGET_STATE_MODIFIED)
        .value("NK_WIDGET_STATE_INACTIVE", NK_WIDGET_STATE_INACTIVE)
        .value("NK_WIDGET_STATE_ENTERED", NK_WIDGET_STATE_ENTERED)
        .value("NK_WIDGET_STATE_HOVER", NK_WIDGET_STATE_HOVER)
        .value("NK_WIDGET_STATE_ACTIVED", NK_WIDGET_STATE_ACTIVED)
        .value("NK_WIDGET_STATE_LEFT", NK_WIDGET_STATE_LEFT)
        .value("NK_WIDGET_STATE_HOVERED", NK_WIDGET_STATE_HOVERED)
        .value("NK_WIDGET_STATE_ACTIVE", NK_WIDGET_STATE_ACTIVE)
        .export_values();

    nb::enum_<enum nk_text_align>(m, "nk_text_align", nb::is_flag())
        .value("NK_TEXT_ALIGN_LEFT", NK_TEXT_ALIGN_LEFT)
        .value("NK_TEXT_ALIGN_CENTERED", NK_TEXT_ALIGN_CENTERED)
        .value("NK_TEXT_ALIGN_RIGHT", NK_TEXT_ALIGN_RIGHT)
        .value("NK_TEXT_ALIGN_TOP", NK_TEXT_ALIGN_TOP)
        .value("NK_TEXT_ALIGN_MIDDLE", NK_TEXT_ALIGN_MIDDLE)
        .value("NK_TEXT_ALIGN_BOTTOM", NK_TEXT_ALIGN_BOTTOM)
        .export_values();

    nb::enum_<enum nk_text_alignment>(m, "nk_text_alignment", nb::is_flag())
        .value("NK_TEXT_LEFT", NK_TEXT_LEFT)
        .value("NK_TEXT_CENTERED", NK_TEXT_CENTERED)
        .value("NK_TEXT_RIGHT", NK_TEXT_RIGHT)
        .export_values();

    nb::enum_<enum nk_edit_flags>(m, "nk_edit_flags", nb::is_flag())
        .value("NK_EDIT_DEFAULT", NK_EDIT_DEFAULT)
        .value("NK_EDIT_READ_ONLY", NK_EDIT_READ_ONLY)
        .value("NK_EDIT_AUTO_SELECT", NK_EDIT_AUTO_SELECT)
        .value("NK_EDIT_SIG_ENTER", NK_EDIT_SIG_ENTER)
        .value("NK_EDIT_ALLOW_TAB", NK_EDIT_ALLOW_TAB)
        .value("NK_EDIT_NO_CURSOR", NK_EDIT_NO_CURSOR)
        .value("NK_EDIT_SELECTABLE", NK_EDIT_SELECTABLE)
        .value("NK_EDIT_CLIPBOARD", NK_EDIT_CLIPBOARD)
        .value("NK_EDIT_CTRL_ENTER_NEWLINE", NK_EDIT_CTRL_ENTER_NEWLINE)
        .value("NK_EDIT_NO_HORIZONTAL_SCROLL", NK_EDIT_NO_HORIZONTAL_SCROLL)
        .value("NK_EDIT_ALWAYS_INSERT_MODE", NK_EDIT_ALWAYS_INSERT_MODE)
        .value("NK_EDIT_MULTILINE", NK_EDIT_MULTILINE)
        .value("NK_EDIT_GOTO_END_ON_ACTIVATE", NK_EDIT_GOTO_END_ON_ACTIVATE)
        .export_values();

    nb::enum_<enum nk_edit_types>(m, "nk_edit_types", nb::is_flag())
        .value("NK_EDIT_SIMPLE", NK_EDIT_SIMPLE)
        .value("NK_EDIT_FIELD", NK_EDIT_FIELD)
        .value("NK_EDIT_BOX", NK_EDIT_BOX)
        .value("NK_EDIT_EDITOR", NK_EDIT_EDITOR)
        .export_values();

    nb::enum_<enum nk_edit_events>(m, "nk_edit_events", nb::is_flag())
        .value("NK_EDIT_ACTIVE", NK_EDIT_ACTIVE)
        .value("NK_EDIT_INACTIVE", NK_EDIT_INACTIVE)
        .value("NK_EDIT_ACTIVATED", NK_EDIT_ACTIVATED)
        .value("NK_EDIT_DEACTIVATED", NK_EDIT_DEACTIVATED)
        .value("NK_EDIT_COMMITED", NK_EDIT_COMMITED)
        .export_values();

    nb::enum_<enum nk_style_colors>(m, "nk_style_colors")
        .value("NK_COLOR_TEXT", NK_COLOR_TEXT)
        .value("NK_COLOR_WINDOW", NK_COLOR_WINDOW)
        .value("NK_COLOR_HEADER", NK_COLOR_HEADER)
        .value("NK_COLOR_BORDER", NK_COLOR_BORDER)
        .value("NK_COLOR_BUTTON", NK_COLOR_BUTTON)
        .value("NK_COLOR_BUTTON_HOVER", NK_COLOR_BUTTON_HOVER)
        .value("NK_COLOR_BUTTON_ACTIVE", NK_COLOR_BUTTON_ACTIVE)
        .value("NK_COLOR_TOGGLE", NK_COLOR_TOGGLE)
        .value("NK_COLOR_TOGGLE_HOVER", NK_COLOR_TOGGLE_HOVER)
        .value("NK_COLOR_TOGGLE_CURSOR", NK_COLOR_TOGGLE_CURSOR)
        .value("NK_COLOR_SELECT", NK_COLOR_SELECT)
        .value("NK_COLOR_SELECT_ACTIVE", NK_COLOR_SELECT_ACTIVE)
        .value("NK_COLOR_SLIDER", NK_COLOR_SLIDER)
        .value("NK_COLOR_SLIDER_CURSOR", NK_COLOR_SLIDER_CURSOR)
        .value("NK_COLOR_SLIDER_CURSOR_HOVER", NK_COLOR_SLIDER_CURSOR_HOVER)
        .value("NK_COLOR_SLIDER_CURSOR_ACTIVE", NK_COLOR_SLIDER_CURSOR_ACTIVE)
        .value("NK_COLOR_PROPERTY", NK_COLOR_PROPERTY)
        .value("NK_COLOR_EDIT", NK_COLOR_EDIT)
        .value("NK_COLOR_EDIT_CURSOR", NK_COLOR_EDIT_CURSOR)
        .value("NK_COLOR_COMBO", NK_COLOR_COMBO)
        .value("NK_COLOR_CHART", NK_COLOR_CHART)
        .value("NK_COLOR_CHART_COLOR", NK_COLOR_CHART_COLOR)
        .value("NK_COLOR_CHART_COLOR_HIGHLIGHT", NK_COLOR_CHART_COLOR_HIGHLIGHT)
        .value("NK_COLOR_SCROLLBAR", NK_COLOR_SCROLLBAR)
        .value("NK_COLOR_SCROLLBAR_CURSOR", NK_COLOR_SCROLLBAR_CURSOR)
        .value("NK_COLOR_SCROLLBAR_CURSOR_HOVER", NK_COLOR_SCROLLBAR_CURSOR_HOVER)
        .value("NK_COLOR_SCROLLBAR_CURSOR_ACTIVE", NK_COLOR_SCROLLBAR_CURSOR_ACTIVE)
        .value("NK_COLOR_TAB_HEADER", NK_COLOR_TAB_HEADER)
        .value("NK_COLOR_KNOB", NK_COLOR_KNOB)
        .value("NK_COLOR_KNOB_CURSOR", NK_COLOR_KNOB_CURSOR)
        .value("NK_COLOR_KNOB_CURSOR_HOVER", NK_COLOR_KNOB_CURSOR_HOVER)
        .value("NK_COLOR_KNOB_CURSOR_ACTIVE", NK_COLOR_KNOB_CURSOR_ACTIVE)
        .value("NK_COLOR_COUNT", NK_COLOR_COUNT)
        .export_values();

    nb::enum_<enum nk_style_cursor>(m, "nk_style_cursor")
        .value("NK_CURSOR_ARROW", NK_CURSOR_ARROW)
        .value("NK_CURSOR_TEXT", NK_CURSOR_TEXT)
        .value("NK_CURSOR_MOVE", NK_CURSOR_MOVE)
        .value("NK_CURSOR_RESIZE_VERTICAL", NK_CURSOR_RESIZE_VERTICAL)
        .value("NK_CURSOR_RESIZE_HORIZONTAL", NK_CURSOR_RESIZE_HORIZONTAL)
        .value("NK_CURSOR_RESIZE_TOP_LEFT_DOWN_RIGHT", NK_CURSOR_RESIZE_TOP_LEFT_DOWN_RIGHT)
        .value("NK_CURSOR_RESIZE_TOP_RIGHT_DOWN_LEFT", NK_CURSOR_RESIZE_TOP_RIGHT_DOWN_LEFT)
        .value("NK_CURSOR_COUNT", NK_CURSOR_COUNT)
        .export_values();

    nb::enum_<enum nk_font_coord_type>(m, "nk_font_coord_type")
        .value("NK_COORD_UV", NK_COORD_UV)
        .value("NK_COORD_PIXEL", NK_COORD_PIXEL)
        .export_values();

    nb::enum_<enum nk_font_atlas_format>(m, "nk_font_atlas_format")
        .value("NK_FONT_ATLAS_ALPHA8", NK_FONT_ATLAS_ALPHA8)
        .value("NK_FONT_ATLAS_RGBA32", NK_FONT_ATLAS_RGBA32)
        .export_values();

    nb::enum_<enum nk_allocation_type>(m, "nk_allocation_type")
        .value("NK_BUFFER_FIXED", NK_BUFFER_FIXED)
        .value("NK_BUFFER_DYNAMIC", NK_BUFFER_DYNAMIC)
        .export_values();

    nb::enum_<enum nk_buffer_allocation_type>(m, "nk_buffer_allocation_type")
        .value("NK_BUFFER_FRONT", NK_BUFFER_FRONT)
        .value("NK_BUFFER_BACK", NK_BUFFER_BACK)
        .value("NK_BUFFER_MAX", NK_BUFFER_MAX)
        .export_values();

    nb::enum_<enum nk_text_edit_type>(m, "nk_text_edit_type")
        .value("NK_TEXT_EDIT_SINGLE_LINE", NK_TEXT_EDIT_SINGLE_LINE)
        .value("NK_TEXT_EDIT_MULTI_LINE", NK_TEXT_EDIT_MULTI_LINE)
        .export_values();

    nb::enum_<enum nk_text_edit_mode>(m, "nk_text_edit_mode")
        .value("NK_TEXT_EDIT_MODE_VIEW", NK_TEXT_EDIT_MODE_VIEW)
        .value("NK_TEXT_EDIT_MODE_INSERT", NK_TEXT_EDIT_MODE_INSERT)
        .value("NK_TEXT_EDIT_MODE_REPLACE", NK_TEXT_EDIT_MODE_REPLACE)
        .export_values();

    nb::enum_<enum nk_command_type>(m, "nk_command_type")
        .value("NK_COMMAND_NOP", NK_COMMAND_NOP)
        .value("NK_COMMAND_SCISSOR", NK_COMMAND_SCISSOR)
        .value("NK_COMMAND_LINE", NK_COMMAND_LINE)
        .value("NK_COMMAND_CURVE", NK_COMMAND_CURVE)
        .value("NK_COMMAND_RECT", NK_COMMAND_RECT)
        .value("NK_COMMAND_RECT_FILLED", NK_COMMAND_RECT_FILLED)
        .value("NK_COMMAND_RECT_MULTI_COLOR", NK_COMMAND_RECT_MULTI_COLOR)
        .value("NK_COMMAND_CIRCLE", NK_COMMAND_CIRCLE)
        .value("NK_COMMAND_CIRCLE_FILLED", NK_COMMAND_CIRCLE_FILLED)
        .value("NK_COMMAND_ARC", NK_COMMAND_ARC)
        .value("NK_COMMAND_ARC_FILLED", NK_COMMAND_ARC_FILLED)
        .value("NK_COMMAND_TRIANGLE", NK_COMMAND_TRIANGLE)
        .value("NK_COMMAND_TRIANGLE_FILLED", NK_COMMAND_TRIANGLE_FILLED)
        .value("NK_COMMAND_POLYGON", NK_COMMAND_POLYGON)
        .value("NK_COMMAND_POLYGON_FILLED", NK_COMMAND_POLYGON_FILLED)
        .value("NK_COMMAND_POLYLINE", NK_COMMAND_POLYLINE)
        .value("NK_COMMAND_TEXT", NK_COMMAND_TEXT)
        .value("NK_COMMAND_IMAGE", NK_COMMAND_IMAGE)
        .value("NK_COMMAND_CUSTOM", NK_COMMAND_CUSTOM)
        .export_values();

    nb::enum_<enum nk_command_clipping>(m, "nk_command_clipping", nb::is_flag())
        .value("NK_CLIPPING_OFF", NK_CLIPPING_OFF)
        .value("NK_CLIPPING_ON", NK_CLIPPING_ON)
        .export_values();

    nb::enum_<enum nk_draw_list_stroke>(m, "nk_draw_list_stroke", nb::is_flag())
        .value("NK_STROKE_OPEN", NK_STROKE_OPEN)
        .value("NK_STROKE_CLOSED", NK_STROKE_CLOSED)
        .export_values();

    nb::enum_<enum nk_draw_vertex_layout_attribute>(m, "nk_draw_vertex_layout_attribute")
        .value("NK_VERTEX_POSITION", NK_VERTEX_POSITION)
        .value("NK_VERTEX_COLOR", NK_VERTEX_COLOR)
        .value("NK_VERTEX_TEXCOORD", NK_VERTEX_TEXCOORD)
        .value("NK_VERTEX_ATTRIBUTE_COUNT", NK_VERTEX_ATTRIBUTE_COUNT)
        .export_values();

    nb::enum_<enum nk_draw_vertex_layout_format>(m, "nk_draw_vertex_layout_format", nb::is_flag())
        .value("NK_FORMAT_SCHAR", NK_FORMAT_SCHAR)
        .value("NK_FORMAT_SSHORT", NK_FORMAT_SSHORT)
        .value("NK_FORMAT_SINT", NK_FORMAT_SINT)
        .value("NK_FORMAT_UCHAR", NK_FORMAT_UCHAR)
        .value("NK_FORMAT_USHORT", NK_FORMAT_USHORT)
        .value("NK_FORMAT_UINT", NK_FORMAT_UINT)
        .value("NK_FORMAT_FLOAT", NK_FORMAT_FLOAT)
        .value("NK_FORMAT_DOUBLE", NK_FORMAT_DOUBLE)
        .value("NK_FORMAT_COLOR_BEGIN", NK_FORMAT_COLOR_BEGIN)
        .value("NK_FORMAT_R8G8B8", NK_FORMAT_R8G8B8)
        .value("NK_FORMAT_R16G15B16", NK_FORMAT_R16G15B16)
        .value("NK_FORMAT_R32G32B32", NK_FORMAT_R32G32B32)
        .value("NK_FORMAT_R8G8B8A8", NK_FORMAT_R8G8B8A8)
        .value("NK_FORMAT_B8G8R8A8", NK_FORMAT_B8G8R8A8)
        .value("NK_FORMAT_R16G15B16A16", NK_FORMAT_R16G15B16A16)
        .value("NK_FORMAT_R32G32B32A32", NK_FORMAT_R32G32B32A32)
        .value("NK_FORMAT_R32G32B32A32_FLOAT", NK_FORMAT_R32G32B32A32_FLOAT)
        .value("NK_FORMAT_R32G32B32A32_DOUBLE", NK_FORMAT_R32G32B32A32_DOUBLE)
        .value("NK_FORMAT_RGB32", NK_FORMAT_RGB32)
        .value("NK_FORMAT_RGBA32", NK_FORMAT_RGBA32)
        .value("NK_FORMAT_COLOR_END", NK_FORMAT_COLOR_END)
        .value("NK_FORMAT_COUNT", NK_FORMAT_COUNT)
        .export_values();

    nb::enum_<enum nk_style_item_type>(m, "nk_style_item_type")
        .value("NK_STYLE_ITEM_COLOR", NK_STYLE_ITEM_COLOR)
        .value("NK_STYLE_ITEM_IMAGE", NK_STYLE_ITEM_IMAGE)
        .value("NK_STYLE_ITEM_NINE_SLICE", NK_STYLE_ITEM_NINE_SLICE)
        .export_values();

    nb::enum_<enum nk_style_header_align>(m, "nk_style_header_align")
        .value("NK_HEADER_LEFT", NK_HEADER_LEFT)
        .value("NK_HEADER_RIGHT", NK_HEADER_RIGHT)
        .export_values();

    nb::enum_<enum nk_panel_type>(m, "nk_panel_type", nb::is_flag())
        .value("NK_PANEL_NONE", NK_PANEL_NONE)
        .value("NK_PANEL_WINDOW", NK_PANEL_WINDOW)
        .value("NK_PANEL_GROUP", NK_PANEL_GROUP)
        .value("NK_PANEL_POPUP", NK_PANEL_POPUP)
        .value("NK_PANEL_CONTEXTUAL", NK_PANEL_CONTEXTUAL)
        .value("NK_PANEL_COMBO", NK_PANEL_COMBO)
        .value("NK_PANEL_MENU", NK_PANEL_MENU)
        .value("NK_PANEL_TOOLTIP", NK_PANEL_TOOLTIP)
        .export_values();

    nb::enum_<enum nk_panel_set>(m, "nk_panel_set", nb::is_flag())
        .value("NK_PANEL_SET_NONBLOCK", NK_PANEL_SET_NONBLOCK)
        .value("NK_PANEL_SET_POPUP", NK_PANEL_SET_POPUP)
        .value("NK_PANEL_SET_SUB", NK_PANEL_SET_SUB)
        .export_values();

    nb::enum_<enum nk_panel_row_layout_type>(m, "nk_panel_row_layout_type", nb::is_flag())
        .value("NK_LAYOUT_DYNAMIC_FIXED", NK_LAYOUT_DYNAMIC_FIXED)
        .value("NK_LAYOUT_DYNAMIC_ROW", NK_LAYOUT_DYNAMIC_ROW)
        .value("NK_LAYOUT_DYNAMIC_FREE", NK_LAYOUT_DYNAMIC_FREE)
        .value("NK_LAYOUT_DYNAMIC", NK_LAYOUT_DYNAMIC)
        .value("NK_LAYOUT_STATIC_FIXED", NK_LAYOUT_STATIC_FIXED)
        .value("NK_LAYOUT_STATIC_ROW", NK_LAYOUT_STATIC_ROW)
        .value("NK_LAYOUT_STATIC_FREE", NK_LAYOUT_STATIC_FREE)
        .value("NK_LAYOUT_STATIC", NK_LAYOUT_STATIC)
        .value("NK_LAYOUT_TEMPLATE", NK_LAYOUT_TEMPLATE)
        .value("NK_LAYOUT_COUNT", NK_LAYOUT_COUNT)
        .export_values();

    nb::enum_<enum nk_window_flags>(m, "nk_window_flags", nb::is_flag())
        .value("NK_WINDOW_PRIVATE", NK_WINDOW_PRIVATE)
        .value("NK_WINDOW_DYNAMIC", NK_WINDOW_DYNAMIC)
        .value("NK_WINDOW_ROM", NK_WINDOW_ROM)
        .value("NK_WINDOW_NOT_INTERACTIVE", NK_WINDOW_NOT_INTERACTIVE)
        .value("NK_WINDOW_HIDDEN", NK_WINDOW_HIDDEN)
        .value("NK_WINDOW_CLOSED", NK_WINDOW_CLOSED)
        .value("NK_WINDOW_MINIMIZED", NK_WINDOW_MINIMIZED)
        .value("NK_WINDOW_REMOVE_ROM", NK_WINDOW_REMOVE_ROM)
        .export_values();

    auto nk_color_var = nb::class_<struct nk_color>(m, "nk_color");
        nk_color_var.def(nb::init<>());

    auto nk_colorf_var = nb::class_<struct nk_colorf>(m, "nk_colorf");
        nk_colorf_var.def(nb::init<>());

    auto nk_vec2_var = nb::class_<struct nk_vec2>(m, "nk_vec2");
        nk_vec2_var.def(nb::init<>());

    auto nk_vec2i_var = nb::class_<struct nk_vec2i>(m, "nk_vec2i");
        nk_vec2i_var.def(nb::init<>());

    auto nk_rect_var = nb::class_<struct nk_rect>(m, "nk_rect");
        nk_rect_var.def(nb::init<>());

    auto nk_recti_var = nb::class_<struct nk_recti>(m, "nk_recti");
        nk_recti_var.def(nb::init<>());

    auto nk_image_var = nb::class_<struct nk_image>(m, "nk_image");
        nk_image_var.def(nb::init<>());

    auto nk_nine_slice_var = nb::class_<struct nk_nine_slice>(m, "nk_nine_slice");
        nk_nine_slice_var.def(nb::init<>());

    auto nk_cursor_var = nb::class_<struct nk_cursor>(m, "nk_cursor");
        nk_cursor_var.def(nb::init<>());

    auto nk_scroll_var = nb::class_<struct nk_scroll>(m, "nk_scroll");
        nk_scroll_var.def(nb::init<>());

    auto nk_draw_null_texture_var = nb::class_<struct nk_draw_null_texture>(m, "nk_draw_null_texture");
        nk_draw_null_texture_var.def(nb::init<>());

    auto nk_convert_config_var = nb::class_<struct nk_convert_config>(m, "nk_convert_config");
        nk_convert_config_var.def(nb::init<>());

    auto nk_list_view_var = nb::class_<struct nk_list_view>(m, "nk_list_view");
        nk_list_view_var.def(nb::init<>());

    auto nk_user_font_glyph_var = nb::class_<struct nk_user_font_glyph>(m, "nk_user_font_glyph");
        nk_user_font_glyph_var.def(nb::init<>());

    auto nk_user_font_var = nb::class_<struct nk_user_font>(m, "nk_user_font");
        nk_user_font_var.def(nb::init<>());

    auto nk_baked_font_var = nb::class_<struct nk_baked_font>(m, "nk_baked_font");
        nk_baked_font_var.def(nb::init<>());

    auto nk_font_config_var = nb::class_<struct nk_font_config>(m, "nk_font_config");
        nk_font_config_var.def(nb::init<>());

    auto nk_font_glyph_var = nb::class_<struct nk_font_glyph>(m, "nk_font_glyph");
        nk_font_glyph_var.def(nb::init<>());

    auto nk_font_var = nb::class_<struct nk_font>(m, "nk_font");
        nk_font_var.def(nb::init<>());

    auto nk_memory_status_var = nb::class_<struct nk_memory_status>(m, "nk_memory_status");
        nk_memory_status_var.def(nb::init<>());

    auto nk_buffer_marker_var = nb::class_<struct nk_buffer_marker>(m, "nk_buffer_marker");
        nk_buffer_marker_var.def(nb::init<>());

    auto nk_memory_var = nb::class_<struct nk_memory>(m, "nk_memory");
        nk_memory_var.def(nb::init<>());

    auto nk_str_var = nb::class_<struct nk_str>(m, "nk_str");
        nk_str_var.def(nb::init<>());

    auto nk_clipboard_var = nb::class_<struct nk_clipboard>(m, "nk_clipboard");
        nk_clipboard_var.def(nb::init<>());

    auto nk_text_undo_record_var = nb::class_<struct nk_text_undo_record>(m, "nk_text_undo_record");
        nk_text_undo_record_var.def(nb::init<>());

    auto nk_text_undo_state_var = nb::class_<struct nk_text_undo_state>(m, "nk_text_undo_state");
        nk_text_undo_state_var.def(nb::init<>());

    auto nk_text_edit_var = nb::class_<struct nk_text_edit>(m, "nk_text_edit");
        nk_text_edit_var.def(nb::init<>());

    auto nk_command_var = nb::class_<struct nk_command>(m, "nk_command");
        nk_command_var.def(nb::init<>());

    auto nk_command_scissor_var = nb::class_<struct nk_command_scissor>(m, "nk_command_scissor");
        nk_command_scissor_var.def(nb::init<>());

    auto nk_command_line_var = nb::class_<struct nk_command_line>(m, "nk_command_line");
        nk_command_line_var.def(nb::init<>());

    auto nk_command_curve_var = nb::class_<struct nk_command_curve>(m, "nk_command_curve");
        nk_command_curve_var.def(nb::init<>());

    auto nk_command_rect_var = nb::class_<struct nk_command_rect>(m, "nk_command_rect");
        nk_command_rect_var.def(nb::init<>());

    auto nk_command_rect_filled_var = nb::class_<struct nk_command_rect_filled>(m, "nk_command_rect_filled");
        nk_command_rect_filled_var.def(nb::init<>());

    auto nk_command_rect_multi_color_var = nb::class_<struct nk_command_rect_multi_color>(m, "nk_command_rect_multi_color");
        nk_command_rect_multi_color_var.def(nb::init<>());

    auto nk_command_triangle_var = nb::class_<struct nk_command_triangle>(m, "nk_command_triangle");
        nk_command_triangle_var.def(nb::init<>());

    auto nk_command_triangle_filled_var = nb::class_<struct nk_command_triangle_filled>(m, "nk_command_triangle_filled");
        nk_command_triangle_filled_var.def(nb::init<>());

    auto nk_command_circle_var = nb::class_<struct nk_command_circle>(m, "nk_command_circle");
        nk_command_circle_var.def(nb::init<>());

    auto nk_command_circle_filled_var = nb::class_<struct nk_command_circle_filled>(m, "nk_command_circle_filled");
        nk_command_circle_filled_var.def(nb::init<>());

    auto nk_command_arc_var = nb::class_<struct nk_command_arc>(m, "nk_command_arc");
        nk_command_arc_var.def(nb::init<>());

    auto nk_command_arc_filled_var = nb::class_<struct nk_command_arc_filled>(m, "nk_command_arc_filled");
        nk_command_arc_filled_var.def(nb::init<>());

    auto nk_command_polygon_var = nb::class_<struct nk_command_polygon>(m, "nk_command_polygon");
        nk_command_polygon_var.def(nb::init<>());

    auto nk_command_polygon_filled_var = nb::class_<struct nk_command_polygon_filled>(m, "nk_command_polygon_filled");
        nk_command_polygon_filled_var.def(nb::init<>());

    auto nk_command_polyline_var = nb::class_<struct nk_command_polyline>(m, "nk_command_polyline");
        nk_command_polyline_var.def(nb::init<>());

    auto nk_command_image_var = nb::class_<struct nk_command_image>(m, "nk_command_image");
        nk_command_image_var.def(nb::init<>());

    auto nk_command_text_var = nb::class_<struct nk_command_text>(m, "nk_command_text");
        nk_command_text_var.def(nb::init<>());

    auto nk_command_buffer_var = nb::class_<struct nk_command_buffer>(m, "nk_command_buffer");
        nk_command_buffer_var.def(nb::init<>());

    auto nk_mouse_button_var = nb::class_<struct nk_mouse_button>(m, "nk_mouse_button");
        nk_mouse_button_var.def(nb::init<>());

    auto nk_mouse_var = nb::class_<struct nk_mouse>(m, "nk_mouse");
        nk_mouse_var.def(nb::init<>());

    auto nk_key_var = nb::class_<struct nk_key>(m, "nk_key");
        nk_key_var.def(nb::init<>());

    auto nk_keyboard_var = nb::class_<struct nk_keyboard>(m, "nk_keyboard");
        nk_keyboard_var.def(nb::init<>());

    auto nk_input_var = nb::class_<struct nk_input>(m, "nk_input");
        nk_input_var.def(nb::init<>());

    auto nk_draw_vertex_layout_element_var = nb::class_<struct nk_draw_vertex_layout_element>(m, "nk_draw_vertex_layout_element");
        nk_draw_vertex_layout_element_var.def(nb::init<>());

    auto nk_draw_command_var = nb::class_<struct nk_draw_command>(m, "nk_draw_command");
        nk_draw_command_var.def(nb::init<>());

    auto nk_draw_list_var = nb::class_<struct nk_draw_list>(m, "nk_draw_list");
        nk_draw_list_var.def(nb::init<>());

    auto nk_style_item_var = nb::class_<struct nk_style_item>(m, "nk_style_item");
        nk_style_item_var.def(nb::init<>());

    auto nk_style_text_var = nb::class_<struct nk_style_text>(m, "nk_style_text");
        nk_style_text_var.def(nb::init<>());

    auto nk_style_button_var = nb::class_<struct nk_style_button>(m, "nk_style_button");
        nk_style_button_var.def(nb::init<>());

    auto nk_style_toggle_var = nb::class_<struct nk_style_toggle>(m, "nk_style_toggle");
        nk_style_toggle_var.def(nb::init<>());

    auto nk_style_selectable_var = nb::class_<struct nk_style_selectable>(m, "nk_style_selectable");
        nk_style_selectable_var.def(nb::init<>());

    auto nk_style_slider_var = nb::class_<struct nk_style_slider>(m, "nk_style_slider");
        nk_style_slider_var.def(nb::init<>());

    auto nk_style_knob_var = nb::class_<struct nk_style_knob>(m, "nk_style_knob");
        nk_style_knob_var.def(nb::init<>());

    auto nk_style_progress_var = nb::class_<struct nk_style_progress>(m, "nk_style_progress");
        nk_style_progress_var.def(nb::init<>());

    auto nk_style_scrollbar_var = nb::class_<struct nk_style_scrollbar>(m, "nk_style_scrollbar");
        nk_style_scrollbar_var.def(nb::init<>());

    auto nk_style_edit_var = nb::class_<struct nk_style_edit>(m, "nk_style_edit");
        nk_style_edit_var.def(nb::init<>());

    auto nk_style_property_var = nb::class_<struct nk_style_property>(m, "nk_style_property");
        nk_style_property_var.def(nb::init<>());

    auto nk_style_chart_var = nb::class_<struct nk_style_chart>(m, "nk_style_chart");
        nk_style_chart_var.def(nb::init<>());

    auto nk_style_combo_var = nb::class_<struct nk_style_combo>(m, "nk_style_combo");
        nk_style_combo_var.def(nb::init<>());

    auto nk_style_tab_var = nb::class_<struct nk_style_tab>(m, "nk_style_tab");
        nk_style_tab_var.def(nb::init<>());

    auto nk_style_window_header_var = nb::class_<struct nk_style_window_header>(m, "nk_style_window_header");
        nk_style_window_header_var.def(nb::init<>());

    auto nk_style_window_var = nb::class_<struct nk_style_window>(m, "nk_style_window");
        nk_style_window_var.def(nb::init<>());

    auto nk_style_var = nb::class_<struct nk_style>(m, "nk_style");
        nk_style_var.def(nb::init<>());

    auto nk_chart_slot_var = nb::class_<struct nk_chart_slot>(m, "nk_chart_slot");
        nk_chart_slot_var.def(nb::init<>());

    auto nk_chart_var = nb::class_<struct nk_chart>(m, "nk_chart");
        nk_chart_var.def(nb::init<>());

    auto nk_row_layout_var = nb::class_<struct nk_row_layout>(m, "nk_row_layout");
        nk_row_layout_var.def(nb::init<>());

    auto nk_popup_buffer_var = nb::class_<struct nk_popup_buffer>(m, "nk_popup_buffer");
        nk_popup_buffer_var.def(nb::init<>());

    auto nk_menu_state_var = nb::class_<struct nk_menu_state>(m, "nk_menu_state");
        nk_menu_state_var.def(nb::init<>());

    auto nk_panel_var = nb::class_<struct nk_panel>(m, "nk_panel");
        nk_panel_var.def(nb::init<>());

    auto nk_popup_state_var = nb::class_<struct nk_popup_state>(m, "nk_popup_state");
        nk_popup_state_var.def(nb::init<>());

    auto nk_edit_state_var = nb::class_<struct nk_edit_state>(m, "nk_edit_state");
        nk_edit_state_var.def(nb::init<>());

    auto nk_property_state_var = nb::class_<struct nk_property_state>(m, "nk_property_state");
        nk_property_state_var.def(nb::init<>());

    auto nk_window_var = nb::class_<struct nk_window>(m, "nk_window");
        nk_window_var.def(nb::init<>());

    auto nk_config_stack_style_item_element_var = nb::class_<struct nk_config_stack_style_item_element>(m, "nk_config_stack_style_item_element");
        nk_config_stack_style_item_element_var.def(nb::init<>());

    auto nk_config_stack_float_element_var = nb::class_<struct nk_config_stack_float_element>(m, "nk_config_stack_float_element");
        nk_config_stack_float_element_var.def(nb::init<>());

    auto nk_config_stack_vec2_element_var = nb::class_<struct nk_config_stack_vec2_element>(m, "nk_config_stack_vec2_element");
        nk_config_stack_vec2_element_var.def(nb::init<>());

    auto nk_config_stack_flags_element_var = nb::class_<struct nk_config_stack_flags_element>(m, "nk_config_stack_flags_element");
        nk_config_stack_flags_element_var.def(nb::init<>());

    auto nk_config_stack_color_element_var = nb::class_<struct nk_config_stack_color_element>(m, "nk_config_stack_color_element");
        nk_config_stack_color_element_var.def(nb::init<>());

    auto nk_config_stack_user_font_element_var = nb::class_<struct nk_config_stack_user_font_element>(m, "nk_config_stack_user_font_element");
        nk_config_stack_user_font_element_var.def(nb::init<>());

    auto nk_config_stack_button_behavior_element_var = nb::class_<struct nk_config_stack_button_behavior_element>(m, "nk_config_stack_button_behavior_element");
        nk_config_stack_button_behavior_element_var.def(nb::init<>());

    auto nk_config_stack_style_item_var = nb::class_<struct nk_config_stack_style_item>(m, "nk_config_stack_style_item");
        nk_config_stack_style_item_var.def(nb::init<>());

    auto nk_config_stack_float_var = nb::class_<struct nk_config_stack_float>(m, "nk_config_stack_float");
        nk_config_stack_float_var.def(nb::init<>());

    auto nk_config_stack_vec2_var = nb::class_<struct nk_config_stack_vec2>(m, "nk_config_stack_vec2");
        nk_config_stack_vec2_var.def(nb::init<>());

    auto nk_config_stack_flags_var = nb::class_<struct nk_config_stack_flags>(m, "nk_config_stack_flags");
        nk_config_stack_flags_var.def(nb::init<>());

    auto nk_config_stack_color_var = nb::class_<struct nk_config_stack_color>(m, "nk_config_stack_color");
        nk_config_stack_color_var.def(nb::init<>());

    auto nk_config_stack_user_font_var = nb::class_<struct nk_config_stack_user_font>(m, "nk_config_stack_user_font");
        nk_config_stack_user_font_var.def(nb::init<>());

    auto nk_config_stack_button_behavior_var = nb::class_<struct nk_config_stack_button_behavior>(m, "nk_config_stack_button_behavior");
        nk_config_stack_button_behavior_var.def(nb::init<>());

    auto nk_configuration_stacks_var = nb::class_<struct nk_configuration_stacks>(m, "nk_configuration_stacks");
        nk_configuration_stacks_var.def(nb::init<>());

    auto nk_table_var = nb::class_<struct nk_table>(m, "nk_table");
        nk_table_var.def(nb::init<>());

    auto nk_page_element_var = nb::class_<struct nk_page_element>(m, "nk_page_element");
        nk_page_element_var.def(nb::init<>());

    auto nk_page_var = nb::class_<struct nk_page>(m, "nk_page");
        nk_page_var.def(nb::init<>());

    auto nk_context_var = nb::class_<struct nk_context>(m, "nk_context");
        nk_context_var.def(nb::init<>());

    nk_color_var.def_rw("r", &nk_color::r);
    nk_color_var.def_rw("g", &nk_color::g);
    nk_color_var.def_rw("b", &nk_color::b);
    nk_color_var.def_rw("a", &nk_color::a);

    nk_colorf_var.def_rw("r", &nk_colorf::r);
    nk_colorf_var.def_rw("g", &nk_colorf::g);
    nk_colorf_var.def_rw("b", &nk_colorf::b);
    nk_colorf_var.def_rw("a", &nk_colorf::a);

    nk_vec2_var.def_rw("x", &nk_vec2::x);
    nk_vec2_var.def_rw("y", &nk_vec2::y);

    nk_vec2i_var.def_rw("y", &nk_vec2i::y);

    nk_rect_var.def_rw("x", &nk_rect::x);
    nk_rect_var.def_rw("y", &nk_rect::y);
    nk_rect_var.def_rw("w", &nk_rect::w);
    nk_rect_var.def_rw("h", &nk_rect::h);

    nk_recti_var.def_rw("x", &nk_recti::x);
    nk_recti_var.def_rw("y", &nk_recti::y);
    nk_recti_var.def_rw("w", &nk_recti::w);
    nk_recti_var.def_rw("h", &nk_recti::h);

    nk_image_var.def_rw("handle", &nk_image::handle);
    nk_image_var.def_rw("h", &nk_image::h);

    nk_nine_slice_var.def_rw("img", &nk_nine_slice::img);
    nk_nine_slice_var.def_rw("b", &nk_nine_slice::b);

    nk_cursor_var.def_rw("img", &nk_cursor::img);
    nk_cursor_var.def_rw("offset", &nk_cursor::offset);

    nk_scroll_var.def_rw("y", &nk_scroll::y);

    nk_draw_null_texture_var.def_rw("texture", &nk_draw_null_texture::texture);
    nk_draw_null_texture_var.def_rw("uv", &nk_draw_null_texture::uv);

    nk_convert_config_var.def_rw("global_alpha", &nk_convert_config::global_alpha);
    nk_convert_config_var.def_rw("line_AA", &nk_convert_config::line_AA);
    nk_convert_config_var.def_rw("shape_AA", &nk_convert_config::shape_AA);
    nk_convert_config_var.def_rw("circle_segment_count", &nk_convert_config::circle_segment_count);
    nk_convert_config_var.def_rw("arc_segment_count", &nk_convert_config::arc_segment_count);
    nk_convert_config_var.def_rw("curve_segment_count", &nk_convert_config::curve_segment_count);
    nk_convert_config_var.def_rw("tex_null", &nk_convert_config::tex_null);
    nk_convert_config_var.def_rw("vertex_size", &nk_convert_config::vertex_size);
    nk_convert_config_var.def_rw("vertex_alignment", &nk_convert_config::vertex_alignment);

    nk_list_view_var.def_rw("count", &nk_list_view::count);
    nk_list_view_var.def_rw("total_height", &nk_list_view::total_height);
    nk_list_view_var.def_rw("scroll_value", &nk_list_view::scroll_value);

    nk_user_font_glyph_var.def_rw("offset", &nk_user_font_glyph::offset);
    nk_user_font_glyph_var.def_rw("height", &nk_user_font_glyph::height);
    nk_user_font_glyph_var.def_rw("xadvance", &nk_user_font_glyph::xadvance);

    nk_user_font_var.def_rw("userdata", &nk_user_font::userdata);
    nk_user_font_var.def_rw("height", &nk_user_font::height);
    nk_user_font_var.def_rw("texture", &nk_user_font::texture);

    nk_baked_font_var.def_rw("height", &nk_baked_font::height);
    nk_baked_font_var.def_rw("ascent", &nk_baked_font::ascent);
    nk_baked_font_var.def_rw("descent", &nk_baked_font::descent);
    nk_baked_font_var.def_rw("glyph_offset", &nk_baked_font::glyph_offset);
    nk_baked_font_var.def_rw("glyph_count", &nk_baked_font::glyph_count);

    nk_font_config_var.def_rw("ttf_size", &nk_font_config::ttf_size);
    nk_font_config_var.def_rw("ttf_data_owned_by_atlas", &nk_font_config::ttf_data_owned_by_atlas);
    nk_font_config_var.def_rw("merge_mode", &nk_font_config::merge_mode);
    nk_font_config_var.def_rw("pixel_snap", &nk_font_config::pixel_snap);
    nk_font_config_var.def_rw("oversample_h", &nk_font_config::oversample_h);
    nk_font_config_var.def_rw("size", &nk_font_config::size);
    nk_font_config_var.def_rw("coord_type", &nk_font_config::coord_type);
    nk_font_config_var.def_rw("spacing", &nk_font_config::spacing);
    nk_font_config_var.def_rw("fallback_glyph", &nk_font_config::fallback_glyph);

    nk_font_glyph_var.def_rw("codepoint", &nk_font_glyph::codepoint);
    nk_font_glyph_var.def_rw("xadvance", &nk_font_glyph::xadvance);
    nk_font_glyph_var.def_rw("h", &nk_font_glyph::h);
    nk_font_glyph_var.def_rw("v1", &nk_font_glyph::v1);

    nk_font_var.def_rw("handle", &nk_font::handle);
    nk_font_var.def_rw("info", &nk_font::info);
    nk_font_var.def_rw("scale", &nk_font::scale);
    nk_font_var.def_rw("fallback_codepoint", &nk_font::fallback_codepoint);
    nk_font_var.def_rw("texture", &nk_font::texture);

    nk_memory_status_var.def_rw("type", &nk_memory_status::type);
    nk_memory_status_var.def_rw("size", &nk_memory_status::size);
    nk_memory_status_var.def_rw("allocated", &nk_memory_status::allocated);
    nk_memory_status_var.def_rw("needed", &nk_memory_status::needed);
    nk_memory_status_var.def_rw("calls", &nk_memory_status::calls);

    nk_buffer_marker_var.def_rw("active", &nk_buffer_marker::active);
    nk_buffer_marker_var.def_rw("offset", &nk_buffer_marker::offset);

    nk_memory_var.def_rw("size", &nk_memory::size);

    nk_str_var.def_rw("buffer", &nk_str::buffer);
    nk_str_var.def_rw("len", &nk_str::len);

    nk_clipboard_var.def_rw("userdata", &nk_clipboard::userdata);

    nk_text_undo_record_var.def_rw("where", &nk_text_undo_record::where);
    nk_text_undo_record_var.def_rw("insert_length", &nk_text_undo_record::insert_length);
    nk_text_undo_record_var.def_rw("delete_length", &nk_text_undo_record::delete_length);
    nk_text_undo_record_var.def_rw("char_storage", &nk_text_undo_record::char_storage);

    nk_text_undo_state_var.def_rw("undo_point", &nk_text_undo_state::undo_point);
    nk_text_undo_state_var.def_rw("redo_point", &nk_text_undo_state::redo_point);
    nk_text_undo_state_var.def_rw("undo_char_point", &nk_text_undo_state::undo_char_point);
    nk_text_undo_state_var.def_rw("redo_char_point", &nk_text_undo_state::redo_char_point);

    nk_text_edit_var.def_rw("clip", &nk_text_edit::clip);
    nk_text_edit_var.def_rw("string", &nk_text_edit::string);
    nk_text_edit_var.def_rw("scrollbar", &nk_text_edit::scrollbar);
    nk_text_edit_var.def_rw("cursor", &nk_text_edit::cursor);
    nk_text_edit_var.def_rw("select_start", &nk_text_edit::select_start);
    nk_text_edit_var.def_rw("select_end", &nk_text_edit::select_end);
    nk_text_edit_var.def_rw("mode", &nk_text_edit::mode);
    nk_text_edit_var.def_rw("cursor_at_end_of_line", &nk_text_edit::cursor_at_end_of_line);
    nk_text_edit_var.def_rw("initialized", &nk_text_edit::initialized);
    nk_text_edit_var.def_rw("has_preferred_x", &nk_text_edit::has_preferred_x);
    nk_text_edit_var.def_rw("single_line", &nk_text_edit::single_line);
    nk_text_edit_var.def_rw("active", &nk_text_edit::active);
    nk_text_edit_var.def_rw("padding1", &nk_text_edit::padding1);
    nk_text_edit_var.def_rw("preferred_x", &nk_text_edit::preferred_x);
    nk_text_edit_var.def_rw("undo", &nk_text_edit::undo);

    nk_command_var.def_rw("type", &nk_command::type);
    nk_command_var.def_rw("next", &nk_command::next);

    nk_command_scissor_var.def_rw("header", &nk_command_scissor::header);
    nk_command_scissor_var.def_rw("y", &nk_command_scissor::y);
    nk_command_scissor_var.def_rw("h", &nk_command_scissor::h);

    nk_command_line_var.def_rw("header", &nk_command_line::header);
    nk_command_line_var.def_rw("line_thickness", &nk_command_line::line_thickness);
    nk_command_line_var.def_rw("begin", &nk_command_line::begin);
    nk_command_line_var.def_rw("end", &nk_command_line::end);
    nk_command_line_var.def_rw("color", &nk_command_line::color);

    nk_command_curve_var.def_rw("header", &nk_command_curve::header);
    nk_command_curve_var.def_rw("line_thickness", &nk_command_curve::line_thickness);
    nk_command_curve_var.def_rw("begin", &nk_command_curve::begin);
    nk_command_curve_var.def_rw("end", &nk_command_curve::end);
    nk_command_curve_var.def_rw("color", &nk_command_curve::color);

    nk_command_rect_var.def_rw("header", &nk_command_rect::header);
    nk_command_rect_var.def_rw("rounding", &nk_command_rect::rounding);
    nk_command_rect_var.def_rw("line_thickness", &nk_command_rect::line_thickness);
    nk_command_rect_var.def_rw("y", &nk_command_rect::y);
    nk_command_rect_var.def_rw("h", &nk_command_rect::h);
    nk_command_rect_var.def_rw("color", &nk_command_rect::color);

    nk_command_rect_filled_var.def_rw("header", &nk_command_rect_filled::header);
    nk_command_rect_filled_var.def_rw("rounding", &nk_command_rect_filled::rounding);
    nk_command_rect_filled_var.def_rw("y", &nk_command_rect_filled::y);
    nk_command_rect_filled_var.def_rw("h", &nk_command_rect_filled::h);
    nk_command_rect_filled_var.def_rw("color", &nk_command_rect_filled::color);

    nk_command_rect_multi_color_var.def_rw("header", &nk_command_rect_multi_color::header);
    nk_command_rect_multi_color_var.def_rw("y", &nk_command_rect_multi_color::y);
    nk_command_rect_multi_color_var.def_rw("h", &nk_command_rect_multi_color::h);
    nk_command_rect_multi_color_var.def_rw("left", &nk_command_rect_multi_color::left);
    nk_command_rect_multi_color_var.def_rw("top", &nk_command_rect_multi_color::top);
    nk_command_rect_multi_color_var.def_rw("bottom", &nk_command_rect_multi_color::bottom);
    nk_command_rect_multi_color_var.def_rw("right", &nk_command_rect_multi_color::right);

    nk_command_triangle_var.def_rw("header", &nk_command_triangle::header);
    nk_command_triangle_var.def_rw("line_thickness", &nk_command_triangle::line_thickness);
    nk_command_triangle_var.def_rw("a", &nk_command_triangle::a);
    nk_command_triangle_var.def_rw("b", &nk_command_triangle::b);
    nk_command_triangle_var.def_rw("c", &nk_command_triangle::c);
    nk_command_triangle_var.def_rw("color", &nk_command_triangle::color);

    nk_command_triangle_filled_var.def_rw("header", &nk_command_triangle_filled::header);
    nk_command_triangle_filled_var.def_rw("a", &nk_command_triangle_filled::a);
    nk_command_triangle_filled_var.def_rw("b", &nk_command_triangle_filled::b);
    nk_command_triangle_filled_var.def_rw("c", &nk_command_triangle_filled::c);
    nk_command_triangle_filled_var.def_rw("color", &nk_command_triangle_filled::color);

    nk_command_circle_var.def_rw("header", &nk_command_circle::header);
    nk_command_circle_var.def_rw("y", &nk_command_circle::y);
    nk_command_circle_var.def_rw("line_thickness", &nk_command_circle::line_thickness);
    nk_command_circle_var.def_rw("h", &nk_command_circle::h);
    nk_command_circle_var.def_rw("color", &nk_command_circle::color);

    nk_command_circle_filled_var.def_rw("header", &nk_command_circle_filled::header);
    nk_command_circle_filled_var.def_rw("y", &nk_command_circle_filled::y);
    nk_command_circle_filled_var.def_rw("h", &nk_command_circle_filled::h);
    nk_command_circle_filled_var.def_rw("color", &nk_command_circle_filled::color);

    nk_command_arc_var.def_rw("header", &nk_command_arc::header);
    nk_command_arc_var.def_rw("cy", &nk_command_arc::cy);
    nk_command_arc_var.def_rw("r", &nk_command_arc::r);
    nk_command_arc_var.def_rw("line_thickness", &nk_command_arc::line_thickness);
    nk_command_arc_var.def_rw("color", &nk_command_arc::color);

    nk_command_arc_filled_var.def_rw("header", &nk_command_arc_filled::header);
    nk_command_arc_filled_var.def_rw("cy", &nk_command_arc_filled::cy);
    nk_command_arc_filled_var.def_rw("r", &nk_command_arc_filled::r);
    nk_command_arc_filled_var.def_rw("color", &nk_command_arc_filled::color);

    nk_command_polygon_var.def_rw("header", &nk_command_polygon::header);
    nk_command_polygon_var.def_rw("color", &nk_command_polygon::color);
    nk_command_polygon_var.def_rw("line_thickness", &nk_command_polygon::line_thickness);
    nk_command_polygon_var.def_rw("point_count", &nk_command_polygon::point_count);

    nk_command_polygon_filled_var.def_rw("header", &nk_command_polygon_filled::header);
    nk_command_polygon_filled_var.def_rw("color", &nk_command_polygon_filled::color);
    nk_command_polygon_filled_var.def_rw("point_count", &nk_command_polygon_filled::point_count);

    nk_command_polyline_var.def_rw("header", &nk_command_polyline::header);
    nk_command_polyline_var.def_rw("color", &nk_command_polyline::color);
    nk_command_polyline_var.def_rw("line_thickness", &nk_command_polyline::line_thickness);
    nk_command_polyline_var.def_rw("point_count", &nk_command_polyline::point_count);

    nk_command_image_var.def_rw("header", &nk_command_image::header);
    nk_command_image_var.def_rw("y", &nk_command_image::y);
    nk_command_image_var.def_rw("h", &nk_command_image::h);
    nk_command_image_var.def_rw("img", &nk_command_image::img);
    nk_command_image_var.def_rw("col", &nk_command_image::col);

    nk_command_text_var.def_rw("header", &nk_command_text::header);
    nk_command_text_var.def_rw("background", &nk_command_text::background);
    nk_command_text_var.def_rw("foreground", &nk_command_text::foreground);
    nk_command_text_var.def_rw("y", &nk_command_text::y);
    nk_command_text_var.def_rw("h", &nk_command_text::h);
    nk_command_text_var.def_rw("height", &nk_command_text::height);
    nk_command_text_var.def_rw("length", &nk_command_text::length);

    nk_command_buffer_var.def_rw("clip", &nk_command_buffer::clip);
    nk_command_buffer_var.def_rw("use_clipping", &nk_command_buffer::use_clipping);
    nk_command_buffer_var.def_rw("userdata", &nk_command_buffer::userdata);
    nk_command_buffer_var.def_rw("last", &nk_command_buffer::last);

    nk_mouse_button_var.def_rw("down", &nk_mouse_button::down);
    nk_mouse_button_var.def_rw("clicked", &nk_mouse_button::clicked);
    nk_mouse_button_var.def_rw("clicked_pos", &nk_mouse_button::clicked_pos);

    nk_mouse_var.def_rw("pos", &nk_mouse::pos);
    nk_mouse_var.def_rw("prev", &nk_mouse::prev);
    nk_mouse_var.def_rw("delta", &nk_mouse::delta);
    nk_mouse_var.def_rw("scroll_delta", &nk_mouse::scroll_delta);
    nk_mouse_var.def_rw("grab", &nk_mouse::grab);
    nk_mouse_var.def_rw("grabbed", &nk_mouse::grabbed);
    nk_mouse_var.def_rw("ungrab", &nk_mouse::ungrab);

    nk_key_var.def_rw("down", &nk_key::down);
    nk_key_var.def_rw("clicked", &nk_key::clicked);

    nk_keyboard_var.def_rw("text_len", &nk_keyboard::text_len);

    nk_input_var.def_rw("keyboard", &nk_input::keyboard);
    nk_input_var.def_rw("mouse", &nk_input::mouse);

    nk_draw_vertex_layout_element_var.def_rw("attribute", &nk_draw_vertex_layout_element::attribute);
    nk_draw_vertex_layout_element_var.def_rw("format", &nk_draw_vertex_layout_element::format);
    nk_draw_vertex_layout_element_var.def_rw("offset", &nk_draw_vertex_layout_element::offset);

    nk_draw_command_var.def_rw("elem_count", &nk_draw_command::elem_count);
    nk_draw_command_var.def_rw("clip_rect", &nk_draw_command::clip_rect);
    nk_draw_command_var.def_rw("texture", &nk_draw_command::texture);

    nk_draw_list_var.def_rw("clip_rect", &nk_draw_list::clip_rect);
    nk_draw_list_var.def_rw("config", &nk_draw_list::config);
    nk_draw_list_var.def_rw("element_count", &nk_draw_list::element_count);
    nk_draw_list_var.def_rw("vertex_count", &nk_draw_list::vertex_count);
    nk_draw_list_var.def_rw("cmd_count", &nk_draw_list::cmd_count);
    nk_draw_list_var.def_rw("cmd_offset", &nk_draw_list::cmd_offset);
    nk_draw_list_var.def_rw("path_count", &nk_draw_list::path_count);
    nk_draw_list_var.def_rw("path_offset", &nk_draw_list::path_offset);
    nk_draw_list_var.def_rw("line_AA", &nk_draw_list::line_AA);
    nk_draw_list_var.def_rw("shape_AA", &nk_draw_list::shape_AA);

    nk_style_item_var.def_rw("type", &nk_style_item::type);
    nk_style_item_var.def_rw("data", &nk_style_item::data);

    nk_style_text_var.def_rw("color", &nk_style_text::color);
    nk_style_text_var.def_rw("padding", &nk_style_text::padding);
    nk_style_text_var.def_rw("color_factor", &nk_style_text::color_factor);
    nk_style_text_var.def_rw("disabled_factor", &nk_style_text::disabled_factor);

    nk_style_button_var.def_rw("normal", &nk_style_button::normal);
    nk_style_button_var.def_rw("hover", &nk_style_button::hover);
    nk_style_button_var.def_rw("active", &nk_style_button::active);
    nk_style_button_var.def_rw("border_color", &nk_style_button::border_color);
    nk_style_button_var.def_rw("color_factor_background", &nk_style_button::color_factor_background);
    nk_style_button_var.def_rw("text_background", &nk_style_button::text_background);
    nk_style_button_var.def_rw("text_normal", &nk_style_button::text_normal);
    nk_style_button_var.def_rw("text_hover", &nk_style_button::text_hover);
    nk_style_button_var.def_rw("text_active", &nk_style_button::text_active);
    nk_style_button_var.def_rw("text_alignment", &nk_style_button::text_alignment);
    nk_style_button_var.def_rw("color_factor_text", &nk_style_button::color_factor_text);
    nk_style_button_var.def_rw("border", &nk_style_button::border);
    nk_style_button_var.def_rw("rounding", &nk_style_button::rounding);
    nk_style_button_var.def_rw("padding", &nk_style_button::padding);
    nk_style_button_var.def_rw("image_padding", &nk_style_button::image_padding);
    nk_style_button_var.def_rw("touch_padding", &nk_style_button::touch_padding);
    nk_style_button_var.def_rw("disabled_factor", &nk_style_button::disabled_factor);
    nk_style_button_var.def_rw("userdata", &nk_style_button::userdata);

    nk_style_toggle_var.def_rw("normal", &nk_style_toggle::normal);
    nk_style_toggle_var.def_rw("hover", &nk_style_toggle::hover);
    nk_style_toggle_var.def_rw("active", &nk_style_toggle::active);
    nk_style_toggle_var.def_rw("border_color", &nk_style_toggle::border_color);
    nk_style_toggle_var.def_rw("cursor_normal", &nk_style_toggle::cursor_normal);
    nk_style_toggle_var.def_rw("cursor_hover", &nk_style_toggle::cursor_hover);
    nk_style_toggle_var.def_rw("text_normal", &nk_style_toggle::text_normal);
    nk_style_toggle_var.def_rw("text_hover", &nk_style_toggle::text_hover);
    nk_style_toggle_var.def_rw("text_active", &nk_style_toggle::text_active);
    nk_style_toggle_var.def_rw("text_background", &nk_style_toggle::text_background);
    nk_style_toggle_var.def_rw("text_alignment", &nk_style_toggle::text_alignment);
    nk_style_toggle_var.def_rw("padding", &nk_style_toggle::padding);
    nk_style_toggle_var.def_rw("touch_padding", &nk_style_toggle::touch_padding);
    nk_style_toggle_var.def_rw("spacing", &nk_style_toggle::spacing);
    nk_style_toggle_var.def_rw("border", &nk_style_toggle::border);
    nk_style_toggle_var.def_rw("color_factor", &nk_style_toggle::color_factor);
    nk_style_toggle_var.def_rw("disabled_factor", &nk_style_toggle::disabled_factor);
    nk_style_toggle_var.def_rw("userdata", &nk_style_toggle::userdata);

    nk_style_selectable_var.def_rw("normal", &nk_style_selectable::normal);
    nk_style_selectable_var.def_rw("hover", &nk_style_selectable::hover);
    nk_style_selectable_var.def_rw("pressed", &nk_style_selectable::pressed);
    nk_style_selectable_var.def_rw("normal_active", &nk_style_selectable::normal_active);
    nk_style_selectable_var.def_rw("hover_active", &nk_style_selectable::hover_active);
    nk_style_selectable_var.def_rw("pressed_active", &nk_style_selectable::pressed_active);
    nk_style_selectable_var.def_rw("text_normal", &nk_style_selectable::text_normal);
    nk_style_selectable_var.def_rw("text_hover", &nk_style_selectable::text_hover);
    nk_style_selectable_var.def_rw("text_pressed", &nk_style_selectable::text_pressed);
    nk_style_selectable_var.def_rw("text_normal_active", &nk_style_selectable::text_normal_active);
    nk_style_selectable_var.def_rw("text_hover_active", &nk_style_selectable::text_hover_active);
    nk_style_selectable_var.def_rw("text_pressed_active", &nk_style_selectable::text_pressed_active);
    nk_style_selectable_var.def_rw("text_background", &nk_style_selectable::text_background);
    nk_style_selectable_var.def_rw("text_alignment", &nk_style_selectable::text_alignment);
    nk_style_selectable_var.def_rw("rounding", &nk_style_selectable::rounding);
    nk_style_selectable_var.def_rw("padding", &nk_style_selectable::padding);
    nk_style_selectable_var.def_rw("touch_padding", &nk_style_selectable::touch_padding);
    nk_style_selectable_var.def_rw("image_padding", &nk_style_selectable::image_padding);
    nk_style_selectable_var.def_rw("color_factor", &nk_style_selectable::color_factor);
    nk_style_selectable_var.def_rw("disabled_factor", &nk_style_selectable::disabled_factor);
    nk_style_selectable_var.def_rw("userdata", &nk_style_selectable::userdata);

    nk_style_slider_var.def_rw("normal", &nk_style_slider::normal);
    nk_style_slider_var.def_rw("hover", &nk_style_slider::hover);
    nk_style_slider_var.def_rw("active", &nk_style_slider::active);
    nk_style_slider_var.def_rw("border_color", &nk_style_slider::border_color);
    nk_style_slider_var.def_rw("bar_normal", &nk_style_slider::bar_normal);
    nk_style_slider_var.def_rw("bar_hover", &nk_style_slider::bar_hover);
    nk_style_slider_var.def_rw("bar_active", &nk_style_slider::bar_active);
    nk_style_slider_var.def_rw("bar_filled", &nk_style_slider::bar_filled);
    nk_style_slider_var.def_rw("cursor_normal", &nk_style_slider::cursor_normal);
    nk_style_slider_var.def_rw("cursor_hover", &nk_style_slider::cursor_hover);
    nk_style_slider_var.def_rw("cursor_active", &nk_style_slider::cursor_active);
    nk_style_slider_var.def_rw("border", &nk_style_slider::border);
    nk_style_slider_var.def_rw("rounding", &nk_style_slider::rounding);
    nk_style_slider_var.def_rw("bar_height", &nk_style_slider::bar_height);
    nk_style_slider_var.def_rw("padding", &nk_style_slider::padding);
    nk_style_slider_var.def_rw("spacing", &nk_style_slider::spacing);
    nk_style_slider_var.def_rw("cursor_size", &nk_style_slider::cursor_size);
    nk_style_slider_var.def_rw("color_factor", &nk_style_slider::color_factor);
    nk_style_slider_var.def_rw("disabled_factor", &nk_style_slider::disabled_factor);
    nk_style_slider_var.def_rw("show_buttons", &nk_style_slider::show_buttons);
    nk_style_slider_var.def_rw("inc_button", &nk_style_slider::inc_button);
    nk_style_slider_var.def_rw("dec_button", &nk_style_slider::dec_button);
    nk_style_slider_var.def_rw("inc_symbol", &nk_style_slider::inc_symbol);
    nk_style_slider_var.def_rw("dec_symbol", &nk_style_slider::dec_symbol);
    nk_style_slider_var.def_rw("userdata", &nk_style_slider::userdata);

    nk_style_knob_var.def_rw("normal", &nk_style_knob::normal);
    nk_style_knob_var.def_rw("hover", &nk_style_knob::hover);
    nk_style_knob_var.def_rw("active", &nk_style_knob::active);
    nk_style_knob_var.def_rw("border_color", &nk_style_knob::border_color);
    nk_style_knob_var.def_rw("knob_normal", &nk_style_knob::knob_normal);
    nk_style_knob_var.def_rw("knob_hover", &nk_style_knob::knob_hover);
    nk_style_knob_var.def_rw("knob_active", &nk_style_knob::knob_active);
    nk_style_knob_var.def_rw("knob_border_color", &nk_style_knob::knob_border_color);
    nk_style_knob_var.def_rw("cursor_normal", &nk_style_knob::cursor_normal);
    nk_style_knob_var.def_rw("cursor_hover", &nk_style_knob::cursor_hover);
    nk_style_knob_var.def_rw("cursor_active", &nk_style_knob::cursor_active);
    nk_style_knob_var.def_rw("border", &nk_style_knob::border);
    nk_style_knob_var.def_rw("knob_border", &nk_style_knob::knob_border);
    nk_style_knob_var.def_rw("padding", &nk_style_knob::padding);
    nk_style_knob_var.def_rw("spacing", &nk_style_knob::spacing);
    nk_style_knob_var.def_rw("cursor_width", &nk_style_knob::cursor_width);
    nk_style_knob_var.def_rw("color_factor", &nk_style_knob::color_factor);
    nk_style_knob_var.def_rw("disabled_factor", &nk_style_knob::disabled_factor);
    nk_style_knob_var.def_rw("userdata", &nk_style_knob::userdata);

    nk_style_progress_var.def_rw("normal", &nk_style_progress::normal);
    nk_style_progress_var.def_rw("hover", &nk_style_progress::hover);
    nk_style_progress_var.def_rw("active", &nk_style_progress::active);
    nk_style_progress_var.def_rw("border_color", &nk_style_progress::border_color);
    nk_style_progress_var.def_rw("cursor_normal", &nk_style_progress::cursor_normal);
    nk_style_progress_var.def_rw("cursor_hover", &nk_style_progress::cursor_hover);
    nk_style_progress_var.def_rw("cursor_active", &nk_style_progress::cursor_active);
    nk_style_progress_var.def_rw("cursor_border_color", &nk_style_progress::cursor_border_color);
    nk_style_progress_var.def_rw("rounding", &nk_style_progress::rounding);
    nk_style_progress_var.def_rw("border", &nk_style_progress::border);
    nk_style_progress_var.def_rw("cursor_border", &nk_style_progress::cursor_border);
    nk_style_progress_var.def_rw("cursor_rounding", &nk_style_progress::cursor_rounding);
    nk_style_progress_var.def_rw("padding", &nk_style_progress::padding);
    nk_style_progress_var.def_rw("color_factor", &nk_style_progress::color_factor);
    nk_style_progress_var.def_rw("disabled_factor", &nk_style_progress::disabled_factor);
    nk_style_progress_var.def_rw("userdata", &nk_style_progress::userdata);

    nk_style_scrollbar_var.def_rw("normal", &nk_style_scrollbar::normal);
    nk_style_scrollbar_var.def_rw("hover", &nk_style_scrollbar::hover);
    nk_style_scrollbar_var.def_rw("active", &nk_style_scrollbar::active);
    nk_style_scrollbar_var.def_rw("border_color", &nk_style_scrollbar::border_color);
    nk_style_scrollbar_var.def_rw("cursor_normal", &nk_style_scrollbar::cursor_normal);
    nk_style_scrollbar_var.def_rw("cursor_hover", &nk_style_scrollbar::cursor_hover);
    nk_style_scrollbar_var.def_rw("cursor_active", &nk_style_scrollbar::cursor_active);
    nk_style_scrollbar_var.def_rw("cursor_border_color", &nk_style_scrollbar::cursor_border_color);
    nk_style_scrollbar_var.def_rw("border", &nk_style_scrollbar::border);
    nk_style_scrollbar_var.def_rw("rounding", &nk_style_scrollbar::rounding);
    nk_style_scrollbar_var.def_rw("border_cursor", &nk_style_scrollbar::border_cursor);
    nk_style_scrollbar_var.def_rw("rounding_cursor", &nk_style_scrollbar::rounding_cursor);
    nk_style_scrollbar_var.def_rw("padding", &nk_style_scrollbar::padding);
    nk_style_scrollbar_var.def_rw("color_factor", &nk_style_scrollbar::color_factor);
    nk_style_scrollbar_var.def_rw("disabled_factor", &nk_style_scrollbar::disabled_factor);
    nk_style_scrollbar_var.def_rw("show_buttons", &nk_style_scrollbar::show_buttons);
    nk_style_scrollbar_var.def_rw("inc_button", &nk_style_scrollbar::inc_button);
    nk_style_scrollbar_var.def_rw("dec_button", &nk_style_scrollbar::dec_button);
    nk_style_scrollbar_var.def_rw("inc_symbol", &nk_style_scrollbar::inc_symbol);
    nk_style_scrollbar_var.def_rw("dec_symbol", &nk_style_scrollbar::dec_symbol);
    nk_style_scrollbar_var.def_rw("userdata", &nk_style_scrollbar::userdata);

    nk_style_edit_var.def_rw("normal", &nk_style_edit::normal);
    nk_style_edit_var.def_rw("hover", &nk_style_edit::hover);
    nk_style_edit_var.def_rw("active", &nk_style_edit::active);
    nk_style_edit_var.def_rw("border_color", &nk_style_edit::border_color);
    nk_style_edit_var.def_rw("scrollbar", &nk_style_edit::scrollbar);
    nk_style_edit_var.def_rw("cursor_normal", &nk_style_edit::cursor_normal);
    nk_style_edit_var.def_rw("cursor_hover", &nk_style_edit::cursor_hover);
    nk_style_edit_var.def_rw("cursor_text_normal", &nk_style_edit::cursor_text_normal);
    nk_style_edit_var.def_rw("cursor_text_hover", &nk_style_edit::cursor_text_hover);
    nk_style_edit_var.def_rw("text_normal", &nk_style_edit::text_normal);
    nk_style_edit_var.def_rw("text_hover", &nk_style_edit::text_hover);
    nk_style_edit_var.def_rw("text_active", &nk_style_edit::text_active);
    nk_style_edit_var.def_rw("selected_normal", &nk_style_edit::selected_normal);
    nk_style_edit_var.def_rw("selected_hover", &nk_style_edit::selected_hover);
    nk_style_edit_var.def_rw("selected_text_normal", &nk_style_edit::selected_text_normal);
    nk_style_edit_var.def_rw("selected_text_hover", &nk_style_edit::selected_text_hover);
    nk_style_edit_var.def_rw("border", &nk_style_edit::border);
    nk_style_edit_var.def_rw("rounding", &nk_style_edit::rounding);
    nk_style_edit_var.def_rw("cursor_size", &nk_style_edit::cursor_size);
    nk_style_edit_var.def_rw("scrollbar_size", &nk_style_edit::scrollbar_size);
    nk_style_edit_var.def_rw("padding", &nk_style_edit::padding);
    nk_style_edit_var.def_rw("row_padding", &nk_style_edit::row_padding);
    nk_style_edit_var.def_rw("color_factor", &nk_style_edit::color_factor);
    nk_style_edit_var.def_rw("disabled_factor", &nk_style_edit::disabled_factor);

    nk_style_property_var.def_rw("normal", &nk_style_property::normal);
    nk_style_property_var.def_rw("hover", &nk_style_property::hover);
    nk_style_property_var.def_rw("active", &nk_style_property::active);
    nk_style_property_var.def_rw("border_color", &nk_style_property::border_color);
    nk_style_property_var.def_rw("label_normal", &nk_style_property::label_normal);
    nk_style_property_var.def_rw("label_hover", &nk_style_property::label_hover);
    nk_style_property_var.def_rw("label_active", &nk_style_property::label_active);
    nk_style_property_var.def_rw("sym_left", &nk_style_property::sym_left);
    nk_style_property_var.def_rw("sym_right", &nk_style_property::sym_right);
    nk_style_property_var.def_rw("border", &nk_style_property::border);
    nk_style_property_var.def_rw("rounding", &nk_style_property::rounding);
    nk_style_property_var.def_rw("padding", &nk_style_property::padding);
    nk_style_property_var.def_rw("color_factor", &nk_style_property::color_factor);
    nk_style_property_var.def_rw("disabled_factor", &nk_style_property::disabled_factor);
    nk_style_property_var.def_rw("edit", &nk_style_property::edit);
    nk_style_property_var.def_rw("inc_button", &nk_style_property::inc_button);
    nk_style_property_var.def_rw("dec_button", &nk_style_property::dec_button);
    nk_style_property_var.def_rw("userdata", &nk_style_property::userdata);

    nk_style_chart_var.def_rw("background", &nk_style_chart::background);
    nk_style_chart_var.def_rw("border_color", &nk_style_chart::border_color);
    nk_style_chart_var.def_rw("selected_color", &nk_style_chart::selected_color);
    nk_style_chart_var.def_rw("color", &nk_style_chart::color);
    nk_style_chart_var.def_rw("border", &nk_style_chart::border);
    nk_style_chart_var.def_rw("rounding", &nk_style_chart::rounding);
    nk_style_chart_var.def_rw("padding", &nk_style_chart::padding);
    nk_style_chart_var.def_rw("color_factor", &nk_style_chart::color_factor);
    nk_style_chart_var.def_rw("disabled_factor", &nk_style_chart::disabled_factor);
    nk_style_chart_var.def_rw("show_markers", &nk_style_chart::show_markers);

    nk_style_combo_var.def_rw("normal", &nk_style_combo::normal);
    nk_style_combo_var.def_rw("hover", &nk_style_combo::hover);
    nk_style_combo_var.def_rw("active", &nk_style_combo::active);
    nk_style_combo_var.def_rw("border_color", &nk_style_combo::border_color);
    nk_style_combo_var.def_rw("label_normal", &nk_style_combo::label_normal);
    nk_style_combo_var.def_rw("label_hover", &nk_style_combo::label_hover);
    nk_style_combo_var.def_rw("label_active", &nk_style_combo::label_active);
    nk_style_combo_var.def_rw("symbol_normal", &nk_style_combo::symbol_normal);
    nk_style_combo_var.def_rw("symbol_hover", &nk_style_combo::symbol_hover);
    nk_style_combo_var.def_rw("symbol_active", &nk_style_combo::symbol_active);
    nk_style_combo_var.def_rw("button", &nk_style_combo::button);
    nk_style_combo_var.def_rw("sym_normal", &nk_style_combo::sym_normal);
    nk_style_combo_var.def_rw("sym_hover", &nk_style_combo::sym_hover);
    nk_style_combo_var.def_rw("sym_active", &nk_style_combo::sym_active);
    nk_style_combo_var.def_rw("border", &nk_style_combo::border);
    nk_style_combo_var.def_rw("rounding", &nk_style_combo::rounding);
    nk_style_combo_var.def_rw("content_padding", &nk_style_combo::content_padding);
    nk_style_combo_var.def_rw("button_padding", &nk_style_combo::button_padding);
    nk_style_combo_var.def_rw("spacing", &nk_style_combo::spacing);
    nk_style_combo_var.def_rw("color_factor", &nk_style_combo::color_factor);
    nk_style_combo_var.def_rw("disabled_factor", &nk_style_combo::disabled_factor);

    nk_style_tab_var.def_rw("background", &nk_style_tab::background);
    nk_style_tab_var.def_rw("border_color", &nk_style_tab::border_color);
    nk_style_tab_var.def_rw("text", &nk_style_tab::text);
    nk_style_tab_var.def_rw("tab_maximize_button", &nk_style_tab::tab_maximize_button);
    nk_style_tab_var.def_rw("tab_minimize_button", &nk_style_tab::tab_minimize_button);
    nk_style_tab_var.def_rw("node_maximize_button", &nk_style_tab::node_maximize_button);
    nk_style_tab_var.def_rw("node_minimize_button", &nk_style_tab::node_minimize_button);
    nk_style_tab_var.def_rw("sym_minimize", &nk_style_tab::sym_minimize);
    nk_style_tab_var.def_rw("sym_maximize", &nk_style_tab::sym_maximize);
    nk_style_tab_var.def_rw("border", &nk_style_tab::border);
    nk_style_tab_var.def_rw("rounding", &nk_style_tab::rounding);
    nk_style_tab_var.def_rw("indent", &nk_style_tab::indent);
    nk_style_tab_var.def_rw("padding", &nk_style_tab::padding);
    nk_style_tab_var.def_rw("spacing", &nk_style_tab::spacing);
    nk_style_tab_var.def_rw("color_factor", &nk_style_tab::color_factor);
    nk_style_tab_var.def_rw("disabled_factor", &nk_style_tab::disabled_factor);

    nk_style_window_header_var.def_rw("normal", &nk_style_window_header::normal);
    nk_style_window_header_var.def_rw("hover", &nk_style_window_header::hover);
    nk_style_window_header_var.def_rw("active", &nk_style_window_header::active);
    nk_style_window_header_var.def_rw("close_button", &nk_style_window_header::close_button);
    nk_style_window_header_var.def_rw("minimize_button", &nk_style_window_header::minimize_button);
    nk_style_window_header_var.def_rw("close_symbol", &nk_style_window_header::close_symbol);
    nk_style_window_header_var.def_rw("minimize_symbol", &nk_style_window_header::minimize_symbol);
    nk_style_window_header_var.def_rw("maximize_symbol", &nk_style_window_header::maximize_symbol);
    nk_style_window_header_var.def_rw("label_normal", &nk_style_window_header::label_normal);
    nk_style_window_header_var.def_rw("label_hover", &nk_style_window_header::label_hover);
    nk_style_window_header_var.def_rw("label_active", &nk_style_window_header::label_active);
    nk_style_window_header_var.def_rw("align", &nk_style_window_header::align);
    nk_style_window_header_var.def_rw("padding", &nk_style_window_header::padding);
    nk_style_window_header_var.def_rw("label_padding", &nk_style_window_header::label_padding);
    nk_style_window_header_var.def_rw("spacing", &nk_style_window_header::spacing);

    nk_style_window_var.def_rw("header", &nk_style_window::header);
    nk_style_window_var.def_rw("fixed_background", &nk_style_window::fixed_background);
    nk_style_window_var.def_rw("background", &nk_style_window::background);
    nk_style_window_var.def_rw("border_color", &nk_style_window::border_color);
    nk_style_window_var.def_rw("popup_border_color", &nk_style_window::popup_border_color);
    nk_style_window_var.def_rw("combo_border_color", &nk_style_window::combo_border_color);
    nk_style_window_var.def_rw("contextual_border_color", &nk_style_window::contextual_border_color);
    nk_style_window_var.def_rw("menu_border_color", &nk_style_window::menu_border_color);
    nk_style_window_var.def_rw("group_border_color", &nk_style_window::group_border_color);
    nk_style_window_var.def_rw("tooltip_border_color", &nk_style_window::tooltip_border_color);
    nk_style_window_var.def_rw("scaler", &nk_style_window::scaler);
    nk_style_window_var.def_rw("border", &nk_style_window::border);
    nk_style_window_var.def_rw("combo_border", &nk_style_window::combo_border);
    nk_style_window_var.def_rw("contextual_border", &nk_style_window::contextual_border);
    nk_style_window_var.def_rw("menu_border", &nk_style_window::menu_border);
    nk_style_window_var.def_rw("group_border", &nk_style_window::group_border);
    nk_style_window_var.def_rw("tooltip_border", &nk_style_window::tooltip_border);
    nk_style_window_var.def_rw("popup_border", &nk_style_window::popup_border);
    nk_style_window_var.def_rw("min_row_height_padding", &nk_style_window::min_row_height_padding);
    nk_style_window_var.def_rw("rounding", &nk_style_window::rounding);
    nk_style_window_var.def_rw("spacing", &nk_style_window::spacing);
    nk_style_window_var.def_rw("scrollbar_size", &nk_style_window::scrollbar_size);
    nk_style_window_var.def_rw("min_size", &nk_style_window::min_size);
    nk_style_window_var.def_rw("padding", &nk_style_window::padding);
    nk_style_window_var.def_rw("group_padding", &nk_style_window::group_padding);
    nk_style_window_var.def_rw("popup_padding", &nk_style_window::popup_padding);
    nk_style_window_var.def_rw("combo_padding", &nk_style_window::combo_padding);
    nk_style_window_var.def_rw("contextual_padding", &nk_style_window::contextual_padding);
    nk_style_window_var.def_rw("menu_padding", &nk_style_window::menu_padding);
    nk_style_window_var.def_rw("tooltip_padding", &nk_style_window::tooltip_padding);
    nk_style_window_var.def_rw("tooltip_origin", &nk_style_window::tooltip_origin);
    nk_style_window_var.def_rw("tooltip_offset", &nk_style_window::tooltip_offset);

    nk_style_var.def_rw("cursor_visible", &nk_style::cursor_visible);
    nk_style_var.def_rw("text", &nk_style::text);
    nk_style_var.def_rw("button", &nk_style::button);
    nk_style_var.def_rw("contextual_button", &nk_style::contextual_button);
    nk_style_var.def_rw("menu_button", &nk_style::menu_button);
    nk_style_var.def_rw("option", &nk_style::option);
    nk_style_var.def_rw("checkbox", &nk_style::checkbox);
    nk_style_var.def_rw("selectable", &nk_style::selectable);
    nk_style_var.def_rw("slider", &nk_style::slider);
    nk_style_var.def_rw("knob", &nk_style::knob);
    nk_style_var.def_rw("progress", &nk_style::progress);
    nk_style_var.def_rw("property", &nk_style::property);
    nk_style_var.def_rw("edit", &nk_style::edit);
    nk_style_var.def_rw("chart", &nk_style::chart);
    nk_style_var.def_rw("scrollh", &nk_style::scrollh);
    nk_style_var.def_rw("scrollv", &nk_style::scrollv);
    nk_style_var.def_rw("tab", &nk_style::tab);
    nk_style_var.def_rw("combo", &nk_style::combo);
    nk_style_var.def_rw("window", &nk_style::window);

    nk_chart_slot_var.def_rw("type", &nk_chart_slot::type);
    nk_chart_slot_var.def_rw("color", &nk_chart_slot::color);
    nk_chart_slot_var.def_rw("highlight", &nk_chart_slot::highlight);
    nk_chart_slot_var.def_rw("range", &nk_chart_slot::range);
    nk_chart_slot_var.def_rw("count", &nk_chart_slot::count);
    nk_chart_slot_var.def_rw("last", &nk_chart_slot::last);
    nk_chart_slot_var.def_rw("index", &nk_chart_slot::index);
    nk_chart_slot_var.def_rw("show_markers", &nk_chart_slot::show_markers);

    nk_chart_var.def_rw("slot", &nk_chart::slot);
    nk_chart_var.def_rw("h", &nk_chart::h);

    nk_row_layout_var.def_rw("type", &nk_row_layout::type);
    nk_row_layout_var.def_rw("index", &nk_row_layout::index);
    nk_row_layout_var.def_rw("height", &nk_row_layout::height);
    nk_row_layout_var.def_rw("min_height", &nk_row_layout::min_height);
    nk_row_layout_var.def_rw("columns", &nk_row_layout::columns);
    nk_row_layout_var.def_rw("item_width", &nk_row_layout::item_width);
    nk_row_layout_var.def_rw("item_height", &nk_row_layout::item_height);
    nk_row_layout_var.def_rw("item_offset", &nk_row_layout::item_offset);
    nk_row_layout_var.def_rw("filled", &nk_row_layout::filled);
    nk_row_layout_var.def_rw("item", &nk_row_layout::item);
    nk_row_layout_var.def_rw("tree_depth", &nk_row_layout::tree_depth);

    nk_popup_buffer_var.def_rw("begin", &nk_popup_buffer::begin);
    nk_popup_buffer_var.def_rw("parent", &nk_popup_buffer::parent);
    nk_popup_buffer_var.def_rw("last", &nk_popup_buffer::last);
    nk_popup_buffer_var.def_rw("end", &nk_popup_buffer::end);
    nk_popup_buffer_var.def_rw("active", &nk_popup_buffer::active);

    nk_menu_state_var.def_rw("h", &nk_menu_state::h);
    nk_menu_state_var.def_rw("offset", &nk_menu_state::offset);

    nk_panel_var.def_rw("type", &nk_panel::type);
    nk_panel_var.def_rw("flags", &nk_panel::flags);
    nk_panel_var.def_rw("bounds", &nk_panel::bounds);
    nk_panel_var.def_rw("max_x", &nk_panel::max_x);
    nk_panel_var.def_rw("footer_height", &nk_panel::footer_height);
    nk_panel_var.def_rw("header_height", &nk_panel::header_height);
    nk_panel_var.def_rw("border", &nk_panel::border);
    nk_panel_var.def_rw("has_scrolling", &nk_panel::has_scrolling);
    nk_panel_var.def_rw("clip", &nk_panel::clip);
    nk_panel_var.def_rw("menu", &nk_panel::menu);
    nk_panel_var.def_rw("row", &nk_panel::row);
    nk_panel_var.def_rw("chart", &nk_panel::chart);

    nk_popup_state_var.def_rw("type", &nk_popup_state::type);
    nk_popup_state_var.def_rw("buf", &nk_popup_state::buf);
    nk_popup_state_var.def_rw("name", &nk_popup_state::name);
    nk_popup_state_var.def_rw("active", &nk_popup_state::active);
    nk_popup_state_var.def_rw("combo_count", &nk_popup_state::combo_count);
    nk_popup_state_var.def_rw("con_old", &nk_popup_state::con_old);
    nk_popup_state_var.def_rw("active_con", &nk_popup_state::active_con);
    nk_popup_state_var.def_rw("header", &nk_popup_state::header);

    nk_edit_state_var.def_rw("name", &nk_edit_state::name);
    nk_edit_state_var.def_rw("seq", &nk_edit_state::seq);
    nk_edit_state_var.def_rw("old", &nk_edit_state::old);
    nk_edit_state_var.def_rw("prev", &nk_edit_state::prev);
    nk_edit_state_var.def_rw("cursor", &nk_edit_state::cursor);
    nk_edit_state_var.def_rw("sel_start", &nk_edit_state::sel_start);
    nk_edit_state_var.def_rw("sel_end", &nk_edit_state::sel_end);
    nk_edit_state_var.def_rw("scrollbar", &nk_edit_state::scrollbar);
    nk_edit_state_var.def_rw("mode", &nk_edit_state::mode);
    nk_edit_state_var.def_rw("single_line", &nk_edit_state::single_line);

    nk_property_state_var.def_rw("prev", &nk_property_state::prev);
    nk_property_state_var.def_rw("length", &nk_property_state::length);
    nk_property_state_var.def_rw("cursor", &nk_property_state::cursor);
    nk_property_state_var.def_rw("select_start", &nk_property_state::select_start);
    nk_property_state_var.def_rw("select_end", &nk_property_state::select_end);
    nk_property_state_var.def_rw("name", &nk_property_state::name);
    nk_property_state_var.def_rw("seq", &nk_property_state::seq);
    nk_property_state_var.def_rw("old", &nk_property_state::old);
    nk_property_state_var.def_rw("state", &nk_property_state::state);
    nk_property_state_var.def_rw("prev_state", &nk_property_state::prev_state);
    nk_property_state_var.def_rw("prev_name", &nk_property_state::prev_name);
    nk_property_state_var.def_rw("prev_length", &nk_property_state::prev_length);

    nk_window_var.def_rw("seq", &nk_window::seq);
    nk_window_var.def_rw("name", &nk_window::name);
    nk_window_var.def_rw("flags", &nk_window::flags);
    nk_window_var.def_rw("bounds", &nk_window::bounds);
    nk_window_var.def_rw("scrollbar", &nk_window::scrollbar);
    nk_window_var.def_rw("buffer", &nk_window::buffer);
    nk_window_var.def_rw("scrollbar_hiding_timer", &nk_window::scrollbar_hiding_timer);
    nk_window_var.def_rw("property", &nk_window::property);
    nk_window_var.def_rw("popup", &nk_window::popup);
    nk_window_var.def_rw("edit", &nk_window::edit);
    nk_window_var.def_rw("scrolled", &nk_window::scrolled);
    nk_window_var.def_rw("widgets_disabled", &nk_window::widgets_disabled);
    nk_window_var.def_rw("table_count", &nk_window::table_count);

    nk_config_stack_style_item_element_var.def_rw("old_value", &nk_config_stack_style_item_element::old_value);

    nk_config_stack_float_element_var.def_rw("old_value", &nk_config_stack_float_element::old_value);

    nk_config_stack_vec2_element_var.def_rw("old_value", &nk_config_stack_vec2_element::old_value);

    nk_config_stack_flags_element_var.def_rw("old_value", &nk_config_stack_flags_element::old_value);

    nk_config_stack_color_element_var.def_rw("old_value", &nk_config_stack_color_element::old_value);


    nk_config_stack_button_behavior_element_var.def_rw("old_value", &nk_config_stack_button_behavior_element::old_value);

    nk_config_stack_style_item_var.def_rw("head", &nk_config_stack_style_item::head);

    nk_config_stack_float_var.def_rw("head", &nk_config_stack_float::head);

    nk_config_stack_vec2_var.def_rw("head", &nk_config_stack_vec2::head);

    nk_config_stack_flags_var.def_rw("head", &nk_config_stack_flags::head);

    nk_config_stack_color_var.def_rw("head", &nk_config_stack_color::head);

    nk_config_stack_user_font_var.def_rw("head", &nk_config_stack_user_font::head);

    nk_config_stack_button_behavior_var.def_rw("head", &nk_config_stack_button_behavior::head);

    nk_configuration_stacks_var.def_rw("style_items", &nk_configuration_stacks::style_items);
    nk_configuration_stacks_var.def_rw("floats", &nk_configuration_stacks::floats);
    nk_configuration_stacks_var.def_rw("vectors", &nk_configuration_stacks::vectors);
    nk_configuration_stacks_var.def_rw("flags", &nk_configuration_stacks::flags);
    nk_configuration_stacks_var.def_rw("colors", &nk_configuration_stacks::colors);
    nk_configuration_stacks_var.def_rw("fonts", &nk_configuration_stacks::fonts);
    nk_configuration_stacks_var.def_rw("button_behaviors", &nk_configuration_stacks::button_behaviors);

    nk_table_var.def_rw("seq", &nk_table::seq);
    nk_table_var.def_rw("size", &nk_table::size);

    nk_page_element_var.def_rw("data", &nk_page_element::data);

    nk_page_var.def_rw("size", &nk_page::size);

    nk_context_var.def_rw("input", &nk_context::input);
    nk_context_var.def_rw("style", &nk_context::style);
    nk_context_var.def_rw("memory", &nk_context::memory);
    nk_context_var.def_rw("clip", &nk_context::clip);
    nk_context_var.def_rw("last_widget_state", &nk_context::last_widget_state);
    nk_context_var.def_rw("button_behavior", &nk_context::button_behavior);
    nk_context_var.def_rw("stacks", &nk_context::stacks);
    nk_context_var.def_rw("delta_time_seconds", &nk_context::delta_time_seconds);
    nk_context_var.def_rw("draw_list", &nk_context::draw_list);
    nk_context_var.def_rw("text_edit", &nk_context::text_edit);
    nk_context_var.def_rw("overlay", &nk_context::overlay);
    nk_context_var.def_rw("build", &nk_context::build);
    nk_context_var.def_rw("use_pool", &nk_context::use_pool);
    nk_context_var.def_rw("pool", &nk_context::pool);
    nk_context_var.def_rw("count", &nk_context::count);
    nk_context_var.def_rw("seq", &nk_context::seq);

    m.def("mnk_init_default", &nk_init_default,"extern nk_bool nk_init_default(struct nk_context*, const struct nk_user_font*);");

    m.def("mnk_init_fixed", &nk_init_fixed,"extern nk_bool nk_init_fixed(struct nk_context*, void *memory, nk_size size, const struct nk_user_font*);");

    m.def("mnk_init_custom", &nk_init_custom,"extern nk_bool nk_init_custom(struct nk_context*, struct nk_buffer *cmds, struct nk_buffer *pool, const struct nk_user_font*);");

    m.def("mnk_clear", &nk_clear,"extern void nk_clear(struct nk_context*);");

    m.def("mnk_free", &nk_free,"extern void nk_free(struct nk_context*);");

    m.def("mnk_input_begin", &nk_input_begin,"extern void nk_input_begin(struct nk_context*);");

    m.def("mnk_input_motion", &nk_input_motion,"extern void nk_input_motion(struct nk_context*, int x, int y);");

    m.def("mnk_input_key", &nk_input_key,"extern void nk_input_key(struct nk_context*, enum nk_keys, nk_bool down);");

    m.def("mnk_input_button", &nk_input_button,"extern void nk_input_button(struct nk_context*, enum nk_buttons, int x, int y, nk_bool down);");

    m.def("mnk_input_scroll", &nk_input_scroll,"extern void nk_input_scroll(struct nk_context*, struct nk_vec2 val);");

    m.def("mnk_input_char", &nk_input_char,"extern void nk_input_char(struct nk_context*, char);");

    m.def("mnk_input_glyph", &nk_input_glyph,"extern void nk_input_glyph(struct nk_context*, const nk_glyph);");

    m.def("mnk_input_unicode", &nk_input_unicode,"extern void nk_input_unicode(struct nk_context*, nk_rune);");

    m.def("mnk_input_end", &nk_input_end,"extern void nk_input_end(struct nk_context*);");

    m.def("mnk_convert", &nk_convert,"extern nk_flags nk_convert(struct nk_context*, struct nk_buffer *cmds, struct nk_buffer *vertices, struct nk_buffer *elements, const struct nk_convert_config*);");

    m.def("mnk_begin", &nk_begin,"extern nk_bool nk_begin(struct nk_context *ctx, const char *title, struct nk_rect bounds, nk_flags flags);");

    m.def("mnk_begin_titled", &nk_begin_titled,"extern nk_bool nk_begin_titled(struct nk_context *ctx, const char *name, const char *title, struct nk_rect bounds, nk_flags flags);");

    m.def("mnk_end", &nk_end,"extern void nk_end(struct nk_context *ctx);");

    m.def("mnk_window_get_bounds", &nk_window_get_bounds,"extern struct nk_rect nk_window_get_bounds(const struct nk_context *ctx);");

    m.def("mnk_window_get_position", &nk_window_get_position,"extern struct nk_vec2 nk_window_get_position(const struct nk_context *ctx);");

    m.def("mnk_window_get_size", &nk_window_get_size,"extern struct nk_vec2 nk_window_get_size(const struct nk_context *ctx);");

    m.def("mnk_window_get_width", &nk_window_get_width,"extern float nk_window_get_width(const struct nk_context *ctx);");

    m.def("mnk_window_get_height", &nk_window_get_height,"extern float nk_window_get_height(const struct nk_context* ctx);");

    m.def("mnk_window_get_panel", &nk_window_get_panel, nb::rv_policy::reference,"extern struct nk_panel* nk_window_get_panel(const struct nk_context* ctx);");

    m.def("mnk_window_get_content_region", &nk_window_get_content_region,"extern struct nk_rect nk_window_get_content_region(const struct nk_context* ctx);");

    m.def("mnk_window_get_content_region_min", &nk_window_get_content_region_min,"extern struct nk_vec2 nk_window_get_content_region_min(const struct nk_context *ctx);");

    m.def("mnk_window_get_content_region_max", &nk_window_get_content_region_max,"extern struct nk_vec2 nk_window_get_content_region_max(const struct nk_context *ctx);");

    m.def("mnk_window_get_content_region_size", &nk_window_get_content_region_size,"extern struct nk_vec2 nk_window_get_content_region_size(const struct nk_context *ctx);");

    m.def("mnk_window_get_canvas", &nk_window_get_canvas, nb::rv_policy::reference,"extern struct nk_command_buffer* nk_window_get_canvas(const struct nk_context* ctx);");

    m.def("mnk_window_get_scroll", &nk_window_get_scroll,"extern void nk_window_get_scroll(const struct nk_context *ctx, nk_uint *offset_x, nk_uint *offset_y);");

    m.def("mnk_window_has_focus", &nk_window_has_focus,"extern nk_bool nk_window_has_focus(const struct nk_context *ctx);");

    m.def("mnk_window_is_hovered", &nk_window_is_hovered,"extern nk_bool nk_window_is_hovered(const struct nk_context *ctx);");

    m.def("mnk_window_is_collapsed", &nk_window_is_collapsed,"extern nk_bool nk_window_is_collapsed(const struct nk_context *ctx, const char *name);");

    m.def("mnk_window_is_closed", &nk_window_is_closed,"extern nk_bool nk_window_is_closed(const struct nk_context *ctx, const char* name);");

    m.def("mnk_window_is_hidden", &nk_window_is_hidden,"extern nk_bool nk_window_is_hidden(const struct nk_context *ctx, const char* name);");

    m.def("mnk_window_is_active", &nk_window_is_active,"extern nk_bool nk_window_is_active(const struct nk_context *ctx, const char* name);");

    m.def("mnk_window_is_any_hovered", &nk_window_is_any_hovered,"extern nk_bool nk_window_is_any_hovered(const struct nk_context *ctx);");

    m.def("mnk_item_is_any_active", &nk_item_is_any_active,"extern nk_bool nk_item_is_any_active(const struct nk_context *ctx);");

    m.def("mnk_window_set_bounds", &nk_window_set_bounds,"extern void nk_window_set_bounds(struct nk_context *ctx, const char *name, struct nk_rect bounds);");

    m.def("mnk_window_set_position", &nk_window_set_position,"extern void nk_window_set_position(struct nk_context *ctx, const char *name, struct nk_vec2 pos);");

    m.def("mnk_window_set_size", &nk_window_set_size,"extern void nk_window_set_size(struct nk_context *ctx, const char *name, struct nk_vec2 size);");

    m.def("mnk_window_set_focus", &nk_window_set_focus,"extern void nk_window_set_focus(struct nk_context *ctx, const char *name);");

    m.def("mnk_window_set_scroll", &nk_window_set_scroll,"extern void nk_window_set_scroll(struct nk_context *ctx, nk_uint offset_x, nk_uint offset_y);");

    m.def("mnk_window_close", &nk_window_close,"extern void nk_window_close(struct nk_context *ctx, const char *name);");

    m.def("mnk_window_collapse", &nk_window_collapse,"extern void nk_window_collapse(struct nk_context *ctx, const char *name, enum nk_collapse_states state);");

    m.def("mnk_window_collapse_if", &nk_window_collapse_if,"extern void nk_window_collapse_if(struct nk_context *ctx, const char *name, enum nk_collapse_states state, int cond);");

    m.def("mnk_window_show", &nk_window_show,"extern void nk_window_show(struct nk_context *ctx, const char *name, enum nk_show_states state);");

    m.def("mnk_window_show_if", &nk_window_show_if,"extern void nk_window_show_if(struct nk_context *ctx, const char *name, enum nk_show_states state, int cond);");

    m.def("mnk_rule_horizontal", &nk_rule_horizontal,"extern void nk_rule_horizontal(struct nk_context *ctx, struct nk_color color, nk_bool rounding);");

    m.def("mnk_layout_set_min_row_height", &nk_layout_set_min_row_height,"extern void nk_layout_set_min_row_height(struct nk_context*, float height);");

    m.def("mnk_layout_reset_min_row_height", &nk_layout_reset_min_row_height,"extern void nk_layout_reset_min_row_height(struct nk_context*);");

    m.def("mnk_layout_widget_bounds", &nk_layout_widget_bounds,"extern struct nk_rect nk_layout_widget_bounds(const struct nk_context *ctx);");

    m.def("mnk_layout_ratio_from_pixel", &nk_layout_ratio_from_pixel,"extern float nk_layout_ratio_from_pixel(const struct nk_context *ctx, float pixel_width);");

    m.def("mnk_layout_row_dynamic", &nk_layout_row_dynamic,"extern void nk_layout_row_dynamic(struct nk_context *ctx, float height, int cols);");

    m.def("mnk_layout_row_static", &nk_layout_row_static,"extern void nk_layout_row_static(struct nk_context *ctx, float height, int item_width, int cols);");

    m.def("mnk_layout_row_begin", &nk_layout_row_begin,"extern void nk_layout_row_begin(struct nk_context *ctx, enum nk_layout_format fmt, float row_height, int cols);");

    m.def("mnk_layout_row_push", &nk_layout_row_push,"extern void nk_layout_row_push(struct nk_context*, float value);");

    m.def("mnk_layout_row_end", &nk_layout_row_end,"extern void nk_layout_row_end(struct nk_context*);");

    m.def("mnk_layout_row", &nk_layout_row,"extern void nk_layout_row(struct nk_context*, enum nk_layout_format, float height, int cols, const float *ratio);");

    m.def("mnk_layout_row_template_begin", &nk_layout_row_template_begin,"extern void nk_layout_row_template_begin(struct nk_context*, float row_height);");

    m.def("mnk_layout_row_template_push_dynamic", &nk_layout_row_template_push_dynamic,"extern void nk_layout_row_template_push_dynamic(struct nk_context*);");

    m.def("mnk_layout_row_template_push_variable", &nk_layout_row_template_push_variable,"extern void nk_layout_row_template_push_variable(struct nk_context*, float min_width);");

    m.def("mnk_layout_row_template_push_static", &nk_layout_row_template_push_static,"extern void nk_layout_row_template_push_static(struct nk_context*, float width);");

    m.def("mnk_layout_row_template_end", &nk_layout_row_template_end,"extern void nk_layout_row_template_end(struct nk_context*);");

    m.def("mnk_layout_space_begin", &nk_layout_space_begin,"extern void nk_layout_space_begin(struct nk_context*, enum nk_layout_format, float height, int widget_count);");

    m.def("mnk_layout_space_push", &nk_layout_space_push,"extern void nk_layout_space_push(struct nk_context*, struct nk_rect bounds);");

    m.def("mnk_layout_space_end", &nk_layout_space_end,"extern void nk_layout_space_end(struct nk_context*);");

    m.def("mnk_layout_space_bounds", &nk_layout_space_bounds,"extern struct nk_rect nk_layout_space_bounds(const struct nk_context *ctx);");

    m.def("mnk_layout_space_to_screen", &nk_layout_space_to_screen,"extern struct nk_vec2 nk_layout_space_to_screen(const struct nk_context* ctx, struct nk_vec2 vec);");

    m.def("mnk_layout_space_to_local", &nk_layout_space_to_local,"extern struct nk_vec2 nk_layout_space_to_local(const struct nk_context *ctx, struct nk_vec2 vec);");

    m.def("mnk_layout_space_rect_to_screen", &nk_layout_space_rect_to_screen,"extern struct nk_rect nk_layout_space_rect_to_screen(const struct nk_context *ctx, struct nk_rect bounds);");

    m.def("mnk_layout_space_rect_to_local", &nk_layout_space_rect_to_local,"extern struct nk_rect nk_layout_space_rect_to_local(const struct nk_context *ctx, struct nk_rect bounds);");

    m.def("mnk_spacer", &nk_spacer,"extern void nk_spacer(struct nk_context *ctx);");

    m.def("mnk_group_begin", &nk_group_begin,"extern nk_bool nk_group_begin(struct nk_context*, const char *title, nk_flags);");

    m.def("mnk_group_begin_titled", &nk_group_begin_titled,"extern nk_bool nk_group_begin_titled(struct nk_context*, const char *name, const char *title, nk_flags);");

    m.def("mnk_group_end", &nk_group_end,"extern void nk_group_end(struct nk_context*);");

    m.def("mnk_group_scrolled_offset_begin", &nk_group_scrolled_offset_begin,"extern nk_bool nk_group_scrolled_offset_begin(struct nk_context*, nk_uint *x_offset, nk_uint *y_offset, const char *title, nk_flags flags);");

    m.def("mnk_group_scrolled_begin", &nk_group_scrolled_begin,"extern nk_bool nk_group_scrolled_begin(struct nk_context*, struct nk_scroll *off, const char *title, nk_flags);");

    m.def("mnk_group_scrolled_end", &nk_group_scrolled_end,"extern void nk_group_scrolled_end(struct nk_context*);");

    m.def("mnk_group_get_scroll", &nk_group_get_scroll,"extern void nk_group_get_scroll(struct nk_context*, const char *id, nk_uint *x_offset, nk_uint *y_offset);");

    m.def("mnk_group_set_scroll", &nk_group_set_scroll,"extern void nk_group_set_scroll(struct nk_context*, const char *id, nk_uint x_offset, nk_uint y_offset);");

    m.def("mnk_tree_push_hashed", &nk_tree_push_hashed,"extern nk_bool nk_tree_push_hashed(struct nk_context*, enum nk_tree_type, const char *title, enum nk_collapse_states initial_state, const char *hash, int len,int seed);");

    m.def("mnk_tree_image_push_hashed", &nk_tree_image_push_hashed,"extern nk_bool nk_tree_image_push_hashed(struct nk_context*, enum nk_tree_type, struct nk_image, const char *title, enum nk_collapse_states initial_state, const char *hash, int len,int seed);");

    m.def("mnk_tree_pop", &nk_tree_pop,"extern void nk_tree_pop(struct nk_context*);");

    m.def("mnk_tree_state_push", &nk_tree_state_push,"extern nk_bool nk_tree_state_push(struct nk_context*, enum nk_tree_type, const char *title, enum nk_collapse_states *state);");

    m.def("mnk_tree_state_image_push", &nk_tree_state_image_push,"extern nk_bool nk_tree_state_image_push(struct nk_context*, enum nk_tree_type, struct nk_image, const char *title, enum nk_collapse_states *state);");

    m.def("mnk_tree_state_pop", &nk_tree_state_pop,"extern void nk_tree_state_pop(struct nk_context*);");

    m.def("mnk_tree_element_push_hashed", &nk_tree_element_push_hashed,"extern nk_bool nk_tree_element_push_hashed(struct nk_context*, enum nk_tree_type, const char *title, enum nk_collapse_states initial_state, nk_bool *selected, const char *hash, int len, int seed);");

    m.def("mnk_tree_element_image_push_hashed", &nk_tree_element_image_push_hashed,"extern nk_bool nk_tree_element_image_push_hashed(struct nk_context*, enum nk_tree_type, struct nk_image, const char *title, enum nk_collapse_states initial_state, nk_bool *selected, const char *hash, int len,int seed);");

    m.def("mnk_tree_element_pop", &nk_tree_element_pop,"extern void nk_tree_element_pop(struct nk_context*);");

    m.def("mnk_list_view_begin", &nk_list_view_begin,"extern nk_bool nk_list_view_begin(struct nk_context*, struct nk_list_view *out, const char *id, nk_flags, int row_height, int row_count);");

    m.def("mnk_list_view_end", &nk_list_view_end,"extern void nk_list_view_end(struct nk_list_view*);");

    m.def("mnk_widget", &nk_widget,"extern enum nk_widget_layout_states nk_widget(struct nk_rect*, const struct nk_context*);");

    m.def("mnk_widget_fitting", &nk_widget_fitting,"extern enum nk_widget_layout_states nk_widget_fitting(struct nk_rect*, const struct nk_context*, struct nk_vec2);");

    m.def("mnk_widget_bounds", &nk_widget_bounds,"extern struct nk_rect nk_widget_bounds(const struct nk_context*);");

    m.def("mnk_widget_position", &nk_widget_position,"extern struct nk_vec2 nk_widget_position(const struct nk_context*);");

    m.def("mnk_widget_size", &nk_widget_size,"extern struct nk_vec2 nk_widget_size(const struct nk_context*);");

    m.def("mnk_widget_width", &nk_widget_width,"extern float nk_widget_width(const struct nk_context*);");

    m.def("mnk_widget_height", &nk_widget_height,"extern float nk_widget_height(const struct nk_context*);");

    m.def("mnk_widget_is_hovered", &nk_widget_is_hovered,"extern nk_bool nk_widget_is_hovered(const struct nk_context*);");

    m.def("mnk_widget_is_mouse_clicked", &nk_widget_is_mouse_clicked,"extern nk_bool nk_widget_is_mouse_clicked(const struct nk_context*, enum nk_buttons);");

    m.def("mnk_widget_has_mouse_click_down", &nk_widget_has_mouse_click_down,"extern nk_bool nk_widget_has_mouse_click_down(const struct nk_context*, enum nk_buttons, nk_bool down);");

    m.def("mnk_spacing", &nk_spacing,"extern void nk_spacing(struct nk_context*, int cols);");

    m.def("mnk_widget_disable_begin", &nk_widget_disable_begin,"extern void nk_widget_disable_begin(struct nk_context* ctx);");

    m.def("mnk_widget_disable_end", &nk_widget_disable_end,"extern void nk_widget_disable_end(struct nk_context* ctx);");

    m.def("mnk_text", &nk_text,"extern void nk_text(struct nk_context*, const char*, int, nk_flags);");

    m.def("mnk_text_colored", &nk_text_colored,"extern void nk_text_colored(struct nk_context*, const char*, int, nk_flags, struct nk_color);");

    m.def("mnk_text_wrap", &nk_text_wrap,"extern void nk_text_wrap(struct nk_context*, const char*, int);");

    m.def("mnk_text_wrap_colored", &nk_text_wrap_colored,"extern void nk_text_wrap_colored(struct nk_context*, const char*, int, struct nk_color);");

    m.def("mnk_label", &nk_label,"extern void nk_label(struct nk_context*, const char*, nk_flags align);");

    m.def("mnk_label_colored", &nk_label_colored,"extern void nk_label_colored(struct nk_context*, const char*, nk_flags align, struct nk_color);");

    m.def("mnk_label_wrap", &nk_label_wrap,"extern void nk_label_wrap(struct nk_context*, const char*);");

    m.def("mnk_label_colored_wrap", &nk_label_colored_wrap,"extern void nk_label_colored_wrap(struct nk_context*, const char*, struct nk_color);");

    m.def("mnk_image", &nk_image,"extern void nk_image(struct nk_context*, struct nk_image);");

    m.def("mnk_image_color", &nk_image_color,"extern void nk_image_color(struct nk_context*, struct nk_image, struct nk_color);");

    m.def("mnk_value_bool", &nk_value_bool,"extern void nk_value_bool(struct nk_context*, const char *prefix, int);");

    m.def("mnk_value_int", &nk_value_int,"extern void nk_value_int(struct nk_context*, const char *prefix, int);");

    m.def("mnk_value_uint", &nk_value_uint,"extern void nk_value_uint(struct nk_context*, const char *prefix, unsigned int);");

    m.def("mnk_value_float", &nk_value_float,"extern void nk_value_float(struct nk_context*, const char *prefix, float);");

    m.def("mnk_value_color_byte", &nk_value_color_byte,"extern void nk_value_color_byte(struct nk_context*, const char *prefix, struct nk_color);");

    m.def("mnk_value_color_float", &nk_value_color_float,"extern void nk_value_color_float(struct nk_context*, const char *prefix, struct nk_color);");

    m.def("mnk_value_color_hex", &nk_value_color_hex,"extern void nk_value_color_hex(struct nk_context*, const char *prefix, struct nk_color);");

    m.def("mnk_button_text", &nk_button_text,"extern nk_bool nk_button_text(struct nk_context*, const char *title, int len);");

    m.def("mnk_button_label", &nk_button_label,"extern nk_bool nk_button_label(struct nk_context*, const char *title);");

    m.def("mnk_button_color", &nk_button_color,"extern nk_bool nk_button_color(struct nk_context*, struct nk_color);");

    m.def("mnk_button_symbol", &nk_button_symbol,"extern nk_bool nk_button_symbol(struct nk_context*, enum nk_symbol_type);");

    m.def("mnk_button_image", &nk_button_image,"extern nk_bool nk_button_image(struct nk_context*, struct nk_image img);");

    m.def("mnk_button_symbol_label", &nk_button_symbol_label,"extern nk_bool nk_button_symbol_label(struct nk_context*, enum nk_symbol_type, const char*, nk_flags text_alignment);");

    m.def("mnk_button_symbol_text", &nk_button_symbol_text,"extern nk_bool nk_button_symbol_text(struct nk_context*, enum nk_symbol_type, const char*, int, nk_flags alignment);");

    m.def("mnk_button_image_label", &nk_button_image_label,"extern nk_bool nk_button_image_label(struct nk_context*, struct nk_image img, const char*, nk_flags text_alignment);");

    m.def("mnk_button_image_text", &nk_button_image_text,"extern nk_bool nk_button_image_text(struct nk_context*, struct nk_image img, const char*, int, nk_flags alignment);");

    m.def("mnk_button_text_styled", &nk_button_text_styled,"extern nk_bool nk_button_text_styled(struct nk_context*, const struct nk_style_button*, const char *title, int len);");

    m.def("mnk_button_label_styled", &nk_button_label_styled,"extern nk_bool nk_button_label_styled(struct nk_context*, const struct nk_style_button*, const char *title);");

    m.def("mnk_button_symbol_styled", &nk_button_symbol_styled,"extern nk_bool nk_button_symbol_styled(struct nk_context*, const struct nk_style_button*, enum nk_symbol_type);");

    m.def("mnk_button_image_styled", &nk_button_image_styled,"extern nk_bool nk_button_image_styled(struct nk_context*, const struct nk_style_button*, struct nk_image img);");

    m.def("mnk_button_symbol_text_styled", &nk_button_symbol_text_styled,"extern nk_bool nk_button_symbol_text_styled(struct nk_context*,const struct nk_style_button*, enum nk_symbol_type, const char*, int, nk_flags alignment);");

    m.def("mnk_button_symbol_label_styled", &nk_button_symbol_label_styled,"extern nk_bool nk_button_symbol_label_styled(struct nk_context *ctx, const struct nk_style_button *style, enum nk_symbol_type symbol, const char *title, nk_flags align);");

    m.def("mnk_button_image_label_styled", &nk_button_image_label_styled,"extern nk_bool nk_button_image_label_styled(struct nk_context*,const struct nk_style_button*, struct nk_image img, const char*, nk_flags text_alignment);");

    m.def("mnk_button_image_text_styled", &nk_button_image_text_styled,"extern nk_bool nk_button_image_text_styled(struct nk_context*,const struct nk_style_button*, struct nk_image img, const char*, int, nk_flags alignment);");

    m.def("mnk_button_set_behavior", &nk_button_set_behavior,"extern void nk_button_set_behavior(struct nk_context*, enum nk_button_behavior);");

    m.def("mnk_button_push_behavior", &nk_button_push_behavior,"extern nk_bool nk_button_push_behavior(struct nk_context*, enum nk_button_behavior);");

    m.def("mnk_button_pop_behavior", &nk_button_pop_behavior,"extern nk_bool nk_button_pop_behavior(struct nk_context*);");

    m.def("mnk_check_label", &nk_check_label,"extern nk_bool nk_check_label(struct nk_context*, const char*, nk_bool active);");

    m.def("mnk_check_text", &nk_check_text,"extern nk_bool nk_check_text(struct nk_context*, const char*, int, nk_bool active);");

    m.def("mnk_check_text_align", &nk_check_text_align,"extern nk_bool nk_check_text_align(struct nk_context*, const char*, int, nk_bool active, nk_flags widget_alignment, nk_flags text_alignment);");

    m.def("mnk_check_flags_label", &nk_check_flags_label,"extern unsigned nk_check_flags_label(struct nk_context*, const char*, unsigned int flags, unsigned int value);");

    m.def("mnk_check_flags_text", &nk_check_flags_text,"extern unsigned nk_check_flags_text(struct nk_context*, const char*, int, unsigned int flags, unsigned int value);");

    m.def("mnk_checkbox_label", &nk_checkbox_label,"extern nk_bool nk_checkbox_label(struct nk_context*, const char*, nk_bool *active);");

    m.def("mnk_checkbox_label_align", &nk_checkbox_label_align,"extern nk_bool nk_checkbox_label_align(struct nk_context *ctx, const char *label, nk_bool *active, nk_flags widget_alignment, nk_flags text_alignment);");

    m.def("mnk_checkbox_text", &nk_checkbox_text,"extern nk_bool nk_checkbox_text(struct nk_context*, const char*, int, nk_bool *active);");

    m.def("mnk_checkbox_text_align", &nk_checkbox_text_align,"extern nk_bool nk_checkbox_text_align(struct nk_context *ctx, const char *text, int len, nk_bool *active, nk_flags widget_alignment, nk_flags text_alignment);");

    m.def("mnk_checkbox_flags_label", &nk_checkbox_flags_label,"extern nk_bool nk_checkbox_flags_label(struct nk_context*, const char*, unsigned int *flags, unsigned int value);");

    m.def("mnk_checkbox_flags_text", &nk_checkbox_flags_text,"extern nk_bool nk_checkbox_flags_text(struct nk_context*, const char*, int, unsigned int *flags, unsigned int value);");

    m.def("mnk_radio_label", &nk_radio_label,"extern nk_bool nk_radio_label(struct nk_context*, const char*, nk_bool *active);");

    m.def("mnk_radio_label_align", &nk_radio_label_align,"extern nk_bool nk_radio_label_align(struct nk_context *ctx, const char *label, nk_bool *active, nk_flags widget_alignment, nk_flags text_alignment);");

    m.def("mnk_radio_text", &nk_radio_text,"extern nk_bool nk_radio_text(struct nk_context*, const char*, int, nk_bool *active);");

    m.def("mnk_radio_text_align", &nk_radio_text_align,"extern nk_bool nk_radio_text_align(struct nk_context *ctx, const char *text, int len, nk_bool *active, nk_flags widget_alignment, nk_flags text_alignment);");

    m.def("mnk_option_label", &nk_option_label,"extern nk_bool nk_option_label(struct nk_context*, const char*, nk_bool active);");

    m.def("mnk_option_label_align", &nk_option_label_align,"extern nk_bool nk_option_label_align(struct nk_context *ctx, const char *label, nk_bool active, nk_flags widget_alignment, nk_flags text_alignment);");

    m.def("mnk_option_text", &nk_option_text,"extern nk_bool nk_option_text(struct nk_context*, const char*, int, nk_bool active);");

    m.def("mnk_option_text_align", &nk_option_text_align,"extern nk_bool nk_option_text_align(struct nk_context *ctx, const char *text, int len, nk_bool is_active, nk_flags widget_alignment, nk_flags text_alignment);");

    m.def("mnk_selectable_label", &nk_selectable_label,"extern nk_bool nk_selectable_label(struct nk_context*, const char*, nk_flags align, nk_bool *value);");

    m.def("mnk_selectable_text", &nk_selectable_text,"extern nk_bool nk_selectable_text(struct nk_context*, const char*, int, nk_flags align, nk_bool *value);");

    m.def("mnk_selectable_image_label", &nk_selectable_image_label,"extern nk_bool nk_selectable_image_label(struct nk_context*,struct nk_image, const char*, nk_flags align, nk_bool *value);");

    m.def("mnk_selectable_image_text", &nk_selectable_image_text,"extern nk_bool nk_selectable_image_text(struct nk_context*,struct nk_image, const char*, int, nk_flags align, nk_bool *value);");

    m.def("mnk_selectable_symbol_label", &nk_selectable_symbol_label,"extern nk_bool nk_selectable_symbol_label(struct nk_context*,enum nk_symbol_type, const char*, nk_flags align, nk_bool *value);");

    m.def("mnk_selectable_symbol_text", &nk_selectable_symbol_text,"extern nk_bool nk_selectable_symbol_text(struct nk_context*,enum nk_symbol_type, const char*, int, nk_flags align, nk_bool *value);");

    m.def("mnk_select_label", &nk_select_label,"extern nk_bool nk_select_label(struct nk_context*, const char*, nk_flags align, nk_bool value);");

    m.def("mnk_select_text", &nk_select_text,"extern nk_bool nk_select_text(struct nk_context*, const char*, int, nk_flags align, nk_bool value);");

    m.def("mnk_select_image_label", &nk_select_image_label,"extern nk_bool nk_select_image_label(struct nk_context*, struct nk_image,const char*, nk_flags align, nk_bool value);");

    m.def("mnk_select_image_text", &nk_select_image_text,"extern nk_bool nk_select_image_text(struct nk_context*, struct nk_image,const char*, int, nk_flags align, nk_bool value);");

    m.def("mnk_select_symbol_label", &nk_select_symbol_label,"extern nk_bool nk_select_symbol_label(struct nk_context*,enum nk_symbol_type, const char*, nk_flags align, nk_bool value);");

    m.def("mnk_select_symbol_text", &nk_select_symbol_text,"extern nk_bool nk_select_symbol_text(struct nk_context*,enum nk_symbol_type, const char*, int, nk_flags align, nk_bool value);");

    m.def("mnk_slide_float", &nk_slide_float,"extern float nk_slide_float(struct nk_context*, float min, float val, float max, float step);");

    m.def("mnk_slide_int", &nk_slide_int,"extern int nk_slide_int(struct nk_context*, int min, int val, int max, int step);");

    m.def("mnk_slider_float", &nk_slider_float,"extern nk_bool nk_slider_float(struct nk_context*, float min, float *val, float max, float step);");

    m.def("mnk_slider_int", &nk_slider_int,"extern nk_bool nk_slider_int(struct nk_context*, int min, int *val, int max, int step);");

    m.def("mnk_knob_float", &nk_knob_float,"extern nk_bool nk_knob_float(struct nk_context*, float min, float *val, float max, float step, enum nk_heading zero_direction, float dead_zone_degrees);");

    m.def("mnk_knob_int", &nk_knob_int,"extern nk_bool nk_knob_int(struct nk_context*, int min, int *val, int max, int step, enum nk_heading zero_direction, float dead_zone_degrees);");

    m.def("mnk_progress", &nk_progress,"extern nk_bool nk_progress(struct nk_context*, nk_size *cur, nk_size max, nk_bool modifyable);");

    m.def("mnk_prog", &nk_prog,"extern nk_size nk_prog(struct nk_context*, nk_size cur, nk_size max, nk_bool modifyable);");

    m.def("mnk_color_picker", &nk_color_picker,"extern struct nk_colorf nk_color_picker(struct nk_context*, struct nk_colorf, enum nk_color_format);");

    m.def("mnk_color_pick", &nk_color_pick,"extern nk_bool nk_color_pick(struct nk_context*, struct nk_colorf*, enum nk_color_format);");

    m.def("mnk_property_int", &nk_property_int,"extern nk_bool nk_property_int(struct nk_context*, const char *name, int min, int *val, int max, int step, float inc_per_pixel);");

    m.def("mnk_property_float", &nk_property_float,"extern nk_bool nk_property_float(struct nk_context*, const char *name, float min, float *val, float max, float step, float inc_per_pixel);");

    m.def("mnk_property_double", &nk_property_double,"extern nk_bool nk_property_double(struct nk_context*, const char *name, double min, double *val, double max, double step, float inc_per_pixel);");

    m.def("mnk_propertyi", &nk_propertyi,"extern int nk_propertyi(struct nk_context*, const char *name, int min, int val, int max, int step, float inc_per_pixel);");

    m.def("mnk_propertyf", &nk_propertyf,"extern float nk_propertyf(struct nk_context*, const char *name, float min, float val, float max, float step, float inc_per_pixel);");

    m.def("mnk_propertyd", &nk_propertyd,"extern double nk_propertyd(struct nk_context*, const char *name, double min, double val, double max, double step, float inc_per_pixel);");

    m.def("mnk_edit_focus", &nk_edit_focus,"extern void nk_edit_focus(struct nk_context*, nk_flags flags);");

    m.def("mnk_edit_unfocus", &nk_edit_unfocus,"extern void nk_edit_unfocus(struct nk_context*);");

    m.def("mnk_chart_begin", &nk_chart_begin,"extern nk_bool nk_chart_begin(struct nk_context*, enum nk_chart_type, int num, float min, float max);");

    m.def("mnk_chart_begin_colored", &nk_chart_begin_colored,"extern nk_bool nk_chart_begin_colored(struct nk_context*, enum nk_chart_type, struct nk_color, struct nk_color active, int num, float min, float max);");

    m.def("mnk_chart_add_slot", &nk_chart_add_slot,"extern void nk_chart_add_slot(struct nk_context *ctx, const enum nk_chart_type, int count, float min_value, float max_value);");

    m.def("mnk_chart_add_slot_colored", &nk_chart_add_slot_colored,"extern void nk_chart_add_slot_colored(struct nk_context *ctx, const enum nk_chart_type, struct nk_color, struct nk_color active, int count, float min_value, float max_value);");

    m.def("mnk_chart_push", &nk_chart_push,"extern nk_flags nk_chart_push(struct nk_context*, float);");

    m.def("mnk_chart_push_slot", &nk_chart_push_slot,"extern nk_flags nk_chart_push_slot(struct nk_context*, float, int);");

    m.def("mnk_chart_end", &nk_chart_end,"extern void nk_chart_end(struct nk_context*);");

    m.def("mnk_plot", &nk_plot,"extern void nk_plot(struct nk_context*, enum nk_chart_type, const float *values, int count, int offset);");

    m.def("mnk_popup_begin", &nk_popup_begin,"extern nk_bool nk_popup_begin(struct nk_context*, enum nk_popup_type, const char*, nk_flags, struct nk_rect bounds);");

    m.def("mnk_popup_close", &nk_popup_close,"extern void nk_popup_close(struct nk_context*);");

    m.def("mnk_popup_end", &nk_popup_end,"extern void nk_popup_end(struct nk_context*);");

    m.def("mnk_popup_get_scroll", &nk_popup_get_scroll,"extern void nk_popup_get_scroll(const struct nk_context*, nk_uint *offset_x, nk_uint *offset_y);");

    m.def("mnk_popup_set_scroll", &nk_popup_set_scroll,"extern void nk_popup_set_scroll(struct nk_context*, nk_uint offset_x, nk_uint offset_y);");

    m.def("mnk_combo_separator", &nk_combo_separator,"extern int nk_combo_separator(struct nk_context*, const char *items_separated_by_separator, int separator, int selected, int count, int item_height, struct nk_vec2 size);");

    m.def("mnk_combo_string", &nk_combo_string,"extern int nk_combo_string(struct nk_context*, const char *items_separated_by_zeros, int selected, int count, int item_height, struct nk_vec2 size);");

    m.def("mnk_combobox_string", &nk_combobox_string,"extern nk_bool nk_combobox_string(struct nk_context*, const char *items_separated_by_zeros, int *selected, int count, int item_height, struct nk_vec2 size);");

    m.def("mnk_combobox_separator", &nk_combobox_separator,"extern nk_bool nk_combobox_separator(struct nk_context*, const char *items_separated_by_separator, int separator, int *selected, int count, int item_height, struct nk_vec2 size);");

    m.def("mnk_combo_begin_text", &nk_combo_begin_text,"extern nk_bool nk_combo_begin_text(struct nk_context*, const char *selected, int, struct nk_vec2 size);");

    m.def("mnk_combo_begin_label", &nk_combo_begin_label,"extern nk_bool nk_combo_begin_label(struct nk_context*, const char *selected, struct nk_vec2 size);");

    m.def("mnk_combo_begin_color", &nk_combo_begin_color,"extern nk_bool nk_combo_begin_color(struct nk_context*, struct nk_color color, struct nk_vec2 size);");

    m.def("mnk_combo_begin_symbol", &nk_combo_begin_symbol,"extern nk_bool nk_combo_begin_symbol(struct nk_context*, enum nk_symbol_type, struct nk_vec2 size);");

    m.def("mnk_combo_begin_symbol_label", &nk_combo_begin_symbol_label,"extern nk_bool nk_combo_begin_symbol_label(struct nk_context*, const char *selected, enum nk_symbol_type, struct nk_vec2 size);");

    m.def("mnk_combo_begin_symbol_text", &nk_combo_begin_symbol_text,"extern nk_bool nk_combo_begin_symbol_text(struct nk_context*, const char *selected, int, enum nk_symbol_type, struct nk_vec2 size);");

    m.def("mnk_combo_begin_image", &nk_combo_begin_image,"extern nk_bool nk_combo_begin_image(struct nk_context*, struct nk_image img, struct nk_vec2 size);");

    m.def("mnk_combo_begin_image_label", &nk_combo_begin_image_label,"extern nk_bool nk_combo_begin_image_label(struct nk_context*, const char *selected, struct nk_image, struct nk_vec2 size);");

    m.def("mnk_combo_begin_image_text", &nk_combo_begin_image_text,"extern nk_bool nk_combo_begin_image_text(struct nk_context*, const char *selected, int, struct nk_image, struct nk_vec2 size);");

    m.def("mnk_combo_item_label", &nk_combo_item_label,"extern nk_bool nk_combo_item_label(struct nk_context*, const char*, nk_flags alignment);");

    m.def("mnk_combo_item_text", &nk_combo_item_text,"extern nk_bool nk_combo_item_text(struct nk_context*, const char*,int, nk_flags alignment);");

    m.def("mnk_combo_item_image_label", &nk_combo_item_image_label,"extern nk_bool nk_combo_item_image_label(struct nk_context*, struct nk_image, const char*, nk_flags alignment);");

    m.def("mnk_combo_item_image_text", &nk_combo_item_image_text,"extern nk_bool nk_combo_item_image_text(struct nk_context*, struct nk_image, const char*, int,nk_flags alignment);");

    m.def("mnk_combo_item_symbol_label", &nk_combo_item_symbol_label,"extern nk_bool nk_combo_item_symbol_label(struct nk_context*, enum nk_symbol_type, const char*, nk_flags alignment);");

    m.def("mnk_combo_item_symbol_text", &nk_combo_item_symbol_text,"extern nk_bool nk_combo_item_symbol_text(struct nk_context*, enum nk_symbol_type, const char*, int, nk_flags alignment);");

    m.def("mnk_combo_close", &nk_combo_close,"extern void nk_combo_close(struct nk_context*);");

    m.def("mnk_combo_end", &nk_combo_end,"extern void nk_combo_end(struct nk_context*);");

    m.def("mnk_contextual_begin", &nk_contextual_begin,"extern nk_bool nk_contextual_begin(struct nk_context*, nk_flags, struct nk_vec2, struct nk_rect trigger_bounds);");

    m.def("mnk_contextual_item_text", &nk_contextual_item_text,"extern nk_bool nk_contextual_item_text(struct nk_context*, const char*, int,nk_flags align);");

    m.def("mnk_contextual_item_label", &nk_contextual_item_label,"extern nk_bool nk_contextual_item_label(struct nk_context*, const char*, nk_flags align);");

    m.def("mnk_contextual_item_image_label", &nk_contextual_item_image_label,"extern nk_bool nk_contextual_item_image_label(struct nk_context*, struct nk_image, const char*, nk_flags alignment);");

    m.def("mnk_contextual_item_image_text", &nk_contextual_item_image_text,"extern nk_bool nk_contextual_item_image_text(struct nk_context*, struct nk_image, const char*, int len, nk_flags alignment);");

    m.def("mnk_contextual_item_symbol_label", &nk_contextual_item_symbol_label,"extern nk_bool nk_contextual_item_symbol_label(struct nk_context*, enum nk_symbol_type, const char*, nk_flags alignment);");

    m.def("mnk_contextual_item_symbol_text", &nk_contextual_item_symbol_text,"extern nk_bool nk_contextual_item_symbol_text(struct nk_context*, enum nk_symbol_type, const char*, int, nk_flags alignment);");

    m.def("mnk_contextual_close", &nk_contextual_close,"extern void nk_contextual_close(struct nk_context*);");

    m.def("mnk_contextual_end", &nk_contextual_end,"extern void nk_contextual_end(struct nk_context*);");

    m.def("mnk_tooltip", &nk_tooltip,"extern void nk_tooltip(struct nk_context*, const char*);");

    m.def("mnk_tooltip_offset", &nk_tooltip_offset,"extern void nk_tooltip_offset(struct nk_context *ctx, const char *text, enum nk_tooltip_pos position, struct nk_vec2 offset);");

    m.def("mnk_tooltip_begin", &nk_tooltip_begin,"extern nk_bool nk_tooltip_begin(struct nk_context*, float width);");

    m.def("mnk_tooltip_begin_offset", &nk_tooltip_begin_offset,"extern nk_bool nk_tooltip_begin_offset(struct nk_context*, float, enum nk_tooltip_pos, struct nk_vec2);");

    m.def("mnk_tooltip_end", &nk_tooltip_end,"extern void nk_tooltip_end(struct nk_context*);");

    m.def("mnk_menubar_begin", &nk_menubar_begin,"extern void nk_menubar_begin(struct nk_context*);");

    m.def("mnk_menubar_end", &nk_menubar_end,"extern void nk_menubar_end(struct nk_context*);");

    m.def("mnk_menu_begin_text", &nk_menu_begin_text,"extern nk_bool nk_menu_begin_text(struct nk_context*, const char* title, int title_len, nk_flags align, struct nk_vec2 size);");

    m.def("mnk_menu_begin_label", &nk_menu_begin_label,"extern nk_bool nk_menu_begin_label(struct nk_context*, const char*, nk_flags align, struct nk_vec2 size);");

    m.def("mnk_menu_begin_image", &nk_menu_begin_image,"extern nk_bool nk_menu_begin_image(struct nk_context*, const char*, struct nk_image, struct nk_vec2 size);");

    m.def("mnk_menu_begin_image_text", &nk_menu_begin_image_text,"extern nk_bool nk_menu_begin_image_text(struct nk_context*, const char*, int,nk_flags align,struct nk_image, struct nk_vec2 size);");

    m.def("mnk_menu_begin_image_label", &nk_menu_begin_image_label,"extern nk_bool nk_menu_begin_image_label(struct nk_context*, const char*, nk_flags align,struct nk_image, struct nk_vec2 size);");

    m.def("mnk_menu_begin_symbol", &nk_menu_begin_symbol,"extern nk_bool nk_menu_begin_symbol(struct nk_context*, const char*, enum nk_symbol_type, struct nk_vec2 size);");

    m.def("mnk_menu_begin_symbol_text", &nk_menu_begin_symbol_text,"extern nk_bool nk_menu_begin_symbol_text(struct nk_context*, const char*, int,nk_flags align,enum nk_symbol_type, struct nk_vec2 size);");

    m.def("mnk_menu_begin_symbol_label", &nk_menu_begin_symbol_label,"extern nk_bool nk_menu_begin_symbol_label(struct nk_context*, const char*, nk_flags align,enum nk_symbol_type, struct nk_vec2 size);");

    m.def("mnk_menu_item_text", &nk_menu_item_text,"extern nk_bool nk_menu_item_text(struct nk_context*, const char*, int,nk_flags align);");

    m.def("mnk_menu_item_label", &nk_menu_item_label,"extern nk_bool nk_menu_item_label(struct nk_context*, const char*, nk_flags alignment);");

    m.def("mnk_menu_item_image_label", &nk_menu_item_image_label,"extern nk_bool nk_menu_item_image_label(struct nk_context*, struct nk_image, const char*, nk_flags alignment);");

    m.def("mnk_menu_item_image_text", &nk_menu_item_image_text,"extern nk_bool nk_menu_item_image_text(struct nk_context*, struct nk_image, const char*, int len, nk_flags alignment);");

    m.def("mnk_menu_item_symbol_text", &nk_menu_item_symbol_text,"extern nk_bool nk_menu_item_symbol_text(struct nk_context*, enum nk_symbol_type, const char*, int, nk_flags alignment);");

    m.def("mnk_menu_item_symbol_label", &nk_menu_item_symbol_label,"extern nk_bool nk_menu_item_symbol_label(struct nk_context*, enum nk_symbol_type, const char*, nk_flags alignment);");

    m.def("mnk_menu_close", &nk_menu_close,"extern void nk_menu_close(struct nk_context*);");

    m.def("mnk_menu_end", &nk_menu_end,"extern void nk_menu_end(struct nk_context*);");

    m.def("mnk_style_default", &nk_style_default,"extern void nk_style_default(struct nk_context*);");

    m.def("mnk_style_from_table", &nk_style_from_table,"extern void nk_style_from_table(struct nk_context*, const struct nk_color*);");

    m.def("mnk_style_load_cursor", &nk_style_load_cursor,"extern void nk_style_load_cursor(struct nk_context*, enum nk_style_cursor, const struct nk_cursor*);");

    m.def("mnk_style_load_all_cursors", &nk_style_load_all_cursors,"extern void nk_style_load_all_cursors(struct nk_context*, const struct nk_cursor*);");

    m.def("mnk_style_get_color_by_name", &nk_style_get_color_by_name, nb::rv_policy::reference,"extern const char* nk_style_get_color_by_name(enum nk_style_colors);");

    m.def("mnk_style_set_font", &nk_style_set_font,"extern void nk_style_set_font(struct nk_context*, const struct nk_user_font*);");

    m.def("mnk_style_set_cursor", &nk_style_set_cursor,"extern nk_bool nk_style_set_cursor(struct nk_context*, enum nk_style_cursor);");

    m.def("mnk_style_show_cursor", &nk_style_show_cursor,"extern void nk_style_show_cursor(struct nk_context*);");

    m.def("mnk_style_hide_cursor", &nk_style_hide_cursor,"extern void nk_style_hide_cursor(struct nk_context*);");

    m.def("mnk_style_push_font", &nk_style_push_font,"extern nk_bool nk_style_push_font(struct nk_context*, const struct nk_user_font*);");

    m.def("mnk_style_push_float", &nk_style_push_float,"extern nk_bool nk_style_push_float(struct nk_context*, float*, float);");

    m.def("mnk_style_push_vec2", &nk_style_push_vec2,"extern nk_bool nk_style_push_vec2(struct nk_context*, struct nk_vec2*, struct nk_vec2);");

    m.def("mnk_style_push_style_item", &nk_style_push_style_item,"extern nk_bool nk_style_push_style_item(struct nk_context*, struct nk_style_item*, struct nk_style_item);");

    m.def("mnk_style_push_flags", &nk_style_push_flags,"extern nk_bool nk_style_push_flags(struct nk_context*, nk_flags*, nk_flags);");

    m.def("mnk_style_push_color", &nk_style_push_color,"extern nk_bool nk_style_push_color(struct nk_context*, struct nk_color*, struct nk_color);");

    m.def("mnk_style_pop_font", &nk_style_pop_font,"extern nk_bool nk_style_pop_font(struct nk_context*);");

    m.def("mnk_style_pop_float", &nk_style_pop_float,"extern nk_bool nk_style_pop_float(struct nk_context*);");

    m.def("mnk_style_pop_vec2", &nk_style_pop_vec2,"extern nk_bool nk_style_pop_vec2(struct nk_context*);");

    m.def("mnk_style_pop_style_item", &nk_style_pop_style_item,"extern nk_bool nk_style_pop_style_item(struct nk_context*);");

    m.def("mnk_style_pop_flags", &nk_style_pop_flags,"extern nk_bool nk_style_pop_flags(struct nk_context*);");

    m.def("mnk_style_pop_color", &nk_style_pop_color,"extern nk_bool nk_style_pop_color(struct nk_context*);");

    m.def("mnk_rgb", &nk_rgb,"extern struct nk_color nk_rgb(int r, int g, int b);");

    m.def("mnk_rgb_iv", &nk_rgb_iv,"extern struct nk_color nk_rgb_iv(const int *rgb);");

    m.def("mnk_rgb_bv", &nk_rgb_bv,"extern struct nk_color nk_rgb_bv(const nk_byte* rgb);");

    m.def("mnk_rgb_f", &nk_rgb_f,"extern struct nk_color nk_rgb_f(float r, float g, float b);");

    m.def("mnk_rgb_fv", &nk_rgb_fv,"extern struct nk_color nk_rgb_fv(const float *rgb);");

    m.def("mnk_rgb_cf", &nk_rgb_cf,"extern struct nk_color nk_rgb_cf(struct nk_colorf c);");

    m.def("mnk_rgb_hex", &nk_rgb_hex,"extern struct nk_color nk_rgb_hex(const char *rgb);");

    m.def("mnk_rgb_factor", &nk_rgb_factor,"extern struct nk_color nk_rgb_factor(struct nk_color col, float factor);");

    m.def("mnk_rgba", &nk_rgba,"extern struct nk_color nk_rgba(int r, int g, int b, int a);");

    m.def("mnk_rgba_u32", &nk_rgba_u32,"extern struct nk_color nk_rgba_u32(nk_uint);");

    m.def("mnk_rgba_iv", &nk_rgba_iv,"extern struct nk_color nk_rgba_iv(const int *rgba);");

    m.def("mnk_rgba_bv", &nk_rgba_bv,"extern struct nk_color nk_rgba_bv(const nk_byte *rgba);");

    m.def("mnk_rgba_f", &nk_rgba_f,"extern struct nk_color nk_rgba_f(float r, float g, float b, float a);");

    m.def("mnk_rgba_fv", &nk_rgba_fv,"extern struct nk_color nk_rgba_fv(const float *rgba);");

    m.def("mnk_rgba_cf", &nk_rgba_cf,"extern struct nk_color nk_rgba_cf(struct nk_colorf c);");

    m.def("mnk_rgba_hex", &nk_rgba_hex,"extern struct nk_color nk_rgba_hex(const char *rgb);");

    m.def("mnk_hsva_colorf", &nk_hsva_colorf,"extern struct nk_colorf nk_hsva_colorf(float h, float s, float v, float a);");

    m.def("mnk_hsva_colorfv", &nk_hsva_colorfv,"extern struct nk_colorf nk_hsva_colorfv(const float *c);");

    m.def("mnk_colorf_hsva_f", &nk_colorf_hsva_f,"extern void nk_colorf_hsva_f(float *out_h, float *out_s, float *out_v, float *out_a, struct nk_colorf in);");

    m.def("mnk_colorf_hsva_fv", &nk_colorf_hsva_fv,"extern void nk_colorf_hsva_fv(float *hsva, struct nk_colorf in);");

    m.def("mnk_hsv", &nk_hsv,"extern struct nk_color nk_hsv(int h, int s, int v);");

    m.def("mnk_hsv_iv", &nk_hsv_iv,"extern struct nk_color nk_hsv_iv(const int *hsv);");

    m.def("mnk_hsv_bv", &nk_hsv_bv,"extern struct nk_color nk_hsv_bv(const nk_byte *hsv);");

    m.def("mnk_hsv_f", &nk_hsv_f,"extern struct nk_color nk_hsv_f(float h, float s, float v);");

    m.def("mnk_hsv_fv", &nk_hsv_fv,"extern struct nk_color nk_hsv_fv(const float *hsv);");

    m.def("mnk_hsva", &nk_hsva,"extern struct nk_color nk_hsva(int h, int s, int v, int a);");

    m.def("mnk_hsva_iv", &nk_hsva_iv,"extern struct nk_color nk_hsva_iv(const int *hsva);");

    m.def("mnk_hsva_bv", &nk_hsva_bv,"extern struct nk_color nk_hsva_bv(const nk_byte *hsva);");

    m.def("mnk_hsva_f", &nk_hsva_f,"extern struct nk_color nk_hsva_f(float h, float s, float v, float a);");

    m.def("mnk_hsva_fv", &nk_hsva_fv,"extern struct nk_color nk_hsva_fv(const float *hsva);");

    m.def("mnk_color_f", &nk_color_f,"extern void nk_color_f(float *r, float *g, float *b, float *a, struct nk_color);");

    m.def("mnk_color_fv", &nk_color_fv,"extern void nk_color_fv(float *rgba_out, struct nk_color);");

    m.def("mnk_color_cf", &nk_color_cf,"extern struct nk_colorf nk_color_cf(struct nk_color);");

    m.def("mnk_color_d", &nk_color_d,"extern void nk_color_d(double *r, double *g, double *b, double *a, struct nk_color);");

    m.def("mnk_color_dv", &nk_color_dv,"extern void nk_color_dv(double *rgba_out, struct nk_color);");

    m.def("mnk_color_u32", &nk_color_u32,"extern nk_uint nk_color_u32(struct nk_color);");

    m.def("mnk_color_hsv_i", &nk_color_hsv_i,"extern void nk_color_hsv_i(int *out_h, int *out_s, int *out_v, struct nk_color);");

    m.def("mnk_color_hsv_b", &nk_color_hsv_b,"extern void nk_color_hsv_b(nk_byte *out_h, nk_byte *out_s, nk_byte *out_v, struct nk_color);");

    m.def("mnk_color_hsv_iv", &nk_color_hsv_iv,"extern void nk_color_hsv_iv(int *hsv_out, struct nk_color);");

    m.def("mnk_color_hsv_bv", &nk_color_hsv_bv,"extern void nk_color_hsv_bv(nk_byte *hsv_out, struct nk_color);");

    m.def("mnk_color_hsv_f", &nk_color_hsv_f,"extern void nk_color_hsv_f(float *out_h, float *out_s, float *out_v, struct nk_color);");

    m.def("mnk_color_hsv_fv", &nk_color_hsv_fv,"extern void nk_color_hsv_fv(float *hsv_out, struct nk_color);");

    m.def("mnk_color_hsva_i", &nk_color_hsva_i,"extern void nk_color_hsva_i(int *h, int *s, int *v, int *a, struct nk_color);");

    m.def("mnk_color_hsva_b", &nk_color_hsva_b,"extern void nk_color_hsva_b(nk_byte *h, nk_byte *s, nk_byte *v, nk_byte *a, struct nk_color);");

    m.def("mnk_color_hsva_iv", &nk_color_hsva_iv,"extern void nk_color_hsva_iv(int *hsva_out, struct nk_color);");

    m.def("mnk_color_hsva_bv", &nk_color_hsva_bv,"extern void nk_color_hsva_bv(nk_byte *hsva_out, struct nk_color);");

    m.def("mnk_color_hsva_f", &nk_color_hsva_f,"extern void nk_color_hsva_f(float *out_h, float *out_s, float *out_v, float *out_a, struct nk_color);");

    m.def("mnk_color_hsva_fv", &nk_color_hsva_fv,"extern void nk_color_hsva_fv(float *hsva_out, struct nk_color);");

    m.def("mnk_handle_ptr", &nk_handle_ptr,"extern nk_handle nk_handle_ptr(void*);");

    m.def("mnk_handle_id", &nk_handle_id,"extern nk_handle nk_handle_id(int);");

    m.def("mnk_image_handle", &nk_image_handle,"extern struct nk_image nk_image_handle(nk_handle);");

    m.def("mnk_image_ptr", &nk_image_ptr,"extern struct nk_image nk_image_ptr(void*);");

    m.def("mnk_image_id", &nk_image_id,"extern struct nk_image nk_image_id(int);");

    m.def("mnk_image_is_subimage", &nk_image_is_subimage,"extern nk_bool nk_image_is_subimage(const struct nk_image* img);");

    m.def("mnk_subimage_ptr", &nk_subimage_ptr,"extern struct nk_image nk_subimage_ptr(void*, nk_ushort w, nk_ushort h, struct nk_rect sub_region);");

    m.def("mnk_subimage_id", &nk_subimage_id,"extern struct nk_image nk_subimage_id(int, nk_ushort w, nk_ushort h, struct nk_rect sub_region);");

    m.def("mnk_subimage_handle", &nk_subimage_handle,"extern struct nk_image nk_subimage_handle(nk_handle, nk_ushort w, nk_ushort h, struct nk_rect sub_region);");

    m.def("mnk_nine_slice_handle", &nk_nine_slice_handle,"extern struct nk_nine_slice nk_nine_slice_handle(nk_handle, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b);");

    m.def("mnk_nine_slice_ptr", &nk_nine_slice_ptr,"extern struct nk_nine_slice nk_nine_slice_ptr(void*, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b);");

    m.def("mnk_nine_slice_id", &nk_nine_slice_id,"extern struct nk_nine_slice nk_nine_slice_id(int, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b);");

    m.def("mnk_nine_slice_is_sub9slice", &nk_nine_slice_is_sub9slice,"extern int nk_nine_slice_is_sub9slice(const struct nk_nine_slice* img);");

    m.def("mnk_sub9slice_ptr", &nk_sub9slice_ptr,"extern struct nk_nine_slice nk_sub9slice_ptr(void*, nk_ushort w, nk_ushort h, struct nk_rect sub_region, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b);");

    m.def("mnk_sub9slice_id", &nk_sub9slice_id,"extern struct nk_nine_slice nk_sub9slice_id(int, nk_ushort w, nk_ushort h, struct nk_rect sub_region, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b);");

    m.def("mnk_sub9slice_handle", &nk_sub9slice_handle,"extern struct nk_nine_slice nk_sub9slice_handle(nk_handle, nk_ushort w, nk_ushort h, struct nk_rect sub_region, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b);");

    m.def("mnk_murmur_hash", &nk_murmur_hash,"extern nk_hash nk_murmur_hash(const void *key, int len, nk_hash seed);");

    m.def("mnk_triangle_from_direction", &nk_triangle_from_direction,"extern void nk_triangle_from_direction(struct nk_vec2 *result, struct nk_rect r, float pad_x, float pad_y, enum nk_heading);");

    m.def("mnk_vec2", &nk_vec2,"extern struct nk_vec2 nk_vec2(float x, float y);");

    m.def("mnk_vec2i", &nk_vec2i,"extern struct nk_vec2 nk_vec2i(int x, int y);");

    m.def("mnk_vec2v", &nk_vec2v,"extern struct nk_vec2 nk_vec2v(const float *xy);");

    m.def("mnk_vec2iv", &nk_vec2iv,"extern struct nk_vec2 nk_vec2iv(const int *xy);");

    m.def("mnk_get_null_rect", &nk_get_null_rect,"extern struct nk_rect nk_get_null_rect(void);");

    m.def("mnk_rect", &nk_rect,"extern struct nk_rect nk_rect(float x, float y, float w, float h);");

    m.def("mnk_recti", &nk_recti,"extern struct nk_rect nk_recti(int x, int y, int w, int h);");

    m.def("mnk_recta", &nk_recta,"extern struct nk_rect nk_recta(struct nk_vec2 pos, struct nk_vec2 size);");

    m.def("mnk_rectv", &nk_rectv,"extern struct nk_rect nk_rectv(const float *xywh);");

    m.def("mnk_rectiv", &nk_rectiv,"extern struct nk_rect nk_rectiv(const int *xywh);");

    m.def("mnk_rect_pos", &nk_rect_pos,"extern struct nk_vec2 nk_rect_pos(struct nk_rect);");

    m.def("mnk_rect_size", &nk_rect_size,"extern struct nk_vec2 nk_rect_size(struct nk_rect);");

    m.def("mnk_strlen", &nk_strlen,"extern int nk_strlen(const char *str);");

    m.def("mnk_stricmp", &nk_stricmp,"extern int nk_stricmp(const char *s1, const char *s2);");

    m.def("mnk_stricmpn", &nk_stricmpn,"extern int nk_stricmpn(const char *s1, const char *s2, int n);");

    m.def("mnk_strfilter", &nk_strfilter,"extern int nk_strfilter(const char *text, const char *regexp);");

    m.def("mnk_strmatch_fuzzy_string", &nk_strmatch_fuzzy_string,"extern int nk_strmatch_fuzzy_string(char const *str, char const *pattern, int *out_score);");

    m.def("mnk_strmatch_fuzzy_text", &nk_strmatch_fuzzy_text,"extern int nk_strmatch_fuzzy_text(const char *txt, int txt_len, const char *pattern, int *out_score);");

    m.def("mnk_font_atlas_init_default", &nk_font_atlas_init_default,"extern void nk_font_atlas_init_default(struct nk_font_atlas*);");

    m.def("mnk_font_atlas_begin", &nk_font_atlas_begin,"extern void nk_font_atlas_begin(struct nk_font_atlas*);");

    m.def("mnk_font_config", &nk_font_config,"extern struct nk_font_config nk_font_config(float pixel_height);");

    m.def("mnk_font_atlas_add_default", &nk_font_atlas_add_default, nb::rv_policy::reference,"extern struct nk_font* nk_font_atlas_add_default(struct nk_font_atlas*, float height, const struct nk_font_config*);");

    m.def("mnk_font_atlas_add_from_memory", &nk_font_atlas_add_from_memory, nb::rv_policy::reference,"extern struct nk_font* nk_font_atlas_add_from_memory(struct nk_font_atlas *atlas, void *memory, nk_size size, float height, const struct nk_font_config *config);");

    m.def("mnk_font_atlas_add_from_file", &nk_font_atlas_add_from_file, nb::rv_policy::reference,"extern struct nk_font* nk_font_atlas_add_from_file(struct nk_font_atlas *atlas, const char *file_path, float height, const struct nk_font_config*);");

    m.def("mnk_font_atlas_add_compressed_base85", &nk_font_atlas_add_compressed_base85, nb::rv_policy::reference,"extern struct nk_font* nk_font_atlas_add_compressed_base85(struct nk_font_atlas*, const char *data, float height, const struct nk_font_config *config);");

    m.def("mnk_font_atlas_bake", as_capsule(&nk_font_atlas_bake),"extern const void* nk_font_atlas_bake(struct nk_font_atlas*, int *width, int *height, enum nk_font_atlas_format);");

    m.def("mnk_font_atlas_end", &nk_font_atlas_end,"extern void nk_font_atlas_end(struct nk_font_atlas*, nk_handle tex, struct nk_draw_null_texture*);");

    m.def("mnk_font_find_glyph", &nk_font_find_glyph, nb::rv_policy::reference,"extern const struct nk_font_glyph* nk_font_find_glyph(const struct nk_font*, nk_rune unicode);");

    m.def("mnk_font_atlas_cleanup", &nk_font_atlas_cleanup,"extern void nk_font_atlas_cleanup(struct nk_font_atlas *atlas);");

    m.def("mnk_font_atlas_clear", &nk_font_atlas_clear,"extern void nk_font_atlas_clear(struct nk_font_atlas*);");

    m.def("mnk_buffer_init_default", &nk_buffer_init_default,"extern void nk_buffer_init_default(struct nk_buffer*);");

    m.def("mnk_buffer_init_fixed", &nk_buffer_init_fixed,"extern void nk_buffer_init_fixed(struct nk_buffer*, void *memory, nk_size size);");

    m.def("mnk_buffer_info", &nk_buffer_info,"extern void nk_buffer_info(struct nk_memory_status*, const struct nk_buffer*);");

    m.def("mnk_buffer_push", &nk_buffer_push,"extern void nk_buffer_push(struct nk_buffer*, enum nk_buffer_allocation_type type, const void *memory, nk_size size, nk_size align);");

    m.def("mnk_buffer_mark", &nk_buffer_mark,"extern void nk_buffer_mark(struct nk_buffer*, enum nk_buffer_allocation_type type);");

    m.def("mnk_buffer_reset", &nk_buffer_reset,"extern void nk_buffer_reset(struct nk_buffer*, enum nk_buffer_allocation_type type);");

    m.def("mnk_buffer_clear", &nk_buffer_clear,"extern void nk_buffer_clear(struct nk_buffer*);");

    m.def("mnk_buffer_free", &nk_buffer_free,"extern void nk_buffer_free(struct nk_buffer*);");

    m.def("mnk_buffer_total", &nk_buffer_total,"extern nk_size nk_buffer_total(const struct nk_buffer*);");

    m.def("mnk_str_init_default", &nk_str_init_default,"extern void nk_str_init_default(struct nk_str*);");

    m.def("mnk_str_init_fixed", &nk_str_init_fixed,"extern void nk_str_init_fixed(struct nk_str*, void *memory, nk_size size);");

    m.def("mnk_str_clear", &nk_str_clear,"extern void nk_str_clear(struct nk_str*);");

    m.def("mnk_str_free", &nk_str_free,"extern void nk_str_free(struct nk_str*);");

    m.def("mnk_str_append_text_char", &nk_str_append_text_char,"extern int nk_str_append_text_char(struct nk_str*, const char*, int);");

    m.def("mnk_str_append_str_char", &nk_str_append_str_char,"extern int nk_str_append_str_char(struct nk_str*, const char*);");

    m.def("mnk_str_append_text_utf8", &nk_str_append_text_utf8,"extern int nk_str_append_text_utf8(struct nk_str*, const char*, int);");

    m.def("mnk_str_append_str_utf8", &nk_str_append_str_utf8,"extern int nk_str_append_str_utf8(struct nk_str*, const char*);");

    m.def("mnk_str_append_text_runes", &nk_str_append_text_runes,"extern int nk_str_append_text_runes(struct nk_str*, const nk_rune*, int);");

    m.def("mnk_str_append_str_runes", &nk_str_append_str_runes,"extern int nk_str_append_str_runes(struct nk_str*, const nk_rune*);");

    m.def("mnk_str_insert_at_char", &nk_str_insert_at_char,"extern int nk_str_insert_at_char(struct nk_str*, int pos, const char*, int);");

    m.def("mnk_str_insert_at_rune", &nk_str_insert_at_rune,"extern int nk_str_insert_at_rune(struct nk_str*, int pos, const char*, int);");

    m.def("mnk_str_insert_text_char", &nk_str_insert_text_char,"extern int nk_str_insert_text_char(struct nk_str*, int pos, const char*, int);");

    m.def("mnk_str_insert_str_char", &nk_str_insert_str_char,"extern int nk_str_insert_str_char(struct nk_str*, int pos, const char*);");

    m.def("mnk_str_insert_text_utf8", &nk_str_insert_text_utf8,"extern int nk_str_insert_text_utf8(struct nk_str*, int pos, const char*, int);");

    m.def("mnk_str_insert_str_utf8", &nk_str_insert_str_utf8,"extern int nk_str_insert_str_utf8(struct nk_str*, int pos, const char*);");

    m.def("mnk_str_insert_text_runes", &nk_str_insert_text_runes,"extern int nk_str_insert_text_runes(struct nk_str*, int pos, const nk_rune*, int);");

    m.def("mnk_str_insert_str_runes", &nk_str_insert_str_runes,"extern int nk_str_insert_str_runes(struct nk_str*, int pos, const nk_rune*);");

    m.def("mnk_str_remove_chars", &nk_str_remove_chars,"extern void nk_str_remove_chars(struct nk_str*, int len);");

    m.def("mnk_str_remove_runes", &nk_str_remove_runes,"extern void nk_str_remove_runes(struct nk_str *str, int len);");

    m.def("mnk_str_delete_chars", &nk_str_delete_chars,"extern void nk_str_delete_chars(struct nk_str*, int pos, int len);");

    m.def("mnk_str_delete_runes", &nk_str_delete_runes,"extern void nk_str_delete_runes(struct nk_str*, int pos, int len);");

    m.def("mnk_str_rune_at", &nk_str_rune_at,"extern nk_rune nk_str_rune_at(const struct nk_str*, int pos);");

    m.def("mnk_str_len", &nk_str_len,"extern int nk_str_len(const struct nk_str*);");

    m.def("mnk_str_len_char", &nk_str_len_char,"extern int nk_str_len_char(const struct nk_str*);");

    m.def("mnk_filter_default", &nk_filter_default,"extern nk_bool nk_filter_default(const struct nk_text_edit*, nk_rune unicode);");

    m.def("mnk_filter_ascii", &nk_filter_ascii,"extern nk_bool nk_filter_ascii(const struct nk_text_edit*, nk_rune unicode);");

    m.def("mnk_filter_float", &nk_filter_float,"extern nk_bool nk_filter_float(const struct nk_text_edit*, nk_rune unicode);");

    m.def("mnk_filter_decimal", &nk_filter_decimal,"extern nk_bool nk_filter_decimal(const struct nk_text_edit*, nk_rune unicode);");

    m.def("mnk_filter_hex", &nk_filter_hex,"extern nk_bool nk_filter_hex(const struct nk_text_edit*, nk_rune unicode);");

    m.def("mnk_filter_oct", &nk_filter_oct,"extern nk_bool nk_filter_oct(const struct nk_text_edit*, nk_rune unicode);");

    m.def("mnk_filter_binary", &nk_filter_binary,"extern nk_bool nk_filter_binary(const struct nk_text_edit*, nk_rune unicode);");

    m.def("mnk_textedit_init_default", &nk_textedit_init_default,"extern void nk_textedit_init_default(struct nk_text_edit*);");

    m.def("mnk_textedit_init_fixed", &nk_textedit_init_fixed,"extern void nk_textedit_init_fixed(struct nk_text_edit*, void *memory, nk_size size);");

    m.def("mnk_textedit_free", &nk_textedit_free,"extern void nk_textedit_free(struct nk_text_edit*);");

    m.def("mnk_textedit_text", &nk_textedit_text,"extern void nk_textedit_text(struct nk_text_edit*, const char*, int total_len);");

    m.def("mnk_textedit_delete", &nk_textedit_delete,"extern void nk_textedit_delete(struct nk_text_edit*, int where, int len);");

    m.def("mnk_textedit_delete_selection", &nk_textedit_delete_selection,"extern void nk_textedit_delete_selection(struct nk_text_edit*);");

    m.def("mnk_textedit_select_all", &nk_textedit_select_all,"extern void nk_textedit_select_all(struct nk_text_edit*);");

    m.def("mnk_textedit_cut", &nk_textedit_cut,"extern nk_bool nk_textedit_cut(struct nk_text_edit*);");

    m.def("mnk_textedit_paste", &nk_textedit_paste,"extern nk_bool nk_textedit_paste(struct nk_text_edit*, char const*, int len);");

    m.def("mnk_textedit_undo", &nk_textedit_undo,"extern void nk_textedit_undo(struct nk_text_edit*);");

    m.def("mnk_textedit_redo", &nk_textedit_redo,"extern void nk_textedit_redo(struct nk_text_edit*);");

    m.def("mnk_stroke_line", &nk_stroke_line,"extern void nk_stroke_line(struct nk_command_buffer *b, float x0, float y0, float x1, float y1, float line_thickness, struct nk_color);");

    m.def("mnk_stroke_curve", &nk_stroke_curve,"extern void nk_stroke_curve(struct nk_command_buffer*, float, float, float, float, float, float, float, float, float line_thickness, struct nk_color);");

    m.def("mnk_stroke_rect", &nk_stroke_rect,"extern void nk_stroke_rect(struct nk_command_buffer*, struct nk_rect, float rounding, float line_thickness, struct nk_color);");

    m.def("mnk_stroke_circle", &nk_stroke_circle,"extern void nk_stroke_circle(struct nk_command_buffer*, struct nk_rect, float line_thickness, struct nk_color);");

    m.def("mnk_stroke_arc", &nk_stroke_arc,"extern void nk_stroke_arc(struct nk_command_buffer*, float cx, float cy, float radius, float a_min, float a_max, float line_thickness, struct nk_color);");

    m.def("mnk_stroke_triangle", &nk_stroke_triangle,"extern void nk_stroke_triangle(struct nk_command_buffer*, float, float, float, float, float, float, float line_thichness, struct nk_color);");

    m.def("mnk_stroke_polyline", &nk_stroke_polyline,"extern void nk_stroke_polyline(struct nk_command_buffer*, const float *points, int point_count, float line_thickness, struct nk_color col);");

    m.def("mnk_stroke_polygon", &nk_stroke_polygon,"extern void nk_stroke_polygon(struct nk_command_buffer*, const float *points, int point_count, float line_thickness, struct nk_color);");

    m.def("mnk_fill_rect", &nk_fill_rect,"extern void nk_fill_rect(struct nk_command_buffer*, struct nk_rect, float rounding, struct nk_color);");

    m.def("mnk_fill_rect_multi_color", &nk_fill_rect_multi_color,"extern void nk_fill_rect_multi_color(struct nk_command_buffer*, struct nk_rect, struct nk_color left, struct nk_color top, struct nk_color right, struct nk_color bottom);");

    m.def("mnk_fill_circle", &nk_fill_circle,"extern void nk_fill_circle(struct nk_command_buffer*, struct nk_rect, struct nk_color);");

    m.def("mnk_fill_arc", &nk_fill_arc,"extern void nk_fill_arc(struct nk_command_buffer*, float cx, float cy, float radius, float a_min, float a_max, struct nk_color);");

    m.def("mnk_fill_triangle", &nk_fill_triangle,"extern void nk_fill_triangle(struct nk_command_buffer*, float x0, float y0, float x1, float y1, float x2, float y2, struct nk_color);");

    m.def("mnk_fill_polygon", &nk_fill_polygon,"extern void nk_fill_polygon(struct nk_command_buffer*, const float *points, int point_count, struct nk_color);");

    m.def("mnk_draw_image", &nk_draw_image,"extern void nk_draw_image(struct nk_command_buffer*, struct nk_rect, const struct nk_image*, struct nk_color);");

    m.def("mnk_draw_nine_slice", &nk_draw_nine_slice,"extern void nk_draw_nine_slice(struct nk_command_buffer*, struct nk_rect, const struct nk_nine_slice*, struct nk_color);");

    m.def("mnk_draw_text", &nk_draw_text,"extern void nk_draw_text(struct nk_command_buffer*, struct nk_rect, const char *text, int len, const struct nk_user_font*, struct nk_color, struct nk_color);");

    m.def("mnk_push_scissor", &nk_push_scissor,"extern void nk_push_scissor(struct nk_command_buffer*, struct nk_rect);");

    m.def("mnk_input_has_mouse_click", &nk_input_has_mouse_click,"extern nk_bool nk_input_has_mouse_click(const struct nk_input*, enum nk_buttons);");

    m.def("mnk_input_has_mouse_click_in_rect", &nk_input_has_mouse_click_in_rect,"extern nk_bool nk_input_has_mouse_click_in_rect(const struct nk_input*, enum nk_buttons, struct nk_rect);");

    m.def("mnk_input_has_mouse_click_in_button_rect", &nk_input_has_mouse_click_in_button_rect,"extern nk_bool nk_input_has_mouse_click_in_button_rect(const struct nk_input*, enum nk_buttons, struct nk_rect);");

    m.def("mnk_input_has_mouse_click_down_in_rect", &nk_input_has_mouse_click_down_in_rect,"extern nk_bool nk_input_has_mouse_click_down_in_rect(const struct nk_input*, enum nk_buttons, struct nk_rect, nk_bool down);");

    m.def("mnk_input_is_mouse_click_in_rect", &nk_input_is_mouse_click_in_rect,"extern nk_bool nk_input_is_mouse_click_in_rect(const struct nk_input*, enum nk_buttons, struct nk_rect);");

    m.def("mnk_input_is_mouse_click_down_in_rect", &nk_input_is_mouse_click_down_in_rect,"extern nk_bool nk_input_is_mouse_click_down_in_rect(const struct nk_input *i, enum nk_buttons id, struct nk_rect b, nk_bool down);");

    m.def("mnk_input_any_mouse_click_in_rect", &nk_input_any_mouse_click_in_rect,"extern nk_bool nk_input_any_mouse_click_in_rect(const struct nk_input*, struct nk_rect);");

    m.def("mnk_input_is_mouse_prev_hovering_rect", &nk_input_is_mouse_prev_hovering_rect,"extern nk_bool nk_input_is_mouse_prev_hovering_rect(const struct nk_input*, struct nk_rect);");

    m.def("mnk_input_is_mouse_hovering_rect", &nk_input_is_mouse_hovering_rect,"extern nk_bool nk_input_is_mouse_hovering_rect(const struct nk_input*, struct nk_rect);");

    m.def("mnk_input_is_mouse_moved", &nk_input_is_mouse_moved,"extern nk_bool nk_input_is_mouse_moved(const struct nk_input*);");

    m.def("mnk_input_mouse_clicked", &nk_input_mouse_clicked,"extern nk_bool nk_input_mouse_clicked(const struct nk_input*, enum nk_buttons, struct nk_rect);");

    m.def("mnk_input_is_mouse_down", &nk_input_is_mouse_down,"extern nk_bool nk_input_is_mouse_down(const struct nk_input*, enum nk_buttons);");

    m.def("mnk_input_is_mouse_pressed", &nk_input_is_mouse_pressed,"extern nk_bool nk_input_is_mouse_pressed(const struct nk_input*, enum nk_buttons);");

    m.def("mnk_input_is_mouse_released", &nk_input_is_mouse_released,"extern nk_bool nk_input_is_mouse_released(const struct nk_input*, enum nk_buttons);");

    m.def("mnk_input_is_key_pressed", &nk_input_is_key_pressed,"extern nk_bool nk_input_is_key_pressed(const struct nk_input*, enum nk_keys);");

    m.def("mnk_input_is_key_released", &nk_input_is_key_released,"extern nk_bool nk_input_is_key_released(const struct nk_input*, enum nk_keys);");

    m.def("mnk_input_is_key_down", &nk_input_is_key_down,"extern nk_bool nk_input_is_key_down(const struct nk_input*, enum nk_keys);");

    m.def("mnk_draw_list_init", &nk_draw_list_init,"extern void nk_draw_list_init(struct nk_draw_list*);");

    m.def("mnk_draw_list_setup", &nk_draw_list_setup,"extern void nk_draw_list_setup(struct nk_draw_list*, const struct nk_convert_config*, struct nk_buffer *cmds, struct nk_buffer *vertices, struct nk_buffer *elements, enum nk_anti_aliasing line_aa,enum nk_anti_aliasing shape_aa);");

    m.def("mnk_draw_list_path_clear", &nk_draw_list_path_clear,"extern void nk_draw_list_path_clear(struct nk_draw_list*);");

    m.def("mnk_draw_list_path_line_to", &nk_draw_list_path_line_to,"extern void nk_draw_list_path_line_to(struct nk_draw_list*, struct nk_vec2 pos);");

    m.def("mnk_draw_list_path_arc_to_fast", &nk_draw_list_path_arc_to_fast,"extern void nk_draw_list_path_arc_to_fast(struct nk_draw_list*, struct nk_vec2 center, float radius, int a_min, int a_max);");

    m.def("mnk_draw_list_path_arc_to", &nk_draw_list_path_arc_to,"extern void nk_draw_list_path_arc_to(struct nk_draw_list*, struct nk_vec2 center, float radius, float a_min, float a_max, unsigned int segments);");

    m.def("mnk_draw_list_path_rect_to", &nk_draw_list_path_rect_to,"extern void nk_draw_list_path_rect_to(struct nk_draw_list*, struct nk_vec2 a, struct nk_vec2 b, float rounding);");

    m.def("mnk_draw_list_path_curve_to", &nk_draw_list_path_curve_to,"extern void nk_draw_list_path_curve_to(struct nk_draw_list*, struct nk_vec2 p2, struct nk_vec2 p3, struct nk_vec2 p4, unsigned int num_segments);");

    m.def("mnk_draw_list_path_fill", &nk_draw_list_path_fill,"extern void nk_draw_list_path_fill(struct nk_draw_list*, struct nk_color);");

    m.def("mnk_draw_list_path_stroke", &nk_draw_list_path_stroke,"extern void nk_draw_list_path_stroke(struct nk_draw_list*, struct nk_color, enum nk_draw_list_stroke closed, float thickness);");

    m.def("mnk_draw_list_stroke_line", &nk_draw_list_stroke_line,"extern void nk_draw_list_stroke_line(struct nk_draw_list*, struct nk_vec2 a, struct nk_vec2 b, struct nk_color, float thickness);");

    m.def("mnk_draw_list_stroke_rect", &nk_draw_list_stroke_rect,"extern void nk_draw_list_stroke_rect(struct nk_draw_list*, struct nk_rect rect, struct nk_color, float rounding, float thickness);");

    m.def("mnk_draw_list_stroke_triangle", &nk_draw_list_stroke_triangle,"extern void nk_draw_list_stroke_triangle(struct nk_draw_list*, struct nk_vec2 a, struct nk_vec2 b, struct nk_vec2 c, struct nk_color, float thickness);");

    m.def("mnk_draw_list_stroke_circle", &nk_draw_list_stroke_circle,"extern void nk_draw_list_stroke_circle(struct nk_draw_list*, struct nk_vec2 center, float radius, struct nk_color, unsigned int segs, float thickness);");

    m.def("mnk_draw_list_stroke_curve", &nk_draw_list_stroke_curve,"extern void nk_draw_list_stroke_curve(struct nk_draw_list*, struct nk_vec2 p0, struct nk_vec2 cp0, struct nk_vec2 cp1, struct nk_vec2 p1, struct nk_color, unsigned int segments, float thickness);");

    m.def("mnk_draw_list_stroke_poly_line", &nk_draw_list_stroke_poly_line,"extern void nk_draw_list_stroke_poly_line(struct nk_draw_list*, const struct nk_vec2 *pnts, const unsigned int cnt, struct nk_color, enum nk_draw_list_stroke, float thickness, enum nk_anti_aliasing);");

    m.def("mnk_draw_list_fill_rect", &nk_draw_list_fill_rect,"extern void nk_draw_list_fill_rect(struct nk_draw_list*, struct nk_rect rect, struct nk_color, float rounding);");

    m.def("mnk_draw_list_fill_rect_multi_color", &nk_draw_list_fill_rect_multi_color,"extern void nk_draw_list_fill_rect_multi_color(struct nk_draw_list*, struct nk_rect rect, struct nk_color left, struct nk_color top, struct nk_color right, struct nk_color bottom);");

    m.def("mnk_draw_list_fill_triangle", &nk_draw_list_fill_triangle,"extern void nk_draw_list_fill_triangle(struct nk_draw_list*, struct nk_vec2 a, struct nk_vec2 b, struct nk_vec2 c, struct nk_color);");

    m.def("mnk_draw_list_fill_circle", &nk_draw_list_fill_circle,"extern void nk_draw_list_fill_circle(struct nk_draw_list*, struct nk_vec2 center, float radius, struct nk_color col, unsigned int segs);");

    m.def("mnk_draw_list_fill_poly_convex", &nk_draw_list_fill_poly_convex,"extern void nk_draw_list_fill_poly_convex(struct nk_draw_list*, const struct nk_vec2 *points, const unsigned int count, struct nk_color, enum nk_anti_aliasing);");

    m.def("mnk_draw_list_add_image", &nk_draw_list_add_image,"extern void nk_draw_list_add_image(struct nk_draw_list*, struct nk_image texture, struct nk_rect rect, struct nk_color);");

    m.def("mnk_draw_list_add_text", &nk_draw_list_add_text,"extern void nk_draw_list_add_text(struct nk_draw_list*, const struct nk_user_font*, struct nk_rect, const char *text, int len, float font_height, struct nk_color);");

    m.def("mnk_style_item_color", &nk_style_item_color,"extern struct nk_style_item nk_style_item_color(struct nk_color);");

    m.def("mnk_style_item_image", &nk_style_item_image,"extern struct nk_style_item nk_style_item_image(struct nk_image img);");

    m.def("mnk_style_item_nine_slice", &nk_style_item_nine_slice,"extern struct nk_style_item nk_style_item_nine_slice(struct nk_nine_slice slice);");

    m.def("mnk_style_item_hide", &nk_style_item_hide,"extern struct nk_style_item nk_style_item_hide(void);");

// NOT AUTOMATIC REALIZATION


    m.def("mnk_combobox", [](nk_context* ctx, std::vector<std::string> items, int selected, int item_height, struct nk_vec2 size) {
        std::vector<const char*> ptrs;
        for (const auto& s : items) ptrs.push_back(s.c_str());
        nk_combobox(ctx, ptrs.data(), (int)ptrs.size(), &selected, item_height, size);
        return selected; 
    });


    m.def("mnk_combo", [](nk_context* ctx, std::vector<std::string> items, int selected, int item_height, struct nk_vec2 size) {
        std::vector<const char*> ptrs;
        for (const auto& s : items) ptrs.push_back(s.c_str());
        return nk_combo(ctx, ptrs.data(), (int)ptrs.size(), selected, item_height, size);
    });


    m.def("mnk_edit_buffer", [](nk_context* ctx, nk_flags flags, nk_text_edit* edit, nb::callable filter) {
        nk_plugin_filter c_filter = nullptr;
        if (!filter.is_none()) {
            filter_map[static_cast<const void*>(edit)] = filter;   
            c_filter = filter_trampoline;
        }
        nk_flags res = nk_edit_buffer(ctx, flags, edit, c_filter);
        filter_map.erase(static_cast<const void*>(edit));           
        return res;
    }, "ctx"_a, "flags"_a, "edit"_a, "filter"_a = nb::none());

    m.def("mnk_plot_function", [](nk_context* ctx, nk_chart_type chart_type, nb::callable value_getter, int count, int offset) {
        if (value_getter.is_none()) {
            nk_plot_function(ctx, chart_type, nullptr, nullptr, count, offset);
        } else {
            nb::callable* cb_ptr = &value_getter;              
            nk_plot_function(ctx, chart_type, cb_ptr, plot_value_getter_trampoline,
                             count, offset);
        }
    }, "ctx"_a, "chart_type"_a, "value_getter"_a = nb::none(), "count"_a, "offset"_a);

    m.def("mnk_combo_callback", [](nk_context* ctx, nb::callable item_getter, void* userdata, int selected, int count, int item_height, struct nk_vec2 size) {
        if (item_getter.is_none()) return nk_combo_callback(ctx, nullptr, nullptr, selected, count, item_height, size);

        nb::callable* cb_ptr = &item_getter;

        return nk_combo_callback(ctx, combo_item_getter_trampoline, cb_ptr, selected, count, item_height, size);

    }, "ctx"_a, "item_getter"_a = nb::none(), "userdata"_a = nb::none(), "selected"_a, "count"_a, "item_height"_a, "size"_a);

    m.def("mnk_combobox_callback", [](nk_context* ctx, nb::callable item_getter, void* userdata, int* selected, int count, int item_height, struct nk_vec2 size) {
        if (item_getter.is_none())
            return nk_combobox_callback(ctx, nullptr, nullptr, selected, count, item_height, size);
        nb::callable* cb_ptr = &item_getter;
        return nk_combobox_callback(ctx, combo_item_getter_trampoline, cb_ptr, selected, count, item_height, size);
    }, "ctx"_a, "item_getter"_a = nb::none(), "userdata"_a = nb::none(), "selected"_a, "count"_a, "item_height"_a, "size"_a);

    m.def("mnk_edit_string_zero_terminated", [](nk_context* ctx, nk_flags flags, std::string buffer, int max, nb::callable filter) {
        buffer.resize(max);
        nk_plugin_filter c_filter = nullptr;
        const void* key = static_cast<const void*>(&filter);  
        if (!filter.is_none()) {
            filter_map[key] = filter;
            c_filter = filter_trampoline;
        }
        nk_flags res = nk_edit_string_zero_terminated(ctx, flags, buffer.data(),
                                                      max, c_filter);
        filter_map.erase(key);
        buffer.resize(strlen(buffer.c_str()));
        return std::make_tuple(res, buffer);
    }, "ctx"_a, "flags"_a, "buffer"_a, "max"_a, "filter"_a = nb::none());

    
    m.def("mnk_edit_string", [](nk_context* ctx, nk_flags flags, std::string buffer, int max, nb::callable filter) {
        buffer.resize(max);
        int current_len = (int)strlen(buffer.c_str());
        nk_plugin_filter c_filter = nullptr;
        const void* key = static_cast<const void*>(&filter);
        if (!filter.is_none()) {
            filter_map[key] = filter;
            c_filter = filter_trampoline;
        }
        nk_flags res = nk_edit_string(ctx, flags, buffer.data(), &current_len, max, c_filter);
        filter_map.erase(key);
        buffer.resize(current_len);
        return std::make_tuple(res, buffer);
    }, "ctx"_a, "flags"_a, "buffer"_a, "max"_a, "filter"_a = nb::none());

    nk_mouse_var.def("__getitem__", [](nk_mouse &m, size_t i) -> nk_mouse_button& {
            if (i >= NK_BUTTON_MAX) throw nb::index_error();
            return m.buttons[i];
        }, nb::rv_policy::reference_internal);
        
    nk_mouse_var.def("__len__", [](nk_mouse &) { return NK_BUTTON_MAX; });

    nb::class_<nk_style_item_data>(m, "nk_style_item_data")
        .def(nb::init<>())
        .def_rw("color", &nk_style_item_data::color)
        .def_rw("image", &nk_style_item_data::image)
        .def_rw("slice", &nk_style_item_data::slice);

}
