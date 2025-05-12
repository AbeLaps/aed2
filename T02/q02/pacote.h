#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABP.h"
#include "ABP.c"

typedef struct Pacote {
    int id;              
    char dado[100];     
} Pacote;

typedef struct ArvPacote {
    Pacote* pacote;
    struct ArvPacote *dir;
    struct ArvPacote *esq;

}ArvPacote;

ArvPacote* criaPacote (int num, char * nome);

ArvPacote* inserePacote(ArvPacote *no, int num, char * nome);

void ordenaArquivo(ArvPacote* no, FILE* f);
