#ifndef PILHADINAMICA_PILHA_H
#define PILHADINAMICA_PILHA_H

#define MAX 20

typedef struct {
    int itens[MAX];
    int topo;
} TPilha;

void inicializarPilha (TPilha *p);

int pilhaVazia(TPilha *p);

int pilhaCheia(TPilha *p);

int empilha(TPilha *p, int elemento);

int desempilha(TPilha *p, int *elemento);

#endif //PILHADINAMICA_PILHA_H
