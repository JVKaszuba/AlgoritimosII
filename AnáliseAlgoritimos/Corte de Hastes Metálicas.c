 #include <stdio.h>
 #include <string.h>
 #include <math.h>
 #include <stdlib.h>

 int max(int a, int b)
 {
     return (a > b) ? a : b;
 }

 int max3(int a, int b, int c)
 {
     return max(max(a, b), c);
 }

 int backracking(int *vet, int sz, int tam)
 {
     int i, j, soma;

         for(i=1; i<=tam && i<=tam; i++)
         {
             if((sz%i == 0) && (vet[i-1]*(sz/i)>soma))
             {
                 for(j=i; j<tam; j++)
                 {
                     if(soma == max3(vet[i-1]*(sz/i), vet[j-1]*(sz/j), soma))
                     {
                        break;
                     }
                     else
                     {
                         soma = max3(vet[i-1]*(sz/i), vet[j-1]*(sz/j), soma);
                     }
                 }
             }
         }

     return soma;
 }

 int main(){

     int i, tam, n;
     int *valor;

     scanf("%d", &tam);
     scanf("%d", &n);

     valor = malloc(n*sizeof(int));

     for(i=0; i<n; i++)
     {
         scanf("%d", &valor[i]);
     }

     printf("%d", backracking(valor, tam, n));

     return 0;
 }
