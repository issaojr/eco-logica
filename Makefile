# Makefile cross-platform (GNU make apenas)

CC      := gcc
CFLAGS  := -Wall -Iinclude -std=c99 -pedantic

SRC_DIR := src
OBJ_DIR := out
BUILD_DIR := build

# Função recursiva para listar arquivos .c
rwildcard = \
  $(foreach p,$(wildcard $1*),\
    $(filter %.$2,$(p)) \
    $(call rwildcard,$(p)/,$2))

SRCS := $(call rwildcard,$(SRC_DIR)/,c)
# Substitui o diretório src/ por out/ e adiciona a extensão .o
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
TARGET := $(BUILD_DIR)/ecologica

.PHONY: all clean cleanall

all: $(TARGET)

$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

# Regra adicional para limpar tudo (objetos e executável)
cleanall:
	rm -rf $(OBJ_DIR) $(BUILD_DIR)
