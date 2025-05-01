# EcoLogica/Makefile

CC = gcc
CFLAGS = -Wall -Iinclude

# Fontes agrupadas por diret�rio
SRC = $(wildcard src/*.c src/ui/*.c src/business/*.c src/crypto/*.c src/persistencia/*.c src/estados/*.c)
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
