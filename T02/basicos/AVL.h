#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Avl {
    int info;
    struct Avl* esq;
    struct Avl* dir;
    struct Avl* pai;
    int fb;
} Avl;

// Cria um novo nó
Avl* criarAvl(int valor);

// Retorna a altura da árvore
int alturaAvl(Avl* no);

// Retorna o máximo entre dois inteiros
int max(int a, int b);

// Atualiza o fator de balanceamento de um nó
void atualizarFB(Avl* no);

// Rotação à esquerda
Avl* rotacaoEsquerda(Avl* no);

// Rotação à direita
Avl* rotacaoDireita(Avl* no);

// Balanceia a árvore
Avl* balancear(Avl* no);

// Insere um valor na árvore
Avl* inserirAvl(Avl* raiz, int valor);

// Percorre a árvore em ordem
void emOrdem(Avl* raiz);

// Libera a memória da árvore
void liberarArvoreAvl(Avl* raiz);

void buscaAvl(Avl* raiz, int chave);

#endif // AVL_H
