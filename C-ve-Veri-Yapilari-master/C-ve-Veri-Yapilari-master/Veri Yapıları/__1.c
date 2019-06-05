#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct rehber{
    char ilkHarf;
    struct kayit *kayitPtr;
};
struct kayit{
    char ad[50];
    char soyad[50];
    int telNo;
    struct kayit *next;
};
void kayitEkle(struct rehber *r){
    char ad[50],soyad[50];
    int telNo;
    printf("Ad girin: ");
    scanf("%s ",&ad);
    fflush(stdin);
    printf("Soyad girin: ");
    fflush(stdin);
    scanf("%s ",&soyad);
    printf("Tel No girin: ");
    scanf("%d ",&telNo);
    char c='a';
    int i=0;
    for(c='a';c<ad[0];c++){
        i++;

    }
        perror("geçti");
    if(r[i].kayitPtr==NULL){
        (r+i)->kayitPtr=(struct kayit*) malloc(sizeof(struct kayit));
        (r+i)->kayitPtr->next = NULL;
        strcpy((r+i)->kayitPtr->ad,ad);
        strcpy((r+i)->kayitPtr->soyad,soyad);
        (r+i)->kayitPtr->telNo = i;
    }

}
int main(){
    struct rehber *r=(struct rehber*) malloc(sizeof(struct rehber)*26);
    int i=0;
    char c;
    for(c='a';c<='z';c++,i++){
        (r+i)->ilkHarf=c;
        (r+i)->kayitPtr=NULL;
    }
    for(i=0;i<26;i++){
        printf("%c ",r[i].ilkHarf); //testing
    }
    kayitEkle(r);
    printf("\n%d %s %s",r[2].kayitPtr->telNo,r[2].kayitPtr->ad,r[2].kayitPtr->soyad);

}
