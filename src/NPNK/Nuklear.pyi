from collections.abc import Sequence
import enum
import types


NK_ANTI_ALIASING_OFF: nk_anti_aliasing = nk_anti_aliasing.NK_ANTI_ALIASING_OFF

NK_ANTI_ALIASING_ON: nk_anti_aliasing = nk_anti_aliasing.NK_ANTI_ALIASING_ON

NK_BOTTOM_CENTER: nk_tooltip_pos = nk_tooltip_pos.NK_BOTTOM_CENTER

NK_BOTTOM_LEFT: nk_tooltip_pos = nk_tooltip_pos.NK_BOTTOM_LEFT

NK_BOTTOM_RIGHT: nk_tooltip_pos = nk_tooltip_pos.NK_BOTTOM_RIGHT

NK_BUFFER_BACK: nk_buffer_allocation_type = nk_buffer_allocation_type.NK_BUFFER_BACK

NK_BUFFER_DYNAMIC: nk_allocation_type = nk_allocation_type.NK_BUFFER_DYNAMIC

NK_BUFFER_FIXED: nk_allocation_type = nk_allocation_type.NK_BUFFER_FIXED

NK_BUFFER_FRONT: nk_buffer_allocation_type = nk_buffer_allocation_type.NK_BUFFER_FRONT

NK_BUFFER_MAX: nk_buffer_allocation_type = nk_buffer_allocation_type.NK_BUFFER_MAX

NK_BUTTON_DEFAULT: nk_button_behavior = nk_button_behavior.NK_BUTTON_DEFAULT

NK_BUTTON_DOUBLE: nk_buttons = nk_buttons.NK_BUTTON_DOUBLE

NK_BUTTON_LEFT: nk_buttons = nk_buttons.NK_BUTTON_LEFT

NK_BUTTON_MAX: nk_buttons = nk_buttons.NK_BUTTON_MAX

NK_BUTTON_MIDDLE: nk_buttons = nk_buttons.NK_BUTTON_MIDDLE

NK_BUTTON_REPEATER: nk_button_behavior = nk_button_behavior.NK_BUTTON_REPEATER

NK_BUTTON_RIGHT: nk_buttons = nk_buttons.NK_BUTTON_RIGHT

NK_CHART_CLICKED: nk_chart_event = nk_chart_event.NK_CHART_CLICKED

NK_CHART_COLUMN: nk_chart_type = nk_chart_type.NK_CHART_COLUMN

NK_CHART_HOVERING: nk_chart_event = nk_chart_event.NK_CHART_HOVERING

NK_CHART_LINES: nk_chart_type = nk_chart_type.NK_CHART_LINES

NK_CHART_MAX: nk_chart_type = nk_chart_type.NK_CHART_MAX

NK_CLIPPING_OFF: nk_command_clipping = nk_command_clipping.NK_CLIPPING_OFF

NK_CLIPPING_ON: nk_command_clipping = nk_command_clipping.NK_CLIPPING_ON

NK_COLOR_BORDER: nk_style_colors = nk_style_colors.NK_COLOR_BORDER

NK_COLOR_BUTTON: nk_style_colors = nk_style_colors.NK_COLOR_BUTTON

NK_COLOR_BUTTON_ACTIVE: nk_style_colors = nk_style_colors.NK_COLOR_BUTTON_ACTIVE

NK_COLOR_BUTTON_HOVER: nk_style_colors = nk_style_colors.NK_COLOR_BUTTON_HOVER

NK_COLOR_CHART: nk_style_colors = nk_style_colors.NK_COLOR_CHART

NK_COLOR_CHART_COLOR: nk_style_colors = nk_style_colors.NK_COLOR_CHART_COLOR

NK_COLOR_CHART_COLOR_HIGHLIGHT: nk_style_colors = nk_style_colors.NK_COLOR_CHART_COLOR_HIGHLIGHT

NK_COLOR_COMBO: nk_style_colors = nk_style_colors.NK_COLOR_COMBO

NK_COLOR_COUNT: nk_style_colors = nk_style_colors.NK_COLOR_COUNT

NK_COLOR_EDIT: nk_style_colors = nk_style_colors.NK_COLOR_EDIT

NK_COLOR_EDIT_CURSOR: nk_style_colors = nk_style_colors.NK_COLOR_EDIT_CURSOR

NK_COLOR_HEADER: nk_style_colors = nk_style_colors.NK_COLOR_HEADER

NK_COLOR_KNOB: nk_style_colors = nk_style_colors.NK_COLOR_KNOB

NK_COLOR_KNOB_CURSOR: nk_style_colors = nk_style_colors.NK_COLOR_KNOB_CURSOR

NK_COLOR_KNOB_CURSOR_ACTIVE: nk_style_colors = nk_style_colors.NK_COLOR_KNOB_CURSOR_ACTIVE

NK_COLOR_KNOB_CURSOR_HOVER: nk_style_colors = nk_style_colors.NK_COLOR_KNOB_CURSOR_HOVER

NK_COLOR_PROPERTY: nk_style_colors = nk_style_colors.NK_COLOR_PROPERTY

NK_COLOR_SCROLLBAR: nk_style_colors = nk_style_colors.NK_COLOR_SCROLLBAR

NK_COLOR_SCROLLBAR_CURSOR: nk_style_colors = nk_style_colors.NK_COLOR_SCROLLBAR_CURSOR

NK_COLOR_SCROLLBAR_CURSOR_ACTIVE: nk_style_colors = nk_style_colors.NK_COLOR_SCROLLBAR_CURSOR_ACTIVE

NK_COLOR_SCROLLBAR_CURSOR_HOVER: nk_style_colors = nk_style_colors.NK_COLOR_SCROLLBAR_CURSOR_HOVER

NK_COLOR_SELECT: nk_style_colors = nk_style_colors.NK_COLOR_SELECT

NK_COLOR_SELECT_ACTIVE: nk_style_colors = nk_style_colors.NK_COLOR_SELECT_ACTIVE

NK_COLOR_SLIDER: nk_style_colors = nk_style_colors.NK_COLOR_SLIDER

NK_COLOR_SLIDER_CURSOR: nk_style_colors = nk_style_colors.NK_COLOR_SLIDER_CURSOR

NK_COLOR_SLIDER_CURSOR_ACTIVE: nk_style_colors = nk_style_colors.NK_COLOR_SLIDER_CURSOR_ACTIVE

NK_COLOR_SLIDER_CURSOR_HOVER: nk_style_colors = nk_style_colors.NK_COLOR_SLIDER_CURSOR_HOVER

NK_COLOR_TAB_HEADER: nk_style_colors = nk_style_colors.NK_COLOR_TAB_HEADER

NK_COLOR_TEXT: nk_style_colors = nk_style_colors.NK_COLOR_TEXT

NK_COLOR_TOGGLE: nk_style_colors = nk_style_colors.NK_COLOR_TOGGLE

NK_COLOR_TOGGLE_CURSOR: nk_style_colors = nk_style_colors.NK_COLOR_TOGGLE_CURSOR

NK_COLOR_TOGGLE_HOVER: nk_style_colors = nk_style_colors.NK_COLOR_TOGGLE_HOVER

NK_COLOR_WINDOW: nk_style_colors = nk_style_colors.NK_COLOR_WINDOW

NK_COMMAND_ARC: nk_command_type = nk_command_type.NK_COMMAND_ARC

NK_COMMAND_ARC_FILLED: nk_command_type = nk_command_type.NK_COMMAND_ARC_FILLED

NK_COMMAND_CIRCLE: nk_command_type = nk_command_type.NK_COMMAND_CIRCLE

NK_COMMAND_CIRCLE_FILLED: nk_command_type = nk_command_type.NK_COMMAND_CIRCLE_FILLED

NK_COMMAND_CURVE: nk_command_type = nk_command_type.NK_COMMAND_CURVE

NK_COMMAND_CUSTOM: nk_command_type = nk_command_type.NK_COMMAND_CUSTOM

NK_COMMAND_IMAGE: nk_command_type = nk_command_type.NK_COMMAND_IMAGE

NK_COMMAND_LINE: nk_command_type = nk_command_type.NK_COMMAND_LINE

NK_COMMAND_NOP: nk_command_type = nk_command_type.NK_COMMAND_NOP

NK_COMMAND_POLYGON: nk_command_type = nk_command_type.NK_COMMAND_POLYGON

NK_COMMAND_POLYGON_FILLED: nk_command_type = nk_command_type.NK_COMMAND_POLYGON_FILLED

NK_COMMAND_POLYLINE: nk_command_type = nk_command_type.NK_COMMAND_POLYLINE

NK_COMMAND_RECT: nk_command_type = nk_command_type.NK_COMMAND_RECT

NK_COMMAND_RECT_FILLED: nk_command_type = nk_command_type.NK_COMMAND_RECT_FILLED

NK_COMMAND_RECT_MULTI_COLOR: nk_command_type = nk_command_type.NK_COMMAND_RECT_MULTI_COLOR

NK_COMMAND_SCISSOR: nk_command_type = nk_command_type.NK_COMMAND_SCISSOR

NK_COMMAND_TEXT: nk_command_type = nk_command_type.NK_COMMAND_TEXT

NK_COMMAND_TRIANGLE: nk_command_type = nk_command_type.NK_COMMAND_TRIANGLE

NK_COMMAND_TRIANGLE_FILLED: nk_command_type = nk_command_type.NK_COMMAND_TRIANGLE_FILLED

NK_CONVERT_COMMAND_BUFFER_FULL: nk_convert_result = nk_convert_result.NK_CONVERT_COMMAND_BUFFER_FULL

NK_CONVERT_ELEMENT_BUFFER_FULL: nk_convert_result = nk_convert_result.NK_CONVERT_ELEMENT_BUFFER_FULL

NK_CONVERT_INVALID_PARAM: nk_convert_result = nk_convert_result.NK_CONVERT_INVALID_PARAM

NK_CONVERT_SUCCESS: nk_convert_result = nk_convert_result.NK_CONVERT_SUCCESS

NK_CONVERT_VERTEX_BUFFER_FULL: nk_convert_result = nk_convert_result.NK_CONVERT_VERTEX_BUFFER_FULL

NK_COORD_PIXEL: nk_font_coord_type = nk_font_coord_type.NK_COORD_PIXEL

NK_COORD_UV: nk_font_coord_type = nk_font_coord_type.NK_COORD_UV

NK_CURSOR_ARROW: nk_style_cursor = nk_style_cursor.NK_CURSOR_ARROW

NK_CURSOR_COUNT: nk_style_cursor = nk_style_cursor.NK_CURSOR_COUNT

NK_CURSOR_MOVE: nk_style_cursor = nk_style_cursor.NK_CURSOR_MOVE

NK_CURSOR_RESIZE_HORIZONTAL: nk_style_cursor = nk_style_cursor.NK_CURSOR_RESIZE_HORIZONTAL

NK_CURSOR_RESIZE_TOP_LEFT_DOWN_RIGHT: nk_style_cursor = nk_style_cursor.NK_CURSOR_RESIZE_TOP_LEFT_DOWN_RIGHT

NK_CURSOR_RESIZE_TOP_RIGHT_DOWN_LEFT: nk_style_cursor = nk_style_cursor.NK_CURSOR_RESIZE_TOP_RIGHT_DOWN_LEFT

NK_CURSOR_RESIZE_VERTICAL: nk_style_cursor = nk_style_cursor.NK_CURSOR_RESIZE_VERTICAL

NK_CURSOR_TEXT: nk_style_cursor = nk_style_cursor.NK_CURSOR_TEXT

NK_DOWN: nk_heading = nk_heading.NK_DOWN

NK_DYNAMIC: nk_layout_format = nk_layout_format.NK_DYNAMIC

NK_EDIT_ACTIVATED: nk_edit_events = nk_edit_events.NK_EDIT_ACTIVATED

NK_EDIT_ACTIVE: nk_edit_events = nk_edit_events.NK_EDIT_ACTIVE

NK_EDIT_ALLOW_TAB: nk_edit_flags = nk_edit_flags.NK_EDIT_ALLOW_TAB

NK_EDIT_ALWAYS_INSERT_MODE: nk_edit_flags = nk_edit_flags.NK_EDIT_ALWAYS_INSERT_MODE

NK_EDIT_AUTO_SELECT: nk_edit_flags = nk_edit_flags.NK_EDIT_AUTO_SELECT

NK_EDIT_BOX: nk_edit_types = nk_edit_types.NK_EDIT_BOX

NK_EDIT_CLIPBOARD: nk_edit_flags = nk_edit_flags.NK_EDIT_CLIPBOARD

NK_EDIT_COMMITED: nk_edit_events = nk_edit_events.NK_EDIT_COMMITED

NK_EDIT_CTRL_ENTER_NEWLINE: nk_edit_flags = nk_edit_flags.NK_EDIT_CTRL_ENTER_NEWLINE

NK_EDIT_DEACTIVATED: nk_edit_events = nk_edit_events.NK_EDIT_DEACTIVATED

NK_EDIT_DEFAULT: nk_edit_flags = nk_edit_flags.NK_EDIT_DEFAULT

NK_EDIT_EDITOR: nk_edit_types = nk_edit_types.NK_EDIT_EDITOR

NK_EDIT_FIELD: nk_edit_types = nk_edit_types.NK_EDIT_FIELD

NK_EDIT_GOTO_END_ON_ACTIVATE: nk_edit_flags = nk_edit_flags.NK_EDIT_GOTO_END_ON_ACTIVATE

NK_EDIT_INACTIVE: nk_edit_events = nk_edit_events.NK_EDIT_INACTIVE

NK_EDIT_MULTILINE: nk_edit_flags = nk_edit_flags.NK_EDIT_MULTILINE

NK_EDIT_NO_CURSOR: nk_edit_flags = nk_edit_flags.NK_EDIT_NO_CURSOR

NK_EDIT_NO_HORIZONTAL_SCROLL: nk_edit_flags = nk_edit_flags.NK_EDIT_NO_HORIZONTAL_SCROLL

NK_EDIT_READ_ONLY: nk_edit_flags = nk_edit_flags.NK_EDIT_READ_ONLY

NK_EDIT_SELECTABLE: nk_edit_flags = nk_edit_flags.NK_EDIT_SELECTABLE

NK_EDIT_SIG_ENTER: nk_edit_flags = nk_edit_flags.NK_EDIT_SIG_ENTER

NK_EDIT_SIMPLE: nk_edit_types = nk_edit_types.NK_EDIT_SIMPLE

NK_FIXED: nk_modify = nk_modify.NK_FIXED

NK_FONT_ATLAS_ALPHA8: nk_font_atlas_format = nk_font_atlas_format.NK_FONT_ATLAS_ALPHA8

NK_FONT_ATLAS_RGBA32: nk_font_atlas_format = nk_font_atlas_format.NK_FONT_ATLAS_RGBA32

NK_FORMAT_B8G8R8A8: nk_draw_vertex_layout_format = nk_draw_vertex_layout_format.NK_FORMAT_B8G8R8A8

NK_FORMAT_COLOR_BEGIN: nk_draw_vertex_layout_format = nk_draw_vertex_layout_format.NK_FORMAT_COLOR_BEGIN

NK_FORMAT_COUNT: nk_draw_vertex_layout_format = nk_draw_vertex_layout_format.NK_FORMAT_COUNT

NK_FORMAT_DOUBLE: nk_draw_vertex_layout_format = nk_draw_vertex_layout_format.NK_FORMAT_DOUBLE

NK_FORMAT_FLOAT: nk_draw_vertex_layout_format = nk_draw_vertex_layout_format.NK_FORMAT_FLOAT

NK_FORMAT_R16G15B16: nk_draw_vertex_layout_format = nk_draw_vertex_layout_format.NK_FORMAT_R16G15B16

NK_FORMAT_R16G15B16A16: nk_draw_vertex_layout_format = nk_draw_vertex_layout_format.NK_FORMAT_R16G15B16A16

NK_FORMAT_R32G32B32: nk_draw_vertex_layout_format = nk_draw_vertex_layout_format.NK_FORMAT_R32G32B32

NK_FORMAT_R32G32B32A32: nk_draw_vertex_layout_format = nk_draw_vertex_layout_format.NK_FORMAT_R32G32B32A32

NK_FORMAT_R32G32B32A32_DOUBLE: nk_draw_vertex_layout_format = nk_draw_vertex_layout_format.NK_FORMAT_R32G32B32A32_DOUBLE

NK_FORMAT_R32G32B32A32_FLOAT: nk_draw_vertex_layout_format = nk_draw_vertex_layout_format.NK_FORMAT_R32G32B32A32_FLOAT

NK_FORMAT_R8G8B8A8: nk_draw_vertex_layout_format = nk_draw_vertex_layout_format.NK_FORMAT_R8G8B8A8

NK_FORMAT_RGB32: nk_draw_vertex_layout_format = nk_draw_vertex_layout_format.NK_FORMAT_RGB32

NK_FORMAT_RGBA32: nk_draw_vertex_layout_format = nk_draw_vertex_layout_format.NK_FORMAT_RGBA32

NK_FORMAT_SCHAR: nk_draw_vertex_layout_format = nk_draw_vertex_layout_format.NK_FORMAT_SCHAR

NK_FORMAT_SINT: nk_draw_vertex_layout_format = nk_draw_vertex_layout_format.NK_FORMAT_SINT

NK_FORMAT_SSHORT: nk_draw_vertex_layout_format = nk_draw_vertex_layout_format.NK_FORMAT_SSHORT

NK_FORMAT_UCHAR: nk_draw_vertex_layout_format = nk_draw_vertex_layout_format.NK_FORMAT_UCHAR

NK_FORMAT_UINT: nk_draw_vertex_layout_format = nk_draw_vertex_layout_format.NK_FORMAT_UINT

NK_FORMAT_USHORT: nk_draw_vertex_layout_format = nk_draw_vertex_layout_format.NK_FORMAT_USHORT

NK_HEADER_LEFT: nk_style_header_align = nk_style_header_align.NK_HEADER_LEFT

NK_HEADER_RIGHT: nk_style_header_align = nk_style_header_align.NK_HEADER_RIGHT

NK_HIDDEN: nk_show_states = nk_show_states.NK_HIDDEN

NK_HORIZONTAL: nk_orientation = nk_orientation.NK_HORIZONTAL

NK_KEY_BACKSPACE: nk_keys = nk_keys.NK_KEY_BACKSPACE

NK_KEY_COPY: nk_keys = nk_keys.NK_KEY_COPY

NK_KEY_CTRL: nk_keys = nk_keys.NK_KEY_CTRL

NK_KEY_CUT: nk_keys = nk_keys.NK_KEY_CUT

NK_KEY_DEL: nk_keys = nk_keys.NK_KEY_DEL

NK_KEY_DOWN: nk_keys = nk_keys.NK_KEY_DOWN

NK_KEY_ENTER: nk_keys = nk_keys.NK_KEY_ENTER

NK_KEY_LEFT: nk_keys = nk_keys.NK_KEY_LEFT

NK_KEY_MAX: nk_keys = nk_keys.NK_KEY_MAX

NK_KEY_NONE: nk_keys = nk_keys.NK_KEY_NONE

NK_KEY_PASTE: nk_keys = nk_keys.NK_KEY_PASTE

NK_KEY_RIGHT: nk_keys = nk_keys.NK_KEY_RIGHT

NK_KEY_SCROLL_DOWN: nk_keys = nk_keys.NK_KEY_SCROLL_DOWN

NK_KEY_SCROLL_END: nk_keys = nk_keys.NK_KEY_SCROLL_END

NK_KEY_SCROLL_START: nk_keys = nk_keys.NK_KEY_SCROLL_START

NK_KEY_SCROLL_UP: nk_keys = nk_keys.NK_KEY_SCROLL_UP

NK_KEY_SHIFT: nk_keys = nk_keys.NK_KEY_SHIFT

NK_KEY_TAB: nk_keys = nk_keys.NK_KEY_TAB

NK_KEY_TEXT_END: nk_keys = nk_keys.NK_KEY_TEXT_END

NK_KEY_TEXT_INSERT_MODE: nk_keys = nk_keys.NK_KEY_TEXT_INSERT_MODE

NK_KEY_TEXT_LINE_END: nk_keys = nk_keys.NK_KEY_TEXT_LINE_END

NK_KEY_TEXT_LINE_START: nk_keys = nk_keys.NK_KEY_TEXT_LINE_START

NK_KEY_TEXT_REDO: nk_keys = nk_keys.NK_KEY_TEXT_REDO

NK_KEY_TEXT_REPLACE_MODE: nk_keys = nk_keys.NK_KEY_TEXT_REPLACE_MODE

NK_KEY_TEXT_RESET_MODE: nk_keys = nk_keys.NK_KEY_TEXT_RESET_MODE

NK_KEY_TEXT_SELECT_ALL: nk_keys = nk_keys.NK_KEY_TEXT_SELECT_ALL

NK_KEY_TEXT_START: nk_keys = nk_keys.NK_KEY_TEXT_START

NK_KEY_TEXT_UNDO: nk_keys = nk_keys.NK_KEY_TEXT_UNDO

NK_KEY_TEXT_WORD_LEFT: nk_keys = nk_keys.NK_KEY_TEXT_WORD_LEFT

NK_KEY_TEXT_WORD_RIGHT: nk_keys = nk_keys.NK_KEY_TEXT_WORD_RIGHT

NK_KEY_UP: nk_keys = nk_keys.NK_KEY_UP

NK_LAYOUT_COUNT: nk_panel_row_layout_type = nk_panel_row_layout_type.NK_LAYOUT_COUNT

NK_LAYOUT_DYNAMIC: nk_panel_row_layout_type = nk_panel_row_layout_type.NK_LAYOUT_DYNAMIC

NK_LAYOUT_DYNAMIC_FIXED: nk_panel_row_layout_type = nk_panel_row_layout_type.NK_LAYOUT_DYNAMIC_FIXED

NK_LAYOUT_DYNAMIC_FREE: nk_panel_row_layout_type = nk_panel_row_layout_type.NK_LAYOUT_DYNAMIC_FREE

NK_LAYOUT_DYNAMIC_ROW: nk_panel_row_layout_type = nk_panel_row_layout_type.NK_LAYOUT_DYNAMIC_ROW

NK_LAYOUT_STATIC: nk_panel_row_layout_type = nk_panel_row_layout_type.NK_LAYOUT_STATIC

NK_LAYOUT_STATIC_FIXED: nk_panel_row_layout_type = nk_panel_row_layout_type.NK_LAYOUT_STATIC_FIXED

NK_LAYOUT_STATIC_FREE: nk_panel_row_layout_type = nk_panel_row_layout_type.NK_LAYOUT_STATIC_FREE

NK_LAYOUT_STATIC_ROW: nk_panel_row_layout_type = nk_panel_row_layout_type.NK_LAYOUT_STATIC_ROW

NK_LAYOUT_TEMPLATE: nk_panel_row_layout_type = nk_panel_row_layout_type.NK_LAYOUT_TEMPLATE

NK_LEFT: nk_heading = nk_heading.NK_LEFT

NK_MAXIMIZED: nk_collapse_states = nk_collapse_states.NK_MAXIMIZED

NK_MIDDLE_CENTER: nk_tooltip_pos = nk_tooltip_pos.NK_MIDDLE_CENTER

NK_MIDDLE_LEFT: nk_tooltip_pos = nk_tooltip_pos.NK_MIDDLE_LEFT

NK_MIDDLE_RIGHT: nk_tooltip_pos = nk_tooltip_pos.NK_MIDDLE_RIGHT

NK_MINIMIZED: nk_collapse_states = nk_collapse_states.NK_MINIMIZED

NK_MODIFIABLE: nk_modify = nk_modify.NK_MODIFIABLE

NK_PANEL_COMBO: nk_panel_type = nk_panel_type.NK_PANEL_COMBO

NK_PANEL_CONTEXTUAL: nk_panel_type = nk_panel_type.NK_PANEL_CONTEXTUAL

NK_PANEL_GROUP: nk_panel_type = nk_panel_type.NK_PANEL_GROUP

NK_PANEL_MENU: nk_panel_type = nk_panel_type.NK_PANEL_MENU

NK_PANEL_NONE: nk_panel_type = nk_panel_type.NK_PANEL_NONE

NK_PANEL_POPUP: nk_panel_type = nk_panel_type.NK_PANEL_POPUP

NK_PANEL_SET_NONBLOCK: nk_panel_set = nk_panel_set.NK_PANEL_SET_NONBLOCK

NK_PANEL_SET_POPUP: nk_panel_set = nk_panel_set.NK_PANEL_SET_POPUP

NK_PANEL_SET_SUB: nk_panel_set = nk_panel_set.NK_PANEL_SET_SUB

NK_PANEL_TOOLTIP: nk_panel_type = nk_panel_type.NK_PANEL_TOOLTIP

NK_PANEL_WINDOW: nk_panel_type = nk_panel_type.NK_PANEL_WINDOW

NK_POPUP_DYNAMIC: nk_popup_type = nk_popup_type.NK_POPUP_DYNAMIC

NK_POPUP_STATIC: nk_popup_type = nk_popup_type.NK_POPUP_STATIC

NK_RGB: nk_color_format = nk_color_format.NK_RGB

NK_RGBA: nk_color_format = nk_color_format.NK_RGBA

NK_RIGHT: nk_heading = nk_heading.NK_RIGHT

NK_SHOWN: nk_show_states = nk_show_states.NK_SHOWN

NK_STATIC: nk_layout_format = nk_layout_format.NK_STATIC

NK_STROKE_CLOSED: nk_draw_list_stroke = nk_draw_list_stroke.NK_STROKE_CLOSED

NK_STROKE_OPEN: nk_draw_list_stroke = nk_draw_list_stroke.NK_STROKE_OPEN

NK_STYLE_ITEM_COLOR: nk_style_item_type = nk_style_item_type.NK_STYLE_ITEM_COLOR

NK_STYLE_ITEM_IMAGE: nk_style_item_type = nk_style_item_type.NK_STYLE_ITEM_IMAGE

NK_STYLE_ITEM_NINE_SLICE: nk_style_item_type = nk_style_item_type.NK_STYLE_ITEM_NINE_SLICE

NK_SYMBOL_CIRCLE_OUTLINE: nk_symbol_type = nk_symbol_type.NK_SYMBOL_CIRCLE_OUTLINE

NK_SYMBOL_CIRCLE_SOLID: nk_symbol_type = nk_symbol_type.NK_SYMBOL_CIRCLE_SOLID

NK_SYMBOL_MAX: nk_symbol_type = nk_symbol_type.NK_SYMBOL_MAX

NK_SYMBOL_MINUS: nk_symbol_type = nk_symbol_type.NK_SYMBOL_MINUS

NK_SYMBOL_NONE: nk_symbol_type = nk_symbol_type.NK_SYMBOL_NONE

NK_SYMBOL_PLUS: nk_symbol_type = nk_symbol_type.NK_SYMBOL_PLUS

NK_SYMBOL_RECT_OUTLINE: nk_symbol_type = nk_symbol_type.NK_SYMBOL_RECT_OUTLINE

NK_SYMBOL_RECT_SOLID: nk_symbol_type = nk_symbol_type.NK_SYMBOL_RECT_SOLID

NK_SYMBOL_TRIANGLE_DOWN: nk_symbol_type = nk_symbol_type.NK_SYMBOL_TRIANGLE_DOWN

NK_SYMBOL_TRIANGLE_DOWN_OUTLINE: nk_symbol_type = nk_symbol_type.NK_SYMBOL_TRIANGLE_DOWN_OUTLINE

NK_SYMBOL_TRIANGLE_LEFT: nk_symbol_type = nk_symbol_type.NK_SYMBOL_TRIANGLE_LEFT

NK_SYMBOL_TRIANGLE_LEFT_OUTLINE: nk_symbol_type = nk_symbol_type.NK_SYMBOL_TRIANGLE_LEFT_OUTLINE

NK_SYMBOL_TRIANGLE_RIGHT: nk_symbol_type = nk_symbol_type.NK_SYMBOL_TRIANGLE_RIGHT

NK_SYMBOL_TRIANGLE_RIGHT_OUTLINE: nk_symbol_type = nk_symbol_type.NK_SYMBOL_TRIANGLE_RIGHT_OUTLINE

NK_SYMBOL_TRIANGLE_UP: nk_symbol_type = nk_symbol_type.NK_SYMBOL_TRIANGLE_UP

NK_SYMBOL_TRIANGLE_UP_OUTLINE: nk_symbol_type = nk_symbol_type.NK_SYMBOL_TRIANGLE_UP_OUTLINE

NK_SYMBOL_UNDERSCORE: nk_symbol_type = nk_symbol_type.NK_SYMBOL_UNDERSCORE

NK_SYMBOL_X: nk_symbol_type = nk_symbol_type.NK_SYMBOL_X

NK_TEXT_ALIGN_BOTTOM: nk_text_align = nk_text_align.NK_TEXT_ALIGN_BOTTOM

NK_TEXT_ALIGN_CENTERED: nk_text_align = nk_text_align.NK_TEXT_ALIGN_CENTERED

NK_TEXT_ALIGN_LEFT: nk_text_align = nk_text_align.NK_TEXT_ALIGN_LEFT

NK_TEXT_ALIGN_MIDDLE: nk_text_align = nk_text_align.NK_TEXT_ALIGN_MIDDLE

NK_TEXT_ALIGN_RIGHT: nk_text_align = nk_text_align.NK_TEXT_ALIGN_RIGHT

NK_TEXT_ALIGN_TOP: nk_text_align = nk_text_align.NK_TEXT_ALIGN_TOP

NK_TEXT_CENTERED: nk_text_alignment = nk_text_alignment.NK_TEXT_CENTERED

NK_TEXT_EDIT_MODE_INSERT: nk_text_edit_mode = nk_text_edit_mode.NK_TEXT_EDIT_MODE_INSERT

NK_TEXT_EDIT_MODE_REPLACE: nk_text_edit_mode = nk_text_edit_mode.NK_TEXT_EDIT_MODE_REPLACE

NK_TEXT_EDIT_MODE_VIEW: nk_text_edit_mode = nk_text_edit_mode.NK_TEXT_EDIT_MODE_VIEW

NK_TEXT_EDIT_MULTI_LINE: nk_text_edit_type = nk_text_edit_type.NK_TEXT_EDIT_MULTI_LINE

NK_TEXT_EDIT_SINGLE_LINE: nk_text_edit_type = nk_text_edit_type.NK_TEXT_EDIT_SINGLE_LINE

NK_TEXT_LEFT: nk_text_alignment = nk_text_alignment.NK_TEXT_LEFT

NK_TEXT_RIGHT: nk_text_alignment = nk_text_alignment.NK_TEXT_RIGHT

NK_TOP_CENTER: nk_tooltip_pos = nk_tooltip_pos.NK_TOP_CENTER

NK_TOP_LEFT: nk_tooltip_pos = nk_tooltip_pos.NK_TOP_LEFT

NK_TOP_RIGHT: nk_tooltip_pos = nk_tooltip_pos.NK_TOP_RIGHT

NK_TREE_NODE: nk_tree_type = nk_tree_type.NK_TREE_NODE

NK_TREE_TAB: nk_tree_type = nk_tree_type.NK_TREE_TAB

NK_UP: nk_heading = nk_heading.NK_UP

NK_VERTEX_ATTRIBUTE_COUNT: nk_draw_vertex_layout_attribute = nk_draw_vertex_layout_attribute.NK_VERTEX_ATTRIBUTE_COUNT

NK_VERTEX_COLOR: nk_draw_vertex_layout_attribute = nk_draw_vertex_layout_attribute.NK_VERTEX_COLOR

NK_VERTEX_POSITION: nk_draw_vertex_layout_attribute = nk_draw_vertex_layout_attribute.NK_VERTEX_POSITION

NK_VERTEX_TEXCOORD: nk_draw_vertex_layout_attribute = nk_draw_vertex_layout_attribute.NK_VERTEX_TEXCOORD

NK_VERTICAL: nk_orientation = nk_orientation.NK_VERTICAL

NK_WIDGET_ALIGN_BOTTOM: nk_widget_align = nk_widget_align.NK_WIDGET_ALIGN_BOTTOM

