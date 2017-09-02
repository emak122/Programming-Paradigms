

#include <stdio.h>
#include <stdlib.h>



struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};



struct Node* newNode(int data){

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->data = data;
	return new_node;
}

void printPreorder(struct Node* root){


	if (root == NULL)
        return;
	
		printf("%d",root->data);
		printPreorder(root->left);
		printPreorder(root->right);
	
}

void printInorder(struct Node* node){

		if (node == NULL)
        return;
	
		printInorder(node->left);
		printf("%d",node->data);
		printInorder(node->right);

}


void printPostorder(struct Node* node){

		if (node == NULL)
        return;
	
		printPostorder(node->left);
		printPostorder(node->right);
		printf("%d",node->data);
}





int main()
{
     struct Node *root  = newNode(1);
     root->left         = newNode(2);
     root->right        = newNode(3);
     root->left->left   = newNode(4);
     root->left->right  = newNode(5); 
 
     printf("\nPreorder traversal of binary tree is \n");
     printPreorder(root);
 
     printf("\nInorder traversal of binary tree is \n");
     printInorder(root);  
 
     printf("\nPostorder traversal of binary tree is \n");
     printPostorder(root);
 
     printf("\n");

     return 0;
}