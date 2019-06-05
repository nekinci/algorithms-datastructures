#include<stdio.h>
#include<stdlib.h>

struct n{
    int data;
    struct n *next;
};
typedef struct n node;
node *root=NULL;
struct liste{
    node *bas;
    node *son;
};
typedef struct liste Liste;
void add(Liste l){
    if(root==NULL){
        root=(node*) malloc(sizeof(node));
        root->data=data;
        root->next=NULL;
        return;
    }
    node *temp=(node*) malloc(sizeof(node));
    temp->data=data;
    temp->next=root;
    root=temp;
}
int main(){
    l->bas=root;
    node *iter=root;
    while(iter->next!=NULL)
        iter=iter->next;
    l->son=iter;

}
