#ifndef avl_H
#define avl_H

typedef struct Avl {
    int info;
    Avl * esq;
    Avl * dir;
    int fb;
}Avl;

Avl * criaAvl (int val); 

void insereValAvl (Avl* avl, int val);

void buscaAvl (Avl* avl, int val);

void tamAvl (Avl * avl);

void visitaAvl(Avl* avl);

void preFixAvl(Avl* avl);

void posFixAvl(Avl* avl);

void ordemAvl(Avl* avl);

