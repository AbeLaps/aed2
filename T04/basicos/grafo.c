#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "fila.h"

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

void dfsAux(Grafo* grafo, int atual, int* visitado, int* pai) {
    visitado[atual] = 1;
    printf("%d; ", atual);  // Exibe vertice visitado

    No* adj = grafo->listaAdj[atual];
    while (adj != NULL) {
        int vizinho = adj->vertice;
        if (!visitado[vizinho]) {
            pai[vizinho] = atual;
            dfsAux(grafo, vizinho, visitado, pai);
        }
        adj = adj->prox;
    }
}

void dfs(Grafo* grafo) {
    int visitado[MAX_VERTICES] = {0};
    int pai[MAX_VERTICES];

    for (int i = 0; i < grafo->numVertices; i++) {
        pai[i] = -1;
    }

    printf("Sequencia de visitas pela Busca por Profundidade: ");
    dfsAux(grafo, 0, visitado, pai);
    printf("\n");
}