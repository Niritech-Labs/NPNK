

typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;






typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;



typedef long int __quad_t;
typedef unsigned long int __u_quad_t;







typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;


typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;

typedef int __daddr_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;


typedef long int __fsword_t;

typedef long int __ssize_t;


typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;




typedef int __sig_atomic_t;




typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;


typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;



typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;


typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;





typedef signed char int_fast8_t;

typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;

typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef long int intptr_t;


typedef unsigned long int uintptr_t;
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
typedef int8_t nk_char;
typedef uint8_t nk_uchar;
typedef uint8_t nk_byte;
typedef int16_t nk_short;
typedef uint16_t nk_ushort;
typedef int32_t nk_int;
typedef uint32_t nk_uint;
typedef uintptr_t nk_size;
typedef uintptr_t nk_ptr;
typedef int nk_bool;

typedef nk_uint nk_hash;
typedef nk_uint nk_flags;
typedef nk_uint nk_rune;




typedef char _dummy_array446[(sizeof(nk_short) == 2)?1:-1];
typedef char _dummy_array447[(sizeof(nk_ushort) == 2)?1:-1];
typedef char _dummy_array448[(sizeof(nk_uint) == 4)?1:-1];
typedef char _dummy_array449[(sizeof(nk_int) == 4)?1:-1];
typedef char _dummy_array450[(sizeof(nk_byte) == 1)?1:-1];
typedef char _dummy_array451[(sizeof(nk_flags) >= 4)?1:-1];
typedef char _dummy_array452[(sizeof(nk_rune) >= 4)?1:-1];
typedef char _dummy_array453[(sizeof(nk_size) >= sizeof(void*))?1:-1];
typedef char _dummy_array454[(sizeof(nk_ptr) >= sizeof(void*))?1:-1];
typedef char _dummy_array455[(sizeof(nk_bool) <= sizeof(int))?1:-1];






struct nk_buffer;
struct nk_allocator;
struct nk_command_buffer;
struct nk_draw_command;
struct nk_convert_config;
struct nk_style_item;
struct nk_text_edit;
struct nk_draw_list;
struct nk_user_font;
struct nk_panel;
struct nk_context;
struct nk_draw_vertex_layout_element;
struct nk_style_button;
struct nk_style_toggle;
struct nk_style_selectable;
struct nk_style_slide;
struct nk_style_progress;
struct nk_style_scrollbar;
struct nk_style_edit;
struct nk_style_property;
struct nk_style_chart;
struct nk_style_combo;
struct nk_style_tab;
struct nk_style_window_header;
struct nk_style_window;

enum {nk_false, nk_true};
struct nk_color {nk_byte r,g,b,a;};
struct nk_colorf {float r,g,b,a;};
struct nk_vec2 {float x,y;};
struct nk_vec2i {short x, y;};
struct nk_rect {float x,y,w,h;};
struct nk_recti {short x,y,w,h;};
typedef char nk_glyph[4];
typedef union {void *ptr; int id;} nk_handle;
struct nk_image {nk_handle handle; nk_ushort w, h; nk_ushort region[4];};
struct nk_nine_slice {struct nk_image img; nk_ushort l, t, r, b;};
struct nk_cursor {struct nk_image img; struct nk_vec2 size, offset;};
struct nk_scroll {nk_uint x, y;};


typedef char _dummy_array503[(!((nk_bool)0) == !(nk_false))?1:-1];
typedef char _dummy_array504[(!((nk_bool)1) == !(nk_true))?1:-1];

enum nk_heading {NK_UP, NK_RIGHT, NK_DOWN, NK_LEFT};
enum nk_button_behavior {NK_BUTTON_DEFAULT, NK_BUTTON_REPEATER};
enum nk_modify {NK_FIXED = nk_false, NK_MODIFIABLE = nk_true};
enum nk_orientation {NK_VERTICAL, NK_HORIZONTAL};
enum nk_collapse_states {NK_MINIMIZED = nk_false, NK_MAXIMIZED = nk_true};
enum nk_show_states {NK_HIDDEN = nk_false, NK_SHOWN = nk_true};
enum nk_chart_type {NK_CHART_LINES, NK_CHART_COLUMN, NK_CHART_MAX};
enum nk_chart_event {NK_CHART_HOVERING = 0x01, NK_CHART_CLICKED = 0x02};
enum nk_color_format {NK_RGB, NK_RGBA};
enum nk_popup_type {NK_POPUP_STATIC, NK_POPUP_DYNAMIC};
enum nk_layout_format {NK_DYNAMIC, NK_STATIC};
enum nk_tree_type {NK_TREE_NODE, NK_TREE_TAB};

enum nk_tooltip_pos {
    NK_TOP_LEFT,
    NK_TOP_CENTER,
    NK_TOP_RIGHT,

    NK_MIDDLE_LEFT,
    NK_MIDDLE_CENTER,
    NK_MIDDLE_RIGHT,

    NK_BOTTOM_LEFT,
    NK_BOTTOM_CENTER,
    NK_BOTTOM_RIGHT
};

typedef void*(*nk_plugin_alloc)(nk_handle, void *old, nk_size);
typedef void (*nk_plugin_free)(nk_handle, void *old);
typedef nk_bool(*nk_plugin_filter)(const struct nk_text_edit*, nk_rune unicode);
typedef void(*nk_plugin_paste)(nk_handle, struct nk_text_edit*);
typedef void(*nk_plugin_copy)(nk_handle, const char*, int len);

struct nk_allocator {
    nk_handle userdata;
    nk_plugin_alloc alloc;
    nk_plugin_free free;
};
enum nk_symbol_type {
    NK_SYMBOL_NONE,
    NK_SYMBOL_X,
    NK_SYMBOL_UNDERSCORE,
    NK_SYMBOL_CIRCLE_SOLID,
    NK_SYMBOL_CIRCLE_OUTLINE,
    NK_SYMBOL_RECT_SOLID,
    NK_SYMBOL_RECT_OUTLINE,
    NK_SYMBOL_TRIANGLE_UP,
    NK_SYMBOL_TRIANGLE_DOWN,
    NK_SYMBOL_TRIANGLE_LEFT,
    NK_SYMBOL_TRIANGLE_RIGHT,
    NK_SYMBOL_PLUS,
    NK_SYMBOL_MINUS,
    NK_SYMBOL_TRIANGLE_UP_OUTLINE,
    NK_SYMBOL_TRIANGLE_DOWN_OUTLINE,
    NK_SYMBOL_TRIANGLE_LEFT_OUTLINE,
    NK_SYMBOL_TRIANGLE_RIGHT_OUTLINE,
    NK_SYMBOL_MAX
};
extern nk_bool nk_init_default(struct nk_context*, const struct nk_user_font*);
extern nk_bool nk_init_fixed(struct nk_context*, void *memory, nk_size size, const struct nk_user_font*);
extern nk_bool nk_init(struct nk_context*, const struct nk_allocator*, const struct nk_user_font*);
extern nk_bool nk_init_custom(struct nk_context*, struct nk_buffer *cmds, struct nk_buffer *pool, const struct nk_user_font*);
extern void nk_clear(struct nk_context*);
extern void nk_free(struct nk_context*);
enum nk_keys {
    NK_KEY_NONE,
    NK_KEY_SHIFT,
    NK_KEY_CTRL,
    NK_KEY_DEL,
    NK_KEY_ENTER,
    NK_KEY_TAB,
    NK_KEY_BACKSPACE,
    NK_KEY_COPY,
    NK_KEY_CUT,
    NK_KEY_PASTE,
    NK_KEY_UP,
    NK_KEY_DOWN,
    NK_KEY_LEFT,
    NK_KEY_RIGHT,

    NK_KEY_TEXT_INSERT_MODE,
    NK_KEY_TEXT_REPLACE_MODE,
    NK_KEY_TEXT_RESET_MODE,
    NK_KEY_TEXT_LINE_START,
    NK_KEY_TEXT_LINE_END,
    NK_KEY_TEXT_START,
    NK_KEY_TEXT_END,
    NK_KEY_TEXT_UNDO,
    NK_KEY_TEXT_REDO,
    NK_KEY_TEXT_SELECT_ALL,
    NK_KEY_TEXT_WORD_LEFT,
    NK_KEY_TEXT_WORD_RIGHT,

