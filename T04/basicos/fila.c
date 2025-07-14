#include "fila.h"



void inicializarFila(Fila* f) {
    f->frente = 0;
    f->tras = -1;
}

int estaVazia(Fila* f) {
    return f->tras < f->frente;
}

void enfileirar(Fila* f, int valor) {
    if (f->tras < MAX_QUEUE - 1) {
        f->itens[++(f->tras)] = valor;
    }
}

void desenfileirar(Fila* f) {
    if (!estaVazia(f)) {
        return f->itens[(f->frente)++];
    }
    return -1;
}
