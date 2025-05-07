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

void ordem(Arv* arv);

int tamArv(Arv* arv);

void insereArv(Arv* arv, int val);

void criaFilhoRand(Arv* arv, int f);

void popularArvRand(Arv* arv, int tam);
