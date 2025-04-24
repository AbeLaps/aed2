#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cria uma lista vazia
void criaLista(tipoLista *l) {
    l->prim = NULL;
}

// Busca sequencial segura na lista
int buscaSeqLista(tipoLista *l, int key) {
    tipoNo *aux = l->prim;
    while (aux != NULL) {
        if (aux->dado == key)
            return 1;
        aux = aux->prox;
    }
    return 0;
}

// Preenche uma lista a partir de um vetor
void preencheListaComVetor(tipoLista *l, tipoVetor *v) {
    if (v->tam == 0) {
        l->prim = NULL;
        return;
    }

    tipoNo *novo = (tipoNo *)malloc(sizeof(tipoNo));
    novo->dado = v->vet[0];
    novo->prox = NULL;
    l->prim = novo;

    tipoNo *aux = novo;
    for (int i = 1; i < v->tam; i++) {
        tipoNo *novo = (tipoNo *)malloc(sizeof(tipoNo));
        novo->dado = v->vet[i];
        novo->prox = NULL;
        aux->prox = novo;
        aux = novo;
    }
}

// Preenche uma lista com inteiros aleatórios
void preencheLista(tipoLista *l, int tam) {
    if (tam == 0) {
        l->prim = NULL;
        return;
    }

    tipoNo *novo = (tipoNo *)malloc(sizeof(tipoNo));
    novo->dado = rand();
    novo->prox = NULL;
    l->prim = novo;

    tipoNo *aux = novo;
    for (int i = 1; i < tam; i++) {
        tipoNo *novo = (tipoNo *)malloc(sizeof(tipoNo));
        novo->dado = rand();
        novo->prox = NULL;
        aux->prox = novo;
        aux = novo;
    }
}
