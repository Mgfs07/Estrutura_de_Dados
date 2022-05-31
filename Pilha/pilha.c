#include "pilha.h"

void inicializarPilha (TPilha *p){
    p->topo = -1;
}

int pilhaVazia(TPilha *p){
    if(p->topo < 0){
        return (1);
    }
    else{
        return (0);
    }
}

int pilhaCheia(TPilha *p)
{
    if(p->topo == MAX-1){
        return (1);
    }
    else {
        return (0);
    }
}

int empilha(TPilha *p, int elemento){
    if(pilhaCheia(p)){
        return (0);
    }
    else{
        p->topo = p->topo + 1;
        p->itens[p->topo] = elemento;
        return(1);
    }
}

int desempilha(TPilha *p, int *elemento) {
    if (pilhaVazia(p)) {
        return (0);
    } else {
        (*elemento) = p->itens[p->topo];
        p->topo = p->topo - 1;
        return (1);
    }
}