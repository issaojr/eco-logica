# Makefile cross-platform (GNU make apenas)

CC      := gcc
CFLAGS  := -Wall -Iinclude -std=c99 -pedantic

SRC_DIR := src
OBJ_DIR := out
BUILD_DIR := build
TEST_DIR := $(BUILD_DIR)/tests

# Função recursiva para listar arquivos .c
rwildcard = \
  $(foreach p,$(wildcard $1*),\
    $(filter %.$2,$(p)) \
    $(call rwildcard,$(p)/,$2))

# Fontes principais (excluindo arquivos de teste)
SRCS := $(filter-out $(SRC_DIR)/testes/%.c,$(call rwildcard,$(SRC_DIR)/,c))
# Substitui o diretório src/ por out/ e adiciona a extensão .o
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
TARGET := $(BUILD_DIR)/ecologica

# Fontes e objetos de testes
TEST_SRCS := $(call rwildcard,$(SRC_DIR)/testes/,c)
TEST_OBJS := $(patsubst $(SRC_DIR)/testes/%.c,$(OBJ_DIR)/testes/%.o,$(TEST_SRCS))
TEST_TARGETS := $(patsubst $(SRC_DIR)/testes/%.c,$(TEST_DIR)/%,$(TEST_SRCS))

.PHONY: all clean cleanall test

all: $(TARGET)

test: $(TEST_TARGETS)

$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# Regra para compilar os testes (exclui main.c)
$(TEST_DIR)/%: $(OBJ_DIR)/testes/%.o $(filter-out $(OBJ_DIR)/main.o,$(OBJS)) | $(TEST_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(TEST_DIR):
	@mkdir -p $(TEST_DIR)

clean:
	rm -rf $(OBJ_DIR)

# Regra adicional para limpar tudo (objetos e executável)
cleanall:
	rm -rf $(OBJ_DIR) $(BUILD_DIR)
