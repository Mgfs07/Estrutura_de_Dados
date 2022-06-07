#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "listaContato.h"


//metodo para iniciar a Lista setando os valores do inicio e do fim como nulos
void iniciaLista(TListaContato *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

/*
 * Metodo para inserir um contato na lista
 * eu começo criando um elemento para ser o meu novo fazendo um malloc nele. e crio um atual do tipo TElemento
 * copio o nome e o telefone que estou passando na funcao para o meu elemento novo, e verifico primeiro se o inicio da lista
 * esta null, se caso ela estiver o proximo do novo recebe nulo pois ainda nao tem proximo, o inicio da lista recebe o meu
 * elemento novo e o fim tambem, e o anterior do novo recebe um nulo pois ele é o primeiro.
 *      o meu atual vai receber o inicio da lista e coloco ele em um laço para verificar os nome, pois a minha lista ela já
 * insere na ordem alfabética, eu possuo 3 cenarios, um se o atual é o inicio no fim e no meio;
 */
TElementoContato *insereListaContato(TListaContato *lista, char *nome, long numeroTelefone) {
    TElementoContato *novo = (TElementoContato *) malloc(sizeof(TElementoContato));
    TElementoContato *atual;
    strcpy(novo->nome, nome);
    novo->telefone = numeroTelefone;
    if (lista->inicio == NULL) {
        novo->prox = NULL;
        lista->inicio = novo;
        lista->fim = novo;
        novo->ant = NULL;
    } else {
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

//metodo para verificar se a lista esta vazia verificando se o inicio esta nulo
int listaVazia(TListaContato f) {
    if (f.inicio == NULL)
        return 1;
    else
        return 0;
}


/*
 * na hora de excluir eu verifico se aquele nome existe para ser excluido, e verifico em qual posição ele esta, sendo em primeiro
 * se caso for primeiro o inicio da lista recebe o proximo do atual e coloco o anterio para nulo, depois verifico se ele esta no fim
 * da lista se caso for o fim da lista rece o anterior do atual, e o proximo do anterio recebe o proximo do atual
 * se nao siginfica que o que o elemento esta no meio
 */
int excluirContatoNome(TListaContato *lista, char *nome) {
    TElementoContato *atual, *anterior;
    anterior = NULL;
    int excluido = 0;
    atual = buscarPorNome(*lista, nome);
    if (listaVazia(*lista) == 1) {
        printf("FILA ESTA VAZIA, NAO PODE EXCLUIR NINGUEM");
    } else {
        if (atual) {
            excluido = 1;
            anterior = atual->ant;
            if (anterior == NULL) {
                lista->inicio = atual->prox;
                if (lista->inicio) lista->inicio->ant = NULL;
            } else if (atual == lista->fim) {
                lista->fim = atual->ant;
                anterior->prox = atual->prox;
            } else {
                anterior->prox = atual->prox;
                anterior->prox->ant = anterior;
            }
            free(atual);
        }
    }
    return excluido;
}

/*
 * metodo para buscar o nome de um contato. Eu passo a lista de contato e um ponteiro para o nome
 * crio um elemento atual para poder ser o retorno de caso achar
 * e esse atual vai receber o inicio da minha lista para poder percorrer, enquanto o atual for diferente de nulo e o nome
 * que estou passando for maior que 0 que siginifica que o nome atual ainda é menor do que o nome que estou passando. Entao
 * o programa vai seguindo para o proximo, quando ele sair do while ele vai verificar se ele é nulo e se o nome do atual
 * é igual o nome que estou passando e retorno o atual, se caso for nulo eu retorno ao nulo mesmo para a funcao.
 */
TElementoContato *buscarPorNome(TListaContato listaContato, char *nome) {
    TElementoContato *atual;
    atual = listaContato.inicio;
    while ((atual != NULL) && (strcmp(nome, atual->nome) > 0)) {
        atual = atual->prox;
    }
    if (atual != NULL && (strcmp(nome, atual->nome) == 0)) {
        return atual;
    } else {
        return NULL;
    }
}

/*
 * metodo para buscar o numero de um contato. Eu passo a lista de contato e um ponteiro para o numero
 * crio um elemento atual para poder ser o retorno de caso achar
 * e esse atual vai receber o inicio da minha lista para poder percorrer, enquanto o atual for diferente de nulo e o numero
 * do atual for diferente do telefone que estou passando Entao o programa vai seguindo para o proximo, quando ele sair do while ele vai verificar se ele é nulo e se o nome do atual
 * é igual o numero que estou passando e retorno o atual, se caso for nulo eu retorno ao nulo mesmo para a funcao.
 */
TElementoContato *buscarNumero(TListaContato listaContato, long telefone) {
    TElementoContato *atual;
    atual = listaContato.inicio;
    while ((atual != NULL) && (atual->telefone != telefone)) {
        atual = atual->prox;
    }
    if (atual != NULL && atual->telefone == telefone) {
        return atual;
    } else {
        return NULL;
    }
}


/*metodo para listar todos os valores da lista passando, eu simplismente passo a lista e crio um elemento atual do tipo
 * TelementoContato e faço ele receber o inicio, depois disso eu vou faço um while para ir imprimindo e indo para o proximo
 * ate esse proximo for um NULL
 */
void listarTodos(TListaContato *lista) {
    TElementoContato *atual;
    atual = lista->inicio;
    if (listaVazia(*lista) == 1) {
        printf("LISTA ESTA VAZIA");
    } else {
        while (atual != NULL) {
            printf("\n\nNome -> %s / Telefone %ld", atual->nome, atual->telefone);
            atual = atual->prox;
            printf("\n========================================\n");
        }
    }
}