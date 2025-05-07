/*operacoes do vetor aqui */
#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <math.h>


void criaVetor(tipoVetor * v, unsigned int size){
    v->tam = size;
    v->vet = (int*)malloc(sizeof(int)* size);
}
void destroiVetor(tipoVetor *v){
    free(v->vet);
    v->tam = 0;
    return;
}

void copiaVetor(tipoVetor * v, tipoVetor * v1){
    for (int j = 0; j < v1->tam; j++) {
        v->vet[j] = v1->vet[j];
    }
    return;
}


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
void bubbleSort(tipoVetor *v) {
    unsigned n = v->tam;

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (v->vet[j] > v->vet[j+1]){
                int temp = v->vet[j];
                v->vet[j] = v->vet[j+1];
                v->vet[j+1] = temp;
            }
        }
    }
    return;
}

void selectionSort(tipoVetor *v){
    unsigned n = v->tam;

    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (v->vet[j] < v->vet[min_idx]) {
                min_idx = j;
            }
        }
        int temp = v->vet[i];
        v->vet[i] = v->vet[min_idx];
        v->vet[min_idx] = temp;
    }
    return;
}

void insertionSort(tipoVetor *v) {
    unsigned n = v->tam;

    for (int i = 1; i < n; i++) {
        int chave = v->vet[i];
        int j = i - 1;

        while (j >= 0 && v->vet[j] > chave) {
            v->vet[j + 1] = v->vet[j];
            j--;
        }
        v->vet[j + 1] = chave;
    }
    return;
}


void quickSortR(tipoVetor *v, int ini, int fim){
    int i = ini;
    int f = fim;

    int pivot = (i + f)/2;
    int np = v->vet[pivot];
    int temp;

    if(i >= f){return;}

    while(i <= f){
        while(v->vet[i] <= np){
            i++;
        }
        while(v->vet[f] >= np){
            f--;
        }
        if(i <= f){
        temp = v->vet[i];
        v->vet[i] = v->vet[f];
        v->vet[f] = temp;
        i++;
        f--;
        }
    }
    if (ini < f){ quickSortR(v, ini, f);}
    if (i < fim){ quickSortR(v, i,fim);}
    return;
}
void quickSort(tipoVetor *v){
    quickSortR(v,0,v->tam-1);
}

void mergeSortR(tipoVetor *v, int aux[], int inicio, int fim) {

  int a,b,k;

  if(inicio < fim) {

    int meio = (inicio+fim)/2;
    mergeSortR(v, aux, inicio, meio);
    mergeSortR(v, aux, meio+1, fim);
  
    a = inicio;  b = meio+1;   k = inicio;
    while((a <= meio) && (b<=fim)) {
      if(v->vet[a] < v->vet[b]) {    aux[k] = v->vet[a];      a++;    }
      else            {    aux[k] = v->vet[b];      b++;    }
      k++;
    }
    while(a <= meio) {    aux[k] = v->vet[a];    a++; k++;  }
    while(b <= fim) {    aux[k] = v->vet[b];    b++;    k++;  }
    for(k = inicio; k <= fim; k++) { v->vet[k] = aux[k]; }
  }
}

void mergeSort (tipoVetor *v) {
  int *aux, tam ;
  tam = v->tam;
  aux =    (int*) malloc( sizeof(int)*tam);

  mergeSortR(v, aux, 0, tam-1);
  free(aux);
}

int buscaBin(tipoVetor v, unsigned int x) {
    int inicio = 0;
    int fim = v.tam - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        // Verifica o elemento do meio
        if (v.vet[meio] == x) {
            return 1; // Retorna 1 se achar o valor
        }

        // Procura na direita
        if (v.vet[meio] < x) {
            inicio = meio + 1;
        }
        // Procura na esquerda
        else {
            fim = meio - 1;
        }
    }

    // Retorna -1 caso o valor não seja encontrado
    return -1;
}

int buscaSeqVetor(tipoVetor v, unsigned int val) {
    for (unsigned int i = 0; i < v.tam; i++) {
        if (v.vet[i] == val) {
            return 1;  // Retorna 1 se achar o valor
        }
    }
    return -1;  // Retorna -1 caso o valor não seja encontrado
}

float calcularDPVetor (tipoVetor v) {
    if (v.tam == 0) return 0.0;

    float soma = 0;

    for ( int i = 0; i < v.tam; i++) {
        soma += v.vet[i];
    }

    float media = soma / v.tam;
    float soma_dif_quad = 0;

    for ( int i = 0; i < v.tam; i++) {
        float dif = v.vet[i] - media;
        soma_dif_quad += dif * dif;
    }
    
    return sqrt(soma_dif_quad / v.tam);
}
