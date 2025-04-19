/*Nomes:
Abel Andrade Prazeres dos Santos
Bruna de Souza Brasil
Gabriel Gregório dos Santos Vitor
Gabriela Silva Malveira

*/

#include "vetor.h"
#include "vetor.c"
#include "lista.c"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main(){
    FILE *arquivo1 = fopen("tempos_busca_seq.txt", "w");
    if (arquivo1 == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }
    FILE *arquivo2 = fopen("tempos_busca_lista.txt", "w");
    if (arquivo2 == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }
    
    tipoVetor v;
    tipoLista l1;
    criaVetor(&v,1e6);
    criaLista(&l1);
    preencheVetor(&v);
    preencheListaComVetor(&l1, &v);

    int n,k;
    float tempo_tot = 0;

    for(int i = 0; i < 30 ; i++){
        if(i > 15){ //numero aleatorio
            n = rand();
            k=n;
        }
        else{
            n = rand() %(int) 1e6; //numero aleatorio dentro do vetor/lista
            k=v.vet[n];
        }
        clock_t tempoini = clock();
        buscaSeqVetor(v,k);
        clock_t tempof = clock();
        tempo_tot = ((float)(tempof - tempoini) / CLOCKS_PER_SEC);
        fprintf(arquivo1, "vetor: %d;%.12f\n", i, tempo_tot);

        clock_t tempoini = clock();
        buscaSeqLista(&l1,k);
        clock_t tempof = clock();
        tempo_tot = (float)(tempof - tempoini) / CLOCKS_PER_SEC;
        fprintf(arquivo2, "lista: %d;%.12f\n", i, tempo_tot);
    }
    fclose(arquivo1);
    printf("Tempos salvos em tempos_busca_seq.txt\n");
    fclose(arquivo2);
    printf("Tempos salvos em tempos_busca_lista.txt\n");

    return 1;
}
