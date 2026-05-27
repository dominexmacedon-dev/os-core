# Repository Policy

This document defines mandatory rules for every repository in the operating system.

Every module must follow the same standards.

No exceptions.

---

# Purpose

The purpose of repository policy is:

* scalability
* consistency
* maintainability
* predictable integration

Every repository must work independently.

No module should depend on the entire operating system to function.

---

# Repository Independence Rule

Every repository must:

* compile independently
* build independently
* test independently
* document independently

Example:

`os-memory`

must compile without:

* graphics
* UI
* apps

Example:

`os-drivers`

must compile without:

* runtime
* UI

---

# Mandatory Repository Structure

Every repository must follow this structure:

```text
repo/
│
├── include/
├── src/
├── tests/
├── docs/
├── examples/
├── Makefile
└── README.md
```

Example:

```text
os-memory/
os-kernel/
os-hal/
os-drivers/
```

must all follow the same structure.

---

# Required Files

Every repository must contain:

## README.md

Must explain:

* purpose
* responsibilities
* architecture
* dependencies
* usage

---

## Makefile

Must support:

```bash
make
make clean
make test
```

---

## include/

Public headers only.

Purpose:

Expose APIs.

Private headers are forbidden here.

---

## src/

Implementation only.

Contains:

* .c
* .cpp
* private headers

---

## tests/

Every repository must include tests.

No repository is considered complete without tests.

---

## docs/

Documentation for:

* contracts
* interfaces
* architecture
* implementation decisions

---

# Dependency Rules

Dependencies must be minimal.

Allowed:

```text
os-kernel
→ os-memory
```

Forbidden:

```text
os-memory
→ os-ui
```

Lower layers must never depend on higher layers.

No circular dependencies allowed.

---

# Public API Rule

Every public API must:

* be documented
* use prefixes
* remain stable

Examples:

```text
hal_
drv_
svc_
mem_
proc_
kernel_
```

Breaking API changes require version updates.

---

# Contract Rule

Every repository must obey contracts.

Examples:

* module contract
* HAL contract
* driver contract
* service contract

No hidden interfaces allowed.

---

# Approval Rule

A repository is approved only if:

* builds successfully
* tests pass
* interfaces documented
* contracts documented
* dependencies verified
* API stable

Only approved repositories may integrate into:

`os-platform`

---

# Forbidden Practices

Forbidden:

* hidden dependencies
* circular dependencies
* direct hardware access outside drivers
* direct driver → UI access
* undocumented APIs
* giant monolithic files

---

# Final Rule

Every repository must remain:

* modular
* testable
* independent
* maintainable

The system must scale cleanly.
