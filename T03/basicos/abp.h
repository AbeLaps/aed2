#ifndef ABP_H
#define ABP_H

#include "vetor.h"  // Incluindo vetor.h, pois vamos usar a estrutura de vetor

typedef struct Abp{
    long long int info;
    struct Abp* esq;
    struct Abp* dir;
} Abp;


Abp* criaAbp(long long int);
void visita(Abp* Abp);
void preFix(Abp* Abp);
void posFix(Abp* Abp);
void inFix(Abp* Abp);
//int tamAbp(Abp* Abp);
void insereValAbpCpf(Abp* Arv, long long int val);
//void popularAbpRand(Abp* Abp, int tam);
void liberarArvoreABP(Abp* raiz);
//void coletaDadosAbp(Abp* Abp, tipoVetor *vetor, int *index);
//void calcularEstatisticas(Abp* Abp, tipoVetor *vetor);

#endif
