# Compiler and flags
CC := gcc
CFLAGS := -std=c17 -O3 -Wall -Werror

# Directories
SRC_DIR := src
TEST_DIR := test

# Targets
TEST_TARGET := run_tests

# Source files
SRC_FILES := $(shell find $(SRC_DIR) -name '*.c')
TEST_FILES := $(filter-out $(TEST_DIR)/test_large.c, $(shell find $(TEST_DIR) -name '*.c'))


.PHONY: all build_test test

all: test

build_test: $(TEST_FILES) $(SRC_FILES)
	$(CC) $(CFLAGS) -g $^ -o $(TEST_TARGET)
	@echo "✅ compiled $(TEST_TARGET)"

test: build_test
	./$(TEST_TARGET)
	@echo "✅ ran tests"

