#include <stdio.h>
#include "listaContato.h"

int main() {

    TListaContato lista;
    iniciaLista(&lista);

    int valorMenu;
    long numeroTelefone;
    char nome[TAMANHO];
    TElementoContato *contato;

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
                printf("\nNome do cliente: ");
                gets(nome);
                contato = buscarPorNome(lista, nome);
                if (!contato) {
                    printf("insira o numero que deseja: ");
                    scanf("%ld", &numeroTelefone);
                    insereListaContato(&lista, nome, numeroTelefone);
                    printf("CONTATO INSERIDO COM SUCESSO\n\n");
                } else {
                    printf("\nContato já existe\n");
                    printf("Nome -> %s / Telefone -> %ld", contato->nome, contato->telefone);
                }
                break;
            case 2:
                printf("insira o nome que deseja excluir: ");
                gets(nome);
                if (excluirContatoNome(&lista, nome) == 1) {
                    printf("\nContato excluido com sucesso\n");
                } else {
                    printf("\nContato nao encontrado para ser excluido\n");
                }
                break;
            case 3:
                listarTodos(&lista);
                break;
            case 4:
                printf("qual o nome que deseja procurar: ");
                gets(nome);
                contato = buscarPorNome(lista, nome);
                !contato ? printf("\n\nNÃO EXISTE CONTATO EXISTENTE") : printf("\nContato existe\n"
                                                                               "Nome -> %s\n"
                                                                               "Telefone -> %ld\n\n", contato->nome,
                                                                               contato->telefone);
                break;
            case 5:
                printf("qual numero deseja procurar: ");
                scanf("%ld", &numeroTelefone);
                contato = buscarNumero(lista, numeroTelefone);
                !contato ? printf("\nNUMERO DESCONHECIDO") : printf("\nO CONTATO -> %ld pertence ao NOME -> %s\n",
                                                                    contato->telefone, contato->nome);
                break;
            default:
                printf("Valor incorreto\n");
                printf("Informe um valor novamente: ");
                scanf("%d", &valorMenu);
        }
    } while (valorMenu != 0);
}


