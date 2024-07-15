#include <bits/stdc++.h>
using namespace std;

//Time Complextity is O(N);

void countCharacters(unordered_map<char,int> &mapping,string str){
	for(int i=0;i<str.length();i++){
		char ch = str[i];
		mapping[ch]++;
	}
}

//mapping[ch]++; isse us ch ki frequency badhte rehti hai jo character aata hai

int main(){
	string str = "lovebabbar";
	unordered_map<char,int>mapping;
	countCharacters(mapping,str);
	
	for(auto i:mapping){
		cout<<i.first<<" -> "<<i.second<<endl;
	}
	
	return 0;
}



//Ordered Mpas me - SORTED order me milega ans
//unordered me time complexity kam hogi pr unsorted