/*

    Isim: Niyazi Ekinci NO: 160204044 Ders: BLG 201_Odev_1
        DONEM I.ODEVi
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct kayit{
    char ad[50];
    char soyad[50];
    int telNo;
    struct kayit *next;
};
typedef struct kayit node; //typedef ile kolay okunsun diye node isminde tanimladik.
struct rehber {
    char ilkHarf;
    node *kayitPtr;
};
typedef struct rehber rehber; //typedef ile tip tanimladik.
/**/
rehber r[26]; //global rehber dizisi
/**/
//prototip tanimlari.
void ilklendir();
void kayitEkle();
void rehberiYazdir();
void kisiSil();
int Ara();
void Sirala();
void swapp(node*,node*);


void main(){
    ilklendir();
    int secim=0;
    do{
        printf("\n1->Kayit Ekle: \n2->Kayit Ara: \n3->Kayit Sil: \n4->Ada Gore Sirala: \n5->Soyada Gore Sirala: \n6->Rehberi yazdır: \n7->Cikis : \nNOT:Telefon numarası eklerken '05' yazmadan ekleyin.\n");
        scanf("%d",&secim);
        //system("clear"); //konsol ekraninin temizlenmesi icin yapilmasi gereken. istege gore yapilabilir.
        switch(secim){
            case 1:kayitEkle();break;
            case 2:printf("\n-----(%d de bulundu.)------\n",Ara());break;
            case 3:kisiSil();break;
            case 4:Sirala(1);break; //1se ad
            case 5:Sirala(0);break; //0 sa soyada gore siralar;
            case 6:rehberiYazdir();break;
            default:printf("Cikiliyor...\n\n\n\n\n\n\n");
        }

    }while(secim<7);
}

