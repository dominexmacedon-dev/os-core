# Dependency Graph

This document defines the system-wide dependency structure.

It ensures that modules interact in a controlled, predictable way.

No module is allowed to bypass this graph.

---

# Core Dependency Flow

The operating system follows a strict layered architecture:

```text id="dep_main"
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

Each layer depends only on the layers below it.

---

# Layer Responsibilities (Summary)

## boot

* CPU initialization
* memory setup
* kernel entry

## kernel

* scheduler
* system control
* interrupts

## memory

* heap
* paging
* allocation

## hal

* hardware abstraction
* unified hardware APIs

## drivers

* hardware drivers
* device communication

## services

* system services
* service manager
* system APIs

## runtime

* application execution environment
* sandboxing

## graphics

* rendering system
* compositor

## ui

* user interface
* widgets
* input handling

## apps

* user applications
* system applications

---

# Dependency Rules

## Rule 1: One-Way Flow

Dependencies must always flow downward:

```text id="flow1"
higher layer → lower layer (allowed)
lower layer → higher layer (forbidden)
```

---

## Rule 2: No Skipping Layers

Modules cannot skip layers.

Example:

```text id="skip_bad"
ui → drivers ❌
```

Correct:

```text id="skip_good"
ui → services → hal → drivers
```

---

## Rule 3: HAL Is Mandatory Bridge

All hardware access must go through HAL.

```text id="hal_rule"
drivers → hal → kernel
```

Kernel must NOT directly access hardware.

---

## Rule 4: Services Are System Bridge

User-facing system components must go through services:

```text id="svc_rule"
ui → services → runtime
```

---

## Rule 5: Apps Are Isolated

Applications cannot access system internals directly.

Apps only interact via:

* UI framework
* system services
* runtime APIs

---

# Forbidden Dependencies

## UI Layer

UI must NOT depend on:

* drivers
* kernel
* memory
* hardware

```text id="ui_bad"
ui → drivers ❌
ui → kernel ❌
```

---

## Drivers Layer

Drivers must NOT depend on:

* UI
* apps
* runtime

```text id="drv_bad"
drivers → ui ❌
```

---

## Kernel Layer

Kernel must NOT depend on:

* UI
* apps
* graphics

```text id="kernel_bad"
kernel → ui ❌
```

---

## Memory Layer

Memory must NOT depend on:

* drivers
* services
* UI

```text id="mem_bad"
memory → ui ❌
```

---

# Correct Communication Pattern

Example full flow:

```text id="correct_flow"
app
→ ui
→ services
→ runtime
→ hal
→ drivers
→ hardware
```

---

# Architectural Goal

The dependency graph ensures:

* modularity
* isolation
* scalability
* testability

No layer should ever bypass this structure.

---

# Final Rule

If a dependency is not explicitly allowed:

 It is forbidden by default.
