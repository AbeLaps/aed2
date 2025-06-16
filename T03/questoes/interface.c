#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
Integrantes do grupo:
Abel Andrade Prazeres dos Santos
Gabriela Silva Malveira
Bruna de Souza Brasil
Gabriel Gregório dos Santos Vitor
*/

tipoItem itemNULO = {-1, 0, 0, "x", "x"};

int main(){
    srand(time(NULL));

    //popula o sistema completo
    hashItem hash[10000];
    inicializaHash(hash);
    FILE * arquivo = fopen("dadosv2.bin", "rb");
    Abp * arvCpf = criaAbp(itemNULO);
    Abp * arvIdade = criaAbp(itemNULO);
    popularSistema(arquivo,arvCpf, arvIdade, hash);

    int TOTAL = 10000;
    long long int CPF_MIN = 10000000000LL;
    long long int CPF_MAX = 10000025000LL;
    int intervalo = CPF_MAX - CPF_MIN + 1;

    tipoItem registros[TOTAL];

    // Gera CPFs únicos
    long long int *cpfs = malloc(intervalo * sizeof(long long int));
    for (int i = 0; i < intervalo; i++) {
        cpfs[i] = CPF_MIN + i;
    }
    for (int i = intervalo - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        long long int temp = cpfs[i];
        cpfs[i] = cpfs[j];
        cpfs[j] = temp;
    }

    // Preenche os registros
    for (int i = 0; i < TOTAL; i++) {
        registros[i].cpf = cpfs[i];
        registros[i].idade = 18 + rand() % (90 - 18 + 1);
        registros[i].agencia = 2 + rand() % (100 - 2 + 1);

        memset(registros[i].nome, 'x', sizeof(registros[i].nome) - 1);
        registros[i].nome[64] = '\0';

        memset(registros[i].email, 'y', sizeof(registros[i].email) - 1);
        registros[i].email[24] = '\0';
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
            printf("Qual tipo de busca gostaria de realizar na abp? \n 1 para busca por atributo chave \n 2 para comparacao de <, >, <= ou >= para atributo nao chave\n");
            scanf("%d", &busca2);
            switch (busca2)
            {
            case 1: //busca cpf na abp
                for(int i = 0; i < 30; i++){
                    inicio = clock();
                    buscaAbp(arvCpf, registros[i]);
                    fim = clock();

                    double tempoBusca = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                    tempos[i] = tempoBusca;
                    somaTempos += tempoBusca;
                }
                mediaTempos = somaTempos/30;
                break;
            
            case 2: //busca intervalo de idade na abp
                printf("Em tipo de busca gostaria de realizar? \n 1 para < \n 2 para > \n 3 para <= \n 4 para >= \n");
                scanf("%d", &flag);
                int intervalo;
                printf("Insira o numero a ser comparado: \n");
                scanf("%d", &intervalo);
                
                for(int i = 0; i < 30; i++){
                    inicio = clock();
                    buscaInterAbp(arvIdade, intervalo, flag);
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
                    buscaHash(hash, registros[i].cpf);
                    fim = clock();

                    double tempoBusca = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                    tempos[i] = tempoBusca;
                    somaTempos += tempoBusca;
                }
                mediaTempos = somaTempos/30;
            break;
        
        case 3: //arquivo
            printf("Em tipo de busca gostaria de realizar? \n 1 para busca por atributo chave \n 2 para comparacao de <, >, <= ou >= para atributo nao chave\n");
            scanf("%d", &busca2);
            switch (busca2)
            {
            case 1:
                for(int i = 0; i < 30; i++){    
                    inicio = clock();   
                    buscaSeqArq(arquivo, registros[i].cpf);
                    fim = clock();

                    double tempoBusca = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                    tempos[i] = tempoBusca;
                    somaTempos += tempoBusca;
                }
                mediaTempos = somaTempos/30;
                break;
            
            case 2:
            printf("Em tipo de busca gostaria de realizar? \n 1 para idade < limite \n 2 para idade > limite \n 3 para idade <= limite \n 4 para idade >= limite \n");
            scanf("%d", &flag);
            int intervaloMin;
            int intervaloMax;
            printf("Insira o numero a ser comparado: \n");
            scanf("%d", &intervalo);
            
            for(int i = 0; i < 30; i++){
                    inicio = clock();
                    buscaArq(arquivo, intervalo,flag);
                    fim = clock();

                    double tempoBusca = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                    tempos[i] = tempoBusca;
                    somaTempos += tempoBusca;
                }
                mediaTempos = somaTempos/30;
                break;
            default:
                printf("entrada invalida");
                break;
            }
            
        }
            
        printf("--------------------------------------------------------------\n");
        printf("|                     Tempos de Busca                        |\n");
        printf("--------------------------------------------------------------\n");

        for (int i = 0; i < 30; i++) {
            printf("| %7.6lf ", tempos[i] * 1000); 
            if ((i + 1) % 5 == 0)
                printf("|\n");
        }
        printf("--------------------------------------------------------------\n");
        printf("| Media dos tempos: %7.4lf                                  |\n", mediaTempos * 1000);
        printf("--------------------------------------------------------------\n");
        }
}
