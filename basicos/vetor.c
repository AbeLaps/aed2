/*operacoes do vetor aqui */
#include <vetor.h>


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
