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
void adicionarAresta(Grafo* grafo, int v1, int v2);
void liberarGrafo(Grafo* grafo);
void imprimirGrafo(Grafo* grafo);
void transfomaEmGrafoConexo(Grafo * grafo);
void ajustaConectividade(Grafo * grafo, float con);

#endif
