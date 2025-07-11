#ifndef FILA_H
#define FILA_H


#define MAX_QUEUE 1000


typedef struct {
    int itens[MAX_QUEUE];
    int frente, tras;
} Fila;


void inicializarFila(Fila* f);

int estaVazia(Fila* f);

void enfileirar(Fila* f, int valor);

void enfileirar(Fila* f, int valor);

#endif