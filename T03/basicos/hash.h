#ifndef HASH_H
#define HASH_H

#include "ABP.h"

typedef struct hashItem {
    struct hashItem *prox;
    unsigned int index;
    long int cpf;
} hashItem;

int hashFunc(long int cpf);
void criaHashItem(hashItem **itemHash, tipoItem item, unsigned int index);
void inserirHash(hashItem hash[], tipoItem item);
hashItem* buscaHash(hashItem hash[], long int cpf);
int EscreverNoArquivo(hashItem *item, FILE *fp, int *pos);
void popularSistema(FILE *arq, Arv *arv, hashItem hash[]);

#endif
