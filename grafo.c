#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>

Grafo *Init(int tam) {
    /*
     *  Cria o grafo 
     */
    Grafo *g = malloc(sizeof(Grafo));
    
    if (g == NULL) return NULL;

    g->numVert = tam;

    /*
    *   Cria x ponteiros
    */
    g->matriz = malloc(tam * sizeof(int *));

    if (g->matriz == NULL) {
        free(g);
        return NULL;
    }

    for (int i = 0; i < tam; i++) {
        /*
        *   Calloc cria uma linha de tamanho x
        */
        g->matriz[i] = calloc(tam, sizeof(int));

        if (g->matriz[i] == NULL) {
            for (int j = 0; j < i; j++)
                free(g->matriz[j]);

            free(g->matriz);
            free(g);

            return NULL;
        }
    }

    return g;
}

void Destroy(Grafo *g) {
    if (g == NULL) return;

    for (int i = 0; i < g->numVert; i++) {
        free(g->matriz[i]);
    }

    free(g->matriz);

    free(g);
}

void Display(Grafo *g) {
    if (g == NULL) return;

    printf("\nMatriz de Adjacencia\n\n");

    for (int i = 0; i < g->numVert; i++) {
        for (int j = 0; j < g->numVert; j++)
            printf("%d ", g->matriz[i][j]);

        printf("\n");
    }
}

void Insert(Grafo *g, int u, int v) {
    u--;
    v--;

    g->matriz[u][v] = 1;
    g->matriz[v][u] = 1;
}

void LerArq(Grafo *g) {
    FILE *arq = fopen("tests/grafo.txt", "r");

    if (arq == NULL) return;

    int n;
    fscanf(arq, "%d", &n);

    /*Grafo *g = Init(n);*/

    if (g == NULL) {
        fclose(arq);
        return;
    }

    int u, v;

    while (fscanf(arq, "%d %d", &u, &v) == 2) {
        Insert(g, u, v);
    }

    fclose(arq);
}