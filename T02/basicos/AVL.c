#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AVL.h"



Avl* criaAvl(int val, Avl *pai){
    Avl *avl;
    avl = (Avl*) malloc(sizeof(Avl));
 avl->esq = NULL;
    avl->dir = NULL;
    avl->info = val;
    avl->pai = pai;
    return avl;
}

// encaminhamentos:

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

void posFixAvl(Avl* avl){
    if(!avl){
    posFix(avl->esq);
    posFix(avl->dir);
    visitaAvl(avl);
    }

    return;
}

void ordemAvl(Avl* avl){
    if(avl != NULL){
    ordemAvl(avl->esq);
    visitaAvl(avl);
    ordemAvl(avl->dir);
    }

    return;
}

//funcoes para calcular a altura de uma avl
int auxTam (Avl*avl, int tam){
    int tamDir = tam, tamEsq = tam;
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

int tamAvl (Avl* avl){
    if (avl == NULL){
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

// busca um no
Avl* buscaAvl(Avl* avl, int val){
    Avl* aux = avl;
    while (aux->dir != NULL && aux->esq != NULL){
        if (aux->info > val){
            if(aux->dir == NULL){return aux;}
            aux = aux->dir;
        }
        else if (aux->info <val){
            if(aux->esq == NULL){return aux;}
            aux = aux->esq;
        }
        else if(aux->info == val){return aux;}
    }
    

}

// rotações:
void rotEsq(Avl * avl){
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
    else{
        paiOri->dir = avl->dir;
        avl->dir->esq = avl;
        avl->dir = NULL;
        avl->pai = paiOri->dir;
        paiOri->dir->pai = paiOri;
        }
    return;
}

void rotDir(Avl * avl){
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
    else{
        paiOri->dir = avl->esq;
        avl->esq->dir = avl;
        avl->esq = NULL;
        avl->pai = paiOri->dir;
        paiOri->dir->pai = paiOri;
        }
    return;
}

void rotDuplaDirEsq(Avl * avl){
    rotEsq(avl);
    rotDir(avl->pai);
}

void rotDuplaEsqDir(Avl * avl){
    rotDir(avl);
    rotEsq(avl->pai);
}

void insereValAvl(Avl * avl, int val){
    


    calcularFBdaArvore(avl);
    return;
}

// funcoes para calcular o fb de todos os nós da arvore
int altura(Avl *no) {
    if (no == NULL) {
        return -1;
    }
    int alturaEsq = altura(no->esq);
    int alturaDir = altura(no->dir);
    return 1 + (alturaEsq > alturaDir ? alturaEsq : alturaDir);
}

// Função para calcular o fator de balanceamento de um nó unico
int calcularFB(Avl * avl) {
    if (avl == NULL) {
        return 0; 
    }
    return altura(avl->esq) - altura(avl->dir);
}

void calcularFBdaArvore(Avl * avl) {
    if (avl != NULL) {
        avl->fb = calcularFB(avl);
        calcularFBdaArvore(avl->esq);
        calcularFBdaArvore(avl->dir);
    }
}
