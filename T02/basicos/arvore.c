#include <stdio.h>
#include <stdlib.h>


typedef struct arv{
    int info;
    struct arv* esq;
    struct arv* dir;
} Arv ;

Arv* criaArv(){
    Arv *arv;
    arv = (Arv*) malloc(sizeof(Arv));
    arv->esq = NULL;
    arv->dir = NULL;
    arv->info = 0;
    return arv;
}

void visita(Arv* arv){
    if(!arv->info){
    printf("%d ",arv->info);
    }
    return;
}

void preFix(Arv* arv){
    if(!arv){
    visita(arv);
    pre(arv->esq);
    pre(arv->dir);
    }

    return;
}

void posFix(Arv* arv){
    if(!arv){
    pos(arv->esq);
    pos(arv->dir);
    visita(arv);
    }

    return;
}

void ordem(Arv* arv){
    if(!arv){
    ordem(arv->esq);
    visita(arv);
    ordem(arv->dir);
    }
    
    return;
}
