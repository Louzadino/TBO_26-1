# Nome do compilador
CC = gcc

# Flags do compilador (avisos e informações de debug)
CFLAGS = -Wall -Wextra -g -std=c11

# Nome do arquivo executável a ser gerado
TARGET = main

# Arquivos fonte (.c) necessários para este programa
SOURCES = main.c merge_sort.c

# Regra padrão: compila o programa principal
all: $(TARGET)

# Regra para criar o executável final
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# Regra para limpar os arquivos gerados (executável)
clean:
	rm -f $(TARGET)