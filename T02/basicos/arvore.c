#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvore.h"

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
    if(!arv){
    visita(arv);
    preFix(arv->esq);
    preFix(arv->dir);
    }

    return;
}

void posFix(Arv* arv){
    if(!arv){
    posFix(arv->esq);
    posFix(arv->dir);
    visita(arv);
    }

    return;
}

void ordem(Arv* arv){
    if(arv != NULL){
    ordem(arv->esq);
    visita(arv);
    ordem(arv->dir);
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

void insereArv(Arv* arv, int val){
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

//funcao para teste. nenhuma funcao no trab final
void criaFilhoRand(Arv* arv, int f){
    /*
    se f == 0 popula o no mais a esquerda possivel 
    se f != 0 popula o no mais a direita possivel
    */
    Arv* aux = arv;
    if(f == 0){
        while(aux->esq != NULL){aux = aux->esq;}
    }
    else{
        while(aux->dir != NULL){aux = aux->dir;}
        }

    int k = rand();
    aux->esq = criaArv(k);
    insereArv(aux, k %100); //insere na esq
    aux->dir = criaArv(k);
    insereArv(aux,k); //insere na dir
    return;
}



void popularArvRand(Arv* arv, int tam){
    if(arv == NULL){return;}
    Arv* aux = arv;
    int n = 0;
    criaFilhoRand(arv,0);
    //chamar da esquerda tam *
    while(n < tam - 1){
        criaFilhoRand(aux->esq,0);
        aux = aux->esq;
        n++;
    }
    //chamar da direita tam *
    aux = arv;
    n = 0;
    while(n < tam - 1){
        criaFilhoRand(aux->dir,1);
        aux = aux->dir;
        n++;
    }
}
