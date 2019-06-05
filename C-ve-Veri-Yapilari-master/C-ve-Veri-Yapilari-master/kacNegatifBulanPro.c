#include<stdio.h>

/*int negatifBulucu(int a)
{
	int i = 0;
	int kacNegatif = 0;
	while (i < 10)
	{
		
		i++;
		if (a < 0)
			kacNegatif++;
	}
	return kacNegatif;
}*/
int main()
{
	int a;
	int i = 0;
	int kacNegatif = 0;
	while (i < 10)
	{
		scanf_s("%d", &a);
		i++;
		if (a < 0)
			kacNegatif++;
	}
	printf("%d", kacNegatif );
	getch();
		
}