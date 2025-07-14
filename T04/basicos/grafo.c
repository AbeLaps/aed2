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

void transformaEmGrafoConexo(Grafo * grafo){ // transforma um grafo sem conexões num grafo conexo
    int i = 0, j = grafo ->numVertices;
    for (i; i + 1 < j; i++){ // este processo cria o grafo conexo com o mínimo possível (n-1) de conexões
        adicionarAresta(grafo, i, i + 1); 
        }   
    int n = grafo->numVertices - 1; // míninimo de conexões
    int m = 0; // iterado para ser o máximo de conexões
        for (int k = 1; k < n; k++){
            m = m + k;}
    grafo->conAt = n/m; // conexão atual do grafo é a mínima possível
}

void aumentaConectividade (Grafo * grafo, float conR){ // ajusta o grafo para uma determinada conectividade mínima Requisitada
    int n = grafo->numVertices - 1; // míninimo de conexões
    int m = 0; // iterado para ser o máximo de conexões
        
    for (int i = 1; i < n; i ++){
        m = m + i;
    }

    float conMin = n/m; // conectividade mínima do grafo;
        
    if (conR < conMin){ // conectividade requisitada menor que a conectividade mínima do grafo
        printf("Erro, a conectividade mínima do grafo é de %.2f%% \n", conMin);
        return;
    }

    if (conR > 1){
        printf("Erro, a conectividade do grafo não pode ser maior que 100%%");
        return;
    }
    
    float conAt = grafo->conAt;
    int tam = sizeof(grafo->listaAdj)/sizeof(grafo->listaAdj[0]); // usado paara escolher nós aleatórios
    int ran1, ran2;
    
    if (conAt < conR){
        while(conAt < conR){
            srand(time(NULL));

            ran1 = rand() % tam; // nó aleatorio da lista de adjascencia
         
            do {
                ran2 = rand() % tam;  // garante que estamos conectando 2 nós diferentes
            } while (ran1 == ran2);
            adicionarAresta (grafo, ran1, ran2);
            conAt =  conAt + 1/m; // atualiza a conectividade
        }
    grafo->conAt = conAt;
    return;
    }
    else{
        printf("A conectividade atual é igual ou superior a requisitada");
        return;
    }    
}
