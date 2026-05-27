# Build Rules

This document defines build system conventions.

Every repository must build consistently.

---

# Build Philosophy

Builds must be:

* reproducible
* isolated
* deterministic
* independent

Every repository must compile alone.

---

# Supported Languages

Allowed:

* C
* C++

Assembly allowed only for:

* boot
* CPU initialization
* architecture-specific logic

Avoid unnecessary language mixing.

---

# Compiler Standards

C standard:

```text
C11
```

C++ standard:

```text
C++20
```

---

# Required Compiler Flags

C:

```text
-ffreestanding
-fno-builtin
-fno-stack-protector
-Wall
-Wextra
-Werror
```

C++:

```text
-ffreestanding
-fno-exceptions
-fno-rtti
-Wall
-Wextra
-Werror
```

---

# Build Targets

Every Makefile must support:

## Build

```bash
make
```

Build module.

---

## Clean

```bash
make clean
```

Remove generated files.

---

## Test

```bash
make test
```

Run tests.

---

# Output Rules

Generated files must go into:

```text
build/
```

Never place build artifacts in source folders.

Forbidden:

```text
src/output.o
kernel.bin
```

Correct:

```text
build/output.o
build/kernel.bin
```

---

# Include Rules

Public headers:

```text
include/
```

Private headers:

```text
src/
```

Never expose private implementation headers.

---

# Architecture Separation

Architecture-specific code must live in:

```text
arch/x86/
arch/arm/
arch/riscv/
```

Never mix architecture code.

Forbidden:

```text
src/cpu_x86.c
```

Correct:

```text
arch/x86/cpu.c
```

---

# Testing Rule

Every repository must support tests.

Testing is mandatory before approval.

---

# Warnings Policy

Warnings are treated as errors.

Required:

```text
-Werror
```

No ignored warnings.

---

# Dependency Rule

Build dependencies must remain minimal.

Only approved dependencies allowed.

No accidental coupling.

---

# Final Rule

A repository must build successfully:

* alone
* repeatedly
* consistently

before approval.
