#include <stdio.h>
#include <time.h>
#include "vetor.h"
#include "vetor.c"
#include "ABP.c"
#include "ABP.h"


int main(){
    FILE *arquivo1 = fopen("/home/icomp/aed2ss/aed2/T02/q03/tempos_busca_binariaVet.txt", "w");
    if (arquivo1 == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }
    FILE *arquivo2 = fopen("/home/icomp/aed2ss/aed2/T02/q03/tempos_buscaABP.txt", "w");
    if (arquivo2 == NULL) {
       printf("Erro ao abrir arquivo!\n");
       return 1;
    }
    
    tipoVetor v;
    criaVetor(&v,1e3);

    preencheVetorOrdenado(&v);
    int n,k;
    float tempo_tot = 0;

    for(int i = 0;i < 30 ;i++){
        if(i > 15){ //numero aleatorio
            n = rand();
            k=n;
        }
        else{
            n = rand() %(int) 1e3; //numero aleatorio dentro do vetor
            k=v.vet[n];
        }
        clock_t tempoini = clock();
        buscaBin(v,k);
        clock_t tempof = clock();
        tempo_tot = ((float)(tempof - tempoini) / CLOCKS_PER_SEC);
        fprintf(arquivo1, "%d;%.40f\n", i, tempo_tot);
    }
    fclose(arquivo1);
    printf("Tempos salvos em tempos_busca_binariaVet.txt\n");
    printf("comecando");

    Arv* arv = criaArv(v.vet[(v.tam)/2]);
    popularArvVet(arv,&v);
    printf("populei");
    for(int i = 0;i < 30 ;i++){
        if(i > 15){ //numero aleatorio
            n = rand();
            k=n;
        }
        else{
            n = rand() %(int) 1e3; //numero aleatorio dentro do arvore
            k=v.vet[n];
        }
        printf("fazendo...\n");
        clock_t tempoini = clock();
        buscaABP(arv,k);
        clock_t tempof = clock();
        tempo_tot = ((float)(tempof - tempoini) / CLOCKS_PER_SEC);
        fprintf(arquivo2, "%d;%.40f\n", i, tempo_tot);
    }
    fclose(arquivo2);
    printf("Tempos salvos em tempos_busca_binariaABP.txt\n");

    return 1;
}
