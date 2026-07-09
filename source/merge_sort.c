#include "merge_sort.h"
#include <stdlib.h>
#include <stdio.h>

void mergeSort(int *lista, int tamanho) {
    if (lista == NULL || tamanho <= 1) return;

    int *aux = malloc(sizeof(int) * tamanho);

    if (aux == NULL) return;

    sort(lista, aux, 0, tamanho - 1);

    free(aux);
}

void sort(int *lista, int *aux, int inicio, int fim) {
    if (inicio >= fim) return;

    int meio = (inicio + fim) / 2;

    sort(lista, aux, inicio, meio);
    sort(lista, aux, meio + 1, fim);

    if (lista[meio] <= lista[meio + 1]) return;

    merge(lista, aux, inicio, meio, fim);
}

void merge(int *lista, int *aux, int inicio, int meio, int fim) {
    int idc;
    int idcEsq = inicio;
    int idcDir = meio + 1;

    for (idc = inicio; idc <= fim; idc++) aux[idc] = lista[idc];

    idc = inicio;

    while (idcEsq <= meio && idcDir <= fim) {
        if (aux[idcEsq] <= aux[idcDir]) lista[idc++] = aux[idcEsq++];
        else lista[idc++] = aux[idcDir++];
    }

    while (idcEsq <= meio) lista[idc++] = aux[idcEsq++];

    while (idcDir <= fim) lista[idc++] = aux[idcDir++];
}