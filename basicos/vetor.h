#ifndef vetor_H
#define vetor_H


typedef struct tipoVetor{
     int * vet;
     int tam; 
}tipoVetor;

void criaVetor(tipoVetor *v, int size );

void preencheVetor(tipoVetor *v);

void preencheVetorOrdenado(tipoVetor *v);

float calcularDPVetor(tipoVetor v);

void printaVetor(tipoVetor *v);

int buscaSeqVetor(tipoVetor v, unsigned int chave);

int buscaBin(tipoVetor v, unsigned int chave);

void qSort (tipoVetor * v);

void selSort (tipoVetor * v);

void insertSort (tipoVetor * v);

void bubbleSort (tipoVetor * v);

void mergeSort ( tipoVetor * v);

#endif
