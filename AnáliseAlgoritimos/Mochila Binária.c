 #include <stdio.h>
 #include <string.h>
 #include <math.h>
 #include <stdlib.h>

 int max(int a, int b)
 {
     return (a > b) ? a : b;
 }

int mochila_binaria(int cap, int quant, int *peso, int *valor)
 {
     int i, j, soma;
     int mat[quant+1][cap+1];

     for(i=0; i<=quant; i++)
     {
         for(j=0; j<=cap; j++)
         {
             if(i==0 || j==0)
             {
                 mat[i][j] = 0;
             }
             else if(peso[i-1] <= j)
             {

                 mat[i][j] = max((valor[i-1] + mat[i-1][j-peso[i-1]]), mat[i-1][j]);
             }
             else
             {
                 mat[i][j] = mat[i-1][j];
             }
         }
     }

     soma = mat[quant][cap];

     return soma;
 }

 int main(){

     int i, cap, quant;
     int *peso, *valor;

     scanf("%d", &cap);
     scanf("%d", &quant);

     peso = malloc(quant*sizeof(int));
     valor = malloc(quant*sizeof(int));

     for(i=0; i<quant; i++)
     {
         scanf("%d %d", &peso[i], &valor[i]);
     }

     printf("%d", mochila_binaria(cap, quant, peso, valor));

     return 0;
 }
