#include<stdio.h>
#include<stdlib.h>

struct n{
    int data;
    struct n *next;
};
typedef struct n node;

node * enque(node *r,int a){
    if(r==NULL){
        r=(node*) malloc(sizeof(node));
        r->data=a;
        r->next=NULL;
        return r;
    }
    node *tmp=(node*) malloc(sizeof(node));
    tmp->data=a;
    tmp->next=r;
    return tmp;
}
int deque(node *r){
    node *iter=r;
    if(r==NULL){
        printf("Bos! ");
        return -1;
    }
    if(iter->next==NULL){
        int rValue=iter->data;
        free (iter);
        return rValue;
    }
    while(iter->next->next!=NULL)
        iter=iter->next;
    node *tmp=iter->next;
    int rValue=iter->next->data;
    free(tmp);
    iter->next=NULL;
    return rValue;
}

int main(){
    node *r=NULL;
    r=enque(r,5);
    r=enque(r,10);
    r=enque(r,15);
    r=enque(r,20);
    r=enque(r,25);
    r=enque(r,30);
    printf("%d ",deque(r));
    printf("%d ",deque(r));
    printf("%d ",deque(r));
    printf("%d ",deque(r));
    printf("%d ",deque(r));
    printf("%d ",deque(r));

}
