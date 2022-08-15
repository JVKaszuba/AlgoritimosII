 #include <stdio.h>
 #include <string.h>
 #include <math.h>
 #include <stdlib.h>

 void somar(int tam, int *vet)
 {
     int i, j, k, somaB;
     int soma = 0;

     for(i=0; i<tam; i++)
     {
         for(j=0; j<tam; j++)
         {
             somaB = 0;

             for(k=i; k<=j; k++)
             {
                 somaB += vet[k];
             }

             if(somaB > soma)
             {
                 soma = somaB;
             }
         }
     }

     printf("%d", soma);
 }

 int main()
 {
     int i, n;
     int *vet;

     scanf("%d", &n);
     vet = malloc(n*sizeof(int));

     for(i=0; i<n; i++)
     {
         scanf("%d", &vet[i]);
     }

     somar(n, vet);

     return 0;
 }
