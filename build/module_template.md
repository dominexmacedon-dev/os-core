# Module Template

Every future repository must follow this template.

Purpose:

Maintain consistency across all modules.

---

# Standard Repository Layout

```text
module-name/
│
├── include/
│   └── public_api.h
│
├── src/
│   ├── module.c
│   └── internal.h
│
├── tests/
│   └── module_tests.c
│
├── docs/
│   ├── architecture.md
│   └── contracts.md
│
├── examples/
│   └── example.c
│
├── build/
│
├── Makefile
└── README.md
```

---

# README.md

Must include:

* purpose
* responsibilities
* dependencies
* public APIs
* build instructions
* examples

---

# include/

Contains:

Public headers only.

Examples:

```text
memory.h
scheduler.h
hal_display.h
```

---

# src/

Contains:

Implementation.

Examples:

```text
memory.c
scheduler.c
```

Private headers stay here.

---

# tests/

Contains:

Unit tests.

Required for approval.

---

# docs/

Contains:

* architecture
* contracts
* implementation notes

---

# examples/

Contains:

Minimal usage examples.

---

# Makefile

Must support:

```bash
make
make clean
make test
```

---

# Example Modules

## os-memory

Responsibilities:

* heap
* paging
* allocator

Example:

```text
os-memory/
├── include/
├── src/
├── tests/
├── docs/
└── Makefile
```

---

## os-kernel

Responsibilities:

* scheduler
* panic system
* timers

---

## os-hal

Responsibilities:

* hardware abstraction
* display
* audio
* input

---

## os-drivers

Responsibilities:

* keyboard
* storage
* GPU
* network

---

# Approval Checklist

Before approval:

* builds successfully
* tests pass
* APIs documented
* contracts documented
* follows coding rules
* dependency-safe

---

# Final Rule

Every module must look structurally similar.

Consistency enables scaling.
