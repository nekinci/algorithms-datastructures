#include<stdio.h>

int main()
{
	//basit if deyimi denilebilir.
	//g�zel bir kullan�m� var.
	//e�er x 3 ten b�y�k ise ? i�aretinden sonraki de�eri al de�ilse : i�aretinden sonraki
	//de�eri al demek if else ile ayn� deyim yaz�labilirdi.
	//pratiklik a��s�sndan kullan�m �nemli.
	int x, y;
	printf("bir sayi girin: ");
	scanf_s("%d", &x);
	y = x > 3 ? x + 5 : x - 1;
	printf("%d", y);
	getch();

}