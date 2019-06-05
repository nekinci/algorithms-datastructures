
/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.c
 * Copyright (C) 2017 Serif Inanir <sheriffnnr@gmail.com>
 * Created 04.05.2017-21.47
 *
 * Patlayici_Tarlasi is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Patlayici_Tarlasi is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *     ALANYA ALAADDIN KEYKUBAT UNİVERSİTESİ
 *   Bilgisayar Mühendisliği 1. Sınıf
 *     Şerif İnanır ~~ 160204057
 *
 */



/*   PROGRAM AMACI
   =================================================

	Oyun alanı 8x8 matrisden oluşur.
	Rasgele 5 patlayici türü bu hücrelere atanır
	(Mayın, Dinamit, Roket, Nükleer, Atom)
	Farklı türdeki patlayıcıların hasarı farklıdır.

	Bomba bulunmayan tüm hücreler açılırsa yada
	canın tükenirse oyun biter.
*/




#include <stdio.h>	 // STANDART GİRDİ ÇIKTI KÜTÜPANESİ
#include <stdlib.h>  // RANDOM SAYI KULLANMAK İÇİN
#include <time.h>    // RANDOMDA SÜREKLİ AYNI SAYI GELMEMESİ İÇİN

// Global Değişkenlerim
int can=10;
int satir,sutun;
char FreeSoftwareLover;

int basarili_hamle_sayisi=0;
// Her patlayıcı için ayrı özellikler
// Tanımlayabilmek için oluşturulan yapı
struct patlayici{
	char patlayici_tipi;
	int patlayici_tesiri;
	int tespit_edildi;
};

//// ANA FONKSİYON
void main(void){
	printf("[ Mayın Tarlası ] ~Şerif İnanır~ Alanya Alaaddin Keykubat Universitesi\n\n");


	// ÇOK KATLI DİZİMİZİ patlayici YAPIMIZA EKLEDİK.
	struct patlayici oyun_alani[8][8];

	// BAŞLANGIÇ TABLOSUNU OLUŞTURUR.
	// TÜM HÜCRELERİN TİPİNİ O ve ZARARINI 0 YAPAR.
	// BU HÜCRELERİN MAYINDAN TEK FARKI TESİRİNİN 0 OLMASIDIR
	for(int ilk_satir=0;ilk_satir<8;ilk_satir++){
		for(int ilk_sutun=0;ilk_sutun<8;ilk_sutun++){
			oyun_alani[ilk_satir][ilk_sutun].patlayici_tipi='O';
			oyun_alani[ilk_satir][ilk_sutun].patlayici_tesiri=0;
			oyun_alani[ilk_satir][ilk_sutun].tespit_edildi=0;
			//printf(" %c ",alan[ilk_satir][ilk_sutun].patlayici_tipi);
		}
		//printf("\n");
	}

	// Bu fonksiyon ile OYUN BAŞLAR
	oyun_alanini_ilklendir(oyun_alani);

}

// OYUN ALANINI OLUŞTURUR VE
// BOMBALARI RASGELE HÜCRELERE ATAR
void oyun_alanini_ilklendir(struct patlayici alan[8][8]){

	// BOMBALAR VE ETKİ ALANLARINI ALAN TABLOSUNA EKLİYORUM
	char bombalar[9];
	int etkiler[9];
	bombalar[0]='M',bombalar[1]='M',bombalar[2]='D';
	bombalar[3]='D',bombalar[4]='R',bombalar[5]='R';
	bombalar[6]='A',bombalar[7]='A',bombalar[8]='N';
	etkiler[0]=2,etkiler[1]=2,etkiler[2]=4;
	etkiler[3]=4,etkiler[4]=6,etkiler[5]=6;
	etkiler[6]=8,etkiler[7]=8,etkiler[8]=10;

	// Bombalar rasgele oluşturulur ve
	// oyun_alanı na tesiriyle beraber atanır.
	int bom_satir,bom_sutun,ayni_kontrol=0;
	srand(time(NULL));
	for (int bom_adeti=1;bom_adeti<=9;bom_adeti++){
		bom_satir=rand()%8;
		bom_sutun=rand()%8;
		ayni_kontrol=ayni_mi(bom_satir,bom_sutun);
		if (ayni_kontrol==1){
			bom_adeti--;
		}
		else{
			// MEVCUT BOMBA YERLERİNİ GÖSTERİR
			//printf("%d %d \n",bom_satir,bom_sutun);
			alan[bom_satir][bom_sutun].patlayici_tipi=bombalar[bom_adeti-1];
			alan[bom_satir][bom_sutun].patlayici_tesiri=etkiler[bom_adeti-1];
		}
	}
	//alan[0][0].patlayici_tipi='O';
	//printf("asdsa %d",alan[0][5].patlayici_tesiri);

	oyun_alanini_goster(alan);
}


