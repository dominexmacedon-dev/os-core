#ifndef MODULE_REGISTRY_H
#define MODULE_REGISTRY_H

#include "../shared/types.h"
#include "../shared/status.h"
#include "../shared/config.h"

#include "../contracts/module_contract.h"
#include "../contracts/driver_contract.h"
#include "../contracts/service_contract.h"
#include "../contracts/hal_contract.h"

#define MODULE_REGISTRY_MAX_ENTRIES 256

typedef struct
{
    module_t* modules[MODULE_REGISTRY_MAX_ENTRIES];

    driver_t* drivers[MODULE_REGISTRY_MAX_ENTRIES];

    service_t* services[MODULE_REGISTRY_MAX_ENTRIES];

    hal_manager_t* hal;

    u32 module_count;
    u32 driver_count;
    u32 service_count;
} module_registry_t;

status_t registry_initialize(void);

status_t registry_shutdown(void);

status_t register_module(
    module_t* module
);

status_t remove_module(
    const char* name
);

module_t* find_module(
    const char* name
);

status_t register_driver(
    driver_t* driver
);

driver_t* find_driver(
    const char* name
);

status_t remove_driver(
    const char* name
);

status_t register_service(
    service_t* service
);

service_t* service_lookup(
    const char* name
);

status_t remove_service(
    const char* name
);

status_t register_hal(
    hal_manager_t* hal
);

hal_manager_t* get_hal(void);

u32 registry_module_count(void);

u32 registry_driver_count(void);

u32 registry_service_count(void);

bool registry_ready(void);

#endif