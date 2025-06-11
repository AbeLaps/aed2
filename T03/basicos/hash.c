#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"

#define tam 100

hashItem NULO = {NULL, 0, -1};

int hashFunc(long int cpf) {
    return (cpf * 10007) % tam;
}

void criaHashItem(hashItem *itemHash, tipoItem item, unsigned int index) {
    itemHash->index = index;
    itemHash->prox = NULL;
    itemHash->cpf = item.cpf;
}

//hashItem hash[10000]

void limpaHash(hashItem hash[]){
    for(int i = 0; i < 10000; i++){
    hash[i] = NULO;
    }
}

void inserirHash(hashItem hash[], tipoItem item) {
    int ind = hashFunc(item.cpf);  // calcula o índice usando o CPF
    hashItem novoItem;
    criaHashItem(&novoItem, item, ind);

    // encadeamento caso já tenha um objeto posicionado
    if (hash[ind].cpf != -1 ) {
        novoItem.prox = &hash[ind];
        hash[ind] = novoItem;
    } else {
        hash[ind] = novoItem;  // caso contrário, simplesmente coloca na posição
    }
}

hashItem buscaHash(hashItem hash[], long int cpf) {
    int ind = hashFunc(cpf);
    hashItem aux = hash[ind];

    // percorre a lista encadeada até encontrar o CPF ou chegar ao final
    while (aux.cpf != -1) {
        if (aux.cpf == cpf) {
            return aux;
        }
        aux = *(aux.prox);
    }
    return NULO;
}

int EscreverNoArquivo(hashItem *item, FILE *fp, int *pos) {
    item->index = *pos;
    fseek(fp, *pos * sizeof(hashItem), SEEK_SET);
    fwrite(item, sizeof(hashItem), 1, fp);
    *pos += 1;
    return 0;
}

void popularSistema(FILE *arq, Arv *arv, hashItem hash[]) {
    tipoItem item;
    int pos = 0;
    while (fread(&item, sizeof(tipoItem), 1, arq)) {
        insereValArv(arv, item.cpf);
        inserirHash(hash, item);
        pos++;
    }
}
