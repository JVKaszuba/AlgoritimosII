 #include <stdio.h>
 #include <string.h>
 #include <math.h>
 #include <stdlib.h>
 #include <limits.h>

 int max_two(int a, int b)
 {
     return (a > b) ? a : b;
 }

 int max_three(int a, int b, int c)
 {
     return(max_two(max_two(a, b), c));
 }

 int mesclado(int *vet, int ini, int meio, int fim)
 {
    int i, soma;
    int somaE = INT_MIN, somaD = INT_MIN;

    soma = 0;

    for(i=meio; i>=ini; i--)
    {
        soma = soma + vet[i];

        if(soma > somaE)
        {
            somaE = soma;
        }
    }

    soma = 0;

    for(i=meio+1; i<=fim; i++)
    {
        soma = soma + vet[i];

        if(soma > somaD)
        {
            somaD = soma;
        }
    }

    return max_three(somaE+somaD, somaE, somaD);
 }

 int subsequencia(int *vet, int ini, int fim)
 {
     int meio;

     if(ini == fim)
     {
         return vet[ini];
     }
     else
     {
         meio = (fim+ini)/2;

         return max_three(subsequencia(vet, ini, meio), subsequencia(vet, meio+1, fim), mesclado(vet, ini, meio, fim));
     }
 }

 int main(){

     int i, tam;

     scanf("%d", &tam);
     int vet[tam];

     for(i=0; i<tam; i++)
     {
         scanf("%d", &vet[i]);
     }

     printf("%d", subsequencia(vet, 0, tam-1));

     return 0;
 }
