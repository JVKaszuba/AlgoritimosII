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

 void espelhar(Node *tree)
 {
     Node *treeB;

     if(tree == NULL)
     {
         return;
     }

     espelhar(tree->left);
     espelhar(tree->right);

     treeB = tree->left;
     tree->left = tree->right;
     tree->right = treeB;
 }

 void infix(Node* tree)
 {
     if(tree != NULL)
     {
         infix(tree->left);
         printf("%d ", tree->item);
         infix(tree->right);
     }
 }

   int main(){

     int i, num, tam;
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

     espelhar(avr);
     infix(avr);

     return 0;
 }
