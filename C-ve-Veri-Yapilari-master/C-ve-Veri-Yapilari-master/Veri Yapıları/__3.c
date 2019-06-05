#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
void kayitEkle(struct rehber r[26]){
    char ad[50],soyad[50],c;
    int telNo,i=-1;
    printf("ad: ");
    scanf("%s",ad);
    scanf("%s",soyad);
    printf("telNO: ");
    scanf("%d",&telNo);
    for(c='a';c<=ad[0];c++)
        i++;
    if(i>=0 && i<26){
        if(r[i].kayitPtr==NULL){
            r[i].kayitPtr = (struct kayit*) malloc(sizeof(struct kayit));
            strcpy(r[i].kayitPtr->ad,ad);
            strcpy(r[i].kayitPtr->soyad,soyad);
            r[i].kayitPtr->telNo=telNo;
            r[i].kayitPtr->next = NULL;
        }
        int stringKontrol; //0dan büyük dönerse ilk büyük 0dan küçük dönerse ikinci büyük
        else if(strcmp(r[i].kayitPtr->ad,ad)>0){
            struct kayit* tmp=(struct kayit*) malloc(sizeof(struct kayit));
            strcpy(tmp->ad,ad);
            strcpy(tmp->soyad,soyad);
            tmp->telNo=telNo;
            tmp->next=r[i].kayitPtr;
        }
        else{
        struct kayit *iter=r[i].kayitPtr;
        while(iter->next!=NULL&&strcpy(iter->next->ad,ad)<0){
            iter=iter->next;
        }
        struct kayit *tmp=(struct kayit*) malloc(sizeof(struct kayit));
        strcpy(tmp->ad,ad);
        strcpy(tmp->soyad,soyad);
        tmp->telNo=telNo;
        tmp->next=iter->next;
        iter->next=tmp;
        }
    }
    else
        printf("Geçersiz karakter!");
}
void rehberiYazdir(struct rehber r[26]){
    char c='a';
    int i=0;
    struct kayit *iter;
    for(char c='a';c<='z';c++,i++){
        printf("%c\n-------------------\n",c);
        iter=r[i].kayitPtr;
        while(iter!=NULL){
            printf("Ad: %s\tSoyad: %s\t Telefon No: %d\n",iter->ad,iter->soyad,iter->telNo);
            iter=iter->next;
        }
        printf("\n");
    }
}
int main(){
    struct rehber r[26];
    char c;int i=0;
    for(c='a';c<='z';c++,i++){
        r[i].ilkHarf=c;
        r[i].kayitPtr=NULL;

    }
    kayitEkle(r);
    kayitEkle(r);
    rehberiYazdir(r);
    printf("\n%s ",r[0].kayitPtr->ad);
    printf("\n%s ",r[0].kayitPtr->next->ad);
}
