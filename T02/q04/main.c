#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AVL.h"

int main() {
    int num_elementos = 1000000; //1e6
    Avl* arvores[10];
    double tempo_criacao[10];
    int alturas[10];
    double tempo_busca[10];
    double media_busca[10];


    srand(time(NULL));
    int valores[num_elementos];
    for (int i = 0; i < num_elementos; i++) {
        valores[i] = rand() %(int) 1e8 ; // Gera valores aleatórios dentro de um intervalo
    }

    printf("--- Criação das Árvores AVL ---\n");
    printf("A");
     for (int i = 0; i < 10; i++) {
        printf("cmoecei");
        arvores[i] = NULL;
        clock_t inicio = clock();
        for (int j = 0; j < num_elementos; j++) {
            printf("inserindo\n");
            //ordemAvl(arvores[i]);
            insereValAvl(&arvores[i], valores[j]);
            printf("Inserção de %d concluída\n", valores[j]);
        }
        clock_t fim = clock();
        tempo_criacao[i] = (double)(fim - inicio) / CLOCKS_PER_SEC;
        alturas[i] = altura(arvores[i]);
        printf("Árvore %d: Tempo de criação = %.4f segundos, Altura = %d\n", i + 1, tempo_criacao[i], alturas[i]);
     }

    printf("\n--- Busca nas Árvores AVL ---\n");
    for (int i = 0; i < 10; i++) {
        tempo_busca[i] = 0.0;
        for (int j = 0; j < 30; j++) {
            int valor_busca = valores[rand() % num_elementos]; // Busca por valores que provavelmente estão na árvore
            clock_t inicio_busca = clock();
            buscaAvl(arvores[i], valor_busca);
            clock_t fim_busca = clock();
            tempo_busca[i] += (double)(fim_busca - inicio_busca) / CLOCKS_PER_SEC;
        }
        media_busca[i] = tempo_busca[i] / 30;
        printf("Árvore %d: Tempo total de %d buscas = %.4f segundos, Tempo médio de busca = %.6f segundos\n",
               i + 1, 30, tempo_busca[i], media_busca[i]);
    }

    return 0;
}

