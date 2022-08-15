 #include <stdio.h>
 #include <string.h>
 #include <math.h>
 #include <stdlib.h>

 int divisao(int *vet1, int *vet2, int ini, int fim, int soma)
 {
     int meio;

     if(ini == fim)
     {
        if(vet1[ini] > vet2[ini])
        {
            soma += (vet1[ini] - vet2[ini]);
            printf("%d - %d = %d\n", vet1[ini], vet2[ini], soma);
        }
        else
        {
            soma += (vet2[ini] - vet1[ini]);
            printf("%d - %d = %d\n", vet1[ini], vet2[ini], soma);
        }
     }
     else
     {
         meio = (ini+fim)/2;
         printf("%d\n", meio);

         soma += divisao(vet1, vet2, ini, meio, soma) + divisao(vet1, vet2, meio+1, fim, soma);
     }

     return soma;
 }

 int main()
 {
     int i, n;
     int *v1, *v2;

     scanf("%d", &n);

     v1 = malloc(n*sizeof(int));
     v2 = malloc(n*sizeof(int));

     for(i=0; i<n; i++)
     {
         scanf("%d", &v1[i]);
     }

     for(i=0; i<n; i++)
     {
         scanf("%d", &v2[i]);
     }

     printf("%d", divisao(v1, v2, 0, n-1, 0));

     return 0;
 }
