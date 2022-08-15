#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 10000

 typedef struct GrafoMA
 {
    int V;
    int A;
    int **mat;

 } GrafoMA;

 static int** iniciar_MA(int n)
 {
     int i;
     int **mat = (int**) malloc(n * sizeof(int*));

     for (i = 0; i < n; i++)
     {
         mat[i] = (int*) calloc(n, sizeof(int));
     }

     return mat;
 }

 static int valida_vertice(GrafoMA* G, int v)
 {
    return (v >= 0) && (v < G->V);
 }

 GrafoMA* iniciar_grafoMA(int v)
 {
     GrafoMA* G = (GrafoMA*) malloc(sizeof(GrafoMA));

     G->V = v;
     G->A = 0;
     G->mat = iniciar_MA(G->V);

     return G;
 }

 int aresta_existe(GrafoMA* G, int v1, int v2)
 {
    return (G != NULL) && valida_vertice(G, v1) && valida_vertice(G, v2) && (G->mat[v1][v2] != 0);
 }


 void inserir_aresta(GrafoMA* G, int v1, int v2)
 {
     if(!aresta_existe(G, v1, v2))
     {
         G->mat[v1][v2] = 1;
         G->A++;
     }
 }

 void remover_aresta(GrafoMA* G, int v1, int v2)
 {
     if(aresta_existe(G, v1, v2))
     {
         G->mat[v2][v1] = G->mat[v1][v2] = 0;
         G->A--;
     }
 }

 void imprimir_arestas(GrafoMA* G)
 {
     int i, j;

     for(i = 1; i < G->V; i++)
     {
         for (j = 0; j < i; j++)
         {
             if (G->mat[i][j] == 1)
             {
                 printf("(%d, %d)\n", i, j);
             }
         }
     }
}

 void liberarGMA(GrafoMA* G)
 {
     if(G != NULL)
     {
        free(G->mat);
        free(G);
     }
 }

 int** adjacentes(GrafoMA* grafo)
 {
     int i, j, k, tam;
     int **mat;

     tam = grafo->V;
     mat = (int**) malloc(sizeof(int*) * tam);

     for(i = 0; i < tam; i++)
     {
         mat[i] = (int*) calloc(tam, sizeof(int));
     }

     for(i = 0; i < tam; i++)
     {
         for(j = 0, k = 0; j < tam; j++)
         {
             if(grafo->mat[i][j] != 0)
             {
                 mat[i][k] = j + 1;
                 k++;
             }
         }
     }

    return mat;
 }

 void buscaVertice(GrafoMA* grafo, int i, int* cor, int* tempo, int* recur, int* d, int* f, int* pai, int** mat)
 {
     int j, k;

     cor[i] = 1;
     *tempo = *tempo + 1;
     d[i] = *tempo;

     for(j = (mat[i][0] - 1), k = 0; mat[i][k] != 0; k++, j = (mat[i][k] - 1))
     {
         if(cor[j] == 0)
         {
             pai[j] = i;
             buscaVertice(grafo, j, cor, tempo, recur, d, f, pai, mat);
         }
         else if((cor[j] == 2) && (grafo->mat[i][j] == 1))
         {
             *recur = *recur + 1;
         }
     }

     cor[i] = 2;
     f[i] = *tempo = *tempo + 1;
 }

 void buscaProfundidade(GrafoMA* grafo)
 {
     int i, tam, tempo, recur;
     int *cor, *pai, *d, *f, *pTempo, *pRecur;
     int **mat;

     tam = grafo->V;

     cor = (int*) malloc(sizeof(int) * tam);
     pai = (int*) malloc(sizeof(int) * tam);
     d = (int*) calloc(tam, sizeof(int));
     f = (int*) calloc(tam, sizeof(int));

     tempo = 0;
     recur = 0;

     pTempo = &tempo;
     pRecur = &recur;

     mat = adjacentes(grafo);

     for(i = 0; i < tam; i++)
     {
        cor[i] = 0;
        pai[i] = INF;
     }

     for(i = 0; i < tam; i++)
     {
         if(cor[i] == 0)
         {
             buscaVertice(grafo, i, cor, pTempo, pRecur, d, f, pai, mat);
         }
     }

     if(recur >= 1)
     {
         printf("ciclico");
     }
     else
     {
         printf("aciclico");
     }
 }

 int main()
 {
     int i, j, tam, num;
     GrafoMA* grafo = NULL;

     scanf("%d", &tam);

     grafo = iniciar_grafoMA(tam);

     for(i = 0; i < tam; i++)
     {
         for(j = 0; j < tam; j++)
         {
             scanf("%d", &num);

             if(num == 1)
             {
                inserir_aresta(grafo, i, j);
             }
         }
     }

     buscaProfundidade(grafo);

     return 0;
 }
