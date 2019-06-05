/*
Niyazi Ekinci
160204044
Veri Sifreleme ve Hata Ayiklama
***Yorumlari daha iyi goruntuleyebilmek icin yorum rengini degistirin.***
*/

#include<stdio.h>

int yanlis_mi=0; //kullanici islem kodunu yanlis girerse yeniden sormak icin.
int e_yanlis_mi=0; // Eslik kurali belirtilirken yanlislik yapilirsa tekrardan sormak icin.
unsigned int sonuc; //Programin her fonksiyonunda kullanabilmek icin.


void sifrele(unsigned int,char,unsigned int); //prototip tanimlari**
void bitleriGoster(unsigned int);
void eslik_Kurali(char);
int main()
{
    /* Do while dongusune girmemizin nedeni kullanici yanlis islem kodu girdiginde tekrar girmesini saglamak.
	   Kullanicidan sayi islem ve anahtar degiskenlerini alttaki kodlarda aldik.
       Ardindan _sifrele(unsigned,char,unsigned)_ fonksiyonuyla belirtilen islemlere gore sifreledik.
       Ekrana yazdirdiktan sonra Kullanicidan eslik kuralini istedik. T veya C ye gore kullanici girisini yapacak.
       Daha sonra _eslik_Kurali(unsigned)_ fonksiyonuyla T veya C ye gore isleme girecek ve ekrana yazdiracak.
       En son asamada ise _bitleriGoster(unsigned)_ fonksiyonuylada bitleri ekranda gosterecek.
    */
    unsigned int sayi,anahtar;
    char islemKodu,eslikKurali;
    do
    {
    printf("[Sayi][Islem][Anahtar] biciminde giriniz: \n");
    scanf("%u",&sayi);
    scanf("%c",&islemKodu);
    scanf("%u",&anahtar);
    printf("*********************************************\n");
    yanlis_mi=0;
    sifrele(sayi,islemKodu,anahtar);


    }while(yanlis_mi==1);
    printf("Sifrelenmis veri: %u\n",sonuc);
    do
    {
        printf("Eslik kuralini belirtiniz: ");
        fflush(stdin); //Karakter girerken ortaya cikabilecek sorunlari yok etmek icin.
        scanf("%c",&eslikKurali);
        e_yanlis_mi=0;
        printf("*********************************************\n");
        eslik_Kurali(eslikKurali);
    }while(e_yanlis_mi==1);


    bitleriGoster(sonuc);
    printf("\n*********************************************\n");
    printf("*********************************************\n");
    system("pause"); // Exe dosyasinda ekranda kalmasi icin.


}
void sifrele(unsigned int a, char c, unsigned int b)
{
    /*
    Sifrele fonksiyonu ekranda girilen isleme gore islemi yapýp global sonuc degerine atar.
    Eger yanlis islem kodu girilirse uyari verir ardindan yanlis_mi degiskenine 1 degerini atar ve main
    fonksiyonundaki dongu icin kullanilir.
    */
    switch(c)
    {
        case '&': sonuc=a&b; break;
        case '|': sonuc=a|b; break;
        case '^': sonuc=a^b; break;
        case '>': sonuc=a>>b;break;
        case '<': sonuc=a<<b; break;
        default: Yeniden:; printf("Yanlis islem kodu\n"); yanlis_mi=1; break;
    }

}
void eslik_Kurali(char e)
{
    /*
    Bu fonksiyonda ise eger c girilirse sonucu bir sola kaydirip ekrana yazdirir.
    Eger T girilirse sonucu 1 sola kaydirip yeni sonuc 1 ile veya islemine girer.
    yani 1 eklemis olur.
    T,t veya C,c disinda bir karakter girilmesi durumunda uyarý verir ve e_yanlis_mi degiskenine 1 atar. Main
    fonksiyonunda tekrar sorma dongusu icin gereklidir.
    */

    if(e=='C'||e=='c')
    {
        sonuc<<=1;
        printf("Sonuc: %u \n",sonuc);
    }
    else if(e=='T'||e=='t')
    {
        sonuc<<=1;
        sonuc=sonuc|1; //Cift olan sayilarda 1 ile OR islemine girilirse  sayiya 1 ekler.
        printf("Sonuc: %u \n",sonuc);
    }
    else
    {
        printf("Yanlis karakter girdiniz.\n");
        e_yanlis_mi=1;
    }

}
void bitleriGoster(unsigned int d)
{/*
    Bu fonksiyonda onluk tabanda olan sayiyi ikilik tabanda gosterdik.
    maske degiskenini ilk olarak 1 le baslattik sonra bu sayiyi sonuc degiskeninden
    kucuk veya esit olana kadar sola kaydirdik. Cunku en soldan baslayip bitleri yazdirmak icin.
    Daha sonra maskeyi 1 den buyuk veya esit olana kadar saga kaydirdik ki sayinin butun bitlerini ogrenelim.
    her dongude t degiskeni eger 0 sa ekrana 0 yazdiracak degilse 1 yazdiracak.
   */
    unsigned int maske=1,t;
    while(maske<=d)
    {
        maske=maske<<1;
    }
    maske>>=1; // basa fazladan 0 koymamasi icin yaptim ama kullanilmasada olurdu.kullanilmasaydi en solda basta 0 olurdu.
    //odev formatinda 0 olmadigi icin bu sekilde yaptim.
    printf("Bit olarak sonuc: ");
    while(maske>=1)
    {
        t=d&maske;
        maske=maske>>1;
        if(t!=0)
            printf("1");
        else
            {printf("0");}
    }

}
