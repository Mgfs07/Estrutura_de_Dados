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
TElementoContato * buscarPorNome(TElementoContato arvore, char * nome);
//
TElementoContato * buscarNumero(TElementoContato listaContato, long telefone);
//
TElementoContato * insereListaContato(TElementoContato * lista, char * nome, long numeroTelefone);
//
int excluirContatoNome(TElementoContato * lista, char * nome);
//
void listarTodos(TElementoContato *lista);

#endif //LISTA_H
