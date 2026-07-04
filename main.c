#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main() {
    Grafo *g = Init(5);

    if (g == NULL) return 1;

    //g = LerArq();

    LerArq(g);

    Display(g);

    GerarArq(g);

    Destroy(g);

    return 0;
}