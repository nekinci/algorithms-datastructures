#include<stdio.h>
#include<stdlib.h>
#include<time.h> //random uretebilmek icin.
#define BOYUT 8

typedef struct{
    char tip;
    int etki;
    int yapildi_mi;
}patlayici;

int skor=10;
int acilmis_alan=0;
//prototip tanimlari
void hamle_yap(int ,int,patlayici d[][BOYUT]);
void komsulari_tara(int, int, patlayici d[][BOYUT]);
void ilklendir(patlayici d[][BOYUT]);
void skor_guncelle(patlayici *);
void goster(patlayici d[][BOYUT]);
int tamamlandi_mi();

int main()
{

    int satir,sutun;
    patlayici oyun_alani[BOYUT][BOYUT];
    ilklendir(oyun_alani);
    goster(oyun_alani);
    do{
        printf("\nKullanici puani: %d",skor);
        printf("\nSeciminiz: ");
        scanf("%d%d",&satir,&sutun);
        hamle_yap(satir,sutun,oyun_alani);
        goster(oyun_alani);

    }while(skor>0);
}
void ilklendir(patlayici d[][BOYUT])
{
    int i,j;
    for(i=0;i<BOYUT;i++)
    {
        for(j=0;j<BOYUT;j++)
        {
            d[i][j].tip='O';d[i][j].etki=0;d[i][j].yapildi_mi=0;
        }

    }
    i=0;
    srand(time(NULL));
    int a,b;
    while(i<=8)
    {
        a=rand()%8;
        b=rand()%8;
        switch(i)
        {
            case 0:case 1: d[a][b].tip='M';d[a][b].etki=2;d[a][b].yapildi_mi=0;break;
            case 2:case 3: d[a][b].tip='D';d[a][b].etki=4;d[a][b].yapildi_mi=0;break;
            case 4:case 5: d[a][b].tip='R';d[a][b].etki=6;d[a][b].yapildi_mi=0;break;
            case 6:case 7: d[a][b].tip='A';d[a][b].etki=8;d[a][b].yapildi_mi=0;break;
            case 8: d[a][b].tip='N';d[a][b].etki=10;d[a][b].yapildi_mi=0;break;
        }
        i++; //random olarak atamalari yaptik.
    }
}
void goster(patlayici d[][BOYUT])
{
    int i,j;
    system("clear");
    for(i=0;i<BOYUT;i++)
    {
        for(j=0;j<BOYUT;j++)
        {
            printf("%c\t",d[i][j].tip);
        }
        printf("\n");
    }
}

void hamle_yap(int satir, int sutun, patlayici d[][BOYUT])
{
    if(d[satir][sutun].yapildi_mi==0) //yapildi_mi =0 demek hamle yapilmamis demek o yuzden bu ifle hamle yapmaya izin veriyoruz.
    {
        if(d[satir][sutun].tip=='O')
        {
            komsulari_tara(satir,sutun,d);
        }
        else
            skor_guncelle(&d[satir][sutun]);
    }
    else
    {
      system("clear");
      puts("acilmis alan");
      getchar();
    }

}
void komsulari_tara(int satir, int sutun, patlayici d[][BOYUT])
{
    //eğer satir-1 satir+1 0 ile 7 arasinda degil ise ve sutun-1 sutun+1 0,7 arasinda degilse sadece sinirda ve ustunde olanlar calisacak.
    //eğer komsudan bi tanesi patlayiciysa onun yerine 'O' gosterilecek yapildi_mi si 0 olsun ki hamle yapılabilsin.
    //O ları X yapacak ama yapildi_mi larida 1 yapacak.
    int i,j;
    for(i=satir-1;i<=satir+1;i++)
    {
        for(j=sutun-1;j<=sutun+1;j++)
        {
            if(d[i][j].tip=='O')
            {
                d[i][j].tip='X';
                d[i][j].yapildi_mi=1;
            }

        }

    }
}
void skor_guncelle(patlayici*a)
{
    skor=skor-a->etki; //skor dan patlayicinin tesirini cikardik.
    a->yapildi_mi=2;
}
