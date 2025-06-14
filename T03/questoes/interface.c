#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//cpf variam de 10000000000 ate 10000100000 variacao de 100 mil para gerar 10 mil cpfs

tipoItem itemNULO = {-1, 0, 0, "x", "x"};

int main(){
    srand(time(NULL));

    //popula o sistema completo
    hashItem hash[10000];
    inicializaHash(hash);
    FILE * arquivo = fopen("C:/VScode/UFAM-codigos/AED-II-2025/T03/basicos/dados.bin", "rb");
    Abp * arvCpf = criaAbpCpf(itemNULO);
    Abp * arvIdade = criaAbpidade(itemNULO);
    popularSistema(arquivo,arvCpf, arvIdade, hash);

    long long int buscasCpf[30];
    long int rangeCpf = 100000;
    long long int inicioIntervaloCpf = 10000000000;

    int buscasIdades[30];
    int rangeIdade = 70;
    int inicioIntervaloIdade = 18;

    // gera vetor de 30 idades aleatorias
    for (int i = 0; i < 30; i++) {
        int r = rand() % rangeIdade;
        buscasIdades[i] = inicioIntervaloIdade + r;
        printf("Idade gerada %2d: %d\n", i + 1, buscasIdades[i]);
    }

    //gera vetor de 30 cpfs aleatorios
    for (int i = 0; i < 30; i++) {
        long long int r = rand() % rangeCpf;
        buscasCpf[i] = inicioIntervaloCpf + r;
        printf("Chave gerada %2d: %lld\n", i + 1, buscasCpf[i]);
    }

    //flags para interface
    int busca = 0;
    int busca2 = 0;

    //para salvar tempos
    clock_t inicio, fim;
    double tempos[30];
    double somaTempos = 0;
    double mediaTempos = 0;
    int flag = 0;
    
    while(1){
        // perguntar qual busca o usuario gostaria de realizar
        printf("Em qual estrutura gostaria de realizar a busca? \n 1 para Arvore binaria \n 2 para hash \n 3 para arquivo\n");
        scanf("%d", &busca);

        switch (busca){
        case 1: // busca na abp
            printf("Qual tipo de busca gostaria de realizar na abp? \n 1 para busca por atributo chave \n 2 para comparação de <, >, <= ou >= para tributo não chave\n");
            scanf("%d", &busca2);
            switch (busca2)
            {
            case 1: //busca cpf na abp
                for(int i = 0; i < 30; i++){
                    inicio = clock();
                    //buscaCpfAbp(arv, buscasCpf[i]);
                    fim = clock();

                    double tempoBusca = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                    tempos[i] = tempoBusca;
                    somaTempos += tempoBusca;
                }
                mediaTempos = somaTempos/30;
                break;
            
            case 2: //busca idade na abp
                for(int i = 0; i < 30; i++){
                    inicio = clock();
                    //buscaIdadeAbp(arv, buscasIdades[i]);
                    fim = clock();

                    double tempoBusca = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                    tempos[i] = tempoBusca;
                    somaTempos += tempoBusca;
                }
                mediaTempos = somaTempos/30;
                break;
            }

            break;
        
        case 2: //hash
            for(int i = 0; i < 30; i++){
                    inicio = clock();
                    buscaHash(hash, buscasCpf[i]);
                    fim = clock();

                    double tempoBusca = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                    tempos[i] = tempoBusca;
                    somaTempos += tempoBusca;
                }
                mediaTempos = somaTempos/30;
            break;
        
        case 3: //arquivo
            printf("Em tipo de busca gostaria de realizar? \n 1 para busca por atributo chave \n 2 para comparacao de <, >, <= ou >= para atributo nao chave");
            scanf("%d", &busca2);
            switch (busca2)
            {
            case 1:
                for(int i = 0; i < 30; i++){
                    inicio = clock();
                    buscaSeqArq(hash, buscasCpf[i]);
                    fim = clock();

                    double tempoBusca = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                    tempos[i] = tempoBusca;
                    somaTempos += tempoBusca;
                }
                mediaTempos = somaTempos/30;
                break;
            
            case 2:
            printf("Em tipo de busca gostaria de realizar? \n 1 < \n 2 para > \n 3 para <= \n 4 para >= \n");
            scanf("%d", &flag);
            int intervaloMin;
            int intervaloMax;
            printf("Qual o intervalo inicial: \n");
            scanf("%d", &intervaloMin);
            printf("Qual o intervalo final: \n");
            scanf("%d", &intervaloMax);
            
            for(int i = 0; i < 30; i++){
                    inicio = clock();
                    buscaArq(arquivo, buscasCpf[i],intervaloMin,intervaloMax,flag);
                    fim = clock();

                    double tempoBusca = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                    tempos[i] = tempoBusca;
                    somaTempos += tempoBusca;
                }
                mediaTempos = somaTempos/30;
                break;
            }
            
        }
            
        printf("--------------------------------------------------------------\n");
        printf("|                     Tempos de Busca                        |\n");
        printf("--------------------------------------------------------------\n");

        for (int i = 0; i < 30; i++) {
            printf("| %7.3lf ", tempos[i]); 
            if ((i + 1) % 5 == 0)
                printf("|\n");
        }
        printf("--------------------------------------------------------------\n");
        printf("| Média dos tempos: %7.3lf                                  |\n", mediaTempos);
        printf("--------------------------------------------------------------\n");
        }
}
