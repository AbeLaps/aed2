#ifndef GRAFO_H
#define GRAFO_H

#define MAX_VERTICES 100

typedef struct No {
    int vertice;
    struct No* prox;
} No;

typedef struct {
    int numVertices;
    No* listaAdj[MAX_VERTICES];
    float conAt ; // grau de conectividade atual do grafo 
} Grafo;

Grafo* criarGrafo(int numVertices);

void buscarTodosCaminhosPorDFS(Grafo* grafo, int atual, int* visitado, int* caminho, int profundidade);

int temCicloPorDFS(Grafo* grafo);

void dfs(Grafo* grafo);

void bfs(Grafo* grafo, int inicio, int* pai);

void adicionarAresta(Grafo* grafo, int v1, int v2);

void gerarGrafoConexo(Grafo* grafo, float conectividade);

void liberarGrafo(Grafo* grafo);

void imprimirGrafo(Grafo* grafo);

#endif
