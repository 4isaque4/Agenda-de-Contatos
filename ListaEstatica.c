#include "ListaEstatica.h"
#include <stdio.h>
#include <string.h>

void inicializarLista(ListaEstatica *lista) {
    lista->tamanho = 0;
}

int adicionarContato(ListaEstatica *lista, Contato contato) {
    if (lista->tamanho >= MAX_CONTATOS) {
        return -1;  
    }
    lista->contatos[lista->tamanho] = contato;
    lista->tamanho++;
    return 0;  
}

int removerContato(ListaEstatica *lista, const char *nome) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (strcmp(lista->contatos[i].nome, nome) == 0) {
            for (int j = i; j < lista->tamanho - 1; j++) {
                lista->contatos[j] = lista->contatos[j + 1];
            }
            lista->tamanho--;
            return 0;  
        }
    }
    return -1;  
}

int buscarContato(ListaEstatica *lista, const char *nome, Contato *contato) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (strcmp(lista->contatos[i].nome, nome) == 0) {
            *contato = lista->contatos[i];
            return 0; 
        }
    }
    return -1;  
}

void listarContatos(ListaEstatica *lista) {
    if (lista->tamanho == 0) {
        printf("Agenda vazia.\n");
    } else {
        for (int i = 0; i < lista->tamanho; i++) {
            printf("Nome: %s\nTelefone: %s\nEmail: %s\n\n",
                   lista->contatos[i].nome,
                   lista->contatos[i].telefone,
                   lista->contatos[i].email);
        }
    }
}
