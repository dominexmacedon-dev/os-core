#include "module_registry.h"

static module_registry_t g_registry;
static bool g_initialized = false;

static bool string_equals(
    const char* a,
    const char* b
)
{
    if (!a || !b)
    {
        return false;
    }

    while (*a && *b)
    {
        if (*a != *b)
        {
            return false;
        }

        a++;
        b++;
    }

    return *a == *b;
}

status_t registry_initialize(void)
{
    g_registry.module_count = 0;
    g_registry.driver_count = 0;
    g_registry.service_count = 0;
    g_registry.hal = 0;

    g_initialized = true;

    return STATUS_OK;
}

status_t registry_shutdown(void)
{
    g_registry.module_count = 0;
    g_registry.driver_count = 0;
    g_registry.service_count = 0;
    g_registry.hal = 0;

    g_initialized = false;

    return STATUS_OK;
}

bool registry_ready(void)
{
    return g_initialized;
}

status_t register_module(
    module_t* module
)
{
    if (!g_initialized || !module)
    {
        return STATUS_FAIL;
    }

    if (g_registry.module_count >=
        MODULE_REGISTRY_MAX_ENTRIES)
    {
        return STATUS_BUSY;
    }

    g_registry.modules[
        g_registry.module_count++
    ] = module;

    return STATUS_OK;
}

module_t* find_module(
    const char* name
)
{
    u32 i;

    for (i = 0;
         i < g_registry.module_count;
         i++)
    {
        if (string_equals(
            g_registry.modules[i]->name,
            name))
        {
            return g_registry.modules[i];
        }
    }

    return 0;
}

status_t remove_module(
    const char* name
)
{
    u32 i;

    for (i = 0;
         i < g_registry.module_count;
         i++)
    {
        if (string_equals(
            g_registry.modules[i]->name,
            name))
        {
            u32 j;

            for (j = i;
                 j < g_registry.module_count - 1;
                 j++)
            {
                g_registry.modules[j] =
                    g_registry.modules[j + 1];
            }

            g_registry.module_count--;

            return STATUS_OK;
        }
    }

    return STATUS_NOT_FOUND;
}

status_t register_driver(
    driver_t* driver
)
{
    if (!g_initialized || !driver)
    {
        return STATUS_FAIL;
    }

    if (g_registry.driver_count >=
        MODULE_REGISTRY_MAX_ENTRIES)
    {
        return STATUS_BUSY;
    }

    g_registry.drivers[
        g_registry.driver_count++
    ] = driver;

    return STATUS_OK;
}

driver_t* find_driver(
    const char* name
)
{
    u32 i;

    for (i = 0;
         i < g_registry.driver_count;
         i++)
    {
        if (string_equals(
            g_registry.drivers[i]->name,
            name))
        {
            return g_registry.drivers[i];
        }
    }

    return 0;
}

status_t remove_driver(
    const char* name
)
{
    u32 i;

    for (i = 0;
         i < g_registry.driver_count;
         i++)
    {
        if (string_equals(
            g_registry.drivers[i]->name,
            name))
        {
            u32 j;

            for (j = i;
                 j < g_registry.driver_count - 1;
                 j++)
            {
                g_registry.drivers[j] =
                    g_registry.drivers[j + 1];
            }

            g_registry.driver_count--;

            return STATUS_OK;
        }
    }

    return STATUS_NOT_FOUND;
}

status_t register_service(
    service_t* service
)
{
    if (!g_initialized || !service)
    {
        return STATUS_FAIL;
    }

    if (g_registry.service_count >=
        MODULE_REGISTRY_MAX_ENTRIES)
    {
        return STATUS_BUSY;
    }

    g_registry.services[
        g_registry.service_count++
    ] = service;

    return STATUS_OK;
}

service_t* service_lookup(
    const char* name
)
{
    u32 i;

    for (i = 0;
         i < g_registry.service_count;
         i++)
    {
        if (string_equals(
            g_registry.services[i]->name,
            name))
        {
            return g_registry.services[i];
        }
    }

    return 0;
}

status_t remove_service(
    const char* name
)
{
    u32 i;

    for (i = 0;
         i < g_registry.service_count;
         i++)
    {
        if (string_equals(
            g_registry.services[i]->name,
            name))
        {
            u32 j;

            for (j = i;
                 j < g_registry.service_count - 1;
                 j++)
            {
                g_registry.services[j] =
                    g_registry.services[j + 1];
            }

            g_registry.service_count--;

            return STATUS_OK;
        }
    }

    return STATUS_NOT_FOUND;
}

status_t register_hal(
    hal_manager_t* hal
)
{
    if (!g_initialized || !hal)
    {
        return STATUS_FAIL;
    }

    g_registry.hal = hal;

    return STATUS_OK;
}

hal_manager_t* get_hal(void)
{
    return g_registry.hal;
}

u32 registry_module_count(void)
{
    return g_registry.module_count;
}

u32 registry_driver_count(void)
{
    return g_registry.driver_count;
}

u32 registry_service_count(void)
{
    return g_registry.service_count;
}