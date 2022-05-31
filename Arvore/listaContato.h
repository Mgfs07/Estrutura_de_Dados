#ifndef LISTA_H
#define LISTA_H

#define TAMANHO 40

typedef struct elementoContato{
    char nome[40];
    long telefone;
    struct elementoContato * prox, *ant;
}TElementoContato;


typedef struct listaContato{
    TElementoContato *inicio, *fim;
} TListaContato;


void iniciaLista(TListaContato * lista);
TElementoContato * buscarPorNome(TListaContato listaContato, char * nome);
TElementoContato * buscarNumero(TListaContato listaContato, long telefone);
TElementoContato * insereListaContato(TListaContato * lista, char * nome, long numeroTelefone);
int excluirContatoNome(TListaContato * lista, char * nome);
void listarTodos(TListaContato *lista);

#endif //LISTA_H