    NK_KEY_SCROLL_START,
    NK_KEY_SCROLL_END,
    NK_KEY_SCROLL_DOWN,
    NK_KEY_SCROLL_UP,
    NK_KEY_MAX
};
enum nk_buttons {
    NK_BUTTON_LEFT,
    NK_BUTTON_MIDDLE,
    NK_BUTTON_RIGHT,
    NK_BUTTON_DOUBLE,
    NK_BUTTON_MAX
};
extern void nk_input_begin(struct nk_context*);
extern void nk_input_motion(struct nk_context*, int x, int y);
extern void nk_input_key(struct nk_context*, enum nk_keys, nk_bool down);
extern void nk_input_button(struct nk_context*, enum nk_buttons, int x, int y, nk_bool down);
extern void nk_input_scroll(struct nk_context*, struct nk_vec2 val);
extern void nk_input_char(struct nk_context*, char);
extern void nk_input_glyph(struct nk_context*, const nk_glyph);
extern void nk_input_unicode(struct nk_context*, nk_rune);
extern void nk_input_end(struct nk_context*);
enum nk_anti_aliasing {NK_ANTI_ALIASING_OFF, NK_ANTI_ALIASING_ON};
enum nk_convert_result {
    NK_CONVERT_SUCCESS = 0,
    NK_CONVERT_INVALID_PARAM = 1,
    NK_CONVERT_COMMAND_BUFFER_FULL = (1 << (1)),
    NK_CONVERT_VERTEX_BUFFER_FULL = (1 << (2)),
    NK_CONVERT_ELEMENT_BUFFER_FULL = (1 << (3))
};
struct nk_draw_null_texture {
    nk_handle texture;
    struct nk_vec2 uv;
};
struct nk_convert_config {
    float global_alpha;
    enum nk_anti_aliasing line_AA;
    enum nk_anti_aliasing shape_AA;
    unsigned circle_segment_count;
    unsigned arc_segment_count;
    unsigned curve_segment_count;
    struct nk_draw_null_texture tex_null;
    const struct nk_draw_vertex_layout_element *vertex_layout;
    nk_size vertex_size;
    nk_size vertex_alignment;
};
extern const struct nk_command* nk__begin(struct nk_context*);
extern const struct nk_command* nk__next(struct nk_context*, const struct nk_command*);
extern nk_flags nk_convert(struct nk_context*, struct nk_buffer *cmds, struct nk_buffer *vertices, struct nk_buffer *elements, const struct nk_convert_config*);
extern const struct nk_draw_command* nk__draw_begin(const struct nk_context*, const struct nk_buffer*);
extern const struct nk_draw_command* nk__draw_end(const struct nk_context*, const struct nk_buffer*);
extern const struct nk_draw_command* nk__draw_next(const struct nk_draw_command*, const struct nk_buffer*, const struct nk_context*);
enum nk_panel_flags {
    NK_WINDOW_BORDER = (1 << (0)),
    NK_WINDOW_MOVABLE = (1 << (1)),
    NK_WINDOW_SCALABLE = (1 << (2)),
    NK_WINDOW_CLOSABLE = (1 << (3)),
    NK_WINDOW_MINIMIZABLE = (1 << (4)),
    NK_WINDOW_NO_SCROLLBAR = (1 << (5)),
    NK_WINDOW_TITLE = (1 << (6)),
    NK_WINDOW_SCROLL_AUTO_HIDE = (1 << (7)),
    NK_WINDOW_BACKGROUND = (1 << (8)),
    NK_WINDOW_SCALE_LEFT = (1 << (9)),
    NK_WINDOW_NO_INPUT = (1 << (10))
};
extern nk_bool nk_begin(struct nk_context *ctx, const char *title, struct nk_rect bounds, nk_flags flags);
extern nk_bool nk_begin_titled(struct nk_context *ctx, const char *name, const char *title, struct nk_rect bounds, nk_flags flags);
extern void nk_end(struct nk_context *ctx);
extern struct nk_window *nk_window_find(const struct nk_context *ctx, const char *name);
extern struct nk_rect nk_window_get_bounds(const struct nk_context *ctx);
extern struct nk_vec2 nk_window_get_position(const struct nk_context *ctx);
extern struct nk_vec2 nk_window_get_size(const struct nk_context *ctx);
extern float nk_window_get_width(const struct nk_context *ctx);
extern float nk_window_get_height(const struct nk_context* ctx);
extern struct nk_panel* nk_window_get_panel(const struct nk_context* ctx);
extern struct nk_rect nk_window_get_content_region(const struct nk_context* ctx);
extern struct nk_vec2 nk_window_get_content_region_min(const struct nk_context *ctx);
extern struct nk_vec2 nk_window_get_content_region_max(const struct nk_context *ctx);
extern struct nk_vec2 nk_window_get_content_region_size(const struct nk_context *ctx);
extern struct nk_command_buffer* nk_window_get_canvas(const struct nk_context* ctx);
extern void nk_window_get_scroll(const struct nk_context *ctx, nk_uint *offset_x, nk_uint *offset_y);
extern nk_bool nk_window_has_focus(const struct nk_context *ctx);
extern nk_bool nk_window_is_hovered(const struct nk_context *ctx);
extern nk_bool nk_window_is_collapsed(const struct nk_context *ctx, const char *name);
extern nk_bool nk_window_is_closed(const struct nk_context *ctx, const char* name);
extern nk_bool nk_window_is_hidden(const struct nk_context *ctx, const char* name);
extern nk_bool nk_window_is_active(const struct nk_context *ctx, const char* name);
extern nk_bool nk_window_is_any_hovered(const struct nk_context *ctx);
extern nk_bool nk_item_is_any_active(const struct nk_context *ctx);
extern void nk_window_set_bounds(struct nk_context *ctx, const char *name, struct nk_rect bounds);
extern void nk_window_set_position(struct nk_context *ctx, const char *name, struct nk_vec2 pos);
extern void nk_window_set_size(struct nk_context *ctx, const char *name, struct nk_vec2 size);
extern void nk_window_set_focus(struct nk_context *ctx, const char *name);
extern void nk_window_set_scroll(struct nk_context *ctx, nk_uint offset_x, nk_uint offset_y);
extern void nk_window_close(struct nk_context *ctx, const char *name);
extern void nk_window_collapse(struct nk_context *ctx, const char *name, enum nk_collapse_states state);
extern void nk_window_collapse_if(struct nk_context *ctx, const char *name, enum nk_collapse_states state, int cond);
extern void nk_window_show(struct nk_context *ctx, const char *name, enum nk_show_states state);
extern void nk_window_show_if(struct nk_context *ctx, const char *name, enum nk_show_states state, int cond);
extern void nk_rule_horizontal(struct nk_context *ctx, struct nk_color color, nk_bool rounding);
enum nk_widget_align {
    NK_WIDGET_ALIGN_LEFT = 0x01,
    NK_WIDGET_ALIGN_CENTERED = 0x02,
    NK_WIDGET_ALIGN_RIGHT = 0x04,
    NK_WIDGET_ALIGN_TOP = 0x08,
    NK_WIDGET_ALIGN_MIDDLE = 0x10,
    NK_WIDGET_ALIGN_BOTTOM = 0x20
};
enum nk_widget_alignment {
    NK_WIDGET_LEFT = NK_WIDGET_ALIGN_MIDDLE|NK_WIDGET_ALIGN_LEFT,
    NK_WIDGET_CENTERED = NK_WIDGET_ALIGN_MIDDLE|NK_WIDGET_ALIGN_CENTERED,
    NK_WIDGET_RIGHT = NK_WIDGET_ALIGN_MIDDLE|NK_WIDGET_ALIGN_RIGHT
};
extern void nk_layout_set_min_row_height(struct nk_context*, float height);
extern void nk_layout_reset_min_row_height(struct nk_context*);
extern struct nk_rect nk_layout_widget_bounds(const struct nk_context *ctx);
extern float nk_layout_ratio_from_pixel(const struct nk_context *ctx, float pixel_width);
extern void nk_layout_row_dynamic(struct nk_context *ctx, float height, int cols);
extern void nk_layout_row_static(struct nk_context *ctx, float height, int item_width, int cols);
extern void nk_layout_row_begin(struct nk_context *ctx, enum nk_layout_format fmt, float row_height, int cols);
extern void nk_layout_row_push(struct nk_context*, float value);
extern void nk_layout_row_end(struct nk_context*);
extern void nk_layout_row(struct nk_context*, enum nk_layout_format, float height, int cols, const float *ratio);
extern void nk_layout_row_template_begin(struct nk_context*, float row_height);
extern void nk_layout_row_template_push_dynamic(struct nk_context*);
extern void nk_layout_row_template_push_variable(struct nk_context*, float min_width);
extern void nk_layout_row_template_push_static(struct nk_context*, float width);
extern void nk_layout_row_template_end(struct nk_context*);
extern void nk_layout_space_begin(struct nk_context*, enum nk_layout_format, float height, int widget_count);
extern void nk_layout_space_push(struct nk_context*, struct nk_rect bounds);
extern void nk_layout_space_end(struct nk_context*);
extern struct nk_rect nk_layout_space_bounds(const struct nk_context *ctx);
extern struct nk_vec2 nk_layout_space_to_screen(const struct nk_context* ctx, struct nk_vec2 vec);
extern struct nk_vec2 nk_layout_space_to_local(const struct nk_context *ctx, struct nk_vec2 vec);
extern struct nk_rect nk_layout_space_rect_to_screen(const struct nk_context *ctx, struct nk_rect bounds);
extern struct nk_rect nk_layout_space_rect_to_local(const struct nk_context *ctx, struct nk_rect bounds);
extern void nk_spacer(struct nk_context *ctx);
extern nk_bool nk_group_begin(struct nk_context*, const char *title, nk_flags);
extern nk_bool nk_group_begin_titled(struct nk_context*, const char *name, const char *title, nk_flags);
extern void nk_group_end(struct nk_context*);
extern nk_bool nk_group_scrolled_offset_begin(struct nk_context*, nk_uint *x_offset, nk_uint *y_offset, const char *title, nk_flags flags);
extern nk_bool nk_group_scrolled_begin(struct nk_context*, struct nk_scroll *off, const char *title, nk_flags);
extern void nk_group_scrolled_end(struct nk_context*);
extern void nk_group_get_scroll(struct nk_context*, const char *id, nk_uint *x_offset, nk_uint *y_offset);
extern void nk_group_set_scroll(struct nk_context*, const char *id, nk_uint x_offset, nk_uint y_offset);
extern nk_bool nk_tree_push_hashed(struct nk_context*, enum nk_tree_type, const char *title, enum nk_collapse_states initial_state, const char *hash, int len,int seed);
extern nk_bool nk_tree_image_push_hashed(struct nk_context*, enum nk_tree_type, struct nk_image, const char *title, enum nk_collapse_states initial_state, const char *hash, int len,int seed);
extern void nk_tree_pop(struct nk_context*);
extern nk_bool nk_tree_state_push(struct nk_context*, enum nk_tree_type, const char *title, enum nk_collapse_states *state);
extern nk_bool nk_tree_state_image_push(struct nk_context*, enum nk_tree_type, struct nk_image, const char *title, enum nk_collapse_states *state);
extern void nk_tree_state_pop(struct nk_context*);



extern nk_bool nk_tree_element_push_hashed(struct nk_context*, enum nk_tree_type, const char *title, enum nk_collapse_states initial_state, nk_bool *selected, const char *hash, int len, int seed);
extern nk_bool nk_tree_element_image_push_hashed(struct nk_context*, enum nk_tree_type, struct nk_image, const char *title, enum nk_collapse_states initial_state, nk_bool *selected, const char *hash, int len,int seed);
extern void nk_tree_element_pop(struct nk_context*);






struct nk_list_view {

    int begin, end, count;

    int total_height;
    struct nk_context *ctx;
    nk_uint *scroll_pointer;
    nk_uint scroll_value;
};
extern nk_bool nk_list_view_begin(struct nk_context*, struct nk_list_view *out, const char *id, nk_flags, int row_height, int row_count);
extern void nk_list_view_end(struct nk_list_view*);





enum nk_widget_layout_states {
    NK_WIDGET_INVALID,
    NK_WIDGET_VALID,
    NK_WIDGET_ROM,
    NK_WIDGET_DISABLED
};
enum nk_widget_states {
    NK_WIDGET_STATE_MODIFIED = (1 << (1)),
    NK_WIDGET_STATE_INACTIVE = (1 << (2)),
    NK_WIDGET_STATE_ENTERED = (1 << (3)),
    NK_WIDGET_STATE_HOVER = (1 << (4)),
    NK_WIDGET_STATE_ACTIVED = (1 << (5)),
    NK_WIDGET_STATE_LEFT = (1 << (6)),
    NK_WIDGET_STATE_HOVERED = NK_WIDGET_STATE_HOVER|NK_WIDGET_STATE_MODIFIED,
    NK_WIDGET_STATE_ACTIVE = NK_WIDGET_STATE_ACTIVED|NK_WIDGET_STATE_MODIFIED
};
extern enum nk_widget_layout_states nk_widget(struct nk_rect*, const struct nk_context*);
extern enum nk_widget_layout_states nk_widget_fitting(struct nk_rect*, const struct nk_context*, struct nk_vec2);
extern struct nk_rect nk_widget_bounds(const struct nk_context*);
extern struct nk_vec2 nk_widget_position(const struct nk_context*);
extern struct nk_vec2 nk_widget_size(const struct nk_context*);
extern float nk_widget_width(const struct nk_context*);
extern float nk_widget_height(const struct nk_context*);
extern nk_bool nk_widget_is_hovered(const struct nk_context*);
extern nk_bool nk_widget_is_mouse_clicked(const struct nk_context*, enum nk_buttons);
extern nk_bool nk_widget_has_mouse_click_down(const struct nk_context*, enum nk_buttons, nk_bool down);
extern void nk_spacing(struct nk_context*, int cols);
extern void nk_widget_disable_begin(struct nk_context* ctx);
extern void nk_widget_disable_end(struct nk_context* ctx);





enum nk_text_align {
    NK_TEXT_ALIGN_LEFT = 0x01,
    NK_TEXT_ALIGN_CENTERED = 0x02,
    NK_TEXT_ALIGN_RIGHT = 0x04,
    NK_TEXT_ALIGN_TOP = 0x08,
    NK_TEXT_ALIGN_MIDDLE = 0x10,
    NK_TEXT_ALIGN_BOTTOM = 0x20
};
enum nk_text_alignment {
    NK_TEXT_LEFT = NK_TEXT_ALIGN_MIDDLE|NK_TEXT_ALIGN_LEFT,
    NK_TEXT_CENTERED = NK_TEXT_ALIGN_MIDDLE|NK_TEXT_ALIGN_CENTERED,
    NK_TEXT_RIGHT = NK_TEXT_ALIGN_MIDDLE|NK_TEXT_ALIGN_RIGHT
};
extern void nk_text(struct nk_context*, const char*, int, nk_flags);
extern void nk_text_colored(struct nk_context*, const char*, int, nk_flags, struct nk_color);
extern void nk_text_wrap(struct nk_context*, const char*, int);
extern void nk_text_wrap_colored(struct nk_context*, const char*, int, struct nk_color);
extern void nk_label(struct nk_context*, const char*, nk_flags align);
extern void nk_label_colored(struct nk_context*, const char*, nk_flags align, struct nk_color);
extern void nk_label_wrap(struct nk_context*, const char*);
extern void nk_label_colored_wrap(struct nk_context*, const char*, struct nk_color);
extern void nk_image(struct nk_context*, struct nk_image);
extern void nk_image_color(struct nk_context*, struct nk_image, struct nk_color);
extern nk_bool nk_button_text(struct nk_context*, const char *title, int len);
extern nk_bool nk_button_label(struct nk_context*, const char *title);
extern nk_bool nk_button_color(struct nk_context*, struct nk_color);
extern nk_bool nk_button_symbol(struct nk_context*, enum nk_symbol_type);
extern nk_bool nk_button_image(struct nk_context*, struct nk_image img);
extern nk_bool nk_button_symbol_label(struct nk_context*, enum nk_symbol_type, const char*, nk_flags text_alignment);
extern nk_bool nk_button_symbol_text(struct nk_context*, enum nk_symbol_type, const char*, int, nk_flags alignment);
extern nk_bool nk_button_image_label(struct nk_context*, struct nk_image img, const char*, nk_flags text_alignment);
extern nk_bool nk_button_image_text(struct nk_context*, struct nk_image img, const char*, int, nk_flags alignment);
extern nk_bool nk_button_text_styled(struct nk_context*, const struct nk_style_button*, const char *title, int len);
extern nk_bool nk_button_label_styled(struct nk_context*, const struct nk_style_button*, const char *title);
extern nk_bool nk_button_symbol_styled(struct nk_context*, const struct nk_style_button*, enum nk_symbol_type);
extern nk_bool nk_button_image_styled(struct nk_context*, const struct nk_style_button*, struct nk_image img);
extern nk_bool nk_button_symbol_text_styled(struct nk_context*,const struct nk_style_button*, enum nk_symbol_type, const char*, int, nk_flags alignment);
extern nk_bool nk_button_symbol_label_styled(struct nk_context *ctx, const struct nk_style_button *style, enum nk_symbol_type symbol, const char *title, nk_flags align);
extern nk_bool nk_button_image_label_styled(struct nk_context*,const struct nk_style_button*, struct nk_image img, const char*, nk_flags text_alignment);
extern nk_bool nk_button_image_text_styled(struct nk_context*,const struct nk_style_button*, struct nk_image img, const char*, int, nk_flags alignment);
extern void nk_button_set_behavior(struct nk_context*, enum nk_button_behavior);
extern nk_bool nk_button_push_behavior(struct nk_context*, enum nk_button_behavior);
extern nk_bool nk_button_pop_behavior(struct nk_context*);





