#include <stdio.h>
#include <stdlib.h>

struct node{
	int root;
	struct node* left;
	struct node* right;
};

void addNode(struct node* node, int val){
	struct node* cur = malloc(sizeof(struct node)); 
	cur->root = val;
	cur->right = NULL;
	cur->left = NULL;
	
	if(val > node->root){
		while(val > node->root && node->right != NULL){	
			node = node->right;
		}
		if(node->root < val){	
			node->right = cur;
		}
	}
	if(val < node->root){
		while(val < node->root && node->left != NULL){
			node = node->left;
		}
		if(node->root > val){
			node->left = cur;
		}else{
			node->right = cur;
		}
	}	
			
	return;
}
void freeNode(struct node* root){
	//free all allocated nodes in the tree	
	if(root->left != NULL){
		freeNode(root->left);
	}
	if(root->right != NULL){
		freeNode(root->right);
	}	
	if(root != NULL){
		free(root);
	}
	return;
}
void printTree(struct node* root, int depth){
	printf("%d ", root->root);	
	if(root->left != NULL){
		printTree(root->left, depth);
	}
	if(root->right != NULL){
		printTree(root->right, depth);
	}
	return;
}
int main(){
	struct node* root = malloc(sizeof(struct node));

	root->root = 9;
	root->left = NULL;
	root->right = NULL;
	addNode(root, 11);
	addNode(root, 13);
	addNode(root, 15);
	addNode(root, 10);
	addNode(root, 8);
	addNode(root, 6);
	addNode(root, 7);
	//addNode(root, 10);
	printTree(root, 0);
	freeNode(root);	
		
	return 0;
}
