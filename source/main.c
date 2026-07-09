#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "grafo_p.h"

void usarMatriz(Grafo *g) {
    if (g == NULL) return;

    gerarRelatorio(g);
    bfs(g, 1);
    dfs(g, 1);
    componentes(g);

    printf("Relatorio da matriz gerado em tests/relatorio_matriz.txt\n");

    Destroy(g);
}

void usarLista(Grafo_Lista *g) {
    if (g == NULL) return;

    gerarRelatorioLista(g);
    bfsLista(g, 1);
    dfsLista(g, 1);
    componentesLista(g);

    printf("Relatorio da lista gerado em tests/relatorio_lista.txt\n");

    DestroyLista(g);
}

int main() {
    int opcao;

    Grafo *g = LerArq();
    Grafo_Lista *gl = LerArqLista();

    do {
        printf("1 - Usar matriz\n");
        printf("2 - Usar lista\n");
        printf("3 - Realizar estudo de caso - Grafo\n");
        printf("4 - Realizar estudo de caso - Grafo Ponderado\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao) {
            case 1: {
                usarMatriz(g);
                break;
            }

            case 2: {
                usarLista(gl);
                break;
            }

            case 3: {
                gerarEstudoCaso(g, gl);
                
                /*Grafo *g = LerArq();
                Grafo_Lista *gl = LerArqLista();

                if (g == NULL || gl == NULL) {
                    printf("Erro ao carregar grafos para estudo de caso.\n");

                    if (g != NULL) Destroy(g);
                    if (gl != NULL) DestroyLista(gl);

                    break;
                }

                printf("\nExecutando estudo de caso...\n");

                GerarArq(g, gl);

                bfs(g, 1);
                dfs(g, 1);
                componentes(g);

                bfsLista(gl, 1);
                dfsLista(gl, 1);
                componentesLista(gl);

                printf("Estudo de caso finalizado.\n");
                printf("Arquivos gerados em tests/.\n");

                Destroy(g);
                DestroyLista(gl);*/
                break;
            }

            case 4: {
                GrafoP *gp = LerArqP();

                if (gp == NULL) return 1;

                gerarEstudoCasoP(gp);

                DestroyP(gp);
                
                break;
            }
        }

    } while (opcao != 0);

    return 0;
}