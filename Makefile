CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
BUILD_DIR = bin
SRC_DIR = src
TEST_DIR = test

# Tüm kaynak kodlarını tek satırda tanımla
SOURCES = $(SRC_DIR)/book_management.c $(SRC_DIR)/library.c
TEST_SOURCES = $(TEST_DIR)/main.c

OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))
TEST_OBJECTS = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%.o, $(TEST_SOURCES))

TARGET = $(BUILD_DIR)/app

.PHONY: all clean test

all: $(TARGET)

# bin klasörünün var olduğundan emin ol
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Kütüphane kaynak kodlarını derle
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Test programını derle ve kütüphane nesneleriyle bağla
$(TARGET): $(OBJECTS) $(BUILD_DIR)/main.o
	$(CC) $(CFLAGS) $(OBJECTS) $(BUILD_DIR)/main.o -o $@

# Test dosyasını derle
$(BUILD_DIR)/main.o: $(TEST_SOURCES) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TARGET)
	@echo "--- Programı Çalıştırılıyor ---"
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)
