#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

void ciftSayiSayisi(string s){

    // bu fonksiyon O(n^2) karmaşıklığında çalışır ve brute-force dir. Direkt ilk akla gelen kaba yaklaşım
    int counter = 0;
    cout << "Bu fonksiyon O(n^2) karmasikliginda problemi cozer: \nSonuc: ";
    for(int i = 0; i < s.length(); i++){
        counter = 0;
        for (int j = i; j < s.length(); j++){
            int sayi = (int) s[j] % 48;
        //    cout << sayi << " ";
            if(sayi%2 == 0)
                counter++;
        }
        cout << " " << counter;
    }
}

void DPCiftSayi(string s){
    int values[s.length()+1] = {0};
    int counter = 0;
    cout << "(Dynamic) Bu fonksiyon ise O(2n) = O(n) karmasikliginda problemi cozer.\nSonuc : ";
    for(int i = s.length()-1; i >= 0; i--){
        int sayi = ((int) s[i]) % 48;
        if (sayi%2 == 0)
            counter++;
        values[i] = counter;
    }
    for (int i = 0; i < s.length(); i++)
        cout << values[i]<< " ";
}

int main(){
    cout << "Lütfen 1-9 arası karakterlerden oluşan stringi giriniz: ";
    string s;
    cin >> s;
    cout << s << "\n";
    ciftSayiSayisi(s);
    cout << "\n ";
    DPCiftSayi(s);
}
