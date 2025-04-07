/*operacoes do vetor aqui */
#include <vetor.h>
#include <stdio.h>
#include <stdlib.h>

void preencheVetor(tipoVetor *v){
    srand(time(NULL));
    unsigned tam = v->tam;
    int k;
    for(int i = 0; i < tam; i++){
        k = rand();
        v->vet[i] = k;
    }
}

void preencheVetorOrdenado(tipoVetor *v){
    srand(time(NULL));  
    unsigned tam = v->tam;
    int k, k1 = 0;

    for(int i = 0; i < tam; i++){
        k = rand() % 20000 + 1;
        k1 += k;
        v->vet[i] = k1;
    }
}



void mergeSortR(tipoVetor *v, int aux[], int inicio, int fim) {

  int a,b,k;

  if(inicio < fim) {

    int meio = (inicio+fim)/2;
    mergeSortR(v, aux, inicio, meio);
    mergeSortR(v, aux, meio+1, fim);
  
    a = inicio;  b = meio+1;   k = inicio;
    while((a <= meio) && (b<=fim)) {
      if(v->v[a] < v->v[b]) {    aux[k] = v->v[a];      a++;    }
      else            {    aux[k] = v->v[b];      b++;    }
      k++;
    }
    while(a <= meio) {    aux[k] = v->v[a];    a++; k++;  }
    while(b <= fim) {    aux[k] = v->v[b];    b++;    k++;  }
    for(k = inicio; k <= fim; k++) { v->v[k] = aux[k]; }
  }
}

void mergeSort (tipoVetor *v) {
  int *aux, tam ;
  tam = v->tam;
  aux =    (int*) malloc( sizeof(int)*tam);

  mergeSortR(v, aux, 0, tam-1);
  free(aux);
}
