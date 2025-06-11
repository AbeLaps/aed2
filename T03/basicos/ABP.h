#ifndef ABP_H
#define ABP_H

#include "vetor.h"  // Incluindo vetor.h, pois vamos usar a estrutura de vetor

typedef struct Arv{
    tipoItem item;
    struct Arv* esq;
    struct Arv* dir;
} Arv;

Arv* criaArv(int val);
void visita(Arv* arv);
void preFix(Arv* arv);
void posFix(Arv* arv);
void inFix(Arv* arv);
int tamArv(Arv* arv);
void insereValArv(Arv* arv, int val);
void popularArvRand(Arv* arv, int tam);
void liberarArvoreABP(Arv* raiz);
void coletaDadosArv(Arv* arv, tipoVetor *vetor, int *index);
void calcularEstatisticas(Arv* arv, tipoVetor *vetor);

#endif
