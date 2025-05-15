# Definición de variables
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC_DIR = src
OBJ_DIR = obj

FILE_MAIN=tests/test

# Regla para encontrar todos los archivos fuente
SRCS = $(wildcard $(SRC_DIR)/*/*.c)

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

OBJ_NAMES = $(notdir $(OBJS))
FILE_MAIN_NAME = $(notdir $(FILE_MAIN))

ejecutar:
	$(CC) -c $(SRCS) $(FILE_MAIN).c
	$(CC) -o out $(OBJ_NAMES) $(FILE_MAIN_NAME).o
	rm *.o
	./out