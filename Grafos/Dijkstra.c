#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 10000

 typedef struct ItemF
 {
     int chave;
     int vertice;

 } ItemF;

 typedef struct Fila
 {
     ItemF *item;
     int n;
     int tam;

 } Fila;

 void troca(ItemF *a, ItemF *b)
 {
     ItemF t = *a;

     *a = *b;
     *b = t;
 }

 Fila* criar_fila(int tam)
 {
     Fila *f = (Fila*) malloc(sizeof(Fila));

     f->item = (ItemF*) malloc(sizeof(ItemF) * tam);
     f->n = 0;
     f->tam = tam;

     return f;
 }

 int fila_cheia(Fila *f)
 {
     if(f == NULL)
     {
         return -1;
     }
     else if(f->n < f->tam)
     {
         return 0;
     }
     else
     {
         return 1;
     }
}

 int fila_vazia(Fila *f)
 {
     if(f == NULL)
     {
         return -1;
     }
     else if (f->n > 0)
     {
         return 0;
     }
     else
     {
         return 1;
     }
 }

 void enfileirar(Fila *f, int num, int* key)
 {
     if(!fila_cheia(f))
     {
         f->item[num].chave = key[num];
         f->item[num].vertice = num;
         f->n++;
     }
 }

 int desenfileirar(Fila *f)
 {
     int i, ini = 0;
     ItemF item;

     if(!fila_vazia(f))
     {
         item = f->item[ini];

         for(i = 0; i < f->n; i++)
         {
             if(f->item[i].chave < item.chave)
             {
                 ini = i;
                 f->item[ini].chave = -1;
                 troca(&f->item[ini], &f->item[f->n-1]);
             }
         }

         f->n--;
     }

     return f->item[ini].vertice;
 }

 int pesquisar(Fila* fila, int chave)
 {
     int i;

     for(i = 0; i < fila->n; i++)
     {
         if(fila->item[chave].chave != -1)
         {
             return 1;
         }
     }

     return 0;
 }

 void liberar_fila(Fila *f)
 {
    if(f != NULL)
    {
        free(f);
    }
 }

 void liberar_itemF(ItemF *item)
 {
    if (item != NULL)
    free(item);
 }

 void imprimir_fila(Fila *f)
 {
     int i;

     for(i = 0; i < f->tam; i++)
     {
         if(f->item[i].chave != -1)
         {
             printf("%d ", f->item[i].vertice);
         }
     }
 }

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

 void arvoreDijkstra(GrafoMA* grafo, int** distancia)
 {
     int i, j, k, tam;
     int *d, *pai;
     int **mat;
     Fila *fila;

     tam = grafo->V;

     fila = criar_fila(tam);

     d = (int*) malloc(sizeof(int) * tam);
     pai = (int*) malloc(sizeof(int) * tam);

     for(i = 0; i < tam; i++)
     {
         d[i] = INF;
         pai[i] = INF;
         enfileirar(fila, i, d);
     }

     d[0] = 0;

     mat = adjacentes(grafo);

     while(!fila_vazia(fila))
     {
         i = desenfileirar(fila);

         printf("\ni = %d\n", i);
         imprimir_fila(fila);

         for(j = (mat[i][0] - 1), k = 0; mat[i][k] != 0; k++, j = (mat[i][k] - 1))
         {
             printf("\nj = %d\n", j);
             printf("d[%d] = %d\n", j, d[j]);

             if(d[j] > (d[i] + distancia[i][j]))
             {
                 d[j] = d[i] + distancia[i][j];
                 fila->item[j].chave = d[j];
                 pai[j] = i;
             }

             printf("\nd[%d] = %d\n", j, d[j]);
             printf("pai[%d] = %d\n", j, pai[j]);
         }
     }

     for(i = 0; i < tam; i++)
     {
         printf("%d: ", i);

         if(pai[i] == INF)
         {
             printf("-\n");
         }
         else
         {
             printf("%d\n", pai[i]);
         }
     }
 }

 int main()
 {
     int i, j, tam, num;
     int **distancias;
     GrafoMA* grafo = NULL;

     scanf("%d", &tam);

     grafo = iniciar_grafoMA(tam);
     distancias = (int**) malloc(sizeof(int*) * tam);

     for(i = 0; i < tam; i++)
     {
         distancias[i] = (int*) calloc(tam, sizeof(int));
     }

     for(i = 0; i < tam; i++)
     {
         for(j = 0; j < tam; j++)
         {
             scanf("%d", &num);

             distancias[i][j] = num;

             if(num != 0)
             {
                inserir_aresta(grafo, i, j);
             }
         }
     }

     arvoreDijkstra(grafo, distancias);

     return 0;
 }
