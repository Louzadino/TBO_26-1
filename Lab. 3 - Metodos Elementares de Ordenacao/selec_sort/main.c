#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"

extern void sort(Item *a, int lo, int hi);

int main(int argc, char** argv) {
    int N = atoi(argv[1]);

    // Alocação do array de itens
    Item* itens = (Item*) calloc(N, sizeof(Item));
    if (!itens) {
        printf("ERRO na alocação do itens\n");
        return 1;
    }

    int erro = 0;

    for (int i = 0; i < N; i++) {
        if (scanf("%d", &itens[i]) != 1) {
            erro = 1;
            break;
        }
    }

    // Se não ocorrer nenhum erro na leitura, faz a ordenação e calcula tempo
    if (!erro) {
        clock_t start, end;
        double cpu_time;

        start = clock();
        sort(itens, 0, N - 1);
        end = clock();
        cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Ordenação: %f segundos\n", cpu_time);

        /*
        for (int i = 0; i < N; i++) {
            printf("%d", itens[i]);
            printf("\n");
        }
            */
    }

    // Libera array de itens
    if (itens) free(itens);
}