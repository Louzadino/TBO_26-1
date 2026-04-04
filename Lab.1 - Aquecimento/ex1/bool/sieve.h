#ifndef SIEVE_H
#define SIEVE_H

typedef struct sieve Sieve;

Sieve* init_sieve(int N);

void exec_sieve(Sieve* s);

void print_sieve(Sieve* s);

void destroy_sieve(Sieve** s);

#endif