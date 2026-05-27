#ifndef SERVICE_CONTRACT_H
#define SERVICE_CONTRACT_H

#include "../shared/types.h"
#include "../shared/status.h"
#include "../shared/version.h"

typedef enum
{
    service_type_unknown = 0,
    service_type_audio,
    service_type_input,
    service_type_window,
    service_type_package,
    service_type_power,
    service_type_notification,
    service_type_settings,
    service_type_network,
    service_type_graphics,
    service_type_security
} service_type_t;

typedef enum
{
    service_state_unregistered = 0,
    service_state_registered,
    service_state_started,
    service_state_stopped,
    service_state_failed
} service_state_t;

typedef struct service service_t;

typedef status_t (*service_register_fn)(void);
typedef status_t (*service_start_fn)(void);
typedef status_t (*service_stop_fn)(void);
typedef status_t (*service_shutdown_fn)(void);

struct service
{
    const char* name;

    service_type_t type;
    service_state_t state;

    u32 api_version;

    version_t version;

    service_register_fn register_service;
    service_start_fn start;
    service_stop_fn stop;
    service_shutdown_fn shutdown;
};

status_t service_register(
    service_t* service
);

status_t service_start(
    service_t* service
);

status_t service_stop(
    service_t* service
);

status_t service_shutdown(
    service_t* service
);

service_t* service_lookup(
    const char* name
);

bool service_is_ready(
    const service_t* service
);

#endif