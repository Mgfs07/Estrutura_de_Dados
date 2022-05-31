#ifndef FILADINAMICA_FILA_H
#define FILADINAMICA_FILA_H

#define TAMANHO 40

//struct de elemento
typedef struct elemento{
    char nome[TAMANHO];
    struct elemento *prox, *ant;
} TElemento;

//struct de tipo de fila
typedef struct fila{
     TElemento *inicio, *fim;
} TFila;


//inicia o a Tfila
void iniciaFila (TFila *f);

//insere o elemento da TFila
int insereFila (TFila *f, char nome[]);

//funçao para verificar se a fila esta vazia
int filaVazia(TFila f);

//remover um elemento da Tfila
char * removeFila(TFila * f);

//imprime a Tfila
void imprimeFila(TFila f);


#endif //FILADINAMICA_FILA_H
