#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

// Criar uma nova arvore AVL
Avl* criarAvl(int valor) {
    Avl* novo = (Avl*)malloc(sizeof(Avl));
    if (novo == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    novo->info = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = NULL;
    novo->fb = 0;
    return novo;
}

// retorna a altura da arvore
int alturaAvl(Avl* no) {
    if (no == NULL) return 0;
    return 1 + max(alturaAvl(no->esq), alturaAvl(no->dir));
}

// funcao auxiliar da altura
int max(int a, int b) {
    if (a > b) {
    return a;
    } 
    else {
    return b;
    }
}

void atualizarFB(Avl* no) {
    if (no == NULL) return;
    no->fb = alturaAvl(no->dir) - alturaAvl(no->esq);
}

// rotacoes:
Avl* rotacaoEsquerda(Avl* x) {
    Avl* y = x->dir;
    x->dir = y->esq;
    
    if (y->esq != NULL) {
        y->esq->pai = x;
    }
    
    y->pai = x->pai;
    
    if (x->pai == NULL) {
        y->pai = NULL;
    } else if (x == x->pai->esq) {
        x->pai->esq = y;
    } else {
        x->pai->dir = y;
    }
    
    y->esq = x;
    x->pai = y;
    
    // Update balance factors
    atualizarFB(x);
    atualizarFB(y);
    
    return y;
}


Avl* rotacaoDireita(Avl* y) {
    Avl* x = y->esq;
    y->esq = x->dir;
    
    if (x->dir != NULL) {
        x->dir->pai = y;
    }
    
    x->pai = y->pai;
    
    if (y->pai == NULL) {
        x->pai = NULL;
    } else if (y == y->pai->dir) {
        y->pai->dir = x;
    } else {
        y->pai->esq = x;
    }
    
    x->dir = y;
    y->pai = x;
    
    // atualiza os fatores de balanceamento
    atualizarFB(y);
    atualizarFB(x);
    
    return x;
}

Avl* balancear(Avl* no) {
    if (no == NULL) return NULL;
    
    atualizarFB(no);
    
    // essquerda pesada
    if (no->fb < -1) {
        if (no->esq->fb > 0) {
            // caso LR
            no->esq = rotacaoEsquerda(no->esq);
        }
        // caso LL
        return rotacaoDireita(no);
    }
    // direita pesada
    else if (no->fb > 1) {
        if (no->dir->fb < 0) {
            // caso RL
            no->dir = rotacaoDireita(no->dir);
        }
        // caso RR
        return rotacaoEsquerda(no);
    }
    
    return no;
}

// Inserir um valor na arvore. valor igual vai para direita
Avl* inserirAvl(Avl* raiz, int valor) {
    if (raiz == NULL) {
        return criarAvl(valor);
    }
    
    if (valor < raiz->info) {
        raiz->esq = inserirAvl(raiz->esq, valor);
        raiz->esq->pai = raiz;
    } else /*if (valor > raiz->info)*/ {
        raiz->dir = inserirAvl(raiz->dir, valor);
        raiz->dir->pai = raiz;
    } /*else {
        return raiz;
    }*/
    
    return balancear(raiz);
}

// free na arvore inteira
void liberarArvoreAvl(Avl* raiz) {
    if (raiz != NULL) {
        liberarArvoreAvl(raiz->esq);
        liberarArvoreAvl(raiz->dir);
        free(raiz);
    }
}

void buscaAvl(Avl* raiz, int key){
    while (raiz != NULL) {
        if (raiz->info == key) {
            return;
        } else if (key < raiz->info) {
            raiz = raiz->esq;
        } else {
            raiz = raiz->dir;
        }
    }
    return;
}


