# System Architecture

This document defines how every subsystem connects.

Its purpose is to prevent dependency chaos and spaghetti architecture.

---

# High-Level Architecture

The operating system follows this dependency chain:

```text
boot
↓
kernel
↓
memory
↓
hal
↓
drivers
↓
services
↓
runtime
↓
graphics
↓
ui
↓
apps
```

Every layer depends only on approved lower layers.

Higher layers must not bypass architecture rules.

---

# Layer Responsibilities

## 1. Boot Layer

Purpose:

Power-on → kernel start

Responsibilities:

* CPU initialization
* Stack setup
* Memory map
* Multiboot
* Kernel entry

Output:

Kernel running.

Module:

`os-boot`

---

## 2. Kernel Layer

Purpose:

Central operating system brain.

Responsibilities:

* Scheduler
* Panic system
* Timers
* System state
* System calls

Module:

`os-kernel`

---

## 3. Memory Layer

Purpose:

Manage system memory.

Responsibilities:

* Physical memory
* Virtual memory
* Paging
* Heap
* Allocation

Module:

`os-memory`

---

## 4. HAL Layer

Purpose:

Hardware abstraction.

Kernel should never directly control hardware.

Instead:

kernel
→ HAL
→ drivers

Responsibilities:

* display abstraction
* audio abstraction
* input abstraction
* storage abstraction
* networking abstraction

Module:

`os-hal`

---

## 5. Driver Layer

Purpose:

Real hardware communication.

Responsibilities:

* keyboard
* mouse
* display
* audio
* usb
* storage
* bluetooth
* networking

Module:

`os-drivers`

---

## 6. Service Layer

Purpose:

Android-style service system.

Responsibilities:

* service manager
* audio service
* package manager
* power manager
* notification service

Module:

`os-services`

---

## 7. Runtime Layer

Purpose:

Application execution.

Responsibilities:

* runtime
* sandbox
* execution model
* language support

Android equivalent:

ART / Dalvik

Module:

`os-runtime`

---

## 8. Graphics Layer

Purpose:

Rendering system.

Responsibilities:

* framebuffer
* compositor
* rendering
* animation
* fonts

Module:

`os-graphics`

---

## 9. UI Layer

Purpose:

User interface framework.

Responsibilities:

* layouts
* buttons
* widgets
* touch input
* themes

Module:

`os-ui`

---

## 10. Application Layer

Purpose:

User applications.

Applications must use approved APIs only.

Apps cannot directly access:

* kernel
* memory
* drivers

Apps communicate through:

UI
→ services
→ runtime

---

# Communication Rules

## Allowed

```text
kernel
→ memory

kernel
→ hal

hal
→ drivers

drivers
→ services

services
→ runtime

runtime
→ ui
```

---

## Forbidden

### Drivers → UI

❌ Forbidden

Wrong:

```text
driver
→ ui
```

Correct:

```text
driver
→ hal
→ service manager
→ ui
```

---

### Apps → Kernel

❌ Forbidden

Wrong:

```text
app
→ kernel
```

Correct:

```text
app
→ runtime
→ services
→ system api
```

---

### UI → Drivers

❌ Forbidden

Wrong:

```text
ui
→ drivers
```

Correct:

```text
ui
→ services
→ hal
→ drivers
```

---

# Dependency Philosophy

Rules:

1. Lower layers never depend on higher layers.

2. Direct hardware access only exists in drivers.

3. Kernel communicates through HAL.

4. Services are the bridge between system and UI.

5. Applications are sandboxed.

6. No circular dependencies allowed.

---

# Architectural Goal

The system should scale without rewrites.

Adding a new driver, service, or UI system should require:

* minimal changes
* stable interfaces
* no architecture breakage

The architecture must remain clean as the system grows.
