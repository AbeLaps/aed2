typedef struct item{
  int ID;
  unsigned int idade;
}item;


typedef struct hashItem{
  struct hashItem * prox;
  unsigned int ia;
}hashItem;

typedef struct hashTable{
 hashItem* vet[10000];
}hashTable
