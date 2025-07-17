#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "fila.h"

Grafo* criarGrafo(int numVertices) {    // cria um grafo com 'n' vértices
    Grafo* grafo = malloc(sizeof(Grafo));
    grafo->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++)
        grafo->listaAdj[i] = NULL;
    grafo->conAt = 0;
    return grafo;
}

void adicionarAresta(Grafo* grafo, int v1, int v2) { // adiciona uma aresta (relação entre 2 vértices) à lista de adjascência
    No* novo = malloc(sizeof(No));
    novo->vertice = v2;
    novo->prox = grafo->listaAdj[v1];
    grafo->listaAdj[v1] = novo;

    novo = malloc(sizeof(No));
    novo->vertice = v1;
    novo->prox = grafo->listaAdj[v2];
    grafo->listaAdj[v2] = novo;
}

void liberarGrafo(Grafo* grafo) { // libera a memória antes reservada para o grafo 
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

int temCicloAux(Grafo* grafo, int atual, int* visitado, int pai) {
    visitado[atual] = 1;

    No* adj = grafo->listaAdj[atual];
    while (adj != NULL) {
        int vizinho = adj->vertice;

        if (!visitado[vizinho]) {
            if (temCicloAux(grafo, vizinho, visitado, atual)) {
                return 1;
            }
        } else if (vizinho != pai) {
            return 1; // ciclo detectado
        }

        adj = adj->prox;
    }

    return 0;
}

int temCicloPorDFS(Grafo* grafo) {
    int visitado[MAX_VERTICES] = {0};

    for (int i = 0; i < grafo->numVertices; i++) {
        if (!visitado[i]) {
            if (temCicloAux(grafo, i, visitado, -1)) {
                return 1;
            }
        }
    }

    return 0;
}

void buscarTodosCaminhosPorDFS(Grafo* grafo, int atual, int* visitado, int* caminho, int profundidade) {
    visitado[atual] = 1;
    caminho[profundidade] = atual;

    if (profundidade == grafo->numVertices - 1) {
        // Caminho completo
        for (int i = 0; i < grafo->numVertices; i++) {
            printf("%d ", caminho[i]);
        }
        printf("\n");
    } else {
        No* adj = grafo->listaAdj[atual];
        while (adj != NULL) {
            int vizinho = adj->vertice;
            if (!visitado[vizinho]) {
                buscarTodosCaminhosPorDFS(grafo, vizinho, visitado, caminho, profundidade + 1);
            }
            adj = adj->prox;
        }
    }

    visitado[atual] = 0; // backtrack
}