extern nk_bool nk_check_label(struct nk_context*, const char*, nk_bool active);
extern nk_bool nk_check_text(struct nk_context*, const char*, int, nk_bool active);
extern nk_bool nk_check_text_align(struct nk_context*, const char*, int, nk_bool active, nk_flags widget_alignment, nk_flags text_alignment);
extern unsigned nk_check_flags_label(struct nk_context*, const char*, unsigned int flags, unsigned int value);
extern unsigned nk_check_flags_text(struct nk_context*, const char*, int, unsigned int flags, unsigned int value);
extern nk_bool nk_checkbox_label(struct nk_context*, const char*, nk_bool *active);
extern nk_bool nk_checkbox_label_align(struct nk_context *ctx, const char *label, nk_bool *active, nk_flags widget_alignment, nk_flags text_alignment);
extern nk_bool nk_checkbox_text(struct nk_context*, const char*, int, nk_bool *active);
extern nk_bool nk_checkbox_text_align(struct nk_context *ctx, const char *text, int len, nk_bool *active, nk_flags widget_alignment, nk_flags text_alignment);
extern nk_bool nk_checkbox_flags_label(struct nk_context*, const char*, unsigned int *flags, unsigned int value);
extern nk_bool nk_checkbox_flags_text(struct nk_context*, const char*, int, unsigned int *flags, unsigned int value);





extern nk_bool nk_radio_label(struct nk_context*, const char*, nk_bool *active);
extern nk_bool nk_radio_label_align(struct nk_context *ctx, const char *label, nk_bool *active, nk_flags widget_alignment, nk_flags text_alignment);
extern nk_bool nk_radio_text(struct nk_context*, const char*, int, nk_bool *active);
extern nk_bool nk_radio_text_align(struct nk_context *ctx, const char *text, int len, nk_bool *active, nk_flags widget_alignment, nk_flags text_alignment);
extern nk_bool nk_option_label(struct nk_context*, const char*, nk_bool active);
extern nk_bool nk_option_label_align(struct nk_context *ctx, const char *label, nk_bool active, nk_flags widget_alignment, nk_flags text_alignment);
extern nk_bool nk_option_text(struct nk_context*, const char*, int, nk_bool active);
extern nk_bool nk_option_text_align(struct nk_context *ctx, const char *text, int len, nk_bool is_active, nk_flags widget_alignment, nk_flags text_alignment);





extern nk_bool nk_selectable_label(struct nk_context*, const char*, nk_flags align, nk_bool *value);
extern nk_bool nk_selectable_text(struct nk_context*, const char*, int, nk_flags align, nk_bool *value);
extern nk_bool nk_selectable_image_label(struct nk_context*,struct nk_image, const char*, nk_flags align, nk_bool *value);
extern nk_bool nk_selectable_image_text(struct nk_context*,struct nk_image, const char*, int, nk_flags align, nk_bool *value);
extern nk_bool nk_selectable_symbol_label(struct nk_context*,enum nk_symbol_type, const char*, nk_flags align, nk_bool *value);
extern nk_bool nk_selectable_symbol_text(struct nk_context*,enum nk_symbol_type, const char*, int, nk_flags align, nk_bool *value);

extern nk_bool nk_select_label(struct nk_context*, const char*, nk_flags align, nk_bool value);
extern nk_bool nk_select_text(struct nk_context*, const char*, int, nk_flags align, nk_bool value);
extern nk_bool nk_select_image_label(struct nk_context*, struct nk_image,const char*, nk_flags align, nk_bool value);
extern nk_bool nk_select_image_text(struct nk_context*, struct nk_image,const char*, int, nk_flags align, nk_bool value);
extern nk_bool nk_select_symbol_label(struct nk_context*,enum nk_symbol_type, const char*, nk_flags align, nk_bool value);
extern nk_bool nk_select_symbol_text(struct nk_context*,enum nk_symbol_type, const char*, int, nk_flags align, nk_bool value);






extern float nk_slide_float(struct nk_context*, float min, float val, float max, float step);
extern int nk_slide_int(struct nk_context*, int min, int val, int max, int step);
extern nk_bool nk_slider_float(struct nk_context*, float min, float *val, float max, float step);
extern nk_bool nk_slider_int(struct nk_context*, int min, int *val, int max, int step);






extern nk_bool nk_knob_float(struct nk_context*, float min, float *val, float max, float step, enum nk_heading zero_direction, float dead_zone_degrees);
extern nk_bool nk_knob_int(struct nk_context*, int min, int *val, int max, int step, enum nk_heading zero_direction, float dead_zone_degrees);






extern nk_bool nk_progress(struct nk_context*, nk_size *cur, nk_size max, nk_bool modifyable);
extern nk_size nk_prog(struct nk_context*, nk_size cur, nk_size max, nk_bool modifyable);






extern struct nk_colorf nk_color_picker(struct nk_context*, struct nk_colorf, enum nk_color_format);
extern nk_bool nk_color_pick(struct nk_context*, struct nk_colorf*, enum nk_color_format);
extern nk_bool nk_property_int(struct nk_context*, const char *name, int min, int *val, int max, int step, float inc_per_pixel);
extern nk_bool nk_property_float(struct nk_context*, const char *name, float min, float *val, float max, float step, float inc_per_pixel);
extern nk_bool nk_property_double(struct nk_context*, const char *name, double min, double *val, double max, double step, float inc_per_pixel);
extern int nk_propertyi(struct nk_context*, const char *name, int min, int val, int max, int step, float inc_per_pixel);
extern float nk_propertyf(struct nk_context*, const char *name, float min, float val, float max, float step, float inc_per_pixel);
extern double nk_propertyd(struct nk_context*, const char *name, double min, double val, double max, double step, float inc_per_pixel);






enum nk_edit_flags {
    NK_EDIT_DEFAULT = 0,
    NK_EDIT_READ_ONLY = (1 << (0)),
    NK_EDIT_AUTO_SELECT = (1 << (1)),
    NK_EDIT_SIG_ENTER = (1 << (2)),
    NK_EDIT_ALLOW_TAB = (1 << (3)),
    NK_EDIT_NO_CURSOR = (1 << (4)),
    NK_EDIT_SELECTABLE = (1 << (5)),
    NK_EDIT_CLIPBOARD = (1 << (6)),
    NK_EDIT_CTRL_ENTER_NEWLINE = (1 << (7)),
    NK_EDIT_NO_HORIZONTAL_SCROLL = (1 << (8)),
    NK_EDIT_ALWAYS_INSERT_MODE = (1 << (9)),
    NK_EDIT_MULTILINE = (1 << (10)),
    NK_EDIT_GOTO_END_ON_ACTIVATE = (1 << (11))
};
enum nk_edit_types {
    NK_EDIT_SIMPLE = NK_EDIT_ALWAYS_INSERT_MODE,
    NK_EDIT_FIELD = NK_EDIT_SIMPLE|NK_EDIT_SELECTABLE|NK_EDIT_CLIPBOARD,
    NK_EDIT_BOX = NK_EDIT_ALWAYS_INSERT_MODE| NK_EDIT_SELECTABLE| NK_EDIT_MULTILINE|NK_EDIT_ALLOW_TAB|NK_EDIT_CLIPBOARD,
    NK_EDIT_EDITOR = NK_EDIT_SELECTABLE|NK_EDIT_MULTILINE|NK_EDIT_ALLOW_TAB| NK_EDIT_CLIPBOARD
};
enum nk_edit_events {
    NK_EDIT_ACTIVE = (1 << (0)),
    NK_EDIT_INACTIVE = (1 << (1)),
    NK_EDIT_ACTIVATED = (1 << (2)),
    NK_EDIT_DEACTIVATED = (1 << (3)),
    NK_EDIT_COMMITED = (1 << (4))
};
extern nk_flags nk_edit_string(struct nk_context*, nk_flags, char *buffer, int *len, int max, nk_plugin_filter);
extern nk_flags nk_edit_string_zero_terminated(struct nk_context*, nk_flags, char *buffer, int max, nk_plugin_filter);
extern nk_flags nk_edit_buffer(struct nk_context*, nk_flags, struct nk_text_edit*, nk_plugin_filter);
extern void nk_edit_focus(struct nk_context*, nk_flags flags);
extern void nk_edit_unfocus(struct nk_context*);





extern nk_bool nk_chart_begin(struct nk_context*, enum nk_chart_type, int num, float min, float max);
extern nk_bool nk_chart_begin_colored(struct nk_context*, enum nk_chart_type, struct nk_color, struct nk_color active, int num, float min, float max);
extern void nk_chart_add_slot(struct nk_context *ctx, const enum nk_chart_type, int count, float min_value, float max_value);
extern void nk_chart_add_slot_colored(struct nk_context *ctx, const enum nk_chart_type, struct nk_color, struct nk_color active, int count, float min_value, float max_value);
extern nk_flags nk_chart_push(struct nk_context*, float);
extern nk_flags nk_chart_push_slot(struct nk_context*, float, int);
extern void nk_chart_end(struct nk_context*);
extern void nk_plot(struct nk_context*, enum nk_chart_type, const float *values, int count, int offset);
extern void nk_plot_function(struct nk_context*, enum nk_chart_type, void *userdata, float(*value_getter)(void* user, int index), int count, int offset);





extern nk_bool nk_popup_begin(struct nk_context*, enum nk_popup_type, const char*, nk_flags, struct nk_rect bounds);
extern void nk_popup_close(struct nk_context*);
extern void nk_popup_end(struct nk_context*);
extern void nk_popup_get_scroll(const struct nk_context*, nk_uint *offset_x, nk_uint *offset_y);
extern void nk_popup_set_scroll(struct nk_context*, nk_uint offset_x, nk_uint offset_y);





extern int nk_combo(struct nk_context*, const char *const *items, int count, int selected, int item_height, struct nk_vec2 size);
extern int nk_combo_separator(struct nk_context*, const char *items_separated_by_separator, int separator, int selected, int count, int item_height, struct nk_vec2 size);
extern int nk_combo_string(struct nk_context*, const char *items_separated_by_zeros, int selected, int count, int item_height, struct nk_vec2 size);
extern int nk_combo_callback(struct nk_context*, void(*item_getter)(void*, int, const char**), void *userdata, int selected, int count, int item_height, struct nk_vec2 size);
extern nk_bool nk_combobox(struct nk_context*, const char *const *items, int count, int *selected, int item_height, struct nk_vec2 size);
extern nk_bool nk_combobox_string(struct nk_context*, const char *items_separated_by_zeros, int *selected, int count, int item_height, struct nk_vec2 size);
extern nk_bool nk_combobox_separator(struct nk_context*, const char *items_separated_by_separator, int separator, int *selected, int count, int item_height, struct nk_vec2 size);
extern nk_bool nk_combobox_callback(struct nk_context*, void(*item_getter)(void*, int, const char**), void*, int *selected, int count, int item_height, struct nk_vec2 size);





extern nk_bool nk_combo_begin_text(struct nk_context*, const char *selected, int, struct nk_vec2 size);
extern nk_bool nk_combo_begin_label(struct nk_context*, const char *selected, struct nk_vec2 size);
extern nk_bool nk_combo_begin_color(struct nk_context*, struct nk_color color, struct nk_vec2 size);
extern nk_bool nk_combo_begin_symbol(struct nk_context*, enum nk_symbol_type, struct nk_vec2 size);
extern nk_bool nk_combo_begin_symbol_label(struct nk_context*, const char *selected, enum nk_symbol_type, struct nk_vec2 size);
extern nk_bool nk_combo_begin_symbol_text(struct nk_context*, const char *selected, int, enum nk_symbol_type, struct nk_vec2 size);
extern nk_bool nk_combo_begin_image(struct nk_context*, struct nk_image img, struct nk_vec2 size);
extern nk_bool nk_combo_begin_image_label(struct nk_context*, const char *selected, struct nk_image, struct nk_vec2 size);
extern nk_bool nk_combo_begin_image_text(struct nk_context*, const char *selected, int, struct nk_image, struct nk_vec2 size);
extern nk_bool nk_combo_item_label(struct nk_context*, const char*, nk_flags alignment);
extern nk_bool nk_combo_item_text(struct nk_context*, const char*,int, nk_flags alignment);
extern nk_bool nk_combo_item_image_label(struct nk_context*, struct nk_image, const char*, nk_flags alignment);
extern nk_bool nk_combo_item_image_text(struct nk_context*, struct nk_image, const char*, int,nk_flags alignment);
extern nk_bool nk_combo_item_symbol_label(struct nk_context*, enum nk_symbol_type, const char*, nk_flags alignment);
extern nk_bool nk_combo_item_symbol_text(struct nk_context*, enum nk_symbol_type, const char*, int, nk_flags alignment);
extern void nk_combo_close(struct nk_context*);
extern void nk_combo_end(struct nk_context*);





