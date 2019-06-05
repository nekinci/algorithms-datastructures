#include<stdio.h>

/*
Palindrom Sayi olup olmadigini kontrol eden C Projesi
160204044 Niyazi EKINCI
*/

int tersiniAl(int a); // C derleyicisine boyle bir fonksiyonun varligini gosterdik.
int basamakSayisi(int b);
int toplam=0,kalan,basamak; //degiskenlerimizi butun fonksiyonlarda kullanabilmek icin burda tanimladik.
int main()
{

	int sayi; SayiAl:; // goto etiketi baslangici
	puts("Bir sayi giriniz(5 basamakli): ");
	scanf("%d",&sayi); // Sayi alma islemini yaptik.
	puts("*************************************************");

	if(basamakSayisi(sayi)==5)
	{

        tersiniAl(sayi); // sayi 5 basamakliysa sayinin tersini alir.
	}
	else
	{

		puts("Lutfen 5 basamakli sayi giriniz: "); goto SayiAl; // goto kullanarak tekrar sayi alma islemine donduk.
	}

	if(sayi==toplam) // girdigimiz sayi sayinin tersine esitse
		puts("Bu sayi palindrom sayidir");
	else
		puts("Bu sayi palindrom sayi degildir.");
	puts("*************************************************");
	system("pause"); // ekranda kalmasini sagladik.
	return 0;
}
int basamakSayisi(int b)
{
	basamak=0;
	while(b!=0)
	{
		b=b/10;
		basamak++; //0 olana kadar 10 a bolup basamagi bir arttirirsak basamak sayisini buluruz.
	}
	return basamak;
}
int tersiniAl(int sayi)
{
	while(sayi!=0)
		{
			toplam=toplam*10; // En son basamaktaki sayidan baslayarak 10 la carparsak tersini almis oluruz.
			kalan=sayi%10; // her adimda son basamagi almak icin
			toplam=toplam+kalan;
			sayi=sayi/10;	// sayi int turunde oldugu icin 0 yapana kadar bolmus olacagiz.
		}
		printf("Tersi: %d\n",toplam);
}
