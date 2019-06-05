#include <iostream>
#include <cstdio>


using namespace std;

int t = 0; 
int recursion_topla(int a){
	if(a == 1)
		return 1;
	return a + recursion_topla(a-1);
}

int iterative_topla(int a){
	int toplam = 0;
	for(int i = 0; i <= a; i++){
		toplam += i;
	}

	return toplam;
}

void recursion_yaz(int a){
	
	if(a > 1)
		recursion_yaz(a-1);
	printf("%d  ",a);
}

void iterative_yaz(int a){
	for(int i = 1; i <= a; i++){
		printf("%d  ",i);
	}
}


void recursion_bastan_sona_yaz(int bas,int son){
	if(bas == son+1)
		return;
	printf("%d ", bas);
	recursion_bastan_sona_yaz(bas+1,son);
}


void recursion_satir_yaz(int);

void recursion_matris_yaz(int n, int m){
	if(n == 0)
		return;
	recursion_satir_yaz(m);
	printf("\n");
	recursion_matris_yaz(n-1,m);
}

void recursion_satir_yaz(int m){

	if (m == 0)
		return;
	printf("1 ");
	recursion_satir_yaz(m-1);	
}

/*
	STACK AND RECURSİON
	
	-	-
	- pr 1	-
	- pr 2	- 
	- pr 3	-
	- pr 4	-
	- pr 5	-	
	---------
	benim anladıgım kadarıyla ; 
	Recursion_yaz algoritmasında: 
		kendini çağırmadan önce yapılacak tüm işleri yaptı sonra kendini çağırdığında yapılacak alt satırlardaki  işi stack e attı - > pr 5
		daha sonra kendini çağırdı yani 4  onuda stack e attı -> pr 4
		""							-> pr 3
		""                                                      -> pr2
		daha sonra kendini çağırmayacağı için önce stacke pr 1 attı
		daha sonra pop etmeye başladı  
		pr 1 -> pr 2 -> pr 3 -> pr 4 -> pr 5
		

*/


int main(){
	
	cout << "Recursion[5] : " << recursion_topla(5) << "\n";
	cout << "Iterative[5] : " << iterative_topla(5) << "\n";

	recursion_yaz(5);
	cout << "\n";
	iterative_yaz(5);
	cout << "\n";
	recursion_bastan_sona_yaz(1, 10);
	recursion_matris_yaz(3,3);	
	return 0;
}
