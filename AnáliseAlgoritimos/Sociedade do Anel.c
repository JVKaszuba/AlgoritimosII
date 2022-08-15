 #include <stdio.h>
 #include <string.h>
 #include <math.h>
 #include <stdlib.h>
 #include <limits.h>

 int percorrer(int l, int c, int mat[l][c], int nPl, int nPc, int soma)
 {
     int min=INT_MAX, aft=0;

     if(nPl == l-1 && nPc == c-1)
     {
         return soma;
     }

     if(min > mat[nPl+1][nPc] && nPl+1 >= 0 && mat[nPl+1][nPc] != INT_MAX)
     {
         aft = 2;
         min = mat[nPl+1][nPc];
         printf("%d %d\n", soma, min);
     }
     if(min > mat[nPl-1][nPc] && nPl-1 >= 0 && mat[nPl-1][nPc] != INT_MAX)
     {
         aft = 1;
         min = mat[nPl-1][nPc];
         printf("%d %d\n", soma, min);
     }
     if(min > mat[nPl][nPc+1] && nPc+1 >= 0 && mat[nPl][nPc+-1] != INT_MAX)
     {
         aft = 4;
         min = mat[nPl][nPc+1];
         printf("%d %d\n", soma, min);
     }
     if(min > mat[nPl][nPc-1] && nPc-1 >= 0 && mat[nPl][nPc-1] != INT_MAX)
     {
         aft = 3;
         min = mat[nPl][nPc-1];
         printf("%d %d\n", soma, min);
     }

     if(aft == 2)
     {
         soma = soma + mat[nPl+1][nPc];
         mat[nPl][nPc] = INT_MAX;
         return percorrer(l, c, mat, nPl+1, nPc, soma);
     }
     if(aft == 1)
     {
         soma = soma + mat[nPl-1][nPc];
         mat[nPl][nPc] = INT_MAX;
         return percorrer(l, c, mat, nPl-1, nPc, soma);
     }
     if(aft == 4)
     {
         soma = soma + mat[nPl][nPc+1];
         mat[nPl][nPc] = INT_MAX;
         return percorrer(l, c, mat, nPl, nPc+1, soma);
     }
     if(aft == 3)
     {
         soma = soma + mat[nPl][nPc-1];
         mat[nPl][nPc] = INT_MAX;
         return percorrer(l, c, mat, nPl, nPc-1, soma);
     }


     return soma;
 }

 int main()
 {
     int i, j, l, c, res;

     scanf("%d %d", &l, &c);
     int mat[l][c];

     for(i=0; i<l; i++)
     {
         for(j=0; j<c; j++)
         {
             scanf("%d", &mat[i][j]);
         }
     }

     res = percorrer(l, c, mat, 0, 0, 0);

     if(res >= 0)
     {
         printf("%d", res);
     }
     else
     {
         printf("sem solucao");
     }

     return 0;
 }
