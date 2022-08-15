#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 10000

 typedef struct ItemF
 {
     int chave;
     int vertice;
     int cor;

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
         f->item[num].cor = 0;
         f->n++;
     }
 }

 int desenfileirar(Fila *f)
 {
     int i, ini = 0;
     ItemF item;

     if(!fila_vazia(f))
     {
         for(i = 0; i < f->tam; i++)
         {
             item = f->item[ini];

             if(f->item[i].chave < item.chave)
             {
                 ini = i;
             }
         }

         f->item[ini].chave = INF;
         f->item[ini].cor = 1;
         f->n--;
     }

     return f->item[ini].vertice;
 }

 int pesquisar(Fila* fila, int chave)
 {
     if(fila->item[chave].cor != 1)
     {
         return 1;
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

     for(i = 0; i < f->n; i++)
     {
         if(f->item[i].cor != 1)
         {
             printf("%d ", i);
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

 void arvorePrim(GrafoMA* grafo, int** distancia)
 {
     int i, j, k, tam;
     int *key, *pai;
     int **mat;
     Fila *fila;

     tam = grafo->V;

     fila = criar_fila(tam);

     key = (int*) malloc(sizeof(int) * tam);
     pai = (int*) malloc(sizeof(int) * tam);

     for(i = 0; i < tam; i++)
     {
         key[i] = INF;
         pai[i] = INF;
         enfileirar(fila, i, key);
     }

     key[0] = 0;

     mat = adjacentes(grafo);

     while(!fila_vazia(fila))
     {
         i = desenfileirar(fila);

         for(j = (mat[i][0] - 1), k = 0; mat[i][k] != 0; k++, j = (mat[i][k] - 1))
         {
             if((pesquisar(fila, j) == 1) && (distancia[i][j] < key[j]))
             {
                 pai[j] = i;
                 key[j] = distancia[i][j];
                 fila->item[j].chave = key[j];
             }
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

     arvorePrim(grafo, distancias);

     return 0;
 }