NK_WIDGET_ALIGN_CENTERED: nk_widget_align = nk_widget_align.NK_WIDGET_ALIGN_CENTERED

NK_WIDGET_ALIGN_LEFT: nk_widget_align = nk_widget_align.NK_WIDGET_ALIGN_LEFT

NK_WIDGET_ALIGN_MIDDLE: nk_widget_align = nk_widget_align.NK_WIDGET_ALIGN_MIDDLE

NK_WIDGET_ALIGN_RIGHT: nk_widget_align = nk_widget_align.NK_WIDGET_ALIGN_RIGHT

NK_WIDGET_ALIGN_TOP: nk_widget_align = nk_widget_align.NK_WIDGET_ALIGN_TOP

NK_WIDGET_CENTERED: nk_widget_alignment = nk_widget_alignment.NK_WIDGET_CENTERED

NK_WIDGET_DISABLED: nk_widget_layout_states = nk_widget_layout_states.NK_WIDGET_DISABLED

NK_WIDGET_INVALID: nk_widget_layout_states = nk_widget_layout_states.NK_WIDGET_INVALID

NK_WIDGET_LEFT: nk_widget_alignment = nk_widget_alignment.NK_WIDGET_LEFT

NK_WIDGET_RIGHT: nk_widget_alignment = nk_widget_alignment.NK_WIDGET_RIGHT

NK_WIDGET_ROM: nk_widget_layout_states = nk_widget_layout_states.NK_WIDGET_ROM

NK_WIDGET_STATE_ACTIVE: nk_widget_states = nk_widget_states.NK_WIDGET_STATE_ACTIVE

NK_WIDGET_STATE_ACTIVED: nk_widget_states = nk_widget_states.NK_WIDGET_STATE_ACTIVED

NK_WIDGET_STATE_ENTERED: nk_widget_states = nk_widget_states.NK_WIDGET_STATE_ENTERED

NK_WIDGET_STATE_HOVER: nk_widget_states = nk_widget_states.NK_WIDGET_STATE_HOVER

NK_WIDGET_STATE_HOVERED: nk_widget_states = nk_widget_states.NK_WIDGET_STATE_HOVERED

NK_WIDGET_STATE_INACTIVE: nk_widget_states = nk_widget_states.NK_WIDGET_STATE_INACTIVE

NK_WIDGET_STATE_LEFT: nk_widget_states = nk_widget_states.NK_WIDGET_STATE_LEFT

NK_WIDGET_STATE_MODIFIED: nk_widget_states = nk_widget_states.NK_WIDGET_STATE_MODIFIED

NK_WIDGET_VALID: nk_widget_layout_states = nk_widget_layout_states.NK_WIDGET_VALID

NK_WINDOW_BACKGROUND: nk_panel_flags = nk_panel_flags.NK_WINDOW_BACKGROUND

NK_WINDOW_BORDER: nk_panel_flags = nk_panel_flags.NK_WINDOW_BORDER

NK_WINDOW_CLOSABLE: nk_panel_flags = nk_panel_flags.NK_WINDOW_CLOSABLE

NK_WINDOW_CLOSED: nk_window_flags = nk_window_flags.NK_WINDOW_CLOSED

NK_WINDOW_HIDDEN: nk_window_flags = nk_window_flags.NK_WINDOW_HIDDEN

NK_WINDOW_MINIMIZABLE: nk_panel_flags = nk_panel_flags.NK_WINDOW_MINIMIZABLE

NK_WINDOW_MINIMIZED: nk_window_flags = nk_window_flags.NK_WINDOW_MINIMIZED

NK_WINDOW_MOVABLE: nk_panel_flags = nk_panel_flags.NK_WINDOW_MOVABLE

NK_WINDOW_NOT_INTERACTIVE: nk_window_flags = nk_window_flags.NK_WINDOW_NOT_INTERACTIVE

NK_WINDOW_NO_INPUT: nk_panel_flags = nk_panel_flags.NK_WINDOW_NO_INPUT

NK_WINDOW_NO_SCROLLBAR: nk_panel_flags = nk_panel_flags.NK_WINDOW_NO_SCROLLBAR

NK_WINDOW_PRIVATE: nk_window_flags = nk_window_flags.NK_WINDOW_PRIVATE

NK_WINDOW_REMOVE_ROM: nk_window_flags = nk_window_flags.NK_WINDOW_REMOVE_ROM

NK_WINDOW_ROM: nk_window_flags = nk_window_flags.NK_WINDOW_ROM

NK_WINDOW_SCALABLE: nk_panel_flags = nk_panel_flags.NK_WINDOW_SCALABLE

NK_WINDOW_SCALE_LEFT: nk_panel_flags = nk_panel_flags.NK_WINDOW_SCALE_LEFT

NK_WINDOW_SCROLL_AUTO_HIDE: nk_panel_flags = nk_panel_flags.NK_WINDOW_SCROLL_AUTO_HIDE

NK_WINDOW_TITLE: nk_panel_flags = nk_panel_flags.NK_WINDOW_TITLE

def mnk_begin(arg0: nk_context, arg1: str, arg2: nk_rect, arg3: int, /) -> bool:
    """
    extern nk_bool nk_begin(struct nk_context *ctx, const char *title, struct nk_rect bounds, nk_flags flags);
    """

def mnk_begin_titled(arg0: nk_context, arg1: str, arg2: str, arg3: nk_rect, arg4: int, /) -> bool:
    """
    extern nk_bool nk_begin_titled(struct nk_context *ctx, const char *name, const char *title, struct nk_rect bounds, nk_flags flags);
    """

def mnk_buffer_clear(arg: "nk_buffer", /) -> None:
    """extern void nk_buffer_clear(struct nk_buffer*);"""

def mnk_buffer_free(arg: "nk_buffer", /) -> None:
    """extern void nk_buffer_free(struct nk_buffer*);"""

def mnk_buffer_info(arg0: nk_memory_status, arg1: "nk_buffer", /) -> None:
    """
    extern void nk_buffer_info(struct nk_memory_status*, const struct nk_buffer*);
    """

def mnk_buffer_init_default(arg: "nk_buffer", /) -> None:
    """extern void nk_buffer_init_default(struct nk_buffer*);"""

def mnk_buffer_init_fixed(arg0: "nk_buffer", arg1: types.CapsuleType, arg2: int, /) -> None:
    """
    extern void nk_buffer_init_fixed(struct nk_buffer*, void *memory, nk_size size);
    """

def mnk_buffer_mark(arg0: "nk_buffer", arg1: nk_buffer_allocation_type, /) -> None:
    """
    extern void nk_buffer_mark(struct nk_buffer*, enum nk_buffer_allocation_type type);
    """

def mnk_buffer_push(arg0: "nk_buffer", arg1: nk_buffer_allocation_type, arg2: types.CapsuleType, arg3: int, arg4: int, /) -> None:
    """
    extern void nk_buffer_push(struct nk_buffer*, enum nk_buffer_allocation_type type, const void *memory, nk_size size, nk_size align);
    """

def mnk_buffer_reset(arg0: "nk_buffer", arg1: nk_buffer_allocation_type, /) -> None:
    """
    extern void nk_buffer_reset(struct nk_buffer*, enum nk_buffer_allocation_type type);
    """

def mnk_buffer_total(arg: "nk_buffer", /) -> int:
    """extern nk_size nk_buffer_total(const struct nk_buffer*);"""

def mnk_button_color(arg0: nk_context, arg1: nk_color, /) -> bool:
    """extern nk_bool nk_button_color(struct nk_context*, struct nk_color);"""

def mnk_button_image(arg0: nk_context, arg1: nk_image, /) -> bool:
    """
    extern nk_bool nk_button_image(struct nk_context*, struct nk_image img);
    """

def mnk_button_image_label(arg0: nk_context, arg1: nk_image, arg2: str, arg3: int, /) -> bool:
    """
    extern nk_bool nk_button_image_label(struct nk_context*, struct nk_image img, const char*, nk_flags text_alignment);
    """

def mnk_button_image_label_styled(arg0: nk_context, arg1: nk_style_button, arg2: nk_image, arg3: str, arg4: int, /) -> bool:
    """
    extern nk_bool nk_button_image_label_styled(struct nk_context*,const struct nk_style_button*, struct nk_image img, const char*, nk_flags text_alignment);
    """

def mnk_button_image_styled(arg0: nk_context, arg1: nk_style_button, arg2: nk_image, /) -> bool:
    """
    extern nk_bool nk_button_image_styled(struct nk_context*, const struct nk_style_button*, struct nk_image img);
    """

def mnk_button_image_text(arg0: nk_context, arg1: nk_image, arg2: str, arg3: int, arg4: int, /) -> bool:
    """
    extern nk_bool nk_button_image_text(struct nk_context*, struct nk_image img, const char*, int, nk_flags alignment);
    """

def mnk_button_image_text_styled(arg0: nk_context, arg1: nk_style_button, arg2: nk_image, arg3: str, arg4: int, arg5: int, /) -> bool:
    """
    extern nk_bool nk_button_image_text_styled(struct nk_context*,const struct nk_style_button*, struct nk_image img, const char*, int, nk_flags alignment);
    """

def mnk_button_label(arg0: nk_context, arg1: str, /) -> bool:
    """extern nk_bool nk_button_label(struct nk_context*, const char *title);"""

def mnk_button_label_styled(arg0: nk_context, arg1: nk_style_button, arg2: str, /) -> bool:
    """
    extern nk_bool nk_button_label_styled(struct nk_context*, const struct nk_style_button*, const char *title);
    """

def mnk_button_pop_behavior(arg: nk_context, /) -> bool:
    """extern nk_bool nk_button_pop_behavior(struct nk_context*);"""

def mnk_button_push_behavior(arg0: nk_context, arg1: nk_button_behavior, /) -> bool:
    """
    extern nk_bool nk_button_push_behavior(struct nk_context*, enum nk_button_behavior);
    """

def mnk_button_set_behavior(arg0: nk_context, arg1: nk_button_behavior, /) -> None:
    """
    extern void nk_button_set_behavior(struct nk_context*, enum nk_button_behavior);
    """

def mnk_button_symbol(arg0: nk_context, arg1: nk_symbol_type, /) -> bool:
    """
    extern nk_bool nk_button_symbol(struct nk_context*, enum nk_symbol_type);
    """

def mnk_button_symbol_label(arg0: nk_context, arg1: nk_symbol_type, arg2: str, arg3: int, /) -> bool:
    """
    extern nk_bool nk_button_symbol_label(struct nk_context*, enum nk_symbol_type, const char*, nk_flags text_alignment);
    """

def mnk_button_symbol_label_styled(arg0: nk_context, arg1: nk_style_button, arg2: nk_symbol_type, arg3: str, arg4: int, /) -> bool:
    """
    extern nk_bool nk_button_symbol_label_styled(struct nk_context *ctx, const struct nk_style_button *style, enum nk_symbol_type symbol, const char *title, nk_flags align);
    """

def mnk_button_symbol_styled(arg0: nk_context, arg1: nk_style_button, arg2: nk_symbol_type, /) -> bool:
    """
    extern nk_bool nk_button_symbol_styled(struct nk_context*, const struct nk_style_button*, enum nk_symbol_type);
    """

def mnk_button_symbol_text(arg0: nk_context, arg1: nk_symbol_type, arg2: str, arg3: int, arg4: int, /) -> bool:
    """
    extern nk_bool nk_button_symbol_text(struct nk_context*, enum nk_symbol_type, const char*, int, nk_flags alignment);
    """

def mnk_button_symbol_text_styled(arg0: nk_context, arg1: nk_style_button, arg2: nk_symbol_type, arg3: str, arg4: int, arg5: int, /) -> bool:
    """
    extern nk_bool nk_button_symbol_text_styled(struct nk_context*,const struct nk_style_button*, enum nk_symbol_type, const char*, int, nk_flags alignment);
    """

def mnk_button_text(arg0: nk_context, arg1: str, arg2: int, /) -> bool:
    """
    extern nk_bool nk_button_text(struct nk_context*, const char *title, int len);
    """

def mnk_button_text_styled(arg0: nk_context, arg1: nk_style_button, arg2: str, arg3: int, /) -> bool:
    """
    extern nk_bool nk_button_text_styled(struct nk_context*, const struct nk_style_button*, const char *title, int len);
    """

def mnk_chart_add_slot(arg0: nk_context, arg1: nk_chart_type, arg2: int, arg3: float, arg4: float, /) -> None:
    """
    extern void nk_chart_add_slot(struct nk_context *ctx, const enum nk_chart_type, int count, float min_value, float max_value);
    """

def mnk_chart_add_slot_colored(arg0: nk_context, arg1: nk_chart_type, arg2: nk_color, arg3: nk_color, arg4: int, arg5: float, arg6: float, /) -> None:
    """
    extern void nk_chart_add_slot_colored(struct nk_context *ctx, const enum nk_chart_type, struct nk_color, struct nk_color active, int count, float min_value, float max_value);
    """

def mnk_chart_begin(arg0: nk_context, arg1: nk_chart_type, arg2: int, arg3: float, arg4: float, /) -> bool:
    """
    extern nk_bool nk_chart_begin(struct nk_context*, enum nk_chart_type, int num, float min, float max);
    """

def mnk_chart_begin_colored(arg0: nk_context, arg1: nk_chart_type, arg2: nk_color, arg3: nk_color, arg4: int, arg5: float, arg6: float, /) -> bool:
    """
    extern nk_bool nk_chart_begin_colored(struct nk_context*, enum nk_chart_type, struct nk_color, struct nk_color active, int num, float min, float max);
    """

def mnk_chart_end(arg: nk_context, /) -> None:
    """extern void nk_chart_end(struct nk_context*);"""

def mnk_chart_push(arg0: nk_context, arg1: float, /) -> int:
    """extern nk_flags nk_chart_push(struct nk_context*, float);"""

def mnk_chart_push_slot(arg0: nk_context, arg1: float, arg2: int, /) -> int:
    """extern nk_flags nk_chart_push_slot(struct nk_context*, float, int);"""

def mnk_check_flags_label(arg0: nk_context, arg1: str, arg2: int, arg3: int, /) -> int:
    """
    extern unsigned nk_check_flags_label(struct nk_context*, const char*, unsigned int flags, unsigned int value);
    """

def mnk_check_flags_text(arg0: nk_context, arg1: str, arg2: int, arg3: int, arg4: int, /) -> int:
    """
    extern unsigned nk_check_flags_text(struct nk_context*, const char*, int, unsigned int flags, unsigned int value);
    """

def mnk_check_label(arg0: nk_context, arg1: str, arg2: bool, /) -> bool:
    """
    extern nk_bool nk_check_label(struct nk_context*, const char*, nk_bool active);
    """

def mnk_check_text(arg0: nk_context, arg1: str, arg2: int, arg3: bool, /) -> bool:
    """
    extern nk_bool nk_check_text(struct nk_context*, const char*, int, nk_bool active);
    """

def mnk_check_text_align(arg0: nk_context, arg1: str, arg2: int, arg3: bool, arg4: int, arg5: int, /) -> bool:
    """
    extern nk_bool nk_check_text_align(struct nk_context*, const char*, int, nk_bool active, nk_flags widget_alignment, nk_flags text_alignment);
    """

def mnk_checkbox_flags_label(arg0: nk_context, arg1: str, arg2: int, arg3: int, /) -> bool:
    """
    extern nk_bool nk_checkbox_flags_label(struct nk_context*, const char*, unsigned int *flags, unsigned int value);
    """

def mnk_checkbox_flags_text(arg0: nk_context, arg1: str, arg2: int, arg3: int, arg4: int, /) -> bool:
    """
    extern nk_bool nk_checkbox_flags_text(struct nk_context*, const char*, int, unsigned int *flags, unsigned int value);
    """

def mnk_checkbox_label(arg0: nk_context, arg1: str, arg2: bool, /) -> bool:
    """
    extern nk_bool nk_checkbox_label(struct nk_context*, const char*, nk_bool *active);
    """

def mnk_checkbox_label_align(arg0: nk_context, arg1: str, arg2: bool, arg3: int, arg4: int, /) -> bool:
    """
    extern nk_bool nk_checkbox_label_align(struct nk_context *ctx, const char *label, nk_bool *active, nk_flags widget_alignment, nk_flags text_alignment);
    """

def mnk_checkbox_text(arg0: nk_context, arg1: str, arg2: int, arg3: bool, /) -> bool:
    """
    extern nk_bool nk_checkbox_text(struct nk_context*, const char*, int, nk_bool *active);
    """

def mnk_checkbox_text_align(arg0: nk_context, arg1: str, arg2: int, arg3: bool, arg4: int, arg5: int, /) -> bool:
    """
    extern nk_bool nk_checkbox_text_align(struct nk_context *ctx, const char *text, int len, nk_bool *active, nk_flags widget_alignment, nk_flags text_alignment);
    """

def mnk_clear(arg: nk_context, /) -> None:
    """extern void nk_clear(struct nk_context*);"""

def mnk_color_cf(arg: nk_color, /) -> nk_colorf:
    """extern struct nk_colorf nk_color_cf(struct nk_color);"""

def mnk_color_d(arg0: float, arg1: float, arg2: float, arg3: float, arg4: nk_color, /) -> None:
    """
    extern void nk_color_d(double *r, double *g, double *b, double *a, struct nk_color);
    """

def mnk_color_dv(arg0: float, arg1: nk_color, /) -> None:
    """extern void nk_color_dv(double *rgba_out, struct nk_color);"""

def mnk_color_f(arg0: float, arg1: float, arg2: float, arg3: float, arg4: nk_color, /) -> None:
    """
    extern void nk_color_f(float *r, float *g, float *b, float *a, struct nk_color);
    """

def mnk_color_fv(arg0: float, arg1: nk_color, /) -> None:
    """extern void nk_color_fv(float *rgba_out, struct nk_color);"""

def mnk_color_hsv_b(arg0: int, arg1: int, arg2: int, arg3: nk_color, /) -> None:
    """
    extern void nk_color_hsv_b(nk_byte *out_h, nk_byte *out_s, nk_byte *out_v, struct nk_color);
    """

def mnk_color_hsv_bv(arg0: int, arg1: nk_color, /) -> None:
    """extern void nk_color_hsv_bv(nk_byte *hsv_out, struct nk_color);"""

def mnk_color_hsv_f(arg0: float, arg1: float, arg2: float, arg3: nk_color, /) -> None:
    """
    extern void nk_color_hsv_f(float *out_h, float *out_s, float *out_v, struct nk_color);
    """

def mnk_color_hsv_fv(arg0: float, arg1: nk_color, /) -> None:
    """extern void nk_color_hsv_fv(float *hsv_out, struct nk_color);"""

def mnk_color_hsv_i(arg0: int, arg1: int, arg2: int, arg3: nk_color, /) -> None:
    """
    extern void nk_color_hsv_i(int *out_h, int *out_s, int *out_v, struct nk_color);
    """

def mnk_color_hsv_iv(arg0: int, arg1: nk_color, /) -> None:
    """extern void nk_color_hsv_iv(int *hsv_out, struct nk_color);"""

def mnk_color_hsva_b(arg0: int, arg1: int, arg2: int, arg3: int, arg4: nk_color, /) -> None:
    """
    extern void nk_color_hsva_b(nk_byte *h, nk_byte *s, nk_byte *v, nk_byte *a, struct nk_color);
    """

def mnk_color_hsva_bv(arg0: int, arg1: nk_color, /) -> None:
    """extern void nk_color_hsva_bv(nk_byte *hsva_out, struct nk_color);"""

def mnk_color_hsva_f(arg0: float, arg1: float, arg2: float, arg3: float, arg4: nk_color, /) -> None:
    """
    extern void nk_color_hsva_f(float *out_h, float *out_s, float *out_v, float *out_a, struct nk_color);
    """

def mnk_color_hsva_fv(arg0: float, arg1: nk_color, /) -> None:
    """extern void nk_color_hsva_fv(float *hsva_out, struct nk_color);"""

def mnk_color_hsva_i(arg0: int, arg1: int, arg2: int, arg3: int, arg4: nk_color, /) -> None:
    """
    extern void nk_color_hsva_i(int *h, int *s, int *v, int *a, struct nk_color);
    """

def mnk_color_hsva_iv(arg0: int, arg1: nk_color, /) -> None:
    """extern void nk_color_hsva_iv(int *hsva_out, struct nk_color);"""

def mnk_color_pick(arg0: nk_context, arg1: nk_colorf, arg2: nk_color_format, /) -> bool:
    """
    extern nk_bool nk_color_pick(struct nk_context*, struct nk_colorf*, enum nk_color_format);
    """

def mnk_color_picker(arg0: nk_context, arg1: nk_colorf, arg2: nk_color_format, /) -> nk_colorf:
    """
    extern struct nk_colorf nk_color_picker(struct nk_context*, struct nk_colorf, enum nk_color_format);
    """

def mnk_color_u32(arg: nk_color, /) -> int:
    """extern nk_uint nk_color_u32(struct nk_color);"""

def mnk_colorf_hsva_f(arg0: float, arg1: float, arg2: float, arg3: float, arg4: nk_colorf, /) -> None:
    """
    extern void nk_colorf_hsva_f(float *out_h, float *out_s, float *out_v, float *out_a, struct nk_colorf in);
    """

def mnk_colorf_hsva_fv(arg0: float, arg1: nk_colorf, /) -> None:
    """extern void nk_colorf_hsva_fv(float *hsva, struct nk_colorf in);"""

def mnk_combo(arg0: nk_context, arg1: Sequence[str], arg2: int, arg3: int, arg4: nk_vec2, /) -> int: ...

def mnk_combo_begin_color(arg0: nk_context, arg1: nk_color, arg2: nk_vec2, /) -> bool:
    """
    extern nk_bool nk_combo_begin_color(struct nk_context*, struct nk_color color, struct nk_vec2 size);
    """

def mnk_combo_begin_image(arg0: nk_context, arg1: nk_image, arg2: nk_vec2, /) -> bool:
    """
    extern nk_bool nk_combo_begin_image(struct nk_context*, struct nk_image img, struct nk_vec2 size);
    """

def mnk_combo_begin_image_label(arg0: nk_context, arg1: str, arg2: nk_image, arg3: nk_vec2, /) -> bool:
    """
    extern nk_bool nk_combo_begin_image_label(struct nk_context*, const char *selected, struct nk_image, struct nk_vec2 size);
    """

def mnk_combo_begin_image_text(arg0: nk_context, arg1: str, arg2: int, arg3: nk_image, arg4: nk_vec2, /) -> bool:
    """
    extern nk_bool nk_combo_begin_image_text(struct nk_context*, const char *selected, int, struct nk_image, struct nk_vec2 size);
    """

def mnk_combo_begin_label(arg0: nk_context, arg1: str, arg2: nk_vec2, /) -> bool:
    """
    extern nk_bool nk_combo_begin_label(struct nk_context*, const char *selected, struct nk_vec2 size);
    """

def mnk_combo_begin_symbol(arg0: nk_context, arg1: nk_symbol_type, arg2: nk_vec2, /) -> bool:
    """
    extern nk_bool nk_combo_begin_symbol(struct nk_context*, enum nk_symbol_type, struct nk_vec2 size);
    """

def mnk_combo_begin_symbol_label(arg0: nk_context, arg1: str, arg2: nk_symbol_type, arg3: nk_vec2, /) -> bool:
    """
    extern nk_bool nk_combo_begin_symbol_label(struct nk_context*, const char *selected, enum nk_symbol_type, struct nk_vec2 size);
    """

def mnk_combo_begin_symbol_text(arg0: nk_context, arg1: str, arg2: int, arg3: nk_symbol_type, arg4: nk_vec2, /) -> bool:
    """
    extern nk_bool nk_combo_begin_symbol_text(struct nk_context*, const char *selected, int, enum nk_symbol_type, struct nk_vec2 size);
    """

def mnk_combo_begin_text(arg0: nk_context, arg1: str, arg2: int, arg3: nk_vec2, /) -> bool:
    """
    extern nk_bool nk_combo_begin_text(struct nk_context*, const char *selected, int, struct nk_vec2 size);
    """

def mnk_combo_callback(arg0: nk_context, arg1: "void (void*, int, char const**)", arg2: types.CapsuleType, arg3: int, arg4: int, arg5: int, arg6: nk_vec2, /) -> int:
    """
    extern int nk_combo_callback(struct nk_context*, void(*item_getter)(void*, int, const char**), void *userdata, int selected, int count, int item_height, struct nk_vec2 size);
    """

def mnk_combo_close(arg: nk_context, /) -> None:
    """extern void nk_combo_close(struct nk_context*);"""

def mnk_combo_end(arg: nk_context, /) -> None:
    """extern void nk_combo_end(struct nk_context*);"""

def mnk_combo_item_image_label(arg0: nk_context, arg1: nk_image, arg2: str, arg3: int, /) -> bool:
    """
    extern nk_bool nk_combo_item_image_label(struct nk_context*, struct nk_image, const char*, nk_flags alignment);
    """

def mnk_combo_item_image_text(arg0: nk_context, arg1: nk_image, arg2: str, arg3: int, arg4: int, /) -> bool:
    """
    extern nk_bool nk_combo_item_image_text(struct nk_context*, struct nk_image, const char*, int,nk_flags alignment);
    """

def mnk_combo_item_label(arg0: nk_context, arg1: str, arg2: int, /) -> bool:
    """
    extern nk_bool nk_combo_item_label(struct nk_context*, const char*, nk_flags alignment);
    """

def mnk_combo_item_symbol_label(arg0: nk_context, arg1: nk_symbol_type, arg2: str, arg3: int, /) -> bool:
    """
    extern nk_bool nk_combo_item_symbol_label(struct nk_context*, enum nk_symbol_type, const char*, nk_flags alignment);
    """

def mnk_combo_item_symbol_text(arg0: nk_context, arg1: nk_symbol_type, arg2: str, arg3: int, arg4: int, /) -> bool:
    """
    extern nk_bool nk_combo_item_symbol_text(struct nk_context*, enum nk_symbol_type, const char*, int, nk_flags alignment);
    """

def mnk_combo_item_text(arg0: nk_context, arg1: str, arg2: int, arg3: int, /) -> bool:
    """
    extern nk_bool nk_combo_item_text(struct nk_context*, const char*,int, nk_flags alignment);
    """

def mnk_combo_separator(arg0: nk_context, arg1: str, arg2: int, arg3: int, arg4: int, arg5: int, arg6: nk_vec2, /) -> int:
    """
    extern int nk_combo_separator(struct nk_context*, const char *items_separated_by_separator, int separator, int selected, int count, int item_height, struct nk_vec2 size);
    """

def mnk_combo_string(arg0: nk_context, arg1: str, arg2: int, arg3: int, arg4: int, arg5: nk_vec2, /) -> int:
    """
    extern int nk_combo_string(struct nk_context*, const char *items_separated_by_zeros, int selected, int count, int item_height, struct nk_vec2 size);
    """

def mnk_combobox(arg0: nk_context, arg1: Sequence[str], arg2: int, arg3: int, arg4: nk_vec2, /) -> int: ...

def mnk_combobox_callback(arg0: nk_context, arg1: "void (void*, int, char const**)", arg2: types.CapsuleType, arg3: int, arg4: int, arg5: int, arg6: nk_vec2, /) -> bool:
    """
    extern nk_bool nk_combobox_callback(struct nk_context*, void(*item_getter)(void*, int, const char**), void*, int *selected, int count, int item_height, struct nk_vec2 size);
    """

def mnk_combobox_separator(arg0: nk_context, arg1: str, arg2: int, arg3: int, arg4: int, arg5: int, arg6: nk_vec2, /) -> bool:
    """
    extern nk_bool nk_combobox_separator(struct nk_context*, const char *items_separated_by_separator, int separator, int *selected, int count, int item_height, struct nk_vec2 size);
    """

def mnk_combobox_string(arg0: nk_context, arg1: str, arg2: int, arg3: int, arg4: int, arg5: nk_vec2, /) -> bool:
    """
    extern nk_bool nk_combobox_string(struct nk_context*, const char *items_separated_by_zeros, int *selected, int count, int item_height, struct nk_vec2 size);
    """

def mnk_contextual_begin(arg0: nk_context, arg1: int, arg2: nk_vec2, arg3: nk_rect, /) -> bool:
    """
    extern nk_bool nk_contextual_begin(struct nk_context*, nk_flags, struct nk_vec2, struct nk_rect trigger_bounds);
    """

def mnk_contextual_close(arg: nk_context, /) -> None:
    """extern void nk_contextual_close(struct nk_context*);"""

def mnk_contextual_end(arg: nk_context, /) -> None:
    """extern void nk_contextual_end(struct nk_context*);"""

def mnk_contextual_item_image_label(arg0: nk_context, arg1: nk_image, arg2: str, arg3: int, /) -> bool:
    """
    extern nk_bool nk_contextual_item_image_label(struct nk_context*, struct nk_image, const char*, nk_flags alignment);
    """

def mnk_contextual_item_image_text(arg0: nk_context, arg1: nk_image, arg2: str, arg3: int, arg4: int, /) -> bool:
    """
    extern nk_bool nk_contextual_item_image_text(struct nk_context*, struct nk_image, const char*, int len, nk_flags alignment);
    """

def mnk_contextual_item_label(arg0: nk_context, arg1: str, arg2: int, /) -> bool:
    """
    extern nk_bool nk_contextual_item_label(struct nk_context*, const char*, nk_flags align);
    """

def mnk_contextual_item_symbol_label(arg0: nk_context, arg1: nk_symbol_type, arg2: str, arg3: int, /) -> bool:
    """
    extern nk_bool nk_contextual_item_symbol_label(struct nk_context*, enum nk_symbol_type, const char*, nk_flags alignment);
    """

def mnk_contextual_item_symbol_text(arg0: nk_context, arg1: nk_symbol_type, arg2: str, arg3: int, arg4: int, /) -> bool:
    """
    extern nk_bool nk_contextual_item_symbol_text(struct nk_context*, enum nk_symbol_type, const char*, int, nk_flags alignment);
    """

def mnk_contextual_item_text(arg0: nk_context, arg1: str, arg2: int, arg3: int, /) -> bool:
    """
    extern nk_bool nk_contextual_item_text(struct nk_context*, const char*, int,nk_flags align);
    """

def mnk_convert(arg0: nk_context, arg1: "nk_buffer", arg2: "nk_buffer", arg3: "nk_buffer", arg4: nk_convert_config, /) -> int:
    """
    extern nk_flags nk_convert(struct nk_context*, struct nk_buffer *cmds, struct nk_buffer *vertices, struct nk_buffer *elements, const struct nk_convert_config*);
    """

def mnk_draw_image(arg0: nk_command_buffer, arg1: nk_rect, arg2: nk_image, arg3: nk_color, /) -> None:
    """
    extern void nk_draw_image(struct nk_command_buffer*, struct nk_rect, const struct nk_image*, struct nk_color);
    """

def mnk_draw_list_add_image(arg0: nk_draw_list, arg1: nk_image, arg2: nk_rect, arg3: nk_color, /) -> None:
    """
    extern void nk_draw_list_add_image(struct nk_draw_list*, struct nk_image texture, struct nk_rect rect, struct nk_color);
    """

def mnk_draw_list_add_text(arg0: nk_draw_list, arg1: nk_user_font, arg2: nk_rect, arg3: str, arg4: int, arg5: float, arg6: nk_color, /) -> None:
    """
    extern void nk_draw_list_add_text(struct nk_draw_list*, const struct nk_user_font*, struct nk_rect, const char *text, int len, float font_height, struct nk_color);
    """

def mnk_draw_list_fill_circle(arg0: nk_draw_list, arg1: nk_vec2, arg2: float, arg3: nk_color, arg4: int, /) -> None:
    """
    extern void nk_draw_list_fill_circle(struct nk_draw_list*, struct nk_vec2 center, float radius, struct nk_color col, unsigned int segs);
    """

def mnk_draw_list_fill_poly_convex(arg0: nk_draw_list, arg1: nk_vec2, arg2: int, arg3: nk_color, arg4: nk_anti_aliasing, /) -> None:
    """
    extern void nk_draw_list_fill_poly_convex(struct nk_draw_list*, const struct nk_vec2 *points, const unsigned int count, struct nk_color, enum nk_anti_aliasing);
    """

