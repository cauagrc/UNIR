#include "grafo_p.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <time.h>

GrafoP *InitP(int tam) {
    GrafoP *g = malloc(sizeof(GrafoP));

    if (g == NULL) return NULL;

    g->numVert = tam;

    g->matriz = malloc(tam * sizeof(double *));

    if (g->matriz == NULL) {
        free(g);
        return NULL;
    }

    for (int i = 0; i < tam; i++) {
        g->matriz[i] = calloc(tam, sizeof(double));

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

void DestroyP(GrafoP *g) {
    if (g == NULL) return;

    for (int i = 0; i < g->numVert; i++) {
        free(g->matriz[i]);
    }

    free(g->matriz);
    free(g);
}

void InsertP(GrafoP *g, int u, int v, double peso) {
    if (g == NULL) return;

    if (u < 1 || u > g->numVert || v < 1 || v > g->numVert) return;

    u--;
    v--;

    g->matriz[u][v] = peso;
    g->matriz[v][u] = peso;
}

GrafoP *LerArqP() {
    FILE *arq = fopen("parte_2/grafo_W_1.txt", "r");

    if (arq == NULL) return NULL;

    int n;
    fscanf(arq, "%d", &n);

    GrafoP *g = InitP(n);

    if (g == NULL) {
        fclose(arq);
        return NULL;
    }

    int u, v;
    double peso;

    while (fscanf(arq, "%d %d %lf", &u, &v, &peso) == 3) {
        InsertP(g, u, v, peso);
    }

    fclose(arq);

    return g;
}

void DisplayP(GrafoP *g) {
    if (g == NULL) return;

    printf("\nMatriz de Adjacencia Ponderada\n\n");

    for (int i = 0; i < g->numVert; i++) {
        for (int j = 0; j < g->numVert; j++) {
            printf("%6.2f ", g->matriz[i][j]);
        }

        printf("\n");
    }
}

void destruirResultadoDijkstra(ResultadoDijkstra r) {
    free(r.distancia);
    free(r.pai);
}

ResultadoDijkstra dijkstraVetor(GrafoP *g, int origem) {
    ResultadoDijkstra r;

    r.distancia = NULL;
    r.pai = NULL;
    r.valido = false;

    if (g == NULL) return r;

    if (origem < 1 || origem > g->numVert) return r;

    int n = g->numVert;

    bool *visitado = calloc(n, sizeof(bool));
    r.distancia = malloc(n * sizeof(double));
    r.pai = malloc(n * sizeof(int));

    if (visitado == NULL || r.distancia == NULL || r.pai == NULL) {
        free(visitado);
        destruirResultadoDijkstra(r);

        r.distancia = NULL;
        r.pai = NULL;
        r.valido = false;

        return r;
    }

    for (int i = 0; i < n; i++) {
        r.distancia[i] = DBL_MAX;
        r.pai[i] = -1;
    }

    int origemIndex = origem - 1;
    r.distancia[origemIndex] = 0.0;

    for (int cont = 0; cont < n; cont++) {
        int atual = -1;
        double menorDistancia = DBL_MAX;

        for (int i = 0; i < n; i++) {
            if (!visitado[i] && r.distancia[i] < menorDistancia) {
                menorDistancia = r.distancia[i];
                atual = i;
            }
        }

        if (atual == -1) break;

        visitado[atual] = true;

        for (int vizinho = 0; vizinho < n; vizinho++) {
            double peso = g->matriz[atual][vizinho];

            if (peso != 0.0 && !visitado[vizinho]) {
                double novaDistancia = r.distancia[atual] + peso;

                if (novaDistancia < r.distancia[vizinho]) {
                    r.distancia[vizinho] = novaDistancia;
                    r.pai[vizinho] = atual + 1;
                }
            }
        }
    }

    free(visitado);

    r.valido = true;

    return r;
}

Heap *criarHeap(int capacidade) {
    Heap *h = malloc(sizeof(Heap));

    if (h == NULL) return NULL;

    h->dados = malloc(capacidade * sizeof(NoHeap));

    if (h->dados == NULL) {
        free(h);
        return NULL;
    }

    h->tamanho = 0;
    h->capacidade = capacidade;

    return h;
}

void destruirHeap(Heap *h) {
    if (h == NULL) return;

    free(h->dados);
    free(h);
}

void trocarNoHeap(NoHeap *a, NoHeap *b) {
    NoHeap temp = *a;
    *a = *b;
    *b = temp;
}

void subirHeap(Heap *h, int indice) {
    while (indice > 0) {
        int pai = (indice - 1) / 2;

        if (h->dados[pai].distancia <= h->dados[indice].distancia)
            break;

        trocarNoHeap(&h->dados[pai], &h->dados[indice]);
        indice = pai;
    }
}

void descerHeap(Heap *h, int indice) {
    while (1) {
        int menor = indice;
        int esq = 2 * indice + 1;
        int dir = 2 * indice + 2;

        if (esq < h->tamanho &&
            h->dados[esq].distancia < h->dados[menor].distancia)
            menor = esq;

        if (dir < h->tamanho &&
            h->dados[dir].distancia < h->dados[menor].distancia)
            menor = dir;

        if (menor == indice)
            break;

        trocarNoHeap(&h->dados[indice], &h->dados[menor]);
        indice = menor;
    }
}

int inserirHeap(Heap *h, int vertice, double distancia) {
    if (h == NULL) return 0;

    if (h->tamanho >= h->capacidade) return 0;

    h->dados[h->tamanho].vertice = vertice;
    h->dados[h->tamanho].distancia = distancia;

    subirHeap(h, h->tamanho);

    h->tamanho++;

    return 1;
}

NoHeap removerMinHeap(Heap *h) {
    NoHeap min;

    min.vertice = -1;
    min.distancia = DBL_MAX;

    if (h == NULL || h->tamanho == 0)
        return min;

    min = h->dados[0];

    h->tamanho--;

    if (h->tamanho > 0) {
        h->dados[0] = h->dados[h->tamanho];
        descerHeap(h, 0);
    }

    return min;
}

ResultadoDijkstra dijkstraHeap(GrafoP *g, int origem) {
    ResultadoDijkstra r;

    r.distancia = NULL;
    r.pai = NULL;
    r.valido = false;

    if (g == NULL) return r;

    if (origem < 1 || origem > g->numVert) return r;

    int n = g->numVert;

    bool *visitado = calloc(n, sizeof(bool));
    r.distancia = malloc(n * sizeof(double));
    r.pai = malloc(n * sizeof(int));
    
    Heap *heap = criarHeap(n * n);

    if (visitado == NULL || r.distancia == NULL || r.pai == NULL || heap == NULL) {
        free(visitado);
        destruirHeap(heap);
        destruirResultadoDijkstra(r);

        r.distancia = NULL;
        r.pai = NULL;
        r.valido = false;

        return r;
    }

    for (int i = 0; i < n; i++) {
        r.distancia[i] = DBL_MAX;
        r.pai[i] = -1;
    }

    int origemIndex = origem - 1;

    r.distancia[origemIndex] = 0.0;
    inserirHeap(heap, origemIndex, 0.0);

    while (heap->tamanho > 0) {
        NoHeap atualHeap = removerMinHeap(heap);
        int atual = atualHeap.vertice;

        if (atual == -1) break;

        if (visitado[atual]) continue;

        visitado[atual] = true;

        for (int vizinho = 0; vizinho < n; vizinho++) {
            double peso = g->matriz[atual][vizinho];

            if (peso != 0.0 && !visitado[vizinho]) {
                double novaDistancia = r.distancia[atual] + peso;

                if (novaDistancia < r.distancia[vizinho]) {
                    r.distancia[vizinho] = novaDistancia;
                    r.pai[vizinho] = atual + 1;

                    inserirHeap(heap, vizinho, novaDistancia);
                }
            }
        }
    }

    destruirHeap(heap);
    free(visitado);

    r.valido = true;

    return r;
}

double tempoMedioDijkstraVetor(GrafoP *g, int k) {
    if (g == NULL || k <= 0) return -1.0;

    double soma = 0.0;

    for (int i = 0; i < k; i++) {
        int origem = (i % g->numVert) + 1;

        clock_t inicio = clock();

        ResultadoDijkstra r = dijkstraVetor(g, origem);

        clock_t fim = clock();

        if (!r.valido) {
            destruirResultadoDijkstra(r);
            return -1.0;
        }

        soma += ((double)(fim - inicio) * 1000.0) / CLOCKS_PER_SEC;

        destruirResultadoDijkstra(r);
    }

    return soma / k;
}

double tempoMedioDijkstraHeap(GrafoP *g, int k) {
    if (g == NULL || k <= 0) return -1.0;

    double soma = 0.0;

    for (int i = 0; i < k; i++) {
        int origem = (i % g->numVert) + 1;

        clock_t inicio = clock();

        ResultadoDijkstra r = dijkstraHeap(g, origem);

        clock_t fim = clock();

        if (!r.valido) {
            destruirResultadoDijkstra(r);
            return -1.0;
        }

        soma += ((double)(fim - inicio) * 1000.0) / CLOCKS_PER_SEC;

        destruirResultadoDijkstra(r);
    }

    return soma / k;
}

void imprimirCaminhoDijkstra(FILE *arq, ResultadoDijkstra r, int origem, int destino) {
    if (arq == NULL || !r.valido) return;

    int caminho[10000];
    int tam = 0;
    int atual = destino;

    while (atual != -1) {
        caminho[tam++] = atual;

        if (atual == origem) break;

        atual = r.pai[atual - 1];
    }

    if (caminho[tam - 1] != origem) {
        fprintf(arq, "Nao existe caminho");
        return;
    }

    for (int i = tam - 1; i >= 0; i--) {
        fprintf(arq, "%d", caminho[i]);

        if (i > 0) fprintf(arq, " -> ");
    }
}

void gerarEstudoCasoP(GrafoP *g) {
    if (g == NULL) return;

    FILE *arq = fopen("out/estudoDeCaso_ponderado_1.txt", "w");

    if (arq == NULL) return;

    fprintf(arq, "ESTUDO DE CASO - GRAFOS PONDERADOS\n\n");

    fprintf(arq, "Origem: 10\n\n");
    fprintf(arq, "Destino\tDistancia Vetor\tCaminho Vetor\tDistancia Heap\tCaminho Heap\n");

    ResultadoDijkstra vetor = dijkstraVetor(g, 10);
    ResultadoDijkstra heap = dijkstraHeap(g, 10);

    int destinos[] = {20, 30, 40, 50, 60};

    for (int i = 0; i < 5; i++) {
        int destino = destinos[i];

        fprintf(arq, "%d\t", destino);

        if (destino > g->numVert) {
            fprintf(arq, "Indisponivel\t-\tIndisponivel\t-\n");
            continue;
        }

        if (vetor.distancia[destino - 1] == DBL_MAX)
            fprintf(arq, "INF\t");
        else
            fprintf(arq, "%.2f\t", vetor.distancia[destino - 1]);

        imprimirCaminhoDijkstra(arq, vetor, 10, destino);
        fprintf(arq, "\t");

        if (heap.distancia[destino - 1] == DBL_MAX)
            fprintf(arq, "INF\t");
        else
            fprintf(arq, "%.2f\t", heap.distancia[destino - 1]);

        imprimirCaminhoDijkstra(arq, heap, 10, destino);
        fprintf(arq, "\n");
    }

    destruirResultadoDijkstra(vetor);
    destruirResultadoDijkstra(heap);

    fprintf(arq, "\nTEMPO MEDIO\n\n");
    fprintf(arq, "Dijkstra com vetor, k = 100: %.2f ms\n", tempoMedioDijkstraVetor(g, 100));
    fprintf(arq, "Dijkstra com heap, k = 100: %.2f ms\n", tempoMedioDijkstraHeap(g, 100));

    fclose(arq);
}