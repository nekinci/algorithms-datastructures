#include<stdio.h>
#include<stdlib.h>
#include "stack_ll.h"

int rValue;
int pop(node *root){
    if(root==NULL){
        printf("Stack Bos!");
        return -1;
    }
    node *iter=root;
    if(iter->next==NULL){
        node *temp=iter;
        iter=NULL;
        free(iter);
        free(root);
        return temp->data;
    }
    while(iter->next->next!=NULL)
        iter=iter->next;
    node *temp=iter->next;
    iter->next=NULL;
    free(iter->next);
    return temp->data;
}
node* push(node *root,int data){
    if(root==NULL){
        root=(node*) malloc(sizeof(node));
        root->data=data;
        root->next=NULL;
        return root;
    }
    node *iter=root;
    while(iter->next!=NULL){
        iter=iter->next;
    }
    node *temp=(node* ) malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    iter->next=temp;
    return root;
}
void bastir(node *r){
    while(r!=NULL)
    {
        printf("%d ",r->data);
        r=r->next;

    }
}
node *pushOne(node *r,int data){
    if(r==NULL){
        r=(node*) malloc(sizeof(node));
        r->data=data;
        r->next=NULL;
        return r;
    }
    node *temp=(node*) malloc(sizeof(node));
    temp->data=data;
    temp->next=r;
    return temp;
}
node* popOne(node *r){

    if(r==NULL){
        printf("Cekilecek eleman kalmadi!");
        return -1;
    }
    if(r->next==NULL){
        rValue=r->data;
        //free(r);
        return rValue;
    }
    rValue=r->data;
    r=r->next;
    return r;
}

