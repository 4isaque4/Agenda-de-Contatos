#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H

#define MAX_CONTATOS 100  

typedef struct {
    char nome[50];
    char telefone[15];
    char email[50];
} Contato;

typedef struct {
    Contato contatos[MAX_CONTATOS];
    int tamanho;
} ListaEstatica;

void inicializarLista(ListaEstatica *lista);
int adicionarContato(ListaEstatica *lista, Contato contato);
int removerContato(ListaEstatica *lista, const char *nome);
int buscarContato(ListaEstatica *lista, const char *nome, Contato *contato);
void listarContatos(ListaEstatica *lista);

#endif 
