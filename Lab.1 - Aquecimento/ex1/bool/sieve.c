#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sieve.h"

struct sieve
{
    int N;
    bool *marked; // 0 = primo, 1 = não primo
};


Sieve* init_sieve(int N){

    // Inicialização da struct
    Sieve* s = (Sieve*) malloc(sizeof(Sieve));

    if (s == NULL) {
        printf("ERRO: Alocação do crivo falhou\n");
        return NULL;
    }

    s->N = N;

    s->marked = (bool*) malloc((N + 1) * sizeof(bool));

    if (s->marked == NULL) {
        free(s);
        printf("ERRO: Alocação do marked de marcados falhou\n");
        return NULL;
    }

    // Inicialmente, todos números são primos
    for (int i = 0; i <= N; i++) {
        s->marked[i] = 0;
    }

    if (N >= 0) s->marked[0] = 1;
    if (N >= 1) s->marked[1] = 1;

    return s;
}

void exec_sieve(Sieve* s) {

    // Começa em i = 2, o primeiro primo
    // i não deve exceder raiz de N
    for (int i = 2; i * i <= s->N; i++) {
        // Se marked[i] != '1', então é primo
        if (s->marked[i] == 0) {
            // Marcar todos o números na lista que são múltiplos de i
            for (int j = i * i; j <= s->N; j += i) {
                s->marked[j] = 1;
            }
        }
    }
}

void print_sieve(Sieve* s) {

    for (int i = 2; i <= s->N; i++) {
        if (s->marked[i] != 1)
            printf("%d\n", i);
    }
}

void destroy_sieve(Sieve** s) {

    if (s == NULL) return;
    free((*s)->marked);
    free(*s);
    s = NULL;
}