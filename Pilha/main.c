#include <stdio.h>
#include "pilha.h"

int main(){
    TPilha p;
    int num, resto, elemento;

    printf("\nInforme um numero decimal: ");
    scanf("%d",&num);

    inicializarPilha(&p);
    while(num != 0){
        resto = num % 2;
        empilha(&p, resto);
        num = num / 2;
    }

    printf("\n\nNumero na base 2 eh: ");
    while(desempilha(&p, &elemento)){
        printf("%d",elemento);
    }

}