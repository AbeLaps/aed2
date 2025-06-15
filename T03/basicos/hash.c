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
        novoItem.prox = &hashNULO;
        hash[ind] = novoItem;  // caso contrário, simplesmente coloca na posição
    }
}

hashItem buscaHash(hashItem hash[], long int cpf) {
    int ind = hashFunc(cpf);
    hashItem aux = hash[ind];

    // percorre a lista encadeada até encontrar o CPF ou chegar ao final
    while (aux.cpf != -1) {
        printf("andando");
        printf("%ld\n",aux.prox);
        printf("%d", &aux);
        if (aux.cpf == cpf) {
            return aux;
        }
        aux = *(aux.prox);
    }
    return hashNULO;
}

void popularSistema(FILE *arq, Abp *arvCpf, Abp *arvIdade, hashItem hash[]){
    tipoItem item;
    int posArq = 0;
    while(fread(&item, sizeof(tipoItem), 1, arq)){
        insereValAbpCpf(arvCpf, item);
        insereValAbpIdade(arvIdade, item);
        inserirHash(hash, item, posArq);
        posArq++;
    }
    
}

void buscaArq(FILE *arquivo, long long int idadeBusca, int intervaloMin, int intervaloMax, int flag) {
    tipoItem item;
    int encontrou = 0;

    // Volta ao início do arquivo
    fseek(arquivo, 0, SEEK_SET);

    while (fread(&item, sizeof(tipoItem), 1, arquivo) == 1) {
        //printf("%ld\n",item.cpf);
        // Verifica se a idade do item está no intervalo exclusivo (intervaloMin, intervaloMax)
        if (item.idade > intervaloMin && item.idade < intervaloMax) {
            int condicao = 0;

            switch (flag) {
                case 1: condicao = (item.idade < idadeBusca); break;
                case 2: condicao = (item.idade > idadeBusca); break;
                case 3: condicao = (item.idade <= idadeBusca); break;
                case 4: condicao = (item.idade >= idadeBusca); break;
                default:
                    printf("Flag invalida! Use 1 (<), 2 (>), 3 (<=), 4 (>=)\n");
                    return;
            }

            if (condicao) {
                encontrou = 1;
                //printf("CPF: %lld | Idade: %u | Agencia: %d | Nome: %s | Email: %s\n",
                       //item.cpf, item.idade, item.agencia, item.nome, item.email);
            }
        }
    }

    if (!encontrou) {
        printf("Nenhum registro encontrado com os criterios especificados.\n");
    }
}

void buscaSeqArq(FILE *arquivo, long long int cpfBusca) {
    tipoItem item;

    // Volta ao início do arquivo
    fseek(arquivo, 0, SEEK_SET);

    while (fread(&item, sizeof(tipoItem), 1, arquivo) == 1){
        if (item.cpf == cpfBusca) {
            printf("Registro encontrado:\n");
            printf("CPF: %lld | Idade: %u | Agencia: %d | Nome: %s | Email: %s\n",
                   item.cpf, item.idade, item.agencia, item.nome, item.email);
            return;
        }
    }

    printf("CPF %lld nao encontrado.\n", cpfBusca);
}

