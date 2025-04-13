# EcoLogica/Makefile

CC = gcc
CFLAGS = -Wall -Iinclude
# Liste os arquivos que você já criou; adicione os outros conforme forem sendo implementados
SOURCES = src/main.c src/interface/menu.c src/business/auth.c
TARGET = ecologica

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
