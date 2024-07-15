								//JAI SHREE RAM
								//JAI BAJRANGBALI
								//OM NAMAH SHIVAYE
								
			
			
			
//QUESTION : - Prime Number

#include <bits/stdc++.h>
using namespace std;
//---------------------------------------

bool isPrime(int num){
	for(int i=2;i<num;i++){
		if(num%i==0){
			return false;
		}
		
	}
	return true;
}

int main(){
	
	int num;
	cin>>num;
	bool ans = isPrime(num);
	if(ans){
		cout<<"Number is Prime"<<endl;
	}
	else{
		cout<<"Number is Not Prime"<<endl;
	}
	
}