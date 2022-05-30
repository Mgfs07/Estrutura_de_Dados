#include "filaPrioridade.h"
#include <stdlib.h>
#include <stdio.h>

void iniciaFilaPrioridades(TFilaPrioridade *f, int quantidadePrioridade, int maxAge) {
    int i = 0;
    f->quantidadePrioridade = quantidadePrioridade; //eu pego a quantidade que prioridade que eu quero
    f->maxAge = maxAge; //ele seta quantos "atendimento" que eu quero fazer para ele dar age
    f->filas = (TFila *) malloc(quantidadePrioridade * sizeof(TFila));
    f->ages = (int *) malloc(quantidadePrioridade * sizeof(int));
    for (i = 0; i < quantidadePrioridade; i++) { //inicio a quantidade de filas necessarias
        iniciaFila(&(f->filas[i]));
        f->ages[i] = 0; // todas essas filas terao o seu age zerados antes de começar a inserir os elementos
    }
}


//funcao para inserir o elemento de acordo com a prioridade dele
//ele faz a verificação se a prioridade é menor que a quantidade de prioridade que eu declarei no main
//se for ele insere um elemento no seu respectivo vetor de prioridade que no caso é 1,2 ou 3
int insereFilaPrioridades(TFilaPrioridade *f, char nome[], int prioridade) {
    if (prioridade < f->quantidadePrioridade){
        return insereFila(&f->filas[prioridade], nome);
    }
    else
        return 0;
}

//funcao para poder imprimir os elementos
void imprimeFilaPrioridades(TFilaPrioridade f) {
    int i;
    printf("\n\nFila");
    for (i = 0; i < f.quantidadePrioridade; i++) {
        printf("\n Fila de Prioridade %d", i+1);
        imprimeFila(f.filas[i]);
    }
}


//funcao para remover os elementos da fila
//eu passo o TFilaPrioridade e depois eu verifico se a prioridade é menor que a quantidade de prioridade
//e tambem se a fila daquela prioridade esta vazia, se ela estiver vazia eu coloca a prioridade com mais 1
//depois de veiricar eu entro no If para verificar seto o age daquele vetor como 0
//e adiciona mais um para ele ir para a proxima prioridade
char *removeFilaPrioridades(TFilaPrioridade *f) {
    int prioridade = 0;
    while ((prioridade < f->quantidadePrioridade) && filaVazia(f->filas[prioridade]))
        prioridade++;
    if (prioridade < f->quantidadePrioridade) {
        f->ages[prioridade] = 0;
        int i = prioridade + 1;
        while (i < f->quantidadePrioridade) {
            if (!filaVazia(f->filas[i])) {
                f->ages[i]++;
                if (f->ages[i] > f->maxAge) { //quando o age se torna maior que o MaxAnge, ele remove de fila de maior prioridade e adiciona no fila de menor prioridade que aquela
                    insereFila(&f->filas[i - 1], removeFila(&f->filas[i]));
                    f->ages[i] = 0;
                }
            }
            i++;
        }
        return removeFila(&f->filas[prioridade]);
    } else
        return NULL;
}
