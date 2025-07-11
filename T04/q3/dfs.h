#ifndef DFS_H
#define DFS_H

#include "grafo.h"

void dfsAux(Grafo* grafo, int atual, int* visitado, int* pai);

void dfs(Grafo* grafo);

#endif