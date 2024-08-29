#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H

#define MAX_CONTATOS 100
typedef struct {
    char nome[50];
    char telefone[20];
    char email[50];
} Contato;

typedef struct {
    Contato contatos[MAX_CONTATOS];
    int numContatos;
} ListaEstatica;

void inicializarLista(ListaEstatica *lista);
int adicionarContato(ListaEstatica *lista, Contato *contato);
int removerContato(ListaEstatica *lista, char *nome);
int buscarContato(ListaEstatica *lista, char *nome, Contato *contato);
void listarContatos(ListaEstatica *lista);

#endif