#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AVL.h"



Avl* criaAvl(int val){
    Avl *avl;
    avl = (Avl*) malloc(sizeof(Avl));
 avl->esq = NULL;
    avl->dir = NULL;
    avl->info = val;
    return avl;
}

void visitaAvl (Avl * avl){
    printf("%d ",avl->info);
    return;
}

void preFixAvl(Avl* avl){
    if(!avl){
    visitaAvl(avl);
    preFixAvl(avl->esq);
    preFixAvl(avl->dir);
    }
    return;
}

void posFix(Avl* avl){
    if(!avl){
    posFix(avl->esq);
    posFix(avl->dir);
    visitaAvl(avl);
    }

    return;
}

void OrdemAvl(Avl* avl){
    if(avl != NULL){
    Ordem(avl->esq);
    visitaAvl(avl);
    Ordem(avl->dir);
    }

    return;
}

int tamAvl (Avl* avl){
    if (avl ==NULL){
        return(-1);
    }    
    int tamEsq,tamDir = 0;
    Avl* auxDir = avl->dir; 
    Avl* auxEsq = avl->esq;
    tamDir = auxTam(auxDir,tamDir);
    tamEsq = auxTam(auxEsq,tamEsq);
    if (tamDir > tamEsq){
        return(tamDir);
       }
    return(tamEsq);
}
    int auxTam (Avl*avl, int tam){
        int tamDir, tamEsq = tam;
        if (avl->dir != NULL){
            tamDir += 1;
            tamDir = auxTam (avl->dir,tamDir);
        }
        if (avl->esq != NULL){
            tamEsq += 1;
            tamEsq = auxTam (avl->esq,tamEsq);
        }
        if (tamDir>tamEsq){
            return(tamDir);
        }
        else{
            return(tamEsq);
        }
    }

int buscaAvl(Avl* avl, int val){
    Avl* aux = avl;
    while (aux->dir != NULL && aux->esq != NULL){
        if (aux->info > val){
            aux = aux->dir;
        }
        if (aux->info <val){
            aux = aux->esq;
        }
    }

}

void rotEsq(Avl* avl,Avl* root){
    Avl* paiOri = avl->pai;

    int flag = 0;
    if(avl->pai->esq == avl){flag = 1;} // se 1 o no esta a esq
    else{flag = 2;}
    if(flag = 1){
        paiOri->esq = avl->dir;
        avl->dir->esq = avl;
        avl->dir = NULL;
        avl->pai = paiOri->esq;
        paiOri->esq->pai = paiOri;
        }
    else{paiOri->dir = avl->dir;
        avl->dir->esq = avl;
        avl->dir = NULL;
        avl->pai = paiOri->dir;
        paiOri->dir->pai = paiOri;
        }
    return;
}