extern nk_bool nk_contextual_begin(struct nk_context*, nk_flags, struct nk_vec2, struct nk_rect trigger_bounds);
extern nk_bool nk_contextual_item_text(struct nk_context*, const char*, int,nk_flags align);
extern nk_bool nk_contextual_item_label(struct nk_context*, const char*, nk_flags align);
extern nk_bool nk_contextual_item_image_label(struct nk_context*, struct nk_image, const char*, nk_flags alignment);
extern nk_bool nk_contextual_item_image_text(struct nk_context*, struct nk_image, const char*, int len, nk_flags alignment);
extern nk_bool nk_contextual_item_symbol_label(struct nk_context*, enum nk_symbol_type, const char*, nk_flags alignment);
extern nk_bool nk_contextual_item_symbol_text(struct nk_context*, enum nk_symbol_type, const char*, int, nk_flags alignment);
extern void nk_contextual_close(struct nk_context*);
extern void nk_contextual_end(struct nk_context*);





extern void nk_tooltip(struct nk_context*, const char*);
extern void nk_tooltip_offset(struct nk_context *ctx, const char *text, enum nk_tooltip_pos position, struct nk_vec2 offset);






extern nk_bool nk_tooltip_begin(struct nk_context*, float width);
extern nk_bool nk_tooltip_begin_offset(struct nk_context*, float, enum nk_tooltip_pos, struct nk_vec2);
extern void nk_tooltip_end(struct nk_context*);





extern void nk_menubar_begin(struct nk_context*);
extern void nk_menubar_end(struct nk_context*);
extern nk_bool nk_menu_begin_text(struct nk_context*, const char* title, int title_len, nk_flags align, struct nk_vec2 size);
extern nk_bool nk_menu_begin_label(struct nk_context*, const char*, nk_flags align, struct nk_vec2 size);
extern nk_bool nk_menu_begin_image(struct nk_context*, const char*, struct nk_image, struct nk_vec2 size);
extern nk_bool nk_menu_begin_image_text(struct nk_context*, const char*, int,nk_flags align,struct nk_image, struct nk_vec2 size);
extern nk_bool nk_menu_begin_image_label(struct nk_context*, const char*, nk_flags align,struct nk_image, struct nk_vec2 size);
extern nk_bool nk_menu_begin_symbol(struct nk_context*, const char*, enum nk_symbol_type, struct nk_vec2 size);
extern nk_bool nk_menu_begin_symbol_text(struct nk_context*, const char*, int,nk_flags align,enum nk_symbol_type, struct nk_vec2 size);
extern nk_bool nk_menu_begin_symbol_label(struct nk_context*, const char*, nk_flags align,enum nk_symbol_type, struct nk_vec2 size);
extern nk_bool nk_menu_item_text(struct nk_context*, const char*, int,nk_flags align);
extern nk_bool nk_menu_item_label(struct nk_context*, const char*, nk_flags alignment);
extern nk_bool nk_menu_item_image_label(struct nk_context*, struct nk_image, const char*, nk_flags alignment);
extern nk_bool nk_menu_item_image_text(struct nk_context*, struct nk_image, const char*, int len, nk_flags alignment);
extern nk_bool nk_menu_item_symbol_text(struct nk_context*, enum nk_symbol_type, const char*, int, nk_flags alignment);
extern nk_bool nk_menu_item_symbol_label(struct nk_context*, enum nk_symbol_type, const char*, nk_flags alignment);
extern void nk_menu_close(struct nk_context*);
extern void nk_menu_end(struct nk_context*);
enum nk_style_colors {
    NK_COLOR_TEXT,
    NK_COLOR_WINDOW,
    NK_COLOR_HEADER,
    NK_COLOR_BORDER,
    NK_COLOR_BUTTON,
    NK_COLOR_BUTTON_HOVER,
    NK_COLOR_BUTTON_ACTIVE,
    NK_COLOR_TOGGLE,
    NK_COLOR_TOGGLE_HOVER,
    NK_COLOR_TOGGLE_CURSOR,
    NK_COLOR_SELECT,
    NK_COLOR_SELECT_ACTIVE,
    NK_COLOR_SLIDER,
    NK_COLOR_SLIDER_CURSOR,
    NK_COLOR_SLIDER_CURSOR_HOVER,
    NK_COLOR_SLIDER_CURSOR_ACTIVE,
    NK_COLOR_PROPERTY,
    NK_COLOR_EDIT,
    NK_COLOR_EDIT_CURSOR,
    NK_COLOR_COMBO,
    NK_COLOR_CHART,
    NK_COLOR_CHART_COLOR,
    NK_COLOR_CHART_COLOR_HIGHLIGHT,
    NK_COLOR_SCROLLBAR,
    NK_COLOR_SCROLLBAR_CURSOR,
    NK_COLOR_SCROLLBAR_CURSOR_HOVER,
    NK_COLOR_SCROLLBAR_CURSOR_ACTIVE,
    NK_COLOR_TAB_HEADER,
    NK_COLOR_KNOB,
    NK_COLOR_KNOB_CURSOR,
    NK_COLOR_KNOB_CURSOR_HOVER,
    NK_COLOR_KNOB_CURSOR_ACTIVE,
    NK_COLOR_COUNT
};
enum nk_style_cursor {
    NK_CURSOR_ARROW,
    NK_CURSOR_TEXT,
    NK_CURSOR_MOVE,
    NK_CURSOR_RESIZE_VERTICAL,
    NK_CURSOR_RESIZE_HORIZONTAL,
    NK_CURSOR_RESIZE_TOP_LEFT_DOWN_RIGHT,
    NK_CURSOR_RESIZE_TOP_RIGHT_DOWN_LEFT,
    NK_CURSOR_COUNT
};
extern void nk_style_default(struct nk_context*);
extern void nk_style_from_table(struct nk_context*, const struct nk_color*);
extern void nk_style_load_cursor(struct nk_context*, enum nk_style_cursor, const struct nk_cursor*);
extern void nk_style_load_all_cursors(struct nk_context*, const struct nk_cursor*);
extern const char* nk_style_get_color_by_name(enum nk_style_colors);
extern void nk_style_set_font(struct nk_context*, const struct nk_user_font*);
extern nk_bool nk_style_set_cursor(struct nk_context*, enum nk_style_cursor);
extern void nk_style_show_cursor(struct nk_context*);
extern void nk_style_hide_cursor(struct nk_context*);

extern nk_bool nk_style_push_font(struct nk_context*, const struct nk_user_font*);
extern nk_bool nk_style_push_float(struct nk_context*, float*, float);
extern nk_bool nk_style_push_vec2(struct nk_context*, struct nk_vec2*, struct nk_vec2);
extern nk_bool nk_style_push_style_item(struct nk_context*, struct nk_style_item*, struct nk_style_item);
extern nk_bool nk_style_push_flags(struct nk_context*, nk_flags*, nk_flags);
extern nk_bool nk_style_push_color(struct nk_context*, struct nk_color*, struct nk_color);

extern nk_bool nk_style_pop_font(struct nk_context*);
extern nk_bool nk_style_pop_float(struct nk_context*);
extern nk_bool nk_style_pop_vec2(struct nk_context*);
extern nk_bool nk_style_pop_style_item(struct nk_context*);
extern nk_bool nk_style_pop_flags(struct nk_context*);
extern nk_bool nk_style_pop_color(struct nk_context*);





extern struct nk_color nk_rgb(int r, int g, int b);
extern struct nk_color nk_rgb_iv(const int *rgb);
extern struct nk_color nk_rgb_bv(const nk_byte* rgb);
extern struct nk_color nk_rgb_f(float r, float g, float b);
extern struct nk_color nk_rgb_fv(const float *rgb);
extern struct nk_color nk_rgb_cf(struct nk_colorf c);
extern struct nk_color nk_rgb_hex(const char *rgb);
extern struct nk_color nk_rgb_factor(struct nk_color col, float factor);

extern struct nk_color nk_rgba(int r, int g, int b, int a);
extern struct nk_color nk_rgba_u32(nk_uint);
extern struct nk_color nk_rgba_iv(const int *rgba);
extern struct nk_color nk_rgba_bv(const nk_byte *rgba);
extern struct nk_color nk_rgba_f(float r, float g, float b, float a);
extern struct nk_color nk_rgba_fv(const float *rgba);
extern struct nk_color nk_rgba_cf(struct nk_colorf c);
extern struct nk_color nk_rgba_hex(const char *rgb);

extern struct nk_colorf nk_hsva_colorf(float h, float s, float v, float a);
extern struct nk_colorf nk_hsva_colorfv(const float *c);
extern void nk_colorf_hsva_f(float *out_h, float *out_s, float *out_v, float *out_a, struct nk_colorf in);
extern void nk_colorf_hsva_fv(float *hsva, struct nk_colorf in);

extern struct nk_color nk_hsv(int h, int s, int v);
extern struct nk_color nk_hsv_iv(const int *hsv);
extern struct nk_color nk_hsv_bv(const nk_byte *hsv);
extern struct nk_color nk_hsv_f(float h, float s, float v);
extern struct nk_color nk_hsv_fv(const float *hsv);

extern struct nk_color nk_hsva(int h, int s, int v, int a);
extern struct nk_color nk_hsva_iv(const int *hsva);
extern struct nk_color nk_hsva_bv(const nk_byte *hsva);
extern struct nk_color nk_hsva_f(float h, float s, float v, float a);
extern struct nk_color nk_hsva_fv(const float *hsva);


extern void nk_color_f(float *r, float *g, float *b, float *a, struct nk_color);
extern void nk_color_fv(float *rgba_out, struct nk_color);
extern struct nk_colorf nk_color_cf(struct nk_color);
extern void nk_color_d(double *r, double *g, double *b, double *a, struct nk_color);
extern void nk_color_dv(double *rgba_out, struct nk_color);

extern nk_uint nk_color_u32(struct nk_color);
extern void nk_color_hex_rgba(char *output, struct nk_color);
extern void nk_color_hex_rgb(char *output, struct nk_color);

extern void nk_color_hsv_i(int *out_h, int *out_s, int *out_v, struct nk_color);
extern void nk_color_hsv_b(nk_byte *out_h, nk_byte *out_s, nk_byte *out_v, struct nk_color);
extern void nk_color_hsv_iv(int *hsv_out, struct nk_color);
extern void nk_color_hsv_bv(nk_byte *hsv_out, struct nk_color);
extern void nk_color_hsv_f(float *out_h, float *out_s, float *out_v, struct nk_color);
extern void nk_color_hsv_fv(float *hsv_out, struct nk_color);

extern void nk_color_hsva_i(int *h, int *s, int *v, int *a, struct nk_color);
extern void nk_color_hsva_b(nk_byte *h, nk_byte *s, nk_byte *v, nk_byte *a, struct nk_color);
extern void nk_color_hsva_iv(int *hsva_out, struct nk_color);
extern void nk_color_hsva_bv(nk_byte *hsva_out, struct nk_color);
extern void nk_color_hsva_f(float *out_h, float *out_s, float *out_v, float *out_a, struct nk_color);
extern void nk_color_hsva_fv(float *hsva_out, struct nk_color);





extern nk_handle nk_handle_ptr(void*);
extern nk_handle nk_handle_id(int);
extern struct nk_image nk_image_handle(nk_handle);
extern struct nk_image nk_image_ptr(void*);
extern struct nk_image nk_image_id(int);
extern nk_bool nk_image_is_subimage(const struct nk_image* img);
extern struct nk_image nk_subimage_ptr(void*, nk_ushort w, nk_ushort h, struct nk_rect sub_region);
extern struct nk_image nk_subimage_id(int, nk_ushort w, nk_ushort h, struct nk_rect sub_region);
extern struct nk_image nk_subimage_handle(nk_handle, nk_ushort w, nk_ushort h, struct nk_rect sub_region);