def mnk_draw_list_fill_rect(arg0: nk_draw_list, arg1: nk_rect, arg2: nk_color, arg3: float, /) -> None:
    """
    extern void nk_draw_list_fill_rect(struct nk_draw_list*, struct nk_rect rect, struct nk_color, float rounding);
    """

def mnk_draw_list_fill_rect_multi_color(arg0: nk_draw_list, arg1: nk_rect, arg2: nk_color, arg3: nk_color, arg4: nk_color, arg5: nk_color, /) -> None:
    """
    extern void nk_draw_list_fill_rect_multi_color(struct nk_draw_list*, struct nk_rect rect, struct nk_color left, struct nk_color top, struct nk_color right, struct nk_color bottom);
    """

def mnk_draw_list_fill_triangle(arg0: nk_draw_list, arg1: nk_vec2, arg2: nk_vec2, arg3: nk_vec2, arg4: nk_color, /) -> None:
    """
    extern void nk_draw_list_fill_triangle(struct nk_draw_list*, struct nk_vec2 a, struct nk_vec2 b, struct nk_vec2 c, struct nk_color);
    """

def mnk_draw_list_init(arg: nk_draw_list, /) -> None:
    """extern void nk_draw_list_init(struct nk_draw_list*);"""

def mnk_draw_list_path_arc_to(arg0: nk_draw_list, arg1: nk_vec2, arg2: float, arg3: float, arg4: float, arg5: int, /) -> None:
    """
    extern void nk_draw_list_path_arc_to(struct nk_draw_list*, struct nk_vec2 center, float radius, float a_min, float a_max, unsigned int segments);
    """

def mnk_draw_list_path_arc_to_fast(arg0: nk_draw_list, arg1: nk_vec2, arg2: float, arg3: int, arg4: int, /) -> None:
    """
    extern void nk_draw_list_path_arc_to_fast(struct nk_draw_list*, struct nk_vec2 center, float radius, int a_min, int a_max);
    """

def mnk_draw_list_path_clear(arg: nk_draw_list, /) -> None:
    """extern void nk_draw_list_path_clear(struct nk_draw_list*);"""

def mnk_draw_list_path_curve_to(arg0: nk_draw_list, arg1: nk_vec2, arg2: nk_vec2, arg3: nk_vec2, arg4: int, /) -> None:
    """
    extern void nk_draw_list_path_curve_to(struct nk_draw_list*, struct nk_vec2 p2, struct nk_vec2 p3, struct nk_vec2 p4, unsigned int num_segments);
    """

def mnk_draw_list_path_fill(arg0: nk_draw_list, arg1: nk_color, /) -> None:
    """
    extern void nk_draw_list_path_fill(struct nk_draw_list*, struct nk_color);
    """

def mnk_draw_list_path_line_to(arg0: nk_draw_list, arg1: nk_vec2, /) -> None:
    """
    extern void nk_draw_list_path_line_to(struct nk_draw_list*, struct nk_vec2 pos);
    """

def mnk_draw_list_path_rect_to(arg0: nk_draw_list, arg1: nk_vec2, arg2: nk_vec2, arg3: float, /) -> None:
    """
    extern void nk_draw_list_path_rect_to(struct nk_draw_list*, struct nk_vec2 a, struct nk_vec2 b, float rounding);
    """

def mnk_draw_list_path_stroke(arg0: nk_draw_list, arg1: nk_color, arg2: nk_draw_list_stroke, arg3: float, /) -> None:
    """
    extern void nk_draw_list_path_stroke(struct nk_draw_list*, struct nk_color, enum nk_draw_list_stroke closed, float thickness);
    """

def mnk_draw_list_setup(arg0: nk_draw_list, arg1: nk_convert_config, arg2: "nk_buffer", arg3: "nk_buffer", arg4: "nk_buffer", arg5: nk_anti_aliasing, arg6: nk_anti_aliasing, /) -> None:
    """
    extern void nk_draw_list_setup(struct nk_draw_list*, const struct nk_convert_config*, struct nk_buffer *cmds, struct nk_buffer *vertices, struct nk_buffer *elements, enum nk_anti_aliasing line_aa,enum nk_anti_aliasing shape_aa);
    """

def mnk_draw_list_stroke_circle(arg0: nk_draw_list, arg1: nk_vec2, arg2: float, arg3: nk_color, arg4: int, arg5: float, /) -> None:
    """
    extern void nk_draw_list_stroke_circle(struct nk_draw_list*, struct nk_vec2 center, float radius, struct nk_color, unsigned int segs, float thickness);
    """

def mnk_draw_list_stroke_curve(arg0: nk_draw_list, arg1: nk_vec2, arg2: nk_vec2, arg3: nk_vec2, arg4: nk_vec2, arg5: nk_color, arg6: int, arg7: float, /) -> None:
    """
    extern void nk_draw_list_stroke_curve(struct nk_draw_list*, struct nk_vec2 p0, struct nk_vec2 cp0, struct nk_vec2 cp1, struct nk_vec2 p1, struct nk_color, unsigned int segments, float thickness);
    """

def mnk_draw_list_stroke_line(arg0: nk_draw_list, arg1: nk_vec2, arg2: nk_vec2, arg3: nk_color, arg4: float, /) -> None:
    """
    extern void nk_draw_list_stroke_line(struct nk_draw_list*, struct nk_vec2 a, struct nk_vec2 b, struct nk_color, float thickness);
    """

def mnk_draw_list_stroke_poly_line(arg0: nk_draw_list, arg1: nk_vec2, arg2: int, arg3: nk_color, arg4: nk_draw_list_stroke, arg5: float, arg6: nk_anti_aliasing, /) -> None:
    """
    extern void nk_draw_list_stroke_poly_line(struct nk_draw_list*, const struct nk_vec2 *pnts, const unsigned int cnt, struct nk_color, enum nk_draw_list_stroke, float thickness, enum nk_anti_aliasing);
    """

def mnk_draw_list_stroke_rect(arg0: nk_draw_list, arg1: nk_rect, arg2: nk_color, arg3: float, arg4: float, /) -> None:
    """
    extern void nk_draw_list_stroke_rect(struct nk_draw_list*, struct nk_rect rect, struct nk_color, float rounding, float thickness);
    """

def mnk_draw_list_stroke_triangle(arg0: nk_draw_list, arg1: nk_vec2, arg2: nk_vec2, arg3: nk_vec2, arg4: nk_color, arg5: float, /) -> None:
    """
    extern void nk_draw_list_stroke_triangle(struct nk_draw_list*, struct nk_vec2 a, struct nk_vec2 b, struct nk_vec2 c, struct nk_color, float thickness);
    """

def mnk_draw_nine_slice(arg0: nk_command_buffer, arg1: nk_rect, arg2: nk_nine_slice, arg3: nk_color, /) -> None:
    """
    extern void nk_draw_nine_slice(struct nk_command_buffer*, struct nk_rect, const struct nk_nine_slice*, struct nk_color);
    """

def mnk_draw_text(arg0: nk_command_buffer, arg1: nk_rect, arg2: str, arg3: int, arg4: nk_user_font, arg5: nk_color, arg6: nk_color, /) -> None:
    """
    extern void nk_draw_text(struct nk_command_buffer*, struct nk_rect, const char *text, int len, const struct nk_user_font*, struct nk_color, struct nk_color);
    """

def mnk_edit_buffer(arg0: nk_context, arg1: int, arg2: nk_text_edit, arg3: "bool (nk_text_edit const*, unsigned int)", /) -> int:
    """
    extern nk_flags nk_edit_buffer(struct nk_context*, nk_flags, struct nk_text_edit*, nk_plugin_filter);
    """

def mnk_edit_focus(arg0: nk_context, arg1: int, /) -> None:
    """extern void nk_edit_focus(struct nk_context*, nk_flags flags);"""

def mnk_edit_string(ctx: nk_context, flags: int, buffer: str, max: int, filter: "bool (nk_text_edit const*, unsigned int)" | None = None) -> tuple[int, str]: ...

def mnk_edit_string_zero_terminated(ctx: nk_context, flags: int, buffer: str, max: int, filter: "bool (nk_text_edit const*, unsigned int)" | None = None) -> tuple[int, str]: ...

def mnk_edit_unfocus(arg: nk_context, /) -> None:
    """extern void nk_edit_unfocus(struct nk_context*);"""

def mnk_end(arg: nk_context, /) -> None:
    """extern void nk_end(struct nk_context *ctx);"""

def mnk_fill_arc(arg0: nk_command_buffer, arg1: float, arg2: float, arg3: float, arg4: float, arg5: float, arg6: nk_color, /) -> None:
    """
    extern void nk_fill_arc(struct nk_command_buffer*, float cx, float cy, float radius, float a_min, float a_max, struct nk_color);
    """

def mnk_fill_circle(arg0: nk_command_buffer, arg1: nk_rect, arg2: nk_color, /) -> None:
    """
    extern void nk_fill_circle(struct nk_command_buffer*, struct nk_rect, struct nk_color);
    """

def mnk_fill_polygon(arg0: nk_command_buffer, arg1: float, arg2: int, arg3: nk_color, /) -> None:
    """
    extern void nk_fill_polygon(struct nk_command_buffer*, const float *points, int point_count, struct nk_color);
    """

def mnk_fill_rect(arg0: nk_command_buffer, arg1: nk_rect, arg2: float, arg3: nk_color, /) -> None:
    """
    extern void nk_fill_rect(struct nk_command_buffer*, struct nk_rect, float rounding, struct nk_color);
    """

def mnk_fill_rect_multi_color(arg0: nk_command_buffer, arg1: nk_rect, arg2: nk_color, arg3: nk_color, arg4: nk_color, arg5: nk_color, /) -> None:
    """
    extern void nk_fill_rect_multi_color(struct nk_command_buffer*, struct nk_rect, struct nk_color left, struct nk_color top, struct nk_color right, struct nk_color bottom);
    """

def mnk_fill_triangle(arg0: nk_command_buffer, arg1: float, arg2: float, arg3: float, arg4: float, arg5: float, arg6: float, arg7: nk_color, /) -> None:
    """
    extern void nk_fill_triangle(struct nk_command_buffer*, float x0, float y0, float x1, float y1, float x2, float y2, struct nk_color);
    """

def mnk_filter_ascii(arg0: nk_text_edit, arg1: int, /) -> bool:
    """
    extern nk_bool nk_filter_ascii(const struct nk_text_edit*, nk_rune unicode);
    """

def mnk_filter_binary(arg0: nk_text_edit, arg1: int, /) -> bool:
    """
    extern nk_bool nk_filter_binary(const struct nk_text_edit*, nk_rune unicode);
    """

def mnk_filter_decimal(arg0: nk_text_edit, arg1: int, /) -> bool:
    """
    extern nk_bool nk_filter_decimal(const struct nk_text_edit*, nk_rune unicode);
    """

def mnk_filter_default(arg0: nk_text_edit, arg1: int, /) -> bool:
    """
    extern nk_bool nk_filter_default(const struct nk_text_edit*, nk_rune unicode);
    """

def mnk_filter_float(arg0: nk_text_edit, arg1: int, /) -> bool:
    """
    extern nk_bool nk_filter_float(const struct nk_text_edit*, nk_rune unicode);
    """

def mnk_filter_hex(arg0: nk_text_edit, arg1: int, /) -> bool:
    """
    extern nk_bool nk_filter_hex(const struct nk_text_edit*, nk_rune unicode);
    """

def mnk_filter_oct(arg0: nk_text_edit, arg1: int, /) -> bool:
    """
    extern nk_bool nk_filter_oct(const struct nk_text_edit*, nk_rune unicode);
    """

def mnk_font_atlas_add_compressed_base85(arg0: "nk_font_atlas", arg1: str, arg2: float, arg3: nk_font_config, /) -> nk_font:
    """
    extern struct nk_font* nk_font_atlas_add_compressed_base85(struct nk_font_atlas*, const char *data, float height, const struct nk_font_config *config);
    """

def mnk_font_atlas_add_default(arg0: "nk_font_atlas", arg1: float, arg2: nk_font_config, /) -> nk_font:
    """
    extern struct nk_font* nk_font_atlas_add_default(struct nk_font_atlas*, float height, const struct nk_font_config*);
    """

def mnk_font_atlas_add_from_file(arg0: "nk_font_atlas", arg1: str, arg2: float, arg3: nk_font_config, /) -> nk_font:
    """
    extern struct nk_font* nk_font_atlas_add_from_file(struct nk_font_atlas *atlas, const char *file_path, float height, const struct nk_font_config*);
    """

def mnk_font_atlas_add_from_memory(arg0: "nk_font_atlas", arg1: types.CapsuleType, arg2: int, arg3: float, arg4: nk_font_config, /) -> nk_font:
    """
    extern struct nk_font* nk_font_atlas_add_from_memory(struct nk_font_atlas *atlas, void *memory, nk_size size, float height, const struct nk_font_config *config);
    """

def mnk_font_atlas_bake(arg0: "nk_font_atlas", arg1: int, arg2: int, arg3: nk_font_atlas_format, /) -> types.CapsuleType:
    """
    extern const void* nk_font_atlas_bake(struct nk_font_atlas*, int *width, int *height, enum nk_font_atlas_format);
    """

def mnk_font_atlas_begin(arg: "nk_font_atlas", /) -> None:
    """extern void nk_font_atlas_begin(struct nk_font_atlas*);"""

def mnk_font_atlas_cleanup(arg: "nk_font_atlas", /) -> None:
    """extern void nk_font_atlas_cleanup(struct nk_font_atlas *atlas);"""

def mnk_font_atlas_clear(arg: "nk_font_atlas", /) -> None:
    """extern void nk_font_atlas_clear(struct nk_font_atlas*);"""

def mnk_font_atlas_end(arg0: "nk_font_atlas", arg1: "nk_handle", arg2: nk_draw_null_texture, /) -> None:
    """
    extern void nk_font_atlas_end(struct nk_font_atlas*, nk_handle tex, struct nk_draw_null_texture*);
    """

def mnk_font_atlas_init_default(arg: "nk_font_atlas", /) -> None:
    """extern void nk_font_atlas_init_default(struct nk_font_atlas*);"""

def mnk_font_config(arg: float, /) -> nk_font_config:
    """extern struct nk_font_config nk_font_config(float pixel_height);"""

def mnk_font_find_glyph(arg0: nk_font, arg1: int, /) -> nk_font_glyph:
    """
    extern const struct nk_font_glyph* nk_font_find_glyph(const struct nk_font*, nk_rune unicode);
    """

def mnk_free(arg: nk_context, /) -> None:
    """extern void nk_free(struct nk_context*);"""

def mnk_get_null_rect() -> nk_rect:
    """extern struct nk_rect nk_get_null_rect(void);"""

def mnk_group_begin(arg0: nk_context, arg1: str, arg2: int, /) -> bool:
    """
    extern nk_bool nk_group_begin(struct nk_context*, const char *title, nk_flags);
    """

def mnk_group_begin_titled(arg0: nk_context, arg1: str, arg2: str, arg3: int, /) -> bool:
    """
    extern nk_bool nk_group_begin_titled(struct nk_context*, const char *name, const char *title, nk_flags);
    """

def mnk_group_end(arg: nk_context, /) -> None:
    """extern void nk_group_end(struct nk_context*);"""

def mnk_group_get_scroll(arg0: nk_context, arg1: str, arg2: int, arg3: int, /) -> None:
    """
    extern void nk_group_get_scroll(struct nk_context*, const char *id, nk_uint *x_offset, nk_uint *y_offset);
    """

def mnk_group_scrolled_begin(arg0: nk_context, arg1: nk_scroll, arg2: str, arg3: int, /) -> bool:
    """
    extern nk_bool nk_group_scrolled_begin(struct nk_context*, struct nk_scroll *off, const char *title, nk_flags);
    """

def mnk_group_scrolled_end(arg: nk_context, /) -> None:
    """extern void nk_group_scrolled_end(struct nk_context*);"""

def mnk_group_scrolled_offset_begin(arg0: nk_context, arg1: int, arg2: int, arg3: str, arg4: int, /) -> bool:
    """
    extern nk_bool nk_group_scrolled_offset_begin(struct nk_context*, nk_uint *x_offset, nk_uint *y_offset, const char *title, nk_flags flags);
    """

def mnk_group_set_scroll(arg0: nk_context, arg1: str, arg2: int, arg3: int, /) -> None:
    """
    extern void nk_group_set_scroll(struct nk_context*, const char *id, nk_uint x_offset, nk_uint y_offset);
    """

def mnk_handle_id(arg: int, /) -> "nk_handle":
    """extern nk_handle nk_handle_id(int);"""

def mnk_handle_ptr(arg: types.CapsuleType, /) -> "nk_handle":
    """extern nk_handle nk_handle_ptr(void*);"""

def mnk_hsv(arg0: int, arg1: int, arg2: int, /) -> nk_color:
    """extern struct nk_color nk_hsv(int h, int s, int v);"""

def mnk_hsv_bv(arg: int, /) -> nk_color:
    """extern struct nk_color nk_hsv_bv(const nk_byte *hsv);"""

def mnk_hsv_f(arg0: float, arg1: float, arg2: float, /) -> nk_color:
    """extern struct nk_color nk_hsv_f(float h, float s, float v);"""

def mnk_hsv_fv(arg: float, /) -> nk_color:
    """extern struct nk_color nk_hsv_fv(const float *hsv);"""

def mnk_hsv_iv(arg: int, /) -> nk_color:
    """extern struct nk_color nk_hsv_iv(const int *hsv);"""

def mnk_hsva(arg0: int, arg1: int, arg2: int, arg3: int, /) -> nk_color:
    """extern struct nk_color nk_hsva(int h, int s, int v, int a);"""

def mnk_hsva_bv(arg: int, /) -> nk_color:
    """extern struct nk_color nk_hsva_bv(const nk_byte *hsva);"""

def mnk_hsva_colorf(arg0: float, arg1: float, arg2: float, arg3: float, /) -> nk_colorf:
    """
    extern struct nk_colorf nk_hsva_colorf(float h, float s, float v, float a);
    """

def mnk_hsva_colorfv(arg: float, /) -> nk_colorf:
    """extern struct nk_colorf nk_hsva_colorfv(const float *c);"""

def mnk_hsva_f(arg0: float, arg1: float, arg2: float, arg3: float, /) -> nk_color:
    """extern struct nk_color nk_hsva_f(float h, float s, float v, float a);"""

def mnk_hsva_fv(arg: float, /) -> nk_color:
    """extern struct nk_color nk_hsva_fv(const float *hsva);"""

def mnk_hsva_iv(arg: int, /) -> nk_color:
    """extern struct nk_color nk_hsva_iv(const int *hsva);"""

def mnk_image(arg0: nk_context, arg1: nk_image, /) -> None:
    """extern void nk_image(struct nk_context*, struct nk_image);"""

def mnk_image_color(arg0: nk_context, arg1: nk_image, arg2: nk_color, /) -> None:
    """
    extern void nk_image_color(struct nk_context*, struct nk_image, struct nk_color);
    """

def mnk_image_handle(arg: "nk_handle", /) -> nk_image:
    """extern struct nk_image nk_image_handle(nk_handle);"""

def mnk_image_id(arg: int, /) -> nk_image:
    """extern struct nk_image nk_image_id(int);"""

def mnk_image_is_subimage(arg: nk_image, /) -> bool:
    """extern nk_bool nk_image_is_subimage(const struct nk_image* img);"""

def mnk_image_ptr(arg: types.CapsuleType, /) -> nk_image:
    """extern struct nk_image nk_image_ptr(void*);"""

def mnk_init_custom(arg0: nk_context, arg1: "nk_buffer", arg2: "nk_buffer", arg3: nk_user_font, /) -> bool:
    """
    extern nk_bool nk_init_custom(struct nk_context*, struct nk_buffer *cmds, struct nk_buffer *pool, const struct nk_user_font*);
    """

def mnk_init_default(arg0: nk_context, arg1: nk_user_font, /) -> bool:
    """
    extern nk_bool nk_init_default(struct nk_context*, const struct nk_user_font*);
    """

def mnk_init_fixed(arg0: nk_context, arg1: types.CapsuleType, arg2: int, arg3: nk_user_font, /) -> bool:
    """
    extern nk_bool nk_init_fixed(struct nk_context*, void *memory, nk_size size, const struct nk_user_font*);
    """

def mnk_input_any_mouse_click_in_rect(arg0: nk_input, arg1: nk_rect, /) -> bool:
    """
    extern nk_bool nk_input_any_mouse_click_in_rect(const struct nk_input*, struct nk_rect);
    """

def mnk_input_begin(arg: nk_context, /) -> None:
    """extern void nk_input_begin(struct nk_context*);"""

def mnk_input_button(arg0: nk_context, arg1: nk_buttons, arg2: int, arg3: int, arg4: bool, /) -> None:
    """
    extern void nk_input_button(struct nk_context*, enum nk_buttons, int x, int y, nk_bool down);
    """

def mnk_input_char(arg0: nk_context, arg1: str, /) -> None:
    """extern void nk_input_char(struct nk_context*, char);"""

def mnk_input_end(arg: nk_context, /) -> None:
    """extern void nk_input_end(struct nk_context*);"""

def mnk_input_glyph(arg0: nk_context, arg1: str, /) -> None:
    """extern void nk_input_glyph(struct nk_context*, const nk_glyph);"""

def mnk_input_has_mouse_click(arg0: nk_input, arg1: nk_buttons, /) -> bool:
    """
    extern nk_bool nk_input_has_mouse_click(const struct nk_input*, enum nk_buttons);
    """

def mnk_input_has_mouse_click_down_in_rect(arg0: nk_input, arg1: nk_buttons, arg2: nk_rect, arg3: bool, /) -> bool:
    """
    extern nk_bool nk_input_has_mouse_click_down_in_rect(const struct nk_input*, enum nk_buttons, struct nk_rect, nk_bool down);
    """

def mnk_input_has_mouse_click_in_button_rect(arg0: nk_input, arg1: nk_buttons, arg2: nk_rect, /) -> bool:
    """
    extern nk_bool nk_input_has_mouse_click_in_button_rect(const struct nk_input*, enum nk_buttons, struct nk_rect);
    """

def mnk_input_has_mouse_click_in_rect(arg0: nk_input, arg1: nk_buttons, arg2: nk_rect, /) -> bool:
    """
    extern nk_bool nk_input_has_mouse_click_in_rect(const struct nk_input*, enum nk_buttons, struct nk_rect);
    """

def mnk_input_is_key_down(arg0: nk_input, arg1: nk_keys, /) -> bool:
    """
    extern nk_bool nk_input_is_key_down(const struct nk_input*, enum nk_keys);
    """

def mnk_input_is_key_pressed(arg0: nk_input, arg1: nk_keys, /) -> bool:
    """
    extern nk_bool nk_input_is_key_pressed(const struct nk_input*, enum nk_keys);
    """

def mnk_input_is_key_released(arg0: nk_input, arg1: nk_keys, /) -> bool:
    """
    extern nk_bool nk_input_is_key_released(const struct nk_input*, enum nk_keys);
    """

def mnk_input_is_mouse_click_down_in_rect(arg0: nk_input, arg1: nk_buttons, arg2: nk_rect, arg3: bool, /) -> bool:
    """
    extern nk_bool nk_input_is_mouse_click_down_in_rect(const struct nk_input *i, enum nk_buttons id, struct nk_rect b, nk_bool down);
    """

def mnk_input_is_mouse_click_in_rect(arg0: nk_input, arg1: nk_buttons, arg2: nk_rect, /) -> bool:
    """
    extern nk_bool nk_input_is_mouse_click_in_rect(const struct nk_input*, enum nk_buttons, struct nk_rect);
    """

def mnk_input_is_mouse_down(arg0: nk_input, arg1: nk_buttons, /) -> bool:
    """
    extern nk_bool nk_input_is_mouse_down(const struct nk_input*, enum nk_buttons);
    """

def mnk_input_is_mouse_hovering_rect(arg0: nk_input, arg1: nk_rect, /) -> bool:
    """
    extern nk_bool nk_input_is_mouse_hovering_rect(const struct nk_input*, struct nk_rect);
    """

def mnk_input_is_mouse_moved(arg: nk_input, /) -> bool:
    """extern nk_bool nk_input_is_mouse_moved(const struct nk_input*);"""

def mnk_input_is_mouse_pressed(arg0: nk_input, arg1: nk_buttons, /) -> bool:
    """
    extern nk_bool nk_input_is_mouse_pressed(const struct nk_input*, enum nk_buttons);
    """

def mnk_input_is_mouse_prev_hovering_rect(arg0: nk_input, arg1: nk_rect, /) -> bool:
    """
    extern nk_bool nk_input_is_mouse_prev_hovering_rect(const struct nk_input*, struct nk_rect);
    """

def mnk_input_is_mouse_released(arg0: nk_input, arg1: nk_buttons, /) -> bool:
    """
    extern nk_bool nk_input_is_mouse_released(const struct nk_input*, enum nk_buttons);
    """

def mnk_input_key(arg0: nk_context, arg1: nk_keys, arg2: bool, /) -> None:
    """
    extern void nk_input_key(struct nk_context*, enum nk_keys, nk_bool down);
    """

def mnk_input_motion(arg0: nk_context, arg1: int, arg2: int, /) -> None:
    """extern void nk_input_motion(struct nk_context*, int x, int y);"""

def mnk_input_mouse_clicked(arg0: nk_input, arg1: nk_buttons, arg2: nk_rect, /) -> bool:
    """
    extern nk_bool nk_input_mouse_clicked(const struct nk_input*, enum nk_buttons, struct nk_rect);
    """

def mnk_input_scroll(arg0: nk_context, arg1: nk_vec2, /) -> None:
    """extern void nk_input_scroll(struct nk_context*, struct nk_vec2 val);"""

def mnk_input_unicode(arg0: nk_context, arg1: int, /) -> None:
    """extern void nk_input_unicode(struct nk_context*, nk_rune);"""

def mnk_item_is_any_active(arg: nk_context, /) -> bool:
    """extern nk_bool nk_item_is_any_active(const struct nk_context *ctx);"""

def mnk_knob_float(arg0: nk_context, arg1: float, arg2: float, arg3: float, arg4: float, arg5: nk_heading, arg6: float, /) -> bool:
    """
    extern nk_bool nk_knob_float(struct nk_context*, float min, float *val, float max, float step, enum nk_heading zero_direction, float dead_zone_degrees);
    """

def mnk_knob_int(arg0: nk_context, arg1: int, arg2: int, arg3: int, arg4: int, arg5: nk_heading, arg6: float, /) -> bool:
    """
    extern nk_bool nk_knob_int(struct nk_context*, int min, int *val, int max, int step, enum nk_heading zero_direction, float dead_zone_degrees);
    """

def mnk_label(arg0: nk_context, arg1: str, arg2: int, /) -> None:
    """extern void nk_label(struct nk_context*, const char*, nk_flags align);"""

def mnk_label_colored(arg0: nk_context, arg1: str, arg2: int, arg3: nk_color, /) -> None:
    """
    extern void nk_label_colored(struct nk_context*, const char*, nk_flags align, struct nk_color);
    """

def mnk_label_colored_wrap(arg0: nk_context, arg1: str, arg2: nk_color, /) -> None:
    """
    extern void nk_label_colored_wrap(struct nk_context*, const char*, struct nk_color);
    """

def mnk_label_wrap(arg0: nk_context, arg1: str, /) -> None:
    """extern void nk_label_wrap(struct nk_context*, const char*);"""

def mnk_layout_ratio_from_pixel(arg0: nk_context, arg1: float, /) -> float:
    """
    extern float nk_layout_ratio_from_pixel(const struct nk_context *ctx, float pixel_width);
    """

def mnk_layout_reset_min_row_height(arg: nk_context, /) -> None:
    """extern void nk_layout_reset_min_row_height(struct nk_context*);"""

def mnk_layout_row(arg0: nk_context, arg1: nk_layout_format, arg2: float, arg3: int, arg4: float, /) -> None:
    """
    extern void nk_layout_row(struct nk_context*, enum nk_layout_format, float height, int cols, const float *ratio);
    """

def mnk_layout_row_begin(arg0: nk_context, arg1: nk_layout_format, arg2: float, arg3: int, /) -> None:
    """
    extern void nk_layout_row_begin(struct nk_context *ctx, enum nk_layout_format fmt, float row_height, int cols);
    """

def mnk_layout_row_dynamic(arg0: nk_context, arg1: float, arg2: int, /) -> None:
    """
    extern void nk_layout_row_dynamic(struct nk_context *ctx, float height, int cols);
    """

def mnk_layout_row_end(arg: nk_context, /) -> None:
    """extern void nk_layout_row_end(struct nk_context*);"""

def mnk_layout_row_push(arg0: nk_context, arg1: float, /) -> None:
    """extern void nk_layout_row_push(struct nk_context*, float value);"""

def mnk_layout_row_static(arg0: nk_context, arg1: float, arg2: int, arg3: int, /) -> None:
    """
    extern void nk_layout_row_static(struct nk_context *ctx, float height, int item_width, int cols);
    """

def mnk_layout_row_template_begin(arg0: nk_context, arg1: float, /) -> None:
    """
    extern void nk_layout_row_template_begin(struct nk_context*, float row_height);
    """

def mnk_layout_row_template_end(arg: nk_context, /) -> None:
    """extern void nk_layout_row_template_end(struct nk_context*);"""

def mnk_layout_row_template_push_dynamic(arg: nk_context, /) -> None:
    """extern void nk_layout_row_template_push_dynamic(struct nk_context*);"""

def mnk_layout_row_template_push_static(arg0: nk_context, arg1: float, /) -> None:
    """
    extern void nk_layout_row_template_push_static(struct nk_context*, float width);
    """

def mnk_layout_row_template_push_variable(arg0: nk_context, arg1: float, /) -> None:
    """
    extern void nk_layout_row_template_push_variable(struct nk_context*, float min_width);
    """

def mnk_layout_set_min_row_height(arg0: nk_context, arg1: float, /) -> None:
    """
    extern void nk_layout_set_min_row_height(struct nk_context*, float height);
    """

def mnk_layout_space_begin(arg0: nk_context, arg1: nk_layout_format, arg2: float, arg3: int, /) -> None:
    """
    extern void nk_layout_space_begin(struct nk_context*, enum nk_layout_format, float height, int widget_count);
    """

def mnk_layout_space_bounds(arg: nk_context, /) -> nk_rect:
    """
    extern struct nk_rect nk_layout_space_bounds(const struct nk_context *ctx);
    """

def mnk_layout_space_end(arg: nk_context, /) -> None:
    """extern void nk_layout_space_end(struct nk_context*);"""

def mnk_layout_space_push(arg0: nk_context, arg1: nk_rect, /) -> None:
    """
    extern void nk_layout_space_push(struct nk_context*, struct nk_rect bounds);
    """

def mnk_layout_space_rect_to_local(arg0: nk_context, arg1: nk_rect, /) -> nk_rect:
    """
    extern struct nk_rect nk_layout_space_rect_to_local(const struct nk_context *ctx, struct nk_rect bounds);
    """

def mnk_layout_space_rect_to_screen(arg0: nk_context, arg1: nk_rect, /) -> nk_rect:
    """
    extern struct nk_rect nk_layout_space_rect_to_screen(const struct nk_context *ctx, struct nk_rect bounds);
    """

def mnk_layout_space_to_local(arg0: nk_context, arg1: nk_vec2, /) -> nk_vec2:
    """
    extern struct nk_vec2 nk_layout_space_to_local(const struct nk_context *ctx, struct nk_vec2 vec);
    """

def mnk_layout_space_to_screen(arg0: nk_context, arg1: nk_vec2, /) -> nk_vec2:
    """
    extern struct nk_vec2 nk_layout_space_to_screen(const struct nk_context* ctx, struct nk_vec2 vec);
    """

def mnk_layout_widget_bounds(arg: nk_context, /) -> nk_rect:
    """
    extern struct nk_rect nk_layout_widget_bounds(const struct nk_context *ctx);
    """