void kayitEkle(){
    char ad[50],soyad[50],c;
    int telNo,i=-1;
    printf("[ad][soyad][telno] seklinde giriniz: ");
    scanf("%s%s%d",ad,soyad,&telNo);
    for(c='a';c<=ad[0];c++) //adin ilk harfine gore rehber dizisine ekleme yapacak.i yi ona gore arttiriyoruz.
        i++;
    if(i>=0&&i<26){
        if(r[i].kayitPtr==NULL){ //eger hic eleman yoksa yer ayirip ilk elemani atiyoruz.
            r[i].kayitPtr=(node*) malloc(sizeof(node));
            strcpy(r[i].kayitPtr->ad,ad);
            strcpy(r[i].kayitPtr->soyad,soyad);
            r[i].kayitPtr->telNo=telNo;
            r[i].kayitPtr->next=NULL;
            return;
        }
        if(strcmp(r[i].kayitPtr->ad,ad)>0){ //ekleyecegimiz eleman ilk elemandan kucukse
            node *temp=(node*) malloc(sizeof(node)); //gecici degisken tanimlayip onun nextine kayitPtri isaret ediyoruz.
            strcpy(temp->ad,ad);
            strcpy(temp->soyad,soyad);
            temp->telNo=telNo;
            temp->next=r[i].kayitPtr;
            r[i].kayitPtr=temp;
            return;
        } //araya ekleme islemi
        node *iter=r[i].kayitPtr;
        while(iter->next!=NULL&&strcmp(r[i].kayitPtr->next->ad,ad)<0&&strcmp(r[i].kayitPtr->next->soyad,soyad))
            iter=iter->next;
        node *temp=(node*) malloc(sizeof(node));
        temp->next=iter->next;
        iter->next=temp;
        strcpy(temp->ad,ad);
        strcpy(temp->soyad,soyad);
        temp->telNo=telNo;
        return;
}
    else
        printf("Gecersiz karakter!");
}
void rehberiYazdir(){
    int i=0;
    char c;
    node *iter;
    for(c='a';c<='z';c++,i++){
        printf("%c\n------------------\n",c);
        iter=r[i].kayitPtr;
        while(iter!=NULL){
            printf("%s\t%s\t05%d\n",iter->ad,iter->soyad,iter->telNo);
            iter=iter->next;
        }
        printf("\n");
    }
}
void ilklendir(){
    char c;int i=0;
    for(c='a';c<='z';c++,i++){
        r[i].ilkHarf=c;
        r[i].kayitPtr=NULL;
    }
}
void kisiSil(){
    char ad[50],soyad[50],c;
    int i=-1;
    printf("[ad][soyad] seklinde silinecek ismi girin: ");scanf("%s%s",ad,soyad);
    for(c='a';c<=ad[0];c++) //ismin ilk harfine gore i yi arttirdik
        i++;
    node *iter=r[i].kayitPtr; //iterasyonu kayitPtr ina esitledik.
    if(i>=0&&i<26){
        if(iter!=NULL&&strcmp(iter->ad,ad)==0&&strcmp(iter->soyad,soyad)==0){ //silmek istedigimiz eleman ilk basta ise
            node *temp=iter;
            iter=iter->next;  //iteri bir ilerletiyoruz.
            free (temp);
            r[i].kayitPtr=iter; // ve listemizi tekrar itere esitliyoruz.
            return;
        }
        while(iter->next!=NULL&&strcmp(iter->next->ad,ad)!=0&&strcmp(iter->next->soyad,soyad)!=0)
            iter=iter->next; //ismi bulana kadar iterasyonu ilerletiyoruz.
        if(iter->next==NULL){ //eger NULL'a gelmissek bulunamamistir.
            printf("Bulunamadi!");return;
        }
        node *temp=iter->next; //else : silecegimiz elemandan bir onceki elemanda durduk
        iter->next=iter->next->next; // bu elemanin sonrakisi olan elemanin baglantisini listeden kopardik. yani
        free(temp);                 //silmis olduk.
        return;
    }
    else{
        printf("Gecersiz karakter!");
    }
}
void Sirala(int soyad_mi){
    int i,k;
    for(k=0;k<26;k++){
    node *iter=r[k].kayitPtr,*temp;
    for(i=0;iter!=NULL;i++){
        temp=r[k].kayitPtr;
        while(temp->next!=NULL){
            if(soyad_mi==0&&strcmp(temp->soyad,temp->next->soyad)>0) //fonksiyona verilen soyad_mi degiskeni eger 0sa soyad
                swapp(temp,temp->next);                              //eger 1se isime gore siralama yapiyor.
            if(soyad_mi==1&&strcmp(temp->ad,temp->next->ad)>0)
                swapp(temp,temp->next); //swapping yapiyor.
            temp=temp->next;
        }
        iter=iter->next;
    }
    }
}
int Ara(){
    char ad[50],soyad[50],c;int i=-1,loc=0;
    printf("Aramak istediginiz ad ve soyad:-> "); // aramak istenilen ad ve soyadi girince ilk once adin ilk harfine baktik.
    scanf("%s%s",ad,soyad); // eger adin ilk harfi alfabeye uygunsa i degiskenini ona gore arttiriyoruz.
    for(c='a';c<=ad[0];c++)
        i++;
    node *iter=r[i].kayitPtr; //a ise 0 b ise 1 c ise 2 gibi...
    if(i>=0&&i<26){ //i a ile z arasinda olmalı yani 0 ve 26 arasinda..
        for(loc=0;iter!=NULL;loc++){ //lokasyon ilk olarak 0da tanimli iterator pointerimiz NULL olana kadar donmek icin programlandi.
            if(strcmp(iter->ad,ad)==0) //eger aradigimiz degeri bulursak o anki lokasyonu donduruyoruz.
                return loc;
            iter=iter->next; //bulana kadar iterasyon pointerimizi ilerletiyoruz.
        }
        return -1; //bulamazsak -1 donuyor.
    }
    else{
        printf("Gecersiz karakter!");
    }
}
void swapp(node *a,node *b){
    //bu fonksiyon yer degistirme islemi yapar.
    char ad[50],soyad[50]; //ad ve soyadi tanimladik
    int telNo; //telefon numarasini tanimladik. temp olarak bu degiskenlerde tutacak.

    strcpy(ad,a->ad); //ad tempine a->ad i kopyaladık.aynı islemler asagidakiler icinde gecerli.
    strcpy(soyad,a->soyad);
    telNo=a->telNo;

    strcpy(a->ad,b->ad);
    strcpy(a->soyad,b->soyad);
    a->telNo=b->telNo;

    strcpy(b->ad,ad);
    strcpy(b->soyad,soyad);
    b->telNo=telNo;
}
