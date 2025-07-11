#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grafo.h"
#include "util.h"


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

void executarQuestao2();

void executarQuestao3(){
    int numVertices = 100;
    float conectividades[] = {0.25, 0.5, 0.75, 1.0};
    clock_t inicio, final;
    double tempo;

    for (int i = 0; i < 10; i++) {
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



void executarQuestao4();
void executarQuestao5();

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
