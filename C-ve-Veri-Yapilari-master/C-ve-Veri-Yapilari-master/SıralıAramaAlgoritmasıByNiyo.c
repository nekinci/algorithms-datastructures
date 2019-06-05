#include <stdio.h>


int main() {
	int arananSayi;
	int a[10] = { 1,2,3,4,5,6,7,8,9 };
	printf("Aramak istediginiz rakami giriniz: ");
	scanf_s("%d", &arananSayi);
	int i;
	i = 0;
	while (i <= 9)
	{
		printf("\n \### Eslestirilen deger : %d", a[i]);
		if (arananSayi == a[i])
		{
			printf("\nSonuc bulundu."); break;
		}
		else
			printf("\nEslestirme yok.");
		i++;

	}
	getch();
}