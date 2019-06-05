
#include<stdio.h>

int mutlakDeger(int a, int b) {
	int sonuc;
	if (a >= b)
		sonuc = a - b;
	else
		sonuc = b - a;
	return sonuc;

}





int main()
{
	int a, b;
	printf("Mutlak deger icin iki adet sayý giriniz: ");
	printf("\nBirinci sayiyi giriniz: ");
	scanf_s("%d", &a);
	printf("Ikinci sayiyi giriniz : ");
	scanf_s("%d", &b);
	printf("Mutlak deger: %d", mutlakDeger(a, b));
	getch();
}