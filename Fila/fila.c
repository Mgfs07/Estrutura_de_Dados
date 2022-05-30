#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "fila.h"

//inicia a fila
void iniciaFila(TFila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

//verifica se a fila esta vazia
int filaVazia(TFila f) {
    if (f.inicio == NULL)
        return 1;
    else
        return 0;
}


//funcao para inserir o elemento da Fila
//copio o nome que estava vindo para o ponteiro de novo
int insereFila(TFila *f, char nome[]) {
    TElemento *novo = (TElemento *) malloc(sizeof(TElemento));
    if (novo == NULL)
        return 0;
    else {
        strcpy(novo->nome, nome);
        novo->prox = NULL;
        novo->ant = f->fim;
        if (filaVazia(*f))
            f->inicio = novo;
        else
            f->fim->prox = novo;
        f->fim = novo;
        return 1;
    }
}


//remover a elemento da fila
char *removeFila(TFila *f) {
    char  * ret = (char *)malloc(30 * sizeof (char));
    TElemento *rem;
    if (filaVazia(*f))
        return NULL;
    else {
        strcpy(ret, f->inicio->nome);
        rem = f->inicio;
        f->inicio = f->inicio->prox;
        if (f->inicio == NULL)
            f->fim = NULL;
        else
            f->inicio->ant = NULL;
        free(rem);
        return ret;
    }
}

void imprimeFila(TFila f) {
    TElemento *atual;
    atual = f.inicio;
    printf("\n FILA ATUAL: \n");
    while (atual != NULL) {
        printf(" %s - ", atual->nome);
        atual = atual->prox;
    }
}


