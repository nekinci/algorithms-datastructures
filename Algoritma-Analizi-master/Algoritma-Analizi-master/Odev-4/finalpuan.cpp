#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>
#include <algorithm>
#include <bits/stdc++.h>



using namespace std;

const char* source = "sozluk.txt";
const char* text = "test.txt";

map<string,int> values;
vector<string> texts;

void dictionaryRead(){
    ifstream file (source);
    string line;
    if(file.is_open()){
        while ( getline (file,line) ){
         	values[line]++;
        }
        file.close();
    }
}

void matchAndPrintValues(){
	map<string,int>::iterator it;
	for(int i = 0; i < texts.size(); i++){
		if(){
			cout << texts[i] << "\n";
		}
	}
}

void textFileRead(){
    ifstream file (text);
    string line;
    string temp="";
    if(file.is_open()){
        int i = 0;
        while ( getline (file,line)){
            transform(line.begin(),line.end(),line.begin(),::tolower);
            while(line[i] != '\0'){
                if(line[i]<='z'&&line[i]>='a')
                    temp += line[i];
                i++;
            }
            i = 0;
            texts.push_back(temp);
            temp = "";
        }
    }
    file.close();
}

int main(){
    dictionaryRead();
    textFileRead();
	matchAndPrintValues();



}