def mnk_list_view_begin(arg0: nk_context, arg1: nk_list_view, arg2: str, arg3: int, arg4: int, arg5: int, /) -> bool:
    """
    extern nk_bool nk_list_view_begin(struct nk_context*, struct nk_list_view *out, const char *id, nk_flags, int row_height, int row_count);
    """

def mnk_list_view_end(arg: nk_list_view, /) -> None:
    """extern void nk_list_view_end(struct nk_list_view*);"""

def mnk_menu_begin_image(arg0: nk_context, arg1: str, arg2: nk_image, arg3: nk_vec2, /) -> bool:
    """
    extern nk_bool nk_menu_begin_image(struct nk_context*, const char*, struct nk_image, struct nk_vec2 size);
    """

def mnk_menu_begin_image_label(arg0: nk_context, arg1: str, arg2: int, arg3: nk_image, arg4: nk_vec2, /) -> bool:
    """
    extern nk_bool nk_menu_begin_image_label(struct nk_context*, const char*, nk_flags align,struct nk_image, struct nk_vec2 size);
    """

def mnk_menu_begin_image_text(arg0: nk_context, arg1: str, arg2: int, arg3: int, arg4: nk_image, arg5: nk_vec2, /) -> bool:
    """
    extern nk_bool nk_menu_begin_image_text(struct nk_context*, const char*, int,nk_flags align,struct nk_image, struct nk_vec2 size);
    """

def mnk_menu_begin_label(arg0: nk_context, arg1: str, arg2: int, arg3: nk_vec2, /) -> bool:
    """
    extern nk_bool nk_menu_begin_label(struct nk_context*, const char*, nk_flags align, struct nk_vec2 size);
    """

def mnk_menu_begin_symbol(arg0: nk_context, arg1: str, arg2: nk_symbol_type, arg3: nk_vec2, /) -> bool:
    """
    extern nk_bool nk_menu_begin_symbol(struct nk_context*, const char*, enum nk_symbol_type, struct nk_vec2 size);
    """

def mnk_menu_begin_symbol_label(arg0: nk_context, arg1: str, arg2: int, arg3: nk_symbol_type, arg4: nk_vec2, /) -> bool:
    """
    extern nk_bool nk_menu_begin_symbol_label(struct nk_context*, const char*, nk_flags align,enum nk_symbol_type, struct nk_vec2 size);
    """

def mnk_menu_begin_symbol_text(arg0: nk_context, arg1: str, arg2: int, arg3: int, arg4: nk_symbol_type, arg5: nk_vec2, /) -> bool:
    """
    extern nk_bool nk_menu_begin_symbol_text(struct nk_context*, const char*, int,nk_flags align,enum nk_symbol_type, struct nk_vec2 size);
    """

def mnk_menu_begin_text(arg0: nk_context, arg1: str, arg2: int, arg3: int, arg4: nk_vec2, /) -> bool:
    """
    extern nk_bool nk_menu_begin_text(struct nk_context*, const char* title, int title_len, nk_flags align, struct nk_vec2 size);
    """

def mnk_menu_close(arg: nk_context, /) -> None:
    """extern void nk_menu_close(struct nk_context*);"""

def mnk_menu_end(arg: nk_context, /) -> None:
    """extern void nk_menu_end(struct nk_context*);"""

def mnk_menu_item_image_label(arg0: nk_context, arg1: nk_image, arg2: str, arg3: int, /) -> bool:
    """
    extern nk_bool nk_menu_item_image_label(struct nk_context*, struct nk_image, const char*, nk_flags alignment);
    """

def mnk_menu_item_image_text(arg0: nk_context, arg1: nk_image, arg2: str, arg3: int, arg4: int, /) -> bool:
    """
    extern nk_bool nk_menu_item_image_text(struct nk_context*, struct nk_image, const char*, int len, nk_flags alignment);
    """

def mnk_menu_item_label(arg0: nk_context, arg1: str, arg2: int, /) -> bool:
    """
    extern nk_bool nk_menu_item_label(struct nk_context*, const char*, nk_flags alignment);
    """

def mnk_menu_item_symbol_label(arg0: nk_context, arg1: nk_symbol_type, arg2: str, arg3: int, /) -> bool:
    """
    extern nk_bool nk_menu_item_symbol_label(struct nk_context*, enum nk_symbol_type, const char*, nk_flags alignment);
    """

def mnk_menu_item_symbol_text(arg0: nk_context, arg1: nk_symbol_type, arg2: str, arg3: int, arg4: int, /) -> bool:
    """
    extern nk_bool nk_menu_item_symbol_text(struct nk_context*, enum nk_symbol_type, const char*, int, nk_flags alignment);
    """

def mnk_menu_item_text(arg0: nk_context, arg1: str, arg2: int, arg3: int, /) -> bool:
    """
    extern nk_bool nk_menu_item_text(struct nk_context*, const char*, int,nk_flags align);
    """

def mnk_menubar_begin(arg: nk_context, /) -> None:
    """extern void nk_menubar_begin(struct nk_context*);"""

def mnk_menubar_end(arg: nk_context, /) -> None:
    """extern void nk_menubar_end(struct nk_context*);"""

def mnk_murmur_hash(arg0: types.CapsuleType, arg1: int, arg2: int, /) -> int:
    """extern nk_hash nk_murmur_hash(const void *key, int len, nk_hash seed);"""

def mnk_nine_slice_handle(arg0: "nk_handle", arg1: int, arg2: int, arg3: int, arg4: int, /) -> nk_nine_slice:
    """
    extern struct nk_nine_slice nk_nine_slice_handle(nk_handle, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b);
    """

def mnk_nine_slice_id(arg0: int, arg1: int, arg2: int, arg3: int, arg4: int, /) -> nk_nine_slice:
    """
    extern struct nk_nine_slice nk_nine_slice_id(int, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b);
    """

def mnk_nine_slice_is_sub9slice(arg: nk_nine_slice, /) -> int:
    """
    extern int nk_nine_slice_is_sub9slice(const struct nk_nine_slice* img);
    """

def mnk_nine_slice_ptr(arg0: types.CapsuleType, arg1: int, arg2: int, arg3: int, arg4: int, /) -> nk_nine_slice:
    """
    extern struct nk_nine_slice nk_nine_slice_ptr(void*, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b);
    """

def mnk_option_label(arg0: nk_context, arg1: str, arg2: bool, /) -> bool:
    """
    extern nk_bool nk_option_label(struct nk_context*, const char*, nk_bool active);
    """

def mnk_option_label_align(arg0: nk_context, arg1: str, arg2: bool, arg3: int, arg4: int, /) -> bool:
    """
    extern nk_bool nk_option_label_align(struct nk_context *ctx, const char *label, nk_bool active, nk_flags widget_alignment, nk_flags text_alignment);
    """

def mnk_option_text(arg0: nk_context, arg1: str, arg2: int, arg3: bool, /) -> bool:
    """
    extern nk_bool nk_option_text(struct nk_context*, const char*, int, nk_bool active);
    """

def mnk_option_text_align(arg0: nk_context, arg1: str, arg2: int, arg3: bool, arg4: int, arg5: int, /) -> bool:
    """
    extern nk_bool nk_option_text_align(struct nk_context *ctx, const char *text, int len, nk_bool is_active, nk_flags widget_alignment, nk_flags text_alignment);
    """

def mnk_plot(arg0: nk_context, arg1: nk_chart_type, arg2: float, arg3: int, arg4: int, /) -> None:
    """
    extern void nk_plot(struct nk_context*, enum nk_chart_type, const float *values, int count, int offset);
    """

def mnk_plot_function(arg0: nk_context, arg1: nk_chart_type, arg2: types.CapsuleType, arg3: "float (void*, int)", arg4: int, arg5: int, /) -> None:
    """
    extern void nk_plot_function(struct nk_context*, enum nk_chart_type, void *userdata, float(*value_getter)(void* user, int index), int count, int offset);
    """

def mnk_popup_begin(arg0: nk_context, arg1: nk_popup_type, arg2: str, arg3: int, arg4: nk_rect, /) -> bool:
    """
    extern nk_bool nk_popup_begin(struct nk_context*, enum nk_popup_type, const char*, nk_flags, struct nk_rect bounds);
    """

def mnk_popup_close(arg: nk_context, /) -> None:
    """extern void nk_popup_close(struct nk_context*);"""

def mnk_popup_end(arg: nk_context, /) -> None:
    """extern void nk_popup_end(struct nk_context*);"""

def mnk_popup_get_scroll(arg0: nk_context, arg1: int, arg2: int, /) -> None:
    """
    extern void nk_popup_get_scroll(const struct nk_context*, nk_uint *offset_x, nk_uint *offset_y);
    """

def mnk_popup_set_scroll(arg0: nk_context, arg1: int, arg2: int, /) -> None:
    """
    extern void nk_popup_set_scroll(struct nk_context*, nk_uint offset_x, nk_uint offset_y);
    """

def mnk_prog(arg0: nk_context, arg1: int, arg2: int, arg3: bool, /) -> int:
    """
    extern nk_size nk_prog(struct nk_context*, nk_size cur, nk_size max, nk_bool modifyable);
    """

def mnk_progress(arg0: nk_context, arg1: int, arg2: int, arg3: bool, /) -> bool:
    """
    extern nk_bool nk_progress(struct nk_context*, nk_size *cur, nk_size max, nk_bool modifyable);
    """

def mnk_property_double(arg0: nk_context, arg1: str, arg2: float, arg3: float, arg4: float, arg5: float, arg6: float, /) -> bool:
    """
    extern nk_bool nk_property_double(struct nk_context*, const char *name, double min, double *val, double max, double step, float inc_per_pixel);
    """

def mnk_property_float(arg0: nk_context, arg1: str, arg2: float, arg3: float, arg4: float, arg5: float, arg6: float, /) -> bool:
    """
    extern nk_bool nk_property_float(struct nk_context*, const char *name, float min, float *val, float max, float step, float inc_per_pixel);
    """

def mnk_property_int(arg0: nk_context, arg1: str, arg2: int, arg3: int, arg4: int, arg5: int, arg6: float, /) -> bool:
    """
    extern nk_bool nk_property_int(struct nk_context*, const char *name, int min, int *val, int max, int step, float inc_per_pixel);
    """

def mnk_propertyd(arg0: nk_context, arg1: str, arg2: float, arg3: float, arg4: float, arg5: float, arg6: float, /) -> float:
    """
    extern double nk_propertyd(struct nk_context*, const char *name, double min, double val, double max, double step, float inc_per_pixel);
    """

def mnk_propertyf(arg0: nk_context, arg1: str, arg2: float, arg3: float, arg4: float, arg5: float, arg6: float, /) -> float:
    """
    extern float nk_propertyf(struct nk_context*, const char *name, float min, float val, float max, float step, float inc_per_pixel);
    """

def mnk_propertyi(arg0: nk_context, arg1: str, arg2: int, arg3: int, arg4: int, arg5: int, arg6: float, /) -> int:
    """
    extern int nk_propertyi(struct nk_context*, const char *name, int min, int val, int max, int step, float inc_per_pixel);
    """

def mnk_push_scissor(arg0: nk_command_buffer, arg1: nk_rect, /) -> None:
    """
    extern void nk_push_scissor(struct nk_command_buffer*, struct nk_rect);
    """

def mnk_radio_label(arg0: nk_context, arg1: str, arg2: bool, /) -> bool:
    """
    extern nk_bool nk_radio_label(struct nk_context*, const char*, nk_bool *active);
    """

def mnk_radio_label_align(arg0: nk_context, arg1: str, arg2: bool, arg3: int, arg4: int, /) -> bool:
    """
    extern nk_bool nk_radio_label_align(struct nk_context *ctx, const char *label, nk_bool *active, nk_flags widget_alignment, nk_flags text_alignment);
    """

def mnk_radio_text(arg0: nk_context, arg1: str, arg2: int, arg3: bool, /) -> bool:
    """
    extern nk_bool nk_radio_text(struct nk_context*, const char*, int, nk_bool *active);
    """

def mnk_radio_text_align(arg0: nk_context, arg1: str, arg2: int, arg3: bool, arg4: int, arg5: int, /) -> bool:
    """
    extern nk_bool nk_radio_text_align(struct nk_context *ctx, const char *text, int len, nk_bool *active, nk_flags widget_alignment, nk_flags text_alignment);
    """

def mnk_rect(arg0: float, arg1: float, arg2: float, arg3: float, /) -> nk_rect:
    """extern struct nk_rect nk_rect(float x, float y, float w, float h);"""

def mnk_rect_pos(arg: nk_rect, /) -> nk_vec2:
    """extern struct nk_vec2 nk_rect_pos(struct nk_rect);"""

def mnk_rect_size(arg: nk_rect, /) -> nk_vec2:
    """extern struct nk_vec2 nk_rect_size(struct nk_rect);"""

def mnk_recta(arg0: nk_vec2, arg1: nk_vec2, /) -> nk_rect:
    """
    extern struct nk_rect nk_recta(struct nk_vec2 pos, struct nk_vec2 size);
    """

def mnk_recti(arg0: int, arg1: int, arg2: int, arg3: int, /) -> nk_rect:
    """extern struct nk_rect nk_recti(int x, int y, int w, int h);"""

def mnk_rectiv(arg: int, /) -> nk_rect:
    """extern struct nk_rect nk_rectiv(const int *xywh);"""

def mnk_rectv(arg: float, /) -> nk_rect:
    """extern struct nk_rect nk_rectv(const float *xywh);"""

def mnk_rgb(arg0: int, arg1: int, arg2: int, /) -> nk_color:
    """extern struct nk_color nk_rgb(int r, int g, int b);"""

def mnk_rgb_bv(arg: int, /) -> nk_color:
    """extern struct nk_color nk_rgb_bv(const nk_byte* rgb);"""

def mnk_rgb_cf(arg: nk_colorf, /) -> nk_color:
    """extern struct nk_color nk_rgb_cf(struct nk_colorf c);"""

def mnk_rgb_f(arg0: float, arg1: float, arg2: float, /) -> nk_color:
    """extern struct nk_color nk_rgb_f(float r, float g, float b);"""

def mnk_rgb_factor(arg0: nk_color, arg1: float, /) -> nk_color:
    """
    extern struct nk_color nk_rgb_factor(struct nk_color col, float factor);
    """

def mnk_rgb_fv(arg: float, /) -> nk_color:
    """extern struct nk_color nk_rgb_fv(const float *rgb);"""

def mnk_rgb_hex(arg: str, /) -> nk_color:
    """extern struct nk_color nk_rgb_hex(const char *rgb);"""

def mnk_rgb_iv(arg: int, /) -> nk_color:
    """extern struct nk_color nk_rgb_iv(const int *rgb);"""

def mnk_rgba(arg0: int, arg1: int, arg2: int, arg3: int, /) -> nk_color:
    """extern struct nk_color nk_rgba(int r, int g, int b, int a);"""

def mnk_rgba_bv(arg: int, /) -> nk_color:
    """extern struct nk_color nk_rgba_bv(const nk_byte *rgba);"""

def mnk_rgba_cf(arg: nk_colorf, /) -> nk_color:
    """extern struct nk_color nk_rgba_cf(struct nk_colorf c);"""

def mnk_rgba_f(arg0: float, arg1: float, arg2: float, arg3: float, /) -> nk_color:
    """extern struct nk_color nk_rgba_f(float r, float g, float b, float a);"""

def mnk_rgba_fv(arg: float, /) -> nk_color:
    """extern struct nk_color nk_rgba_fv(const float *rgba);"""

def mnk_rgba_hex(arg: str, /) -> nk_color:
    """extern struct nk_color nk_rgba_hex(const char *rgb);"""

def mnk_rgba_iv(arg: int, /) -> nk_color:
    """extern struct nk_color nk_rgba_iv(const int *rgba);"""

def mnk_rgba_u32(arg: int, /) -> nk_color:
    """extern struct nk_color nk_rgba_u32(nk_uint);"""

def mnk_rule_horizontal(arg0: nk_context, arg1: nk_color, arg2: bool, /) -> None:
    """
    extern void nk_rule_horizontal(struct nk_context *ctx, struct nk_color color, nk_bool rounding);
    """

def mnk_select_image_label(arg0: nk_context, arg1: nk_image, arg2: str, arg3: int, arg4: bool, /) -> bool:
    """
    extern nk_bool nk_select_image_label(struct nk_context*, struct nk_image,const char*, nk_flags align, nk_bool value);
    """

def mnk_select_image_text(arg0: nk_context, arg1: nk_image, arg2: str, arg3: int, arg4: int, arg5: bool, /) -> bool:
    """
    extern nk_bool nk_select_image_text(struct nk_context*, struct nk_image,const char*, int, nk_flags align, nk_bool value);
    """

def mnk_select_label(arg0: nk_context, arg1: str, arg2: int, arg3: bool, /) -> bool:
    """
    extern nk_bool nk_select_label(struct nk_context*, const char*, nk_flags align, nk_bool value);
    """

def mnk_select_symbol_label(arg0: nk_context, arg1: nk_symbol_type, arg2: str, arg3: int, arg4: bool, /) -> bool:
    """
    extern nk_bool nk_select_symbol_label(struct nk_context*,enum nk_symbol_type, const char*, nk_flags align, nk_bool value);
    """

def mnk_select_symbol_text(arg0: nk_context, arg1: nk_symbol_type, arg2: str, arg3: int, arg4: int, arg5: bool, /) -> bool:
    """
    extern nk_bool nk_select_symbol_text(struct nk_context*,enum nk_symbol_type, const char*, int, nk_flags align, nk_bool value);
    """

def mnk_select_text(arg0: nk_context, arg1: str, arg2: int, arg3: int, arg4: bool, /) -> bool:
    """
    extern nk_bool nk_select_text(struct nk_context*, const char*, int, nk_flags align, nk_bool value);
    """

def mnk_selectable_image_label(arg0: nk_context, arg1: nk_image, arg2: str, arg3: int, arg4: bool, /) -> bool:
    """
    extern nk_bool nk_selectable_image_label(struct nk_context*,struct nk_image, const char*, nk_flags align, nk_bool *value);
    """

def mnk_selectable_image_text(arg0: nk_context, arg1: nk_image, arg2: str, arg3: int, arg4: int, arg5: bool, /) -> bool:
    """
    extern nk_bool nk_selectable_image_text(struct nk_context*,struct nk_image, const char*, int, nk_flags align, nk_bool *value);
    """

def mnk_selectable_label(arg0: nk_context, arg1: str, arg2: int, arg3: bool, /) -> bool:
    """
    extern nk_bool nk_selectable_label(struct nk_context*, const char*, nk_flags align, nk_bool *value);
    """

def mnk_selectable_symbol_label(arg0: nk_context, arg1: nk_symbol_type, arg2: str, arg3: int, arg4: bool, /) -> bool:
    """
    extern nk_bool nk_selectable_symbol_label(struct nk_context*,enum nk_symbol_type, const char*, nk_flags align, nk_bool *value);
    """

def mnk_selectable_symbol_text(arg0: nk_context, arg1: nk_symbol_type, arg2: str, arg3: int, arg4: int, arg5: bool, /) -> bool:
    """
    extern nk_bool nk_selectable_symbol_text(struct nk_context*,enum nk_symbol_type, const char*, int, nk_flags align, nk_bool *value);
    """

def mnk_selectable_text(arg0: nk_context, arg1: str, arg2: int, arg3: int, arg4: bool, /) -> bool:
    """
    extern nk_bool nk_selectable_text(struct nk_context*, const char*, int, nk_flags align, nk_bool *value);
    """

def mnk_slide_float(arg0: nk_context, arg1: float, arg2: float, arg3: float, arg4: float, /) -> float:
    """
    extern float nk_slide_float(struct nk_context*, float min, float val, float max, float step);
    """

def mnk_slide_int(arg0: nk_context, arg1: int, arg2: int, arg3: int, arg4: int, /) -> int:
    """
    extern int nk_slide_int(struct nk_context*, int min, int val, int max, int step);
    """

def mnk_slider_float(arg0: nk_context, arg1: float, arg2: float, arg3: float, arg4: float, /) -> bool:
    """
    extern nk_bool nk_slider_float(struct nk_context*, float min, float *val, float max, float step);
    """

def mnk_slider_int(arg0: nk_context, arg1: int, arg2: int, arg3: int, arg4: int, /) -> bool:
    """
    extern nk_bool nk_slider_int(struct nk_context*, int min, int *val, int max, int step);
    """

def mnk_spacer(arg: nk_context, /) -> None:
    """extern void nk_spacer(struct nk_context *ctx);"""

def mnk_spacing(arg0: nk_context, arg1: int, /) -> None:
    """extern void nk_spacing(struct nk_context*, int cols);"""

def mnk_str_append_str_char(arg0: nk_str, arg1: str, /) -> int:
    """extern int nk_str_append_str_char(struct nk_str*, const char*);"""

def mnk_str_append_str_runes(arg0: nk_str, arg1: int, /) -> int:
    """extern int nk_str_append_str_runes(struct nk_str*, const nk_rune*);"""

def mnk_str_append_str_utf8(arg0: nk_str, arg1: str, /) -> int:
    """extern int nk_str_append_str_utf8(struct nk_str*, const char*);"""

def mnk_str_append_text_char(arg0: nk_str, arg1: str, arg2: int, /) -> int:
    """extern int nk_str_append_text_char(struct nk_str*, const char*, int);"""

def mnk_str_append_text_runes(arg0: nk_str, arg1: int, arg2: int, /) -> int:
    """
    extern int nk_str_append_text_runes(struct nk_str*, const nk_rune*, int);
    """

def mnk_str_append_text_utf8(arg0: nk_str, arg1: str, arg2: int, /) -> int:
    """extern int nk_str_append_text_utf8(struct nk_str*, const char*, int);"""

def mnk_str_clear(arg: nk_str, /) -> None:
    """extern void nk_str_clear(struct nk_str*);"""

def mnk_str_delete_chars(arg0: nk_str, arg1: int, arg2: int, /) -> None:
    """extern void nk_str_delete_chars(struct nk_str*, int pos, int len);"""

def mnk_str_delete_runes(arg0: nk_str, arg1: int, arg2: int, /) -> None:
    """extern void nk_str_delete_runes(struct nk_str*, int pos, int len);"""

def mnk_str_free(arg: nk_str, /) -> None:
    """extern void nk_str_free(struct nk_str*);"""

def mnk_str_init_default(arg: nk_str, /) -> None:
    """extern void nk_str_init_default(struct nk_str*);"""

def mnk_str_init_fixed(arg0: nk_str, arg1: types.CapsuleType, arg2: int, /) -> None:
    """
    extern void nk_str_init_fixed(struct nk_str*, void *memory, nk_size size);
    """

def mnk_str_insert_at_char(arg0: nk_str, arg1: int, arg2: str, arg3: int, /) -> int:
    """
    extern int nk_str_insert_at_char(struct nk_str*, int pos, const char*, int);
    """

def mnk_str_insert_at_rune(arg0: nk_str, arg1: int, arg2: str, arg3: int, /) -> int:
    """
    extern int nk_str_insert_at_rune(struct nk_str*, int pos, const char*, int);
    """

def mnk_str_insert_str_char(arg0: nk_str, arg1: int, arg2: str, /) -> int:
    """
    extern int nk_str_insert_str_char(struct nk_str*, int pos, const char*);
    """

def mnk_str_insert_str_runes(arg0: nk_str, arg1: int, arg2: int, /) -> int:
    """
    extern int nk_str_insert_str_runes(struct nk_str*, int pos, const nk_rune*);
    """

def mnk_str_insert_str_utf8(arg0: nk_str, arg1: int, arg2: str, /) -> int:
    """
    extern int nk_str_insert_str_utf8(struct nk_str*, int pos, const char*);
    """

def mnk_str_insert_text_char(arg0: nk_str, arg1: int, arg2: str, arg3: int, /) -> int:
    """
    extern int nk_str_insert_text_char(struct nk_str*, int pos, const char*, int);
    """

def mnk_str_insert_text_runes(arg0: nk_str, arg1: int, arg2: int, arg3: int, /) -> int:
    """
    extern int nk_str_insert_text_runes(struct nk_str*, int pos, const nk_rune*, int);
    """

def mnk_str_insert_text_utf8(arg0: nk_str, arg1: int, arg2: str, arg3: int, /) -> int:
    """
    extern int nk_str_insert_text_utf8(struct nk_str*, int pos, const char*, int);
    """

def mnk_str_len(arg: nk_str, /) -> int:
    """extern int nk_str_len(const struct nk_str*);"""

def mnk_str_len_char(arg: nk_str, /) -> int:
    """extern int nk_str_len_char(const struct nk_str*);"""

def mnk_str_remove_chars(arg0: nk_str, arg1: int, /) -> None:
    """extern void nk_str_remove_chars(struct nk_str*, int len);"""

def mnk_str_remove_runes(arg0: nk_str, arg1: int, /) -> None:
    """extern void nk_str_remove_runes(struct nk_str *str, int len);"""

def mnk_str_rune_at(arg0: nk_str, arg1: int, /) -> int:
    """extern nk_rune nk_str_rune_at(const struct nk_str*, int pos);"""

def mnk_strfilter(arg0: str, arg1: str, /) -> int:
    """extern int nk_strfilter(const char *text, const char *regexp);"""

def mnk_stricmp(arg0: str, arg1: str, /) -> int:
    """extern int nk_stricmp(const char *s1, const char *s2);"""

def mnk_stricmpn(arg0: str, arg1: str, arg2: int, /) -> int:
    """extern int nk_stricmpn(const char *s1, const char *s2, int n);"""

def mnk_strlen(arg: str, /) -> int:
    """extern int nk_strlen(const char *str);"""

def mnk_strmatch_fuzzy_string(arg0: str, arg1: str, arg2: int, /) -> int:
    """
    extern int nk_strmatch_fuzzy_string(char const *str, char const *pattern, int *out_score);
    """

def mnk_strmatch_fuzzy_text(arg0: str, arg1: int, arg2: str, arg3: int, /) -> int:
    """
    extern int nk_strmatch_fuzzy_text(const char *txt, int txt_len, const char *pattern, int *out_score);
    """

def mnk_stroke_arc(arg0: nk_command_buffer, arg1: float, arg2: float, arg3: float, arg4: float, arg5: float, arg6: float, arg7: nk_color, /) -> None:
    """
    extern void nk_stroke_arc(struct nk_command_buffer*, float cx, float cy, float radius, float a_min, float a_max, float line_thickness, struct nk_color);
    """

def mnk_stroke_circle(arg0: nk_command_buffer, arg1: nk_rect, arg2: float, arg3: nk_color, /) -> None:
    """
    extern void nk_stroke_circle(struct nk_command_buffer*, struct nk_rect, float line_thickness, struct nk_color);
    """

def mnk_stroke_curve(arg0: nk_command_buffer, arg1: float, arg2: float, arg3: float, arg4: float, arg5: float, arg6: float, arg7: float, arg8: float, arg9: float, arg10: nk_color, /) -> None:
    """
    extern void nk_stroke_curve(struct nk_command_buffer*, float, float, float, float, float, float, float, float, float line_thickness, struct nk_color);
    """

def mnk_stroke_line(arg0: nk_command_buffer, arg1: float, arg2: float, arg3: float, arg4: float, arg5: float, arg6: nk_color, /) -> None:
    """
    extern void nk_stroke_line(struct nk_command_buffer *b, float x0, float y0, float x1, float y1, float line_thickness, struct nk_color);
    """

def mnk_stroke_polygon(arg0: nk_command_buffer, arg1: float, arg2: int, arg3: float, arg4: nk_color, /) -> None:
    """
    extern void nk_stroke_polygon(struct nk_command_buffer*, const float *points, int point_count, float line_thickness, struct nk_color);
    """

def mnk_stroke_polyline(arg0: nk_command_buffer, arg1: float, arg2: int, arg3: float, arg4: nk_color, /) -> None:
    """
    extern void nk_stroke_polyline(struct nk_command_buffer*, const float *points, int point_count, float line_thickness, struct nk_color col);
    """

def mnk_stroke_rect(arg0: nk_command_buffer, arg1: nk_rect, arg2: float, arg3: float, arg4: nk_color, /) -> None:
    """
    extern void nk_stroke_rect(struct nk_command_buffer*, struct nk_rect, float rounding, float line_thickness, struct nk_color);
    """

def mnk_stroke_triangle(arg0: nk_command_buffer, arg1: float, arg2: float, arg3: float, arg4: float, arg5: float, arg6: float, arg7: float, arg8: nk_color, /) -> None:
    """
    extern void nk_stroke_triangle(struct nk_command_buffer*, float, float, float, float, float, float, float line_thichness, struct nk_color);
    """

def mnk_style_default(arg: nk_context, /) -> None:
    """extern void nk_style_default(struct nk_context*);"""

def mnk_style_from_table(arg0: nk_context, arg1: nk_color, /) -> None:
    """
    extern void nk_style_from_table(struct nk_context*, const struct nk_color*);
    """

def mnk_style_get_color_by_name(arg: nk_style_colors, /) -> str:
    """extern const char* nk_style_get_color_by_name(enum nk_style_colors);"""

def mnk_style_hide_cursor(arg: nk_context, /) -> None:
    """extern void nk_style_hide_cursor(struct nk_context*);"""

def mnk_style_item_color(arg: nk_color, /) -> nk_style_item:
    """extern struct nk_style_item nk_style_item_color(struct nk_color);"""

def mnk_style_item_hide() -> nk_style_item:
    """extern struct nk_style_item nk_style_item_hide(void);"""

def mnk_style_item_image(arg: nk_image, /) -> nk_style_item:
    """extern struct nk_style_item nk_style_item_image(struct nk_image img);"""

def mnk_style_item_nine_slice(arg: nk_nine_slice, /) -> nk_style_item:
    """
    extern struct nk_style_item nk_style_item_nine_slice(struct nk_nine_slice slice);
    """

def mnk_style_load_all_cursors(arg0: nk_context, arg1: nk_cursor, /) -> None:
    """
    extern void nk_style_load_all_cursors(struct nk_context*, const struct nk_cursor*);
    """

def mnk_style_load_cursor(arg0: nk_context, arg1: nk_style_cursor, arg2: nk_cursor, /) -> None:
    """
    extern void nk_style_load_cursor(struct nk_context*, enum nk_style_cursor, const struct nk_cursor*);
    """

def mnk_style_pop_color(arg: nk_context, /) -> bool:
    """extern nk_bool nk_style_pop_color(struct nk_context*);"""

def mnk_style_pop_flags(arg: nk_context, /) -> bool:
    """extern nk_bool nk_style_pop_flags(struct nk_context*);"""

def mnk_style_pop_float(arg: nk_context, /) -> bool:
    """extern nk_bool nk_style_pop_float(struct nk_context*);"""

def mnk_style_pop_font(arg: nk_context, /) -> bool:
    """extern nk_bool nk_style_pop_font(struct nk_context*);"""

def mnk_style_pop_style_item(arg: nk_context, /) -> bool:
    """extern nk_bool nk_style_pop_style_item(struct nk_context*);"""

def mnk_style_pop_vec2(arg: nk_context, /) -> bool:
    """extern nk_bool nk_style_pop_vec2(struct nk_context*);"""

def mnk_style_push_color(arg0: nk_context, arg1: nk_color, arg2: nk_color, /) -> bool:
    """
    extern nk_bool nk_style_push_color(struct nk_context*, struct nk_color*, struct nk_color);
    """

def mnk_style_push_flags(arg0: nk_context, arg1: int, arg2: int, /) -> bool:
    """
    extern nk_bool nk_style_push_flags(struct nk_context*, nk_flags*, nk_flags);
    """

def mnk_style_push_float(arg0: nk_context, arg1: float, arg2: float, /) -> bool:
    """extern nk_bool nk_style_push_float(struct nk_context*, float*, float);"""

def mnk_style_push_font(arg0: nk_context, arg1: nk_user_font, /) -> bool:
    """
    extern nk_bool nk_style_push_font(struct nk_context*, const struct nk_user_font*);
    """

def mnk_style_push_style_item(arg0: nk_context, arg1: nk_style_item, arg2: nk_style_item, /) -> bool:
    """
    extern nk_bool nk_style_push_style_item(struct nk_context*, struct nk_style_item*, struct nk_style_item);
    """

