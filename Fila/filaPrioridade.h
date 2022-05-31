#ifndef FILA_FILAPRIORIDADE_H
#define FILA_FILAPRIORIDADE_H

#include "fila.h"
#include "filaPrioridade.h"

//struct fila de prioridade que vai armazenar os ages e o vetor de filas
typedef struct filaPrioridade{
    int quantidadePrioridade;
    TFila * filas;
    int * ages;
    int maxAge;
}TFilaPrioridade;

//inicia a fila de prioridade
void iniciaFilaPrioridades (TFilaPrioridade *f, int quantidadePrioridade, int maxAge);

//insere na fila de prioridade
int insereFilaPrioridades (TFilaPrioridade *f, char nome[], int prioridade);

//remove da fila de prioridade
char * removeFilaPrioridades (TFilaPrioridade *f);

//imprime a fila de prioridade
void imprimeFilaPrioridades (TFilaPrioridade f);

#endif //FILA_FILAPRIORIDADE_H
