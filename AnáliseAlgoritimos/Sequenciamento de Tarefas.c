 #include <stdio.h>
 #include <string.h>
 #include <math.h>
 #include <stdlib.h>

 typedef struct{

    int id;
    int e;
    int d;

 }tarefa;

 void organizar(tarefa *vet, int tam)
 {
     int i, j;
     tarefa iB;

     for(i=0; i<tam - 1; i++)
     {
         for(j=0; j< tam - i - 1; j++)
         {
             if((vet[j].d - vet[j].e) < (vet[j + 1].d - vet[j + 1].e))
             {
                 iB = vet[j];
                 vet[j] = vet[j+1];
                 vet[j+1] = iB;
             }
         }
     }

     /*for(i=0; i<tam; i++)
     {
         k = i;

         for(j=i+1; j<tam; j++)
         {
             if((vet[j].d - vet[j].e) > (vet[k].d - vet[k].e))
             {
                 k = j;
             }
         }

         iB = vet[i];
         vet[i] = vet[k];
         vet[k] = iB;
     }*/
 }

 void sequenciar(tarefa *vet, int tam)
 {
     int i, soma = 0;

     for(i=0; i<tam; i++)
     {
         if(i == 0)
         {
            soma = vet[i].d - vet[i].e;
         }
         else
         {
            soma = soma + (vet[i].d - vet[i].e);
         }
     }

     for(i=0; i<tam; i++)
     {
         printf("%d ", vet[i].id);
     }

     if(soma >= 0)
     {
         printf("\n0");
     }
     else
     {
         printf("\n%d", (-1*soma));
     }
 }

 int main()
 {
    int n, i;
    tarefa *vet;

    scanf("%d", &n);
    vet = malloc(n*sizeof(tarefa));

    for(i=0; i<n; i++)
    {
        vet[i].id = i;
        scanf("%d %d", &vet[i].e, &vet[i].d);
    }

    organizar(vet, n);

    sequenciar(vet, n);

    return 0;
 }
