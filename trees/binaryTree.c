#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define COUNT 5

struct node{
	int root;
	struct node* left;
	struct node* right;
};

void addNode(struct node* node, int val){
	
	//base case	 1
	if(node->left == NULL && val < node->root){
		//insert
		struct node* cur = malloc(sizeof(struct node));
		cur->root = val;	
		cur->left = NULL;
		cur->right = NULL;
		node->left = cur;	
	}
	// base case 2
	if(node->right == NULL && val > node->root){
		//insert	
		struct node* cur = malloc(sizeof(struct node));
		cur->root = val;	
		cur->left = NULL;
		cur->right = NULL;
		node->right = cur;	
	}
	if(val > node->root){
		//traverse right
		addNode(node->right, val);
	}
	else if(val < node->root){
		//traverse left
		addNode(node->left, val);
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
void search(struct node* node, int val){
	
}
void delete(struct node* r_node, struct node* d_node){
	search	
	return;

}
void getHeight(struct node* node, int* left, int* right){
	if(node->left != NULL){
		getHeight(node->left, left, right);
	}
	if(node->right != NULL){
		getHeight(node->right, left, right);
	}	
	return;
}

void printTree(struct node* root, int space){
	//stolen from the internet.. 
	if(root == NULL){
		return;
	}
	space += COUNT;
	printTree(root->right, space);
	printf("\n");
	for(int i = COUNT; i<space; i++){
		printf(" ");
	}
	printf("%d\n", root->root);
	printTree(root->left, space);

}

int main(){
	struct node* root = malloc(sizeof(struct node));

	root->root = 10;
	root->left = NULL;
	root->right = NULL;
	
	addNode(root, 5);
	addNode(root, 13);
	addNode(root, 1);
	addNode(root, 7);
	addNode(root, 16);
	addNode(root, 11);
	
	printTree(root, 0);
	freeNode(root);	
		
	return 0;
}
