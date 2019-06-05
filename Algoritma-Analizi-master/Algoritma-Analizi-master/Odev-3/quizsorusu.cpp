#include<iostream>
#include<string>
#include<stdio.h>


using namespace std;
int counter = 0;

int mutlakDeger(char a,char b){
	if(a <= b)
		return b-a;
	return a-b;
}

int gunSayisi(char a[],char b[],int uzunluk){
	bool check = false;
	for (int i=0; i < uzunluk; i++ ){
		
		while(b[i]-a[i] >= 13){
			counter++;
			a[i] = a[i] +13;
			
		}
		while(a[i]-b[i] >=13){
			counter++;
			b[i] = b[i] + 13;
		}
		if(b[i] % a[i] < 13){
			counter += mutlakDeger(a[i],b[i]);
		}
		if(a[i] % b[i] < 13)
			counter += mutlakDeger(a[i],b[i]); 
		
		
	}
	return counter;
}

int main(){
	cout << "String uzunlugu girin: ";
	int l; 
	cin >> l;
	cout << "Stringleri giriniz: ";
	char a[l] , b[l];
	cin >> a;
	cin >> b;
	cout << gunSayisi(a,b,l);
}
