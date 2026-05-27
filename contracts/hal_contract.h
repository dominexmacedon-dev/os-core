#ifndef HAL_CONTRACT_H
#define HAL_CONTRACT_H

#include "../shared/types.h"
#include "../shared/status.h"

typedef struct
{
    status_t (*initialize)(void);
    status_t (*shutdown)(void);
} hal_base_t;

typedef struct
{
    status_t (*initialize)(void);
    status_t (*clear_screen)(void);
    status_t (*draw_pixel)(u32 x, u32 y, u32 color);
    status_t (*draw_text)(u32 x, u32 y, const char* text);
} hal_display_t;

typedef struct
{
    status_t (*initialize)(void);
    status_t (*read_key)(u8* key);
    bool (*key_available)(void);
} hal_input_t;

typedef struct
{
    status_t (*initialize)(void);
    status_t (*play_sound)(u32 frequency, u32 duration_ms);
    status_t (*stop_sound)(void);
} hal_audio_t;

typedef struct
{
    status_t (*initialize)(void);
    status_t (*read)(
        u64 address,
        void* buffer,
        u32 size
    );
    status_t (*write)(
        u64 address,
        const void* buffer,
        u32 size
    );
} hal_storage_t;

typedef struct
{
    status_t (*initialize)(void);
    status_t (*connect)(void);
    status_t (*disconnect)(void);
    status_t (*send)(
        const void* data,
        u32 size
    );
    status_t (*receive)(
        void* buffer,
        u32 size
    );
} hal_network_t;

typedef struct
{
    hal_display_t display;
    hal_input_t input;
    hal_audio_t audio;
    hal_storage_t storage;
    hal_network_t network;
} hal_manager_t;

status_t hal_initialize(void);
status_t hal_shutdown(void);

hal_display_t* hal_display(void);
hal_input_t* hal_input(void);
hal_audio_t* hal_audio(void);
hal_storage_t* hal_storage(void);
hal_network_t* hal_network(void);

#endif