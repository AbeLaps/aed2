#ifndef ABP_C
#define ABP_C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abp.h"

Abp* criaAbpCpf(long long int val){
    Abp *Arv;
    Arv = (Abp * ) malloc(sizeof(Abp));
    Arv->esq = NULL;
    Arv->dir = NULL;
    Arv->info = val;  // Usando item em vez de info
    return Arv;
}

void visita(Abp* Arv){
    printf("%ld ", Arv->info);  // Usando item.cpf em vez de info
    return;
}

void preFix(Abp* Arv){
    if (Arv != NULL){
        visita(Arv);
        preFix(Arv->esq);
        preFix(Arv->dir);
    }
    return;
}

void posFix(Abp* Arv){
    if (Arv != NULL){
        posFix(Arv->esq);
        posFix(Arv->dir);
        visita(Arv);
    }
    return;
}

/*
int buscaAbp(AbpCpf* arv, long long int chave) {
    AbpCpf* atual = arv;
    while (atual != NULL) {
        if (chave == atual->val) {
            return 1;  // encontrou
        }
        else if (chave < atual->val) {
            atual = atual->esq;
        }
        else {
            atual = atual->dir;
        }
    }
    return 0;  // não encontrou
}
*/

void inFix(Abp* Arv){
    if (Arv != NULL){
        inFix(Arv->esq);
        printf("%ld  ", Arv->info);  // Usando item.cpf
        inFix(Arv->dir);
    }
    return;
}

int auxTam(Abp* Arv, int tam){
    int tamDir = 0, tamEsq = tam;
    if (Arv->dir != NULL){
        tamDir += 1;
        tamDir = auxTam(Arv->dir, tamDir);
    }
    if (Arv->esq != NULL){
        tamEsq += 1;
        tamEsq = auxTam(Arv->esq, tamEsq);
    }
    if (tamDir > tamEsq){
        return(tamDir);
    }
    else{
        return(tamEsq);
    }
}

int tamAbpCpf(Abp* Arv){
    if (Arv == NULL){
        return(-1);
    }    
    int tamEsq, tamDir = 0;
    Abp * auxDir = Arv->dir; 
    Abp * auxEsq = Arv->esq;
    tamDir = auxTam(auxDir, tamDir);
    tamEsq = auxTam(auxEsq, tamEsq);
    if (tamDir > tamEsq){
        return(tamDir);
    }
    return(tamEsq);
}

void insereValAbpCpf(Abp* Arv, long long int val){
    Abp* aux = Arv;
    while (aux != NULL){
        if (aux->cpf < aux->cpf){  // Usando item.cpf em vez de info
            if (aux->dir == NULL){
                aux->dir = criaAbpCpf(val);
                return;
            }
            aux = aux->dir;
        }
        else{
            if (aux->esq == NULL){
                aux->esq = criaAbpCpf(val);
                return;
            }
            aux = aux->esq;
        }
    }
    printf("erro: Arvore inserida == null");
    return;
}

void popularAbpCpfRand(Abp* Arv, int tam){
    if (Arv == NULL){ return; }
    for (int i = 0; i < tam; i++){
        long long int k;
        k = rand();
        snprintf(k, sizeof(k), "Pessoa %d", i);  // Nome fictício
        snprintf(k, sizeof(k), "pessoa%d@email.com", i);  // Email fictício
        insereValAbpCpf(Arv, k);
    }
}

void liberarArvoreABPCpf(Abp* raiz) {
    if (raiz != NULL) {
        liberarArvoreABPCpf(raiz->esq);
        liberarArvoreABPCpf(raiz->dir);
        free(raiz);
    }
}

void coletaDadosAbpCpf(Abp* Arv, tipoVetor *vetor, int *index) {
    if (Arv != NULL) {
        coletaDadosAbp(Arv->esq, vetor, index);
        vetor->vet[*index] = Arv->info;  // Coleta a idade
        (*index)++;
        coletaDadosAbp(Arv->dir, vetor, index);
    }
}

void calcularEstatisticas(Abp* Arv, tipoVetor *vetor) {
    int index = 0;
    coletaDadosAbp(Arv, vetor, &index);
    printf("Média: %.2f\n", calcularMedia(*vetor));
    printf("Desvio Padrão: %.2f\n", calcularDPVetor(*vetor));
    quickSort(vetor);
    printf("Vetor Ordenado: ");
    for (int i = 0; i < vetor->tam; i++) {
        printf("%d ", vetor->vet[i]);
    }
    printf("\n");
}

#endif
