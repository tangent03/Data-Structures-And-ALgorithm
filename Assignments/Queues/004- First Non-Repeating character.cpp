#include <bits/stdc++.h>
using namespace std;

//question - phela letter without reoccurance

int main(){
	string str="ababc";
	queue<char>q;
	int freq[26] ={0};
	
	for(int i=0;i<str.length();i++){
		char ch = str[i];
		freq[ch-'a']++;
		q.push(ch);
		
		//answer find karo
		
		while(!q.empty()){
			char frontCharacter = q.front();
			if(freq[frontCharacter-'a'] > 1){
				q.pop();
			}
			else{
				//1 wala case
				//yehi ans hai
				
				cout<<frontCharacter<<"->";
				break;
			}
		}
		
		if(q.empty()){
			//koi ans nahi hai
			
			cout<<"#"<<"->";
		}
	}
	
	return 0;
}