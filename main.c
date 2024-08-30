#include <stdio.h>
#include "ListaEstatica.h"

void exibirMenu() {
    printf("Menu:\n");
    printf("1. Adicionar Contato\n");
    printf("2. Remover Contato\n");
    printf("3. Buscar Contato\n");
    printf("4. Listar Contatos\n");
    printf("5. Sair\n");
}

int main() {
    ListaEstatica agenda;
    inicializarLista(&agenda);
    int opcao;
    Contato contato;
    char nome[50];
    int resultado;

    do {
        exibirMenu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();  

        switch (opcao) {
            case 1:
                printf("Adicionar Contato:\n");
                printf("Nome: ");
                fgets(contato.nome, 50, stdin);
                contato.nome[strcspn(contato.nome, "\n")] = 0; 
                printf("Telefone: ");
                fgets(contato.telefone, 15, stdin);
                contato.telefone[strcspn(contato.telefone, "\n")] = 0;
                printf("Email: ");
                fgets(contato.email, 50, stdin);
                contato.email[strcspn(contato.email, "\n")] = 0;

                if (adicionarContato(&agenda, contato) == 0) {
                    printf("Contato adicionado com sucesso.\n");
                } else {
                    printf("Erro: Lista cheia.\n");
                }
                break;

            case 2:
                printf("Remover Contato:\n");
                printf("Nome: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0;

                if (removerContato(&agenda, nome) == 0) {
                    printf("Contato removido com sucesso.\n");
                } else {
                    printf("Erro: Contato não encontrado.\n");
                }
                break;

            case 3:
                printf("Buscar Contato:\n");
                printf("Nome: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0;

                resultado = buscarContato(&agenda, nome, &contato);
                if (resultado == 0) {
                    printf("Contato encontrado:\n");
                    printf("Nome: %s\nTelefone: %s\nEmail: %s\n",
                           contato.nome, contato.telefone, contato.email);
                } else {
                    printf("Erro: Contato não encontrado.\n");
                }
                break;

            case 4:
                printf("Listar Contatos:\n");
                listarContatos(&agenda);
                break;

            case 5:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }

        printf("\n");
    } while (opcao != 5);

    return 0;
}
