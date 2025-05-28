#include "abp.h"

typedef struct tipoItem{
  long int cpf;
  unsigned int idade;
  int agencia;
  char nome[65];
  char email[25];
}tipoItem;


typedef struct hashItem{
  struct hashItem * prox;
  unsigned int index;
  long int cpf;
}hashItem;
