#include <stdio.h>
#include <stdlib.h>
#include "sieve.h"

int main(int argc, char *argv[]) {
    // Verifica se o parâmetro N foi fornecido na execução
    if (argc != 2) {
        fprintf(stderr, "Uso correto: %s <N>\n", argv[0]);
        return 1;
    }

    // Converte o parâmetro (que chega como texto) para inteiro
    int N = atoi(argv[1]);

    // Validação básica (o menor primo é 2)
    if (N < 2) {
        fprintf(stderr, "O valor de N deve ser maior ou igual a 2.\n");
        return 1;
    }

    // Inicializa o crivo
    Sieve* s = init_sieve(N);
    
    // Boa prática: verificar se a alocação de memória falhou
    if (s == NULL) {
        fprintf(stderr, "Erro de alocação de memória para N = %d.\n", N);
        return 1;
    }

    // Executa a busca pelos primos
    exec_sieve(s);

    //print_sieve(s); // Mantido comentado para os testes de tempo/memória

    // Libera a memória
    destroy_sieve(&s);

    return 0;
}