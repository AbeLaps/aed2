#ifndef ABP_H
#define ABP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Arv{
    int info;
    struct Arv* esq;
    struct Arv* dir;
    
} Arv ;

Arv* criaArv(int val);

void visita(Arv* arv);

void preFix(Arv* arv);

void posFix(Arv* arv);

void inFix(Arv* arv);

int tamArv(Arv* arv);

void insereArv(Arv* arv, int val);

void popularArvRand(Arv* arv, int tam);

void pegaMeio (Arv* arv, tipoVetor *v, int ini, int fim);

void popularArvVet(Arv* arv, tipoVetor *vet);

#endif