extern struct nk_nine_slice nk_nine_slice_handle(nk_handle, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b);
extern struct nk_nine_slice nk_nine_slice_ptr(void*, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b);
extern struct nk_nine_slice nk_nine_slice_id(int, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b);
extern int nk_nine_slice_is_sub9slice(const struct nk_nine_slice* img);
extern struct nk_nine_slice nk_sub9slice_ptr(void*, nk_ushort w, nk_ushort h, struct nk_rect sub_region, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b);
extern struct nk_nine_slice nk_sub9slice_id(int, nk_ushort w, nk_ushort h, struct nk_rect sub_region, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b);
extern struct nk_nine_slice nk_sub9slice_handle(nk_handle, nk_ushort w, nk_ushort h, struct nk_rect sub_region, nk_ushort l, nk_ushort t, nk_ushort r, nk_ushort b);





extern nk_hash nk_murmur_hash(const void *key, int len, nk_hash seed);
extern void nk_triangle_from_direction(struct nk_vec2 *result, struct nk_rect r, float pad_x, float pad_y, enum nk_heading);

extern struct nk_vec2 nk_vec2(float x, float y);
extern struct nk_vec2 nk_vec2i(int x, int y);
extern struct nk_vec2 nk_vec2v(const float *xy);
extern struct nk_vec2 nk_vec2iv(const int *xy);

extern struct nk_rect nk_get_null_rect(void);
extern struct nk_rect nk_rect(float x, float y, float w, float h);
extern struct nk_rect nk_recti(int x, int y, int w, int h);
extern struct nk_rect nk_recta(struct nk_vec2 pos, struct nk_vec2 size);
extern struct nk_rect nk_rectv(const float *xywh);
extern struct nk_rect nk_rectiv(const int *xywh);
extern struct nk_vec2 nk_rect_pos(struct nk_rect);
extern struct nk_vec2 nk_rect_size(struct nk_rect);





extern int nk_strlen(const char *str);
extern int nk_stricmp(const char *s1, const char *s2);
extern int nk_stricmpn(const char *s1, const char *s2, int n);
extern int nk_strtoi(const char *str, char **endptr);
extern float nk_strtof(const char *str, char **endptr);



extern double nk_strtod(const char *str, char **endptr);

extern int nk_strfilter(const char *text, const char *regexp);
extern int nk_strmatch_fuzzy_string(char const *str, char const *pattern, int *out_score);
extern int nk_strmatch_fuzzy_text(const char *txt, int txt_len, const char *pattern, int *out_score);





extern int nk_utf_decode(const char*, nk_rune*, int);
extern int nk_utf_encode(nk_rune, char*, int);
extern int nk_utf_len(const char*, int byte_len);
extern const char* nk_utf_at(const char *buffer, int length, int index, nk_rune *unicode, int *len);
struct nk_user_font_glyph;
typedef float(*nk_text_width_f)(nk_handle, float h, const char*, int len);
typedef void(*nk_query_font_glyph_f)(nk_handle handle, float font_height,
                                    struct nk_user_font_glyph *glyph,
                                    nk_rune codepoint, nk_rune next_codepoint);


struct nk_user_font_glyph {
    struct nk_vec2 uv[2];
    struct nk_vec2 offset;
    float width, height;
    float xadvance;
};


struct nk_user_font {
    nk_handle userdata;
    float height;
    nk_text_width_f width;

    nk_query_font_glyph_f query;
    nk_handle texture;

};


enum nk_font_coord_type {
    NK_COORD_UV,
    NK_COORD_PIXEL
};

struct nk_font;
struct nk_baked_font {
    float height;
    float ascent;
    float descent;
    nk_rune glyph_offset;
    nk_rune glyph_count;
    const nk_rune *ranges;
};

struct nk_font_config {
    struct nk_font_config *next;
    void *ttf_blob;
    nk_size ttf_size;

    unsigned char ttf_data_owned_by_atlas;
    unsigned char merge_mode;
    unsigned char pixel_snap;
    unsigned char oversample_v, oversample_h;
    unsigned char padding[3];

    float size;
    enum nk_font_coord_type coord_type;
    struct nk_vec2 spacing;
    const nk_rune *range;
    struct nk_baked_font *font;
    nk_rune fallback_glyph;
    struct nk_font_config *n;
    struct nk_font_config *p;
};

struct nk_font_glyph {
    nk_rune codepoint;
    float xadvance;
    float x0, y0, x1, y1, w, h;
    float u0, v0, u1, v1;
};

struct nk_font {
    struct nk_font *next;
    struct nk_user_font handle;
    struct nk_baked_font info;
    float scale;
    struct nk_font_glyph *glyphs;
    const struct nk_font_glyph *fallback;
    nk_rune fallback_codepoint;
    nk_handle texture;
    struct nk_font_config *config;
};

enum nk_font_atlas_format {
    NK_FONT_ATLAS_ALPHA8,
    NK_FONT_ATLAS_RGBA32
};

struct nk_font_atlas {
    void *pixel;
    int tex_width;
    int tex_height;

    struct nk_allocator permanent;
    struct nk_allocator temporary;

    struct nk_recti custom;
    struct nk_cursor cursors[NK_CURSOR_COUNT];

    int glyph_count;
    struct nk_font_glyph *glyphs;
    struct nk_font *default_font;
    struct nk_font *fonts;
    struct nk_font_config *config;
    int font_num;
};


extern const nk_rune *nk_font_default_glyph_ranges(void);
extern const nk_rune *nk_font_chinese_glyph_ranges(void);
extern const nk_rune *nk_font_cyrillic_glyph_ranges(void);
extern const nk_rune *nk_font_korean_glyph_ranges(void);


extern void nk_font_atlas_init_default(struct nk_font_atlas*);

extern void nk_font_atlas_init(struct nk_font_atlas*, const struct nk_allocator*);
extern void nk_font_atlas_init_custom(struct nk_font_atlas*, const struct nk_allocator *persistent, const struct nk_allocator *transient);
extern void nk_font_atlas_begin(struct nk_font_atlas*);
extern struct nk_font_config nk_font_config(float pixel_height);
extern struct nk_font *nk_font_atlas_add(struct nk_font_atlas*, const struct nk_font_config*);

extern struct nk_font* nk_font_atlas_add_default(struct nk_font_atlas*, float height, const struct nk_font_config*);

extern struct nk_font* nk_font_atlas_add_from_memory(struct nk_font_atlas *atlas, void *memory, nk_size size, float height, const struct nk_font_config *config);

extern struct nk_font* nk_font_atlas_add_from_file(struct nk_font_atlas *atlas, const char *file_path, float height, const struct nk_font_config*);

extern struct nk_font *nk_font_atlas_add_compressed(struct nk_font_atlas*, void *memory, nk_size size, float height, const struct nk_font_config*);
extern struct nk_font* nk_font_atlas_add_compressed_base85(struct nk_font_atlas*, const char *data, float height, const struct nk_font_config *config);
extern const void* nk_font_atlas_bake(struct nk_font_atlas*, int *width, int *height, enum nk_font_atlas_format);
extern void nk_font_atlas_end(struct nk_font_atlas*, nk_handle tex, struct nk_draw_null_texture*);
extern const struct nk_font_glyph* nk_font_find_glyph(const struct nk_font*, nk_rune unicode);
extern void nk_font_atlas_cleanup(struct nk_font_atlas *atlas);
extern void nk_font_atlas_clear(struct nk_font_atlas*);
struct nk_memory_status {
    void *memory;
    unsigned int type;
    nk_size size;
    nk_size allocated;
    nk_size needed;
    nk_size calls;
};

enum nk_allocation_type {
    NK_BUFFER_FIXED,
    NK_BUFFER_DYNAMIC
};

enum nk_buffer_allocation_type {
    NK_BUFFER_FRONT,
    NK_BUFFER_BACK,
    NK_BUFFER_MAX
};

struct nk_buffer_marker {
    nk_bool active;
    nk_size offset;
};

struct nk_memory {void *ptr;nk_size size;};
struct nk_buffer {
    struct nk_buffer_marker marker[NK_BUFFER_MAX];
    struct nk_allocator pool;
    enum nk_allocation_type type;
    struct nk_memory memory;
    float grow_factor;
    nk_size allocated;
    nk_size needed;
    nk_size calls;
    nk_size size;
};


extern void nk_buffer_init_default(struct nk_buffer*);

extern void nk_buffer_init(struct nk_buffer*, const struct nk_allocator*, nk_size size);
extern void nk_buffer_init_fixed(struct nk_buffer*, void *memory, nk_size size);
extern void nk_buffer_info(struct nk_memory_status*, const struct nk_buffer*);
extern void nk_buffer_push(struct nk_buffer*, enum nk_buffer_allocation_type type, const void *memory, nk_size size, nk_size align);
extern void nk_buffer_mark(struct nk_buffer*, enum nk_buffer_allocation_type type);
extern void nk_buffer_reset(struct nk_buffer*, enum nk_buffer_allocation_type type);
extern void nk_buffer_clear(struct nk_buffer*);
extern void nk_buffer_free(struct nk_buffer*);
extern void *nk_buffer_memory(struct nk_buffer*);
extern const void *nk_buffer_memory_const(const struct nk_buffer*);
extern nk_size nk_buffer_total(const struct nk_buffer*);
struct nk_str {
    struct nk_buffer buffer;
    int len;
};


extern void nk_str_init_default(struct nk_str*);

extern void nk_str_init(struct nk_str*, const struct nk_allocator*, nk_size size);
extern void nk_str_init_fixed(struct nk_str*, void *memory, nk_size size);
extern void nk_str_clear(struct nk_str*);
extern void nk_str_free(struct nk_str*);

extern int nk_str_append_text_char(struct nk_str*, const char*, int);
extern int nk_str_append_str_char(struct nk_str*, const char*);
extern int nk_str_append_text_utf8(struct nk_str*, const char*, int);
extern int nk_str_append_str_utf8(struct nk_str*, const char*);
extern int nk_str_append_text_runes(struct nk_str*, const nk_rune*, int);
extern int nk_str_append_str_runes(struct nk_str*, const nk_rune*);

extern int nk_str_insert_at_char(struct nk_str*, int pos, const char*, int);
extern int nk_str_insert_at_rune(struct nk_str*, int pos, const char*, int);

extern int nk_str_insert_text_char(struct nk_str*, int pos, const char*, int);
extern int nk_str_insert_str_char(struct nk_str*, int pos, const char*);
extern int nk_str_insert_text_utf8(struct nk_str*, int pos, const char*, int);
extern int nk_str_insert_str_utf8(struct nk_str*, int pos, const char*);
extern int nk_str_insert_text_runes(struct nk_str*, int pos, const nk_rune*, int);
extern int nk_str_insert_str_runes(struct nk_str*, int pos, const nk_rune*);

extern void nk_str_remove_chars(struct nk_str*, int len);
extern void nk_str_remove_runes(struct nk_str *str, int len);
extern void nk_str_delete_chars(struct nk_str*, int pos, int len);
extern void nk_str_delete_runes(struct nk_str*, int pos, int len);

extern char *nk_str_at_char(struct nk_str*, int pos);
extern char *nk_str_at_rune(struct nk_str*, int pos, nk_rune *unicode, int *len);
extern nk_rune nk_str_rune_at(const struct nk_str*, int pos);
extern const char *nk_str_at_char_const(const struct nk_str*, int pos);
extern const char *nk_str_at_const(const struct nk_str*, int pos, nk_rune *unicode, int *len);

extern char *nk_str_get(struct nk_str*);
extern const char *nk_str_get_const(const struct nk_str*);
extern int nk_str_len(const struct nk_str*);
extern int nk_str_len_char(const struct nk_str*);
struct nk_text_edit;
struct nk_clipboard {
    nk_handle userdata;
    nk_plugin_paste paste;
    nk_plugin_copy copy;
};

struct nk_text_undo_record {
   int where;
   short insert_length;
   short delete_length;
   short char_storage;
};

struct nk_text_undo_state {
   struct nk_text_undo_record undo_rec[99];
   nk_rune undo_char[999];
   short undo_point;
   short redo_point;
   short undo_char_point;
   short redo_char_point;
};

enum nk_text_edit_type {
    NK_TEXT_EDIT_SINGLE_LINE,
    NK_TEXT_EDIT_MULTI_LINE
};

enum nk_text_edit_mode {
    NK_TEXT_EDIT_MODE_VIEW,
    NK_TEXT_EDIT_MODE_INSERT,
    NK_TEXT_EDIT_MODE_REPLACE
};

struct nk_text_edit {
    struct nk_clipboard clip;
    struct nk_str string;
    nk_plugin_filter filter;
    struct nk_vec2 scrollbar;

    int cursor;
    int select_start;
    int select_end;
    unsigned char mode;
    unsigned char cursor_at_end_of_line;
    unsigned char initialized;
    unsigned char has_preferred_x;
    unsigned char single_line;
    unsigned char active;
    unsigned char padding1;
    float preferred_x;
    struct nk_text_undo_state undo;
};


