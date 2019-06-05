#include<stdio.h>
#include<stdlib.h>
struct n{
    int data;
    struct n *next;
};
typedef struct n node;

void print(node * );
void append(node *,int );
node * add(node *, int ); //sirali ekleme yapmak icin.
void main(){
    node *root;
    root=NULL;
    root=add(root,400);
    root=add(root,40);
    root=add(root,4);
    root=add(root,450);
    root=add(root,50);
    print(root);
}
void print(node *r){
    while(r!=NULL){
        printf("%d ",r->data);
        r=r->next;
    }
}
void append(node* r, int x){
    while(r->next!=NULL){
     r=r->next;             //bu en son' a data append yapmak icin. pointer i en son' a tasir.
    }
    r->next=(node *) malloc(sizeof(node));
    r->next->data=x;
    r->next->next=NULL;
}
node * add(node* r, int x){
    if(r==NULL){
        r=(node *) malloc(sizeof(node));
        r->next=NULL;
        r->data=x;
        return r;
    }
    if(r->data>x){
        node* temp=(node*) malloc(sizeof(node));
        temp->data=x;
        temp->next=r;
        return temp;
    }
    node *iter=r;
    while(iter->next!=NULL&&iter->next->data<x)
        iter=iter->next;
    node *temp=(node*) malloc(sizeof(node));
    temp->next=iter->next;
    iter->next=temp;
    temp->data=x;
    return r;
}
