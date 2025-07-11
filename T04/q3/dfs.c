#include "grafo.h"
#include "dfs.h"
#include <stdio.h>

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