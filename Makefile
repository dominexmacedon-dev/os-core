CC=gcc

CFLAGS=-std=c11 -Wall -Wextra -Werror -ffreestanding -nostdlib

INCLUDES=-Ishared -Icontracts -Iinterfaces -Iregistry

BUILD_DIR=build

TARGET=$(BUILD_DIR)/os_core_test

# Source files
SRC=registry/module_registry.c registry/start.c

# Object files (auto-generated in build/)
OBJ=$(SRC:registry/%.c=$(BUILD_DIR)/%.o)

all: prepare $(TARGET)

prepare:
	mkdir -p $(BUILD_DIR)

# Compile any registry/*.c into build/*.o
$(BUILD_DIR)/%.o: registry/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Link all objects
$(TARGET): $(OBJ)
	$(CC) -nostdlib -o $@ $^

clean:
	rm -rf $(BUILD_DIR)

check:
	@echo "Checking file structure..."
	@test -f shared/types.h || echo "MISSING shared/types.h"
	@test -f shared/status.h || echo "MISSING shared/status.h"
	@test -f shared/config.h || echo "MISSING shared/config.h"
	@test -f shared/version.h || echo "MISSING shared/version.h"
	@test -f contracts/module_contract.h || echo "MISSING contracts/module_contract.h"
	@test -f contracts/hal_contract.h || echo "MISSING contracts/hal_contract.h"
	@test -f contracts/driver_contract.h || echo "MISSING contracts/driver_contract.h"
	@test -f contracts/service_contract.h || echo "MISSING contracts/service_contract.h"
	@test -f registry/module_registry.h || echo "MISSING registry/module_registry.h"
	@test -f registry/module_registry.c || echo "MISSING registry/module_registry.c"
	@test -f registry/start.c || echo "MISSING registry/start.c"
	@echo "OK: structure valid"

test: all
	@echo "OK: build successful"

validate: check test
	@echo "ALL OK: os-core ready"