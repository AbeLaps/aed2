#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Avl {
    int info;
    struct Avl *esq;
    struct Avl *dir;
    struct Avl *pai;
    int fb;
} Avl;

Avl* criaAvl(int val, Avl *pai);

int tamAvl (Avl * avl);

void visitaAvl(Avl* avl);

void preFixAvl(Avl* avl);

void posFixAvl(Avl* avl);

void ordemAvl(Avl* avl);

void insereValAvl(Avl** raiz, int val);

int buscaAvl(Avl* avl, int val);

int altura(Avl *no);

int calcularFB(Avl *avl);

void calcularFBdaArvore(Avl *avl);

void rotEsq(Avl *avl);

void rotDir(Avl *avl);

void rotDuplaDirEsq(Avl *avl);

void rotDuplaEsqDir(Avl *avl);

#endif // AVL_H