def mnk_style_push_vec2(arg0: nk_context, arg1: nk_vec2, arg2: nk_vec2, /) -> bool:
    """
    extern nk_bool nk_style_push_vec2(struct nk_context*, struct nk_vec2*, struct nk_vec2);
    """

def mnk_style_set_cursor(arg0: nk_context, arg1: nk_style_cursor, /) -> bool:
    """
    extern nk_bool nk_style_set_cursor(struct nk_context*, enum nk_style_cursor);
    """

def mnk_style_set_font(arg0: nk_context, arg1: nk_user_font, /) -> None:
    """
    extern void nk_style_set_font(struct nk_context*, const struct nk_user_font*);
    """

def mnk_style_show_cursor(arg: nk_context, /) -> None:
    """extern void nk_style_show_cursor(struct nk_context*);"""

def mnk_sub9slice_handle(arg0: "nk_handle", arg1: int, arg2: int, arg3: nk_rect, arg4: int, arg5: int, arg6: int, arg7: int, /) -> nk_nine_slice:
    """
    extern struct nk_nine_slice nk_sub9slice_handle(nk_handle, nk_ushort w, nk_ushort h, struct nk_rect sub_region, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b);
    """

def mnk_sub9slice_id(arg0: int, arg1: int, arg2: int, arg3: nk_rect, arg4: int, arg5: int, arg6: int, arg7: int, /) -> nk_nine_slice:
    """
    extern struct nk_nine_slice nk_sub9slice_id(int, nk_ushort w, nk_ushort h, struct nk_rect sub_region, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b);
    """

def mnk_sub9slice_ptr(arg0: types.CapsuleType, arg1: int, arg2: int, arg3: nk_rect, arg4: int, arg5: int, arg6: int, arg7: int, /) -> nk_nine_slice:
    """
    extern struct nk_nine_slice nk_sub9slice_ptr(void*, nk_ushort w, nk_ushort h, struct nk_rect sub_region, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b);
    """

def mnk_subimage_handle(arg0: "nk_handle", arg1: int, arg2: int, arg3: nk_rect, /) -> nk_image:
    """
    extern struct nk_image nk_subimage_handle(nk_handle, nk_ushort w, nk_ushort h, struct nk_rect sub_region);
    """

def mnk_subimage_id(arg0: int, arg1: int, arg2: int, arg3: nk_rect, /) -> nk_image:
    """
    extern struct nk_image nk_subimage_id(int, nk_ushort w, nk_ushort h, struct nk_rect sub_region);
    """

def mnk_subimage_ptr(arg0: types.CapsuleType, arg1: int, arg2: int, arg3: nk_rect, /) -> nk_image:
    """
    extern struct nk_image nk_subimage_ptr(void*, nk_ushort w, nk_ushort h, struct nk_rect sub_region);
    """

def mnk_text(arg0: nk_context, arg1: str, arg2: int, arg3: int, /) -> None:
    """extern void nk_text(struct nk_context*, const char*, int, nk_flags);"""

def mnk_text_colored(arg0: nk_context, arg1: str, arg2: int, arg3: int, arg4: nk_color, /) -> None:
    """
    extern void nk_text_colored(struct nk_context*, const char*, int, nk_flags, struct nk_color);
    """

def mnk_text_wrap(arg0: nk_context, arg1: str, arg2: int, /) -> None:
    """extern void nk_text_wrap(struct nk_context*, const char*, int);"""

def mnk_text_wrap_colored(arg0: nk_context, arg1: str, arg2: int, arg3: nk_color, /) -> None:
    """
    extern void nk_text_wrap_colored(struct nk_context*, const char*, int, struct nk_color);
    """

def mnk_textedit_cut(arg: nk_text_edit, /) -> bool:
    """extern nk_bool nk_textedit_cut(struct nk_text_edit*);"""

def mnk_textedit_delete(arg0: nk_text_edit, arg1: int, arg2: int, /) -> None:
    """
    extern void nk_textedit_delete(struct nk_text_edit*, int where, int len);
    """

def mnk_textedit_delete_selection(arg: nk_text_edit, /) -> None:
    """extern void nk_textedit_delete_selection(struct nk_text_edit*);"""

def mnk_textedit_free(arg: nk_text_edit, /) -> None:
    """extern void nk_textedit_free(struct nk_text_edit*);"""

def mnk_textedit_init_default(arg: nk_text_edit, /) -> None:
    """extern void nk_textedit_init_default(struct nk_text_edit*);"""

def mnk_textedit_init_fixed(arg0: nk_text_edit, arg1: types.CapsuleType, arg2: int, /) -> None:
    """
    extern void nk_textedit_init_fixed(struct nk_text_edit*, void *memory, nk_size size);
    """

def mnk_textedit_paste(arg0: nk_text_edit, arg1: str, arg2: int, /) -> bool:
    """
    extern nk_bool nk_textedit_paste(struct nk_text_edit*, char const*, int len);
    """

def mnk_textedit_redo(arg: nk_text_edit, /) -> None:
    """extern void nk_textedit_redo(struct nk_text_edit*);"""

def mnk_textedit_select_all(arg: nk_text_edit, /) -> None:
    """extern void nk_textedit_select_all(struct nk_text_edit*);"""

def mnk_textedit_text(arg0: nk_text_edit, arg1: str, arg2: int, /) -> None:
    """
    extern void nk_textedit_text(struct nk_text_edit*, const char*, int total_len);
    """

def mnk_textedit_undo(arg: nk_text_edit, /) -> None:
    """extern void nk_textedit_undo(struct nk_text_edit*);"""

def mnk_tooltip(arg0: nk_context, arg1: str, /) -> None:
    """extern void nk_tooltip(struct nk_context*, const char*);"""

def mnk_tooltip_begin(arg0: nk_context, arg1: float, /) -> bool:
    """extern nk_bool nk_tooltip_begin(struct nk_context*, float width);"""

def mnk_tooltip_begin_offset(arg0: nk_context, arg1: float, arg2: nk_tooltip_pos, arg3: nk_vec2, /) -> bool:
    """
    extern nk_bool nk_tooltip_begin_offset(struct nk_context*, float, enum nk_tooltip_pos, struct nk_vec2);
    """

def mnk_tooltip_end(arg: nk_context, /) -> None:
    """extern void nk_tooltip_end(struct nk_context*);"""

def mnk_tooltip_offset(arg0: nk_context, arg1: str, arg2: nk_tooltip_pos, arg3: nk_vec2, /) -> None:
    """
    extern void nk_tooltip_offset(struct nk_context *ctx, const char *text, enum nk_tooltip_pos position, struct nk_vec2 offset);
    """

def mnk_tree_element_image_push_hashed(arg0: nk_context, arg1: nk_tree_type, arg2: nk_image, arg3: str, arg4: nk_collapse_states, arg5: bool, arg6: str, arg7: int, arg8: int, /) -> bool:
    """
    extern nk_bool nk_tree_element_image_push_hashed(struct nk_context*, enum nk_tree_type, struct nk_image, const char *title, enum nk_collapse_states initial_state, nk_bool *selected, const char *hash, int len,int seed);
    """

def mnk_tree_element_pop(arg: nk_context, /) -> None:
    """extern void nk_tree_element_pop(struct nk_context*);"""

def mnk_tree_element_push_hashed(arg0: nk_context, arg1: nk_tree_type, arg2: str, arg3: nk_collapse_states, arg4: bool, arg5: str, arg6: int, arg7: int, /) -> bool:
    """
    extern nk_bool nk_tree_element_push_hashed(struct nk_context*, enum nk_tree_type, const char *title, enum nk_collapse_states initial_state, nk_bool *selected, const char *hash, int len, int seed);
    """

def mnk_tree_image_push_hashed(arg0: nk_context, arg1: nk_tree_type, arg2: nk_image, arg3: str, arg4: nk_collapse_states, arg5: str, arg6: int, arg7: int, /) -> bool:
    """
    extern nk_bool nk_tree_image_push_hashed(struct nk_context*, enum nk_tree_type, struct nk_image, const char *title, enum nk_collapse_states initial_state, const char *hash, int len,int seed);
    """

def mnk_tree_pop(arg: nk_context, /) -> None:
    """extern void nk_tree_pop(struct nk_context*);"""

def mnk_tree_push_hashed(arg0: nk_context, arg1: nk_tree_type, arg2: str, arg3: nk_collapse_states, arg4: str, arg5: int, arg6: int, /) -> bool:
    """
    extern nk_bool nk_tree_push_hashed(struct nk_context*, enum nk_tree_type, const char *title, enum nk_collapse_states initial_state, const char *hash, int len,int seed);
    """

def mnk_tree_state_image_push(arg0: nk_context, arg1: nk_tree_type, arg2: nk_image, arg3: str, arg4: nk_collapse_states, /) -> bool:
    """
    extern nk_bool nk_tree_state_image_push(struct nk_context*, enum nk_tree_type, struct nk_image, const char *title, enum nk_collapse_states *state);
    """

def mnk_tree_state_pop(arg: nk_context, /) -> None:
    """extern void nk_tree_state_pop(struct nk_context*);"""

def mnk_tree_state_push(arg0: nk_context, arg1: nk_tree_type, arg2: str, arg3: nk_collapse_states, /) -> bool:
    """
    extern nk_bool nk_tree_state_push(struct nk_context*, enum nk_tree_type, const char *title, enum nk_collapse_states *state);
    """

def mnk_triangle_from_direction(arg0: nk_vec2, arg1: nk_rect, arg2: float, arg3: float, arg4: nk_heading, /) -> None:
    """
    extern void nk_triangle_from_direction(struct nk_vec2 *result, struct nk_rect r, float pad_x, float pad_y, enum nk_heading);
    """

def mnk_value_bool(arg0: nk_context, arg1: str, arg2: int, /) -> None:
    """
    extern void nk_value_bool(struct nk_context*, const char *prefix, int);
    """

def mnk_value_color_byte(arg0: nk_context, arg1: str, arg2: nk_color, /) -> None:
    """
    extern void nk_value_color_byte(struct nk_context*, const char *prefix, struct nk_color);
    """

def mnk_value_color_float(arg0: nk_context, arg1: str, arg2: nk_color, /) -> None:
    """
    extern void nk_value_color_float(struct nk_context*, const char *prefix, struct nk_color);
    """

def mnk_value_color_hex(arg0: nk_context, arg1: str, arg2: nk_color, /) -> None:
    """
    extern void nk_value_color_hex(struct nk_context*, const char *prefix, struct nk_color);
    """

def mnk_value_float(arg0: nk_context, arg1: str, arg2: float, /) -> None:
    """
    extern void nk_value_float(struct nk_context*, const char *prefix, float);
    """

def mnk_value_int(arg0: nk_context, arg1: str, arg2: int, /) -> None:
    """extern void nk_value_int(struct nk_context*, const char *prefix, int);"""

def mnk_value_uint(arg0: nk_context, arg1: str, arg2: int, /) -> None:
    """
    extern void nk_value_uint(struct nk_context*, const char *prefix, unsigned int);
    """

def mnk_vec2(arg0: float, arg1: float, /) -> nk_vec2:
    """extern struct nk_vec2 nk_vec2(float x, float y);"""

def mnk_vec2i(arg0: int, arg1: int, /) -> nk_vec2:
    """extern struct nk_vec2 nk_vec2i(int x, int y);"""

def mnk_vec2iv(arg: int, /) -> nk_vec2:
    """extern struct nk_vec2 nk_vec2iv(const int *xy);"""

def mnk_vec2v(arg: float, /) -> nk_vec2:
    """extern struct nk_vec2 nk_vec2v(const float *xy);"""

def mnk_widget(arg0: nk_rect, arg1: nk_context, /) -> nk_widget_layout_states:
    """
    extern enum nk_widget_layout_states nk_widget(struct nk_rect*, const struct nk_context*);
    """

def mnk_widget_bounds(arg: nk_context, /) -> nk_rect:
    """extern struct nk_rect nk_widget_bounds(const struct nk_context*);"""

def mnk_widget_disable_begin(arg: nk_context, /) -> None:
    """extern void nk_widget_disable_begin(struct nk_context* ctx);"""

def mnk_widget_disable_end(arg: nk_context, /) -> None:
    """extern void nk_widget_disable_end(struct nk_context* ctx);"""

def mnk_widget_fitting(arg0: nk_rect, arg1: nk_context, arg2: nk_vec2, /) -> nk_widget_layout_states:
    """
    extern enum nk_widget_layout_states nk_widget_fitting(struct nk_rect*, const struct nk_context*, struct nk_vec2);
    """

def mnk_widget_has_mouse_click_down(arg0: nk_context, arg1: nk_buttons, arg2: bool, /) -> bool:
    """
    extern nk_bool nk_widget_has_mouse_click_down(const struct nk_context*, enum nk_buttons, nk_bool down);
    """

def mnk_widget_height(arg: nk_context, /) -> float:
    """extern float nk_widget_height(const struct nk_context*);"""

def mnk_widget_is_hovered(arg: nk_context, /) -> bool:
    """extern nk_bool nk_widget_is_hovered(const struct nk_context*);"""

def mnk_widget_is_mouse_clicked(arg0: nk_context, arg1: nk_buttons, /) -> bool:
    """
    extern nk_bool nk_widget_is_mouse_clicked(const struct nk_context*, enum nk_buttons);
    """

def mnk_widget_position(arg: nk_context, /) -> nk_vec2:
    """extern struct nk_vec2 nk_widget_position(const struct nk_context*);"""

def mnk_widget_size(arg: nk_context, /) -> nk_vec2:
    """extern struct nk_vec2 nk_widget_size(const struct nk_context*);"""

def mnk_widget_width(arg: nk_context, /) -> float:
    """extern float nk_widget_width(const struct nk_context*);"""

def mnk_window_close(arg0: nk_context, arg1: str, /) -> None:
    """extern void nk_window_close(struct nk_context *ctx, const char *name);"""

def mnk_window_collapse(arg0: nk_context, arg1: str, arg2: nk_collapse_states, /) -> None:
    """
    extern void nk_window_collapse(struct nk_context *ctx, const char *name, enum nk_collapse_states state);
    """

def mnk_window_collapse_if(arg0: nk_context, arg1: str, arg2: nk_collapse_states, arg3: int, /) -> None:
    """
    extern void nk_window_collapse_if(struct nk_context *ctx, const char *name, enum nk_collapse_states state, int cond);
    """

def mnk_window_get_bounds(arg: nk_context, /) -> nk_rect:
    """
    extern struct nk_rect nk_window_get_bounds(const struct nk_context *ctx);
    """

def mnk_window_get_canvas(arg: nk_context, /) -> nk_command_buffer:
    """
    extern struct nk_command_buffer* nk_window_get_canvas(const struct nk_context* ctx);
    """

def mnk_window_get_content_region(arg: nk_context, /) -> nk_rect:
    """
    extern struct nk_rect nk_window_get_content_region(const struct nk_context* ctx);
    """

def mnk_window_get_content_region_max(arg: nk_context, /) -> nk_vec2:
    """
    extern struct nk_vec2 nk_window_get_content_region_max(const struct nk_context *ctx);
    """

def mnk_window_get_content_region_min(arg: nk_context, /) -> nk_vec2:
    """
    extern struct nk_vec2 nk_window_get_content_region_min(const struct nk_context *ctx);
    """

def mnk_window_get_content_region_size(arg: nk_context, /) -> nk_vec2:
    """
    extern struct nk_vec2 nk_window_get_content_region_size(const struct nk_context *ctx);
    """

def mnk_window_get_height(arg: nk_context, /) -> float:
    """extern float nk_window_get_height(const struct nk_context* ctx);"""

def mnk_window_get_panel(arg: nk_context, /) -> nk_panel:
    """
    extern struct nk_panel* nk_window_get_panel(const struct nk_context* ctx);
    """

def mnk_window_get_position(arg: nk_context, /) -> nk_vec2:
    """
    extern struct nk_vec2 nk_window_get_position(const struct nk_context *ctx);
    """

def mnk_window_get_scroll(arg0: nk_context, arg1: int, arg2: int, /) -> None:
    """
    extern void nk_window_get_scroll(const struct nk_context *ctx, nk_uint *offset_x, nk_uint *offset_y);
    """

def mnk_window_get_size(arg: nk_context, /) -> nk_vec2:
    """
    extern struct nk_vec2 nk_window_get_size(const struct nk_context *ctx);
    """

def mnk_window_get_width(arg: nk_context, /) -> float:
    """extern float nk_window_get_width(const struct nk_context *ctx);"""

def mnk_window_has_focus(arg: nk_context, /) -> bool:
    """extern nk_bool nk_window_has_focus(const struct nk_context *ctx);"""

def mnk_window_is_active(arg0: nk_context, arg1: str, /) -> bool:
    """
    extern nk_bool nk_window_is_active(const struct nk_context *ctx, const char* name);
    """

def mnk_window_is_any_hovered(arg: nk_context, /) -> bool:
    """extern nk_bool nk_window_is_any_hovered(const struct nk_context *ctx);"""

def mnk_window_is_closed(arg0: nk_context, arg1: str, /) -> bool:
    """
    extern nk_bool nk_window_is_closed(const struct nk_context *ctx, const char* name);
    """

def mnk_window_is_collapsed(arg0: nk_context, arg1: str, /) -> bool:
    """
    extern nk_bool nk_window_is_collapsed(const struct nk_context *ctx, const char *name);
    """

def mnk_window_is_hidden(arg0: nk_context, arg1: str, /) -> bool:
    """
    extern nk_bool nk_window_is_hidden(const struct nk_context *ctx, const char* name);
    """

def mnk_window_is_hovered(arg: nk_context, /) -> bool:
    """extern nk_bool nk_window_is_hovered(const struct nk_context *ctx);"""

def mnk_window_set_bounds(arg0: nk_context, arg1: str, arg2: nk_rect, /) -> None:
    """
    extern void nk_window_set_bounds(struct nk_context *ctx, const char *name, struct nk_rect bounds);
    """

def mnk_window_set_focus(arg0: nk_context, arg1: str, /) -> None:
    """
    extern void nk_window_set_focus(struct nk_context *ctx, const char *name);
    """

def mnk_window_set_position(arg0: nk_context, arg1: str, arg2: nk_vec2, /) -> None:
    """
    extern void nk_window_set_position(struct nk_context *ctx, const char *name, struct nk_vec2 pos);
    """

def mnk_window_set_scroll(arg0: nk_context, arg1: int, arg2: int, /) -> None:
    """
    extern void nk_window_set_scroll(struct nk_context *ctx, nk_uint offset_x, nk_uint offset_y);
    """

def mnk_window_set_size(arg0: nk_context, arg1: str, arg2: nk_vec2, /) -> None:
    """
    extern void nk_window_set_size(struct nk_context *ctx, const char *name, struct nk_vec2 size);
    """

def mnk_window_show(arg0: nk_context, arg1: str, arg2: nk_show_states, /) -> None:
    """
    extern void nk_window_show(struct nk_context *ctx, const char *name, enum nk_show_states state);
    """

def mnk_window_show_if(arg0: nk_context, arg1: str, arg2: nk_show_states, arg3: int, /) -> None:
    """
    extern void nk_window_show_if(struct nk_context *ctx, const char *name, enum nk_show_states state, int cond);
    """

class nk_allocation_type(enum.Enum):
    NK_BUFFER_FIXED = 0

    NK_BUFFER_DYNAMIC = 1

class nk_anti_aliasing(enum.Enum):
    NK_ANTI_ALIASING_OFF = 0

    NK_ANTI_ALIASING_ON = 1

class nk_baked_font:
    def __init__(self) -> None: ...

    @property
    def height(self) -> float: ...

    @height.setter
    def height(self, arg: float, /) -> None: ...

    @property
    def ascent(self) -> float: ...

    @ascent.setter
    def ascent(self, arg: float, /) -> None: ...

    @property
    def descent(self) -> float: ...

    @descent.setter
    def descent(self, arg: float, /) -> None: ...

    @property
    def glyph_offset(self) -> int: ...

    @glyph_offset.setter
    def glyph_offset(self, arg: int, /) -> None: ...

    @property
    def glyph_count(self) -> int: ...

    @glyph_count.setter
    def glyph_count(self, arg: int, /) -> None: ...

class nk_buffer_allocation_type(enum.Enum):
    NK_BUFFER_FRONT = 0

    NK_BUFFER_BACK = 1

    NK_BUFFER_MAX = 2

class nk_buffer_marker:
    def __init__(self) -> None: ...

    @property
    def active(self) -> bool: ...

    @active.setter
    def active(self, arg: bool, /) -> None: ...

    @property
    def offset(self) -> int: ...

    @offset.setter
    def offset(self, arg: int, /) -> None: ...

class nk_button_behavior(enum.Enum):
    NK_BUTTON_DEFAULT = 0

    NK_BUTTON_REPEATER = 1

class nk_buttons(enum.Enum):
    NK_BUTTON_LEFT = 0

    NK_BUTTON_MIDDLE = 1

    NK_BUTTON_RIGHT = 2

    NK_BUTTON_DOUBLE = 3

    NK_BUTTON_MAX = 4

class nk_chart:
    def __init__(self) -> None: ...

    @property
    def slot(self) -> int: ...

    @slot.setter
    def slot(self, arg: int, /) -> None: ...

    @property
    def h(self) -> float: ...

    @h.setter
    def h(self, arg: float, /) -> None: ...

class nk_chart_event(enum.Flag):
    NK_CHART_HOVERING = 1

    NK_CHART_CLICKED = 2

class nk_chart_slot:
    def __init__(self) -> None: ...

    @property
    def type(self) -> nk_chart_type: ...

    @type.setter
    def type(self, arg: nk_chart_type, /) -> None: ...

    @property
    def color(self) -> nk_color: ...

    @color.setter
    def color(self, arg: nk_color, /) -> None: ...

    @property
    def highlight(self) -> nk_color: ...

    @highlight.setter
    def highlight(self, arg: nk_color, /) -> None: ...

    @property
    def range(self) -> float: ...

    @range.setter
    def range(self, arg: float, /) -> None: ...

    @property
    def count(self) -> int: ...

    @count.setter
    def count(self, arg: int, /) -> None: ...

    @property
    def last(self) -> nk_vec2: ...

    @last.setter
    def last(self, arg: nk_vec2, /) -> None: ...

    @property
    def index(self) -> int: ...

    @index.setter
    def index(self, arg: int, /) -> None: ...

    @property
    def show_markers(self) -> bool: ...

    @show_markers.setter
    def show_markers(self, arg: bool, /) -> None: ...

class nk_chart_type(enum.Enum):
    NK_CHART_LINES = 0

    NK_CHART_COLUMN = 1

    NK_CHART_MAX = 2

class nk_clipboard:
    def __init__(self) -> None: ...

    @property
    def userdata(self) -> "nk_handle": ...

    @userdata.setter
    def userdata(self, arg: "nk_handle", /) -> None: ...

class nk_collapse_states(enum.Flag):
    NK_MINIMIZED = 0

    NK_MAXIMIZED = 1

class nk_color:
    def __init__(self) -> None: ...

    @property
    def r(self) -> int: ...

    @r.setter
    def r(self, arg: int, /) -> None: ...

    @property
    def g(self) -> int: ...

    @g.setter
    def g(self, arg: int, /) -> None: ...

    @property
    def b(self) -> int: ...

    @b.setter
    def b(self, arg: int, /) -> None: ...

    @property
    def a(self) -> int: ...

    @a.setter
    def a(self, arg: int, /) -> None: ...

class nk_color_format(enum.Enum):
    NK_RGB = 0

    NK_RGBA = 1

class nk_colorf:
    def __init__(self) -> None: ...

    @property
    def r(self) -> float: ...

    @r.setter
    def r(self, arg: float, /) -> None: ...

    @property
    def g(self) -> float: ...

    @g.setter
    def g(self, arg: float, /) -> None: ...

    @property
    def b(self) -> float: ...

    @b.setter
    def b(self, arg: float, /) -> None: ...

    @property
    def a(self) -> float: ...

    @a.setter
    def a(self, arg: float, /) -> None: ...

class nk_command:
    def __init__(self) -> None: ...

    @property
    def type(self) -> nk_command_type: ...

    @type.setter
    def type(self, arg: nk_command_type, /) -> None: ...

    @property
    def next(self) -> int: ...

    @next.setter
    def next(self, arg: int, /) -> None: ...

class nk_command_arc:
    def __init__(self) -> None: ...

    @property
    def header(self) -> nk_command: ...

    @header.setter
    def header(self, arg: nk_command, /) -> None: ...

    @property
    def cy(self) -> int: ...

    @cy.setter
    def cy(self, arg: int, /) -> None: ...

    @property
    def r(self) -> int: ...

    @r.setter
    def r(self, arg: int, /) -> None: ...

    @property
    def line_thickness(self) -> int: ...

    @line_thickness.setter
    def line_thickness(self, arg: int, /) -> None: ...

    @property
    def color(self) -> nk_color: ...

    @color.setter
    def color(self, arg: nk_color, /) -> None: ...

class nk_command_arc_filled:
    def __init__(self) -> None: ...

    @property
    def header(self) -> nk_command: ...

    @header.setter
    def header(self, arg: nk_command, /) -> None: ...

    @property
    def cy(self) -> int: ...

    @cy.setter
    def cy(self, arg: int, /) -> None: ...

    @property
    def r(self) -> int: ...

    @r.setter
    def r(self, arg: int, /) -> None: ...

    @property
    def color(self) -> nk_color: ...

    @color.setter
    def color(self, arg: nk_color, /) -> None: ...

class nk_command_buffer:
    def __init__(self) -> None: ...

    @property
    def clip(self) -> nk_rect: ...

    @clip.setter
    def clip(self, arg: nk_rect, /) -> None: ...

    @property
    def use_clipping(self) -> int: ...

    @use_clipping.setter
    def use_clipping(self, arg: int, /) -> None: ...

    @property
    def userdata(self) -> "nk_handle": ...

    @userdata.setter
    def userdata(self, arg: "nk_handle", /) -> None: ...

    @property
    def last(self) -> int: ...

    @last.setter
    def last(self, arg: int, /) -> None: ...

class nk_command_circle:
    def __init__(self) -> None: ...

    @property
    def header(self) -> nk_command: ...

    @header.setter
    def header(self, arg: nk_command, /) -> None: ...

    @property
    def y(self) -> int: ...

    @y.setter
    def y(self, arg: int, /) -> None: ...

    @property
    def line_thickness(self) -> int: ...

    @line_thickness.setter
    def line_thickness(self, arg: int, /) -> None: ...

    @property
    def h(self) -> int: ...

    @h.setter
    def h(self, arg: int, /) -> None: ...

    @property
    def color(self) -> nk_color: ...

    @color.setter
    def color(self, arg: nk_color, /) -> None: ...

class nk_command_circle_filled:
    def __init__(self) -> None: ...

    @property
    def header(self) -> nk_command: ...

    @header.setter
    def header(self, arg: nk_command, /) -> None: ...

    @property
    def y(self) -> int: ...

    @y.setter
    def y(self, arg: int, /) -> None: ...

    @property
    def h(self) -> int: ...

    @h.setter
    def h(self, arg: int, /) -> None: ...

    @property
    def color(self) -> nk_color: ...

    @color.setter
    def color(self, arg: nk_color, /) -> None: ...

class nk_command_clipping(enum.Flag):
    NK_CLIPPING_OFF = 0

    NK_CLIPPING_ON = 1

class nk_command_curve:
    def __init__(self) -> None: ...

    @property
    def header(self) -> nk_command: ...

    @header.setter
    def header(self, arg: nk_command, /) -> None: ...

    @property
    def line_thickness(self) -> int: ...

    @line_thickness.setter
    def line_thickness(self, arg: int, /) -> None: ...

    @property
    def begin(self) -> nk_vec2i: ...

    @begin.setter
    def begin(self, arg: nk_vec2i, /) -> None: ...

    @property
    def end(self) -> nk_vec2i: ...

    @end.setter
    def end(self, arg: nk_vec2i, /) -> None: ...

    @property
    def color(self) -> nk_color: ...

    @color.setter
    def color(self, arg: nk_color, /) -> None: ...

class nk_command_image:
    def __init__(self) -> None: ...

    @property
    def header(self) -> nk_command: ...

    @header.setter
    def header(self, arg: nk_command, /) -> None: ...

    @property
    def y(self) -> int: ...

    @y.setter
    def y(self, arg: int, /) -> None: ...

    @property
    def h(self) -> int: ...

    @h.setter
    def h(self, arg: int, /) -> None: ...

    @property
    def img(self) -> nk_image: ...

    @img.setter
    def img(self, arg: nk_image, /) -> None: ...

    @property
    def col(self) -> nk_color: ...

    @col.setter
    def col(self, arg: nk_color, /) -> None: ...

class nk_command_line:
    def __init__(self) -> None: ...

    @property
    def header(self) -> nk_command: ...

    @header.setter
    def header(self, arg: nk_command, /) -> None: ...

    @property
    def line_thickness(self) -> int: ...

    @line_thickness.setter
    def line_thickness(self, arg: int, /) -> None: ...

    @property
    def begin(self) -> nk_vec2i: ...

    @begin.setter
    def begin(self, arg: nk_vec2i, /) -> None: ...

    @property
    def end(self) -> nk_vec2i: ...

    @end.setter
    def end(self, arg: nk_vec2i, /) -> None: ...

    @property
    def color(self) -> nk_color: ...

    @color.setter
    def color(self, arg: nk_color, /) -> None: ...

class nk_command_polygon:
    def __init__(self) -> None: ...

    @property
    def header(self) -> nk_command: ...

    @header.setter
    def header(self, arg: nk_command, /) -> None: ...

    @property
    def color(self) -> nk_color: ...

    @color.setter
    def color(self, arg: nk_color, /) -> None: ...

    @property
    def line_thickness(self) -> int: ...

    @line_thickness.setter
    def line_thickness(self, arg: int, /) -> None: ...

    @property
    def point_count(self) -> int: ...

    @point_count.setter
    def point_count(self, arg: int, /) -> None: ...

class nk_command_polygon_filled:
    def __init__(self) -> None: ...

    @property
    def header(self) -> nk_command: ...

    @header.setter
    def header(self, arg: nk_command, /) -> None: ...

    @property
    def color(self) -> nk_color: ...

    @color.setter
    def color(self, arg: nk_color, /) -> None: ...

    @property
    def point_count(self) -> int: ...

    @point_count.setter
    def point_count(self, arg: int, /) -> None: ...

class nk_command_polyline:
    def __init__(self) -> None: ...

    @property
    def header(self) -> nk_command: ...

    @header.setter
    def header(self, arg: nk_command, /) -> None: ...

    @property
    def color(self) -> nk_color: ...

    @color.setter
    def color(self, arg: nk_color, /) -> None: ...

    @property
    def line_thickness(self) -> int: ...

    @line_thickness.setter
    def line_thickness(self, arg: int, /) -> None: ...

    @property
    def point_count(self) -> int: ...

    @point_count.setter
    def point_count(self, arg: int, /) -> None: ...

class nk_command_rect:
    def __init__(self) -> None: ...

    @property
    def header(self) -> nk_command: ...

    @header.setter
    def header(self, arg: nk_command, /) -> None: ...

    @property
    def rounding(self) -> int: ...

    @rounding.setter
    def rounding(self, arg: int, /) -> None: ...

    @property
    def line_thickness(self) -> int: ...

    @line_thickness.setter
    def line_thickness(self, arg: int, /) -> None: ...

    @property
    def y(self) -> int: ...

    @y.setter
    def y(self, arg: int, /) -> None: ...

    @property
    def h(self) -> int: ...

    @h.setter
    def h(self, arg: int, /) -> None: ...

    @property
    def color(self) -> nk_color: ...

    @color.setter
    def color(self, arg: nk_color, /) -> None: ...

class nk_command_rect_filled:
    def __init__(self) -> None: ...

    @property
    def header(self) -> nk_command: ...

    @header.setter
    def header(self, arg: nk_command, /) -> None: ...

    @property
    def rounding(self) -> int: ...

    @rounding.setter
    def rounding(self, arg: int, /) -> None: ...

    @property
    def y(self) -> int: ...

    @y.setter
    def y(self, arg: int, /) -> None: ...

    @property
    def h(self) -> int: ...

    @h.setter
    def h(self, arg: int, /) -> None: ...

    @property
    def color(self) -> nk_color: ...

    @color.setter
    def color(self, arg: nk_color, /) -> None: ...

