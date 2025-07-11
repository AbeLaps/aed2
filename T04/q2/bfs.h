#ifndef BFS_H
#define BFS_H

#include "grafo.h"


void bfs(Grafo* grafo, int inicio, int* pai);

void imprimirArvoreBfs(int* pai, int n);

#endif