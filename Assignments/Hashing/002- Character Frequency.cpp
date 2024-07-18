
/*
#include <bits/stdc++.h>
using namespace std;



int main(){
	string s;
	cin>>s;
	int q;
	cin>>q;
	
	//precomputer
	int hash[26] = {0};
	for(int i=0;i<s.size();i++){
		hash[s[i] - 'a']++;
	}
	
	
	
	while(q--){
		char c;
		cin>>c;
		
		//fetch 
		cout<<hash[c-'a']<<endl;
		
	}
	
	
	return 0;
}

*/

//Points To Remember
//1. if samll letters then ch-'a'
//2.if Capital letter than ch-'A'
//3.if All characters than tahke hash[256] and simply hash[c]  and hash[s[i]];


















#