class nk_command_rect_multi_color:
    def __init__(self) -> None: ...

    @property
    def header(self) -> nk_command: ...

    @header.setter
    def header(self, arg: nk_command, /) -> None: ...

    @property
    def y(self) -> int: ...

    @y.setter
    def y(self, arg: int, /) -> None: ...

    @property
    def h(self) -> int: ...

    @h.setter
    def h(self, arg: int, /) -> None: ...

    @property
    def left(self) -> nk_color: ...

    @left.setter
    def left(self, arg: nk_color, /) -> None: ...

    @property
    def top(self) -> nk_color: ...

    @top.setter
    def top(self, arg: nk_color, /) -> None: ...

    @property
    def bottom(self) -> nk_color: ...

    @bottom.setter
    def bottom(self, arg: nk_color, /) -> None: ...

    @property
    def right(self) -> nk_color: ...

    @right.setter
    def right(self, arg: nk_color, /) -> None: ...

class nk_command_scissor:
    def __init__(self) -> None: ...

    @property
    def header(self) -> nk_command: ...

    @header.setter
    def header(self, arg: nk_command, /) -> None: ...

    @property
    def y(self) -> int: ...

    @y.setter
    def y(self, arg: int, /) -> None: ...

    @property
    def h(self) -> int: ...

    @h.setter
    def h(self, arg: int, /) -> None: ...

class nk_command_text:
    def __init__(self) -> None: ...

    @property
    def header(self) -> nk_command: ...

    @header.setter
    def header(self, arg: nk_command, /) -> None: ...

    @property
    def background(self) -> nk_color: ...

    @background.setter
    def background(self, arg: nk_color, /) -> None: ...

    @property
    def foreground(self) -> nk_color: ...

    @foreground.setter
    def foreground(self, arg: nk_color, /) -> None: ...

    @property
    def y(self) -> int: ...

    @y.setter
    def y(self, arg: int, /) -> None: ...

    @property
    def h(self) -> int: ...

    @h.setter
    def h(self, arg: int, /) -> None: ...

    @property
    def height(self) -> float: ...

    @height.setter
    def height(self, arg: float, /) -> None: ...

    @property
    def length(self) -> int: ...

    @length.setter
    def length(self, arg: int, /) -> None: ...

class nk_command_triangle:
    def __init__(self) -> None: ...

    @property
    def header(self) -> nk_command: ...

    @header.setter
    def header(self, arg: nk_command, /) -> None: ...

    @property
    def line_thickness(self) -> int: ...

    @line_thickness.setter
    def line_thickness(self, arg: int, /) -> None: ...

    @property
    def a(self) -> nk_vec2i: ...

    @a.setter
    def a(self, arg: nk_vec2i, /) -> None: ...

    @property
    def b(self) -> nk_vec2i: ...

    @b.setter
    def b(self, arg: nk_vec2i, /) -> None: ...

    @property
    def c(self) -> nk_vec2i: ...

    @c.setter
    def c(self, arg: nk_vec2i, /) -> None: ...

    @property
    def color(self) -> nk_color: ...

    @color.setter
    def color(self, arg: nk_color, /) -> None: ...

class nk_command_triangle_filled:
    def __init__(self) -> None: ...

    @property
    def header(self) -> nk_command: ...

    @header.setter
    def header(self, arg: nk_command, /) -> None: ...

    @property
    def a(self) -> nk_vec2i: ...

    @a.setter
    def a(self, arg: nk_vec2i, /) -> None: ...

    @property
    def b(self) -> nk_vec2i: ...

    @b.setter
    def b(self, arg: nk_vec2i, /) -> None: ...

    @property
    def c(self) -> nk_vec2i: ...

    @c.setter
    def c(self, arg: nk_vec2i, /) -> None: ...

    @property
    def color(self) -> nk_color: ...

    @color.setter
    def color(self, arg: nk_color, /) -> None: ...

class nk_command_type(enum.Enum):
    NK_COMMAND_NOP = 0

    NK_COMMAND_SCISSOR = 1

    NK_COMMAND_LINE = 2

    NK_COMMAND_CURVE = 3

    NK_COMMAND_RECT = 4

    NK_COMMAND_RECT_FILLED = 5

    NK_COMMAND_RECT_MULTI_COLOR = 6

    NK_COMMAND_CIRCLE = 7

    NK_COMMAND_CIRCLE_FILLED = 8

    NK_COMMAND_ARC = 9

    NK_COMMAND_ARC_FILLED = 10

    NK_COMMAND_TRIANGLE = 11

    NK_COMMAND_TRIANGLE_FILLED = 12

    NK_COMMAND_POLYGON = 13

    NK_COMMAND_POLYGON_FILLED = 14

    NK_COMMAND_POLYLINE = 15

    NK_COMMAND_TEXT = 16

    NK_COMMAND_IMAGE = 17

    NK_COMMAND_CUSTOM = 18

class nk_config_stack_button_behavior:
    def __init__(self) -> None: ...

    @property
    def head(self) -> int: ...

    @head.setter
    def head(self, arg: int, /) -> None: ...

class nk_config_stack_button_behavior_element:
    def __init__(self) -> None: ...

    @property
    def old_value(self) -> nk_button_behavior: ...

    @old_value.setter
    def old_value(self, arg: nk_button_behavior, /) -> None: ...

class nk_config_stack_color:
    def __init__(self) -> None: ...

    @property
    def head(self) -> int: ...

    @head.setter
    def head(self, arg: int, /) -> None: ...

class nk_config_stack_color_element:
    def __init__(self) -> None: ...

    @property
    def old_value(self) -> nk_color: ...

    @old_value.setter
    def old_value(self, arg: nk_color, /) -> None: ...

class nk_config_stack_flags:
    def __init__(self) -> None: ...

    @property
    def head(self) -> int: ...

    @head.setter
    def head(self, arg: int, /) -> None: ...

class nk_config_stack_flags_element:
    def __init__(self) -> None: ...

    @property
    def old_value(self) -> int: ...

    @old_value.setter
    def old_value(self, arg: int, /) -> None: ...

class nk_config_stack_float:
    def __init__(self) -> None: ...

    @property
    def head(self) -> int: ...

    @head.setter
    def head(self, arg: int, /) -> None: ...

class nk_config_stack_float_element:
    def __init__(self) -> None: ...

    @property
    def old_value(self) -> float: ...

    @old_value.setter
    def old_value(self, arg: float, /) -> None: ...

class nk_config_stack_style_item:
    def __init__(self) -> None: ...

    @property
    def head(self) -> int: ...

    @head.setter
    def head(self, arg: int, /) -> None: ...

class nk_config_stack_style_item_element:
    def __init__(self) -> None: ...

    @property
    def old_value(self) -> nk_style_item: ...

    @old_value.setter
    def old_value(self, arg: nk_style_item, /) -> None: ...

class nk_config_stack_user_font:
    def __init__(self) -> None: ...

    @property
    def head(self) -> int: ...

    @head.setter
    def head(self, arg: int, /) -> None: ...

class nk_config_stack_user_font_element:
    def __init__(self) -> None: ...

class nk_config_stack_vec2:
    def __init__(self) -> None: ...

    @property
    def head(self) -> int: ...

    @head.setter
    def head(self, arg: int, /) -> None: ...

class nk_config_stack_vec2_element:
    def __init__(self) -> None: ...

    @property
    def old_value(self) -> nk_vec2: ...

    @old_value.setter
    def old_value(self, arg: nk_vec2, /) -> None: ...

class nk_configuration_stacks:
    def __init__(self) -> None: ...

    @property
    def style_items(self) -> nk_config_stack_style_item: ...

    @style_items.setter
    def style_items(self, arg: nk_config_stack_style_item, /) -> None: ...

    @property
    def floats(self) -> nk_config_stack_float: ...

    @floats.setter
    def floats(self, arg: nk_config_stack_float, /) -> None: ...

    @property
    def vectors(self) -> nk_config_stack_vec2: ...

    @vectors.setter
    def vectors(self, arg: nk_config_stack_vec2, /) -> None: ...

    @property
    def flags(self) -> nk_config_stack_flags: ...

    @flags.setter
    def flags(self, arg: nk_config_stack_flags, /) -> None: ...

    @property
    def colors(self) -> nk_config_stack_color: ...

    @colors.setter
    def colors(self, arg: nk_config_stack_color, /) -> None: ...

    @property
    def fonts(self) -> nk_config_stack_user_font: ...

    @fonts.setter
    def fonts(self, arg: nk_config_stack_user_font, /) -> None: ...

    @property
    def button_behaviors(self) -> nk_config_stack_button_behavior: ...

    @button_behaviors.setter
    def button_behaviors(self, arg: nk_config_stack_button_behavior, /) -> None: ...

class nk_context:
    def __init__(self) -> None: ...

    @property
    def input(self) -> nk_input: ...

    @input.setter
    def input(self, arg: nk_input, /) -> None: ...

    @property
    def style(self) -> nk_style: ...

    @style.setter
    def style(self, arg: nk_style, /) -> None: ...

    @property
    def memory(self) -> "nk_buffer": ...

    @memory.setter
    def memory(self, arg: "nk_buffer", /) -> None: ...

    @property
    def clip(self) -> nk_clipboard: ...

    @clip.setter
    def clip(self, arg: nk_clipboard, /) -> None: ...

    @property
    def last_widget_state(self) -> int: ...

    @last_widget_state.setter
    def last_widget_state(self, arg: int, /) -> None: ...

    @property
    def button_behavior(self) -> nk_button_behavior: ...

    @button_behavior.setter
    def button_behavior(self, arg: nk_button_behavior, /) -> None: ...

    @property
    def stacks(self) -> nk_configuration_stacks: ...

    @stacks.setter
    def stacks(self, arg: nk_configuration_stacks, /) -> None: ...

    @property
    def delta_time_seconds(self) -> float: ...

    @delta_time_seconds.setter
    def delta_time_seconds(self, arg: float, /) -> None: ...

    @property
    def draw_list(self) -> nk_draw_list: ...

    @draw_list.setter
    def draw_list(self, arg: nk_draw_list, /) -> None: ...

    @property
    def text_edit(self) -> nk_text_edit: ...

    @text_edit.setter
    def text_edit(self, arg: nk_text_edit, /) -> None: ...

    @property
    def overlay(self) -> nk_command_buffer: ...

    @overlay.setter
    def overlay(self, arg: nk_command_buffer, /) -> None: ...

    @property
    def build(self) -> int: ...

    @build.setter
    def build(self, arg: int, /) -> None: ...

    @property
    def use_pool(self) -> int: ...

    @use_pool.setter
    def use_pool(self, arg: int, /) -> None: ...

    @property
    def pool(self) -> "nk_pool": ...

    @pool.setter
    def pool(self, arg: "nk_pool", /) -> None: ...

    @property
    def count(self) -> int: ...

    @count.setter
    def count(self, arg: int, /) -> None: ...

    @property
    def seq(self) -> int: ...

    @seq.setter
    def seq(self, arg: int, /) -> None: ...

class nk_convert_config:
    def __init__(self) -> None: ...

    @property
    def global_alpha(self) -> float: ...

    @global_alpha.setter
    def global_alpha(self, arg: float, /) -> None: ...

    @property
    def line_AA(self) -> nk_anti_aliasing: ...

    @line_AA.setter
    def line_AA(self, arg: nk_anti_aliasing, /) -> None: ...

    @property
    def shape_AA(self) -> nk_anti_aliasing: ...

    @shape_AA.setter
    def shape_AA(self, arg: nk_anti_aliasing, /) -> None: ...

    @property
    def circle_segment_count(self) -> int: ...

    @circle_segment_count.setter
    def circle_segment_count(self, arg: int, /) -> None: ...

    @property
    def arc_segment_count(self) -> int: ...

    @arc_segment_count.setter
    def arc_segment_count(self, arg: int, /) -> None: ...

    @property
    def curve_segment_count(self) -> int: ...

    @curve_segment_count.setter
    def curve_segment_count(self, arg: int, /) -> None: ...

    @property
    def tex_null(self) -> nk_draw_null_texture: ...

    @tex_null.setter
    def tex_null(self, arg: nk_draw_null_texture, /) -> None: ...

    @property
    def vertex_size(self) -> int: ...

    @vertex_size.setter
    def vertex_size(self, arg: int, /) -> None: ...

    @property
    def vertex_alignment(self) -> int: ...

    @vertex_alignment.setter
    def vertex_alignment(self, arg: int, /) -> None: ...

class nk_convert_result(enum.Flag):
    NK_CONVERT_SUCCESS = 0

    NK_CONVERT_INVALID_PARAM = 1

    NK_CONVERT_COMMAND_BUFFER_FULL = 2

    NK_CONVERT_VERTEX_BUFFER_FULL = 4

    NK_CONVERT_ELEMENT_BUFFER_FULL = 8

class nk_cursor:
    def __init__(self) -> None: ...

    @property
    def img(self) -> nk_image: ...

    @img.setter
    def img(self, arg: nk_image, /) -> None: ...

    @property
    def offset(self) -> nk_vec2: ...

    @offset.setter
    def offset(self, arg: nk_vec2, /) -> None: ...

class nk_draw_command:
    def __init__(self) -> None: ...

    @property
    def elem_count(self) -> int: ...

    @elem_count.setter
    def elem_count(self, arg: int, /) -> None: ...

    @property
    def clip_rect(self) -> nk_rect: ...

    @clip_rect.setter
    def clip_rect(self, arg: nk_rect, /) -> None: ...

    @property
    def texture(self) -> "nk_handle": ...

    @texture.setter
    def texture(self, arg: "nk_handle", /) -> None: ...

class nk_draw_list:
    def __init__(self) -> None: ...

    @property
    def clip_rect(self) -> nk_rect: ...

    @clip_rect.setter
    def clip_rect(self, arg: nk_rect, /) -> None: ...

    @property
    def config(self) -> nk_convert_config: ...

    @config.setter
    def config(self, arg: nk_convert_config, /) -> None: ...

    @property
    def element_count(self) -> int: ...

    @element_count.setter
    def element_count(self, arg: int, /) -> None: ...

    @property
    def vertex_count(self) -> int: ...

    @vertex_count.setter
    def vertex_count(self, arg: int, /) -> None: ...

    @property
    def cmd_count(self) -> int: ...

    @cmd_count.setter
    def cmd_count(self, arg: int, /) -> None: ...

    @property
    def cmd_offset(self) -> int: ...

    @cmd_offset.setter
    def cmd_offset(self, arg: int, /) -> None: ...

    @property
    def path_count(self) -> int: ...

    @path_count.setter
    def path_count(self, arg: int, /) -> None: ...

    @property
    def path_offset(self) -> int: ...

    @path_offset.setter
    def path_offset(self, arg: int, /) -> None: ...

    @property
    def line_AA(self) -> nk_anti_aliasing: ...

    @line_AA.setter
    def line_AA(self, arg: nk_anti_aliasing, /) -> None: ...

    @property
    def shape_AA(self) -> nk_anti_aliasing: ...

    @shape_AA.setter
    def shape_AA(self, arg: nk_anti_aliasing, /) -> None: ...

class nk_draw_list_stroke(enum.Flag):
    NK_STROKE_OPEN = 0

    NK_STROKE_CLOSED = 1

class nk_draw_null_texture:
    def __init__(self) -> None: ...

    @property
    def texture(self) -> "nk_handle": ...

    @texture.setter
    def texture(self, arg: "nk_handle", /) -> None: ...

    @property
    def uv(self) -> nk_vec2: ...

    @uv.setter
    def uv(self, arg: nk_vec2, /) -> None: ...

class nk_draw_vertex_layout_attribute(enum.Enum):
    NK_VERTEX_POSITION = 0

    NK_VERTEX_COLOR = 1

    NK_VERTEX_TEXCOORD = 2

    NK_VERTEX_ATTRIBUTE_COUNT = 3

class nk_draw_vertex_layout_element:
    def __init__(self) -> None: ...

    @property
    def attribute(self) -> nk_draw_vertex_layout_attribute: ...

    @attribute.setter
    def attribute(self, arg: nk_draw_vertex_layout_attribute, /) -> None: ...

    @property
    def format(self) -> nk_draw_vertex_layout_format: ...

    @format.setter
    def format(self, arg: nk_draw_vertex_layout_format, /) -> None: ...

    @property
    def offset(self) -> int: ...

    @offset.setter
    def offset(self, arg: int, /) -> None: ...

class nk_draw_vertex_layout_format(enum.Flag):
    NK_FORMAT_SCHAR = 0

    NK_FORMAT_SSHORT = 1

    NK_FORMAT_SINT = 2

    NK_FORMAT_UCHAR = 3

    NK_FORMAT_USHORT = 4

    NK_FORMAT_UINT = 5

    NK_FORMAT_FLOAT = 6

    NK_FORMAT_DOUBLE = 7

    NK_FORMAT_COLOR_BEGIN = 8

    NK_FORMAT_R8G8B8 = 8

    NK_FORMAT_R16G15B16 = 9

    NK_FORMAT_R32G32B32 = 10

    NK_FORMAT_R8G8B8A8 = 11

    NK_FORMAT_B8G8R8A8 = 12

    NK_FORMAT_R16G15B16A16 = 13

    NK_FORMAT_R32G32B32A32 = 14

    NK_FORMAT_R32G32B32A32_FLOAT = 15

    NK_FORMAT_R32G32B32A32_DOUBLE = 16

    NK_FORMAT_RGB32 = 17

    NK_FORMAT_RGBA32 = 18

    NK_FORMAT_COLOR_END = 18

    NK_FORMAT_COUNT = 19

class nk_edit_events(enum.Flag):
    NK_EDIT_ACTIVE = 1

    NK_EDIT_INACTIVE = 2

    NK_EDIT_ACTIVATED = 4

    NK_EDIT_DEACTIVATED = 8

    NK_EDIT_COMMITED = 16

class nk_edit_flags(enum.Flag):
    NK_EDIT_DEFAULT = 0

    NK_EDIT_READ_ONLY = 1

    NK_EDIT_AUTO_SELECT = 2

    NK_EDIT_SIG_ENTER = 4

    NK_EDIT_ALLOW_TAB = 8

    NK_EDIT_NO_CURSOR = 16

    NK_EDIT_SELECTABLE = 32

    NK_EDIT_CLIPBOARD = 64

    NK_EDIT_CTRL_ENTER_NEWLINE = 128

    NK_EDIT_NO_HORIZONTAL_SCROLL = 256

    NK_EDIT_ALWAYS_INSERT_MODE = 512

    NK_EDIT_MULTILINE = 1024

    NK_EDIT_GOTO_END_ON_ACTIVATE = 2048

class nk_edit_state:
    def __init__(self) -> None: ...

    @property
    def name(self) -> int: ...

    @name.setter
    def name(self, arg: int, /) -> None: ...

    @property
    def seq(self) -> int: ...

    @seq.setter
    def seq(self, arg: int, /) -> None: ...

    @property
    def old(self) -> int: ...

    @old.setter
    def old(self, arg: int, /) -> None: ...

    @property
    def prev(self) -> int: ...

    @prev.setter
    def prev(self, arg: int, /) -> None: ...

    @property
    def cursor(self) -> int: ...

    @cursor.setter
    def cursor(self, arg: int, /) -> None: ...

    @property
    def sel_start(self) -> int: ...

    @sel_start.setter
    def sel_start(self, arg: int, /) -> None: ...

    @property
    def sel_end(self) -> int: ...

    @sel_end.setter
    def sel_end(self, arg: int, /) -> None: ...

    @property
    def scrollbar(self) -> nk_scroll: ...

    @scrollbar.setter
    def scrollbar(self, arg: nk_scroll, /) -> None: ...

    @property
    def mode(self) -> int: ...

    @mode.setter
    def mode(self, arg: int, /) -> None: ...

    @property
    def single_line(self) -> int: ...

    @single_line.setter
    def single_line(self, arg: int, /) -> None: ...

class nk_edit_types(enum.Flag):
    NK_EDIT_SIMPLE = 512

    NK_EDIT_FIELD = 608

    NK_EDIT_BOX = 1640

    NK_EDIT_EDITOR = 1128

class nk_font:
    def __init__(self) -> None: ...

    @property
    def handle(self) -> nk_user_font: ...

    @handle.setter
    def handle(self, arg: nk_user_font, /) -> None: ...

    @property
    def info(self) -> nk_baked_font: ...

    @info.setter
    def info(self, arg: nk_baked_font, /) -> None: ...

    @property
    def scale(self) -> float: ...

    @scale.setter
    def scale(self, arg: float, /) -> None: ...

    @property
    def fallback_codepoint(self) -> int: ...

    @fallback_codepoint.setter
    def fallback_codepoint(self, arg: int, /) -> None: ...

    @property
    def texture(self) -> "nk_handle": ...

    @texture.setter
    def texture(self, arg: "nk_handle", /) -> None: ...

class nk_font_atlas_format(enum.Enum):
    NK_FONT_ATLAS_ALPHA8 = 0

    NK_FONT_ATLAS_RGBA32 = 1

class nk_font_config:
    def __init__(self) -> None: ...

    @property
    def ttf_size(self) -> int: ...

    @ttf_size.setter
    def ttf_size(self, arg: int, /) -> None: ...

    @property
    def ttf_data_owned_by_atlas(self) -> int: ...

    @ttf_data_owned_by_atlas.setter
    def ttf_data_owned_by_atlas(self, arg: int, /) -> None: ...

    @property
    def merge_mode(self) -> int: ...

    @merge_mode.setter
    def merge_mode(self, arg: int, /) -> None: ...

    @property
    def pixel_snap(self) -> int: ...

    @pixel_snap.setter
    def pixel_snap(self, arg: int, /) -> None: ...

    @property
    def oversample_h(self) -> int: ...

    @oversample_h.setter
    def oversample_h(self, arg: int, /) -> None: ...

    @property
    def size(self) -> float: ...

    @size.setter
    def size(self, arg: float, /) -> None: ...

    @property
    def coord_type(self) -> nk_font_coord_type: ...

    @coord_type.setter
    def coord_type(self, arg: nk_font_coord_type, /) -> None: ...

    @property
    def spacing(self) -> nk_vec2: ...

    @spacing.setter
    def spacing(self, arg: nk_vec2, /) -> None: ...

    @property
    def fallback_glyph(self) -> int: ...

    @fallback_glyph.setter
    def fallback_glyph(self, arg: int, /) -> None: ...

class nk_font_coord_type(enum.Enum):
    NK_COORD_UV = 0

    NK_COORD_PIXEL = 1

class nk_font_glyph:
    def __init__(self) -> None: ...

    @property
    def codepoint(self) -> int: ...

    @codepoint.setter
    def codepoint(self, arg: int, /) -> None: ...

    @property
    def xadvance(self) -> float: ...

    @xadvance.setter
    def xadvance(self, arg: float, /) -> None: ...

    @property
    def h(self) -> float: ...

    @h.setter
    def h(self, arg: float, /) -> None: ...

    @property
    def v1(self) -> float: ...

    @v1.setter
    def v1(self, arg: float, /) -> None: ...

class nk_heading(enum.Enum):
    NK_UP = 0

    NK_RIGHT = 1

    NK_DOWN = 2

    NK_LEFT = 3

class nk_image:
    def __init__(self) -> None: ...

    @property
    def handle(self) -> "nk_handle": ...

    @handle.setter
    def handle(self, arg: "nk_handle", /) -> None: ...

    @property
    def h(self) -> int: ...

    @h.setter
    def h(self, arg: int, /) -> None: ...

class nk_input:
    def __init__(self) -> None: ...

    @property
    def keyboard(self) -> nk_keyboard: ...

    @keyboard.setter
    def keyboard(self, arg: nk_keyboard, /) -> None: ...

    @property
    def mouse(self) -> nk_mouse: ...

    @mouse.setter
    def mouse(self, arg: nk_mouse, /) -> None: ...

class nk_key:
    def __init__(self) -> None: ...

    @property
    def down(self) -> bool: ...

    @down.setter
    def down(self, arg: bool, /) -> None: ...

    @property
    def clicked(self) -> int: ...

    @clicked.setter
    def clicked(self, arg: int, /) -> None: ...

class nk_keyboard:
    def __init__(self) -> None: ...

    @property
    def text_len(self) -> int: ...

    @text_len.setter
    def text_len(self, arg: int, /) -> None: ...

class nk_keys(enum.Enum):
    NK_KEY_NONE = 0

    NK_KEY_SHIFT = 1

    NK_KEY_CTRL = 2

    NK_KEY_DEL = 3

    NK_KEY_ENTER = 4

    NK_KEY_TAB = 5

    NK_KEY_BACKSPACE = 6

    NK_KEY_COPY = 7

    NK_KEY_CUT = 8

    NK_KEY_PASTE = 9

    NK_KEY_UP = 10

    NK_KEY_DOWN = 11

    NK_KEY_LEFT = 12

    NK_KEY_RIGHT = 13

    NK_KEY_TEXT_INSERT_MODE = 14

    NK_KEY_TEXT_REPLACE_MODE = 15

    NK_KEY_TEXT_RESET_MODE = 16

    NK_KEY_TEXT_LINE_START = 17

    NK_KEY_TEXT_LINE_END = 18

    NK_KEY_TEXT_START = 19

    NK_KEY_TEXT_END = 20

    NK_KEY_TEXT_UNDO = 21

    NK_KEY_TEXT_REDO = 22

    NK_KEY_TEXT_SELECT_ALL = 23

    NK_KEY_TEXT_WORD_LEFT = 24

    NK_KEY_TEXT_WORD_RIGHT = 25

    NK_KEY_SCROLL_START = 26

    NK_KEY_SCROLL_END = 27

    NK_KEY_SCROLL_DOWN = 28

    NK_KEY_SCROLL_UP = 29

    NK_KEY_MAX = 30

class nk_layout_format(enum.Enum):
    NK_DYNAMIC = 0

    NK_STATIC = 1

class nk_list_view:
    def __init__(self) -> None: ...

    @property
    def count(self) -> int: ...

    @count.setter
    def count(self, arg: int, /) -> None: ...

    @property
    def total_height(self) -> int: ...

    @total_height.setter
    def total_height(self, arg: int, /) -> None: ...

    @property
    def scroll_value(self) -> int: ...

    @scroll_value.setter
    def scroll_value(self, arg: int, /) -> None: ...

class nk_memory:
    def __init__(self) -> None: ...

    @property
    def size(self) -> int: ...

    @size.setter
    def size(self, arg: int, /) -> None: ...

class nk_memory_status:
    def __init__(self) -> None: ...

    @property
    def type(self) -> int: ...

    @type.setter
    def type(self, arg: int, /) -> None: ...

    @property
    def size(self) -> int: ...

    @size.setter
    def size(self, arg: int, /) -> None: ...

    @property
    def allocated(self) -> int: ...

    @allocated.setter
    def allocated(self, arg: int, /) -> None: ...

    @property
    def needed(self) -> int: ...

    @needed.setter
    def needed(self, arg: int, /) -> None: ...

    @property
    def calls(self) -> int: ...

    @calls.setter
    def calls(self, arg: int, /) -> None: ...

class nk_menu_state:
    def __init__(self) -> None: ...

    @property
    def h(self) -> float: ...

    @h.setter
    def h(self, arg: float, /) -> None: ...

    @property
    def offset(self) -> nk_scroll: ...

    @offset.setter
    def offset(self, arg: nk_scroll, /) -> None: ...

class nk_modify(enum.Flag):
    NK_FIXED = 0

    NK_MODIFIABLE = 1

class nk_mouse:
    def __init__(self) -> None: ...

    @property
    def pos(self) -> nk_vec2: ...

    @pos.setter
    def pos(self, arg: nk_vec2, /) -> None: ...

    @property
    def prev(self) -> nk_vec2: ...

    @prev.setter
    def prev(self, arg: nk_vec2, /) -> None: ...

    @property
    def delta(self) -> nk_vec2: ...

    @delta.setter
    def delta(self, arg: nk_vec2, /) -> None: ...

    @property
    def scroll_delta(self) -> nk_vec2: ...

    @scroll_delta.setter
    def scroll_delta(self, arg: nk_vec2, /) -> None: ...

    @property
    def grab(self) -> int: ...

    @grab.setter
    def grab(self, arg: int, /) -> None: ...

    @property
    def grabbed(self) -> int: ...

    @grabbed.setter
    def grabbed(self, arg: int, /) -> None: ...

    @property
    def ungrab(self) -> int: ...

    @ungrab.setter
    def ungrab(self, arg: int, /) -> None: ...

    def __getitem__(self, arg: int, /) -> nk_mouse_button: ...

    def __len__(self) -> nk_buttons: ...

class nk_mouse_button:
    def __init__(self) -> None: ...

    @property
    def down(self) -> bool: ...

    @down.setter
    def down(self, arg: bool, /) -> None: ...

    @property
    def clicked(self) -> int: ...

    @clicked.setter
    def clicked(self, arg: int, /) -> None: ...

    @property
    def clicked_pos(self) -> nk_vec2: ...

    @clicked_pos.setter
    def clicked_pos(self, arg: nk_vec2, /) -> None: ...

class nk_nine_slice:
    def __init__(self) -> None: ...

    @property
    def img(self) -> nk_image: ...

    @img.setter
    def img(self, arg: nk_image, /) -> None: ...

    @property
    def b(self) -> int: ...

    @b.setter
    def b(self, arg: int, /) -> None: ...

class nk_orientation(enum.Enum):
    NK_VERTICAL = 0

    NK_HORIZONTAL = 1

class nk_page:
    def __init__(self) -> None: ...

    @property
    def size(self) -> int: ...

    @size.setter
    def size(self, arg: int, /) -> None: ...

class nk_page_element:
    def __init__(self) -> None: ...

    @property
    def data(self) -> "nk_page_data": ...

    @data.setter
    def data(self, arg: "nk_page_data", /) -> None: ...

class nk_panel:
    def __init__(self) -> None: ...

    @property
    def type(self) -> nk_panel_type: ...

    @type.setter
    def type(self, arg: nk_panel_type, /) -> None: ...

    @property
    def flags(self) -> int: ...

    @flags.setter
    def flags(self, arg: int, /) -> None: ...

    @property
    def bounds(self) -> nk_rect: ...

    @bounds.setter
    def bounds(self, arg: nk_rect, /) -> None: ...

    @property
    def max_x(self) -> float: ...

    @max_x.setter
    def max_x(self, arg: float, /) -> None: ...

    @property
    def footer_height(self) -> float: ...

    @footer_height.setter
    def footer_height(self, arg: float, /) -> None: ...

    @property
    def header_height(self) -> float: ...

    @header_height.setter
    def header_height(self, arg: float, /) -> None: ...

    @property
    def border(self) -> float: ...

    @border.setter
    def border(self, arg: float, /) -> None: ...

    @property
    def has_scrolling(self) -> int: ...

    @has_scrolling.setter
    def has_scrolling(self, arg: int, /) -> None: ...

    @property
    def clip(self) -> nk_rect: ...

    @clip.setter
    def clip(self, arg: nk_rect, /) -> None: ...

    @property
    def menu(self) -> nk_menu_state: ...

    @menu.setter
    def menu(self, arg: nk_menu_state, /) -> None: ...

    @property
    def row(self) -> nk_row_layout: ...

    @row.setter
    def row(self, arg: nk_row_layout, /) -> None: ...

    @property
    def chart(self) -> nk_chart: ...

    @chart.setter
    def chart(self, arg: nk_chart, /) -> None: ...

class nk_panel_flags(enum.Flag):
    NK_WINDOW_BORDER = 1

    NK_WINDOW_MOVABLE = 2

    NK_WINDOW_SCALABLE = 4

    NK_WINDOW_CLOSABLE = 8

    NK_WINDOW_MINIMIZABLE = 16

    NK_WINDOW_NO_SCROLLBAR = 32

    NK_WINDOW_TITLE = 64

    NK_WINDOW_SCROLL_AUTO_HIDE = 128

    NK_WINDOW_BACKGROUND = 256

    NK_WINDOW_SCALE_LEFT = 512

    NK_WINDOW_NO_INPUT = 1024

