#ifndef PACOTE_H
#define PACOTE_H

typedef struct Pacote {
    int id;
    char dado[100];
} Pacote;

typedef struct ArvPacote {
    Pacote* pacote;
    struct ArvPacote *dir;
    struct ArvPacote *esq;
} ArvPacote;

ArvPacote* criaPacote(int num, char *nome);
ArvPacote* inserePacote(ArvPacote *no, int num, char *nome);
void ordenaArquivo(ArvPacote* no, FILE* f);

#endif