extern nk_bool nk_filter_default(const struct nk_text_edit*, nk_rune unicode);
extern nk_bool nk_filter_ascii(const struct nk_text_edit*, nk_rune unicode);
extern nk_bool nk_filter_float(const struct nk_text_edit*, nk_rune unicode);
extern nk_bool nk_filter_decimal(const struct nk_text_edit*, nk_rune unicode);
extern nk_bool nk_filter_hex(const struct nk_text_edit*, nk_rune unicode);
extern nk_bool nk_filter_oct(const struct nk_text_edit*, nk_rune unicode);
extern nk_bool nk_filter_binary(const struct nk_text_edit*, nk_rune unicode);



extern void nk_textedit_init_default(struct nk_text_edit*);

extern void nk_textedit_init(struct nk_text_edit*, const struct nk_allocator*, nk_size size);
extern void nk_textedit_init_fixed(struct nk_text_edit*, void *memory, nk_size size);
extern void nk_textedit_free(struct nk_text_edit*);
extern void nk_textedit_text(struct nk_text_edit*, const char*, int total_len);
extern void nk_textedit_delete(struct nk_text_edit*, int where, int len);
extern void nk_textedit_delete_selection(struct nk_text_edit*);
extern void nk_textedit_select_all(struct nk_text_edit*);
extern nk_bool nk_textedit_cut(struct nk_text_edit*);
extern nk_bool nk_textedit_paste(struct nk_text_edit*, char const*, int len);
extern void nk_textedit_undo(struct nk_text_edit*);
extern void nk_textedit_redo(struct nk_text_edit*);
enum nk_command_type {
    NK_COMMAND_NOP,
    NK_COMMAND_SCISSOR,
    NK_COMMAND_LINE,
    NK_COMMAND_CURVE,
    NK_COMMAND_RECT,
    NK_COMMAND_RECT_FILLED,
    NK_COMMAND_RECT_MULTI_COLOR,
    NK_COMMAND_CIRCLE,
    NK_COMMAND_CIRCLE_FILLED,
    NK_COMMAND_ARC,
    NK_COMMAND_ARC_FILLED,
    NK_COMMAND_TRIANGLE,
    NK_COMMAND_TRIANGLE_FILLED,
    NK_COMMAND_POLYGON,
    NK_COMMAND_POLYGON_FILLED,
    NK_COMMAND_POLYLINE,
    NK_COMMAND_TEXT,
    NK_COMMAND_IMAGE,
    NK_COMMAND_CUSTOM
};


struct nk_command {
    enum nk_command_type type;
    nk_size next;



};

struct nk_command_scissor {
    struct nk_command header;
    short x, y;
    unsigned short w, h;
};

struct nk_command_line {
    struct nk_command header;
    unsigned short line_thickness;
    struct nk_vec2i begin;
    struct nk_vec2i end;
    struct nk_color color;
};

struct nk_command_curve {
    struct nk_command header;
    unsigned short line_thickness;
    struct nk_vec2i begin;
    struct nk_vec2i end;
    struct nk_vec2i ctrl[2];
    struct nk_color color;
};

struct nk_command_rect {
    struct nk_command header;
    unsigned short rounding;
    unsigned short line_thickness;
    short x, y;
    unsigned short w, h;
    struct nk_color color;
};

struct nk_command_rect_filled {
    struct nk_command header;
    unsigned short rounding;
    short x, y;
    unsigned short w, h;
    struct nk_color color;
};

struct nk_command_rect_multi_color {
    struct nk_command header;
    short x, y;
    unsigned short w, h;
    struct nk_color left;
    struct nk_color top;
    struct nk_color bottom;
    struct nk_color right;
};

struct nk_command_triangle {
    struct nk_command header;
    unsigned short line_thickness;
    struct nk_vec2i a;
    struct nk_vec2i b;
    struct nk_vec2i c;
    struct nk_color color;
};

struct nk_command_triangle_filled {
    struct nk_command header;
    struct nk_vec2i a;
    struct nk_vec2i b;
    struct nk_vec2i c;
    struct nk_color color;
};

struct nk_command_circle {
    struct nk_command header;
    short x, y;
    unsigned short line_thickness;
    unsigned short w, h;
    struct nk_color color;
};

struct nk_command_circle_filled {
    struct nk_command header;
    short x, y;
    unsigned short w, h;
    struct nk_color color;
};

struct nk_command_arc {
    struct nk_command header;
    short cx, cy;
    unsigned short r;
    unsigned short line_thickness;
    float a[2];
    struct nk_color color;
};

struct nk_command_arc_filled {
    struct nk_command header;
    short cx, cy;
    unsigned short r;
    float a[2];
    struct nk_color color;
};

struct nk_command_polygon {
    struct nk_command header;
    struct nk_color color;
    unsigned short line_thickness;
    unsigned short point_count;
    struct nk_vec2i points[1];
};

struct nk_command_polygon_filled {
    struct nk_command header;
    struct nk_color color;
    unsigned short point_count;
    struct nk_vec2i points[1];
};

struct nk_command_polyline {
    struct nk_command header;
    struct nk_color color;
    unsigned short line_thickness;
    unsigned short point_count;
    struct nk_vec2i points[1];
};

struct nk_command_image {
    struct nk_command header;
    short x, y;
    unsigned short w, h;
    struct nk_image img;
    struct nk_color col;
};

typedef void (*nk_command_custom_callback)(void *canvas, short x,short y,
    unsigned short w, unsigned short h, nk_handle callback_data);
struct nk_command_custom {
    struct nk_command header;
    short x, y;
    unsigned short w, h;
    nk_handle callback_data;
    nk_command_custom_callback callback;
};

struct nk_command_text {
    struct nk_command header;
    const struct nk_user_font *font;
    struct nk_color background;
    struct nk_color foreground;
    short x, y;
    unsigned short w, h;
    float height;
    int length;
    char string[2];
};

enum nk_command_clipping {
    NK_CLIPPING_OFF = nk_false,
    NK_CLIPPING_ON = nk_true
};

struct nk_command_buffer {
    struct nk_buffer *base;
    struct nk_rect clip;
    int use_clipping;
    nk_handle userdata;
    nk_size begin, end, last;
};


extern void nk_stroke_line(struct nk_command_buffer *b, float x0, float y0, float x1, float y1, float line_thickness, struct nk_color);
extern void nk_stroke_curve(struct nk_command_buffer*, float, float, float, float, float, float, float, float, float line_thickness, struct nk_color);
extern void nk_stroke_rect(struct nk_command_buffer*, struct nk_rect, float rounding, float line_thickness, struct nk_color);
extern void nk_stroke_circle(struct nk_command_buffer*, struct nk_rect, float line_thickness, struct nk_color);
extern void nk_stroke_arc(struct nk_command_buffer*, float cx, float cy, float radius, float a_min, float a_max, float line_thickness, struct nk_color);
extern void nk_stroke_triangle(struct nk_command_buffer*, float, float, float, float, float, float, float line_thichness, struct nk_color);
extern void nk_stroke_polyline(struct nk_command_buffer*, const float *points, int point_count, float line_thickness, struct nk_color col);
extern void nk_stroke_polygon(struct nk_command_buffer*, const float *points, int point_count, float line_thickness, struct nk_color);


extern void nk_fill_rect(struct nk_command_buffer*, struct nk_rect, float rounding, struct nk_color);
extern void nk_fill_rect_multi_color(struct nk_command_buffer*, struct nk_rect, struct nk_color left, struct nk_color top, struct nk_color right, struct nk_color bottom);
extern void nk_fill_circle(struct nk_command_buffer*, struct nk_rect, struct nk_color);
extern void nk_fill_arc(struct nk_command_buffer*, float cx, float cy, float radius, float a_min, float a_max, struct nk_color);
extern void nk_fill_triangle(struct nk_command_buffer*, float x0, float y0, float x1, float y1, float x2, float y2, struct nk_color);
extern void nk_fill_polygon(struct nk_command_buffer*, const float *points, int point_count, struct nk_color);


extern void nk_draw_image(struct nk_command_buffer*, struct nk_rect, const struct nk_image*, struct nk_color);
extern void nk_draw_nine_slice(struct nk_command_buffer*, struct nk_rect, const struct nk_nine_slice*, struct nk_color);
extern void nk_draw_text(struct nk_command_buffer*, struct nk_rect, const char *text, int len, const struct nk_user_font*, struct nk_color, struct nk_color);
extern void nk_push_scissor(struct nk_command_buffer*, struct nk_rect);
extern void nk_push_custom(struct nk_command_buffer*, struct nk_rect, nk_command_custom_callback, nk_handle usr);






struct nk_mouse_button {
    nk_bool down;
    unsigned int clicked;
    struct nk_vec2 clicked_pos;
};
struct nk_mouse {
    struct nk_mouse_button buttons[NK_BUTTON_MAX];
    struct nk_vec2 pos;



    struct nk_vec2 prev;
    struct nk_vec2 delta;
    struct nk_vec2 scroll_delta;
    unsigned char grab;
    unsigned char grabbed;
    unsigned char ungrab;
};

struct nk_key {
    nk_bool down;
    unsigned int clicked;
};
struct nk_keyboard {
    struct nk_key keys[NK_KEY_MAX];
    char text[16];
    int text_len;
};

struct nk_input {
    struct nk_keyboard keyboard;
    struct nk_mouse mouse;
};

extern nk_bool nk_input_has_mouse_click(const struct nk_input*, enum nk_buttons);
extern nk_bool nk_input_has_mouse_click_in_rect(const struct nk_input*, enum nk_buttons, struct nk_rect);
extern nk_bool nk_input_has_mouse_click_in_button_rect(const struct nk_input*, enum nk_buttons, struct nk_rect);
extern nk_bool nk_input_has_mouse_click_down_in_rect(const struct nk_input*, enum nk_buttons, struct nk_rect, nk_bool down);
extern nk_bool nk_input_is_mouse_click_in_rect(const struct nk_input*, enum nk_buttons, struct nk_rect);
extern nk_bool nk_input_is_mouse_click_down_in_rect(const struct nk_input *i, enum nk_buttons id, struct nk_rect b, nk_bool down);
extern nk_bool nk_input_any_mouse_click_in_rect(const struct nk_input*, struct nk_rect);
extern nk_bool nk_input_is_mouse_prev_hovering_rect(const struct nk_input*, struct nk_rect);
extern nk_bool nk_input_is_mouse_hovering_rect(const struct nk_input*, struct nk_rect);
extern nk_bool nk_input_is_mouse_moved(const struct nk_input*);
extern nk_bool nk_input_mouse_clicked(const struct nk_input*, enum nk_buttons, struct nk_rect);
extern nk_bool nk_input_is_mouse_down(const struct nk_input*, enum nk_buttons);
extern nk_bool nk_input_is_mouse_pressed(const struct nk_input*, enum nk_buttons);
extern nk_bool nk_input_is_mouse_released(const struct nk_input*, enum nk_buttons);
extern nk_bool nk_input_is_key_pressed(const struct nk_input*, enum nk_keys);
extern nk_bool nk_input_is_key_released(const struct nk_input*, enum nk_keys);
extern nk_bool nk_input_is_key_down(const struct nk_input*, enum nk_keys);
typedef nk_ushort nk_draw_index;

enum nk_draw_list_stroke {
    NK_STROKE_OPEN = nk_false,
    NK_STROKE_CLOSED = nk_true
};

enum nk_draw_vertex_layout_attribute {
    NK_VERTEX_POSITION,
    NK_VERTEX_COLOR,
    NK_VERTEX_TEXCOORD,
    NK_VERTEX_ATTRIBUTE_COUNT
};

enum nk_draw_vertex_layout_format {
    NK_FORMAT_SCHAR,
    NK_FORMAT_SSHORT,
    NK_FORMAT_SINT,
    NK_FORMAT_UCHAR,
    NK_FORMAT_USHORT,
    NK_FORMAT_UINT,
    NK_FORMAT_FLOAT,
    NK_FORMAT_DOUBLE,

    NK_FORMAT_COLOR_BEGIN,
    NK_FORMAT_R8G8B8 = NK_FORMAT_COLOR_BEGIN,
    NK_FORMAT_R16G15B16,
    NK_FORMAT_R32G32B32,

    NK_FORMAT_R8G8B8A8,
    NK_FORMAT_B8G8R8A8,
    NK_FORMAT_R16G15B16A16,
    NK_FORMAT_R32G32B32A32,
    NK_FORMAT_R32G32B32A32_FLOAT,
    NK_FORMAT_R32G32B32A32_DOUBLE,

    NK_FORMAT_RGB32,
    NK_FORMAT_RGBA32,
    NK_FORMAT_COLOR_END = NK_FORMAT_RGBA32,
    NK_FORMAT_COUNT
};


