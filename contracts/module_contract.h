#ifndef MODULE_CONTRACT_H
#define MODULE_CONTRACT_H

#include "../shared/types.h"
#include "../shared/status.h"
#include "../shared/version.h"

typedef enum
{
    module_type_unknown = 0,
    module_type_boot,
    module_type_kernel,
    module_type_memory,
    module_type_hal,
    module_type_driver,
    module_type_service,
    module_type_runtime,
    module_type_graphics,
    module_type_ui,
    module_type_network,
    module_type_filesystem
} module_type_t;

typedef enum
{
    module_state_uninitialized = 0,
    module_state_initialized,
    module_state_started,
    module_state_stopped,
    module_state_shutdown,
    module_state_failed
} module_state_t;

typedef struct module module_t;

typedef status_t (*module_init_fn)(void);
typedef status_t (*module_start_fn)(void);
typedef status_t (*module_stop_fn)(void);
typedef status_t (*module_shutdown_fn)(void);

struct module
{
    const char* name;

    module_type_t type;
    module_state_t state;

    u32 api_version;

    version_t version;

    module_init_fn init;
    module_start_fn start;
    module_stop_fn stop;
    module_shutdown_fn shutdown;
};

status_t module_initialize(module_t* module);
status_t module_start(module_t* module);
status_t module_stop(module_t* module);
status_t module_shutdown(module_t* module);

bool module_is_ready(const module_t* module);

#endif