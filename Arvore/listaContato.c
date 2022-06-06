#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "listaContato.h"

void iniciaLista(TElementoContato ** arvore) {
    *arvore = NULL;
}

//TElementoContato * insereListaContato(TElementoContato * lista, char * nome, long numeroTelefone){
//    TElementoContato *novo = (TElementoContato *) malloc(sizeof(TElementoContato));
//    TElementoContato * atual;
//    strcpy(novo->nome, nome);
//    novo->telefone = numeroTelefone;
//    if(lista->inicio == NULL){
//        novo->direita = NULL;
//        lista->inicio = novo;
//        lista->fim = novo;
//        novo->esquerda = NULL;
//    }else {
//        atual = lista->inicio;
//        while ((atual != NULL) && (strcmp(atual->nome, nome) < 0))
//            atual = atual->direita;
//        if (atual == lista->inicio) {
//            novo->esquerda = NULL;
//            novo->direita = atual;
//            atual->esquerda = novo;
//            lista->inicio = novo;
//        } else if (atual == NULL) {
//            novo->esquerda = lista->fim;
//            novo->direita = NULL;
//            lista->fim->direita = novo;
//            lista->fim = novo;
//        } else {
//            novo->direita = atual;
//            novo->esquerda = atual->esquerda;
//            atual->esquerda->direita = novo;
//            atual->esquerda = novo;
//        }
//    }
//    return novo;
//
//}
//
//int listaVazia(TElementoContato f) {
//    if (f.inicio == NULL)
//        return 1;
//    else
//        return 0;
//}
//
////metodo de excluir o contato
//int excluirContatoNome(TListaContato * lista, char * nome){
//    TElementoContato *atual, *anterior;
//    anterior = NULL;
//    int excluido = 0;
//    atual = buscarPorNome(*lista, nome);
//    if(listaVazia(*lista) == 1){
//        printf("FILA ESTA VAZIA, NAO PODE EXCLUIR NINGUEM");
//    }else{
//        if(atual){
//            excluido = 1;
//            anterior = atual->esquerda;
//            if(anterior == NULL) lista->inicio = atual->direita;
//            else anterior->direita = atual->direita;
//
//            if(atual == lista->fim) lista->fim = NULL;
//            free(atual);
//        }
//    }
//    return excluido;
//}
//
//TElementoContato * buscarPorNome(TListaContato arvore, char * nome){
//    TElementoContato * atual;
//    atual = arvore.inicio;
//    while ((atual != NULL) && (strcmp(nome,atual->nome)>0)) {
//        atual = atual->direita;
//    }
//    if(atual != NULL && (strcmp(nome,atual->nome)==0)){
//        return atual;
//    }else{
//        return NULL;
//    }
//}
//
//TElementoContato * buscarNumero(TListaContato listaContato, long telefone){
//    TElementoContato * atual;
//    atual = listaContato.inicio;
//    while ((atual != NULL) && (atual->telefone != telefone)){
//        atual = atual->direita;
//    }
//    if(atual != NULL && atual->telefone == telefone){
//        return atual;
//    }else{
//        return NULL;
//    }
//}
//
//void listarTodos(TListaContato *lista){
//    TElementoContato * atual;
//    atual = lista->inicio;
//    while (atual != NULL){
//        printf("\n\nNome -> %s", atual->nome);
//        printf("\n\nTelefone -> %ld,", atual->telefone);
//        atual = atual->direita;
//        printf("\n\n=================\n\n");
//    }
//}