#ifndef I_NETWORK_H
#define I_NETWORK_H

#include "../shared/types.h"
#include "../shared/status.h"

typedef enum
{
    network_type_unknown = 0,
    network_type_ethernet,
    network_type_wifi,
    network_type_bluetooth
} network_type_t;

typedef struct
{
    bool connected;
    u32 speed_mbps;
    network_type_t type;
} network_info_t;

status_t i_network_initialize(void);

status_t i_network_shutdown(void);

status_t i_network_connect(void);

status_t i_network_disconnect(void);

bool i_network_is_connected(void);

status_t i_network_send(
    const void* data,
    u32 size
);

status_t i_network_receive(
    void* buffer,
    u32 size
);

network_info_t i_network_get_info(void);

#endif