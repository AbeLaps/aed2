#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pacote.h"

void simularChegadaDePacotes(ArvPacote** arvore, int totalPacotes, float probabilidadeRetransmissao) {
    srand(time(NULL));

    for (int i = 0; i < totalPacotes; i++) {
    int pacote = i;
    char nome[100];

    if (rand() % 100 < probabilidadeRetransmissao * 100) {
        printf("Retransmissão do pacote: %d\n", pacote);
        snprintf(nome, sizeof(nome), "Pacote-%d (Retransmissão)", pacote);
    } else {
        printf("Chegada do pacote: %d\n", pacote);
        snprintf(nome, sizeof(nome), "Pacote-%d", pacote);
    }

    *arvore = inserePacote(*arvore, pacote, nome);
}
}

void salvarEmArquivo(ArvPacote* arvore, FILE* arquivo) {
    if (arvore != NULL) {
        salvarEmArquivo(arvore->esq, arquivo);
        fprintf(arquivo, "ID: %d, Dados: %s\n", arvore->pacote->id, arvore->pacote->dado);
        salvarEmArquivo(arvore->dir, arquivo);
    }
}

int main() {
    ArvPacote* arvore = NULL;
    int totalPacotes = 100;
    float probabilidadeRetransmissao = 0.2;

    simularChegadaDePacotes(&arvore, totalPacotes, probabilidadeRetransmissao);

    printf("Exibindo pacotes em ordem:\n");
    ordenaArquivo(arvore, stdout);

    FILE* arquivo = fopen("pacotes_recebidos.txt", "w");
    if (arquivo != NULL) {
        salvarEmArquivo(arvore, arquivo);
        fclose(arquivo);
        printf("Arquivo com pacotes criado com sucesso.\n");
    } else {
        printf("Erro ao criar o arquivo.\n");
    }

    return 0;
}
