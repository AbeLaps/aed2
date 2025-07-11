#include <stdlib.h>
#include <time.h>
#include "util.h"

int existeAresta(Grafo* grafo, int v1, int v2) {
    No* atual = grafo->listaAdj[v1];
    while (atual) {
        if (atual->vertice == v2)
            return 1;
        atual = atual->prox;
    }
    return 0;
}

void gerarGrafoConexo(Grafo* grafo, float conectividade) {
    int n = grafo->numVertices;
    int maxArestas = n * (n - 1) / 2;
    int arestasDesejadas = (int)(conectividade * maxArestas);

    // Garante a conexão com uma árvore
    for (int i = 1; i < n; i++) {
        int v = rand() % i;
        adicionarAresta(grafo, i, v);
    }

    int arestasAdicionadas = n - 1;
    while (arestasAdicionadas < arestasDesejadas) {
        int v1 = rand() % n;
        int v2 = rand() % n;
        if (v1 != v2 && !existeAresta(grafo, v1, v2)) {
            adicionarAresta(grafo, v1, v2);
            arestasAdicionadas++;
        }
    }
}