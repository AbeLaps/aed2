#ifndef ABP_H
#define ABP_H

//#include "vetor.h"  

/*
Integrantes do grupo:
Abel Andrade Prazeres dos Santos
Gabriela Silva Malveira
Bruna de Souza Brasil
Gabriel Gregório dos Santos Vitor
*/

typedef struct tipoItem {
    long long int cpf;
    unsigned int idade;
    int agencia;
    char nome[65];
    char email[25];
} tipoItem;

typedef struct Abp{
    tipoItem item;
    struct Abp* esq;
    struct Abp* dir;
} Abp;

Abp* criaAbp(tipoItem item);

void insereValAbpIdade(Abp* Arv, tipoItem);

void insereValAbpCpf(Abp* Arv, tipoItem);

int buscaAbp(Abp* arv, tipoItem chave);

void buscaInterAbp(Abp* raiz, int idadeBase, int flag);

/*
void visita(Abp* Abp);
//void preFix(Abp* Abp);
//void posFix(Abp* Abp);
//void inFix(Abp* Abp);
//int tamAbp(Abp* Abp);
//void popularAbpRand(Abp* Abp, int tam);
//void liberarArvoreABP(Abp* raiz);
//void coletaDadosAbp(Abp* Abp, tipoVetor *vetor, int *index);
//void calcularEstatisticas(Abp* Abp, tipoVetor *vetor);
*/

#endif
