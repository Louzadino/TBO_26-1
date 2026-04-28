#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "merge_sort.h"
#include "item.h"

extern void sort(Item* a, int lo, int hi);

int main(int argc, char** argv) {

    // Receber número N de itens a serem ordenados
    int N = atoi(argv[1]);

    // Alocação do array de itens
    Item* itens = (Item*) calloc(N, sizeof(Item));
    if (!itens) {
        printf("Falha na alocação do array de itens\n");
        return 1;
    }

    int erro = 0;

    // Leitura dos N valores
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &itens[i]) != 1) {
            erro = 1;
            break;
        }   
    }

    // Se não houve erro na leitura dos valores, executa o algoritmo
    if (!erro) {
        // 4. Exec da ordenação e medição do tempo
        clock_t start, end;
        double tempo_cpu;

        start = clock();
        sort(itens, 0, N - 1);
        end = clock();
        tempo_cpu = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Ordenação: %f segundos\n", tempo_cpu);

        // 5. Print do array ordenado
        /*
        printf("Depois da ordenação: \n");
        for (int i = 0; i < N; i++) {
            printf("%d ", itens[i]);
            printf("\n");
        }
        */
    }

    // 6. Liberar memória do array
    if (itens) free(itens);
}