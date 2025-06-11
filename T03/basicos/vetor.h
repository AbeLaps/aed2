#ifndef vetor_H
#define vetor_H

typedef struct tipoVetor{
     int * vet;
     int tam; 
}tipoVetor;

typedef struct tipoItem {
    long int cpf;
    unsigned int idade;
    int agencia;
    char nome[65];
    char email[25];
} tipoItem;

void criaVetor(tipoVetor *v, unsigned int size );
void destroiVetor(tipoVetor *v);
void copiaVetor(tipoVetor * v, tipoVetor * v1);
void preencheVetor(tipoVetor *v);
void preencheVetorOrdenado(tipoVetor *v);
float calcularDPVetor(tipoVetor v);
void printaVetor(tipoVetor *v);
int buscaSeqVetor(tipoVetor v, unsigned int chave);
int buscaBin(tipoVetor v, unsigned int chave);
void quickSort (tipoVetor * v);
void selectionSort (tipoVetor * v);
void insertionSort (tipoVetor * v);
void bubbleSort (tipoVetor * v);
void mergeSort ( tipoVetor * v);

#endif
