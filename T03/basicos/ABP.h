#ifndef ABP_H
#define ABP_H

#include "hash.h"
//#include "vetor.h"

typedef struct Arv{
    tipoItem item;
    struct Arv* esq;
    struct Arv* dir;
    
} Arv ;

Arv* criaArv(tipoItem val);

void visita(Arv* arv);

void preFix(Arv* arv);

void posFix(Arv* arv);

void inFix(Arv* arv);

int tamArv(Arv* arv);

void insereValArv(Arv* arv, tipoItem val);

void popularArvRand(Arv* arv, int tam);

Arv* buscaABP(Arv* arv, int chave);

void liberarArvoreABP(Arv* raiz);

#endif
