typedef struct Grafo {
    int numVert;
    int **matriz;
} Grafo;

Grafo *Init(int tam);

void Destroy(Grafo *g);

void Display(Grafo *g);

void Insert(Grafo *g, int u, int v);

void LerArq(Grafo *g);