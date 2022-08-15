 #include <stdio.h>
 #include <string.h>
 #include <math.h>
 #include <stdlib.h>

 typedef struct Node{

	int item;
	struct Node *left;
	struct Node *right;

 }Node;

 int max(int a, int b)
 {
     return (a > b) ? a : b;
 }

 Node* criar(int item)
 {
	Node *tree = (Node*) malloc(sizeof(Node));

	tree->item = item;
	tree->left = NULL;
	tree->right = NULL;

	return tree;
 }

 Node* inserir(int item, Node* tree)
 {
	if(tree == NULL)
    {
        tree = criar(item);
    }
	else if(item < tree->item)
    {
        tree->left = inserir(item, tree->left);
    }
	else if(item > tree->item)
    {
        tree->right = inserir(item, tree->right);
    }

	return tree;
 }

 int alturaRec(Node* tree)
 {
     int somaD, somaE;
     Node *treeB;

     treeB = tree;

     if(tree == NULL)
     {
         return -1;
     }
     else
     {
         somaD = alturaRec(treeB->right);
         somaE = alturaRec(treeB->left);
     }

     return max(somaD, somaE) + 1;
 }

  int main(){

     int i, num, tam, h;
     Node *avr;

     scanf("%d", &tam);

     for(i=0; i<tam; i++)
     {
         scanf("%d", &num);

         if(i==0)
         {
             avr = criar(num);
         }
         else
         {
            inserir(num, avr);
         }
     }

     h = alturaRec(avr);

     if(tam == (pow(2,h+1)-1))
     {
         printf("%d - sim", alturaRec(avr));
     }
     else
     {
         printf("%d - nao", alturaRec(avr));
     }

     return 0;
 }
