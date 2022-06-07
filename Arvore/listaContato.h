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
//OK
TElementoContato * consultarNome(TElementoContato *  arvore, char * nome);
//OK
TElementoContato * consultarNumero(TElementoContato *  arvore, long numeroTelefone);
//OK
int insereListaContato(TElementoContato ** raiz, char * nome, long numeroTelefone);
//OK
void inserirNovo(TElementoContato ** arvore, TElementoContato * novo);

#endif //LISTA_H
