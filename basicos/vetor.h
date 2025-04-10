#ifndef vetor_H
#define vetor_H


typedef struct tipoVetor{
    unsigned int vet[1000000];
    unsigned int tam;
}tipoVetor;

void criaVetor(tipoVetor * v );

void preencheVetor(tipoVetor v);

void preencheVetorOrdenado(tipoVetor v);

void printaVetor(tipoVetor *v);

int buscaSeqVetor(tipoVetor v, unsigned int chave);

int buscaBin(tipoVetor v, unsigned int chave);

void qSort (tipoVetor * v);

void selSort (tipoVetor * v);

void insertSort (tipoVetor * v);

void bubbleSort (tipoVetor * v);

void mergeSort ( tipoVetor * v);

#endif
