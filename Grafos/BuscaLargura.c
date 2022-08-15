#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 10000

 typedef struct Cell
 {
     int item;
     struct Cell *next;

 } Cell;

 typedef struct FilaE
 {
     Cell *inicio;
     Cell *fim;

 } FilaE;

 Cell* criar_celula(int key)
 {
     Cell *c = (Cell*) malloc(sizeof(Cell));
     c->item = key;

     c->next = NULL;

     return c;
 }

 FilaE* criar_filaE()
 {
     FilaE *f = (FilaE*) malloc(sizeof(FilaE));

     f->inicio = NULL;
     f->fim = NULL;

     return f;
 }

 int filaE_vazia(FilaE* f)
 {
     return (f == NULL) || (f->inicio == NULL);
 }

 void enfileirar(int key, FilaE* f)
 {
     Cell *aux;

     if(f == NULL)
     {
         f = criar_filaE();
     }

     aux = criar_celula(key);

     if(f->inicio == NULL)
     {
         f->inicio = f->fim = aux;
     }
     else
     {
         f->fim->next = aux;
         f->fim = f->fim->next;
     }
 }

 int desenfileirar(FilaE* f)
 {
     Cell *aux;
     int item = -INT_MAX;

     if(!filaE_vazia(f))
     {
         aux = f->inicio;

         f->inicio = aux->next;

         item = aux->item;

         free(aux);
     }

     return item;
 }

 void imprimir_fila(FilaE* f)
 {
     Cell *aux;

     if(!filaE_vazia(f))
     {
         aux = f->inicio;

         while(aux != NULL)
         {
             printf("%d ", aux->item);
             aux = aux->next;
         }
     }
 }

 int liberar_filaE(FilaE* f)
 {
     if(!filaE_vazia(f))
     {
         while(f->inicio != NULL)
         {
             desenfileirar(f);
         }

         free(f);

         return 1;
     }

    return 0;
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
         G->mat[v1][v2] = G->mat[v2][v1] = 1;
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

 void buscaLargura(GrafoMA* grafo, int raiz)
 {
     int i, j, k, tam;
     int *cor, *d, *pai;
     int **mat;
     FilaE* fila;

     tam = grafo->V;

     cor = (int*) malloc(sizeof(int) * tam);
     d = (int*) malloc(sizeof(int) * tam);
     pai = (int*) malloc(sizeof(int) * tam);

     for(i = 0; i < tam; i++)
     {
         if(i != raiz)
         {
             cor[i] = 0;
             d[i] = INF;
             pai[i] = INF;
         }
         else
         {
             cor[i] = 1;
             d[i] = 0;
             pai[i] = INF;
         }
     }

     fila = criar_filaE();
     enfileirar(raiz, fila);

     mat = adjacentes(grafo);

     while(!filaE_vazia(fila))
     {
         i = desenfileirar(fila);

         for(j = (mat[i][0] - 1), k = 0; mat[i][k] != 0; k++, j = (mat[i][k] - 1))
         {
             if(cor[j] == 0)
             {
                 cor[j] = 1;
                 d[j] = d[i] + 1;
                 pai[j] = i;

                 enfileirar(j, fila);
             }
         }

         cor[i] = 2;
     }

     printf("v d p\n");

     for(i = 0; i < tam; i++)
     {
         printf("%d ", i);

         if(d[i] == INF)
         {
             printf("- ");
         }
         else
         {
             printf("%d ", d[i]);
         }

         if(pai[i] == INF)
         {
             printf("- ");
         }
         else
         {
             printf("%d ", pai[i]);
         }

         printf("\n");
     }
 }

 int main()
 {
     int i, j, tam, num, raiz;
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

     scanf("%d", &raiz);

     buscaLargura(grafo, raiz);

     return 0;
 }
