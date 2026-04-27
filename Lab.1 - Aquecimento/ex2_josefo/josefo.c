#include <stdio.h>
#include <stdlib.h>
#include "josefo.h"

typedef struct no {
    int idPessoa;    
    struct no *prox;
    struct no *ant;
} No;

struct Josefo
{
    No* cursor; // Ponteiro para a posição atual no círculo
    int N; // Qtd de pessoas no círculo
};

Josefo* iniciaJosefo (int N) {

    if (N < 1) return NULL;

    // Cria estrutura Josefo e inicializa

    Josefo* j = (Josefo*) malloc(sizeof(Josefo));

    if (j == NULL) {
        printf("ERRO: falha ao alocar estrutura Josefo\n");
        return NULL;
    }

    j->N = N;

    // Criar primeiro nó e apontar com o cursor

    j->cursor = (No*) malloc(sizeof(No));

    if (j->cursor == NULL) {
        printf("ERRO: falha ao alocar cursor\n");
        return NULL;
    }

    j->cursor->idPessoa = 1;
    No* anterior = j->cursor;

    // Inicializa os outros nós
    for (int i = 2; i <= N; i++) {
        No* novo = (No*) malloc(sizeof(No));
        novo->idPessoa = i;
        novo->ant = anterior;
        anterior->prox = novo;
        anterior = novo;
    }

    // Fechar o círculo de pessoas
    anterior->prox = j->cursor;
    j->cursor->ant = anterior;

    return j;
}

void execJosefo(Josefo* j, int M) {

    No* posAtual = j->cursor;

    for (int i = 0; i < j->N; i++) {
        for (int x = 1; x < M; x++) {
            posAtual = posAtual->prox;
        }

        posAtual->ant->prox = posAtual->prox;
        posAtual->prox->ant = posAtual->ant;
        printf("Eliminado: %d\n", posAtual->idPessoa);
        No* eliminado = posAtual;
        posAtual = posAtual->prox;

        free(eliminado);
    }
}

void limpaJosefo(Josefo** j) {

    if (*j == NULL) return;

    // Só deve sobrar um nó no final da simulação
    if ((*j)->cursor != NULL) {
        free((*j)->cursor);
    }

    free(*j);
    *j = NULL;
}
