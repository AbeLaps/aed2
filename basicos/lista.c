#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void criaLista (tipoLista *l){
    l->prim = NULL;
}


int buscaSeqLista (tipoLista *l, int key){
    if(l->prim == NULL){
        return 0;
        }
   else { tipoNo *  aux = l->prim;
        while(aux ->dado != key){
            aux = aux->prox;
        }
    }
}


void preencheListaComVetor (tipoLista*l, tipoVetor *v){
    int i = v->tam;
    int j = 1;
    tipoNo * aux;
    aux =(tipoNo*)malloc(sizeof(tipoNo));
    aux->dado = v->vet[0];
    while (i != j){
        aux->prox =(tipoNo*)malloc(sizeof(tipoNo));
        aux->dado = v->vet[j];
        aux = aux->prox;
        j++;
    }
}


void preencheLista (tipoLista *l, int tam){
    int i = 0;
    tipoNo * aux;
    aux = (tipoNo *)malloc(sizeof(tipoNo));
     aux->dado = rand();
    while(i != tam){
        aux->prox =(tipoNo*)malloc(sizeof(tipoNo));
        aux = aux->prox;
        aux->dado = rand();
        i++;
    }    
}




