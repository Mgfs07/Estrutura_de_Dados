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
    printf("CONTATO ADICIONADO COM SUCESSO");
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

TElementoContato *menorEsquerda(TElementoContato **no){
    if((*no)->direita != NULL)
        return menorEsquerda(&(*no)->esquerda);
    else{
        TElementoContato *aux = *no;
        if((*no)->direita != NULL)
            *no = (*no)->direita;
        else
            *no = NULL;
        return aux;
    }
}

void remover(TElementoContato **pRaiz, char * nome){
    TElementoContato * contato;
    contato = consultarNome(*pRaiz, nome);
    if((*pRaiz == NULL) || (contato == NULL)){
        printf("Numero nao existe na arvore!");
        return;
    }
//    if(strcmp(nome,(*pRaiz)->nome) < 0)
//        remover(&(*pRaiz)->esquerda, nome);
//    else
//    if(strcmp(nome,(*pRaiz)->nome) > 0)
//        remover(&(*pRaiz)->direita, nome);
    else{
        TElementoContato *pAux = *pRaiz;
        if (((*pRaiz)->esquerda == NULL) && ((*pRaiz)->direita == NULL)){
            free(pAux);
            (*pRaiz) = NULL;
        }
        else{
            if ((*pRaiz)->esquerda == NULL){
                (*pRaiz) = (*pRaiz)->direita;
                pAux->direita = NULL;
                free(pAux);
                pAux = NULL;
            }
            else{
                if ((*pRaiz)->direita == NULL){
                    (*pRaiz) = (*pRaiz)->esquerda;
                    pAux->esquerda = NULL;
                    free(pAux);
                    pAux = NULL;
                }
                else{
                    pAux = maiorDireita(&(*pRaiz)->esquerda);
                    pAux->esquerda = (*pRaiz)->esquerda;
                    pAux->direita = (*pRaiz)->direita;
                    (*pRaiz)->esquerda = (*pRaiz)->direita = NULL;
                    free((*pRaiz));
                    *pRaiz = pAux;
                    pAux = NULL;
                }
            }
        }
    }
}
