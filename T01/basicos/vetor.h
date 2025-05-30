#ifndef vetor_H
#define vetor_H


typedef struct tipoVetor{
     int * vet;
     int tam; 
}tipoVetor;

void criaVetor(tipoVetor *v, unsigned int size );

void destroiVetor(tipoVetor *v);

void preencheVetor(tipoVetor *v);

void preencheVetorOrdenado(tipoVetor *v);

float calcularDPVetor(tipoVetor v);

void copiaVetor(tipoVetor * v, tipoVetor * v1);

void printaVetor(tipoVetor *v);

int buscaSeqVetor(tipoVetor v, unsigned int chave);

int buscaBin(tipoVetor v, unsigned int chave);

void quickSort (tipoVetor * v);

void selectionSort (tipoVetor * v);

void insertionSort (tipoVetor * v);

void bubbleSort (tipoVetor * v);

void mergeSort ( tipoVetor * v);

#endif
