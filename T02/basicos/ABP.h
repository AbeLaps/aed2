#ifndef ABP_H
#define ABP_H

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

void insereValArv(Arv* arv, int val);

void popularArvRand(Arv* arv, int tam);

void pegaMeio (Arv* arv, tipoVetor *v, int ini, int fim);

void popularArvVet(Arv* arv, tipoVetor *vet);

Arv* buscaABP(Arv* arv, int chave);

#endif
