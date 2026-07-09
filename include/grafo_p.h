#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct GrafoP {
    int numVert;
    double **matriz;
} GrafoP;

typedef struct ResultadoDijkstra {
    double *distancia;
    int *pai;
    bool valido;
} ResultadoDijkstra;

typedef struct {
    int vertice;
    double distancia;
} NoHeap;

typedef struct {
    NoHeap *dados;
    int tamanho;
    int capacidade;
} Heap;

GrafoP *InitP(int tam);

void DestroyP(GrafoP *g);

void InsertP(GrafoP *g, int u, int v, double peso);

GrafoP *LerArqP();

void DisplayP(GrafoP *g);

ResultadoDijkstra dijkstraVetor(GrafoP *g, int origem);

ResultadoDijkstra dijkstraHeap(GrafoP *g, int origem);

Heap *criarHeap(int capacidade);

void destruirHeap(Heap *h);
void trocarNoHeap(NoHeap *a, NoHeap *b);

void subirHeap(Heap *h, int indice);

void descerHeap(Heap *h, int indice);

int inserirHeap(Heap *h, int vertice, double distancia);

NoHeap removerMinHeap(Heap *h);

void destruirResultadoDijkstra(ResultadoDijkstra r);

double tempoMedioDijkstraVetor(GrafoP *g, int k);
double tempoMedioDijkstraHeap(GrafoP *g, int k);

void imprimirCaminhoDijkstra(FILE *arq, ResultadoDijkstra r, int origem, int destino);

void gerarEstudoCasoP(GrafoP *g);