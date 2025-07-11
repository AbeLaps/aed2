#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

Grafo* criarGrafo(int numVertices) {
    Grafo* grafo = malloc(sizeof(Grafo));
    grafo->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++)
        grafo->listaAdj[i] = NULL;
    return grafo;
}

void adicionarAresta(Grafo* grafo, int v1, int v2) {
    No* novo = malloc(sizeof(No));
    novo->vertice = v2;
    novo->prox = grafo->listaAdj[v1];
    grafo->listaAdj[v1] = novo;

    novo = malloc(sizeof(No));
    novo->vertice = v1;
    novo->prox = grafo->listaAdj[v2];
    grafo->listaAdj[v2] = novo;
}

void liberarGrafo(Grafo* grafo) {
    for (int i = 0; i < grafo->numVertices; i++) {
        No* atual = grafo->listaAdj[i];
        while (atual) {
            No* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(grafo);
}

void imprimirGrafo(Grafo* grafo) {
    for (int i = 0; i < grafo->numVertices; i++) {
        printf("%d -> ", i);
        No* atual = grafo->listaAdj[i];
        while (atual) {
            printf("%d ", atual->vertice);
            atual = atual->prox;
        }
        printf("\n");
    }
}
