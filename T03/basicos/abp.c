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
    Arv->item = val;  
    return Arv;
}

void visita(Abp* Arv){
    printf("%ld ", Arv->item);  
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


int buscaAbp(Abp* arv, tipoItem chave) {
    Abp* atual = arv;
    while (atual != NULL) {
        if (chave.cpf == atual->item.cpf) {
            return 1;  // encontrou
        }
        else if (chave.cpf < atual->item.cpf) {
            atual = atual->esq;
        }
        else {
            atual = atual->dir;
        }
    }
    return 0;  // nao encontrou
}

void buscaInterAbp(Abp *raiz, tipoItem idadeBusca, int intervaloMin, int intervaloMax, int flag) {
    if (raiz == NULL) return;

    // Percorre a arvore esquerda
    buscaInterAbp(raiz->esq, idadeBusca, intervaloMin, intervaloMax, flag);

    // Verifica se está no intervalo
    if (raiz->item.idade > intervaloMin && raiz->item.idade < intervaloMax) {
        int condicao = 0;

        switch (flag) {
            case 1: condicao = (raiz->item.idade < idadeBusca.idade); break;
            case 2: condicao = (raiz->item.idade > idadeBusca.idade); break;
            case 3: condicao = (raiz->item.idade <= idadeBusca.idade); break;
            case 4: condicao = (raiz->item.idade >= idadeBusca.idade); break;
            default:
                printf("Flag inválida! Use 1 (<), 2 (>), 3 (<=), 4 (>=)\n");
                return;
        }

        if (condicao) {
            printf("Idade: %lld\n", raiz->item);
        }
    }

    // Percorre arvore direita
    buscaInterAbp(raiz->dir, idadeBusca, intervaloMin, intervaloMax, flag);
}

void inFix(Abp* Arv){
    if (Arv != NULL){
        inFix(Arv->esq);
        printf("%ld  ", Arv->item);  
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

void insereValAbpIdade(Abp* Arv, tipoItem val){
    Abp* aux = Arv;
    while (aux != NULL){
        if (aux->item.idade < aux->item.idade){  // Usando item
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

void insereValAbpCpf(Abp* Arv, tipoItem val){
    Abp* aux = Arv;
    while (aux != NULL){
        if (aux->item.cpf < aux->item.cpf){  // Usando item
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

/*
void popularAbpRand(Abp* Arv, int tam){
    if (Arv == NULL){ return; }
    for (int i = 0; i < tam; i++){
        long long int k;
        k = rand();
        snprintf(k, sizeof(k), "Pessoa %ld", i);  // Nome fictício
        snprintf(k, sizeof(k), "pessoa%ld@email.com", i);  // Email fictício
        insereValAbp(Arv, k);
    }
}
*/

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
        vetor->vet[*index] = Arv->item.cpf;  // Coleta a idade ou cpf
        (*index)++;
        coletaDadosAbp(Arv->dir, vetor, index);
    }
}
/*
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
*/
#endif