class nk_panel_row_layout_type(enum.Flag):
    NK_LAYOUT_DYNAMIC_FIXED = 0

    NK_LAYOUT_DYNAMIC_ROW = 1

    NK_LAYOUT_DYNAMIC_FREE = 2

    NK_LAYOUT_DYNAMIC = 3

    NK_LAYOUT_STATIC_FIXED = 4

    NK_LAYOUT_STATIC_ROW = 5

    NK_LAYOUT_STATIC_FREE = 6

    NK_LAYOUT_STATIC = 7

    NK_LAYOUT_TEMPLATE = 8

    NK_LAYOUT_COUNT = 9

class nk_panel_set(enum.Flag):
    NK_PANEL_SET_NONBLOCK = 240

    NK_PANEL_SET_POPUP = 244

    NK_PANEL_SET_SUB = 246

class nk_panel_type(enum.Flag):
    NK_PANEL_NONE = 0

    NK_PANEL_WINDOW = 1

    NK_PANEL_GROUP = 2

    NK_PANEL_POPUP = 4

    NK_PANEL_CONTEXTUAL = 16

    NK_PANEL_COMBO = 32

    NK_PANEL_MENU = 64

    NK_PANEL_TOOLTIP = 128

class nk_popup_buffer:
    def __init__(self) -> None: ...

    @property
    def begin(self) -> int: ...

    @begin.setter
    def begin(self, arg: int, /) -> None: ...

    @property
    def parent(self) -> int: ...

    @parent.setter
    def parent(self, arg: int, /) -> None: ...

    @property
    def last(self) -> int: ...

    @last.setter
    def last(self, arg: int, /) -> None: ...

    @property
    def end(self) -> int: ...

    @end.setter
    def end(self, arg: int, /) -> None: ...

    @property
    def active(self) -> bool: ...

    @active.setter
    def active(self, arg: bool, /) -> None: ...

class nk_popup_state:
    def __init__(self) -> None: ...

    @property
    def type(self) -> nk_panel_type: ...

    @type.setter
    def type(self, arg: nk_panel_type, /) -> None: ...

    @property
    def buf(self) -> nk_popup_buffer: ...

    @buf.setter
    def buf(self, arg: nk_popup_buffer, /) -> None: ...

    @property
    def name(self) -> int: ...

    @name.setter
    def name(self, arg: int, /) -> None: ...

    @property
    def active(self) -> bool: ...

    @active.setter
    def active(self, arg: bool, /) -> None: ...

    @property
    def combo_count(self) -> int: ...

    @combo_count.setter
    def combo_count(self, arg: int, /) -> None: ...

    @property
    def con_old(self) -> int: ...

    @con_old.setter
    def con_old(self, arg: int, /) -> None: ...

    @property
    def active_con(self) -> int: ...

    @active_con.setter
    def active_con(self, arg: int, /) -> None: ...

    @property
    def header(self) -> nk_rect: ...

    @header.setter
    def header(self, arg: nk_rect, /) -> None: ...

class nk_popup_type(enum.Enum):
    NK_POPUP_STATIC = 0

    NK_POPUP_DYNAMIC = 1

class nk_property_state:
    def __init__(self) -> None: ...

    @property
    def prev(self) -> int: ...

    @prev.setter
    def prev(self, arg: int, /) -> None: ...

    @property
    def length(self) -> int: ...

    @length.setter
    def length(self, arg: int, /) -> None: ...

    @property
    def cursor(self) -> int: ...

    @cursor.setter
    def cursor(self, arg: int, /) -> None: ...

    @property
    def select_start(self) -> int: ...

    @select_start.setter
    def select_start(self, arg: int, /) -> None: ...

    @property
    def select_end(self) -> int: ...

    @select_end.setter
    def select_end(self, arg: int, /) -> None: ...

    @property
    def name(self) -> int: ...

    @name.setter
    def name(self, arg: int, /) -> None: ...

    @property
    def seq(self) -> int: ...

    @seq.setter
    def seq(self, arg: int, /) -> None: ...

    @property
    def old(self) -> int: ...

    @old.setter
    def old(self, arg: int, /) -> None: ...

    @property
    def state(self) -> int: ...

    @state.setter
    def state(self, arg: int, /) -> None: ...

    @property
    def prev_state(self) -> int: ...

    @prev_state.setter
    def prev_state(self, arg: int, /) -> None: ...

    @property
    def prev_name(self) -> int: ...

    @prev_name.setter
    def prev_name(self, arg: int, /) -> None: ...

    @property
    def prev_length(self) -> int: ...

    @prev_length.setter
    def prev_length(self, arg: int, /) -> None: ...

class nk_rect:
    def __init__(self) -> None: ...

    @property
    def x(self) -> float: ...

    @x.setter
    def x(self, arg: float, /) -> None: ...

    @property
    def y(self) -> float: ...

    @y.setter
    def y(self, arg: float, /) -> None: ...

    @property
    def w(self) -> float: ...

    @w.setter
    def w(self, arg: float, /) -> None: ...

    @property
    def h(self) -> float: ...

    @h.setter
    def h(self, arg: float, /) -> None: ...

class nk_recti:
    def __init__(self) -> None: ...

    @property
    def x(self) -> int: ...

    @x.setter
    def x(self, arg: int, /) -> None: ...

    @property
    def y(self) -> int: ...

    @y.setter
    def y(self, arg: int, /) -> None: ...

    @property
    def w(self) -> int: ...

    @w.setter
    def w(self, arg: int, /) -> None: ...

    @property
    def h(self) -> int: ...

    @h.setter
    def h(self, arg: int, /) -> None: ...

class nk_row_layout:
    def __init__(self) -> None: ...

    @property
    def type(self) -> nk_panel_row_layout_type: ...

    @type.setter
    def type(self, arg: nk_panel_row_layout_type, /) -> None: ...

    @property
    def index(self) -> int: ...

    @index.setter
    def index(self, arg: int, /) -> None: ...

    @property
    def height(self) -> float: ...

    @height.setter
    def height(self, arg: float, /) -> None: ...

    @property
    def min_height(self) -> float: ...

    @min_height.setter
    def min_height(self, arg: float, /) -> None: ...

    @property
    def columns(self) -> int: ...

    @columns.setter
    def columns(self, arg: int, /) -> None: ...

    @property
    def item_width(self) -> float: ...

    @item_width.setter
    def item_width(self, arg: float, /) -> None: ...

    @property
    def item_height(self) -> float: ...

    @item_height.setter
    def item_height(self, arg: float, /) -> None: ...

    @property
    def item_offset(self) -> float: ...

    @item_offset.setter
    def item_offset(self, arg: float, /) -> None: ...

    @property
    def filled(self) -> float: ...

    @filled.setter
    def filled(self, arg: float, /) -> None: ...

    @property
    def item(self) -> nk_rect: ...

    @item.setter
    def item(self, arg: nk_rect, /) -> None: ...

    @property
    def tree_depth(self) -> int: ...

    @tree_depth.setter
    def tree_depth(self, arg: int, /) -> None: ...

class nk_scroll:
    def __init__(self) -> None: ...

    @property
    def y(self) -> int: ...

    @y.setter
    def y(self, arg: int, /) -> None: ...

class nk_show_states(enum.Flag):
    NK_HIDDEN = 0

    NK_SHOWN = 1

class nk_str:
    def __init__(self) -> None: ...

    @property
    def buffer(self) -> "nk_buffer": ...

    @buffer.setter
    def buffer(self, arg: "nk_buffer", /) -> None: ...

    @property
    def len(self) -> int: ...

    @len.setter
    def len(self, arg: int, /) -> None: ...

class nk_style:
    def __init__(self) -> None: ...

    @property
    def cursor_visible(self) -> int: ...

    @cursor_visible.setter
    def cursor_visible(self, arg: int, /) -> None: ...

    @property
    def text(self) -> nk_style_text: ...

    @text.setter
    def text(self, arg: nk_style_text, /) -> None: ...

    @property
    def button(self) -> nk_style_button: ...

    @button.setter
    def button(self, arg: nk_style_button, /) -> None: ...

    @property
    def contextual_button(self) -> nk_style_button: ...

    @contextual_button.setter
    def contextual_button(self, arg: nk_style_button, /) -> None: ...

    @property
    def menu_button(self) -> nk_style_button: ...

    @menu_button.setter
    def menu_button(self, arg: nk_style_button, /) -> None: ...

    @property
    def option(self) -> nk_style_toggle: ...

    @option.setter
    def option(self, arg: nk_style_toggle, /) -> None: ...

    @property
    def checkbox(self) -> nk_style_toggle: ...

    @checkbox.setter
    def checkbox(self, arg: nk_style_toggle, /) -> None: ...

    @property
    def selectable(self) -> nk_style_selectable: ...

    @selectable.setter
    def selectable(self, arg: nk_style_selectable, /) -> None: ...

    @property
    def slider(self) -> nk_style_slider: ...

    @slider.setter
    def slider(self, arg: nk_style_slider, /) -> None: ...

    @property
    def knob(self) -> nk_style_knob: ...

    @knob.setter
    def knob(self, arg: nk_style_knob, /) -> None: ...

    @property
    def progress(self) -> nk_style_progress: ...

    @progress.setter
    def progress(self, arg: nk_style_progress, /) -> None: ...

    @property
    def property(self) -> nk_style_property: ...

    @property.setter
    def property(self, arg: nk_style_property, /) -> None: ...

    @property
    def edit(self) -> nk_style_edit: ...

    @edit.setter
    def edit(self, arg: nk_style_edit, /) -> None: ...

    @property
    def chart(self) -> nk_style_chart: ...

    @chart.setter
    def chart(self, arg: nk_style_chart, /) -> None: ...

    @property
    def scrollh(self) -> nk_style_scrollbar: ...

    @scrollh.setter
    def scrollh(self, arg: nk_style_scrollbar, /) -> None: ...

    @property
    def scrollv(self) -> nk_style_scrollbar: ...

    @scrollv.setter
    def scrollv(self, arg: nk_style_scrollbar, /) -> None: ...

    @property
    def tab(self) -> nk_style_tab: ...

    @tab.setter
    def tab(self, arg: nk_style_tab, /) -> None: ...

    @property
    def combo(self) -> nk_style_combo: ...

    @combo.setter
    def combo(self, arg: nk_style_combo, /) -> None: ...

    @property
    def window(self) -> nk_style_window: ...

    @window.setter
    def window(self, arg: nk_style_window, /) -> None: ...

class nk_style_button:
    def __init__(self) -> None: ...

    @property
    def normal(self) -> nk_style_item: ...

    @normal.setter
    def normal(self, arg: nk_style_item, /) -> None: ...

    @property
    def hover(self) -> nk_style_item: ...

    @hover.setter
    def hover(self, arg: nk_style_item, /) -> None: ...

    @property
    def active(self) -> nk_style_item: ...

    @active.setter
    def active(self, arg: nk_style_item, /) -> None: ...

    @property
    def border_color(self) -> nk_color: ...

    @border_color.setter
    def border_color(self, arg: nk_color, /) -> None: ...

    @property
    def color_factor_background(self) -> float: ...

    @color_factor_background.setter
    def color_factor_background(self, arg: float, /) -> None: ...

    @property
    def text_background(self) -> nk_color: ...

    @text_background.setter
    def text_background(self, arg: nk_color, /) -> None: ...

    @property
    def text_normal(self) -> nk_color: ...

    @text_normal.setter
    def text_normal(self, arg: nk_color, /) -> None: ...

    @property
    def text_hover(self) -> nk_color: ...

    @text_hover.setter
    def text_hover(self, arg: nk_color, /) -> None: ...

    @property
    def text_active(self) -> nk_color: ...

    @text_active.setter
    def text_active(self, arg: nk_color, /) -> None: ...

    @property
    def text_alignment(self) -> int: ...

    @text_alignment.setter
    def text_alignment(self, arg: int, /) -> None: ...

    @property
    def color_factor_text(self) -> float: ...

    @color_factor_text.setter
    def color_factor_text(self, arg: float, /) -> None: ...

    @property
    def border(self) -> float: ...

    @border.setter
    def border(self, arg: float, /) -> None: ...

    @property
    def rounding(self) -> float: ...

    @rounding.setter
    def rounding(self, arg: float, /) -> None: ...

    @property
    def padding(self) -> nk_vec2: ...

    @padding.setter
    def padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def image_padding(self) -> nk_vec2: ...

    @image_padding.setter
    def image_padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def touch_padding(self) -> nk_vec2: ...

    @touch_padding.setter
    def touch_padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def disabled_factor(self) -> float: ...

    @disabled_factor.setter
    def disabled_factor(self, arg: float, /) -> None: ...

    @property
    def userdata(self) -> "nk_handle": ...

    @userdata.setter
    def userdata(self, arg: "nk_handle", /) -> None: ...

class nk_style_chart:
    def __init__(self) -> None: ...

    @property
    def background(self) -> nk_style_item: ...

    @background.setter
    def background(self, arg: nk_style_item, /) -> None: ...

    @property
    def border_color(self) -> nk_color: ...

    @border_color.setter
    def border_color(self, arg: nk_color, /) -> None: ...

    @property
    def selected_color(self) -> nk_color: ...

    @selected_color.setter
    def selected_color(self, arg: nk_color, /) -> None: ...

    @property
    def color(self) -> nk_color: ...

    @color.setter
    def color(self, arg: nk_color, /) -> None: ...

    @property
    def border(self) -> float: ...

    @border.setter
    def border(self, arg: float, /) -> None: ...

    @property
    def rounding(self) -> float: ...

    @rounding.setter
    def rounding(self, arg: float, /) -> None: ...

    @property
    def padding(self) -> nk_vec2: ...

    @padding.setter
    def padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def color_factor(self) -> float: ...

    @color_factor.setter
    def color_factor(self, arg: float, /) -> None: ...

    @property
    def disabled_factor(self) -> float: ...

    @disabled_factor.setter
    def disabled_factor(self, arg: float, /) -> None: ...

    @property
    def show_markers(self) -> bool: ...

    @show_markers.setter
    def show_markers(self, arg: bool, /) -> None: ...

class nk_style_colors(enum.Enum):
    NK_COLOR_TEXT = 0

    NK_COLOR_WINDOW = 1

    NK_COLOR_HEADER = 2

    NK_COLOR_BORDER = 3

    NK_COLOR_BUTTON = 4

    NK_COLOR_BUTTON_HOVER = 5

    NK_COLOR_BUTTON_ACTIVE = 6

    NK_COLOR_TOGGLE = 7

    NK_COLOR_TOGGLE_HOVER = 8

    NK_COLOR_TOGGLE_CURSOR = 9

    NK_COLOR_SELECT = 10

    NK_COLOR_SELECT_ACTIVE = 11

    NK_COLOR_SLIDER = 12

    NK_COLOR_SLIDER_CURSOR = 13

    NK_COLOR_SLIDER_CURSOR_HOVER = 14

    NK_COLOR_SLIDER_CURSOR_ACTIVE = 15

    NK_COLOR_PROPERTY = 16

    NK_COLOR_EDIT = 17

    NK_COLOR_EDIT_CURSOR = 18

    NK_COLOR_COMBO = 19

    NK_COLOR_CHART = 20

    NK_COLOR_CHART_COLOR = 21

    NK_COLOR_CHART_COLOR_HIGHLIGHT = 22

    NK_COLOR_SCROLLBAR = 23

    NK_COLOR_SCROLLBAR_CURSOR = 24

    NK_COLOR_SCROLLBAR_CURSOR_HOVER = 25

    NK_COLOR_SCROLLBAR_CURSOR_ACTIVE = 26

    NK_COLOR_TAB_HEADER = 27

    NK_COLOR_KNOB = 28

    NK_COLOR_KNOB_CURSOR = 29

    NK_COLOR_KNOB_CURSOR_HOVER = 30

    NK_COLOR_KNOB_CURSOR_ACTIVE = 31

    NK_COLOR_COUNT = 32

class nk_style_combo:
    def __init__(self) -> None: ...

    @property
    def normal(self) -> nk_style_item: ...

    @normal.setter
    def normal(self, arg: nk_style_item, /) -> None: ...

    @property
    def hover(self) -> nk_style_item: ...

    @hover.setter
    def hover(self, arg: nk_style_item, /) -> None: ...

    @property
    def active(self) -> nk_style_item: ...

    @active.setter
    def active(self, arg: nk_style_item, /) -> None: ...

    @property
    def border_color(self) -> nk_color: ...

    @border_color.setter
    def border_color(self, arg: nk_color, /) -> None: ...

    @property
    def label_normal(self) -> nk_color: ...

    @label_normal.setter
    def label_normal(self, arg: nk_color, /) -> None: ...

    @property
    def label_hover(self) -> nk_color: ...

    @label_hover.setter
    def label_hover(self, arg: nk_color, /) -> None: ...

    @property
    def label_active(self) -> nk_color: ...

    @label_active.setter
    def label_active(self, arg: nk_color, /) -> None: ...

    @property
    def symbol_normal(self) -> nk_color: ...

    @symbol_normal.setter
    def symbol_normal(self, arg: nk_color, /) -> None: ...

    @property
    def symbol_hover(self) -> nk_color: ...

    @symbol_hover.setter
    def symbol_hover(self, arg: nk_color, /) -> None: ...

    @property
    def symbol_active(self) -> nk_color: ...

    @symbol_active.setter
    def symbol_active(self, arg: nk_color, /) -> None: ...

    @property
    def button(self) -> nk_style_button: ...

    @button.setter
    def button(self, arg: nk_style_button, /) -> None: ...

    @property
    def sym_normal(self) -> nk_symbol_type: ...

    @sym_normal.setter
    def sym_normal(self, arg: nk_symbol_type, /) -> None: ...

    @property
    def sym_hover(self) -> nk_symbol_type: ...

    @sym_hover.setter
    def sym_hover(self, arg: nk_symbol_type, /) -> None: ...

    @property
    def sym_active(self) -> nk_symbol_type: ...

    @sym_active.setter
    def sym_active(self, arg: nk_symbol_type, /) -> None: ...

    @property
    def border(self) -> float: ...

    @border.setter
    def border(self, arg: float, /) -> None: ...

    @property
    def rounding(self) -> float: ...

    @rounding.setter
    def rounding(self, arg: float, /) -> None: ...

    @property
    def content_padding(self) -> nk_vec2: ...

    @content_padding.setter
    def content_padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def button_padding(self) -> nk_vec2: ...

    @button_padding.setter
    def button_padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def spacing(self) -> nk_vec2: ...

    @spacing.setter
    def spacing(self, arg: nk_vec2, /) -> None: ...

    @property
    def color_factor(self) -> float: ...

    @color_factor.setter
    def color_factor(self, arg: float, /) -> None: ...

    @property
    def disabled_factor(self) -> float: ...

    @disabled_factor.setter
    def disabled_factor(self, arg: float, /) -> None: ...

class nk_style_cursor(enum.Enum):
    NK_CURSOR_ARROW = 0

    NK_CURSOR_TEXT = 1

    NK_CURSOR_MOVE = 2

    NK_CURSOR_RESIZE_VERTICAL = 3

    NK_CURSOR_RESIZE_HORIZONTAL = 4

    NK_CURSOR_RESIZE_TOP_LEFT_DOWN_RIGHT = 5

    NK_CURSOR_RESIZE_TOP_RIGHT_DOWN_LEFT = 6

    NK_CURSOR_COUNT = 7

class nk_style_edit:
    def __init__(self) -> None: ...

    @property
    def normal(self) -> nk_style_item: ...

    @normal.setter
    def normal(self, arg: nk_style_item, /) -> None: ...

    @property
    def hover(self) -> nk_style_item: ...

    @hover.setter
    def hover(self, arg: nk_style_item, /) -> None: ...

    @property
    def active(self) -> nk_style_item: ...

    @active.setter
    def active(self, arg: nk_style_item, /) -> None: ...

    @property
    def border_color(self) -> nk_color: ...

    @border_color.setter
    def border_color(self, arg: nk_color, /) -> None: ...

    @property
    def scrollbar(self) -> nk_style_scrollbar: ...

    @scrollbar.setter
    def scrollbar(self, arg: nk_style_scrollbar, /) -> None: ...

    @property
    def cursor_normal(self) -> nk_color: ...

    @cursor_normal.setter
    def cursor_normal(self, arg: nk_color, /) -> None: ...

    @property
    def cursor_hover(self) -> nk_color: ...

    @cursor_hover.setter
    def cursor_hover(self, arg: nk_color, /) -> None: ...

    @property
    def cursor_text_normal(self) -> nk_color: ...

    @cursor_text_normal.setter
    def cursor_text_normal(self, arg: nk_color, /) -> None: ...

    @property
    def cursor_text_hover(self) -> nk_color: ...

    @cursor_text_hover.setter
    def cursor_text_hover(self, arg: nk_color, /) -> None: ...

    @property
    def text_normal(self) -> nk_color: ...

    @text_normal.setter
    def text_normal(self, arg: nk_color, /) -> None: ...

    @property
    def text_hover(self) -> nk_color: ...

    @text_hover.setter
    def text_hover(self, arg: nk_color, /) -> None: ...

    @property
    def text_active(self) -> nk_color: ...

    @text_active.setter
    def text_active(self, arg: nk_color, /) -> None: ...

    @property
    def selected_normal(self) -> nk_color: ...

    @selected_normal.setter
    def selected_normal(self, arg: nk_color, /) -> None: ...

    @property
    def selected_hover(self) -> nk_color: ...

    @selected_hover.setter
    def selected_hover(self, arg: nk_color, /) -> None: ...

    @property
    def selected_text_normal(self) -> nk_color: ...

    @selected_text_normal.setter
    def selected_text_normal(self, arg: nk_color, /) -> None: ...

    @property
    def selected_text_hover(self) -> nk_color: ...

    @selected_text_hover.setter
    def selected_text_hover(self, arg: nk_color, /) -> None: ...

    @property
    def border(self) -> float: ...

    @border.setter
    def border(self, arg: float, /) -> None: ...

    @property
    def rounding(self) -> float: ...

    @rounding.setter
    def rounding(self, arg: float, /) -> None: ...

    @property
    def cursor_size(self) -> float: ...

    @cursor_size.setter
    def cursor_size(self, arg: float, /) -> None: ...

    @property
    def scrollbar_size(self) -> nk_vec2: ...

    @scrollbar_size.setter
    def scrollbar_size(self, arg: nk_vec2, /) -> None: ...

    @property
    def padding(self) -> nk_vec2: ...

    @padding.setter
    def padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def row_padding(self) -> float: ...

    @row_padding.setter
    def row_padding(self, arg: float, /) -> None: ...

    @property
    def color_factor(self) -> float: ...

    @color_factor.setter
    def color_factor(self, arg: float, /) -> None: ...

    @property
    def disabled_factor(self) -> float: ...

    @disabled_factor.setter
    def disabled_factor(self, arg: float, /) -> None: ...

class nk_style_header_align(enum.Enum):
    NK_HEADER_LEFT = 0

    NK_HEADER_RIGHT = 1

class nk_style_item:
    def __init__(self) -> None: ...

    @property
    def type(self) -> nk_style_item_type: ...

    @type.setter
    def type(self, arg: nk_style_item_type, /) -> None: ...

    @property
    def data(self) -> nk_style_item_data: ...

    @data.setter
    def data(self, arg: nk_style_item_data, /) -> None: ...

class nk_style_item_data:
    def __init__(self) -> None: ...

    @property
    def color(self) -> nk_color: ...

    @color.setter
    def color(self, arg: nk_color, /) -> None: ...

    @property
    def image(self) -> nk_image: ...

    @image.setter
    def image(self, arg: nk_image, /) -> None: ...

    @property
    def slice(self) -> nk_nine_slice: ...

    @slice.setter
    def slice(self, arg: nk_nine_slice, /) -> None: ...

class nk_style_item_type(enum.Enum):
    NK_STYLE_ITEM_COLOR = 0

    NK_STYLE_ITEM_IMAGE = 1

    NK_STYLE_ITEM_NINE_SLICE = 2

class nk_style_knob:
    def __init__(self) -> None: ...

    @property
    def normal(self) -> nk_style_item: ...

    @normal.setter
    def normal(self, arg: nk_style_item, /) -> None: ...

    @property
    def hover(self) -> nk_style_item: ...

    @hover.setter
    def hover(self, arg: nk_style_item, /) -> None: ...

    @property
    def active(self) -> nk_style_item: ...

    @active.setter
    def active(self, arg: nk_style_item, /) -> None: ...

    @property
    def border_color(self) -> nk_color: ...

    @border_color.setter
    def border_color(self, arg: nk_color, /) -> None: ...

    @property
    def knob_normal(self) -> nk_color: ...

    @knob_normal.setter
    def knob_normal(self, arg: nk_color, /) -> None: ...

    @property
    def knob_hover(self) -> nk_color: ...

    @knob_hover.setter
    def knob_hover(self, arg: nk_color, /) -> None: ...

    @property
    def knob_active(self) -> nk_color: ...

    @knob_active.setter
    def knob_active(self, arg: nk_color, /) -> None: ...

    @property
    def knob_border_color(self) -> nk_color: ...

    @knob_border_color.setter
    def knob_border_color(self, arg: nk_color, /) -> None: ...

    @property
    def cursor_normal(self) -> nk_color: ...

    @cursor_normal.setter
    def cursor_normal(self, arg: nk_color, /) -> None: ...

    @property
    def cursor_hover(self) -> nk_color: ...

    @cursor_hover.setter
    def cursor_hover(self, arg: nk_color, /) -> None: ...

    @property
    def cursor_active(self) -> nk_color: ...

    @cursor_active.setter
    def cursor_active(self, arg: nk_color, /) -> None: ...

    @property
    def border(self) -> float: ...

    @border.setter
    def border(self, arg: float, /) -> None: ...

    @property
    def knob_border(self) -> float: ...

    @knob_border.setter
    def knob_border(self, arg: float, /) -> None: ...

    @property
    def padding(self) -> nk_vec2: ...

    @padding.setter
    def padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def spacing(self) -> nk_vec2: ...

    @spacing.setter
    def spacing(self, arg: nk_vec2, /) -> None: ...

    @property
    def cursor_width(self) -> float: ...

    @cursor_width.setter
    def cursor_width(self, arg: float, /) -> None: ...

    @property
    def color_factor(self) -> float: ...

    @color_factor.setter
    def color_factor(self, arg: float, /) -> None: ...

    @property
    def disabled_factor(self) -> float: ...

    @disabled_factor.setter
    def disabled_factor(self, arg: float, /) -> None: ...

    @property
    def userdata(self) -> "nk_handle": ...

    @userdata.setter
    def userdata(self, arg: "nk_handle", /) -> None: ...

class nk_style_progress:
    def __init__(self) -> None: ...

    @property
    def normal(self) -> nk_style_item: ...

    @normal.setter
    def normal(self, arg: nk_style_item, /) -> None: ...

    @property
    def hover(self) -> nk_style_item: ...

    @hover.setter
    def hover(self, arg: nk_style_item, /) -> None: ...

    @property
    def active(self) -> nk_style_item: ...

    @active.setter
    def active(self, arg: nk_style_item, /) -> None: ...

    @property
    def border_color(self) -> nk_color: ...

    @border_color.setter
    def border_color(self, arg: nk_color, /) -> None: ...

    @property
    def cursor_normal(self) -> nk_style_item: ...

    @cursor_normal.setter
    def cursor_normal(self, arg: nk_style_item, /) -> None: ...

    @property
    def cursor_hover(self) -> nk_style_item: ...

    @cursor_hover.setter
    def cursor_hover(self, arg: nk_style_item, /) -> None: ...

    @property
    def cursor_active(self) -> nk_style_item: ...

    @cursor_active.setter
    def cursor_active(self, arg: nk_style_item, /) -> None: ...

    @property
    def cursor_border_color(self) -> nk_color: ...

    @cursor_border_color.setter
    def cursor_border_color(self, arg: nk_color, /) -> None: ...

    @property
    def rounding(self) -> float: ...

    @rounding.setter
    def rounding(self, arg: float, /) -> None: ...

    @property
    def border(self) -> float: ...

    @border.setter
    def border(self, arg: float, /) -> None: ...

    @property
    def cursor_border(self) -> float: ...

    @cursor_border.setter
    def cursor_border(self, arg: float, /) -> None: ...

    @property
    def cursor_rounding(self) -> float: ...

    @cursor_rounding.setter
    def cursor_rounding(self, arg: float, /) -> None: ...

    @property
    def padding(self) -> nk_vec2: ...

    @padding.setter
    def padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def color_factor(self) -> float: ...

    @color_factor.setter
    def color_factor(self, arg: float, /) -> None: ...

    @property
    def disabled_factor(self) -> float: ...

    @disabled_factor.setter
    def disabled_factor(self, arg: float, /) -> None: ...

    @property
    def userdata(self) -> "nk_handle": ...

    @userdata.setter
    def userdata(self, arg: "nk_handle", /) -> None: ...

class nk_style_property:
    def __init__(self) -> None: ...

    @property
    def normal(self) -> nk_style_item: ...

    @normal.setter
    def normal(self, arg: nk_style_item, /) -> None: ...

    @property
    def hover(self) -> nk_style_item: ...

    @hover.setter
    def hover(self, arg: nk_style_item, /) -> None: ...

    @property
    def active(self) -> nk_style_item: ...

    @active.setter
    def active(self, arg: nk_style_item, /) -> None: ...

    @property
    def border_color(self) -> nk_color: ...

    @border_color.setter
    def border_color(self, arg: nk_color, /) -> None: ...

    @property
    def label_normal(self) -> nk_color: ...

    @label_normal.setter
    def label_normal(self, arg: nk_color, /) -> None: ...

    @property
    def label_hover(self) -> nk_color: ...

    @label_hover.setter
    def label_hover(self, arg: nk_color, /) -> None: ...

    @property
    def label_active(self) -> nk_color: ...

    @label_active.setter
    def label_active(self, arg: nk_color, /) -> None: ...

    @property
    def sym_left(self) -> nk_symbol_type: ...

    @sym_left.setter
    def sym_left(self, arg: nk_symbol_type, /) -> None: ...

    @property
    def sym_right(self) -> nk_symbol_type: ...

    @sym_right.setter
    def sym_right(self, arg: nk_symbol_type, /) -> None: ...

    @property
    def border(self) -> float: ...

    @border.setter
    def border(self, arg: float, /) -> None: ...

    @property
    def rounding(self) -> float: ...

    @rounding.setter
    def rounding(self, arg: float, /) -> None: ...

    @property
    def padding(self) -> nk_vec2: ...

    @padding.setter
    def padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def color_factor(self) -> float: ...

    @color_factor.setter
    def color_factor(self, arg: float, /) -> None: ...

    @property
    def disabled_factor(self) -> float: ...

    @disabled_factor.setter
    def disabled_factor(self, arg: float, /) -> None: ...

    @property
    def edit(self) -> nk_style_edit: ...

    @edit.setter
    def edit(self, arg: nk_style_edit, /) -> None: ...

    @property
    def inc_button(self) -> nk_style_button: ...

    @inc_button.setter
    def inc_button(self, arg: nk_style_button, /) -> None: ...

    @property
    def dec_button(self) -> nk_style_button: ...

    @dec_button.setter
    def dec_button(self, arg: nk_style_button, /) -> None: ...

    @property
    def userdata(self) -> "nk_handle": ...

    @userdata.setter
    def userdata(self, arg: "nk_handle", /) -> None: ...

