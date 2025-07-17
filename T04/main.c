#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grafo.h"


void buscarTodosCaminhos(Grafo* grafo, int atual, int* visitado, int* caminho, int profundidade) {
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
                buscarTodosCaminhos(grafo, vizinho, visitado, caminho, profundidade + 1);
            }
            adj = adj->prox;
        }
    }

    visitado[atual] = 0; // backtrack
}

void imprimirArvoreBusca(int* pai, int n) {
    printf("Árvore de busca (formato filho -> pai):\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> %d\n", i, pai[i]);
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

int temCiclo(Grafo* grafo) {
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

void executarQuestao1() {
    int numVertices = 10;
    float conectividades[] = {0.25, 0.5, 0.75, 1.0};

    for (int i = 0; i < 4; i++) {
        printf("\n--- Grafo com conectividade %.0f%% ---\n", conectividades[i]*100);
        Grafo* g = criarGrafo(numVertices);
        gerarGrafoConexo(g, conectividades[i]);
        imprimirGrafo(g);
        liberarGrafo(g); 
    }
}

void executarQuestao2() {
    int numVertices = 100;
    float conectividades[] = {0.25, 0.5, 0.75, 1.0};
    clock_t inicio, fim;
    double tempo;

    for (int i = 0; i < 4; i++) {
        printf("\n--- BFS com conectividade %.0f%% ---\n", conectividades[i]*100);
        Grafo* g = criarGrafo(numVertices);
        gerarGrafoConexo(g, conectividades[i]);

        int pai[MAX_VERTICES];
        inicio = clock();
        bfs(g, 0, pai);
        fim = clock();

        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Tempo de execução: %.4f s\n", tempo);
        imprimirArvoreBusca(pai, numVertices);

        liberarGrafo(g);
    }
}

void executarQuestao3(){
    int numVertices = 100;
    float conectividades[] = {0.25, 0.5, 0.75, 1.0};
    clock_t inicio, final;
    double tempo;

    for (int i = 0; i < 4; i++) { //so tem 4 conectividades
        printf("\n--- Grafo com conectividade %.0f%% ---\n", conectividades[i]*100);
        Grafo* g = criarGrafo(numVertices);
        gerarGrafoConexo(g, conectividades[i]);
        inicio = clock();
        dfs(g);
        final = clock();
        tempo = ((double) (final - inicio)) / CLOCKS_PER_SEC;
        printf("tempo para realizar DFS: %ld\n", tempo);
        liberarGrafo(g);    
    }
}

void executarQuestao4() {
    int numVertices = 6; // evitar explosão combinatória
    Grafo* grafo = criarGrafo(numVertices);
    gerarGrafoConexo(grafo, 1.0); // total para garantir conectividade

    printf("\nTodos os caminhos DFS que visitam todos os vértices:\n");

    int visitado[MAX_VERTICES] = {0};
    int caminho[MAX_VERTICES];

    buscarTodosCaminhos(grafo, 0, visitado, caminho, 0);

    liberarGrafo(grafo);
}

void executarQuestao5() {
    int numVertices = 10;
    float conectividades[] = {0.25, 0.5, 0.75, 1.0};

    for (int i = 0; i < 4; i++) {
        printf("\n--- Grafo com conectividade %.0f%% ---\n", conectividades[i]*100);
        Grafo* g = criarGrafo(numVertices);
        gerarGrafoConexo(g, conectividades[i]);
        imprimirGrafo(g);

        if (temCiclo(g)) {
            printf("→ O grafo possui ciclo.\n");
        } else {
            printf("→ O grafo NÃO possui ciclo.\n");
        }

        liberarGrafo(g);
    }
}

int main() {
    srand(time(NULL));
    int opcao;

    do {
        printf("\n=== Menu de Execução ===\n");
        printf("1. Criar grafos conexos com diferentes conectividades\n");
        printf("2. Busca em Largura (BFS)\n");
        printf("3. Busca em Profundidade (DFS)\n");
        printf("4. Todos os caminhos DFS\n");
        printf("5. Detecção de ciclos (DFS)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                executarQuestao1();
                break;
            case 2:
                executarQuestao2();
                break;
            case 3:
                executarQuestao3();
                break;
            case 4:
                executarQuestao4();
                break;
            case 5:
                executarQuestao5();
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
