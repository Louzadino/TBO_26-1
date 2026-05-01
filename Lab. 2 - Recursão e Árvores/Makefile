# Nome do compilador
CC = gcc

# Flags do compilador (avisos e informações de debug)
# A flag -g já está aqui e é essencial para o valgrind mostrar a linha exata dos erros
CFLAGS = -Wall -Wextra -g -std=c11

# Nome do arquivo executável a ser gerado
TARGET = main

# Arquivos fonte (.c) necessários para este programa
SOURCES = main.c bst.c

# Declara os alvos que não representam arquivos reais
.PHONY: all clean val

# Regra padrão: compila o programa principal
all: $(TARGET)

# Regra para criar o executável final
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# Regra para executar o valgrind
val: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

# Regra para limpar os arquivos gerados (executável)
clean:
	rm -f $(TARGET)