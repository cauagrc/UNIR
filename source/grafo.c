#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include "merge_sort.h"

#define GRAFO_ATUAL "parte_1/grafo_1.txt"

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

Grafo_Lista *InitLista(int tam) {
    Grafo_Lista *g = malloc(sizeof(Grafo_Lista));

    if (g == NULL) return NULL;

    g->numVert = tam;

    g->lista = calloc(tam, sizeof(No *));

    if (g->lista == NULL) {
        free(g);
        return NULL;
    }

    return g;
}

void DestroyLista(Grafo_Lista *g) {
    if (g == NULL) return;

    for (int i = 0; i < g->numVert; i++) {
        No *atual = g->lista[i];

        while (atual != NULL) {
            No *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }

    free(g->lista);
    free(g);
}

int existeAresta(Grafo_Lista *g, int u, int v) {
    No *atual = g->lista[u - 1];

    while (atual != NULL) {
        if (atual->vertice == v) return 1;
        atual = atual->prox;
    }

    return 0;
}

void InsertLista(Grafo_Lista *g, int u, int v) {
    if (g == NULL) return;

    if (u < 1 || u > g->numVert || v < 1 || v > g->numVert) return;

    if (existeAresta(g, u, v)) return;

    No *novo = malloc(sizeof(No));
    if (novo == NULL) return;

    novo->vertice = v;
    novo->prox = g->lista[u - 1];
    g->lista[u - 1] = novo;

    if (u == v) return;

    No *novo2 = malloc(sizeof(No));
    if (novo2 == NULL) return;

    novo2->vertice = u;
    novo2->prox = g->lista[v - 1];
    g->lista[v - 1] = novo2;
}

void DisplayLista(Grafo_Lista *g) {
    if (g == NULL) return;

    printf("\nLista de Adjacencia\n\n");

    for (int i = 0; i < g->numVert; i++) {
        printf("%d: ", i + 1);

        No *atual = g->lista[i];

        while (atual != NULL) {
            printf("%d -> ", atual->vertice);
            atual = atual->prox;
        }

        printf("NULL\n");
    }
}

int numArestas(Grafo *g) {
    int numArestas = 0;

    for (int i = 0; i < g->numVert; i++) 
        for(int j = 0; j < g->numVert; j++)
            if(g->matriz[i][j] == 1) numArestas++;
    
    return numArestas /= 2;
}

int grauVert(Grafo *g, int vertice) {
    if (g == NULL) return 0;

    if (vertice < 1 || vertice > g->numVert) return -1;

    int grau = 0;

    for (int i = 0; i < g->numVert; i++) 
        if (g->matriz[vertice - 1][i] == 1) grau++;
    
    return grau;
}

int grauMin(Grafo *g) {
    if (g == NULL) return 0;

    int menor = grauVert(g, 1);

    for (int i = 2; i <= g->numVert; i++) {
        int grau = grauVert(g, i);

        if (grau < menor) menor = grau;
    }

    return menor;
}

int grauMax(Grafo *g) {
    if (g == NULL) return 0;

    int maior = grauVert(g, 1);

    for (int i = 2; i <= g->numVert; i++) {
        int grau = grauVert(g, i);

        if (grau > maior) maior = grau;
    }

    return maior;
}

float grauMedio(Grafo *g) {
    if (g == NULL) return 0;

    int soma = 0;

    for (int i = 1; i <= g->numVert; i++) soma += grauVert(g, i);

    return (float)soma / g->numVert;
}

float grauMediana(Grafo *g) {
    float mediana;

    if (g == NULL) return 0;

    int *graus = malloc(g->numVert * sizeof(int));

    if (graus == NULL) return 0;

    for (int i = 0; i < g->numVert; i++) graus[i] = grauVert(g, i + 1);

    mergeSort(graus, g->numVert);

    /**
     * 1, 1, #2, 2, 4
     */

    if (g->numVert % 2 == 0) mediana = (graus[g->numVert / 2 - 1] + graus[g->numVert / 2]) / 2.0f;
    else mediana = graus[g->numVert / 2];
    
    free(graus);

    return mediana;
}

Resultado bfs(Grafo *g, int origem) {
    Resultado r;

    r.caminho = NULL;
    r.pai = NULL;
    r.nivel = NULL;
    r.tamanho = 0;
    r.tempo_execucao = 0.0;
    r.valido = false;

    if (g == NULL) return r;

    if (origem < 1 || origem > g->numVert) return r;

    int *visitado = calloc(g->numVert, sizeof(int));
    int *fila = malloc(g->numVert * sizeof(int));

    r.pai = malloc(g->numVert * sizeof(int));
    r.nivel = malloc(g->numVert * sizeof(int));
    r.caminho = malloc(g->numVert * sizeof(int));

    if (visitado == NULL || fila == NULL || r.pai == NULL || r.nivel == NULL || r.caminho == NULL) {
        free(visitado);
        free(fila);
        destruirResultado(r);

        r.caminho = NULL;
        r.pai = NULL;
        r.nivel = NULL;
        r.tamanho = 0;
        r.tempo_execucao = 0.0;
        r.valido = false;

        return r;
    }

    clock_t inicioTempo = clock();

    for (int i = 0; i < g->numVert; i++) {
        r.pai[i] = -1;
        r.nivel[i] = -1;
    }

    int inicio = 0;
    int fim = 0;

    int origemIndex = origem - 1;

    visitado[origemIndex] = 1;
    r.nivel[origemIndex] = 0;
    fila[fim++] = origemIndex;

    while (inicio < fim) {
        int atual = fila[inicio++];

        r.caminho[r.tamanho++] = atual + 1;

        for (int vizinho = 0; vizinho < g->numVert; vizinho++) {
            if (g->matriz[atual][vizinho] == 1 && visitado[vizinho] == 0) {
                visitado[vizinho] = 1;
                r.pai[vizinho] = atual + 1;
                r.nivel[vizinho] = r.nivel[atual] + 1;
                fila[fim++] = vizinho;
            }
        }
    }

    clock_t fimTempo = clock();

    r.tempo_execucao = ((double)(fimTempo - inicioTempo) * 1000.0) / CLOCKS_PER_SEC;
    r.valido = true;

    free(visitado);
    free(fila);

    return r;
}

void destruirResultado(Resultado r) {
    free(r.caminho);
    free(r.pai);
    free(r.nivel);
}

void dfsRec(Grafo *g, int atual, int *visitado, Resultado *r) {
    visitado[atual] = 1;

    r->caminho[r->tamanho] = atual + 1;
    r->tamanho++;

    for (int vizinho = 0; vizinho < g->numVert; vizinho++) {
        if (g->matriz[atual][vizinho] == 1 && visitado[vizinho] == 0) {
            r->pai[vizinho] = atual + 1;
            r->nivel[vizinho] = r->nivel[atual] + 1;

            dfsRec(g, vizinho, visitado, r);
        }
    }
}

Resultado dfs(Grafo *g, int origem) {
    Resultado r;

    r.caminho = NULL;
    r.pai = NULL;
    r.nivel = NULL;
    r.tamanho = 0;
    r.tempo_execucao = 0.0;
    r.valido = false;

    if (g == NULL) return r;

    if (origem < 1 || origem > g->numVert) return r;

    int *visitado = calloc(g->numVert, sizeof(int));

    r.pai = malloc(g->numVert * sizeof(int));
    r.nivel = malloc(g->numVert * sizeof(int));
    r.caminho = malloc(g->numVert * sizeof(int));

    if (visitado == NULL || r.pai == NULL || r.nivel == NULL || r.caminho == NULL) {
        free(visitado);
        destruirResultado(r);

        r.caminho = NULL;
        r.pai = NULL;
        r.nivel = NULL;
        r.tamanho = 0;
        r.tempo_execucao = 0.0;
        r.valido = false;

        return r;
    }

    for (int i = 0; i < g->numVert; i++) {
        r.pai[i] = -1;
        r.nivel[i] = -1;
    }

    int origemIndex = origem - 1;

    r.nivel[origemIndex] = 0;

    dfsRec(g, origemIndex, visitado, &r);

    r.valido = true;

    free(visitado);

    return r;
}

int distancia(Grafo *g, int origem, int destino) {
    if (g == NULL) return -1;

    if (origem < 1 || origem > g->numVert) return -1;
    if (destino < 1 || destino > g->numVert) return -1;

    int *visitado = calloc(g->numVert, sizeof(int));
    int *nivel = malloc(g->numVert * sizeof(int));
    int *fila = malloc(g->numVert * sizeof(int));

    if (visitado == NULL || nivel == NULL || fila == NULL) {
        free(visitado);
        free(nivel);
        free(fila);
        return -1;
    }

    for (int i = 0; i < g->numVert; i++) nivel[i] = -1;

    int inicio = 0;
    int fim = 0;

    int origemIndex = origem - 1;
    int destinoIndex = destino - 1;

    visitado[origemIndex] = 1;
    nivel[origemIndex] = 0;
    fila[fim++] = origemIndex;

    while (inicio < fim) {
        int atual = fila[inicio++];

        if (atual == destinoIndex) {
            int resposta = nivel[atual];

            free(visitado);
            free(nivel);
            free(fila);

            return resposta;
        }

        for (int vizinho = 0; vizinho < g->numVert; vizinho++) {
            if (g->matriz[atual][vizinho] == 1 && visitado[vizinho] == 0) {
                visitado[vizinho] = 1;
                nivel[vizinho] = nivel[atual] + 1;
                fila[fim++] = vizinho;
            }
        }
    }

    free(visitado);
    free(nivel);
    free(fila);

    return -1;
}

int diametro(Grafo *g) {
    if (g == NULL) return -1;

    int maiorDistancia = -1;

    for (int i = 1; i <= g->numVert; i++) {
        for (int j = 1; j <= g->numVert; j++) {
            int dist = distancia(g, i, j);

            if (dist > maiorDistancia) maiorDistancia = dist;
        }
    }

    return maiorDistancia;
}

void dfsComponente(Grafo *g, int vertice, int *visitado, int *componentes, int *tam) {
    visitado[vertice] = 1;

    componentes[*tam] = vertice + 1;
    (*tam)++;

    for (int vizinho = 0; vizinho < g->numVert; vizinho++) {
        if (g->matriz[vertice][vizinho] == 1 && visitado[vizinho] == 0) {
            dfsComponente(g, vizinho, visitado, componentes, tam);
        }
    }
}

void ordenarComponentes(Componentes *c) {
    for (int i = 0; i < c->numComponentes - 1; i++) {
        for (int j = i + 1; j < c->numComponentes; j++) {
            if (c->tamanhos[j] > c->tamanhos[i]) {
                int tempTam = c->tamanhos[i];
                c->tamanhos[i] = c->tamanhos[j];
                c->tamanhos[j] = tempTam;

                int *tempVertices = c->vertices[i];
                c->vertices[i] = c->vertices[j];
                c->vertices[j] = tempVertices;
            }
        }
    }
}

void destruirComponentes(Componentes *comp) {
    if (comp == NULL) return;

    for (int i = 0; i < comp->numComponentes; i++) {
        free(comp->vertices[i]);
    }

    free(comp->vertices);
    free(comp->tamanhos);
}

void componentes(Grafo *g) {
    if (g == NULL) return;

    FILE *arq = fopen("tests/componentes.txt", "w");

    if (arq == NULL) return;

    int *visitado = calloc(g->numVert, sizeof(int));

    Componentes comp;

    comp.numComponentes = 0;
    comp.tamanhos = malloc(g->numVert * sizeof(int));
    comp.vertices = malloc(g->numVert * sizeof(int *));

    if (visitado == NULL || comp.tamanhos == NULL || comp.vertices == NULL) {
        free(visitado);
        free(comp.tamanhos);
        free(comp.vertices);
        fclose(arq);
        return;
    }

    for (int i = 0; i < g->numVert; i++) {
        if (visitado[i] == 0) {
            comp.vertices[comp.numComponentes] = malloc(g->numVert * sizeof(int));

            if (comp.vertices[comp.numComponentes] == NULL) {
                destruirComponentes(&comp);
                free(visitado);
                fclose(arq);
                return;
            }

            comp.tamanhos[comp.numComponentes] = 0;

            dfsComponente(g, i, visitado, comp.vertices[comp.numComponentes], &comp.tamanhos[comp.numComponentes]);

            comp.numComponentes++;
        }
    }

    ordenarComponentes(&comp);

    fprintf(arq, "Componentes Conexas\n\n");
    fprintf(arq, "Quantidade de componentes conexas: %d\n\n", comp.numComponentes);

    for (int i = 0; i < comp.numComponentes; i++) {
        fprintf(arq, "Componente %d\n", i + 1);
        fprintf(arq, "Tamanho: %d\n", comp.tamanhos[i]);
        fprintf(arq, "Vertices: ");

        for (int j = 0; j < comp.tamanhos[i]; j++) {
            fprintf(arq, "%d ", comp.vertices[i][j]);
        }

        fprintf(arq, "\n\n");
    }

    destruirComponentes(&comp);
    free(visitado);
    fclose(arq);
}

int grauVertLista(Grafo_Lista *g, int vertice) {
    if (g == NULL) return 0;

    if (vertice < 1 || vertice > g->numVert) return -1;

    int grau = 0;

    No *atual = g->lista[vertice - 1];

    while (atual != NULL) {
        grau++;
        atual = atual->prox;
    }

    return grau;
}

int numArestasLista(Grafo_Lista *g) {
    if (g == NULL) return 0;

    int somaGraus = 0;

    for (int i = 1; i <= g->numVert; i++) {
        somaGraus += grauVertLista(g, i);
    }

    return somaGraus / 2;
}

int grauMinLista(Grafo_Lista *g) {
    if (g == NULL) return 0;

    int menor = grauVertLista(g, 1);

    for (int i = 2; i <= g->numVert; i++) {
        int grau = grauVertLista(g, i);

        if (grau < menor) menor = grau;
    }

    return menor;
}

int grauMaxLista(Grafo_Lista *g) {
    if (g == NULL) return 0;

    int maior = grauVertLista(g, 1);

    for (int i = 2; i <= g->numVert; i++) {
        int grau = grauVertLista(g, i);

        if (grau > maior) maior = grau;
    }

    return maior;
}

float grauMedioLista(Grafo_Lista *g) {
    if (g == NULL) return 0;

    int soma = 0;

    for (int i = 1; i <= g->numVert; i++) {
        soma += grauVertLista(g, i);
    }

    return (float)soma / g->numVert;
}

float grauMedianaLista(Grafo_Lista *g) {
    if (g == NULL) return 0;

    int *graus = malloc(g->numVert * sizeof(int));

    if (graus == NULL) return 0;

    for (int i = 0; i < g->numVert; i++) {
        graus[i] = grauVertLista(g, i + 1);
    }

    mergeSort(graus, g->numVert);

    float mediana;

    if (g->numVert % 2 == 0) {
        mediana = (graus[g->numVert / 2 - 1] + graus[g->numVert / 2]) / 2.0f;
    } else {
        mediana = graus[g->numVert / 2];
    }

    free(graus);

    return mediana;
}

Resultado bfsLista(Grafo_Lista *g, int origem) {
    Resultado r;

    r.caminho = NULL;
    r.pai = NULL;
    r.nivel = NULL;
    r.tamanho = 0;
    r.tempo_execucao = 0.0;
    r.valido = false;

    if (g == NULL) return r;

    if (origem < 1 || origem > g->numVert) return r;

    int *visitado = calloc(g->numVert, sizeof(int));
    int *fila = malloc(g->numVert * sizeof(int));

    r.pai = malloc(g->numVert * sizeof(int));
    r.nivel = malloc(g->numVert * sizeof(int));
    r.caminho = malloc(g->numVert * sizeof(int));

    if (visitado == NULL || fila == NULL || r.pai == NULL || r.nivel == NULL || r.caminho == NULL) {
        free(visitado);
        free(fila);
        destruirResultado(r);

        r.caminho = NULL;
        r.pai = NULL;
        r.nivel = NULL;
        r.tamanho = 0;
        r.tempo_execucao = 0.0;
        r.valido = false;

        return r;
    }

    for (int i = 0; i < g->numVert; i++) {
        r.pai[i] = -1;
        r.nivel[i] = -1;
    }

    int inicio = 0;
    int fim = 0;
    int origemIndex = origem - 1;

    visitado[origemIndex] = 1;
    r.nivel[origemIndex] = 0;
    fila[fim++] = origemIndex;

    while (inicio < fim) {
        int atual = fila[inicio++];

        r.caminho[r.tamanho++] = atual + 1;

        No *vizinho = g->lista[atual];

        while (vizinho != NULL) {
            int vizinhoIndex = vizinho->vertice - 1;

            if (visitado[vizinhoIndex] == 0) {
                visitado[vizinhoIndex] = 1;
                r.pai[vizinhoIndex] = atual + 1;
                r.nivel[vizinhoIndex] = r.nivel[atual] + 1;
                fila[fim++] = vizinhoIndex;
            }

            vizinho = vizinho->prox;
        }
    }

    r.valido = true;

    free(visitado);
    free(fila);

    return r;
}

void dfsRecLista(Grafo_Lista *g, int atual, int *visitado, Resultado *r) {
    visitado[atual] = 1;

    r->caminho[r->tamanho++] = atual + 1;

    No *vizinho = g->lista[atual];

    while (vizinho != NULL) {
        int vizinhoIndex = vizinho->vertice - 1;

        if (visitado[vizinhoIndex] == 0) {
            r->pai[vizinhoIndex] = atual + 1;
            r->nivel[vizinhoIndex] = r->nivel[atual] + 1;

            dfsRecLista(g, vizinhoIndex, visitado, r);
        }

        vizinho = vizinho->prox;
    }
}

Resultado dfsLista(Grafo_Lista *g, int origem) {
    Resultado r;

    r.caminho = NULL;
    r.pai = NULL;
    r.nivel = NULL;
    r.tamanho = 0;
    r.tempo_execucao = 0.0;
    r.valido = false;

    if (g == NULL) return r;

    if (origem < 1 || origem > g->numVert) return r;

    int *visitado = calloc(g->numVert, sizeof(int));

    r.pai = malloc(g->numVert * sizeof(int));
    r.nivel = malloc(g->numVert * sizeof(int));
    r.caminho = malloc(g->numVert * sizeof(int));

    if (visitado == NULL || r.pai == NULL || r.nivel == NULL || r.caminho == NULL) {
        free(visitado);
        destruirResultado(r);

        r.caminho = NULL;
        r.pai = NULL;
        r.nivel = NULL;
        r.tamanho = 0;
        r.tempo_execucao = 0.0;
        r.valido = false;

        return r;
    }

    for (int i = 0; i < g->numVert; i++) {
        r.pai[i] = -1;
        r.nivel[i] = -1;
    }

    int origemIndex = origem - 1;

    r.nivel[origemIndex] = 0;

    dfsRecLista(g, origemIndex, visitado, &r);

    r.valido = true;

    free(visitado);

    return r;
}

int distanciaLista(Grafo_Lista *g, int origem, int destino) {
    if (g == NULL) return -1;

    if (origem < 1 || origem > g->numVert) return -1;
    if (destino < 1 || destino > g->numVert) return -1;

    int *visitado = calloc(g->numVert, sizeof(int));
    int *nivel = malloc(g->numVert * sizeof(int));
    int *fila = malloc(g->numVert * sizeof(int));

    if (visitado == NULL || nivel == NULL || fila == NULL) {
        free(visitado);
        free(nivel);
        free(fila);
        return -1;
    }

    for (int i = 0; i < g->numVert; i++) {
        nivel[i] = -1;
    }

    int inicio = 0;
    int fim = 0;

    int origemIndex = origem - 1;
    int destinoIndex = destino - 1;

    visitado[origemIndex] = 1;
    nivel[origemIndex] = 0;
    fila[fim++] = origemIndex;

    while (inicio < fim) {
        int atual = fila[inicio++];

        if (atual == destinoIndex) {
            int resposta = nivel[atual];

            free(visitado);
            free(nivel);
            free(fila);

            return resposta;
        }

        No *vizinho = g->lista[atual];

        while (vizinho != NULL) {
            int vizinhoIndex = vizinho->vertice - 1;

            if (visitado[vizinhoIndex] == 0) {
                visitado[vizinhoIndex] = 1;
                nivel[vizinhoIndex] = nivel[atual] + 1;
                fila[fim++] = vizinhoIndex;
            }

            vizinho = vizinho->prox;
        }
    }

    free(visitado);
    free(nivel);
    free(fila);

    return -1;
}

int diametroLista(Grafo_Lista *g) {
    if (g == NULL) return -1;

    int maiorDistancia = -1;

    for (int i = 1; i <= g->numVert; i++) {
        for (int j = 1; j <= g->numVert; j++) {
            int dist = distanciaLista(g, i, j);

            if (dist > maiorDistancia) {
                maiorDistancia = dist;
            }
        }
    }

    return maiorDistancia;
}

void dfsComponenteLista(Grafo_Lista *g, int vertice, int *visitado, int *componentes, int *tam) {
    visitado[vertice] = 1;

    componentes[*tam] = vertice + 1;
    (*tam)++;

    No *vizinho = g->lista[vertice];

    while (vizinho != NULL) {
        int vizinhoIndex = vizinho->vertice - 1;

        if (visitado[vizinhoIndex] == 0) {
            dfsComponenteLista(g, vizinhoIndex, visitado, componentes, tam);
        }

        vizinho = vizinho->prox;
    }
}

void componentesLista(Grafo_Lista *g) {
    if (g == NULL) return;

    FILE *arq = fopen("tests/componentes_lista.txt", "w");

    if (arq == NULL) return;

    int *visitado = calloc(g->numVert, sizeof(int));

    Componentes comp;

    comp.numComponentes = 0;
    comp.tamanhos = malloc(g->numVert * sizeof(int));
    comp.vertices = malloc(g->numVert * sizeof(int *));

    if (visitado == NULL || comp.tamanhos == NULL || comp.vertices == NULL) {
        free(visitado);
        free(comp.tamanhos);
        free(comp.vertices);
        fclose(arq);
        return;
    }

    for (int i = 0; i < g->numVert; i++) {
        if (visitado[i] == 0) {
            comp.vertices[comp.numComponentes] = malloc(g->numVert * sizeof(int));

            if (comp.vertices[comp.numComponentes] == NULL) {
                destruirComponentes(&comp);
                free(visitado);
                fclose(arq);
                return;
            }

            comp.tamanhos[comp.numComponentes] = 0;

            dfsComponenteLista(
                g,
                i,
                visitado,
                comp.vertices[comp.numComponentes],
                &comp.tamanhos[comp.numComponentes]
            );

            comp.numComponentes++;
        }
    }

    ordenarComponentes(&comp);

    fprintf(arq, "Componentes Conexas - Lista\n\n");
    fprintf(arq, "Quantidade de componentes conexas: %d\n\n", comp.numComponentes);

    for (int i = 0; i < comp.numComponentes; i++) {
        fprintf(arq, "Componente %d\n", i + 1);
        fprintf(arq, "Tamanho: %d\n", comp.tamanhos[i]);
        fprintf(arq, "Vertices: ");

        for (int j = 0; j < comp.tamanhos[i]; j++) {
            fprintf(arq, "%d ", comp.vertices[i][j]);
        }

        fprintf(arq, "\n\n");
    }

    destruirComponentes(&comp);
    free(visitado);
    fclose(arq);
}

Grafo *LerArq() {
    FILE *arq = fopen(GRAFO_ATUAL, "r");

    if (arq == NULL) return NULL;

    int n;

    fscanf(arq, "%d", &n);

    Grafo *g = Init(n);

    if (g == NULL) {
        fclose(arq);
        return NULL;
    }

    int u, v;

    while (fscanf(arq, "%d %d", &u, &v) == 2) {
        Insert(g, u, v);
    }

    fclose(arq);

    return g;
}

Grafo_Lista *LerArqLista() {
    FILE *arq = fopen(GRAFO_ATUAL, "r");

    if (arq == NULL) return NULL;

    int n;

    fscanf(arq, "%d", &n);

    Grafo_Lista *g = InitLista(n);

    if (g == NULL) {
        fclose(arq);
        return NULL;
    }

    int u, v;

    while (fscanf(arq, "%d %d", &u, &v) == 2) {
        InsertLista(g, u, v);
    }

    fclose(arq);

    return g;
}

void gerarRelatorio(Grafo *g) {
    if (g == NULL) return;

    FILE *arq = fopen("out/relatorio_matriz.txt", "w");

    if (arq == NULL) return;

    fprintf(arq, "RELATORIO - MATRIZ DE ADJACENCIA\n\n");

    fprintf(arq, "Numero de vertices: %d\n", g->numVert);
    fprintf(arq, "Numero de arestas: %d\n", numArestas(g));
    fprintf(arq, "Grau minimo: %d\n", grauMin(g));
    fprintf(arq, "Grau maximo: %d\n", grauMax(g));
    fprintf(arq, "Grau medio: %.2f\n", grauMedio(g));
    fprintf(arq, "Mediana de grau: %.2f\n", grauMediana(g));

    fprintf(arq, "\nDistancias:\n");
    fprintf(arq, "(10,20): %d\n", distancia(g, 10, 20));
    fprintf(arq, "(10,30): %d\n", distancia(g, 10, 30));
    fprintf(arq, "(20,30): %d\n", distancia(g, 20, 30));

    //fprintf(arq, "\nDiametro: %d\n", diametro(g));

    fprintf(arq, "\nMatriz de Adjacencia:\n\n");

    for (int i = 0; i < g->numVert; i++) {
        for (int j = 0; j < g->numVert; j++) {
            fprintf(arq, "%d ", g->matriz[i][j]);
        }
        fprintf(arq, "\n");
    }

    fclose(arq);
}

void gerarRelatorioLista(Grafo_Lista *g) {
    if (g == NULL) return;

    FILE *arq = fopen("out/relatorio_lista.txt", "w");

    if (arq == NULL) return;

    fprintf(arq, "RELATORIO - LISTA DE ADJACENCIA\n\n");

    fprintf(arq, "Numero de vertices: %d\n", g->numVert);
    fprintf(arq, "Numero de arestas: %d\n", numArestasLista(g));
    fprintf(arq, "Grau minimo: %d\n", grauMinLista(g));
    fprintf(arq, "Grau maximo: %d\n", grauMaxLista(g));
    fprintf(arq, "Grau medio: %.2f\n", grauMedioLista(g));
    fprintf(arq, "Mediana de grau: %.2f\n", grauMedianaLista(g));

    fprintf(arq, "\nDistancias:\n");
    fprintf(arq, "(10,20): %d\n", distanciaLista(g, 10, 20));
    fprintf(arq, "(10,30): %d\n", distanciaLista(g, 10, 30));
    fprintf(arq, "(20,30): %d\n", distanciaLista(g, 20, 30));

    //fprintf(arq, "\nDiametro: %d\n", diametroLista(g));

    fprintf(arq, "\nLista de Adjacencia:\n\n");

    for (int i = 0; i < g->numVert; i++) {
        fprintf(arq, "%d: ", i + 1);

        No *atual = g->lista[i];

        while (atual != NULL) {
            fprintf(arq, "%d -> ", atual->vertice);
            atual = atual->prox;
        }

        fprintf(arq, "NULL\n");
    }

    fclose(arq);
}

double calcularMemoria(Grafo *g) {
    if (g == NULL) return 0.0;

    size_t memoria = 0;

    memoria += sizeof(Grafo);
    memoria += g->numVert * sizeof(int *);

    for (int i = 0; i < g->numVert; i++) {
        memoria += g->numVert * sizeof(int);
    }

    return memoria / (1024.0 * 1024.0);
}

double bfs100(Grafo *g) {
    if (g == NULL) return -1.0;

    double soma = 0.0;

    for (int i = 0; i < 100; i++) {
        int origem = (i % g->numVert) + 1;

        clock_t inicio = clock();

        Resultado r = bfs(g, origem);

        clock_t fim = clock();

        if (!r.valido) {
            destruirResultado(r);
            return -1.0;
        }

        soma += ((double)(fim - inicio) * 1000.0) / CLOCKS_PER_SEC;

        destruirResultado(r);
    }

    return soma / 100.0;
}

double dfs100(Grafo *g) {
    if (g == NULL) return -1.0;

    double soma = 0.0;

    for (int i = 0; i < 100; i++) {
        int origem = (i % g->numVert) + 1;

        clock_t inicio = clock();

        Resultado r = dfs(g, origem);

        clock_t fim = clock();

        if (!r.valido) {
            destruirResultado(r);
            return -1.0;
        }

        soma += ((double)(fim - inicio) * 1000.0) / CLOCKS_PER_SEC;

        destruirResultado(r);
    }

    return soma / 100.0;
}

double calcularMemoriaLista(Grafo_Lista *gl) {
    if (gl == NULL) return 0.0;

    size_t memoria = 0;

    memoria += sizeof(Grafo_Lista);
    memoria += gl->numVert * sizeof(No *);

    for (int i = 0; i < gl->numVert; i++) {
        No *atual = gl->lista[i];

        while (atual != NULL) {
            memoria += sizeof(No);
            atual = atual->prox;
        }
    }

    return memoria / (1024.0 * 1024.0);
}

double bfs100Lista(Grafo_Lista *gl) {
    if (gl == NULL) return -1.0;

    double soma = 0.0;

    for (int i = 0; i < 100; i++) {
        int origem = (i % gl->numVert) + 1;

        clock_t inicio = clock();

        Resultado r = bfsLista(gl, origem);

        clock_t fim = clock();

        if (!r.valido) {
            destruirResultado(r);
            return -1.0;
        }

        soma += ((double)(fim - inicio) * 1000.0) / CLOCKS_PER_SEC;

        destruirResultado(r);
    }

    return soma / 100.0;
}

double dfs100Lista(Grafo_Lista *gl) {
    if (gl == NULL) return -1.0;

    double soma = 0.0;

    for (int i = 0; i < 100; i++) {
        int origem = (i % gl->numVert) + 1;

        clock_t inicio = clock();

        Resultado r = dfsLista(gl, origem);

        clock_t fim = clock();

        if (!r.valido) {
            destruirResultado(r);
            return -1.0;
        }

        soma += ((double)(fim - inicio) * 1000.0) / CLOCKS_PER_SEC;

        destruirResultado(r);
    }

    return soma / 100.0;
}

void gerarEstudoCaso(Grafo *g, Grafo_Lista *gl) {
    FILE *arq = fopen("out/estudoDeCaso_grafo_1.txt", "w");

    if (arq == NULL) return;

    fprintf(arq, "---------- MATRIZ DE ADJACENCIA ----------\n\n");

    fprintf(arq, "Estatisticas da matriz:\n");
    fprintf(arq, "Memoria utilizada: %.2f MB\n", calcularMemoria(g));
    fprintf(arq, "Numero de vertices: %d\n", g->numVert);
    fprintf(arq, "Numero de arestas: %d\n", numArestas(g));
    fprintf(arq, "Grau minimo: %d\n", grauMin(g));
    fprintf(arq, "Grau maximo: %d\n", grauMax(g));
    fprintf(arq, "Grau medio: %.2f\n", grauMedio(g));
    fprintf(arq, "Grau mediana: %.2f\n", grauMediana(g));
    fprintf(arq, "Tempo medio de execucao em 100 BFS: %.2f ms\n", bfs100(g));
    fprintf(arq, "Tempo medio de execucao em 100 DFS: %.2f ms\n\n", dfs100(g));

    for (int i = 1; i <= 3; i++) {
        Resultado r = bfs(g, i);

        if (r.valido) {
            fprintf(arq, "BFS inicio: %d\n", i);
            fprintf(arq, "Pai(10): %d\n", r.pai[9]);
            fprintf(arq, "Pai(20): %d\n", r.pai[19]);
            fprintf(arq, "Pai(30): %d\n\n", r.pai[29]);
        }

        destruirResultado(r);
    }

    for (int i = 1; i <= 3; i++) {
        Resultado r = dfs(g, i);

        if (r.valido) {
            fprintf(arq, "DFS inicio: %d\n", i);
            fprintf(arq, "Pai(10): %d\n", r.pai[9]);
            fprintf(arq, "Pai(20): %d\n", r.pai[19]);
            fprintf(arq, "Pai(30): %d\n\n", r.pai[29]);
        }

        destruirResultado(r);
    }

    fprintf(arq, "Distancia entre pares (10,20): %d\n", distancia(g, 10, 20));
    fprintf(arq, "Distancia entre pares (10,30): %d\n", distancia(g, 10, 30));
    fprintf(arq, "Distancia entre pares (20,30): %d\n\n", distancia(g, 20, 30));

    fprintf(arq, "---------- LISTA DE ADJACENCIA ----------\n\n");

    fprintf(arq, "Estatisticas da lista:\n");
    fprintf(arq, "Memoria utilizada: %.2f MB\n", calcularMemoriaLista(gl));
    fprintf(arq, "Numero de vertices: %d\n", gl->numVert);
    fprintf(arq, "Numero de arestas: %d\n", numArestasLista(gl));
    fprintf(arq, "Grau minimo: %d\n", grauMinLista(gl));
    fprintf(arq, "Grau maximo: %d\n", grauMaxLista(gl));
    fprintf(arq, "Grau medio: %.2f\n", grauMedioLista(gl));
    fprintf(arq, "Grau mediana: %.2f\n", grauMedianaLista(gl));
    fprintf(arq, "Tempo medio de execucao em 100 BFS: %.2f ms\n", bfs100Lista(gl));
    fprintf(arq, "Tempo medio de execucao em 100 DFS: %.2f ms\n\n", dfs100Lista(gl));

    for (int i = 1; i <= 3; i++) {
        Resultado r = bfsLista(gl, i);

        if (r.valido) {
            fprintf(arq, "BFS inicio: %d\n", i);
            fprintf(arq, "Pai(10): %d\n", r.pai[9]);
            fprintf(arq, "Pai(20): %d\n", r.pai[19]);
            fprintf(arq, "Pai(30): %d\n\n", r.pai[29]);
        }

        destruirResultado(r);
    }

    for (int i = 1; i <= 3; i++) {
        Resultado r = dfsLista(gl, i);

        if (r.valido) {
            fprintf(arq, "DFS inicio: %d\n", i);
            fprintf(arq, "Pai(10): %d\n", r.pai[9]);
            fprintf(arq, "Pai(20): %d\n", r.pai[19]);
            fprintf(arq, "Pai(30): %d\n\n", r.pai[29]);
        }

        destruirResultado(r);
    }

    fprintf(arq, "Distancia entre pares (10,20): %d\n", distanciaLista(gl, 10, 20));
    fprintf(arq, "Distancia entre pares (10,30): %d\n", distanciaLista(gl, 10, 30));
    fprintf(arq, "Distancia entre pares (20,30): %d\n", distanciaLista(gl, 20, 30));

    fclose(arq);
}