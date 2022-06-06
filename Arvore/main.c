#include <stdio.h>
#include "listaContato.h"

int main() {

    TElementoContato * arvore;
    iniciaLista(&arvore);

    int valorMenu;
    long numeroTelefone;
    char nome[TAMANHO];

    do {
        printf("\nOpcoes: \n");
        printf("0 - Sair\n");
        printf("1 - Inserir na Fila\n");
        printf("2 - Remover da Fila\n");
        printf("3 - Exibir toda a Lista com os Contatos\n");
        printf("4 - Buscar Contato pelo Nome\n");
        printf("5 - Buscar Contato pelo Numero\n");
        printf("Informe um valor: ");
        scanf("%d", &valorMenu);
        getchar();

        switch (valorMenu) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                printf("Valor incorreto\n");
                printf("Informe um valor novamente: ");
                scanf("%d", &valorMenu);
        }
    } while (valorMenu != 0);
}


