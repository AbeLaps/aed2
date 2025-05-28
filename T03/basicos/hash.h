#include <stdlib.h>
#include <stdio.h>


typedef struct item{
  long int cpf;
  unsigned int idade;
  int agencia;
  char nome[65];
  char email[25];
}item;


typedef struct hashItem{
  struct hashItem * prox;
  unsigned int index;
  long int cpf;
}hashItem;

