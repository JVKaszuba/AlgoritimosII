 #include <stdio.h>
 #include <string.h>
 #include <math.h>
 #include <stdlib.h>

  typedef struct Node{

	int item;
	struct Node *left;
	struct Node *right;

 } NodeBi;

 NodeBi* criar_Bi(int item)
 {
	NodeBi *tree = (NodeBi*) malloc(sizeof(NodeBi));

	tree->item = item;
	tree->left = NULL;
	tree->right = NULL;

	return tree;
 }

 NodeBi* inserir_Bi(int item, NodeBi* tree)
 {
	if(tree == NULL)
    {
        tree = criar_Bi(item);
    }
	else if(item < tree->item)
    {
        tree->left = inserir_Bi(item, tree->left);
    }
	else if(item > tree->item)
    {
        tree->right = inserir_Bi(item, tree->right);
    }

	return tree;
 }

 typedef struct Pointer
 {
 	 int item;
 	 int fb;
	 struct Pointer *left;
	 struct Pointer *right;

 }NodeAVL;

 NodeAVL* criar(int item)
 {
 	 NodeAVL* tree = (NodeAVL*) malloc(sizeof(NodeAVL));

 	 tree->item = item;
	 tree->left = NULL;
	 tree->right = NULL;
	 tree->fb = 0;

	 return tree;
 }

 static NodeAVL* rotateL_AVL(NodeAVL *tree)
 {
     NodeAVL *auxA = tree->left, *auxB;

 	 if(auxA->fb == +1)
     {
		 tree->left = auxA->right;
		 auxA->right = tree;
		 tree->fb = 0;
		 tree = auxA;
	 }
	 else
     {
		 auxB = auxA->right;
		 auxA->right = auxB->left;
		 auxB->left = auxA;
		 tree->left = auxB->right;
		 auxB->right = tree;

 		 if(auxB->fb == +1)
         {
             tree->fb = -1;
         }
		 else
         {
             tree->fb = 0;
         }

		 if(auxB->fb == -1)
         {
             auxA->fb = +1;
         }
		 else
         {
             auxA->fb = 0;
         }

		 tree = auxB;
	 }

	 return tree;
 }

 static NodeAVL* rotateR_AVL(NodeAVL *tree)
 {
 	 NodeAVL *auxA = tree->right, *auxB;

	 if(auxA->fb == -1)
     {
	 	 tree->right = auxA->left;
		 auxA->left = tree;
		 tree->fb = 0;
		 tree = auxA;
	 }
	 else
     {
		 auxB = auxA->left;
		 auxA->left = auxB->right;
		 auxB->right = auxA;
		 tree->right = auxB->left;
		 auxB->left = tree;

		 if(auxB->fb == -1)
         {
             tree->fb = +1;
         }
		 else
         {
             tree->fb = 0;
         }

		 if(auxB-> fb == +1)
         {
             auxA->fb = -1;
         }
		 else
         {
             auxA->fb = 0;
         }

		 tree = auxB;
	 }

	 return tree;
 }

 NodeAVL* inserir_AVL(NodeAVL* tree, int value, int *grown)
 {
 	 if(tree == NULL)
     {
		 tree = criar(value);

		 *grown = 1;

	 }
	 else if(value < tree->item)
     {
		 tree->left = inserir_AVL(tree->left, value, grown);

		 if(*grown)
         {
			 switch(tree->fb)
			 {
				 case -1: tree->fb = 0; *grown = 0; break;
				 case 0: tree->fb = +1; break;
				 case +1: tree = rotateL_AVL(tree); tree->fb = 0; *grown = 0;
			 }
		 }
	 }
	 else if(value > tree->item)
     {
		 tree->right = inserir_AVL(tree->right, value, grown);

		 if(*grown)
         {
			 switch(tree->fb)
			 {
				 case +1: tree->fb = 0; *grown = 0; break;
				 case 0: tree->fb = -1; break;
				 case -1: tree = rotateR_AVL(tree); tree->fb = 0; *grown = 0;
			 }
		 }
	 }

	 return tree;
 }

 void imprimirPrefix_AVL (NodeAVL* tree)
 {
	if(tree != NULL)
    {
		printf("%i ", tree->item);
		imprimirPrefix_AVL(tree->left);
		imprimirPrefix_AVL(tree->right);
	}
 }

 NodeAVL* bi_to_avl(NodeAVL* treeAVL, NodeBi* treeBi)
 {
     int p1;
	 int *p2;

     p1 = 0;
     p2 = &p1;

	 if(treeBi != NULL)
	 {
		treeAVL = inserir_AVL(treeAVL, treeBi->item, p2);
		treeAVL = bi_to_avl(treeAVL, treeBi->left);
		treeAVL = bi_to_avl(treeAVL, treeBi->right);
	 }

     return treeAVL;
 }

 int main()
 {
     int i, tam, num;
     NodeBi* treeBi = NULL;
     NodeAVL* treeAVL = NULL;

     scanf("%d", &tam);

     for(i=0; i<tam; i++)
     {
         scanf("%d", &num);
         treeBi = inserir_Bi(num, treeBi);
     }

     treeAVL = bi_to_avl(treeAVL, treeBi);
     imprimirPrefix_AVL(treeAVL);

     return 0;
 }
