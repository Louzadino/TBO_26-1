#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "sieve.h"

#define BYTE 8
#define set_bit(a, n)     (a[n/BYTE] |= (1U << (n % BYTE)))
#define is_set(a, n)  ((a[n/BYTE] >> (n % BYTE)) & 1U)

struct sieve
{
    int N;
    unsigned char* marked; // 0 = primo, 1 = não primo
};


Sieve* init_sieve(int N){

    // Inicialização da struct
    Sieve* s = (Sieve*) malloc(sizeof(Sieve));

    if (s == NULL) {
        printf("ERRO: Alocação do crivo falhou\n");
        return NULL;
    }

    s->N = N;

    // Calcula o numero de bytes necessarios para armazenar N+1 bits.
    // Adicionamos 1 para garantir que o ultimo bit N caiba.
    size_t tamanho_em_bytes = (N / BYTE) + 1;

    s->marked = (unsigned char*) calloc(tamanho_em_bytes, sizeof(unsigned char));

    if (s->marked == NULL) {
        free(s);
        printf("ERRO: Alocação do marked de marcados falhou\n");
        return NULL;
    }

    return s;
}

void exec_sieve(Sieve* s) {

    // Começa em i = 2, o primeiro primo
    // i não deve exceder raiz de N
    for (int i = 2; i * i <= s->N; i++) {
        // Se marked[i] != '1', então é primo
        if (!is_set(s->marked, i)) {
            // Marcar todos o números na lista que são múltiplos de i
            for (int j = i * i; j <= s->N; j += i) {
                set_bit(s->marked, j);
            }
        }
    }
}

void print_sieve(Sieve* s) {

    for (int i = 2; i <= s->N; i++) {
        if (!is_set(s->marked, i))
            printf("%d\n", i);
    }
}

void destroy_sieve(Sieve** s) {

    if (s == NULL) return;
    free((*s)->marked);
    free(*s);
    s = NULL;
}