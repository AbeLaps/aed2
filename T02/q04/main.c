#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "avl.h"
#include "ABP.h"

#define NUM_ELEMENTS 100000
#define NUM_ARVS 10
#define NUM_BUSCAS 30

int main() {
    srand(time(NULL)); 
    
    int valores[NUM_ELEMENTS];
    double tempos_ABP[NUM_ARVS];
    int alturas_ABP[NUM_ARVS];
    double tempos_AVL[NUM_ARVS];
    int alturas_AVL[NUM_ARVS];
    double tempos_busca_ABP[NUM_ARVS][NUM_BUSCAS];
    double tempos_busca_AVL[NUM_ARVS][NUM_BUSCAS];
    
    printf("Gerando %d valores aleatorios...\n", NUM_ELEMENTS);
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        valores[i] = rand();
    }
    printf("Valores gerados.\n");
    
    // Criar e testar as árvores
    for (int i = 0; i < NUM_ARVS; i++) {
        // AVL
        clock_t inicio = clock();
        Avl* arvoreAvl = NULL;
        for(int j = 0; j < NUM_ELEMENTS; j++) {
            arvoreAvl = inserirAvl(arvoreAvl, valores[j]);
        }
        tempos_AVL[i] = (double)(clock() - inicio) / CLOCKS_PER_SEC;
        alturas_AVL[i] = alturaAvl(arvoreAvl);
        
        // ABP
        inicio = clock();
        Arv* arvoreABP = criaArv(valores[0]);
        for(int j = 1; j < NUM_ELEMENTS; j++) {
            insereValArv(arvoreABP, valores[j]);
        }
        tempos_ABP[i] = (double)(clock() - inicio) / CLOCKS_PER_SEC;
        alturas_ABP[i] = tamArv(arvoreABP);
        
        // Testes de busca
        for (int k = 0; k < NUM_BUSCAS; k++) {
            int valor_busca = valores[rand() % NUM_ELEMENTS]; // Busca por valor existente
            
            // Busca AVL
            inicio = clock();
            buscaAvl(arvoreAvl, valor_busca);
            tempos_busca_AVL[i][k] = (double)(clock() - inicio) / CLOCKS_PER_SEC;
            
            // Busca ABP
            inicio = clock();
            buscaABP(arvoreABP, valor_busca);
            tempos_busca_ABP[i][k] = (double)(clock() - inicio) / CLOCKS_PER_SEC;
        }
        
        liberarArvoreAvl(arvoreAvl);
        liberarArvoreABP(arvoreABP);
        
        printf("Execucao %d concluida.\n", i+1);
    }

    // Calcular médias
    double tempo_medio_insercao_ABP = 0;
    double tempo_medio_insercao_AVL = 0;
    int altura_media_ABP = 0;
    int altura_media_AVL = 0;
    double tempo_medio_busca_ABP = 0;
    double tempo_medio_busca_AVL = 0;
    
    for (int i = 0; i < NUM_ARVS; i++) {
        tempo_medio_insercao_ABP += tempos_ABP[i];
        tempo_medio_insercao_AVL += tempos_AVL[i];
        altura_media_ABP += alturas_ABP[i];
        altura_media_AVL += alturas_AVL[i];
        
        for (int k = 0; k < NUM_BUSCAS; k++) {
            tempo_medio_busca_ABP += tempos_busca_ABP[i][k];
            tempo_medio_busca_AVL += tempos_busca_AVL[i][k];
        }
    }

    tempo_medio_insercao_ABP /= NUM_ARVS;
    tempo_medio_insercao_AVL /= NUM_ARVS;
    altura_media_ABP /= NUM_ARVS;
    altura_media_AVL /= NUM_ARVS;
    tempo_medio_busca_ABP /= (NUM_ARVS * NUM_BUSCAS);
    tempo_medio_busca_AVL /= (NUM_ARVS * NUM_BUSCAS);

    // Imprimir resultados
    printf("\n=== RESULTADOS ===\n");
    printf("\n=== INSERCAO ===\n");
    printf("Tempo medio de insercao ABP: %.6f segundos\n", tempo_medio_insercao_ABP);
    printf("Tempo medio de insercao AVL: %.6f segundos\n", tempo_medio_insercao_AVL);
    printf("Altura media ABP: %d\n", altura_media_ABP);
    printf("Altura media AVL: %d\n", altura_media_AVL);
    
    printf("\n=== BUSCA ===\n");
    printf("Tempo medio de busca ABP (30 buscas): %.6f segundos\n", tempo_medio_busca_ABP);
    printf("Tempo medio de busca AVL (30 buscas): %.6f segundos\n", tempo_medio_busca_AVL);
    
    printf("\n=== DETALHES POR EXECUCAO ===\n");
    for (int i = 0; i < NUM_ARVS; i++) {
        printf("\nExecucao %d:\n", i+1);
        printf("  ABP - Tempo insercao: %.6f s, Altura: %d\n", tempos_ABP[i], alturas_ABP[i]);
        printf("  AVL - Tempo insercao: %.6f s, Altura: %d\n", tempos_AVL[i], alturas_AVL[i]);
    } 
    return 0;
}
