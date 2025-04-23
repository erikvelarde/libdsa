CC = gcc
INCLUDES = -Iinclude
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c11 $(INCLUDES)
TARGET = libdsa

SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

all: directories $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

directories:
	@mkdir -p $(SRC_DIR) $(OBJ_DIR) $(INCLUDE_DIR)/libdsa

.PHONY: all clean directories run
