#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct node {
	int data;
	int height;
	struct node* lc;
	struct node* rc;
	struct node* parent;
};

struct tree {
	struct node* root;
	int size;
	int height;
};

struct tree* init(int root_val){

	struct node* head = malloc(sizeof(struct node)); 
	head->data = root_val;	
	head->lc = NULL;
	head->rc = NULL;
	head->parent = NULL;

	struct tree* Tree = malloc(sizeof(struct tree));
	Tree->root = head;
	Tree->size = 1;
	Tree->height = 1;
	
	return Tree;
}

struct tree* add(struct tree* Tree, struct node* root,  int val){
	
	struct node* new_node = malloc(sizeof(struct node));
	
	new_node->data = val;
	new_node->lc = NULL;
	new_node->rc = NULL;
	new_node->parent = NULL;

	if(val < root->data && root->lc == NULL){
		//insert left	
		root->lc = new_node;
		new_node->parent = root;
		Tree->size += 1;
	}
	else if(val > root->data && root->rc == NULL){
		//insert right
		root->rc = new_node;
		new_node->parent = root;
		Tree->size += 1;
	}
	else{
		//recursive call
		free(new_node);
		if(val < root->data){
			add(Tree, root->lc, val);
		}
		if(val > root->data){
			add(Tree, root->rc, val);
		}
		
	}
}

void freeNode(struct node* root){
	//printf("%d", root->data);
	if(root->lc != NULL){
		freeNode(root->lc);
	}
	if(root->rc != NULL){
		freeNode(root->rc);
	}
	if(root != NULL){
		free(root);
		return;
	}
}

void printTree(struct tree* Tree, struct node* root){
	if(root->lc != NULL){
		printTree(Tree, root->lc);
	}
	if(root->rc != NULL){
		printTree(Tree, root->rc);
	}
	if(root != NULL){
		printf("%d ", root->data);		
		return;
	}	 
}

int main(){
	
	struct tree* my_tree = init(8);
	struct node* root = my_tree->root;
	
	srand(time(NULL));
	
	while(my_tree->size < 100){
		int r = rand();
		add(my_tree, root, r % 100);
	}
	
	printf("size: %d ", my_tree->size);
	
	printTree(my_tree, my_tree->root);
	freeNode(my_tree->root);	
	free(my_tree);

	return 0;
}
/*
 
How we expect this data structure to work..

	Binary Tree: Left node < Parent Node, Right Node >  Parent Node. 

	AVL/ Balance? 

	Methods & Properties:
		1. init(val): create empty binary tree 
		2. add(val): determines optimal spot to insert the node and inserts it
		3. more to be continued


	Examples:  8			
			 /  \
			4   17
		   /\    /\
		  1  7  13 19
		/  \
     NULL  NULL

	 Free  8
	      / \
		 5  NULL
		/ \
	   3  NULL
	  / \
	NULL NULL
	
Remove:
	



 * */
