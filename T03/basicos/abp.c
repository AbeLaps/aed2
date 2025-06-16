#ifndef ABP_C
#define ABP_C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abp.h"

/*
Integrantes do grupo:
Abel Andrade Prazeres dos Santos
Gabriela Silva Malveira
Bruna de Souza Brasil
Gabriel Gregório dos Santos Vitor
*/

Abp* criaAbp(tipoItem val){
    Abp *Arv;
    Arv = (Abp * ) malloc(sizeof(Abp));
    Arv->esq = NULL;
    Arv->dir = NULL;
    Arv->item = val;  
    return Arv;
}

int buscaAbp(Abp* arv, tipoItem chave) {
    Abp* atual = arv;
    while (atual != NULL) {
        if (chave.cpf == atual->item.cpf) {
            printf("Registro encontrado: CPF = %lld\n", chave.cpf);
            return 1;
        }
        else if (chave.cpf < atual->item.cpf) {
            atual = atual->esq;
        }
        else {
            atual = atual->dir;
        }
    }
    printf("Registro com CPF = %lld nao encontrado.\n", chave.cpf);
    return 0;
}

void buscaInterAbp(Abp* raiz, int idadeBase, int flag){
    if (raiz == NULL) return ;

    // Percorre subarvore esquerda
    buscaInterAbp(raiz->esq, idadeBase, flag);

    // Verifica a condicao baseada na flag
    int condicao = 0;
    switch (flag){
        case 1: condicao = (raiz->item.idade < idadeBase); break;
        case 2: condicao = (raiz->item.idade > idadeBase); break;
        case 3: condicao = (raiz->item.idade <= idadeBase); break;
        case 4: condicao = (raiz->item.idade >= idadeBase); break;
        default:
            printf("Flag invalida! Use 1 (<), 2 (>), 3 (<=), 4 (>=)\n");
            return;
    }

    /*if (condicao){ //comentado para nao inflar o tempo
        printf("Registro encontrado:\n");
        printf("CPF: %lld | Idade: %u | Agencia: %d | Nome: %s | Email: %s\n",
               raiz->item.cpf, raiz->item.idade, raiz->item.agencia, raiz->item.nome, raiz->item.email);
    }
    */

    // Percorre subarvore direita
    buscaInterAbp(raiz->dir, idadeBase, flag);
}

void insereValAbpIdade(Abp* Arv, tipoItem val) {
    Abp* aux = Arv;
    while (aux != NULL) {
        if (val.idade < aux->item.idade) {
            if (aux->esq == NULL) {
                aux->esq = criaAbp(val);
                return;
            }
            aux = aux->esq;
        } else {
            if (aux->dir == NULL) {
                aux->dir = criaAbp(val);
                return;
            }
            aux = aux->dir;
        }
    }
    printf("Erro: Árvore raiz == NULL\n");
}

void insereValAbpCpf(Abp* Arv, tipoItem val) {
    Abp* aux = Arv;
    while (aux != NULL) {
        if (val.cpf < aux->item.cpf) {
            if (aux->esq == NULL) {
                aux->esq = criaAbp(val);
                return;
            }
            aux = aux->esq;
        } else {
            if (aux->dir == NULL) {
                aux->dir = criaAbp(val);
                return;
            }
            aux = aux->dir;
        }
    }
    printf("Erro: Arvore raiz == NULL\n");
}

void liberarArvoreABP(Abp* raiz) {
    if (raiz != NULL) {
        liberarArvoreABP(raiz->esq);
        liberarArvoreABP(raiz->dir);
        free(raiz);
    }
}

/*
void coletaDadosAbp(Abp* Arv, tipoVetor *vetor, int *index) {
    if (Arv != NULL) {
        coletaDadosAbp(Arv->esq, vetor, index);
        vetor->vet[*index] = Arv->item.cpf;  // Coleta a idade ou cpf
        (*index)++;
        coletaDadosAbp(Arv->dir, vetor, index);
    }
}


void calcularEstatisticas(Abp* Arv, tipoVetor *vetor) {
    int index = 0;
    coletaDadosAbp(Arv, vetor, &index);
    printf("Média: %.2f\n", calcularMedia(*vetor));
    printf("Desvio Padrão: %.2f\n", calcularDPVetor(*vetor));
    quickSort(vetor);
    printf("Vetor Ordenado: ");
    for (int i = 0; i < vetor->tam; i++) {
        printf("%d ", vetor->vet[i]);
    }
    printf("\n");
}
*/
#endif
