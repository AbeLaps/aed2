#include "lista.h"


void criaLista (tipoLista *l){
    tipoLista->prim = NULL;
}


int buscaSeqLista (tipolista *l, int key){
    if(l->prim == NULL){
        return 0;
        }
   else{ aux = l->prim->dado;
        while(aux ->dado != key){
            aux = aux->prox;
        }
    }
}

void preencheListaComVetor (tipoLista*l, tipoVetor *v){
    int i = tipoVetor->tam;
    int j = 1;
    tipoNo * aux;
    aux =(tipoNo)malloc(sizeof(tipoNo));
    aux->dado = v->vet[0];
    while (i != j){
        aux->prox =(tipoNo)malloc(sizeof(tipoNo));
        aux->dado = v->vet[j];
        aux = aux->prox;
        j++;
    }
}



