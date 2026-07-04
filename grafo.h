typedef struct Grafo {
    int numVert;
    int **matriz;
} Grafo;

Grafo *Init(int tam);

void Destroy(Grafo *g);

void Display(Grafo *g);

void Insert(Grafo *g, int u, int v);

void LerArq(Grafo *g);

void GerarArq(Grafo *g);

/* Informações do grafo */
int NumeroVertices(Grafo *g);
int NumeroArestas(Grafo *g);

int GrauVertice(Grafo *g, int vertice);
int GrauMinimo(Grafo *g);
int GrauMaximo(Grafo *g);

float GrauMedio(Grafo *g);
float MedianaGrau(Grafo *g);