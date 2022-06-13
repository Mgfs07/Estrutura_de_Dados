#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "listaContato.h"

void iniciaLista(TElementoContato ** arvore) {
    *arvore = NULL;
}

TElementoContato * consultarNome(TElementoContato * arvore, char * nome){
    if(arvore == NULL)
        return NULL;
    else if(strcmp(nome, arvore->nome) == 0)
        return arvore;
    else if(strcmp(nome, arvore->nome) > 0)
        return consultarNome(arvore->direita, nome);
    else
        return consultarNome(arvore->esquerda, nome);
}

TElementoContato * consultarNumero(TElementoContato * arvore, long numeroTelefone){
    if(arvore == NULL)
        return NULL;
    else if(arvore->telefone == numeroTelefone)
        return arvore;
    else if(numeroTelefone > arvore->telefone)
        return consultarNumero(arvore->direita, numeroTelefone);
    else
        return consultarNumero(arvore->esquerda, numeroTelefone);
}


int insereListaContato(TElementoContato ** arvore, char * nome, long numeroTelefone){
    if (consultarNome(*arvore, nome) == NULL){
        TElementoContato * novo = (TElementoContato *) malloc(sizeof (TElementoContato));
        novo->telefone = numeroTelefone;
        strcpy(novo->nome, nome);
        novo->esquerda = NULL;
        novo->direita = NULL;
        inserirNovo(arvore,novo);
        return 1;
    }else
        return 0;
}

void inserirNovo(TElementoContato ** arvore, TElementoContato * novo){
    if(*arvore == NULL)
        *arvore = novo;
    else{
        if (strcmp(novo->nome, (*arvore)->nome) > 0){
            ((*arvore)->direita == NULL) ? (*arvore)->direita = novo : inserirNovo(&(*arvore)->direita, novo);
        }else {
            ((*arvore)->esquerda == NULL) ? (*arvore)->esquerda = novo : inserirNovo(&(*arvore)->esquerda, novo);
        }
    }
}

void ordem(TElementoContato *raiz){
    if(raiz!=NULL){
        ordem((raiz)->esquerda);
        printf("\n\nNome = %s", (raiz)->nome);
        printf("\nTelefone = %ld", (raiz)->telefone);
        ordem((raiz)->direita);
    }
}
