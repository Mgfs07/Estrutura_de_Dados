#include "filaPrioridade.h"
#include <stdio.h>

#define TAMANHO 40

int main(){
    TFilaPrioridade tFilaPrioridade;
    iniciaFilaPrioridades(&tFilaPrioridade, 3, 2);

    int valorMenu, num;
    char nome[40];


    do {
        printf("\nOpcoes: \n");
        printf("0 - Sair\n");
        printf("1 - Inserir na Fila\n");
        printf("2 - Remover da Fila\n");
        printf("3 - Exibir Elementos a Serem Atendidos\n");
        printf("Informe um valor: ");
        scanf("%d", &valorMenu);
        getchar();

        switch (valorMenu) {
            case 0:
                break;
            case 1:
                printf("\nNome do cliente: ");
                gets(nome);

                do {
                    printf("Prioridade(1-2-3): ");
                    scanf("%d", &num);
                } while (num < 1 || num > 3);

                insereFilaPrioridades(&tFilaPrioridade, nome, num - 1);
                break;
            case 2:
                removeFilaPrioridades(&tFilaPrioridade);
                break;
            case 3:
                imprimeFilaPrioridades(tFilaPrioridade);
                break;
            default:
                printf("Valor incorreto\n");
                printf("Informe um valor novamente: ");
                scanf("%d", &valorMenu);

        }
    } while (valorMenu != 0);
}



