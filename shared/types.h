#ifndef TYPES_H
#define TYPES_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

typedef enum
{
    false = 0,
    true = 1
} bool;

typedef enum
{
    status_ok = 0,
    status_fail,
    status_invalid,
    status_not_found,
    status_denied,
    status_busy,
    status_timeout,
    status_out_of_memory,
    status_not_supported
} status_t;

#endif