#ifndef ABP_C
#define ABP_C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ABP.h"

Arv* criaArv(tipoItem val){
    Arv *arv;
    arv = (Arv*) malloc(sizeof(Arv));
    arv->esq = NULL;
    arv->dir = NULL;
    arv->item = val;  // Usando item em vez de info
    return arv;
}

void visita(Arv* arv){
    printf("%ld ", arv->item.cpf);  // Usando item.cpf em vez de info
    return;
}

void preFix(Arv* arv){
    if (arv != NULL){
        visita(arv);
        preFix(arv->esq);
        preFix(arv->dir);
    }
    return;
}

void posFix(Arv* arv){
    if (arv != NULL){
        posFix(arv->esq);
        posFix(arv->dir);
        visita(arv);
    }
    return;
}

void inFix(Arv* arv){
    if (arv != NULL){
        inFix(arv->esq);
        printf("%ld  ", arv->item.cpf);  // Usando item.cpf
        inFix(arv->dir);
    }
    return;
}

int auxTam(Arv* arv, int tam){
    int tamDir = 0, tamEsq = tam;
    if (arv->dir != NULL){
        tamDir += 1;
        tamDir = auxTam(arv->dir, tamDir);
    }
    if (arv->esq != NULL){
        tamEsq += 1;
        tamEsq = auxTam(arv->esq, tamEsq);
    }
    if (tamDir > tamEsq){
        return(tamDir);
    }
    else{
        return(tamEsq);
    }
}

int tamArv(Arv* arv){
    if (arv == NULL){
        return(-1);
    }    
    int tamEsq, tamDir = 0;
    Arv* auxDir = arv->dir; 
    Arv* auxEsq = arv->esq;
    tamDir = auxTam(auxDir, tamDir);
    tamEsq = auxTam(auxEsq, tamEsq);
    if (tamDir > tamEsq){
        return(tamDir);
    }
    return(tamEsq);
}

void insereValArv(Arv* arv, tipoItem val){
    Arv* aux = arv;
    while (aux != NULL){
        if (aux->item.cpf < val.cpf){  // Usando item.cpf em vez de info
            if (aux->dir == NULL){
                aux->dir = criaArv(val);
                return;
            }
            aux = aux->dir;
        }
        else{
            if (aux->esq == NULL){
                aux->esq = criaArv(val);
                return;
            }
            aux = aux->esq;
        }
    }
    printf("erro: arvore inserida == null");
    return;
}

void popularArvRand(Arv* arv, int tam){
    if (arv == NULL){ return; }
    for (int i = 0; i < tam; i++){
        tipoItem k;
        k.cpf = rand();
        k.idade = rand() % 100;  // Exemplo de valor aleatório para idade
        k.agencia = rand() % 1000;  // Exemplo de valor aleatório para agência
        snprintf(k.nome, sizeof(k.nome), "Pessoa %d", i);  // Nome fictício
        snprintf(k.email, sizeof(k.email), "pessoa%d@email.com", i);  // Email fictício
        insereValArv(arv, k);
    }
}

void liberarArvoreABP(Arv* raiz) {
    if (raiz != NULL) {
        liberarArvoreABP(raiz->esq);
        liberarArvoreABP(raiz->dir);
        free(raiz);
    }
}

void coletaDadosArv(Arv* arv, tipoVetor *vetor, int *index) {
    if (arv != NULL) {
        coletaDadosArv(arv->esq, vetor, index);
        vetor->vet[*index] = arv->item.idade;  // Coleta a idade
        (*index)++;
        coletaDadosArv(arv->dir, vetor, index);
    }
}

void calcularEstatisticas(Arv* arv, tipoVetor *vetor) {
    int index = 0;
    coletaDadosArv(arv, vetor, &index);
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
