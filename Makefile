# Makefile para EcoLogica - com executável em bin/

CC      := gcc
CFLAGS  := -Wall -Iinclude -std=c99 -pedantic -finput-charset=UTF-8

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# Função recursiva para listar arquivos .c
rwildcard = \
  $(foreach p,$(wildcard $1*),\
    $(filter %.$2,$(p)) \
    $(call rwildcard,$(p)/,$2))

# Fontes e objetos
SRCS := $(call rwildcard,$(SRC_DIR)/,c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
TARGET := $(BIN_DIR)/ecologica

.PHONY: all clean cleanall

# Compilação principal
all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@
	@mkdir -p $(BIN_DIR)/dados

# Compilação de objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Diretórios
$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Limpeza
clean:
	@rm -f $(OBJS)

cleanall: clean
	@rm -f $(BIN_DIR)/ecologica
