#include <stdio.h>
#include <stdlib.h>
struct n{
	int data;
	struct n *next;
};

typedef struct n node;

void addFirst(node **root,int data){
	//başa ekler
	node *tmp = (node *) malloc(sizeof(node));
	tmp -> data = data;
	tmp -> next = *root;
	*root = tmp;	
}


void add(node **root,int data){
	//Sıralı ekleme
	if((*root) == NULL){
		node *temp = (node *) malloc(sizeof(node));
		temp -> data = data;
		temp -> next = NULL;
		*root = temp;
		return;
	}
	
	if ((*root) -> data > data){
		node *temp = (node *) malloc(sizeof(node));
		temp -> data = data;
 		temp -> next = *root;
		(*root) = temp;
		return;
	}

	node *iter = *root;
	while(iter->next != NULL && iter->next->data < data)
		iter = iter->next;
	node *temp = (node *) malloc(sizeof(node));
	temp -> data =data;
	temp -> next = iter->next;
	iter -> next = temp;
	return;
	
}

void printNodes(node *root){
	node *iter =root;
	printf("\n\nNodes: ");
	while(iter != NULL){
		printf("%d -> ",iter->data);
		iter = iter -> next;
	}
	printf("NULL");
}

int main(){
	node *root = NULL;
//	addFirst(&root,5);
//	addFirst(&root,1);
//	printf("%d ",root->data);
	add(&root,1);
	add(&root,6);
	add(&root,3);
	add(&root,2);
	add(&root,0);
	printNodes(root);
}
