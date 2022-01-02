#include <stdio.h>
#include <stdlib.h>

struct tNode{

	int data;
	struct tNode* left; 
	struct tNode* right;

};

void traverse(struct tNode* head){
	
		
	if(head == NULL){
		return;
	}	
	printf("%d",head->data);
	if(head->left != NULL){		
		
		traverse(head->left);
	}	
	if(head->right != NULL){

		traverse(head->right);

	}
		
}
void addNode(struct tNode* head, int val){

	struct tnode* new = calloc(1, sizeof(struct tNode));
	new->data = val;

	while(head != NULL){
		if(val > head->data){
			//traverse right 
			head = head->right;
		}

		if(vald < head->data){
			//traverse left
			head = head->left;l
		
		}


	}

}

int main(){
	
	struct tNode* left = calloc(1, sizeof(struct tNode));
	
	left->data = 3;
	left->left = NULL;
	left->right = NULL;	
	
	struct tNode* right = calloc(1, sizeof(struct tNode));
	
	right->data = 7;
	right->left = NULL;
	right->left = NULL;

	struct tNode* head = calloc(1, sizeof(struct tNode));
	
	head->data = 5;
	head->left = left;
	head->right = right;
		
	traverse(head);

	free(head);
	free(left);
	free(right);
}
