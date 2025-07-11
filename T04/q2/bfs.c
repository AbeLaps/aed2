#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "grafo.h"

#define MAX_QUEUE 1000

typedef struct {
    int itens[MAX_QUEUE];
    int frente, tras;
} Fila;

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

int desenfileirar(Fila* f) {
    if (!estaVazia(f)) {
        return f->itens[(f->frente)++];
    }
    return -1;
}

void bfs(Grafo* grafo, int inicio, int* pai) {
    int n = grafo->numVertices;
    int visitado[MAX_VERTICES] = {0};
    Fila fila;
    inicializarFila(&fila);

    visitado[inicio] = 1;
    pai[inicio] = -1;
    enfileirar(&fila, inicio);

    while (!estaVazia(&fila)) {
        int atual = desenfileirar(&fila);
        No* adj = grafo->listaAdj[atual];
        while (adj != NULL) {
            int vizinho = adj->vertice;
            if (!visitado[vizinho]) {
                visitado[vizinho] = 1;
                pai[vizinho] = atual;
                enfileirar(&fila, vizinho);
            }
            adj = adj->prox;
        }
    }
}

void imprimirArvoreBusca(int* pai, int n) {
    printf("Árvore de busca (formato filho -> pai):\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> %d\n", i, pai[i]);
    }
}
