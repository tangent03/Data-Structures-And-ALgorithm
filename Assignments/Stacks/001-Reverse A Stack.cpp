#include <bits/stdc++.h>
using namespace std;



/*
*** JAB BHI KISI CHEEJ KO REVERSE KRNA HO TO 
USE STACK

EX= EK TARAF SE AALO DUSRE TARAF SE SONAA
TO EK TARAF KOI CHEEZ BICH ME YE ALGO DUSRE TARAF REVERSED CHEEJ



*/


int main(){
	
	string str = "helloJee";
	stack<char>st;
	
	for(int i=0;i<str.length();i++){
		char ch = str[i];
		st.push(ch);
	}
	
	cout<<endl;
	while(!st.empty()){
		cout<<st.top();
		st.pop();
	}
	cout<<endl;
	
	return 0;
}