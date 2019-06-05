#include<stdio.h>
#include<time.h>


int siniflandir(int not);
int main()
{
	int a;
	scanf_s("%d", &a);
	siniflandir(a);
	getch();
}
int siniflandir(int not)
{
	if (not<= 60)
		printf("0");
	if (not<= 70&& not>60)
		printf("1");
	if (not<= 80 && not>70)
		printf("2");
	if (not<= 90 && not>80)
		printf("3");
	if (not<= 100 && not>90)
		printf("4");

	return 0;
}