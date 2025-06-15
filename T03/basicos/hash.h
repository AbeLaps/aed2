#ifndef HASH_H
#define HASH_H

#include "abp.h"
#include <stdio.h>

typedef struct hashItem {
    struct hashItem *prox;
    unsigned int index;
    long int cpf;
} hashItem;

int hashFunc(long int cpf);
void criaHashItem(hashItem *itemHash, tipoItem item, unsigned int indexArq);
void inicializaHash(hashItem hash[]);
void inserirHash(hashItem hash[], tipoItem item,int indArq);
hashItem buscaHash(hashItem hash[], long int cpf);
//int EscreverNoArquivo(hashItem *item, FILE *fp, int *pos);
void popularSistema(FILE *arq, Abp *arvCpf,Abp *arvIdade, hashItem hash[]);
void buscaArq(FILE *arquivo, long long int idadeBusca, int intervaloMin, int intervaloMax, int flag);
void buscaSeqArq(FILE *arquivo, long long int cpfBusca);
#endif
