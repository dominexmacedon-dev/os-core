#ifndef I_AUDIO_H
#define I_AUDIO_H

#include "../shared/types.h"
#include "../shared/status.h"

typedef enum
{
    audio_format_unknown = 0,
    audio_format_pcm,
    audio_format_wav,
    audio_format_mp3
} audio_format_t;

typedef struct
{
    u32 sample_rate;
    u32 channels;
    u32 bit_depth;
} audio_info_t;

status_t i_audio_initialize(void);

status_t i_audio_shutdown(void);

status_t i_audio_play_sound(
    u32 frequency,
    u32 duration_ms
);

status_t i_audio_play_buffer(
    const void* data,
    u32 size
);

status_t i_audio_stop(void);

status_t i_audio_set_volume(
    u32 volume
);

audio_info_t i_audio_get_info(void);

#endif