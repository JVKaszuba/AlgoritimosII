 #include <stdio.h>
 #include <string.h>
 #include <math.h>
 #include <stdlib.h>

typedef struct Node
{
	int item;
	struct Node *left;
	struct Node *right;

} Node;

 Node* criar(int item)
 {
 	 Node* tree = (Node*) malloc(sizeof(Node));

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

 int altura(Node* tree)
 {
     int esq, dir;
     Node* treeB = tree;

     if(treeB == NULL)
     {
         return 0;
     }

     esq = altura(treeB->left);
     dir = altura(treeB->right);

     if(esq > dir)
     {
         esq++;

         return esq;
     }
     else
     {
         dir++;

         return dir;
     }
 }

 int verificar(Node* tree)
 {
     int esq, dir, total;
     Node* treeB = tree;

     if(treeB == NULL)
     {
         return 1;
     }

     esq = altura(treeB->left);
     dir = altura(treeB->right);

     if(esq > dir)
     {
         total = esq - dir;
     }
     else
     {
         total = dir - esq;
     }

     if((total <= 1) && (verificar(treeB->left)) && (verificar(treeB->right)))
     {
         return 1;
     }

     return 0;
 }

 int main()
 {
     int i, nos, num;
     Node* avrL = NULL;

     scanf("%d", &nos);

     for(i=0; i<nos; i++)
     {
         scanf("%d", &num);
         avrL = inserir(num, avrL);
     }

     printf("%d", verificar(avrL));

     return 0;
 }
