#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ABP.h"

Arv* criaArv(int val){
    Arv *arv;
    arv = (Arv*) malloc(sizeof(Arv));
    arv->esq = NULL;
    arv->dir = NULL;
    arv->info = val;
    return arv;
}

void visita(Arv* arv){
    printf("%d ",arv->info);
    
    return;
}

void preFix(Arv* arv){
    if(arv != NULL){
    visita(arv);
    preFix(arv->esq);
    preFix(arv->dir);
    }

    return;
}

void posFix(Arv* arv){
    if(arv != NULL){
    posFix(arv->esq);
    posFix(arv->dir);
    visita(arv);
    }

    return;
}

void inFix(Arv* arv){
    if(arv != NULL){
    inFix(arv->esq);
    printf("%d  ",arv->info);
    inFix(arv->dir);
    }
    return;
}

int tamArv(Arv* arv){
    Arv* aux = arv;
    int tam = 0;
    while(aux!=NULL){
        printf("a");
    }
    return 0;
}

void insereValArv(Arv* arv, int val){
    Arv* aux = arv;
    while(aux != NULL){
    if(aux->info < val){
        if(aux->dir == NULL){
            aux->dir = criaArv(val);
            return;
        }
        aux = aux->dir;
    }
    else{
        if(aux->esq == NULL){
            aux->esq = criaArv(val);
            return;
        }
        aux=aux->esq;
    }
    }
    printf("erro: arvore inserida == null");
    return;
}


void popularArvRand(Arv* arv, int tam){
    if(arv == NULL){return;}
    for(int i = 0; i < tam;i++){
        int k = rand();
        insereValArv(arv,k);
    }
}

int pegaMeio (Arv* arv, tipoVetor *v, int ini, int fim){
    int i = ini;
    int j = fim;
    int meio = (i+j)/2 ;
    //insereArv(arv, v[meio]);
    if(ini == fim){return v->vet[meio];}
    insereValArv(arv, pegaMeio(arv, v, 0, j -1));
    insereValArv(arv, pegaMeio(arv, v,j+1, v->tam));
    return v->vet[meio];
}
void popularArvVet(Arv* arv, tipoVetor *vet){
    if(vet == NULL){return;}
    pegaMeio(arv, vet, 0, vet->tam);
}

Arv* buscaABP(Arv* arv, int chave){
    if (arv == NULL || arv->info == chave) {
        return arv;
    }
    else if (arv->info < chave) {
        return buscaABP(arv->dir, chave);
    }
    else {
        return buscaABP(arv->esq, chave);
    }
}
