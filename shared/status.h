#ifndef STATUS_H
#define STATUS_H

#include "types.h"

#define STATUS_OK                status_ok
#define STATUS_FAIL              status_fail
#define STATUS_INVALID           status_invalid
#define STATUS_NOT_FOUND         status_not_found
#define STATUS_DENIED            status_denied
#define STATUS_BUSY              status_busy
#define STATUS_TIMEOUT           status_timeout
#define STATUS_OUT_OF_MEMORY     status_out_of_memory
#define STATUS_NOT_SUPPORTED     status_not_supported

static inline bool status_success(status_t status)
{
    return status == status_ok;
}

static inline bool status_failure(status_t status)
{
    return status != status_ok;
}

#endif