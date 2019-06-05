#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct n{
    char data[5];
    struct n *next;
};
typedef struct n node;
node *calisan=NULL;
void enque(node *r,char data[5]){
    if(r==NULL){
        r=(node*) malloc(sizeof(node));
        strcpy(r->data,data);
        r->next=NULL;
        return;
    }
    node *tmp,*iter=r;
    while(iter->next!=NULL)
        iter=iter->next;
    tmp=(node*) malloc(sizeof(node));
    strcpy(tmp->data,data);
    tmp->next=NULL;
    iter->next=tmp;
}
char * deque(node *r){
    if(r==NULL)
        return "NULL";
    node *tmp=r;
    r=r->next;;
    return tmp->data;
}
void killProcess(char x[5]){

}
int main(){
    enque(calisan,"P5");
    enque(calisan,"P6");
    enque(calisan,"P7");
    printf("%s ",calisan->data);
    printf("%s ",deque(calisan));
    printf("%s ",deque(calisan));
    printf("%s ",deque(calisan));
}
