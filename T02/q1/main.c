#include <stdio.h>
#include "ABP.h"
#include "ABP.c"


int main(){

    Arv *arv = criaArv(rand()%1000);
    popularArvRand(arv, 20);
    printf("Arvore prefixada:\n");
    preFix(arv);
    printf("\nArvore infixada:\n");
    infix(arv);
    printf("\nArvore posfixada:\n");
    posFix(arv);

    return 1;
}
