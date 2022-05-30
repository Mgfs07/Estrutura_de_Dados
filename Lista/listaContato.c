#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "listaContato.h"

void iniciaLista(TListaContato * lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

TElementoContato * insereListaContato(TListaContato * lista, char * nome, long numeroTelefone){
    TElementoContato *novo = (TElementoContato *) malloc(sizeof(TElementoContato));
    TElementoContato * atual;
    strcpy(novo->nome, nome);
    novo->telefone = numeroTelefone;
    if(lista->inicio == NULL){
        novo->prox = NULL;
        lista->inicio = novo;
        lista->fim = novo;
        novo->ant = NULL;
    }else {
        atual = lista->inicio;
        while ((atual != NULL) && (strcmp(atual->nome, nome) < 0))
            atual = atual->prox;
        if (atual == lista->inicio) {
            novo->ant = NULL;
            novo->prox = atual;
            atual->ant = novo;
            lista->inicio = novo;
        } else if (atual == NULL) {
            novo->ant = lista->fim;
            novo->prox = NULL;
            lista->fim->prox = novo;
            lista->fim = novo;
        } else {
            novo->prox = atual;
            novo->ant = atual->ant;
            atual->ant->prox = novo;
            atual->ant = novo;
        }
    }
    return novo;

}

int listaVazia(TListaContato f) {
    if (f.inicio == NULL)
        return 1;
    else
        return 0;
}

int excluirContatoNome(TListaContato * lista, char * nome){
    TElementoContato *atual, *anterior;
    anterior = NULL;
    int excluido = 0;
    atual = buscarPorNome(*lista, nome);
    if(listaVazia(*lista) == 1){
        printf("FILA ESTA VAZIA, NAO PODE EXCLUIR NINGUEM");
    }else{
        if(atual){
            excluido = 1;
            anterior = atual->ant;
            if(anterior == NULL) lista->inicio = atual->prox;
            else anterior->prox = atual->prox;

            if(atual == lista->fim) lista->fim = NULL;
            free(atual);
        }
    }
    return excluido;
}

TElementoContato * buscarPorNome(TListaContato listaContato, char * nome){
    TElementoContato * atual;
    atual = listaContato.inicio;
    while ((atual != NULL) && (strcmp(nome,atual->nome)>0)) {
        atual = atual->prox;
    }
    if(atual != NULL && (strcmp(nome,atual->nome)==0)){
        return atual;
    }else{
        return NULL;
    }
}

TElementoContato * buscarNumero(TListaContato listaContato, long telefone){
    TElementoContato * atual;
    atual = listaContato.inicio;
    while ((atual != NULL) && (atual->telefone != telefone)){
        atual = atual->prox;
    }
    if(atual != NULL && atual->telefone == telefone){
        return atual;
    }else{
        return NULL;
    }
}

void listarTodos(TListaContato *lista){
    TElementoContato * atual;
    atual = lista->inicio;
    while (atual != NULL){
        printf("\n\nNome -> %s", atual->nome);
        printf("\n\nTelefone -> %ld,", atual->telefone);
        atual = atual->prox;
        printf("\n\n=================\n\n");
    }
}