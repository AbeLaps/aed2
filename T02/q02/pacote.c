#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABP.h"
#include "ABP.c"
#include "pacote.h"

ArvPacote* criaPacote (int num, char * nome){
    ArvPacote* no = (ArvPacote*) malloc(sizeof(ArvPacote));
    Pacote* p = (Pacote*) malloc(sizeof(Pacote));
    p->id = num;
    strcpy(p->dado, nome); 
    no->pacote = p;
    no->esq = no->dir = NULL;
    return no;
}

ArvPacote* inserePacote(ArvPacote *no, int num, char * nome){
    if (no == NULL){
        return criaPacote(num, nome);
    }
    if (num < no->pacote->id){
        no->esq = inserePacote (no->esq, num, nome);
    }
    else if (num > no->pacote->id){
        no->dir = inserePacote(no->dir, num, nome);
    }
    return no;
}

void ordenaArquivo(ArvPacote* no, FILE* f) {
    if (no == NULL) {
        return;
    }
    ordenaArquivo(no->esq, f);
    fprintf(f, "ID: %d, Dado: %s\n", no->pacote->id, no->pacote->dado);
    ordenaArquivo(no->dir, f);
}