// static deger dizisi değerleri sıfırlanmayacak
// Rasgele satır sütün * ve + larıyla daha önceki çarpımlarla
// ve toplamlarla kontrol ettiren bir fonksiyon olması gerek
// Bir yerde birden fazla bomba olmaması için.
int ayni_mi(int satirB,int sutunB){
	static int deger[30],king=0;
	int carp;
	int toplam;
	carp=satirB*sutunB;
	toplam=satirB+sutunB+carp;
	for(int sira=0;sira<king;sira++){
		if(toplam==deger[sira]){
			return 1;
		}
	}
	deger[king]=toplam;
	king++;
	return 0;
}

void oyun_alanini_goster(struct patlayici alan[8][8]){
	int oyun_bitti_mi=0;
	while (oyun_bitti_mi==0){
	// GÜNCEL ALANI GÖSTERİR.
	// ANA ALANDAKİ AÇILAN KUTULARI GÖSTERİR SADECE.
	// AÇILMAYANLARI DUZ TABLOYA YÖNLENDİRİR
	// static char duz_alan[8][8];
	// Mevcut oyun alanını gösterir.
	for(int sutun_no=0;sutun_no<8;sutun_no++){
		printf("  %d",sutun_no);
	}
	for(int ilk_satir=0;ilk_satir<8;ilk_satir++){
		printf("\n%d",ilk_satir);
		for(int ilk_sutun=0;ilk_sutun<8;ilk_sutun++){
			if(alan[ilk_satir][ilk_sutun].tespit_edildi==0){
				printf(" O ");
			}
			else if (alan[ilk_satir][ilk_sutun].tespit_edildi==1){
				printf(" %c ",alan[ilk_satir][ilk_sutun].patlayici_tipi);
			}
		}
	}

	// Kullanıcı iletişim bölümü
	printf("\nMevcut Canın: %d\n",can);
	printf("Satır ve Sütunu gir (5-2 şeklinde): ");

	scanf("%d%c%d",&satir,&FreeSoftwareLover,&sutun);

	if (0<=satir<8 && 0<=sutun<8){
	// HÜCRE AÇMA İŞLEMLERİ
	hamle_yap(satir,sutun,alan);

	// OYUNUN BİTİP BİTMEDİĞİNİ KONTROL ETTİRİR
	oyun_bitti_mi=oyun_tamamlandi_mi(alan);
	}
	else{
		printf("\n0'dan 7 (dahil)'ye kadar numara girin!\n");
	}
	}
}

// GİRİLEN SATIR-SUTUNDA BOMBA OLUP OLMADIĞINI
// KONTROL EDER SADECE
void hamle_yap(int satir,int sutun,struct patlayici alan[8][8]){
	// GİRİLEN SATIR-SÜTUN DA NE VAR DİYE GÖRMEK İÇİN
	alan[satir][sutun].tespit_edildi=1;
	switch(alan[satir][sutun].patlayici_tipi){
		case 'O':
			basarili_hamle_sayisi++;
			printf("%d. Başarılı Hamle!\n",basarili_hamle_sayisi);
			komsulari_tara(satir,sutun,alan);
			break;
		default:
			if (alan[satir][sutun].patlayici_tesiri!=0){
				printf("%c Patlayicisina bastın!\n",alan[satir][sutun].patlayici_tipi);
				puani_guncelle(satir,sutun,alan);
			}
			else{
				printf("Bu hücre zaten açılı...\n");
			}
			break;
	}
}

