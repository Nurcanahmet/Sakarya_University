# Derleme ayarları
CC = gcc
CFLAGS = -Wall -Werror -g

# Proje dosyalarının isimleri
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Kaynak dosyalar ve hedef dosyalar
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/shell.c
OBJECTS = $(OBJ_DIR)/main.o $(OBJ_DIR)/shell.o
TARGET = $(BIN_DIR)/shell

# Varsayılan hedef: shell'i derle
all: $(TARGET)

# Derleme kuralı
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Objeleri derlemek için kural
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Temizleme kuralı
clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/$(TARGET)

# Klasörler oluşturma kuralı
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)


