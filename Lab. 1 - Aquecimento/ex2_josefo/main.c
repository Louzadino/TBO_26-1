#include <stdio.h>
#include <stdlib.h>
#include "josefo.h"

int main() {    

    int N, M;

    scanf("%d %d", &N, &M);

    Josefo* j = iniciaJosefo(N);
    if (j == NULL) {
        printf("Falha ao criar problema de josefo");
        return 0;
    }

    execJosefo(j, M);
    limpaJosefo(&j);

    return 0;
}
