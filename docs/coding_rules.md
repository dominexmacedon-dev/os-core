# Coding Rules

This document defines the coding standards for the operating system.

The purpose of these rules is to maintain consistency, scalability, and maintainability as the project grows.

Without strict rules, a large system becomes difficult to debug, extend, and test.

These rules apply to every module.

---

# Core Philosophy

Code must be:

* predictable
* modular
* testable
* maintainable
* scalable

The system should remain understandable even when thousands of files exist.

---

# 1. Naming Rules

Naming consistency is mandatory.

## General Rules

Use:

* lowercase
* snake_case
* meaningful names

Avoid:

* camelCase
* random abbreviations
* unclear naming

Correct:

```c
memory_manager_init();
driver_register();
service_start();
```

Wrong:

```c
memInit();
DrvReg();
DoThing();
```

---

## File Naming

All files use:

```text
snake_case
```

Correct:

```text
memory_manager.c
service_manager.c
display_driver.c
```

Wrong:

```text
MemoryManager.c
DisplayDriver.cpp
helperStuff.c
```

---

## Folder Naming

Folders must use:

```text
lowercase
```

Correct:

```text
kernel
memory
drivers
services
```

Wrong:

```text
Kernel
DriverLayer
MemorySystem
```

---

## Struct Naming

Use suffix `_t`

Correct:

```c
process_t
driver_t
service_t
memory_block_t
```

Wrong:

```c
Process
DriverClass
MEMBLOCK
```

---

## Enum Naming

Use prefixes.

Correct:

```c
status_ok
status_fail
status_busy
```

Wrong:

```c
OK
FAILED
BUSY
```

---

# 2. API Prefix Rules

Every public API must use prefixes.

This prevents naming collisions and improves readability.

## HAL

Prefix:

```text
hal_
```

Example:

```c
hal_display_draw();
hal_audio_play();
hal_input_read();
```

---

## Services

Prefix:

```text
svc_
```

Example:

```c
svc_register();
svc_start();
svc_lookup();
```

---

## Drivers

Prefix:

```text
drv_
```

Example:

```c
drv_keyboard_init();
drv_gpu_start();
drv_storage_read();
```

---

## Memory

Prefix:

```text
mem_
```

Example:

```c
mem_alloc();
mem_free();
mem_copy();
```

---

## Process System

Prefix:

```text
proc_
```

Example:

```c
proc_create();
proc_schedule();
proc_kill();
```

---

## Kernel

Prefix:

```text
kernel_
```

Example:

```c
kernel_init();
kernel_panic();
kernel_shutdown();
```

---

## Runtime

Prefix:

```text
rt_
```

Example:

```c
rt_start();
rt_execute();
```

---

## Graphics

Prefix:

```text
gfx_
```

Example:

```c
gfx_draw_pixel();
gfx_render_frame();
```

---

## UI

Prefix:

```text
ui_
```

Example:

```c
ui_button_create();
ui_layout_update();
```

---

# 3. Folder Rules

Every module follows the same structure.

Required structure:

```text
module/
│
├── include/
├── src/
├── tests/
├── docs/
├── examples/
├── Makefile
└── README.md
```

Purpose:

Consistency between all repos.

Example:

```text
os-memory
os-kernel
os-drivers
```

must follow the same layout.

---

# 4. Header Rules

Every header must use include guards.

Required:

```c
#ifndef FILE_NAME_H
#define FILE_NAME_H

// code

#endif
```

Example:

```c
#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

void mem_init(void);

#endif
```

Never:

```c
#pragma once
```

Reason:

Maximum portability.

---

## Public vs Private Headers

### Public headers

Go inside:

```text
include/
```

Expose APIs.

### Private headers

Stay inside:

```text
src/
```

Never exposed externally.

---

# 5. Error Handling Rules

Never silently fail.

Every failure must return status.

Use shared status system.

Correct:

```c
status_t result = mem_alloc();

if (result != status_ok)
{
    return status_fail;
}
```

Wrong:

```c
do_work();
```

without validation.

---

## Kernel Panic Rule

Critical failures must panic.

Example:

```c
kernel_panic("Memory corruption");
```

Never continue execution after unrecoverable errors.

---

# 6. Memory Ownership Rules

Ownership must always be clear.

Rule:

Who allocates memory is responsible for freeing it.

Correct:

```c
buffer = mem_alloc();

/* use */

mem_free(buffer);
```

Wrong:

```c
random_module_free(buffer);
```

Never free memory you do not own.

---

## Avoid Global State

Global variables are discouraged.

Allowed only for:

* kernel state
* registry system
* hardware mappings

Everything else should pass through interfaces.

---

# 7. Thread Safety Rules

Assume concurrency exists.

Shared resources must be protected.

Never:

```c
shared_counter++;
```

without synchronization.

Use:

* locks
* mutexes
* atomics
* scheduler-safe mechanisms

Future-safe design matters.

---

# 8. Module Isolation Rules

Modules must stay independent.

Bad:

```text
drivers
→ ui
```

Good:

```text
drivers
→ hal
→ services
→ ui
```

Forbidden:

* circular dependencies
* hidden dependencies
* cross-module hacks

---

# 9. Dependency Rules

Lower layers must never depend on higher layers.

Correct:

```text
kernel
→ memory
```

Wrong:

```text
memory
→ ui
```

Architecture direction must always flow downward.

---

# 10. Code Style Rules

Braces always required.

Correct:

```c
if (ready)
{
    start();
}
```

Wrong:

```c
if (ready)
    start();
```

---

## Line Length

Recommended:

```text
100 characters max
```

---

## Function Size

Recommended:

```text
under 100 lines
```

Large functions should be split.

---

## Magic Numbers

Never hardcode unexplained values.

Wrong:

```c
buffer[4096];
```

Correct:

```c
#define PAGE_SIZE 4096
```

---

# 11. Documentation Rules

Every public API must explain:

* purpose
* parameters
* return value
* failure conditions

Example:

```c
/*
 * Allocates memory block.
 *
 * size: bytes to allocate
 *
 * Returns:
 * pointer on success
 * NULL on failure
 */
void* mem_alloc(int size);
```

---

# 12. Testing Rules

Every module must have tests.

Before approval:

* builds successfully
* tests pass
* interfaces documented
* contracts stable

No exceptions.

---

# Final Rule

Consistency over cleverness.

Readable code is preferred over complicated code.

The architecture must remain understandable years later.
