
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

namespace nb = nanobind;

template <typename Ret, typename... Args>
auto as_capsule(Ret (*func)(Args...)) {
    return [func](Args... args) {
        return nb::capsule((void*)func(args...));
    };
}


NB_MODULE(npnuklear, m) {
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

    m.def("mnk_init_default", &nk_init_default);

    m.def("mnk_init_fixed", &nk_init_fixed);

    m.def("mnk_init_custom", &nk_init_custom);

    m.def("mnk_clear", &nk_clear);

    m.def("mnk_free", &nk_free);

    m.def("mnk_input_begin", &nk_input_begin);

    m.def("mnk_input_motion", &nk_input_motion);

    m.def("mnk_input_key", &nk_input_key);

    m.def("mnk_input_button", &nk_input_button);

    m.def("mnk_input_scroll", &nk_input_scroll);

    m.def("mnk_input_char", &nk_input_char);

    m.def("mnk_input_glyph", &nk_input_glyph);

    m.def("mnk_input_unicode", &nk_input_unicode);

    m.def("mnk_input_end", &nk_input_end);

    m.def("mnk_convert", &nk_convert);

    m.def("mnk_begin", &nk_begin);

    m.def("mnk_begin_titled", &nk_begin_titled);

    m.def("mnk_end", &nk_end);

    m.def("mnk_window_get_bounds", &nk_window_get_bounds);

    m.def("mnk_window_get_position", &nk_window_get_position);

    m.def("mnk_window_get_size", &nk_window_get_size);

    m.def("mnk_window_get_width", &nk_window_get_width);

    m.def("mnk_window_get_height", &nk_window_get_height);

    m.def("mnk_window_get_panel", &nk_window_get_panel, nb::rv_policy::reference);

    m.def("mnk_window_get_content_region", &nk_window_get_content_region);

    m.def("mnk_window_get_content_region_min", &nk_window_get_content_region_min);

    m.def("mnk_window_get_content_region_max", &nk_window_get_content_region_max);

    m.def("mnk_window_get_content_region_size", &nk_window_get_content_region_size);

    m.def("mnk_window_get_canvas", &nk_window_get_canvas, nb::rv_policy::reference);

    m.def("mnk_window_get_scroll", &nk_window_get_scroll);

    m.def("mnk_window_has_focus", &nk_window_has_focus);

    m.def("mnk_window_is_hovered", &nk_window_is_hovered);

    m.def("mnk_window_is_collapsed", &nk_window_is_collapsed);

    m.def("mnk_window_is_closed", &nk_window_is_closed);

    m.def("mnk_window_is_hidden", &nk_window_is_hidden);

    m.def("mnk_window_is_active", &nk_window_is_active);

    m.def("mnk_window_is_any_hovered", &nk_window_is_any_hovered);

    m.def("mnk_item_is_any_active", &nk_item_is_any_active);

    m.def("mnk_window_set_bounds", &nk_window_set_bounds);

    m.def("mnk_window_set_position", &nk_window_set_position);

    m.def("mnk_window_set_size", &nk_window_set_size);

    m.def("mnk_window_set_focus", &nk_window_set_focus);

    m.def("mnk_window_set_scroll", &nk_window_set_scroll);

    m.def("mnk_window_close", &nk_window_close);

    m.def("mnk_window_collapse", &nk_window_collapse);

    m.def("mnk_window_collapse_if", &nk_window_collapse_if);

    m.def("mnk_window_show", &nk_window_show);

    m.def("mnk_window_show_if", &nk_window_show_if);

    m.def("mnk_rule_horizontal", &nk_rule_horizontal);

    m.def("mnk_layout_set_min_row_height", &nk_layout_set_min_row_height);

    m.def("mnk_layout_reset_min_row_height", &nk_layout_reset_min_row_height);

    m.def("mnk_layout_widget_bounds", &nk_layout_widget_bounds);

    m.def("mnk_layout_ratio_from_pixel", &nk_layout_ratio_from_pixel);

    m.def("mnk_layout_row_dynamic", &nk_layout_row_dynamic);

    m.def("mnk_layout_row_static", &nk_layout_row_static);

    m.def("mnk_layout_row_begin", &nk_layout_row_begin);

    m.def("mnk_layout_row_push", &nk_layout_row_push);

    m.def("mnk_layout_row_end", &nk_layout_row_end);

    m.def("mnk_layout_row", &nk_layout_row);

    m.def("mnk_layout_row_template_begin", &nk_layout_row_template_begin);

    m.def("mnk_layout_row_template_push_dynamic", &nk_layout_row_template_push_dynamic);

    m.def("mnk_layout_row_template_push_variable", &nk_layout_row_template_push_variable);

    m.def("mnk_layout_row_template_push_static", &nk_layout_row_template_push_static);

    m.def("mnk_layout_row_template_end", &nk_layout_row_template_end);

    m.def("mnk_layout_space_begin", &nk_layout_space_begin);

    m.def("mnk_layout_space_push", &nk_layout_space_push);

    m.def("mnk_layout_space_end", &nk_layout_space_end);

    m.def("mnk_layout_space_bounds", &nk_layout_space_bounds);

    m.def("mnk_layout_space_to_screen", &nk_layout_space_to_screen);

    m.def("mnk_layout_space_to_local", &nk_layout_space_to_local);

    m.def("mnk_layout_space_rect_to_screen", &nk_layout_space_rect_to_screen);

    m.def("mnk_layout_space_rect_to_local", &nk_layout_space_rect_to_local);

    m.def("mnk_spacer", &nk_spacer);

    m.def("mnk_group_begin", &nk_group_begin);

    m.def("mnk_group_begin_titled", &nk_group_begin_titled);

    m.def("mnk_group_end", &nk_group_end);

    m.def("mnk_group_scrolled_offset_begin", &nk_group_scrolled_offset_begin);

    m.def("mnk_group_scrolled_begin", &nk_group_scrolled_begin);

    m.def("mnk_group_scrolled_end", &nk_group_scrolled_end);

    m.def("mnk_group_get_scroll", &nk_group_get_scroll);

    m.def("mnk_group_set_scroll", &nk_group_set_scroll);

    m.def("mnk_tree_push_hashed", &nk_tree_push_hashed);

    m.def("mnk_tree_image_push_hashed", &nk_tree_image_push_hashed);

    m.def("mnk_tree_pop", &nk_tree_pop);

    m.def("mnk_tree_state_push", &nk_tree_state_push);

    m.def("mnk_tree_state_image_push", &nk_tree_state_image_push);

    m.def("mnk_tree_state_pop", &nk_tree_state_pop);

    m.def("mnk_tree_element_push_hashed", &nk_tree_element_push_hashed);

    m.def("mnk_tree_element_image_push_hashed", &nk_tree_element_image_push_hashed);

    m.def("mnk_tree_element_pop", &nk_tree_element_pop);

    m.def("mnk_list_view_begin", &nk_list_view_begin);

    m.def("mnk_list_view_end", &nk_list_view_end);

    m.def("mnk_widget", &nk_widget);

    m.def("mnk_widget_fitting", &nk_widget_fitting);

    m.def("mnk_widget_bounds", &nk_widget_bounds);

    m.def("mnk_widget_position", &nk_widget_position);

    m.def("mnk_widget_size", &nk_widget_size);

    m.def("mnk_widget_width", &nk_widget_width);

    m.def("mnk_widget_height", &nk_widget_height);

    m.def("mnk_widget_is_hovered", &nk_widget_is_hovered);

    m.def("mnk_widget_is_mouse_clicked", &nk_widget_is_mouse_clicked);

    m.def("mnk_widget_has_mouse_click_down", &nk_widget_has_mouse_click_down);

    m.def("mnk_spacing", &nk_spacing);

    m.def("mnk_widget_disable_begin", &nk_widget_disable_begin);

    m.def("mnk_widget_disable_end", &nk_widget_disable_end);

    m.def("mnk_text", &nk_text);

    m.def("mnk_text_colored", &nk_text_colored);

    m.def("mnk_text_wrap", &nk_text_wrap);

    m.def("mnk_text_wrap_colored", &nk_text_wrap_colored);

    m.def("mnk_label", &nk_label);

    m.def("mnk_label_colored", &nk_label_colored);

    m.def("mnk_label_wrap", &nk_label_wrap);

    m.def("mnk_label_colored_wrap", &nk_label_colored_wrap);

    m.def("mnk_image", &nk_image);

    m.def("mnk_image_color", &nk_image_color);

    m.def("mnk_value_bool", &nk_value_bool);

    m.def("mnk_value_int", &nk_value_int);

    m.def("mnk_value_uint", &nk_value_uint);

    m.def("mnk_value_float", &nk_value_float);

    m.def("mnk_value_color_byte", &nk_value_color_byte);

    m.def("mnk_value_color_float", &nk_value_color_float);

    m.def("mnk_value_color_hex", &nk_value_color_hex);

    m.def("mnk_button_text", &nk_button_text);

    m.def("mnk_button_label", &nk_button_label);

    m.def("mnk_button_color", &nk_button_color);

    m.def("mnk_button_symbol", &nk_button_symbol);

    m.def("mnk_button_image", &nk_button_image);

    m.def("mnk_button_symbol_label", &nk_button_symbol_label);

    m.def("mnk_button_symbol_text", &nk_button_symbol_text);

    m.def("mnk_button_image_label", &nk_button_image_label);

    m.def("mnk_button_image_text", &nk_button_image_text);

    m.def("mnk_button_text_styled", &nk_button_text_styled);

    m.def("mnk_button_label_styled", &nk_button_label_styled);

    m.def("mnk_button_symbol_styled", &nk_button_symbol_styled);

    m.def("mnk_button_image_styled", &nk_button_image_styled);

    m.def("mnk_button_symbol_text_styled", &nk_button_symbol_text_styled);

    m.def("mnk_button_symbol_label_styled", &nk_button_symbol_label_styled);

    m.def("mnk_button_image_label_styled", &nk_button_image_label_styled);

    m.def("mnk_button_image_text_styled", &nk_button_image_text_styled);

    m.def("mnk_button_set_behavior", &nk_button_set_behavior);

    m.def("mnk_button_push_behavior", &nk_button_push_behavior);

    m.def("mnk_button_pop_behavior", &nk_button_pop_behavior);

    m.def("mnk_check_label", &nk_check_label);

    m.def("mnk_check_text", &nk_check_text);

    m.def("mnk_check_text_align", &nk_check_text_align);

    m.def("mnk_check_flags_label", &nk_check_flags_label);

    m.def("mnk_check_flags_text", &nk_check_flags_text);

    m.def("mnk_checkbox_label", &nk_checkbox_label);

    m.def("mnk_checkbox_label_align", &nk_checkbox_label_align);

    m.def("mnk_checkbox_text", &nk_checkbox_text);

    m.def("mnk_checkbox_text_align", &nk_checkbox_text_align);

    m.def("mnk_checkbox_flags_label", &nk_checkbox_flags_label);

    m.def("mnk_checkbox_flags_text", &nk_checkbox_flags_text);

    m.def("mnk_radio_label", &nk_radio_label);

    m.def("mnk_radio_label_align", &nk_radio_label_align);

    m.def("mnk_radio_text", &nk_radio_text);

    m.def("mnk_radio_text_align", &nk_radio_text_align);

    m.def("mnk_option_label", &nk_option_label);

    m.def("mnk_option_label_align", &nk_option_label_align);

    m.def("mnk_option_text", &nk_option_text);

    m.def("mnk_option_text_align", &nk_option_text_align);

    m.def("mnk_selectable_label", &nk_selectable_label);

    m.def("mnk_selectable_text", &nk_selectable_text);

    m.def("mnk_selectable_image_label", &nk_selectable_image_label);

    m.def("mnk_selectable_image_text", &nk_selectable_image_text);

    m.def("mnk_selectable_symbol_label", &nk_selectable_symbol_label);

    m.def("mnk_selectable_symbol_text", &nk_selectable_symbol_text);

    m.def("mnk_select_label", &nk_select_label);

    m.def("mnk_select_text", &nk_select_text);

    m.def("mnk_select_image_label", &nk_select_image_label);

    m.def("mnk_select_image_text", &nk_select_image_text);

    m.def("mnk_select_symbol_label", &nk_select_symbol_label);

    m.def("mnk_select_symbol_text", &nk_select_symbol_text);

    m.def("mnk_slide_float", &nk_slide_float);

    m.def("mnk_slide_int", &nk_slide_int);

    m.def("mnk_slider_float", &nk_slider_float);

    m.def("mnk_slider_int", &nk_slider_int);

    m.def("mnk_knob_float", &nk_knob_float);

    m.def("mnk_knob_int", &nk_knob_int);

    m.def("mnk_progress", &nk_progress);

    m.def("mnk_prog", &nk_prog);

    m.def("mnk_color_picker", &nk_color_picker);

    m.def("mnk_color_pick", &nk_color_pick);

    m.def("mnk_property_int", &nk_property_int);

    m.def("mnk_property_float", &nk_property_float);

    m.def("mnk_property_double", &nk_property_double);

    m.def("mnk_propertyi", &nk_propertyi);

    m.def("mnk_propertyf", &nk_propertyf);

    m.def("mnk_propertyd", &nk_propertyd);

    m.def("mnk_edit_buffer", &nk_edit_buffer);

    m.def("mnk_edit_focus", &nk_edit_focus);

    m.def("mnk_edit_unfocus", &nk_edit_unfocus);

    m.def("mnk_chart_begin", &nk_chart_begin);

    m.def("mnk_chart_begin_colored", &nk_chart_begin_colored);

    m.def("mnk_chart_add_slot", &nk_chart_add_slot);

    m.def("mnk_chart_add_slot_colored", &nk_chart_add_slot_colored);

    m.def("mnk_chart_push", &nk_chart_push);

    m.def("mnk_chart_push_slot", &nk_chart_push_slot);

    m.def("mnk_chart_end", &nk_chart_end);

    m.def("mnk_plot", &nk_plot);

    m.def("mnk_plot_function", &nk_plot_function);

    m.def("mnk_popup_begin", &nk_popup_begin);

    m.def("mnk_popup_close", &nk_popup_close);

    m.def("mnk_popup_end", &nk_popup_end);

    m.def("mnk_popup_get_scroll", &nk_popup_get_scroll);

    m.def("mnk_popup_set_scroll", &nk_popup_set_scroll);

    m.def("mnk_combo_separator", &nk_combo_separator);

    m.def("mnk_combo_string", &nk_combo_string);

    m.def("mnk_combo_callback", &nk_combo_callback);

    m.def("mnk_combobox_string", &nk_combobox_string);

    m.def("mnk_combobox_separator", &nk_combobox_separator);

    m.def("mnk_combobox_callback", &nk_combobox_callback);

    m.def("mnk_combo_begin_text", &nk_combo_begin_text);

    m.def("mnk_combo_begin_label", &nk_combo_begin_label);

    m.def("mnk_combo_begin_color", &nk_combo_begin_color);

    m.def("mnk_combo_begin_symbol", &nk_combo_begin_symbol);

    m.def("mnk_combo_begin_symbol_label", &nk_combo_begin_symbol_label);

    m.def("mnk_combo_begin_symbol_text", &nk_combo_begin_symbol_text);

    m.def("mnk_combo_begin_image", &nk_combo_begin_image);

    m.def("mnk_combo_begin_image_label", &nk_combo_begin_image_label);

    m.def("mnk_combo_begin_image_text", &nk_combo_begin_image_text);

    m.def("mnk_combo_item_label", &nk_combo_item_label);

    m.def("mnk_combo_item_text", &nk_combo_item_text);

    m.def("mnk_combo_item_image_label", &nk_combo_item_image_label);

    m.def("mnk_combo_item_image_text", &nk_combo_item_image_text);

    m.def("mnk_combo_item_symbol_label", &nk_combo_item_symbol_label);

    m.def("mnk_combo_item_symbol_text", &nk_combo_item_symbol_text);

    m.def("mnk_combo_close", &nk_combo_close);

    m.def("mnk_combo_end", &nk_combo_end);

    m.def("mnk_contextual_begin", &nk_contextual_begin);

    m.def("mnk_contextual_item_text", &nk_contextual_item_text);

    m.def("mnk_contextual_item_label", &nk_contextual_item_label);

    m.def("mnk_contextual_item_image_label", &nk_contextual_item_image_label);

    m.def("mnk_contextual_item_image_text", &nk_contextual_item_image_text);

    m.def("mnk_contextual_item_symbol_label", &nk_contextual_item_symbol_label);

    m.def("mnk_contextual_item_symbol_text", &nk_contextual_item_symbol_text);

    m.def("mnk_contextual_close", &nk_contextual_close);

    m.def("mnk_contextual_end", &nk_contextual_end);

    m.def("mnk_tooltip", &nk_tooltip);

    m.def("mnk_tooltip_offset", &nk_tooltip_offset);

    m.def("mnk_tooltip_begin", &nk_tooltip_begin);

    m.def("mnk_tooltip_begin_offset", &nk_tooltip_begin_offset);

    m.def("mnk_tooltip_end", &nk_tooltip_end);

    m.def("mnk_menubar_begin", &nk_menubar_begin);

    m.def("mnk_menubar_end", &nk_menubar_end);

    m.def("mnk_menu_begin_text", &nk_menu_begin_text);

    m.def("mnk_menu_begin_label", &nk_menu_begin_label);

    m.def("mnk_menu_begin_image", &nk_menu_begin_image);

    m.def("mnk_menu_begin_image_text", &nk_menu_begin_image_text);

    m.def("mnk_menu_begin_image_label", &nk_menu_begin_image_label);

    m.def("mnk_menu_begin_symbol", &nk_menu_begin_symbol);

    m.def("mnk_menu_begin_symbol_text", &nk_menu_begin_symbol_text);

    m.def("mnk_menu_begin_symbol_label", &nk_menu_begin_symbol_label);

    m.def("mnk_menu_item_text", &nk_menu_item_text);

    m.def("mnk_menu_item_label", &nk_menu_item_label);

    m.def("mnk_menu_item_image_label", &nk_menu_item_image_label);

    m.def("mnk_menu_item_image_text", &nk_menu_item_image_text);

    m.def("mnk_menu_item_symbol_text", &nk_menu_item_symbol_text);

    m.def("mnk_menu_item_symbol_label", &nk_menu_item_symbol_label);

    m.def("mnk_menu_close", &nk_menu_close);

    m.def("mnk_menu_end", &nk_menu_end);

    m.def("mnk_style_default", &nk_style_default);

    m.def("mnk_style_from_table", &nk_style_from_table);

    m.def("mnk_style_load_cursor", &nk_style_load_cursor);

    m.def("mnk_style_load_all_cursors", &nk_style_load_all_cursors);

    m.def("mnk_style_get_color_by_name", &nk_style_get_color_by_name, nb::rv_policy::reference);

    m.def("mnk_style_set_font", &nk_style_set_font);

    m.def("mnk_style_set_cursor", &nk_style_set_cursor);

    m.def("mnk_style_show_cursor", &nk_style_show_cursor);

    m.def("mnk_style_hide_cursor", &nk_style_hide_cursor);

    m.def("mnk_style_push_font", &nk_style_push_font);

    m.def("mnk_style_push_float", &nk_style_push_float);

    m.def("mnk_style_push_vec2", &nk_style_push_vec2);

    m.def("mnk_style_push_style_item", &nk_style_push_style_item);

    m.def("mnk_style_push_flags", &nk_style_push_flags);

    m.def("mnk_style_push_color", &nk_style_push_color);

    m.def("mnk_style_pop_font", &nk_style_pop_font);

    m.def("mnk_style_pop_float", &nk_style_pop_float);

    m.def("mnk_style_pop_vec2", &nk_style_pop_vec2);

    m.def("mnk_style_pop_style_item", &nk_style_pop_style_item);

    m.def("mnk_style_pop_flags", &nk_style_pop_flags);

    m.def("mnk_style_pop_color", &nk_style_pop_color);

    m.def("mnk_rgb", &nk_rgb);

    m.def("mnk_rgb_iv", &nk_rgb_iv);

    m.def("mnk_rgb_bv", &nk_rgb_bv);

    m.def("mnk_rgb_f", &nk_rgb_f);

    m.def("mnk_rgb_fv", &nk_rgb_fv);

    m.def("mnk_rgb_cf", &nk_rgb_cf);

    m.def("mnk_rgb_hex", &nk_rgb_hex);

    m.def("mnk_rgb_factor", &nk_rgb_factor);

    m.def("mnk_rgba", &nk_rgba);

    m.def("mnk_rgba_u32", &nk_rgba_u32);

    m.def("mnk_rgba_iv", &nk_rgba_iv);

    m.def("mnk_rgba_bv", &nk_rgba_bv);

    m.def("mnk_rgba_f", &nk_rgba_f);

    m.def("mnk_rgba_fv", &nk_rgba_fv);

    m.def("mnk_rgba_cf", &nk_rgba_cf);

    m.def("mnk_rgba_hex", &nk_rgba_hex);

    m.def("mnk_hsva_colorf", &nk_hsva_colorf);

    m.def("mnk_hsva_colorfv", &nk_hsva_colorfv);

    m.def("mnk_colorf_hsva_f", &nk_colorf_hsva_f);

    m.def("mnk_colorf_hsva_fv", &nk_colorf_hsva_fv);

    m.def("mnk_hsv", &nk_hsv);

    m.def("mnk_hsv_iv", &nk_hsv_iv);

    m.def("mnk_hsv_bv", &nk_hsv_bv);

    m.def("mnk_hsv_f", &nk_hsv_f);

    m.def("mnk_hsv_fv", &nk_hsv_fv);

    m.def("mnk_hsva", &nk_hsva);

    m.def("mnk_hsva_iv", &nk_hsva_iv);

    m.def("mnk_hsva_bv", &nk_hsva_bv);

    m.def("mnk_hsva_f", &nk_hsva_f);

    m.def("mnk_hsva_fv", &nk_hsva_fv);

    m.def("mnk_color_f", &nk_color_f);

    m.def("mnk_color_fv", &nk_color_fv);

    m.def("mnk_color_cf", &nk_color_cf);

    m.def("mnk_color_d", &nk_color_d);

    m.def("mnk_color_dv", &nk_color_dv);

    m.def("mnk_color_u32", &nk_color_u32);

    m.def("mnk_color_hsv_i", &nk_color_hsv_i);

    m.def("mnk_color_hsv_b", &nk_color_hsv_b);

    m.def("mnk_color_hsv_iv", &nk_color_hsv_iv);

    m.def("mnk_color_hsv_bv", &nk_color_hsv_bv);

    m.def("mnk_color_hsv_f", &nk_color_hsv_f);

    m.def("mnk_color_hsv_fv", &nk_color_hsv_fv);

    m.def("mnk_color_hsva_i", &nk_color_hsva_i);

    m.def("mnk_color_hsva_b", &nk_color_hsva_b);

    m.def("mnk_color_hsva_iv", &nk_color_hsva_iv);

    m.def("mnk_color_hsva_bv", &nk_color_hsva_bv);

    m.def("mnk_color_hsva_f", &nk_color_hsva_f);

    m.def("mnk_color_hsva_fv", &nk_color_hsva_fv);

    m.def("mnk_handle_ptr", &nk_handle_ptr);

    m.def("mnk_handle_id", &nk_handle_id);

    m.def("mnk_image_handle", &nk_image_handle);

    m.def("mnk_image_ptr", &nk_image_ptr);

    m.def("mnk_image_id", &nk_image_id);

    m.def("mnk_image_is_subimage", &nk_image_is_subimage);

    m.def("mnk_subimage_ptr", &nk_subimage_ptr);

    m.def("mnk_subimage_id", &nk_subimage_id);

    m.def("mnk_subimage_handle", &nk_subimage_handle);

    m.def("mnk_nine_slice_handle", &nk_nine_slice_handle);

    m.def("mnk_nine_slice_ptr", &nk_nine_slice_ptr);

    m.def("mnk_nine_slice_id", &nk_nine_slice_id);

    m.def("mnk_nine_slice_is_sub9slice", &nk_nine_slice_is_sub9slice);

    m.def("mnk_sub9slice_ptr", &nk_sub9slice_ptr);

    m.def("mnk_sub9slice_id", &nk_sub9slice_id);

    m.def("mnk_sub9slice_handle", &nk_sub9slice_handle);

    m.def("mnk_murmur_hash", &nk_murmur_hash);

    m.def("mnk_triangle_from_direction", &nk_triangle_from_direction);

    m.def("mnk_vec2", &nk_vec2);

    m.def("mnk_vec2i", &nk_vec2i);

    m.def("mnk_vec2v", &nk_vec2v);

    m.def("mnk_vec2iv", &nk_vec2iv);

    m.def("mnk_get_null_rect", &nk_get_null_rect);

    m.def("mnk_rect", &nk_rect);

    m.def("mnk_recti", &nk_recti);

    m.def("mnk_recta", &nk_recta);

    m.def("mnk_rectv", &nk_rectv);

    m.def("mnk_rectiv", &nk_rectiv);

    m.def("mnk_rect_pos", &nk_rect_pos);

    m.def("mnk_rect_size", &nk_rect_size);

    m.def("mnk_strlen", &nk_strlen);

    m.def("mnk_stricmp", &nk_stricmp);

    m.def("mnk_stricmpn", &nk_stricmpn);

    m.def("mnk_strfilter", &nk_strfilter);

    m.def("mnk_strmatch_fuzzy_string", &nk_strmatch_fuzzy_string);

    m.def("mnk_strmatch_fuzzy_text", &nk_strmatch_fuzzy_text);

    m.def("mnk_font_atlas_init_default", &nk_font_atlas_init_default);

    m.def("mnk_font_atlas_begin", &nk_font_atlas_begin);

    m.def("mnk_font_config", &nk_font_config);

    m.def("mnk_font_atlas_add_default", &nk_font_atlas_add_default, nb::rv_policy::reference);

    m.def("mnk_font_atlas_add_from_memory", &nk_font_atlas_add_from_memory, nb::rv_policy::reference);

    m.def("mnk_font_atlas_add_from_file", &nk_font_atlas_add_from_file, nb::rv_policy::reference);

    m.def("mnk_font_atlas_add_compressed_base85", &nk_font_atlas_add_compressed_base85, nb::rv_policy::reference);

    m.def("mnk_font_atlas_bake", as_capsule(&nk_font_atlas_bake));

    m.def("mnk_font_atlas_end", &nk_font_atlas_end);

    m.def("mnk_font_find_glyph", &nk_font_find_glyph, nb::rv_policy::reference);

    m.def("mnk_font_atlas_cleanup", &nk_font_atlas_cleanup);

    m.def("mnk_font_atlas_clear", &nk_font_atlas_clear);

    m.def("mnk_buffer_init_default", &nk_buffer_init_default);

    m.def("mnk_buffer_init_fixed", &nk_buffer_init_fixed);

    m.def("mnk_buffer_info", &nk_buffer_info);

    m.def("mnk_buffer_push", &nk_buffer_push);

    m.def("mnk_buffer_mark", &nk_buffer_mark);

    m.def("mnk_buffer_reset", &nk_buffer_reset);

    m.def("mnk_buffer_clear", &nk_buffer_clear);

    m.def("mnk_buffer_free", &nk_buffer_free);

    m.def("mnk_buffer_total", &nk_buffer_total);

    m.def("mnk_str_init_default", &nk_str_init_default);

    m.def("mnk_str_init_fixed", &nk_str_init_fixed);

    m.def("mnk_str_clear", &nk_str_clear);

    m.def("mnk_str_free", &nk_str_free);

    m.def("mnk_str_append_text_char", &nk_str_append_text_char);

    m.def("mnk_str_append_str_char", &nk_str_append_str_char);

    m.def("mnk_str_append_text_utf8", &nk_str_append_text_utf8);

    m.def("mnk_str_append_str_utf8", &nk_str_append_str_utf8);

    m.def("mnk_str_append_text_runes", &nk_str_append_text_runes);

    m.def("mnk_str_append_str_runes", &nk_str_append_str_runes);

    m.def("mnk_str_insert_at_char", &nk_str_insert_at_char);

    m.def("mnk_str_insert_at_rune", &nk_str_insert_at_rune);

    m.def("mnk_str_insert_text_char", &nk_str_insert_text_char);

    m.def("mnk_str_insert_str_char", &nk_str_insert_str_char);

    m.def("mnk_str_insert_text_utf8", &nk_str_insert_text_utf8);

    m.def("mnk_str_insert_str_utf8", &nk_str_insert_str_utf8);

    m.def("mnk_str_insert_text_runes", &nk_str_insert_text_runes);

    m.def("mnk_str_insert_str_runes", &nk_str_insert_str_runes);

    m.def("mnk_str_remove_chars", &nk_str_remove_chars);

    m.def("mnk_str_remove_runes", &nk_str_remove_runes);

    m.def("mnk_str_delete_chars", &nk_str_delete_chars);

    m.def("mnk_str_delete_runes", &nk_str_delete_runes);

    m.def("mnk_str_rune_at", &nk_str_rune_at);

    m.def("mnk_str_len", &nk_str_len);

    m.def("mnk_str_len_char", &nk_str_len_char);

    m.def("mnk_filter_default", &nk_filter_default);

    m.def("mnk_filter_ascii", &nk_filter_ascii);

    m.def("mnk_filter_float", &nk_filter_float);

    m.def("mnk_filter_decimal", &nk_filter_decimal);

    m.def("mnk_filter_hex", &nk_filter_hex);

    m.def("mnk_filter_oct", &nk_filter_oct);

    m.def("mnk_filter_binary", &nk_filter_binary);

    m.def("mnk_textedit_init_default", &nk_textedit_init_default);

    m.def("mnk_textedit_init_fixed", &nk_textedit_init_fixed);

    m.def("mnk_textedit_free", &nk_textedit_free);

    m.def("mnk_textedit_text", &nk_textedit_text);

    m.def("mnk_textedit_delete", &nk_textedit_delete);

    m.def("mnk_textedit_delete_selection", &nk_textedit_delete_selection);

    m.def("mnk_textedit_select_all", &nk_textedit_select_all);

    m.def("mnk_textedit_cut", &nk_textedit_cut);

    m.def("mnk_textedit_paste", &nk_textedit_paste);

    m.def("mnk_textedit_undo", &nk_textedit_undo);

    m.def("mnk_textedit_redo", &nk_textedit_redo);

    m.def("mnk_stroke_line", &nk_stroke_line);

    m.def("mnk_stroke_curve", &nk_stroke_curve);

    m.def("mnk_stroke_rect", &nk_stroke_rect);

    m.def("mnk_stroke_circle", &nk_stroke_circle);

    m.def("mnk_stroke_arc", &nk_stroke_arc);

    m.def("mnk_stroke_triangle", &nk_stroke_triangle);

    m.def("mnk_stroke_polyline", &nk_stroke_polyline);

    m.def("mnk_stroke_polygon", &nk_stroke_polygon);

    m.def("mnk_fill_rect", &nk_fill_rect);

    m.def("mnk_fill_rect_multi_color", &nk_fill_rect_multi_color);

    m.def("mnk_fill_circle", &nk_fill_circle);

    m.def("mnk_fill_arc", &nk_fill_arc);

    m.def("mnk_fill_triangle", &nk_fill_triangle);

    m.def("mnk_fill_polygon", &nk_fill_polygon);

    m.def("mnk_draw_image", &nk_draw_image);

    m.def("mnk_draw_nine_slice", &nk_draw_nine_slice);

    m.def("mnk_draw_text", &nk_draw_text);

    m.def("mnk_push_scissor", &nk_push_scissor);

    m.def("mnk_input_has_mouse_click", &nk_input_has_mouse_click);

    m.def("mnk_input_has_mouse_click_in_rect", &nk_input_has_mouse_click_in_rect);

    m.def("mnk_input_has_mouse_click_in_button_rect", &nk_input_has_mouse_click_in_button_rect);

    m.def("mnk_input_has_mouse_click_down_in_rect", &nk_input_has_mouse_click_down_in_rect);

    m.def("mnk_input_is_mouse_click_in_rect", &nk_input_is_mouse_click_in_rect);

    m.def("mnk_input_is_mouse_click_down_in_rect", &nk_input_is_mouse_click_down_in_rect);

    m.def("mnk_input_any_mouse_click_in_rect", &nk_input_any_mouse_click_in_rect);

    m.def("mnk_input_is_mouse_prev_hovering_rect", &nk_input_is_mouse_prev_hovering_rect);

    m.def("mnk_input_is_mouse_hovering_rect", &nk_input_is_mouse_hovering_rect);

    m.def("mnk_input_is_mouse_moved", &nk_input_is_mouse_moved);

    m.def("mnk_input_mouse_clicked", &nk_input_mouse_clicked);

    m.def("mnk_input_is_mouse_down", &nk_input_is_mouse_down);

    m.def("mnk_input_is_mouse_pressed", &nk_input_is_mouse_pressed);

    m.def("mnk_input_is_mouse_released", &nk_input_is_mouse_released);

    m.def("mnk_input_is_key_pressed", &nk_input_is_key_pressed);

    m.def("mnk_input_is_key_released", &nk_input_is_key_released);

    m.def("mnk_input_is_key_down", &nk_input_is_key_down);

    m.def("mnk_draw_list_init", &nk_draw_list_init);

    m.def("mnk_draw_list_setup", &nk_draw_list_setup);

    m.def("mnk_draw_list_path_clear", &nk_draw_list_path_clear);

    m.def("mnk_draw_list_path_line_to", &nk_draw_list_path_line_to);

    m.def("mnk_draw_list_path_arc_to_fast", &nk_draw_list_path_arc_to_fast);

    m.def("mnk_draw_list_path_arc_to", &nk_draw_list_path_arc_to);

    m.def("mnk_draw_list_path_rect_to", &nk_draw_list_path_rect_to);

    m.def("mnk_draw_list_path_curve_to", &nk_draw_list_path_curve_to);

    m.def("mnk_draw_list_path_fill", &nk_draw_list_path_fill);

    m.def("mnk_draw_list_path_stroke", &nk_draw_list_path_stroke);

    m.def("mnk_draw_list_stroke_line", &nk_draw_list_stroke_line);

    m.def("mnk_draw_list_stroke_rect", &nk_draw_list_stroke_rect);

    m.def("mnk_draw_list_stroke_triangle", &nk_draw_list_stroke_triangle);

    m.def("mnk_draw_list_stroke_circle", &nk_draw_list_stroke_circle);

    m.def("mnk_draw_list_stroke_curve", &nk_draw_list_stroke_curve);

    m.def("mnk_draw_list_stroke_poly_line", &nk_draw_list_stroke_poly_line);

    m.def("mnk_draw_list_fill_rect", &nk_draw_list_fill_rect);

    m.def("mnk_draw_list_fill_rect_multi_color", &nk_draw_list_fill_rect_multi_color);

    m.def("mnk_draw_list_fill_triangle", &nk_draw_list_fill_triangle);

    m.def("mnk_draw_list_fill_circle", &nk_draw_list_fill_circle);

    m.def("mnk_draw_list_fill_poly_convex", &nk_draw_list_fill_poly_convex);

    m.def("mnk_draw_list_add_image", &nk_draw_list_add_image);

    m.def("mnk_draw_list_add_text", &nk_draw_list_add_text);

    m.def("mnk_style_item_color", &nk_style_item_color);

    m.def("mnk_style_item_image", &nk_style_item_image);

    m.def("mnk_style_item_nine_slice", &nk_style_item_nine_slice);

    m.def("mnk_style_item_hide", &nk_style_item_hide);

// NOT AUTOMATIC REALIZATION

using namespace nanobind::literals;
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

    m.def("mnk_edit_string_zero_terminated", [](nk_context* ctx, nk_flags flags, std::string buffer, int max, nk_plugin_filter filter) {
        buffer.resize(max); 
        nk_flags res = nk_edit_string_zero_terminated(ctx, flags, buffer.data(), max, filter);
    
    
        buffer.resize(strlen(buffer.c_str())); 
        return std::make_tuple(res, buffer);
    }, "ctx"_a, "flags"_a, "buffer"_a, "max"_a, "filter"_a = nullptr);

    m.def("mnk_edit_string", [](nk_context* ctx, nk_flags flags, std::string buffer, int max, nk_plugin_filter filter) {
        buffer.resize(max);
        int current_len = (int)strlen(buffer.c_str()); // Или передавать len из Python
    
        nk_flags res = nk_edit_string(ctx, flags, buffer.data(), &current_len, max, filter);

        buffer.resize(current_len);
        return std::make_tuple(res, buffer);
    }, "ctx"_a, "flags"_a, "buffer"_a, "max"_a, "filter"_a = nullptr);


    nk_mouse_var.def("__getitem__", [](nk_mouse &m, size_t i) -> nk_mouse_button& {
            if (i >= NK_BUTTON_MAX) throw nb::index_error();
            return m.buttons[i];
        }, nb::rv_policy::reference_internal);
        
    nk_mouse_var.def("__len__", [](nk_mouse &) { return NK_BUTTON_MAX; });



 
}
