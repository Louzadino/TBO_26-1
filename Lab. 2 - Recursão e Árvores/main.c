#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "bst.h"

int main(int argc, char *argv[]) {

    // Criação da árvore
    if (argc != 2) printf("ERRO: argumentos do programa incorretos\n");

    BST* bst = create_bst();

    // Leitura da entrada de N chaves aleatórias
    int N = atoi(argv[1]);

    srand(time(NULL));
    
    for (int i = 0; i < N; i++) {
        int new_key = rand();
        Node* new_node = create_node(new_key);
        insert_bst(bst, new_node);
    }

    printf("%d\n", bst_height(bst_root(bst)));
    
    destroy_bst(bst);

    return 0;
}
