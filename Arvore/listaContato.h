#ifndef LISTA_H
#define LISTA_H

#define TAMANHO 40

typedef struct elementoContato{
    char nome[40];
    long telefone;
    struct elementoContato * direita, *esquerda;
}TElementoContato;

//OK
void iniciaLista(TElementoContato ** arvore);
//
int insereListaContato(TElementoContato ** raiz, char nome, long numeroTelefone);
//
void inserirNovo(TElementoContato ** arvore, TElementoContato * novo);

#endif //LISTA_H
