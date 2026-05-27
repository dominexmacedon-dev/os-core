#ifndef CONFIG_H
#define CONFIG_H

#define OS_NAME                    "AndroidStyleOS"

#define OS_DEBUG_MODE              1

#define OS_BUILD_DEBUG             1
#define OS_BUILD_RELEASE           2

#define OS_BUILD_TYPE              OS_BUILD_DEBUG

#define OS_MAX_SERVICES            256
#define OS_MAX_DRIVERS             256
#define OS_MAX_PROCESSES           1024
#define OS_MAX_THREADS             4096

#define OS_MEMORY_PAGE_SIZE        4096
#define OS_MEMORY_HEAP_SIZE_MB     256
#define OS_MEMORY_KERNEL_MB        128

#define OS_MAX_PATH_LENGTH         512
#define OS_MAX_MODULE_NAME         64

#define OS_ENABLE_LOGGING          1
#define OS_ENABLE_ASSERTIONS       1

#define OS_COMPATIBILITY_LEVEL     1

#endif