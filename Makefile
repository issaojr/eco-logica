# EcoLogica/Makefile

CC = gcc
CFLAGS = -Wall -Iinclude
# Liste os arquivos que voce ja criou; adicione os outros conforme forem sendo implementados
SOURCES = \
    src/main.c \
    src/interface/menu_ui.c \
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
    src/business/residuos_business.c \
    src/interface/relatorios_ui.c \
    src/business/relatorios_business.c \
    src/interface/login_ui.c \
    src/interface/logged_user_ui.c \
    src/interface/screen_title_ui.c \
    src/strings_globais.c \
    src/interface/info_dialog_ui.c
	
TARGET = ecologica

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