struct nk_draw_vertex_layout_element {
    enum nk_draw_vertex_layout_attribute attribute;
    enum nk_draw_vertex_layout_format format;
    nk_size offset;
};

struct nk_draw_command {
    unsigned int elem_count;
    struct nk_rect clip_rect;
    nk_handle texture;



};

struct nk_draw_list {
    struct nk_rect clip_rect;
    struct nk_vec2 circle_vtx[12];
    struct nk_convert_config config;

    struct nk_buffer *buffer;
    struct nk_buffer *vertices;
    struct nk_buffer *elements;

    unsigned int element_count;
    unsigned int vertex_count;
    unsigned int cmd_count;
    nk_size cmd_offset;

    unsigned int path_count;
    unsigned int path_offset;

    enum nk_anti_aliasing line_AA;
    enum nk_anti_aliasing shape_AA;




};


extern void nk_draw_list_init(struct nk_draw_list*);
extern void nk_draw_list_setup(struct nk_draw_list*, const struct nk_convert_config*, struct nk_buffer *cmds, struct nk_buffer *vertices, struct nk_buffer *elements, enum nk_anti_aliasing line_aa,enum nk_anti_aliasing shape_aa);



extern const struct nk_draw_command* nk__draw_list_begin(const struct nk_draw_list*, const struct nk_buffer*);
extern const struct nk_draw_command* nk__draw_list_next(const struct nk_draw_command*, const struct nk_buffer*, const struct nk_draw_list*);
extern const struct nk_draw_command* nk__draw_list_end(const struct nk_draw_list*, const struct nk_buffer*);


extern void nk_draw_list_path_clear(struct nk_draw_list*);
extern void nk_draw_list_path_line_to(struct nk_draw_list*, struct nk_vec2 pos);
extern void nk_draw_list_path_arc_to_fast(struct nk_draw_list*, struct nk_vec2 center, float radius, int a_min, int a_max);
extern void nk_draw_list_path_arc_to(struct nk_draw_list*, struct nk_vec2 center, float radius, float a_min, float a_max, unsigned int segments);
extern void nk_draw_list_path_rect_to(struct nk_draw_list*, struct nk_vec2 a, struct nk_vec2 b, float rounding);
extern void nk_draw_list_path_curve_to(struct nk_draw_list*, struct nk_vec2 p2, struct nk_vec2 p3, struct nk_vec2 p4, unsigned int num_segments);
extern void nk_draw_list_path_fill(struct nk_draw_list*, struct nk_color);
extern void nk_draw_list_path_stroke(struct nk_draw_list*, struct nk_color, enum nk_draw_list_stroke closed, float thickness);


extern void nk_draw_list_stroke_line(struct nk_draw_list*, struct nk_vec2 a, struct nk_vec2 b, struct nk_color, float thickness);
extern void nk_draw_list_stroke_rect(struct nk_draw_list*, struct nk_rect rect, struct nk_color, float rounding, float thickness);
extern void nk_draw_list_stroke_triangle(struct nk_draw_list*, struct nk_vec2 a, struct nk_vec2 b, struct nk_vec2 c, struct nk_color, float thickness);
extern void nk_draw_list_stroke_circle(struct nk_draw_list*, struct nk_vec2 center, float radius, struct nk_color, unsigned int segs, float thickness);
extern void nk_draw_list_stroke_curve(struct nk_draw_list*, struct nk_vec2 p0, struct nk_vec2 cp0, struct nk_vec2 cp1, struct nk_vec2 p1, struct nk_color, unsigned int segments, float thickness);
extern void nk_draw_list_stroke_poly_line(struct nk_draw_list*, const struct nk_vec2 *pnts, const unsigned int cnt, struct nk_color, enum nk_draw_list_stroke, float thickness, enum nk_anti_aliasing);


extern void nk_draw_list_fill_rect(struct nk_draw_list*, struct nk_rect rect, struct nk_color, float rounding);
extern void nk_draw_list_fill_rect_multi_color(struct nk_draw_list*, struct nk_rect rect, struct nk_color left, struct nk_color top, struct nk_color right, struct nk_color bottom);
extern void nk_draw_list_fill_triangle(struct nk_draw_list*, struct nk_vec2 a, struct nk_vec2 b, struct nk_vec2 c, struct nk_color);
extern void nk_draw_list_fill_circle(struct nk_draw_list*, struct nk_vec2 center, float radius, struct nk_color col, unsigned int segs);
extern void nk_draw_list_fill_poly_convex(struct nk_draw_list*, const struct nk_vec2 *points, const unsigned int count, struct nk_color, enum nk_anti_aliasing);


extern void nk_draw_list_add_image(struct nk_draw_list*, struct nk_image texture, struct nk_rect rect, struct nk_color);
extern void nk_draw_list_add_text(struct nk_draw_list*, const struct nk_user_font*, struct nk_rect, const char *text, int len, float font_height, struct nk_color);
enum nk_style_item_type {
    NK_STYLE_ITEM_COLOR,
    NK_STYLE_ITEM_IMAGE,
    NK_STYLE_ITEM_NINE_SLICE
};

union nk_style_item_data {
    struct nk_color color;
    struct nk_image image;
    struct nk_nine_slice slice;
};

struct nk_style_item {
    enum nk_style_item_type type;
    union nk_style_item_data data;
};

struct nk_style_text {
    struct nk_color color;
    struct nk_vec2 padding;
    float color_factor;
    float disabled_factor;
};

struct nk_style_button {

    struct nk_style_item normal;
    struct nk_style_item hover;
    struct nk_style_item active;
    struct nk_color border_color;
    float color_factor_background;


    struct nk_color text_background;
    struct nk_color text_normal;
    struct nk_color text_hover;
    struct nk_color text_active;
    nk_flags text_alignment;
    float color_factor_text;


    float border;
    float rounding;
    struct nk_vec2 padding;
    struct nk_vec2 image_padding;
    struct nk_vec2 touch_padding;
    float disabled_factor;


    nk_handle userdata;
    void(*draw_begin)(struct nk_command_buffer*, nk_handle userdata);
    void(*draw_end)(struct nk_command_buffer*, nk_handle userdata);
};

struct nk_style_toggle {

    struct nk_style_item normal;
    struct nk_style_item hover;
    struct nk_style_item active;
    struct nk_color border_color;


    struct nk_style_item cursor_normal;
    struct nk_style_item cursor_hover;


    struct nk_color text_normal;
    struct nk_color text_hover;
    struct nk_color text_active;
    struct nk_color text_background;
    nk_flags text_alignment;


    struct nk_vec2 padding;
    struct nk_vec2 touch_padding;
    float spacing;
    float border;
    float color_factor;
    float disabled_factor;


    nk_handle userdata;
    void(*draw_begin)(struct nk_command_buffer*, nk_handle);
    void(*draw_end)(struct nk_command_buffer*, nk_handle);
};

struct nk_style_selectable {

    struct nk_style_item normal;
    struct nk_style_item hover;
    struct nk_style_item pressed;


    struct nk_style_item normal_active;
    struct nk_style_item hover_active;
    struct nk_style_item pressed_active;


    struct nk_color text_normal;
    struct nk_color text_hover;
    struct nk_color text_pressed;


    struct nk_color text_normal_active;
    struct nk_color text_hover_active;
    struct nk_color text_pressed_active;
    struct nk_color text_background;
    nk_flags text_alignment;


    float rounding;
    struct nk_vec2 padding;
    struct nk_vec2 touch_padding;
    struct nk_vec2 image_padding;
    float color_factor;
    float disabled_factor;


    nk_handle userdata;
    void(*draw_begin)(struct nk_command_buffer*, nk_handle);
    void(*draw_end)(struct nk_command_buffer*, nk_handle);
};

struct nk_style_slider {

    struct nk_style_item normal;
    struct nk_style_item hover;
    struct nk_style_item active;
    struct nk_color border_color;


    struct nk_color bar_normal;
    struct nk_color bar_hover;
    struct nk_color bar_active;
    struct nk_color bar_filled;


    struct nk_style_item cursor_normal;
    struct nk_style_item cursor_hover;
    struct nk_style_item cursor_active;


    float border;
    float rounding;
    float bar_height;
    struct nk_vec2 padding;
    struct nk_vec2 spacing;
    struct nk_vec2 cursor_size;
    float color_factor;
    float disabled_factor;


    int show_buttons;
    struct nk_style_button inc_button;
    struct nk_style_button dec_button;
    enum nk_symbol_type inc_symbol;
    enum nk_symbol_type dec_symbol;


    nk_handle userdata;
    void(*draw_begin)(struct nk_command_buffer*, nk_handle);
    void(*draw_end)(struct nk_command_buffer*, nk_handle);
};

struct nk_style_knob {

    struct nk_style_item normal;
    struct nk_style_item hover;
    struct nk_style_item active;
    struct nk_color border_color;


    struct nk_color knob_normal;
    struct nk_color knob_hover;
    struct nk_color knob_active;
    struct nk_color knob_border_color;


    struct nk_color cursor_normal;
    struct nk_color cursor_hover;
    struct nk_color cursor_active;


    float border;
    float knob_border;
    struct nk_vec2 padding;
    struct nk_vec2 spacing;
    float cursor_width;
    float color_factor;
    float disabled_factor;


    nk_handle userdata;
    void(*draw_begin)(struct nk_command_buffer*, nk_handle);
    void(*draw_end)(struct nk_command_buffer*, nk_handle);
};

struct nk_style_progress {

    struct nk_style_item normal;
    struct nk_style_item hover;
    struct nk_style_item active;
    struct nk_color border_color;


    struct nk_style_item cursor_normal;
    struct nk_style_item cursor_hover;
    struct nk_style_item cursor_active;
    struct nk_color cursor_border_color;


    float rounding;
    float border;
    float cursor_border;
    float cursor_rounding;
    struct nk_vec2 padding;
    float color_factor;
    float disabled_factor;


    nk_handle userdata;
    void(*draw_begin)(struct nk_command_buffer*, nk_handle);
    void(*draw_end)(struct nk_command_buffer*, nk_handle);
};

struct nk_style_scrollbar {

    struct nk_style_item normal;
    struct nk_style_item hover;
    struct nk_style_item active;
    struct nk_color border_color;


    struct nk_style_item cursor_normal;
    struct nk_style_item cursor_hover;
    struct nk_style_item cursor_active;
    struct nk_color cursor_border_color;


    float border;
    float rounding;
    float border_cursor;
    float rounding_cursor;
    struct nk_vec2 padding;
    float color_factor;
    float disabled_factor;


    int show_buttons;
    struct nk_style_button inc_button;
    struct nk_style_button dec_button;
    enum nk_symbol_type inc_symbol;
    enum nk_symbol_type dec_symbol;


    nk_handle userdata;
    void(*draw_begin)(struct nk_command_buffer*, nk_handle);
    void(*draw_end)(struct nk_command_buffer*, nk_handle);
};

struct nk_style_edit {

    struct nk_style_item normal;
    struct nk_style_item hover;
    struct nk_style_item active;
    struct nk_color border_color;
    struct nk_style_scrollbar scrollbar;


    struct nk_color cursor_normal;
    struct nk_color cursor_hover;
    struct nk_color cursor_text_normal;
    struct nk_color cursor_text_hover;


    struct nk_color text_normal;
    struct nk_color text_hover;
    struct nk_color text_active;


    struct nk_color selected_normal;
    struct nk_color selected_hover;
    struct nk_color selected_text_normal;
    struct nk_color selected_text_hover;


    float border;
    float rounding;
    float cursor_size;
    struct nk_vec2 scrollbar_size;
    struct nk_vec2 padding;
    float row_padding;
    float color_factor;
    float disabled_factor;
};

struct nk_style_property {

    struct nk_style_item normal;
    struct nk_style_item hover;
    struct nk_style_item active;
    struct nk_color border_color;


    struct nk_color label_normal;
    struct nk_color label_hover;
    struct nk_color label_active;


    enum nk_symbol_type sym_left;
    enum nk_symbol_type sym_right;


    float border;
    float rounding;
    struct nk_vec2 padding;
    float color_factor;
    float disabled_factor;

    struct nk_style_edit edit;
    struct nk_style_button inc_button;
    struct nk_style_button dec_button;


    nk_handle userdata;
    void(*draw_begin)(struct nk_command_buffer*, nk_handle);
    void(*draw_end)(struct nk_command_buffer*, nk_handle);
};

struct nk_style_chart {

    struct nk_style_item background;
    struct nk_color border_color;
    struct nk_color selected_color;
    struct nk_color color;


    float border;
    float rounding;
    struct nk_vec2 padding;
    float color_factor;
    float disabled_factor;
    nk_bool show_markers;
};

struct nk_style_combo {

