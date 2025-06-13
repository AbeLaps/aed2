#ifndef ABP_C
#define ABP_C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abp.h"

Abp* criaAbp(tipoItem val){
    Abp *Arv;
    Arv = (Abp * ) malloc(sizeof(Abp));
    Arv->esq = NULL;
    Arv->dir = NULL;
    Arv->item = val;  // Usando item em vez de info
    return Arv;
}

void visita(Abp* Arv){
    printf("%ld ", Arv->item.cpf);  // Usando item.cpf em vez de info
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

void inFix(Abp* Arv){
    if (Arv != NULL){
        inFix(Arv->esq);
        printf("%ld  ", Arv->item.cpf);  // Usando item.cpf
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

int tamAbp(Abp* Arv){
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

void insereValAbp(Abp* Arv, tipoItem val){
    Abp* aux = Arv;
    while (aux != NULL){
        if (aux->item.cpf < val.cpf){  // Usando item.cpf em vez de info
            if (aux->dir == NULL){
                aux->dir = criaAbp(val);
                return;
            }
            aux = aux->dir;
        }
        else{
            if (aux->esq == NULL){
                aux->esq = criaAbp(val);
                return;
            }
            aux = aux->esq;
        }
    }
    printf("erro: Arvore inserida == null");
    return;
}

void popularAbpRand(Abp* Arv, int tam){
    if (Arv == NULL){ return; }
    for (int i = 0; i < tam; i++){
        tipoItem k;
        k.cpf = rand();
        k.idade = rand() % 100;  // Exemplo de valor aleatório para idade
        k.agencia = rand() % 1000;  // Exemplo de valor aleatório para agência
        snprintf(k.nome, sizeof(k.nome), "Pessoa %d", i);  // Nome fictício
        snprintf(k.email, sizeof(k.email), "pessoa%d@email.com", i);  // Email fictício
        insereValAbp(Arv, k);
    }
}

void liberarArvoreABP(Abp* raiz) {
    if (raiz != NULL) {
        liberarArvoreABP(raiz->esq);
        liberarArvoreABP(raiz->dir);
        free(raiz);
    }
}

void coletaDadosAbp(Abp* Arv, tipoVetor *vetor, int *index) {
    if (Arv != NULL) {
        coletaDadosAbp(Arv->esq, vetor, index);
        vetor->vet[*index] = Arv->item.idade;  // Coleta a idade
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
