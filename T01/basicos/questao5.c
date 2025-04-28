/*Nomes:
Abel Andrade Prazeres dos Santos
Bruna de Souza Brasil
Gabriel Gregório dos Santos Vitor
Gabriela Silva Malveira

*/

#include "lista.h"
#include "lista.c"
#include "vetor.h"
#include "vetor.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    tipoLista l;
    tipoVetor v;
    int k, n;
    float tempo_tot;
    FILE *arquivo1 = fopen("tempos_Q5.txt", "w");  // Usando caminho relativo
    if (arquivo1 == NULL) {
        perror("Erro ao abrir arquivo!\n");
        return 1;
    }

    // Inicializa a lista antes de usá-la
    criaLista(&l);

    // Configura a semente uma vez no início
    srand(time(NULL));

    // Para cada tamanho de vetor/lista (100.000, 200.000, ..., 1.000.000)
    for (int tamanho = 100000; tamanho <= 1000000; tamanho += 100000) {
        fprintf(arquivo1, "Tamanho: %d\n", tamanho);

        // Cria vetor e preenche
        criaVetor(&v, tamanho);
        preencheVetor(&v);

        // Executa a busca sequencial no vetor
        k = rand();  // Gera um valor aleatório
        clock_t tempoini = clock();
        buscaSeqVetor(v, k);
        clock_t tempof = clock();
        tempo_tot = (float)(tempof - tempoini) / CLOCKS_PER_SEC;
        fprintf(arquivo1, "Busca Seq (Vetor) - Tempo: %.8f\n", tempo_tot);

        // Cria lista e preenche com o vetor
        preencheListaComVetor(&l, &v);

        // Executa a busca sequencial na lista
        tempoini = clock();
        buscaSeqLista(&l, k);
        tempof = clock();
        tempo_tot = (float)(tempof - tempoini) / CLOCKS_PER_SEC;
        fprintf(arquivo1, "Busca Seq (Lista) - Tempo: %.8f\n", tempo_tot);

        // Destrói o vetor para liberar memória
        destroiVetor(&v);
    }

    // Parte 2 - Ordenação dos vetores
    tipoVetor copia;
    fprintf(arquivo1, "parte 2 questao 5\n");
    for (int i = 10000; i <= 100000; i += 10000) {
        criaVetor(&copia, i); // Cria vetor copia
        criaVetor(&v, i); // Cria vetor v

        // Copia o vetor para a variável copia e mede o tempo para cada algoritmo
        copiaVetor(&copia, &v);

        // Bubble Sort
        clock_t tempoini = clock();
        bubbleSort(&copia);
        clock_t tempof = clock();
        tempo_tot = (float)(tempof - tempoini) / CLOCKS_PER_SEC;
        fprintf(arquivo1, "bubble sort: %.8f\n", tempo_tot);

        // Insertion Sort
        copiaVetor(&copia, &v);
        tempoini = clock();
        insertionSort(&copia);
        tempof = clock();
        tempo_tot = (float)(tempof - tempoini) / CLOCKS_PER_SEC;
        fprintf(arquivo1, "insertion sort: %.8f\n", tempo_tot);

        // Selection Sort
        copiaVetor(&copia, &v);
        tempoini = clock();
        selectionSort(&copia);
        tempof = clock();
        tempo_tot = (float)(tempof - tempoini) / CLOCKS_PER_SEC;
        fprintf(arquivo1, "selection sort: %.8f\n", tempo_tot);

        // Quick Sort
        copiaVetor(&copia, &v);
        tempoini = clock();
        quickSort(&copia);
        tempof = clock();
        tempo_tot = (float)(tempof - tempoini) / CLOCKS_PER_SEC;
        fprintf(arquivo1, "quick sort: %.8f\n", tempo_tot);

        // Merge Sort
        copiaVetor(&copia, &v);
        tempoini = clock();
        mergeSort(&copia);
        tempof = clock();
        tempo_tot = (float)(tempof - tempoini) / CLOCKS_PER_SEC;
        fprintf(arquivo1, "merge sort: %.8f\n", tempo_tot);

        // Destrói os vetores para liberar memória
        destroiVetor(&copia);
        destroiVetor(&v);
    }

    fclose(arquivo1);
    printf("Tempos salvos em tempos_Q5.txt\n");

    return 0;
}
