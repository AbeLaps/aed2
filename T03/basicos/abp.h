#ifndef ABP_H
#define ABP_H

#include "vetor.h"  // Incluindo vetor.h, pois vamos usar a estrutura de vetor

typedef struct Abp{
    tipoItem item;
    struct Abp* esq;
    struct Abp* dir;
} Abp;


Abp* criaAbp(tipoItem item);
void visita(Abp* Abp);
void preFix(Abp* Abp);
void posFix(Abp* Abp);
void inFix(Abp* Abp);
//int tamAbp(Abp* Abp);
void insereValAbpIdade(Abp* Arv, tipoItem);
void insereValAbpCpf(Abp* Arv, tipoItem);
int buscaAbp(Abp* arv, tipoItem chave);
void buscaInterAbp(Abp *raiz, tipoItem idadeBusca, int intervaloMin, int intervaloMax, int flag);
//void popularAbpRand(Abp* Abp, int tam);
void liberarArvoreABP(Abp* raiz);
//void coletaDadosAbp(Abp* Abp, tipoVetor *vetor, int *index);
//void calcularEstatisticas(Abp* Abp, tipoVetor *vetor);

#endif
