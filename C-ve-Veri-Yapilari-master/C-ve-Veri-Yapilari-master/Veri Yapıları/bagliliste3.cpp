#include<stdio.h>

#include<stdlib.h>
struct n{
	int data;
	struct n *next;
};
typedef struct n node;
int main(){


	node * root=(node*) malloc(sizeof(node));
	root->data=10;
	root->next=(node*) malloc(sizeof(node));
	root->next->data=20;
	root->next->next=(node*) malloc(sizeof(node));
	root->next->next->data=30;
	root->next->next->next=NULL;
	while(root!=NULL){
		printf("%d",root->data);
		root=root->next;
	}
	return 0;
} 




