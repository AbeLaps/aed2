#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AVL.h"


int main() {
    int num_elementos = 10000; //1e2
    Avl* arvore = criaAvl(0, NULL);;
    double tempo_criacao[10];
    int alturas[10];
    double tempo_busca[10];
    double media_busca[10];

    srand(0);
    int valores[num_elementos];
    for (int i = 0; i < num_elementos; i++) {
        valores[i] = rand(); //%(int) 1e5 ; // Gera valores aleatórios dentro de um intervalo
    }

    printf("--- Criacao das arvores AVL ---\n");
    printf("A");
     for (int i = 0; i < 10; i++){
        printf("comecei");
        clock_t inicio = clock();
        printf("inserindo\n");
        insereValAvl(&arvore, valores[i]);
        printf("Insercao de %d concluida\n", valores[i]);
        clock_t fim = clock();
        tempo_criacao[i] = (double)(fim - inicio) / CLOCKS_PER_SEC;
        alturas[i] = altura(arvore);
        printf("arvore %d: Tempo de criação = %.4f segundos, Altura = %d\n", i + 1, tempo_criacao[i], alturas[i]);
     }

    printf("\n--- Busca nas arvores AVL ---\n");
    for (int i = 0; i < 10; i++) {
        tempo_busca[i] = 0.0;
        int valor_busca = valores[rand() % num_elementos]; // Busca por valores que provavelmente estão na árvore
        clock_t inicio_busca = clock();
        buscaAvl(arvore, valor_busca);
        clock_t fim_busca = clock();
        tempo_busca[i] += (double)(fim_busca - inicio_busca) / CLOCKS_PER_SEC;
        media_busca[i] = tempo_busca[i] / 30;
        printf("arvore %d: Tempo total de %d buscas = %.4f segundos, Tempo medio de busca = %.6f segundos\n",
               i + 1, 30, tempo_busca[i], media_busca[i]);
    }

    return 0;
}

