#include "hash.h"
#include <stdio.h>

tipoItem itemNULO = {-1, 0, 0, "x", "x"};

int main(){
    hashItem hash[10000];
    inicializaHash(hash);
    FILE * arquivo = fopen("C:/VScode/UFAM-codigos/AED-II-2025/T03/basicos/dados.bin", "rb");
    Abp * arv = criaAbp(itemNULO);
    popularSistema(arquivo,arv,hash);


    return 1;
}