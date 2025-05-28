#ifndef ABP_C
#define ABP_C

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
    //if(arv->info != NULL){
    printf("%d ",arv->info);
    //}
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


int auxTam (Arv* arv, int tam){
    int tamDir = 0, tamEsq = tam;
    if (arv->dir != NULL){
        tamDir += 1;
        tamDir = auxTam (arv->dir,tamDir);
    }
    if (arv->esq != NULL){
        tamEsq += 1;
        tamEsq = auxTam (arv->esq,tamEsq);
    }
    if (tamDir>tamEsq){
        return(tamDir);
    }
    else{
        return(tamEsq);
    }
}


int tamArv (Arv* arv){
        if (arv ==NULL){
            return(-1);
        }    
        int tamEsq,tamDir = 0;
        Arv* auxDir = arv->dir; 
        Arv* auxEsq = arv->esq;
        tamDir = auxTam(auxDir,tamDir);
        tamEsq = auxTam(auxEsq,tamEsq);
        if (tamDir > tamEsq){
            return(tamDir);
           }
        return(tamEsq);
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


void liberarArvoreABP(Arv* raiz) {
    if (raiz != NULL) {
        liberarArvoreABP(raiz->esq);
        liberarArvoreABP(raiz->dir);
        free(raiz);
    }
}
#endif
