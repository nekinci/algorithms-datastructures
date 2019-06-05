#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct n{
    char arr[100];
    int top;
}st;
typedef struct n node;
void push(char data){
    if(data=='('||data==')'){
        st.arr[st.top]=data;
        st.top++;
    }
}
char pop(){
    return st.arr[st.top--];
}

int main(){
    st.top=0;
    printf("Giris yapiniz: ");
    char arr[100];
    scanf("%s",arr);
    int uzunluk=strlen(arr),p1=0,p2=0;
    for(int i=0;i<uzunluk;i++){
        push(arr[i]);
    }
    printf("%d",st.top);
    for(int i=0;i<=uzunluk;i++){
       char a=pop();
       if(a=='(')
        p1++;
       if(a==')')
        p2++;
    }
    if(p1==p2){
        printf("dogru");
    }
    else
        printf("yanlis");
}
