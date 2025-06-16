#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TOTAL_REGISTROS 10000
#define MIN_IDADE 18
#define MAX_IDADE 90

#define CPF_MIN 10000000000LL
#define CPF_MAX 10000025000LL
#define INTERVALO_CPF (CPF_MAX - CPF_MIN + 1)

typedef struct tipoItem {
    long long int cpf;
    unsigned int idade;
    int agencia;
    char nome[65];
    char email[25];
} tipoItem;

int main() {
    if (INTERVALO_CPF < TOTAL_REGISTROS) {
        printf("Intervalo de CPFs insuficiente para garantir unicidade.\n");
        return 1;
    }

    FILE *arquivo = fopen("C:/VScode/UFAM-codigos/AED-II-2025/T03/basicos/dadosv2.bin", "wb");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    tipoItem item;
    long long int *cpfsDisponiveis = malloc(INTERVALO_CPF * sizeof(long long int));
    if (!cpfsDisponiveis) {
        perror("Erro ao alocar memória");
        fclose(arquivo);
        return 1;
    }

    for (int i = 0; i < INTERVALO_CPF; i++) {
        cpfsDisponiveis[i] = CPF_MIN + i;
    }

    srand(time(NULL));
    for (int i = INTERVALO_CPF - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        long long int temp = cpfsDisponiveis[i];
        cpfsDisponiveis[i] = cpfsDisponiveis[j];
        cpfsDisponiveis[j] = temp;
    }

    for (int i = 0; i < TOTAL_REGISTROS; i++) {
        item.cpf = cpfsDisponiveis[i];
        item.idade = (rand() % (MAX_IDADE - MIN_IDADE + 1)) + MIN_IDADE;
        item.agencia = (rand() % 99) + 2;
        memset(item.nome, 'x', sizeof(item.nome));
        memset(item.email, 'y', sizeof(item.email));
        item.nome[sizeof(item.nome) - 1] = '\0';
        item.email[sizeof(item.email) - 1] = '\0';

        fwrite(&item, sizeof(tipoItem), 1, arquivo);

        // Mostra o registro no terminal
        printf("Registro %5d | CPF: %lld | Idade: %u | Agencia: %d | Nome: %.64s | Email: %.24s\n",
               i + 1, item.cpf, item.idade, item.agencia, item.nome, item.email);
    }

    fclose(arquivo);
    free(cpfsDisponiveis);

    printf("\nArquivo 'dados.bin' gerado com sucesso.\n");
    return 0;
}
