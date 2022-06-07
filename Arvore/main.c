#include <stdio.h>
#include "listaContato.h"

int main() {

    TElementoContato * arvore;
    iniciaLista(&arvore);
    TElementoContato * contato;

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
                printf("insira um nome que deseja inserir: ");
                gets(nome);
                printf("e o numero de telefone que deseja inserir: ");
                scanf("%ld", &numeroTelefone);
                insereListaContato( &arvore, nome, numeroTelefone);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                printf("insira o nome que deseja pesquisar: ");
                gets(nome);
                contato = consultarNome(arvore, nome);
                !contato ? printf("\n\nNÃO EXISTE CONTATO EXISTENTE") : printf("\nContato existe Nome -> %s Telefone -> %ld\n", contato->nome, contato->telefone);
                break;
            case 5:
                printf("insira o numero que deseja pesquisar: ");
                scanf("%ld", &numeroTelefone);
                contato = consultarNumero(arvore, numeroTelefone);
                !contato ? printf("\n\nNÃO EXISTE CONTATO EXISTENTE") : printf("\nContato existe Nome -> %s Telefone -> %ld\n", contato->nome, contato->telefone);
                break;
            default:
                printf("Valor incorreto\n");
                printf("Informe um valor novamente: ");
                scanf("%d", &valorMenu);
        }
    } while (valorMenu != 0);
}


