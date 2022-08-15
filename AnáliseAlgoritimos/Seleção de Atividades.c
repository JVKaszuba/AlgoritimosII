#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void guloso(int **vet, int tam){

    int i, j, k, l;

    int *res;
    res = malloc(tam*sizeof(int));

    for(i=0; i<tam; i++)
    {
        for(j=0; j<i; j++)
        {
            if(vet[i][1] < vet[j][1])
            {
                k = vet[i][0];
                l = vet[i][1];

                vet[i][0] = vet[j][0];
                vet[i][1] = vet[j][1];

                vet[j][0] = k;
                vet[j][1] = l;
            }
        }
    }

    for(i=0; i<tam; i++)
    {
        printf("%d %d \n", vet[i][0], vet[i][1]);
    }

    for(i=0, j=0, k=0; i<tam; i++)
    {
        if(i == 0)
        {
            j = i;
            res[k] = j;
            k++;
        }
        else if(vet[i][0] > vet[j][1])
        {
            j = i;
            res[k] = j;
            k++;
        }
    }

    printf("Aulas alocadas: ");

    for(i=0; i<k; i++)
    {
        printf("%d ", res[i]);
    }

}

int main(void)
{
    int n, i;
    scanf("%d", &n);

    int **vet;
    vet = malloc(n*sizeof(int*));

    for(i=0; i<n; i++)
    {
        vet[i] = malloc(2*sizeof(int));
    }

    for(i=0; i<n; i++)
    {
        scanf("%d %d", &vet[i][0], &vet[i][1]);
    }

    guloso(vet, n);

    return 0;
}
