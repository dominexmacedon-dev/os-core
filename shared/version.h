#ifndef VERSION_H
#define VERSION_H

#define OS_CORE_VERSION_MAJOR      0
#define OS_CORE_VERSION_MINOR      1
#define OS_CORE_VERSION_PATCH      0

#define OS_MODULE_API_VERSION      1

#define OS_COMPATIBILITY_MIN       1
#define OS_COMPATIBILITY_MAX       1

#define OS_VERSION_STRING          "0.1.0"

typedef struct
{
    u32 major;
    u32 minor;
    u32 patch;
} version_t;

static inline version_t version_get_core(void)
{
    version_t version;

    version.major = OS_CORE_VERSION_MAJOR;
    version.minor = OS_CORE_VERSION_MINOR;
    version.patch = OS_CORE_VERSION_PATCH;

    return version;
}

static inline bool version_is_compatible(u32 api_version)
{
    return api_version >= OS_COMPATIBILITY_MIN &&
           api_version <= OS_COMPATIBILITY_MAX;
}

#endif