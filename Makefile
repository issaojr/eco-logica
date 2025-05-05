# Makefile cross-platform (GNU make apenas)

CC      := gcc
CFLAGS  := -Wall -Iinclude

SRC_DIR := src

# Função recursiva para listar arquivos .c
rwildcard = \
  $(foreach p,$(wildcard $1*),\
    $(filter %.$2,$(p)) \
    $(call rwildcard,$(p)/,$2))

SRCS := $(call rwildcard,$(SRC_DIR)/,c)
OBJS := $(SRCS:.c=.o)
TARGET := ecologica

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
