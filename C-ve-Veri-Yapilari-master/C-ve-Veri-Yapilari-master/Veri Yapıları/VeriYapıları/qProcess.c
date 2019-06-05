#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct n{
    char data[5];
    struct n *next;
};
typedef struct n node;
node *r=NULL;

void enque(char data[5]){
    if(r==NULL){
        r=(node*) malloc(sizeof(node));
        strcpy(r->data,data);
        r->next=NULL;
        return;
    }
    node *tmp=(node*) malloc(sizeof(node));
    node *iter=r;
    while(iter->next!=NULL)
        iter=iter->next;
    strcpy(tmp->data,data);
    iter->next=tmp;
    tmp->next=NULL;
}
char *deque(){
    if(r==NULL)
        return "BOS!";
    node *temp=r;
    char tmp[5];
    strcpy(tmp,r->data);
    r=r->next;
    //free(temp);
    return tmp;
}
void main(){
    enque("P0");
    enque("P2");
    enque("P90");
    enque("P100");
    printf("%s ",deque());
    printf("%s ",deque());
    printf("%s ",deque());
    printf("%s ",deque());
    //printf("%s ",deque());
}
