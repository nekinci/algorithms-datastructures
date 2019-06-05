#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct n{
    char data[5];
    int oncelik;
    struct n *next;
};
typedef struct n node;
node *calisan=NULL;
node * enque(node *r,char data[5]){
    if(r==NULL){
        r=(node*) malloc(sizeof(node));
        strcpy(r->data,data);
        r->next=NULL;
        return r;
    }
    node *iter=r;
    while(iter->next!=NULL)
        iter=iter->next;
    iter->next=(node *) malloc(sizeof(node));
    strcpy(iter->next->data,data);
    iter->next->next=NULL;
    return r;
}
char * deque(node *r){
    if(r==NULL)
        return "BOS!";
    node *temp=r;
    char tmp[5];
    strcpy(tmp,r->data);
    r=r->next;
    //free(temp);
    return temp->data;
}
void main(){
    calisan=enque(calisan,"P5");
    calisan=enque(calisan,"P15");
    calisan=enque(calisan,"P25");
    printf("%s ",deque(calisan));
    printf("%s ",deque(calisan));
    printf("%s ",deque(calisan));
}
