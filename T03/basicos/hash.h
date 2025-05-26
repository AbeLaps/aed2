#include <stdlib.h>
#include <stdio.h>


typedef struct item{
  int cpf;
  unsigned int idade;
  int agencia;
  char nome[65];
  char email[25];
}item;


typedef struct hashItem{
  struct hashItem * prox;
  unsigned int index;
}hashItem;

typedef struct hashTable{
 hashItem* vet[10000];
}hashTable;
