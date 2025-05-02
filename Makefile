# EcoLogica/Makefile

CC = gcc
CFLAGS = -Wall -Iinclude

# Fontes agrupadas por diret�rio
STATE_SRC := $(wildcard src/estados/*.c)
FILTERED_STATE_SRC := $(filter-out \
    src/estados/estado_listar_funcionarios.c \
    src/estados/estado_adicionar_funcionario.c \
    src/estados/estado_editar_funcionario.c \
    src/estados/estado_excluir_funcionario.c, \
    $(STATE_SRC))
SRC := $(wildcard src/*.c src/ui/*.c src/business/*.c src/crypto/*.c src/persistencia/*.c) $(FILTERED_STATE_SRC)
OBJ = $(SRC:.c=.o)
TARGET = ecologica

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

# Regra gen�rica para compila��o de objetos
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

# Regra para criar diret�rios se n�o existirem
directories:
	@mkdir -p src/ui
	@mkdir -p include/ui
