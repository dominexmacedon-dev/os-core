#ifndef DRIVER_CONTRACT_H
#define DRIVER_CONTRACT_H

#include "../shared/types.h"
#include "../shared/status.h"
#include "../shared/version.h"

typedef enum
{
    driver_type_unknown = 0,
    driver_type_display,
    driver_type_keyboard,
    driver_type_mouse,
    driver_type_touch,
    driver_type_audio,
    driver_type_storage,
    driver_type_network,
    driver_type_usb,
    driver_type_camera,
    driver_type_bluetooth,
    driver_type_gpu
} driver_type_t;

typedef enum
{
    driver_state_unloaded = 0,
    driver_state_loaded,
    driver_state_started,
    driver_state_stopped,
    driver_state_failed
} driver_state_t;

typedef struct driver driver_t;

typedef status_t (*driver_load_fn)(void);
typedef status_t (*driver_start_fn)(void);
typedef status_t (*driver_stop_fn)(void);
typedef status_t (*driver_unload_fn)(void);

typedef struct
{
    const char* manufacturer;
    const char* model;
    const char* version;
    const char* description;
} driver_info_t;

struct driver
{
    const char* name;

    driver_type_t type;
    driver_state_t state;

    u32 api_version;

    version_t version;

    driver_info_t info;

    driver_load_fn load;
    driver_start_fn start;
    driver_stop_fn stop;
    driver_unload_fn unload;
};

status_t driver_load(driver_t* driver);
status_t driver_start(driver_t* driver);
status_t driver_stop(driver_t* driver);
status_t driver_unload(driver_t* driver);

const driver_info_t* driver_info(
    const driver_t* driver
);

bool driver_is_ready(
    const driver_t* driver
);

#endif