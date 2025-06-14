#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include "abp.h"

#define tam 100

int posicaoInsert = 0;
hashItem hashNULO = {NULL, 0, -1};

int hashFunc(long int cpf) {
    return (cpf * 10007) % tam;
}

void criaHashItem(hashItem *itemHash, tipoItem item, unsigned int indexArq) {
    itemHash->index = indexArq;
    itemHash->prox = NULL;
    itemHash->cpf = item.cpf;
}

void inicializaHash(hashItem hash[]){
    for(int i = 0; i < 10000; i++){
    hash[i] = hashNULO;
    }
}

void inserirHash(hashItem hash[], tipoItem item,int indArq) {
    int ind = hashFunc(item.cpf);  // calcula o índice usando o CPF
    hashItem novoItem;
    criaHashItem(&novoItem, item, indArq);

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
    return hashNULO;
}

void popularSistema(FILE *arq, Abp *arv, hashItem hash[]){
    //arq é um arquivo com todos os registros já escritos
    tipoItem item;
    int posArq = 0;
    while(fread(&item, sizeof(tipoItem), 1, arq)){
        insereValAbp(arv, item);
        inserirHash(hash, item, posArq);
        posArq++;
    }
    
}
