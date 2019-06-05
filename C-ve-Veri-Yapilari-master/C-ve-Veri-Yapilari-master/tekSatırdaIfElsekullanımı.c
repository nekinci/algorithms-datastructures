#include<stdio.h>

int main()
{
	//basit if deyimi denilebilir.
	//güzel bir kullanýmý var.
	//eðer x 3 ten büyük ise ? iþaretinden sonraki deðeri al deðilse : iþaretinden sonraki
	//deðeri al demek if else ile ayný deyim yazýlabilirdi.
	//pratiklik açýsýsndan kullaným önemli.
	int x, y;
	printf("bir sayi girin: ");
	scanf_s("%d", &x);
	y = x > 3 ? x + 5 : x - 1;
	printf("%d", y);
	getch();

}