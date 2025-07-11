#include <stdio.h>
#include "grafo.h"
#include "bfs.h"
#include "fila.h"





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

void imprimirArvoreBfs(int* pai, int n) {
    printf("Árvore de busca (formato filho -> pai):\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> %d\n", i, pai[i]);
    }
}
