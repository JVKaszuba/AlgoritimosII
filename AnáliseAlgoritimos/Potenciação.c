 #include <stdio.h>
 #include <string.h>
 #include <math.h>
 #include <stdlib.h>

 int potenciacao(int num, int expo)
 {
     if(expo == 0)
     {
         return 1;
     }
     else if(expo == 1)
     {
         return num;
     }
     else
     {
         if(expo%2 == 0)
         {
            return potenciacao(num * num, expo/2);
         }
         else
         {
             return num * potenciacao(num * num, expo/2);
         }
     }
 }

 int main(){

     int a, b;

     scanf("%d %d", &a, &b);

     if(a >= 0 && b >= 0)
     {
         printf("%d", potenciacao(a, b));
     }

    return 0;
 }
