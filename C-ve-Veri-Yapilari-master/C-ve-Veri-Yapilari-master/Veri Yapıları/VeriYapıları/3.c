#include<stdio.h>
#include<stdlib.h>

struct n{
    int data;
    struct n *next;
};

typedef struct n node;

void println(node*);
void append(node*,int);
node* add(node*,int);
node *removeNode(node *r,int data);
void main(){
    node *r=(node*) malloc(sizeof(node));
    node *r1;
    r1=NULL;
    r->data=1;
    r->next=r;
    append(r,5);
    append(r,15);
    append(r,52);
    append(r,523);
    println(r);
    printf("\n");
    r1=add(r1,4);
    r1=add(r1,40);
    r1=add(r1,42);
    r1=add(r1,45);
    r1=add(r1,22);
    r1=add(r1,2);
    r1=add(r1,23);
    r1=add(r1,234);
    r1=add(r1,46);
    r1=removeNode(r1,22);
    r1=removeNode(r1,42);
    println(r1);
}
void println(node *r){
    node *iter=r;
    printf("%d ",iter->data);
    iter=iter->next;
    while(iter!=r){
        printf("%d ",iter->data);
        iter=iter->next;
    }
}
void append(node *r,int data){
    node*iter=r;
    while(iter->next!=r){
        iter=iter->next;
    }
    iter->next=(node*) malloc(sizeof(node));
    iter->next->data=data;
    iter->next->next=r;
}
node * add(node *r,int data){
    if(r==NULL){
        r=(node*) malloc(sizeof(node));
        r->data=data;
        r->next=r;
        return r;
    }
    if(r->data>=data){
        node *temp=(node*) malloc(sizeof(node));
        temp->data=data;
        temp->next=r;
        node *iter=r;
        while(iter->next!=r){
            iter=iter->next;
        }
        iter->next=temp;
        return temp;
    }
    node *iter=r;
    while(iter->next->data < data&&iter->next!=r){
        iter=iter->next;
    }
    node *temp=(node*) malloc(sizeof(node));
    temp->data=data;
    temp->next=iter->next;
    iter->next=temp;
    return r;
}
node *removeNode(node *r,int data){
    node *temp;
    node *iter=r;
    if(r->data==data){
        while(iter->next!=r){
            iter=iter->next;
        }
        temp=iter->next;
        iter->next=iter->next->next;
        free(temp);
        return iter->next;
    }
    while(iter->next!=r&&iter->next->data!=data){
        iter=iter->next;
    }
    if(iter->next==r){
        printf("Sayi Bulunamadi");
        return r;
    }
    temp=iter->next;
    iter->next=iter->next->next;
    free(temp);
    return r;

}