class nk_style_scrollbar:
    def __init__(self) -> None: ...

    @property
    def normal(self) -> nk_style_item: ...

    @normal.setter
    def normal(self, arg: nk_style_item, /) -> None: ...

    @property
    def hover(self) -> nk_style_item: ...

    @hover.setter
    def hover(self, arg: nk_style_item, /) -> None: ...

    @property
    def active(self) -> nk_style_item: ...

    @active.setter
    def active(self, arg: nk_style_item, /) -> None: ...

    @property
    def border_color(self) -> nk_color: ...

    @border_color.setter
    def border_color(self, arg: nk_color, /) -> None: ...

    @property
    def cursor_normal(self) -> nk_style_item: ...

    @cursor_normal.setter
    def cursor_normal(self, arg: nk_style_item, /) -> None: ...

    @property
    def cursor_hover(self) -> nk_style_item: ...

    @cursor_hover.setter
    def cursor_hover(self, arg: nk_style_item, /) -> None: ...

    @property
    def cursor_active(self) -> nk_style_item: ...

    @cursor_active.setter
    def cursor_active(self, arg: nk_style_item, /) -> None: ...

    @property
    def cursor_border_color(self) -> nk_color: ...

    @cursor_border_color.setter
    def cursor_border_color(self, arg: nk_color, /) -> None: ...

    @property
    def border(self) -> float: ...

    @border.setter
    def border(self, arg: float, /) -> None: ...

    @property
    def rounding(self) -> float: ...

    @rounding.setter
    def rounding(self, arg: float, /) -> None: ...

    @property
    def border_cursor(self) -> float: ...

    @border_cursor.setter
    def border_cursor(self, arg: float, /) -> None: ...

    @property
    def rounding_cursor(self) -> float: ...

    @rounding_cursor.setter
    def rounding_cursor(self, arg: float, /) -> None: ...

    @property
    def padding(self) -> nk_vec2: ...

    @padding.setter
    def padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def color_factor(self) -> float: ...

    @color_factor.setter
    def color_factor(self, arg: float, /) -> None: ...

    @property
    def disabled_factor(self) -> float: ...

    @disabled_factor.setter
    def disabled_factor(self, arg: float, /) -> None: ...

    @property
    def show_buttons(self) -> int: ...

    @show_buttons.setter
    def show_buttons(self, arg: int, /) -> None: ...

    @property
    def inc_button(self) -> nk_style_button: ...

    @inc_button.setter
    def inc_button(self, arg: nk_style_button, /) -> None: ...

    @property
    def dec_button(self) -> nk_style_button: ...

    @dec_button.setter
    def dec_button(self, arg: nk_style_button, /) -> None: ...

    @property
    def inc_symbol(self) -> nk_symbol_type: ...

    @inc_symbol.setter
    def inc_symbol(self, arg: nk_symbol_type, /) -> None: ...

    @property
    def dec_symbol(self) -> nk_symbol_type: ...

    @dec_symbol.setter
    def dec_symbol(self, arg: nk_symbol_type, /) -> None: ...

    @property
    def userdata(self) -> "nk_handle": ...

    @userdata.setter
    def userdata(self, arg: "nk_handle", /) -> None: ...

class nk_style_selectable:
    def __init__(self) -> None: ...

    @property
    def normal(self) -> nk_style_item: ...

    @normal.setter
    def normal(self, arg: nk_style_item, /) -> None: ...

    @property
    def hover(self) -> nk_style_item: ...

    @hover.setter
    def hover(self, arg: nk_style_item, /) -> None: ...

    @property
    def pressed(self) -> nk_style_item: ...

    @pressed.setter
    def pressed(self, arg: nk_style_item, /) -> None: ...

    @property
    def normal_active(self) -> nk_style_item: ...

    @normal_active.setter
    def normal_active(self, arg: nk_style_item, /) -> None: ...

    @property
    def hover_active(self) -> nk_style_item: ...

    @hover_active.setter
    def hover_active(self, arg: nk_style_item, /) -> None: ...

    @property
    def pressed_active(self) -> nk_style_item: ...

    @pressed_active.setter
    def pressed_active(self, arg: nk_style_item, /) -> None: ...

    @property
    def text_normal(self) -> nk_color: ...

    @text_normal.setter
    def text_normal(self, arg: nk_color, /) -> None: ...

    @property
    def text_hover(self) -> nk_color: ...

    @text_hover.setter
    def text_hover(self, arg: nk_color, /) -> None: ...

    @property
    def text_pressed(self) -> nk_color: ...

    @text_pressed.setter
    def text_pressed(self, arg: nk_color, /) -> None: ...

    @property
    def text_normal_active(self) -> nk_color: ...

    @text_normal_active.setter
    def text_normal_active(self, arg: nk_color, /) -> None: ...

    @property
    def text_hover_active(self) -> nk_color: ...

    @text_hover_active.setter
    def text_hover_active(self, arg: nk_color, /) -> None: ...

    @property
    def text_pressed_active(self) -> nk_color: ...

    @text_pressed_active.setter
    def text_pressed_active(self, arg: nk_color, /) -> None: ...

    @property
    def text_background(self) -> nk_color: ...

    @text_background.setter
    def text_background(self, arg: nk_color, /) -> None: ...

    @property
    def text_alignment(self) -> int: ...

    @text_alignment.setter
    def text_alignment(self, arg: int, /) -> None: ...

    @property
    def rounding(self) -> float: ...

    @rounding.setter
    def rounding(self, arg: float, /) -> None: ...

    @property
    def padding(self) -> nk_vec2: ...

    @padding.setter
    def padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def touch_padding(self) -> nk_vec2: ...

    @touch_padding.setter
    def touch_padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def image_padding(self) -> nk_vec2: ...

    @image_padding.setter
    def image_padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def color_factor(self) -> float: ...

    @color_factor.setter
    def color_factor(self, arg: float, /) -> None: ...

    @property
    def disabled_factor(self) -> float: ...

    @disabled_factor.setter
    def disabled_factor(self, arg: float, /) -> None: ...

    @property
    def userdata(self) -> "nk_handle": ...

    @userdata.setter
    def userdata(self, arg: "nk_handle", /) -> None: ...

class nk_style_slider:
    def __init__(self) -> None: ...

    @property
    def normal(self) -> nk_style_item: ...

    @normal.setter
    def normal(self, arg: nk_style_item, /) -> None: ...

    @property
    def hover(self) -> nk_style_item: ...

    @hover.setter
    def hover(self, arg: nk_style_item, /) -> None: ...

    @property
    def active(self) -> nk_style_item: ...

    @active.setter
    def active(self, arg: nk_style_item, /) -> None: ...

    @property
    def border_color(self) -> nk_color: ...

    @border_color.setter
    def border_color(self, arg: nk_color, /) -> None: ...

    @property
    def bar_normal(self) -> nk_color: ...

    @bar_normal.setter
    def bar_normal(self, arg: nk_color, /) -> None: ...

    @property
    def bar_hover(self) -> nk_color: ...

    @bar_hover.setter
    def bar_hover(self, arg: nk_color, /) -> None: ...

    @property
    def bar_active(self) -> nk_color: ...

    @bar_active.setter
    def bar_active(self, arg: nk_color, /) -> None: ...

    @property
    def bar_filled(self) -> nk_color: ...

    @bar_filled.setter
    def bar_filled(self, arg: nk_color, /) -> None: ...

    @property
    def cursor_normal(self) -> nk_style_item: ...

    @cursor_normal.setter
    def cursor_normal(self, arg: nk_style_item, /) -> None: ...

    @property
    def cursor_hover(self) -> nk_style_item: ...

    @cursor_hover.setter
    def cursor_hover(self, arg: nk_style_item, /) -> None: ...

    @property
    def cursor_active(self) -> nk_style_item: ...

    @cursor_active.setter
    def cursor_active(self, arg: nk_style_item, /) -> None: ...

    @property
    def border(self) -> float: ...

    @border.setter
    def border(self, arg: float, /) -> None: ...

    @property
    def rounding(self) -> float: ...

    @rounding.setter
    def rounding(self, arg: float, /) -> None: ...

    @property
    def bar_height(self) -> float: ...

    @bar_height.setter
    def bar_height(self, arg: float, /) -> None: ...

    @property
    def padding(self) -> nk_vec2: ...

    @padding.setter
    def padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def spacing(self) -> nk_vec2: ...

    @spacing.setter
    def spacing(self, arg: nk_vec2, /) -> None: ...

    @property
    def cursor_size(self) -> nk_vec2: ...

    @cursor_size.setter
    def cursor_size(self, arg: nk_vec2, /) -> None: ...

    @property
    def color_factor(self) -> float: ...

    @color_factor.setter
    def color_factor(self, arg: float, /) -> None: ...

    @property
    def disabled_factor(self) -> float: ...

    @disabled_factor.setter
    def disabled_factor(self, arg: float, /) -> None: ...

    @property
    def show_buttons(self) -> int: ...

    @show_buttons.setter
    def show_buttons(self, arg: int, /) -> None: ...

    @property
    def inc_button(self) -> nk_style_button: ...

    @inc_button.setter
    def inc_button(self, arg: nk_style_button, /) -> None: ...

    @property
    def dec_button(self) -> nk_style_button: ...

    @dec_button.setter
    def dec_button(self, arg: nk_style_button, /) -> None: ...

    @property
    def inc_symbol(self) -> nk_symbol_type: ...

    @inc_symbol.setter
    def inc_symbol(self, arg: nk_symbol_type, /) -> None: ...

    @property
    def dec_symbol(self) -> nk_symbol_type: ...

    @dec_symbol.setter
    def dec_symbol(self, arg: nk_symbol_type, /) -> None: ...

    @property
    def userdata(self) -> "nk_handle": ...

    @userdata.setter
    def userdata(self, arg: "nk_handle", /) -> None: ...

class nk_style_tab:
    def __init__(self) -> None: ...

    @property
    def background(self) -> nk_style_item: ...

    @background.setter
    def background(self, arg: nk_style_item, /) -> None: ...

    @property
    def border_color(self) -> nk_color: ...

    @border_color.setter
    def border_color(self, arg: nk_color, /) -> None: ...

    @property
    def text(self) -> nk_color: ...

    @text.setter
    def text(self, arg: nk_color, /) -> None: ...

    @property
    def tab_maximize_button(self) -> nk_style_button: ...

    @tab_maximize_button.setter
    def tab_maximize_button(self, arg: nk_style_button, /) -> None: ...

    @property
    def tab_minimize_button(self) -> nk_style_button: ...

    @tab_minimize_button.setter
    def tab_minimize_button(self, arg: nk_style_button, /) -> None: ...

    @property
    def node_maximize_button(self) -> nk_style_button: ...

    @node_maximize_button.setter
    def node_maximize_button(self, arg: nk_style_button, /) -> None: ...

    @property
    def node_minimize_button(self) -> nk_style_button: ...

    @node_minimize_button.setter
    def node_minimize_button(self, arg: nk_style_button, /) -> None: ...

    @property
    def sym_minimize(self) -> nk_symbol_type: ...

    @sym_minimize.setter
    def sym_minimize(self, arg: nk_symbol_type, /) -> None: ...

    @property
    def sym_maximize(self) -> nk_symbol_type: ...

    @sym_maximize.setter
    def sym_maximize(self, arg: nk_symbol_type, /) -> None: ...

    @property
    def border(self) -> float: ...

    @border.setter
    def border(self, arg: float, /) -> None: ...

    @property
    def rounding(self) -> float: ...

    @rounding.setter
    def rounding(self, arg: float, /) -> None: ...

    @property
    def indent(self) -> float: ...

    @indent.setter
    def indent(self, arg: float, /) -> None: ...

    @property
    def padding(self) -> nk_vec2: ...

    @padding.setter
    def padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def spacing(self) -> nk_vec2: ...

    @spacing.setter
    def spacing(self, arg: nk_vec2, /) -> None: ...

    @property
    def color_factor(self) -> float: ...

    @color_factor.setter
    def color_factor(self, arg: float, /) -> None: ...

    @property
    def disabled_factor(self) -> float: ...

    @disabled_factor.setter
    def disabled_factor(self, arg: float, /) -> None: ...

class nk_style_text:
    def __init__(self) -> None: ...

    @property
    def color(self) -> nk_color: ...

    @color.setter
    def color(self, arg: nk_color, /) -> None: ...

    @property
    def padding(self) -> nk_vec2: ...

    @padding.setter
    def padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def color_factor(self) -> float: ...

    @color_factor.setter
    def color_factor(self, arg: float, /) -> None: ...

    @property
    def disabled_factor(self) -> float: ...

    @disabled_factor.setter
    def disabled_factor(self, arg: float, /) -> None: ...

class nk_style_toggle:
    def __init__(self) -> None: ...

    @property
    def normal(self) -> nk_style_item: ...

    @normal.setter
    def normal(self, arg: nk_style_item, /) -> None: ...

    @property
    def hover(self) -> nk_style_item: ...

    @hover.setter
    def hover(self, arg: nk_style_item, /) -> None: ...

    @property
    def active(self) -> nk_style_item: ...

    @active.setter
    def active(self, arg: nk_style_item, /) -> None: ...

    @property
    def border_color(self) -> nk_color: ...

    @border_color.setter
    def border_color(self, arg: nk_color, /) -> None: ...

    @property
    def cursor_normal(self) -> nk_style_item: ...

    @cursor_normal.setter
    def cursor_normal(self, arg: nk_style_item, /) -> None: ...

    @property
    def cursor_hover(self) -> nk_style_item: ...

    @cursor_hover.setter
    def cursor_hover(self, arg: nk_style_item, /) -> None: ...

    @property
    def text_normal(self) -> nk_color: ...

    @text_normal.setter
    def text_normal(self, arg: nk_color, /) -> None: ...

    @property
    def text_hover(self) -> nk_color: ...

    @text_hover.setter
    def text_hover(self, arg: nk_color, /) -> None: ...

    @property
    def text_active(self) -> nk_color: ...

    @text_active.setter
    def text_active(self, arg: nk_color, /) -> None: ...

    @property
    def text_background(self) -> nk_color: ...

    @text_background.setter
    def text_background(self, arg: nk_color, /) -> None: ...

    @property
    def text_alignment(self) -> int: ...

    @text_alignment.setter
    def text_alignment(self, arg: int, /) -> None: ...

    @property
    def padding(self) -> nk_vec2: ...

    @padding.setter
    def padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def touch_padding(self) -> nk_vec2: ...

    @touch_padding.setter
    def touch_padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def spacing(self) -> float: ...

    @spacing.setter
    def spacing(self, arg: float, /) -> None: ...

    @property
    def border(self) -> float: ...

    @border.setter
    def border(self, arg: float, /) -> None: ...

    @property
    def color_factor(self) -> float: ...

    @color_factor.setter
    def color_factor(self, arg: float, /) -> None: ...

    @property
    def disabled_factor(self) -> float: ...

    @disabled_factor.setter
    def disabled_factor(self, arg: float, /) -> None: ...

    @property
    def userdata(self) -> "nk_handle": ...

    @userdata.setter
    def userdata(self, arg: "nk_handle", /) -> None: ...

class nk_style_window:
    def __init__(self) -> None: ...

    @property
    def header(self) -> nk_style_window_header: ...

    @header.setter
    def header(self, arg: nk_style_window_header, /) -> None: ...

    @property
    def fixed_background(self) -> nk_style_item: ...

    @fixed_background.setter
    def fixed_background(self, arg: nk_style_item, /) -> None: ...

    @property
    def background(self) -> nk_color: ...

    @background.setter
    def background(self, arg: nk_color, /) -> None: ...

    @property
    def border_color(self) -> nk_color: ...

    @border_color.setter
    def border_color(self, arg: nk_color, /) -> None: ...

    @property
    def popup_border_color(self) -> nk_color: ...

    @popup_border_color.setter
    def popup_border_color(self, arg: nk_color, /) -> None: ...

    @property
    def combo_border_color(self) -> nk_color: ...

    @combo_border_color.setter
    def combo_border_color(self, arg: nk_color, /) -> None: ...

    @property
    def contextual_border_color(self) -> nk_color: ...

    @contextual_border_color.setter
    def contextual_border_color(self, arg: nk_color, /) -> None: ...

    @property
    def menu_border_color(self) -> nk_color: ...

    @menu_border_color.setter
    def menu_border_color(self, arg: nk_color, /) -> None: ...

    @property
    def group_border_color(self) -> nk_color: ...

    @group_border_color.setter
    def group_border_color(self, arg: nk_color, /) -> None: ...

    @property
    def tooltip_border_color(self) -> nk_color: ...

    @tooltip_border_color.setter
    def tooltip_border_color(self, arg: nk_color, /) -> None: ...

    @property
    def scaler(self) -> nk_style_item: ...

    @scaler.setter
    def scaler(self, arg: nk_style_item, /) -> None: ...

    @property
    def border(self) -> float: ...

    @border.setter
    def border(self, arg: float, /) -> None: ...

    @property
    def combo_border(self) -> float: ...

    @combo_border.setter
    def combo_border(self, arg: float, /) -> None: ...

    @property
    def contextual_border(self) -> float: ...

    @contextual_border.setter
    def contextual_border(self, arg: float, /) -> None: ...

    @property
    def menu_border(self) -> float: ...

    @menu_border.setter
    def menu_border(self, arg: float, /) -> None: ...

    @property
    def group_border(self) -> float: ...

    @group_border.setter
    def group_border(self, arg: float, /) -> None: ...

    @property
    def tooltip_border(self) -> float: ...

    @tooltip_border.setter
    def tooltip_border(self, arg: float, /) -> None: ...

    @property
    def popup_border(self) -> float: ...

    @popup_border.setter
    def popup_border(self, arg: float, /) -> None: ...

    @property
    def min_row_height_padding(self) -> float: ...

    @min_row_height_padding.setter
    def min_row_height_padding(self, arg: float, /) -> None: ...

    @property
    def rounding(self) -> float: ...

    @rounding.setter
    def rounding(self, arg: float, /) -> None: ...

    @property
    def spacing(self) -> nk_vec2: ...

    @spacing.setter
    def spacing(self, arg: nk_vec2, /) -> None: ...

    @property
    def scrollbar_size(self) -> nk_vec2: ...

    @scrollbar_size.setter
    def scrollbar_size(self, arg: nk_vec2, /) -> None: ...

    @property
    def min_size(self) -> nk_vec2: ...

    @min_size.setter
    def min_size(self, arg: nk_vec2, /) -> None: ...

    @property
    def padding(self) -> nk_vec2: ...

    @padding.setter
    def padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def group_padding(self) -> nk_vec2: ...

    @group_padding.setter
    def group_padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def popup_padding(self) -> nk_vec2: ...

    @popup_padding.setter
    def popup_padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def combo_padding(self) -> nk_vec2: ...

    @combo_padding.setter
    def combo_padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def contextual_padding(self) -> nk_vec2: ...

    @contextual_padding.setter
    def contextual_padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def menu_padding(self) -> nk_vec2: ...

    @menu_padding.setter
    def menu_padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def tooltip_padding(self) -> nk_vec2: ...

    @tooltip_padding.setter
    def tooltip_padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def tooltip_origin(self) -> nk_tooltip_pos: ...

    @tooltip_origin.setter
    def tooltip_origin(self, arg: nk_tooltip_pos, /) -> None: ...

    @property
    def tooltip_offset(self) -> nk_vec2: ...

    @tooltip_offset.setter
    def tooltip_offset(self, arg: nk_vec2, /) -> None: ...

class nk_style_window_header:
    def __init__(self) -> None: ...

    @property
    def normal(self) -> nk_style_item: ...

    @normal.setter
    def normal(self, arg: nk_style_item, /) -> None: ...

    @property
    def hover(self) -> nk_style_item: ...

    @hover.setter
    def hover(self, arg: nk_style_item, /) -> None: ...

    @property
    def active(self) -> nk_style_item: ...

    @active.setter
    def active(self, arg: nk_style_item, /) -> None: ...

    @property
    def close_button(self) -> nk_style_button: ...

    @close_button.setter
    def close_button(self, arg: nk_style_button, /) -> None: ...

    @property
    def minimize_button(self) -> nk_style_button: ...

    @minimize_button.setter
    def minimize_button(self, arg: nk_style_button, /) -> None: ...

    @property
    def close_symbol(self) -> nk_symbol_type: ...

    @close_symbol.setter
    def close_symbol(self, arg: nk_symbol_type, /) -> None: ...

    @property
    def minimize_symbol(self) -> nk_symbol_type: ...

    @minimize_symbol.setter
    def minimize_symbol(self, arg: nk_symbol_type, /) -> None: ...

    @property
    def maximize_symbol(self) -> nk_symbol_type: ...

    @maximize_symbol.setter
    def maximize_symbol(self, arg: nk_symbol_type, /) -> None: ...

    @property
    def label_normal(self) -> nk_color: ...

    @label_normal.setter
    def label_normal(self, arg: nk_color, /) -> None: ...

    @property
    def label_hover(self) -> nk_color: ...

    @label_hover.setter
    def label_hover(self, arg: nk_color, /) -> None: ...

    @property
    def label_active(self) -> nk_color: ...

    @label_active.setter
    def label_active(self, arg: nk_color, /) -> None: ...

    @property
    def align(self) -> nk_style_header_align: ...

    @align.setter
    def align(self, arg: nk_style_header_align, /) -> None: ...

    @property
    def padding(self) -> nk_vec2: ...

    @padding.setter
    def padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def label_padding(self) -> nk_vec2: ...

    @label_padding.setter
    def label_padding(self, arg: nk_vec2, /) -> None: ...

    @property
    def spacing(self) -> nk_vec2: ...

    @spacing.setter
    def spacing(self, arg: nk_vec2, /) -> None: ...

class nk_symbol_type(enum.Enum):
    NK_SYMBOL_NONE = 0

    NK_SYMBOL_X = 1

    NK_SYMBOL_UNDERSCORE = 2

    NK_SYMBOL_CIRCLE_SOLID = 3

    NK_SYMBOL_CIRCLE_OUTLINE = 4

    NK_SYMBOL_RECT_SOLID = 5

    NK_SYMBOL_RECT_OUTLINE = 6

    NK_SYMBOL_TRIANGLE_UP = 7

    NK_SYMBOL_TRIANGLE_DOWN = 8

    NK_SYMBOL_TRIANGLE_LEFT = 9

    NK_SYMBOL_TRIANGLE_RIGHT = 10

    NK_SYMBOL_PLUS = 11

    NK_SYMBOL_MINUS = 12

    NK_SYMBOL_TRIANGLE_UP_OUTLINE = 13

    NK_SYMBOL_TRIANGLE_DOWN_OUTLINE = 14

    NK_SYMBOL_TRIANGLE_LEFT_OUTLINE = 15

    NK_SYMBOL_TRIANGLE_RIGHT_OUTLINE = 16

    NK_SYMBOL_MAX = 17

class nk_table:
    def __init__(self) -> None: ...

    @property
    def seq(self) -> int: ...

    @seq.setter
    def seq(self, arg: int, /) -> None: ...

    @property
    def size(self) -> int: ...

    @size.setter
    def size(self, arg: int, /) -> None: ...

class nk_text_align(enum.Flag):
    NK_TEXT_ALIGN_LEFT = 1

    NK_TEXT_ALIGN_CENTERED = 2

    NK_TEXT_ALIGN_RIGHT = 4

    NK_TEXT_ALIGN_TOP = 8

    NK_TEXT_ALIGN_MIDDLE = 16

    NK_TEXT_ALIGN_BOTTOM = 32

class nk_text_alignment(enum.Flag):
    NK_TEXT_LEFT = 17

    NK_TEXT_CENTERED = 18

    NK_TEXT_RIGHT = 20

class nk_text_edit:
    def __init__(self) -> None: ...

    @property
    def clip(self) -> nk_clipboard: ...

    @clip.setter
    def clip(self, arg: nk_clipboard, /) -> None: ...

    @property
    def string(self) -> nk_str: ...

    @string.setter
    def string(self, arg: nk_str, /) -> None: ...

    @property
    def scrollbar(self) -> nk_vec2: ...

    @scrollbar.setter
    def scrollbar(self, arg: nk_vec2, /) -> None: ...

    @property
    def cursor(self) -> int: ...

    @cursor.setter
    def cursor(self, arg: int, /) -> None: ...

    @property
    def select_start(self) -> int: ...

    @select_start.setter
    def select_start(self, arg: int, /) -> None: ...

    @property
    def select_end(self) -> int: ...

    @select_end.setter
    def select_end(self, arg: int, /) -> None: ...

    @property
    def mode(self) -> int: ...

    @mode.setter
    def mode(self, arg: int, /) -> None: ...

    @property
    def cursor_at_end_of_line(self) -> int: ...

    @cursor_at_end_of_line.setter
    def cursor_at_end_of_line(self, arg: int, /) -> None: ...

    @property
    def initialized(self) -> int: ...

    @initialized.setter
    def initialized(self, arg: int, /) -> None: ...

    @property
    def has_preferred_x(self) -> int: ...

    @has_preferred_x.setter
    def has_preferred_x(self, arg: int, /) -> None: ...

    @property
    def single_line(self) -> int: ...

    @single_line.setter
    def single_line(self, arg: int, /) -> None: ...

    @property
    def active(self) -> int: ...

    @active.setter
    def active(self, arg: int, /) -> None: ...

    @property
    def padding1(self) -> int: ...

    @padding1.setter
    def padding1(self, arg: int, /) -> None: ...

    @property
    def preferred_x(self) -> float: ...

    @preferred_x.setter
    def preferred_x(self, arg: float, /) -> None: ...

    @property
    def undo(self) -> nk_text_undo_state: ...

    @undo.setter
    def undo(self, arg: nk_text_undo_state, /) -> None: ...

class nk_text_edit_mode(enum.Enum):
    NK_TEXT_EDIT_MODE_VIEW = 0

    NK_TEXT_EDIT_MODE_INSERT = 1

    NK_TEXT_EDIT_MODE_REPLACE = 2

class nk_text_edit_type(enum.Enum):
    NK_TEXT_EDIT_SINGLE_LINE = 0

    NK_TEXT_EDIT_MULTI_LINE = 1

class nk_text_undo_record:
    def __init__(self) -> None: ...

    @property
    def where(self) -> int: ...

    @where.setter
    def where(self, arg: int, /) -> None: ...

    @property
    def insert_length(self) -> int: ...

    @insert_length.setter
    def insert_length(self, arg: int, /) -> None: ...

    @property
    def delete_length(self) -> int: ...

    @delete_length.setter
    def delete_length(self, arg: int, /) -> None: ...

    @property
    def char_storage(self) -> int: ...

    @char_storage.setter
    def char_storage(self, arg: int, /) -> None: ...

class nk_text_undo_state:
    def __init__(self) -> None: ...

    @property
    def undo_point(self) -> int: ...

    @undo_point.setter
    def undo_point(self, arg: int, /) -> None: ...

    @property
    def redo_point(self) -> int: ...

    @redo_point.setter
    def redo_point(self, arg: int, /) -> None: ...

    @property
    def undo_char_point(self) -> int: ...

    @undo_char_point.setter
    def undo_char_point(self, arg: int, /) -> None: ...

    @property
    def redo_char_point(self) -> int: ...

    @redo_char_point.setter
    def redo_char_point(self, arg: int, /) -> None: ...

class nk_tooltip_pos(enum.Enum):
    NK_TOP_LEFT = 0

    NK_TOP_CENTER = 1

    NK_TOP_RIGHT = 2

    NK_MIDDLE_LEFT = 3

    NK_MIDDLE_CENTER = 4

    NK_MIDDLE_RIGHT = 5

    NK_BOTTOM_LEFT = 6

    NK_BOTTOM_CENTER = 7

    NK_BOTTOM_RIGHT = 8

class nk_tree_type(enum.Enum):
    NK_TREE_NODE = 0

    NK_TREE_TAB = 1

class nk_user_font:
    def __init__(self) -> None: ...

    @property
    def userdata(self) -> "nk_handle": ...

    @userdata.setter
    def userdata(self, arg: "nk_handle", /) -> None: ...

    @property
    def height(self) -> float: ...

    @height.setter
    def height(self, arg: float, /) -> None: ...

    @property
    def texture(self) -> "nk_handle": ...

    @texture.setter
    def texture(self, arg: "nk_handle", /) -> None: ...

class nk_user_font_glyph:
    def __init__(self) -> None: ...

    @property
    def offset(self) -> nk_vec2: ...

    @offset.setter
    def offset(self, arg: nk_vec2, /) -> None: ...

    @property
    def height(self) -> float: ...

    @height.setter
    def height(self, arg: float, /) -> None: ...

    @property
    def xadvance(self) -> float: ...

    @xadvance.setter
    def xadvance(self, arg: float, /) -> None: ...

class nk_vec2:
    def __init__(self) -> None: ...

    @property
    def x(self) -> float: ...

    @x.setter
    def x(self, arg: float, /) -> None: ...

    @property
    def y(self) -> float: ...

    @y.setter
    def y(self, arg: float, /) -> None: ...

class nk_vec2i:
    def __init__(self) -> None: ...

    @property
    def y(self) -> int: ...

    @y.setter
    def y(self, arg: int, /) -> None: ...

class nk_widget_align(enum.Flag):
    NK_WIDGET_ALIGN_LEFT = 1

    NK_WIDGET_ALIGN_CENTERED = 2

    NK_WIDGET_ALIGN_RIGHT = 4

    NK_WIDGET_ALIGN_TOP = 8

    NK_WIDGET_ALIGN_MIDDLE = 16

    NK_WIDGET_ALIGN_BOTTOM = 32

class nk_widget_alignment(enum.Flag):
    NK_WIDGET_LEFT = 17

    NK_WIDGET_CENTERED = 18

    NK_WIDGET_RIGHT = 20

class nk_widget_layout_states(enum.Enum):
    NK_WIDGET_INVALID = 0

    NK_WIDGET_VALID = 1

    NK_WIDGET_ROM = 2

    NK_WIDGET_DISABLED = 3

class nk_widget_states(enum.Flag):
    NK_WIDGET_STATE_MODIFIED = 2

    NK_WIDGET_STATE_INACTIVE = 4

    NK_WIDGET_STATE_ENTERED = 8

    NK_WIDGET_STATE_HOVER = 16

    NK_WIDGET_STATE_ACTIVED = 32

    NK_WIDGET_STATE_LEFT = 64

    NK_WIDGET_STATE_HOVERED = 18

    NK_WIDGET_STATE_ACTIVE = 34

class nk_window:
    def __init__(self) -> None: ...

    @property
    def seq(self) -> int: ...

    @seq.setter
    def seq(self, arg: int, /) -> None: ...

    @property
    def name(self) -> int: ...

    @name.setter
    def name(self, arg: int, /) -> None: ...

    @property
    def flags(self) -> int: ...

    @flags.setter
    def flags(self, arg: int, /) -> None: ...

    @property
    def bounds(self) -> nk_rect: ...

    @bounds.setter
    def bounds(self, arg: nk_rect, /) -> None: ...

    @property
    def scrollbar(self) -> nk_scroll: ...

    @scrollbar.setter
    def scrollbar(self, arg: nk_scroll, /) -> None: ...

    @property
    def buffer(self) -> nk_command_buffer: ...

    @buffer.setter
    def buffer(self, arg: nk_command_buffer, /) -> None: ...

    @property
    def scrollbar_hiding_timer(self) -> float: ...

    @scrollbar_hiding_timer.setter
    def scrollbar_hiding_timer(self, arg: float, /) -> None: ...

    @property
    def property(self) -> nk_property_state: ...

    @property.setter
    def property(self, arg: nk_property_state, /) -> None: ...

    @property
    def popup(self) -> nk_popup_state: ...

    @popup.setter
    def popup(self, arg: nk_popup_state, /) -> None: ...

    @property
    def edit(self) -> nk_edit_state: ...

    @edit.setter
    def edit(self, arg: nk_edit_state, /) -> None: ...

    @property
    def scrolled(self) -> int: ...

    @scrolled.setter
    def scrolled(self, arg: int, /) -> None: ...

    @property
    def widgets_disabled(self) -> bool: ...

    @widgets_disabled.setter
    def widgets_disabled(self, arg: bool, /) -> None: ...

    @property
    def table_count(self) -> int: ...

    @table_count.setter
    def table_count(self, arg: int, /) -> None: ...

class nk_window_flags(enum.Flag):
    NK_WINDOW_PRIVATE = 2048

    NK_WINDOW_DYNAMIC = 2048

    NK_WINDOW_ROM = 4096

    NK_WINDOW_NOT_INTERACTIVE = 5120

    NK_WINDOW_HIDDEN = 8192

    NK_WINDOW_CLOSED = 16384

    NK_WINDOW_MINIMIZED = 32768

    NK_WINDOW_REMOVE_ROM = 65536
