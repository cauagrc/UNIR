#include <stdbool.h>

typedef struct Grafo {
    int numVert;
    int **matriz;
} Grafo; /* Grafo representado por Matrizes */

typedef struct No {
    int vertice;
    struct No *prox;
} No;

typedef struct Grafo_Lista {
    int numVert;
    No **lista;
} Grafo_Lista;

typedef struct Componentes {
    int numComponentes;
    int *tamanhos;
    int **vertices;
} Componentes;

typedef struct {
    int *pai;
    int *nivel;
    int *caminho;
    int tamanho;
    double tempo_execucao;
    bool valido;
} Resultado;

/** */
Grafo *Init(int tam);

void Destroy(Grafo *g);

void Display(Grafo *g);

void Insert(Grafo *g, int u, int v);

/** */

Grafo_Lista *InitLista(int tam);

void DestroyLista(Grafo_Lista *g);

void DisplayLista(Grafo_Lista *g);

int existeAresta(Grafo_Lista *g, int u, int v);

void InsertLista(Grafo_Lista *g, int u, int v);

/** */

Grafo *LerArq();

Grafo_Lista *LerArqLista();

/** */

void gerarEstudoCaso(Grafo *g, Grafo_Lista *gl);

/** */

void gerarRelatorioLista(Grafo_Lista *g);

void gerarRelatorio(Grafo *g);

/* Informações do grafo */
int numArestas(Grafo *g);

int grauVert(Grafo *g, int vertice);

int grauMin(Grafo *g);

int grauMax(Grafo *g);

float grauMedio(Grafo *g);

float grauMediana(Grafo *g);

/*  */

Resultado bfs(Grafo *g, int origem);

void destruirResultado(Resultado r);

void dfsRec(Grafo *g, int atual, int *visitado, Resultado *resultado);

Resultado dfs(Grafo *g, int origem);

int distancia(Grafo *g, int origem, int destino);

int diametro(Grafo *g);

/*  */

void dfsComponente(Grafo *g, int vertice, int *visitado, int *componentes, int *tam);

void componentes(Grafo *g);

void ordenarComponentes(Componentes *c);

void destruirComponentes(Componentes *c);

/** */

int numArestasLista(Grafo_Lista *g);

int grauVertLista(Grafo_Lista *g, int vertice);

int grauMinLista(Grafo_Lista *g);

int grauMaxLista(Grafo_Lista *g);

float grauMedioLista(Grafo_Lista *g);

float grauMedianaLista(Grafo_Lista *g);

/** */

Resultado bfsLista(Grafo_Lista *g, int origem);

Resultado dfsLista(Grafo_Lista *g, int origem);

int distanciaLista(Grafo_Lista *g, int origem, int destino);

int diametroLista(Grafo_Lista *g);

/** */

void dfsComponenteLista(Grafo_Lista *g, int vertice, int *visitado, int *componentes, int *tam);

void componentesLista(Grafo_Lista *g);

/** */

double dfs100(Grafo *g);

double bfs100(Grafo *g);

double calcularMemoria(Grafo *g);

/** */

double calcularMemoriaLista(Grafo_Lista *gl);

double bfs100Lista(Grafo_Lista *gl);

double dfs100Lista(Grafo_Lista *gl);