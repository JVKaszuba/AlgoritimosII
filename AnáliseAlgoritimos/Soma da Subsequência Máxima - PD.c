 #include <stdio.h>
 #include <string.h>
 #include <math.h>
 #include <stdlib.h>
 #include <limits.h>

 int max(int a, int b)
 {
     return (a > b) ? a : b;
 }

 int maiorsoma(int *vet, int tam)
 {
     int i, soma, somaT;

     soma = 0;
     somaT = INT_MIN;

     for(i=0; i<=tam; i++)
     {
         soma += vet[i];

         if(soma > somaT)
         {
             somaT = soma;
         }

         if(soma < 0)
         {
             soma = 0;
         }
     }

     return somaT;
 }

 int main()
 {
     int i, tam;
     int *vet;

     scanf("%d", &tam);
     vet = malloc(tam*sizeof(int));

     for(i=0; i<tam; i++)
     {
         scanf("%d", &vet[i]);
     }

     printf("%d", maiorsoma(vet, tam - 1));

     return 0;
 }

