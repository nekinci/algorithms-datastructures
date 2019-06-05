#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#ifdef _WIN32 //windows icin
#define CLEAR "cls"
#else //diger isletim sistemleri icin
#define CLEAR "clear"                       //hem linux hemde windowsta ekranı temizleyebilmek icin.
#endif // _WIN32

#define BOYUT 8

typedef struct{
    int etki;
    char tip;
    int yapildi_mi;
}patlayici;

int skor=10;
int acilan_alan=0;
void skor_guncelle(patlayici* a);
void ilklendir(patlayici d[][BOYUT]);
void hamle_yap(int satir, int sutun, patlayici d[][BOYUT]);
void komsulari_tara(int satir, int sutun, patlayici d[][BOYUT]);
void goster(patlayici d[][BOYUT]);
int tamamlandi_mi(patlayici d[][BOYUT]);
void oyun_sonu_goster(patlayici d[][BOYUT]);

int main()
{
    patlayici oyun_alani[BOYUT][BOYUT];
    ilklendir(oyun_alani);
    int satir,sutun;
    goster(oyun_alani);
    do{
        don:; //satir ve sutun numaralari oyun alani disina tasarsa bu etiketle basa donecek.
        printf("Kullanici puani : %d",skor);
        printf("\nSeciminiz : ");
        scanf("%d%d",&satir,&sutun);
        if(satir>7||satir<0||sutun>7||sutun<0)
        {
            printf("Yanlis giris\n");goto don;
        }
        hamle_yap(satir,sutun,oyun_alani);
        goster(oyun_alani);
        if(acilan_alan==1)
            {printf("ACILMIS ALAN! FARKLI BIR ALAN GIRIN \n");acilan_alan=0;}
        if(tamamlandi_mi(oyun_alani)==1)
            break;
    }while(skor>0);
    oyun_sonu_goster(oyun_alani);
    if(skor>0)
        printf("Tebrikler");
    else
        printf("Kaybettiniz %d",skor);
}
void ilklendir(patlayici d[][BOYUT])
{
    int i,j,a,b;
    for(i=0;i<BOYUT;i++)
    {
        for(j=0;j<BOYUT;j++)
        {
            d[i][j].tip='O';d[i][j].etki=0;d[i][j].yapildi_mi=0;
        }
    }
    i=0;
    srand(time(NULL));
    int ary[BOYUT+1][BOYUT+1]={0};
    int x,y;

    while(i<BOYUT+1)
    {   YENIDEN:;
        a=rand()%8;
        b=rand()%8;
        for(x=0;x<BOYUT;x++)
        {
            for(y=0;y<BOYUT;y++) //random sayi uretirken a=x ve b=y olsun,
            {                   //x,y sayi ikilisinin tekrar x,y (yalnizca bir kere uretilecek) sayi ikilisi olarak uretilmemesi icin
                if(a==x&&b==y)  //donguye girdik ve bu durumu ortadan kaldirmak icin onlem aldik.
                {
                    ary[x][y]++;
                    if(ary[x][y]>1)
                        goto YENIDEN;
                }
            }
        }
        switch(i)
        {
            case 0:case 1: d[a][b].etki=2;d[a][b].tip='M';d[a][b].yapildi_mi=0;break;
            case 2:case 3: d[a][b].etki=4;d[a][b].tip='D';d[a][b].yapildi_mi=0;break;
            case 4:case 5: d[a][b].etki=6;d[a][b].tip='R';d[a][b].yapildi_mi=0;break;
            case 6:case 7: d[a][b].etki=8;d[a][b].tip='A';d[a][b].yapildi_mi=0;break;
            case 8: d[a][b].etki=10;d[a][b].tip='N';d[a][b].yapildi_mi=0;break;
        }
        i++;
    }
}
void oyun_sonu_goster(patlayici d[][BOYUT])
{
    int i,j;
    system(CLEAR);
    for(i=0;i<BOYUT;i++)
    {
        for(j=0;j<BOYUT;j++)
                printf("%c\t",d[i][j].tip);
        printf("\n");
    }

}
void goster(patlayici d[][BOYUT])
{
    int i,j;
    system(CLEAR);
    for(i=0;i<BOYUT;i++)
    {
        for(j=0;j<BOYUT;j++)
        {
            if(d[i][j].yapildi_mi==0)
                printf("%c\t",'O');
            else if(d[i][j].yapildi_mi==1)
                printf("%c\t",'X');
            else
                printf("%c\t",d[i][j].tip);
        }

        printf("\n");
    }

}
void komsulari_tara(int satir, int sutun, patlayici d[][BOYUT])
{
    //eger girilen satir ve sutunun 1 eksigi ile 1 fazlasi 0dan kucuk veya 7 den buyukse o satirlari es gececek.

    int i,j;
    for(i=satir-1;i<=satir+1;i++)
    {
        if(i<0||i>7)
            continue;

        for(j=sutun-1;j<=sutun+1;j++)
        {
            if(j<0||j>7)
                continue;

            if(d[i][j].tip=='O')
            {
                d[i][j].tip='X';
                d[i][j].yapildi_mi=1; //patlayici olmadan 1 yapacak patlayici varsa 2 yapacak
            }
        }
    }

}
void skor_guncelle(patlayici* a)
{
    skor=skor-a->etki;
    a->yapildi_mi=2; //patlayici varsa 2 yapacak patlayici yoksa 1 yapacak.
}
void hamle_yap(int satir, int sutun, patlayici d[][BOYUT])
{
    if(d[satir][sutun].yapildi_mi==2||d[satir][sutun].yapildi_mi==1)
        {acilan_alan=1;}
    else
    {
            if(d[satir][sutun].tip=='O')
        {
            d[satir][sutun].tip='X';
            d[satir][sutun].yapildi_mi=1;
            komsulari_tara(satir,sutun,d);
        }
            else
        {
            skor_guncelle(&d[satir][sutun]);
        }
    }
}
int tamamlandi_mi(patlayici d[][BOYUT])
{
    int i,j,count=0;
    for(i=0;i<BOYUT;i++)
    {
        for(j=0;j<BOYUT;j++)
        {
            if(d[i][j].tip=='X')
                count++;
        }
    }
    if(count==(BOYUT*BOYUT-9)) //64 taneden 9 tane patlayici yi cikarirsak toplam elde etmek istedigimiz patlayici olmayan
        return 1;              //karelere ulasmis oluruz.
    else
        return -1;
}

