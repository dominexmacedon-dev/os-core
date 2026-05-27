#ifndef I_INPUT_H
#define I_INPUT_H

#include "../shared/types.h"
#include "../shared/status.h"

typedef enum
{
    input_type_unknown = 0,
    input_type_keyboard,
    input_type_mouse,
    input_type_touch
} input_type_t;

typedef enum
{
    key_state_released = 0,
    key_state_pressed
} key_state_t;

typedef struct
{
    u32 keycode;
    key_state_t state;
} keyboard_event_t;

typedef struct
{
    i32 x;
    i32 y;
    bool left_button;
    bool right_button;
    bool middle_button;
} mouse_event_t;

status_t i_input_initialize(void);

status_t i_input_shutdown(void);

bool i_input_key_available(void);

status_t i_input_read_key(
    keyboard_event_t* event
);

status_t i_input_read_mouse(
    mouse_event_t* event
);

bool i_input_touch_available(void);

status_t i_input_read_touch(
    i32* x,
    i32* y
);

#endif