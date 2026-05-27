#ifndef I_STORAGE_H
#define I_STORAGE_H

#include "../shared/types.h"
#include "../shared/status.h"

typedef enum
{
    storage_type_unknown = 0,
    storage_type_hdd,
    storage_type_ssd,
    storage_type_nvme,
    storage_type_usb,
    storage_type_sdcard
} storage_type_t;

typedef struct
{
    u64 total_size;
    u32 block_size;
    storage_type_t type;
} storage_info_t;

status_t i_storage_initialize(void);

status_t i_storage_shutdown(void);

status_t i_storage_read(
    u64 address,
    void* buffer,
    u32 size
);

status_t i_storage_write(
    u64 address,
    const void* buffer,
    u32 size
);

storage_info_t i_storage_get_info(void);

#endif