// BOMBAYA BASILMIŞSA BU FONKSİYON CAN'ı
// BOMBA TESİRİ KADAR AZALTIR.
void puani_guncelle(int satir,int sutun,struct patlayici alan[8][8]){
	can-=alan[satir][sutun].patlayici_tesiri;
	alan[satir][sutun].patlayici_tesiri=0;
	if (can<0){
		can=0;
	}
	// OYUN BİTİYOR
}

void komsulari_tara (int satir,int sutun, struct patlayici alan[8][8]){
	if(alan[satir-1][sutun-1].patlayici_tipi=='O' && sutun>0){
		alan[satir-1][sutun-1].tespit_edildi=1;
		alan[satir-1][sutun-1].patlayici_tipi='X';
	}
	if(alan[satir-1][sutun].patlayici_tipi=='O'){
		alan[satir-1][sutun].tespit_edildi=1;
		alan[satir-1][sutun].patlayici_tipi='X';
	}
	if(alan[satir-1][sutun+1].patlayici_tipi=='O' && sutun<7){
		alan[satir-1][sutun+1].tespit_edildi=1;
		alan[satir-1][sutun+1].patlayici_tipi='X';
	}
	if(alan[satir][sutun-1].patlayici_tipi=='O' && sutun>0){
		alan[satir][sutun-1].tespit_edildi=1;
		alan[satir][sutun-1].patlayici_tipi='X';
	}
	if(alan[satir][sutun].patlayici_tipi=='O'){
		alan[satir][sutun].tespit_edildi=1;
		alan[satir][sutun].patlayici_tipi='X';
	}
	if(alan[satir][sutun+1].patlayici_tipi=='O' && sutun<7){
		alan[satir][sutun+1].tespit_edildi=1;
		alan[satir][sutun+1].patlayici_tipi='X';
	}
	if(alan[satir+1][sutun-1].patlayici_tipi=='O' && sutun>0){
		alan[satir+1][sutun-1].tespit_edildi=1;
		alan[satir+1][sutun-1].patlayici_tipi='X';
	}
	if(alan[satir+1][sutun].patlayici_tipi=='O'){
		alan[satir+1][sutun].tespit_edildi=1;
		alan[satir+1][sutun].patlayici_tipi='X';
	}
	if(alan[satir+1][sutun+1].patlayici_tipi=='O' && sutun<7){
		alan[satir+1][sutun+1].tespit_edildi=1;
		alan[satir+1][sutun+1].patlayici_tipi='X';
	}
}

int oyun_tamamlandi_mi(struct patlayici alan[8][8]){
	int son=0;
	if (can==0){
		oyun_alani_bomba_yerleri(alan);
		return 1;
	}
	for (int a=0;a<8;a++){
		for (int b=0;b<8;b++){
			if(alan[a][b].patlayici_tipi=='O'){
				son++;
			}
		}
	}
	if (son>0){
		return 0;
	}
	else {
		printf("\nTEBRİKLER!!! OYUNU TAMAMLADINIZ ~~~");
		return 1;
	}
}

void oyun_alani_bomba_yerleri(struct patlayici alan[8][8]){
	printf("\n  Mevcut canın: 0\n  OYUN BİTTİ~~~ Başarılı Hamle Sayısı: %d\n  BOMBA YERLEŞİMİ\n",basarili_hamle_sayisi);
	for (int c=0;c<8;c++){printf("  %d",c);}
	for (int a=0;a<8;a++){
		printf("\n%d",a);
		for(int b=0;b<8;b++){
			printf(" %c ",alan[a][b].patlayici_tipi);
		}
	}
}

