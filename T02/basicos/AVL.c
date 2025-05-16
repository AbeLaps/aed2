#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AVL.h"

Avl* criaAvl(int val, Avl* pai) {
    Avl* avl;
    avl = (Avl*)malloc(sizeof(Avl));
    if (avl == NULL) {
        printf("morri total");
        abort();
    }
    avl->esq = NULL;
    avl->dir = NULL;
    avl->info = val;
    avl->pai = pai;
    avl->fb = 0; 
    return avl;
}

void visitaAvl(Avl* avl) {
    printf("%d ", avl->info);
}

void preFixAvl(Avl* avl) {
    if (avl != NULL) {
        visitaAvl(avl);
        preFixAvl(avl->esq);
        preFixAvl(avl->dir);
    }
}

void posFixAvl(Avl* avl) {
    if (avl != NULL) {
        posFixAvl(avl->esq);
        posFixAvl(avl->dir);
        visitaAvl(avl);
    }
}

void ordemAvl(Avl* avl) {
    if (avl != NULL) {
        ordemAvl(avl->esq);
        visitaAvl(avl);
        ordemAvl(avl->dir);
    }
}

int auxTam(Avl* avl, int tam) {
    int tamDir = tam, tamEsq = tam;
    if (avl->dir != NULL) {
        tamDir += 1;
        tamDir = auxTam(avl->dir, tamDir);
    }
    if (avl->esq != NULL) {
        tamEsq += 1;
        tamEsq = auxTam(avl->esq, tamEsq);
    }
    if (tamDir > tamEsq) {
        return tamDir;
    } else {
        return tamEsq;
    }
}

int tamAvl(Avl* avl) {
    if (avl == NULL) {
        return -1;
    }
    int tamEsq = 0, tamDir = 0;
    Avl* auxDir = avl->dir;
    Avl* auxEsq = avl->esq;
    tamDir = auxTam(auxDir, tamDir);
    tamEsq = auxTam(auxEsq, tamEsq);
    if (tamDir > tamEsq) {
        return tamDir;
    }
    return tamEsq;
}

int buscaAvl(Avl* avl, int val) {
    Avl* atual = avl;
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

int altura(Avl* avl) {
    if (avl == NULL) {return -1;}
    int alturaEsq = altura(avl->esq);
    int alturaDir = altura(avl->dir);
    if (alturaEsq > alturaDir) {
    return 1 + alturaEsq;
    } else {
    return 1 + alturaDir;
    }
}

int calcularFB(Avl* avl) {
    if (avl == NULL) {return 0;}
    return altura(avl->esq) - altura(avl->dir);
}

void calcularFBdaArvore(Avl* avl) {
    if (avl != NULL) {
        avl->fb = calcularFB(avl);
    }
}

void rotEsq(Avl *avl) {
    if (avl == NULL || avl->dir == NULL) return;
    
    Avl* newRoot = avl->dir;
    Avl* paiOri = avl->pai;
    
    avl->dir = newRoot->esq;
    if (newRoot->esq != NULL) {
        newRoot->esq->pai = avl;
    }
    newRoot->esq = avl;
    avl->pai = newRoot;
    
    // atualiza filho do paiOri's 
    if (paiOri != NULL) {
        if (paiOri->esq == avl) {
            paiOri->esq = newRoot;
        } else {
            paiOri->dir = newRoot;
        }
    }
    newRoot->pai = paiOri;
    
    calcularFBdaArvore(avl);
    calcularFBdaArvore(newRoot);
}

void rotDir(Avl* avl) {
    if (avl == NULL || avl->esq == NULL) return;
    
    Avl* newRoot = avl->esq;
    Avl* paiOri = avl->pai;
    
    // faz a rotação
    avl->esq = newRoot->dir;
    if (newRoot->dir != NULL) {
        newRoot->dir->pai = avl;
    }
    newRoot->dir = avl;
    avl->pai = newRoot;
    
    // atualiza filho do paiOri's 
    if (paiOri != NULL) {
        if (paiOri->esq == avl) {
            paiOri->esq = newRoot;
        } else {
            paiOri->dir = newRoot;
        }
    }
    newRoot->pai = paiOri;
    
    calcularFBdaArvore(avl);
    calcularFBdaArvore(newRoot);
}

void rotDuplaDirEsq(Avl* avl) {
    if (avl == NULL) return;
    rotDir(avl->dir);
    rotEsq(avl);
}

void rotDuplaEsqDir(Avl* avl) {
    if (avl == NULL) return;
    rotEsq(avl->esq);
    rotDir(avl);
}


void balancear(Avl** avl) {
    if (*avl == NULL) return;

    calcularFBdaArvore(*avl);
    
    if ((*avl)->fb >= 2) {
        if ((*avl)->dir != NULL && (*avl)->dir->fb < 0) {
            rotDuplaDirEsq(*avl);
        } else {
            rotEsq(*avl);
        }
    } else if ((*avl)->fb <= -2) {
        if ((*avl)->esq != NULL && (*avl)->esq->fb > 0) {
            rotDuplaEsqDir(*avl);
        } else {
            rotDir(*avl);
        }
    }
}


void insereValAvl(Avl** avl, int val) {
    if (*avl == NULL) {
        *avl = criaAvl(val, NULL);
        return;
    }

    Avl* atual = *avl;
    Avl* pai = NULL;

    while (atual != NULL) {
        pai = atual;
        if (val < atual->info) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }

    Avl* novo_no = criaAvl(val, pai);
    if (val < pai->info) {
        pai->esq = novo_no;
    } else {
        pai->dir = novo_no;
    }

    atual = pai;
    while (atual != NULL) {
        calcularFBdaArvore(atual);
        
        Avl* paiOri = atual->pai;
        
        if (atual->fb > 1 || atual->fb < -1) {
            balancear(&atual);
            
            if (paiOri == NULL) {
                *avl = atual;
            }
        }
        
        atual = paiOri;
    }
}

void liberaAvl(Avl* avl) {
    if (avl != NULL) {
        liberaAvl(avl->esq);
        liberaAvl(avl->dir);
        free(avl);
    }
}

