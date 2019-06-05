#include<stdio.h>
#include<stdlib.h>

struct n{
    int data;
    struct n *next;
};

typedef struct n node;
node *removeNode(node *r,int data){
    node *temp;
    node *iter=r;
    if(r->data==data){
        temp=r;
        r=r->next;
        free(temp);
        return r;
    }
    while(iter->next!=NULL&&iter->next->data!=data){
        iter=iter->next;
    }
    if(iter->next==NULL){
        printf("Sayi Bulunamadi");
        return r;
    }
    temp=iter->next;
    iter->next=iter->next->next;
    free(temp);
    return r;

}
node * add(node*r,int data){
    if(r==NULL){
        r=(node*) malloc(sizeof(node));
        r->data=data;
        r->next=NULL;
        return r;
    }
    if(r->data>data){
        node *tmp=(node*) malloc(sizeof(node));
        tmp->data=data;
        tmp->next=r;
        return tmp;
    }
    node *iter=r;
    while(iter->next!=NULL&&iter->next->data < data){
        iter=iter->next;
    }
    node *temp=(node*) malloc(sizeof(node));
    temp->next=iter->next;
    iter->next=temp;
    return r;

}
void printNode(node *r){
    while(r!=NULL){
        printf("%d\t",r->data);
        r=r->next;
    }
}

void main(){
    node *r=NULL;
    int i=10;
    for(int i=10;i>0;i--){
        r=add(r,i*10);
    }
    r=removeNode(r,50);
    printNode(r);
}
