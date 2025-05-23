CC = gcc
CFLAGS = -O2 -Wall -W -std=c99
LDFLAGS =
LDLIBS =
SRC = src
BUILD = bin

# Find all .c file paths in the source directory
SRCS = $(wildcard $(SRC)/*.c)
# Transform source file paths to target binaries
# Example: src/hello.c becomes build/hello
TGTS = $(SRCS:$(SRC)/%.c=$(BUILD)/%)

all: $(TGTS)

# Single-file build
# @ suppresses command output
# $@ refers to the target name (binary file)
# $< refers to the first prerequisite (the .c file)
$(BUILD)/%: $(SRC)/%.c
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

.PHONY: all clean

clean:
	@rm -rf $(BUILD)
