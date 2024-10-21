SRC_DIR := src
OUT_DIR := target

CFLAGS := -Wall -Wextra -I$(SRC_DIR)

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)

# todo make incremental builds
OBJ_FILES := $(patsubst $(SRC_DIR)%, $(OUT_DIR)%, $(SRC_FILES:c=o))

.PHONY: build run

run: build
	./$(OUT_DIR)/main

build: 
	gcc $(CFLAGS) $(SRC_FILES) -o $(OUT_DIR)/main
