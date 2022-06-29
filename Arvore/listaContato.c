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


TElementoContato * consultarNumero(TElementoContato * raiz, long numeroTelefone){
    if(raiz == NULL)
        return NULL;
    else if(raiz->telefone == numeroTelefone)
        return raiz;
    else{
        TElementoContato * elemento = consultarNumero(raiz->esquerda, numeroTelefone);
        if (elemento != NULL)
            return elemento;
        else
            return consultarNumero(raiz->direita, numeroTelefone);
    }
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


TElementoContato *maiorDireita(TElementoContato **no){
    if((*no)->direita != NULL)
        return maiorDireita(&(*no)->direita);
    else{
        TElementoContato *aux = *no;
        if((*no)->esquerda != NULL)
            *no = (*no)->esquerda;
        else
            *no = NULL;
        return aux;
    }
}

int remover(TElementoContato **pRaiz, char * nome) {
    TElementoContato * excluir;
    if(*pRaiz != NULL){
        if(strcmp((*pRaiz)->nome, nome) == 0){
            excluir = *pRaiz;
            if((*pRaiz)->esquerda == NULL){
                *pRaiz = (*pRaiz)->direita;
            }else if((*pRaiz)->direita == NULL){
                *pRaiz = (*pRaiz)->esquerda;
            }else{
                excluir = maiorDireita(&(*pRaiz)->esquerda);
                strcpy((*pRaiz)->nome, excluir->nome);
                (*pRaiz)->telefone = excluir->telefone;
            }
            free(excluir);
            return 1;
        }
        else if(strcmp(nome,(*pRaiz)->nome) < 0){
            return remover(&(*pRaiz)->esquerda, nome);
        } else
            return remover(&(*pRaiz)->direita, nome);

    } else
        return 0;
}
