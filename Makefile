# EcoLogica/Makefile

CC = gcc
CFLAGS = -Wall -Iinclude
# Liste os arquivos que voce ja criou; adicione os outros conforme forem sendo implementados
SOURCES = \
    src/main.c \
    src/interface/menu.c \
    src/business/auth.c \
    src/utils.c \
    src/crypto/crypto.c \
    src/session.c \
    src/interface/funcionario_ui.c \
    src/business/funcionario_business.c \
    src/data/persistencia.c \
    src/interface/industria_ui.c \
    src/business/industria_business.c \
    src/interface/residuos_ui.c \
    src/business/residuos_business.c 
	
TARGET = ecologica

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
