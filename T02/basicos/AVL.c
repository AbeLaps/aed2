#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AVL.h"



Avl* criaAvl(int val, Avl *pai){
    Avl *avl;
    avl = (Avl*) malloc(sizeof(Avl));
    if(avl == NULL){printf("morri total"); abort();}
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
    if(avl != NULL){
    visitaAvl(avl);
    preFixAvl(avl->esq);
    preFixAvl(avl->dir);
    }
    return;
}

void posFixAvl(Avl* avl){
    if(avl != NULL){
    posFixAvl(avl->esq);
    posFixAvl(avl->dir);
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

// busca
int buscaAvl(Avl* avl, int val) {
    Avl *atual = avl;
    while (atual != NULL) {
        if (val == atual->info) {
            return 1; 
        } else if (val < atual->info) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }
    return 0; 
}

// rotações:
void rotEsq(Avl *avl){
    if (avl == NULL || avl->dir == NULL) return; // Segurança: verifica se avl e seu filho direito existem

    Avl *dir = avl->dir;
    Avl *paiOri = avl->pai;

    avl->dir = dir->esq; // Filho esquerdo de dir se torna filho direito de avl
    if (dir->esq != NULL) {
        dir->esq->pai = avl;
    }

    dir->esq = avl;     // avl se torna filho esquerdo de dir
    avl->pai = dir;     // pai de avl agora é dir

    dir->pai = paiOri;  // pai de dir agora é o antigo pai de avl

    if (paiOri != NULL) {
        if (avl == paiOri->esq) {
            paiOri->esq = dir; // Atualiza o filho esquerdo do pai original
        } else {
            paiOri->dir = dir; // Atualiza o filho direito do pai original
        }
    }
    calcularFBdaArvore(avl);
    calcularFBdaArvore(dir);
}

void rotDir(Avl *avl) {
    if (avl == NULL || avl->esq == NULL) return; // Segurança: verifica se avl e seu filho esquerdo existem

    Avl *esq = avl->esq;
    Avl *paiOri = avl->pai;

    avl->esq = esq->dir; // Filho direito de esq se torna filho esquerdo de avl
    if (esq->dir != NULL) {
        esq->dir->pai = avl;
    }

    esq->dir = avl;     // avl se torna filho direito de esq
    avl->pai = esq;     // pai de avl agora é esq

    esq->pai = paiOri;  // pai de esq agora é o antigo pai de avl

    if (paiOri != NULL) {
        if (avl == paiOri->esq) {
            paiOri->esq = esq; // Atualiza o filho esquerdo do pai original
        } else {
            paiOri->dir = esq; // Atualiza o filho direito do pai original
        }
    }

    calcularFBdaArvore(avl);
    calcularFBdaArvore(esq);
}

void rotDuplaDirEsq(Avl * avl){
    rotEsq(avl);
    rotDir(avl->pai);
}

void rotDuplaEsqDir(Avl * avl){
    rotDir(avl);
    rotEsq(avl->pai);
}



// funcoes para calcular o fb de todos os nós da arvore
int altura(Avl *avl) {
    if (avl == NULL) {
        return -1;
    }
    int alturaEsq = altura(avl->esq);
    int alturaDir = altura(avl->dir);
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

Avl* balancear(Avl *avl) {
    calcularFBdaArvore(avl); // Recalcula o FB de todos os nós

    if (avl->fb == 2) {
        if (calcularFB(avl->dir) < 0) {
            rotDuplaDirEsq(avl);
        } else {
            rotEsq(avl);
        }
    } else if (avl->fb == -2) {
        if (calcularFB(avl->esq) > 0) {
            rotDuplaEsqDir(avl);
        } else {
            rotDir(avl);
        }
    }
    return avl;
}

void insereValAvl(Avl** avl, int val) {
    if (*avl == NULL) {
        *avl = criaAvl(val, NULL);
        return;
    }

    Avl *atual = *avl;
    Avl *pai = NULL;

    while (atual != NULL) {
        pai = atual;
        if (val < atual->info) {
            atual = atual->esq;
        } else if (val > atual->info) {
            atual = atual->dir;
        } else {
           
            return;
        }
    }

    Avl *novo_no = criaAvl(val, pai);
    if (val < pai->info) {
        pai->esq = novo_no;
    } else {
        pai->dir = novo_no;
    }

    // Balancear a avl
    Avl *no_atual = pai;
    while (no_atual != NULL) {
        Avl *novo_pai = no_atual->pai;
        Avl *balanceado = balancear(no_atual);
        if (novo_pai != NULL) {
            if (no_atual == novo_pai->esq) {
                novo_pai->esq = balanceado;
            } else {
                novo_pai->dir = balanceado;
            }
        } else {
            *avl = balanceado;
        }
        no_atual = novo_pai;
    }
}

