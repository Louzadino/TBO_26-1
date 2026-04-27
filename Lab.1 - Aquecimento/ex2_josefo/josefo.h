#ifndef JOSEFO_H
#define JOSEFO_H

typedef struct Josefo Josefo;

Josefo* iniciaJosefo (int N);

void execJosefo(Josefo* j, int M);

void limpaJosefo(Josefo** j);

#endif