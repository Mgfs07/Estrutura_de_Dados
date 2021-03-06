#include <stdio.h>
#include "listaContato.h"

int main() {

    TElementoContato * arvore;
    iniciaLista(&arvore);
    TElementoContato * contato;

    int valorMenu, valorExcluir, inserir;
    long numeroTelefone;
    char nome[TAMANHO];

    do {
        printf("\n\nOpcoes: \n");
        printf("0 - Sair\n");
        printf("1 - Inserir na Árvore\n");
        printf("2 - Remover da Árvore\n");
        printf("3 - Exibir toda a Árvore com os Contatos\n");
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
                inserir = insereListaContato( &arvore, nome, numeroTelefone);
                inserir == 1 ? printf("Contato Adicionado com Sucesso") : printf("Contato nao adicionado");
                break;
            case 2:
                printf("insira um nome que deseja excluir: ");
                gets(nome);
                valorExcluir = remover(&arvore, nome);
                if(valorExcluir == 1)
                    printf("Excluido com Sucesso");
                else
                    printf("Contato nao excluido");
                break;
            case 3:
                ordem(arvore);
                break;
            case 4:
                printf("insira o nome que deseja pesquisar: ");
                gets(nome);
                contato = consultarNome(arvore, nome);
                contato ? printf("\nContato existe\n Nome -> %s Telefone -> %ld\n", contato->nome, contato->telefone) : printf("\n\nNÃO EXISTE CONTATO EXISTENTE");
                break;
            case 5:
                printf("insira o numero que deseja pesquisar: ");
                scanf("%ld", &numeroTelefone);
                contato = consultarNumero(arvore, numeroTelefone);
                contato ? printf("\nContato existe \nNome -> %s Telefone -> %ld\n", contato->nome, contato->telefone) : printf("\n\nNÃO EXISTE CONTATO EXISTENTE") ;
                break;
            default:
                printf("Valor incorreto\n");
                printf("Informe um valor novamente: ");
                scanf("%d", &valorMenu);
        }
    } while (valorMenu != 0);
}


