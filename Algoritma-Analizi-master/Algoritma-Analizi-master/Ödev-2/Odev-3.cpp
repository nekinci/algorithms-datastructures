#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int toplamPuanSayisi(int p[],int n){
    bool asal[n+1];
    memset(asal,true,sizeof(asal));
    int counter = 0;
    
    for(int i = 2; i*i<=n; i++){
    	if(asal[i] == true){
    		
    		for (int j = i*i; j <=n; j+=i){
    			asal[j] = false;
			}
		}
	}
	
	for (int i = 2; i <= n; i++)
		if(asal[i] == true)
			counter+= p[i-1];
	
	return counter;
}

int main(){
    cout << "Problem sayisini girin: ";
    int n;
    cin >> n;
    int *points = new int[n];
    cout << "Problem puanlarini sirasiyla giriniz(n tane) :";
    for(int i = 0; i < n; i++){
        cin >> points[i];
    }
	cout << "Dynamic-Programming O(nlog(logN))\n";
    cout << "Asal sayýya denk gelen problemlerin toplam puani : " <<toplamPuanSayisi(points,n);

}
