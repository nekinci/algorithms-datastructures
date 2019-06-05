#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct rehber{
    char ilkHarf;
    struct kayit *kayitPtr;
};
struct rehber r[26];
struct kayit{
    char ad[50];
    char soyad[50];
    unsigned long telNo;
    struct kayit *next;
};
struct kayit* kayitEkle(struct rehber r[26]){
    char ad[50],soyad[50],c;
    int telNo,i=-1;
    printf("[Ad] [Soyad] [TelNO] seklinde girisinizi yapiniz: ");
    scanf("%s",ad);
    scanf("%s",soyad);
    scanf("%d",&telNo);
    for(c='a';c<=ad[0];c++)
        i++;
    printf("\n");
    if(i>=0 && i<26){
        if(r[i].kayitPtr==NULL){
            r[i].kayitPtr=(struct kayit*) malloc(sizeof(struct kayit));
            strcpy(r[i].kayitPtr->ad,ad);
            strcpy(r[i].kayitPtr->soyad,soyad);
            r[i].kayitPtr->telNo=telNo;
            r[i].kayitPtr->next=NULL;
            return r[i].kayitPtr;
        }
        if(strcmp(r[i].kayitPtr->ad,ad)>0){
            struct kayit *temp=(struct kayit*) malloc(sizeof(struct kayit));
            strcpy(temp->ad,ad);
            strcpy(temp->soyad,soyad);
            temp->telNo=telNo;
            temp->next=r[i].kayitPtr;
            return temp;
        }
        struct kayit *iter=r[i].kayitPtr;
        while(iter->next!=NULL&&strcmp(iter->next->ad,ad)<0){
            iter=iter->next;
        }
        struct kayit *temp=(struct kayit*) malloc(sizeof(struct kayit));
        strcpy(temp->ad,ad);
        strcpy(temp->soyad,soyad);
        temp->telNo=telNo;
        temp->next=iter->next;
        iter->next=temp;
        return r[i].kayitPtr;
    }
    else{
        printf("Geçersiz karakter!");
        //Buraya gecersiz kayit yapınca bos olan kaydi silmek icin müdahele edilecek.UNUTMA
    }
}
void rehberiYazdir(struct rehber r[26]){
    char c='a';
    int i=0;
    struct kayit *iter;
    for(char c='a';c<='z';c++,i++){
        printf("%c\n-------------------\n",c);
        iter=r[i].kayitPtr;
        while(iter!=NULL){
            printf("Ad: %s \tSoyad: %s\t Telefon No: %lu\n",iter->ad,iter->soyad,iter->telNo);
            iter=iter->next;
        }
        printf("\n");
    }
}
void sil(){
    char ad[50];
    char soyad[50];
    puts("Silmek istediginiz isim ve soyisim->: ");
    scanf("%s",ad);
    scanf("%s",soyad);
    int i=-1;
    char c;
    for(c='a';c<=ad[0];c++)
        i++;
    struct kayit *iter=r[i].kayitPtr;
    if(strcmp(iter->ad,ad)==0&&strcmp(iter->soyad,soyad)==0){
        struct kayit *temp=iter;
        iter=iter->next;
        free(temp);
        return iter;
    }
    while(iter->next!=NULL&&strcmp(iter->next->ad,ad)!=0&&strcmp(iter->next->soyad,soyad)!=0){
            iter=iter->next;
    }
    if(iter!=NULL){
        printf("Bulunamadi");
        return NULL;
    }
    struct kayit *temp=iter->next;
    iter->next=iter->next->next;
    free(temp);
    return iter;

}
int main(){
    char c;int i=0;
    for(c='a';c<='z';c++,i++){
        r[i].ilkHarf=c;
        r[i].kayitPtr=NULL;
    }

}
