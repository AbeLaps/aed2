#ifndef  lista_H
#define lista_H

#include "vetor.h"


typedef struct tipoNo {
    int dado;
    struct tipoNo * prox;
}tipoNo;

typedef struct tipoLista {
   tipoNo * prim;

}tipoLista;

void criaLista (tipoLista * l);

int buscaSeq (tipoLista *l, int chave);

void preencheLista (tipoLista *l, int tam);

void preencheListaComVetor (tipoLista *l, tipoVetor *v);


#endif
