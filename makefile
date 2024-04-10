all: sis_estoque

CC = clang
CFLAGS = -g -Wno-everything -pthread -lm

# Diretórios para código-fonte, cabeçalhos e binários
SRC_DIR = src
INCLUDE_DIR = includes
BIN_DIR = bin

# Lista de arquivos de origem e cabeçalhos
SRCS = $(wildcard $(SRC_DIR)/*.c)
HEADERS = $(wildcard $(INCLUDE_DIR)/*.h)

sis_estoque: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRCS) -o $(BIN_DIR)/$@

main-debug: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -O0 -I$(INCLUDE_DIR) $(SRCS) -o $(BIN_DIR)/$@

clean:
	rm -f $(BIN_DIR)/sis_estoque $(BIN_DIR)/main-debug
