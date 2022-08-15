 #include <stdio.h>
 #include <string.h>
 #include <math.h>
 #include <stdlib.h>

 typedef struct Pointer
 {
 	 int item;
 	 int fb;
	 struct Pointer *left;
	 struct Pointer *right;

 }Node;

 Node* criar(int item)
 {
 	 Node* tree = (Node*) malloc(sizeof(Node));

 	 tree->item = item;
	 tree->left = NULL;
	 tree->right = NULL;

	 return tree;
 }

 static Node* rotateL(Node *tree)
 {
     Node *auxA = tree->left, *auxB;

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

 static Node* rotateR(Node *tree)
 {
 	 Node *auxA = tree->right, *auxB;

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

 Node* inserir(Node* tree, int value, int *grown)
 {
 	 if(tree == NULL)
     {
		 tree = criar(value);

		 *grown = 1;

	 }
	 else if(value < tree->item)
     {
		 tree->left = inserir(tree->left, value, grown);

		 if(*grown)
         {
			 switch(tree->fb)
			 {
				 case -1: tree->fb = 0; *grown = 0; break;
				 case 0: tree->fb = +1; break;
				 case +1: tree = rotateL(tree); tree->fb = 0; *grown = 0;
			 }
		 }
	 }
	 else if(value > tree->item)
     {
		 tree->right = inserir(tree->right, value, grown);

		 if(*grown)
         {
			 switch(tree->fb)
			 {
				 case +1: tree->fb = 0; *grown = 0; break;
				 case 0: tree->fb = -1; break;
				 case -1: tree = rotateR(tree); tree->fb = 0; *grown = 0;
			 }
		 }
	 }

	 return tree;
 }

 int somaFatores(Node* tree)
 {
     Node* treeB = tree;
     int soma = 0;

     if(treeB != NULL)
     {
         soma = treeB->fb;
         soma = soma + somaFatores(treeB->left);
         soma = soma + somaFatores(treeB->right);
     }

     return soma;
 }


 int main()
 {
     int i, nos, num, p1, soma;
     int* p2;
     Node* avrL = NULL;

     scanf("%d", &nos);

     p1 = 0;
     p2 = &p1;

     for(i=0; i<nos; i++)
     {
         scanf("%d", &num);
         avrL = inserir(avrL, num, p2);
     }

     soma = somaFatores(avrL);

     printf("%d", soma);

     return 0;
 }
