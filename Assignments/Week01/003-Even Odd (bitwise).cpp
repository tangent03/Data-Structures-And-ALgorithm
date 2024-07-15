								//JAI SHREE RAM
								//JAI BAJRANGBALI
								//OM NAMAH SHIVAYE
								
			
			
			
//QUESTION : - EVEN ODD - 2 METHODS
//1.BRUTE FORCE
//2.USING BITWISE OPERATORS - FOR EVEN THE LSD IS 0 AND FOR ODD LSD IS 1

//NUM & 1 == LSD

#include <bits/stdc++.h>
using namespace std;
//---------------------------------------

//1. Brute Force

// bool isEven(int num){
	// if(num%2==0){
		// return true;
	// }
	// else{
		// return false;
	// }
// }

//---------------------------------------

//2. Bitwise Operator



bool isEven(int num){
	if((num&1)==0){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	
	int num;
	cin>>num;
	bool ans = isEven(num);
	if(ans){
		cout<<"Number is Even"<<endl;
	}
	else{
		cout<<"Number is Odd"<<endl;
	}
	
}