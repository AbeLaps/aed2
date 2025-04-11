#ifdef  lista_H
#define lista_H

#include "vetor.h"


typedef struct tipoNo {
    int dado;
    struct tipoNo * prox;
}tipoNo;

typedef struct tipoLista {
   tipoNo * prim;

}tipoLista;

void criaLista (tipolista * l);

int buscaSeq (tipoLista *l, int chave);

void preencheLista (tipoLista *l, unsigned tam);

void preencheListaComVetor (tipolista *l, tipoVetor *v);


#endif