    struct nk_style_item normal;
    struct nk_style_item hover;
    struct nk_style_item active;
    struct nk_color border_color;


    struct nk_color label_normal;
    struct nk_color label_hover;
    struct nk_color label_active;


    struct nk_color symbol_normal;
    struct nk_color symbol_hover;
    struct nk_color symbol_active;


    struct nk_style_button button;
    enum nk_symbol_type sym_normal;
    enum nk_symbol_type sym_hover;
    enum nk_symbol_type sym_active;


    float border;
    float rounding;
    struct nk_vec2 content_padding;
    struct nk_vec2 button_padding;
    struct nk_vec2 spacing;
    float color_factor;
    float disabled_factor;
};

struct nk_style_tab {

    struct nk_style_item background;
    struct nk_color border_color;
    struct nk_color text;


    struct nk_style_button tab_maximize_button;
    struct nk_style_button tab_minimize_button;
    struct nk_style_button node_maximize_button;
    struct nk_style_button node_minimize_button;
    enum nk_symbol_type sym_minimize;
    enum nk_symbol_type sym_maximize;


    float border;
    float rounding;
    float indent;
    struct nk_vec2 padding;
    struct nk_vec2 spacing;
    float color_factor;
    float disabled_factor;
};

enum nk_style_header_align {
    NK_HEADER_LEFT,
    NK_HEADER_RIGHT
};
struct nk_style_window_header {

    struct nk_style_item normal;
    struct nk_style_item hover;
    struct nk_style_item active;


    struct nk_style_button close_button;
    struct nk_style_button minimize_button;
    enum nk_symbol_type close_symbol;
    enum nk_symbol_type minimize_symbol;
    enum nk_symbol_type maximize_symbol;


    struct nk_color label_normal;
    struct nk_color label_hover;
    struct nk_color label_active;


    enum nk_style_header_align align;
    struct nk_vec2 padding;
    struct nk_vec2 label_padding;
    struct nk_vec2 spacing;
};

struct nk_style_window {
    struct nk_style_window_header header;
    struct nk_style_item fixed_background;
    struct nk_color background;

    struct nk_color border_color;
    struct nk_color popup_border_color;
    struct nk_color combo_border_color;
    struct nk_color contextual_border_color;
    struct nk_color menu_border_color;
    struct nk_color group_border_color;
    struct nk_color tooltip_border_color;
    struct nk_style_item scaler;

    float border;
    float combo_border;
    float contextual_border;
    float menu_border;
    float group_border;
    float tooltip_border;
    float popup_border;
    float min_row_height_padding;

    float rounding;
    struct nk_vec2 spacing;
    struct nk_vec2 scrollbar_size;
    struct nk_vec2 min_size;

    struct nk_vec2 padding;
    struct nk_vec2 group_padding;
    struct nk_vec2 popup_padding;
    struct nk_vec2 combo_padding;
    struct nk_vec2 contextual_padding;
    struct nk_vec2 menu_padding;
    struct nk_vec2 tooltip_padding;

    enum nk_tooltip_pos tooltip_origin;
    struct nk_vec2 tooltip_offset;
};

struct nk_style {
    const struct nk_user_font *font;
    const struct nk_cursor *cursors[NK_CURSOR_COUNT];
    const struct nk_cursor *cursor_active;
    struct nk_cursor *cursor_last;
    int cursor_visible;

    struct nk_style_text text;
    struct nk_style_button button;
    struct nk_style_button contextual_button;
    struct nk_style_button menu_button;
    struct nk_style_toggle option;
    struct nk_style_toggle checkbox;
    struct nk_style_selectable selectable;
    struct nk_style_slider slider;
    struct nk_style_knob knob;
    struct nk_style_progress progress;
    struct nk_style_property property;
    struct nk_style_edit edit;
    struct nk_style_chart chart;
    struct nk_style_scrollbar scrollh;
    struct nk_style_scrollbar scrollv;
    struct nk_style_tab tab;
    struct nk_style_combo combo;
    struct nk_style_window window;
};

extern struct nk_style_item nk_style_item_color(struct nk_color);
extern struct nk_style_item nk_style_item_image(struct nk_image img);
extern struct nk_style_item nk_style_item_nine_slice(struct nk_nine_slice slice);
extern struct nk_style_item nk_style_item_hide(void);
enum nk_panel_type {
    NK_PANEL_NONE = 0,
    NK_PANEL_WINDOW = (1 << (0)),
    NK_PANEL_GROUP = (1 << (1)),
    NK_PANEL_POPUP = (1 << (2)),
    NK_PANEL_CONTEXTUAL = (1 << (4)),
    NK_PANEL_COMBO = (1 << (5)),
    NK_PANEL_MENU = (1 << (6)),
    NK_PANEL_TOOLTIP = (1 << (7))
};
enum nk_panel_set {
    NK_PANEL_SET_NONBLOCK = NK_PANEL_CONTEXTUAL|NK_PANEL_COMBO|NK_PANEL_MENU|NK_PANEL_TOOLTIP,
    NK_PANEL_SET_POPUP = NK_PANEL_SET_NONBLOCK|NK_PANEL_POPUP,
    NK_PANEL_SET_SUB = NK_PANEL_SET_POPUP|NK_PANEL_GROUP
};

struct nk_chart_slot {
    enum nk_chart_type type;
    struct nk_color color;
    struct nk_color highlight;
    float min, max, range;
    int count;
    struct nk_vec2 last;
    int index;
    nk_bool show_markers;
};

struct nk_chart {
    int slot;
    float x, y, w, h;
    struct nk_chart_slot slots[4];
};

enum nk_panel_row_layout_type {
    NK_LAYOUT_DYNAMIC_FIXED = 0,
    NK_LAYOUT_DYNAMIC_ROW,
    NK_LAYOUT_DYNAMIC_FREE,
    NK_LAYOUT_DYNAMIC,
    NK_LAYOUT_STATIC_FIXED,
    NK_LAYOUT_STATIC_ROW,
    NK_LAYOUT_STATIC_FREE,
    NK_LAYOUT_STATIC,
    NK_LAYOUT_TEMPLATE,
    NK_LAYOUT_COUNT
};
struct nk_row_layout {
    enum nk_panel_row_layout_type type;
    int index;
    float height;
    float min_height;
    int columns;
    const float *ratio;
    float item_width;
    float item_height;
    float item_offset;
    float filled;
    struct nk_rect item;
    int tree_depth;
    float templates[16];
};

struct nk_popup_buffer {
    nk_size begin;
    nk_size parent;
    nk_size last;
    nk_size end;
    nk_bool active;
};

struct nk_menu_state {
    float x, y, w, h;
    struct nk_scroll offset;
};

struct nk_panel {
    enum nk_panel_type type;
    nk_flags flags;
    struct nk_rect bounds;
    nk_uint *offset_x;
    nk_uint *offset_y;
    float at_x, at_y, max_x;
    float footer_height;
    float header_height;
    float border;
    unsigned int has_scrolling;
    struct nk_rect clip;
    struct nk_menu_state menu;
    struct nk_row_layout row;
    struct nk_chart chart;
    struct nk_command_buffer *buffer;
    struct nk_panel *parent;
};
struct nk_table;
enum nk_window_flags {
    NK_WINDOW_PRIVATE = (1 << (11)),
    NK_WINDOW_DYNAMIC = NK_WINDOW_PRIVATE,
    NK_WINDOW_ROM = (1 << (12)),
    NK_WINDOW_NOT_INTERACTIVE = NK_WINDOW_ROM|NK_WINDOW_NO_INPUT,
    NK_WINDOW_HIDDEN = (1 << (13)),
    NK_WINDOW_CLOSED = (1 << (14)),
    NK_WINDOW_MINIMIZED = (1 << (15)),
    NK_WINDOW_REMOVE_ROM = (1 << (16))
};

struct nk_popup_state {
    struct nk_window *win;
    enum nk_panel_type type;
    struct nk_popup_buffer buf;
    nk_hash name;
    nk_bool active;
    unsigned combo_count;
    unsigned con_count, con_old;
    unsigned active_con;
    struct nk_rect header;
};

struct nk_edit_state {
    nk_hash name;
    unsigned int seq;
    unsigned int old;
    int active, prev;
    int cursor;
    int sel_start;
    int sel_end;
    struct nk_scroll scrollbar;
    unsigned char mode;
    unsigned char single_line;
};

struct nk_property_state {
    int active, prev;
    char buffer[64];
    int length;
    int cursor;
    int select_start;
    int select_end;
    nk_hash name;
    unsigned int seq;
    unsigned int old;
    int state;
    int prev_state;
    nk_hash prev_name;
    char prev_buffer[64];
    int prev_length;
};

struct nk_window {
    unsigned int seq;
    nk_hash name;
    char name_string[64];
    nk_flags flags;

    struct nk_rect bounds;
    struct nk_scroll scrollbar;
    struct nk_command_buffer buffer;
    struct nk_panel *layout;
    float scrollbar_hiding_timer;


    struct nk_property_state property;
    struct nk_popup_state popup;
    struct nk_edit_state edit;
    unsigned int scrolled;
    nk_bool widgets_disabled;

    struct nk_table *tables;
    unsigned int table_count;


    struct nk_window *next;
    struct nk_window *prev;
    struct nk_window *parent;
};
struct nk_config_stack_style_item_element { struct nk_style_item *address; struct nk_style_item old_value; };
struct nk_config_stack_float_element { float *address; float old_value; };
struct nk_config_stack_vec2_element { struct nk_vec2 *address; struct nk_vec2 old_value; };
struct nk_config_stack_flags_element { nk_flags *address; nk_flags old_value; };
struct nk_config_stack_color_element { struct nk_color *address; struct nk_color old_value; };
struct nk_config_stack_user_font_element { const struct nk_user_font* *address; const struct nk_user_font* old_value; };
struct nk_config_stack_button_behavior_element { enum nk_button_behavior *address; enum nk_button_behavior old_value; };

struct nk_config_stack_style_item { int head; struct nk_config_stack_style_item_element elements[16]; };
struct nk_config_stack_float { int head; struct nk_config_stack_float_element elements[32]; };
struct nk_config_stack_vec2 { int head; struct nk_config_stack_vec2_element elements[16]; };
struct nk_config_stack_flags { int head; struct nk_config_stack_flags_element elements[32]; };
struct nk_config_stack_color { int head; struct nk_config_stack_color_element elements[32]; };
struct nk_config_stack_user_font { int head; struct nk_config_stack_user_font_element elements[8]; };
struct nk_config_stack_button_behavior { int head; struct nk_config_stack_button_behavior_element elements[8]; };

struct nk_configuration_stacks {
    struct nk_config_stack_style_item style_items;
    struct nk_config_stack_float floats;
    struct nk_config_stack_vec2 vectors;
    struct nk_config_stack_flags flags;
    struct nk_config_stack_color colors;
    struct nk_config_stack_user_font fonts;
    struct nk_config_stack_button_behavior button_behaviors;
};







struct nk_table {
    unsigned int seq;
    unsigned int size;
    nk_hash keys[(((((sizeof(struct nk_window)) < (sizeof(struct nk_panel)) ? (sizeof(struct nk_panel)) : (sizeof(struct nk_window))) / sizeof(nk_uint))) / 2)];
    nk_uint values[(((((sizeof(struct nk_window)) < (sizeof(struct nk_panel)) ? (sizeof(struct nk_panel)) : (sizeof(struct nk_window))) / sizeof(nk_uint))) / 2)];
    struct nk_table *next, *prev;
};

union nk_page_data {
    struct nk_table tbl;
    struct nk_panel pan;
    struct nk_window win;
};

struct nk_page_element {
    union nk_page_data data;
    struct nk_page_element *next;
    struct nk_page_element *prev;
};

struct nk_page {
    unsigned int size;
    struct nk_page *next;
    struct nk_page_element win[1];
};

struct nk_pool {
    struct nk_allocator alloc;
    enum nk_allocation_type type;
    unsigned int page_count;
    struct nk_page *pages;
    struct nk_page_element *freelist;
    unsigned capacity;
    nk_size size;
    nk_size cap;
};

struct nk_context {

    struct nk_input input;
    struct nk_style style;
    struct nk_buffer memory;
    struct nk_clipboard clip;
    nk_flags last_widget_state;
    enum nk_button_behavior button_behavior;
    struct nk_configuration_stacks stacks;
    float delta_time_seconds;





    struct nk_draw_list draw_list;
    struct nk_text_edit text_edit;

    struct nk_command_buffer overlay;


    int build;
    int use_pool;
    struct nk_pool pool;
    struct nk_window *begin;
    struct nk_window *end;
    struct nk_window *active;
    struct nk_window *current;
    struct nk_page_element *freelist;
    unsigned int count;
    unsigned int seq;
};




