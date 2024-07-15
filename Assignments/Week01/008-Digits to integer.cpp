								//JAI SHREE RAM
								//JAI BAJRANGBALI
								//OM NAMAH SHIVAYE
								
			
			
			
//QUESTION : - Print a Integer From Digits;

//
// 

#include <bits/stdc++.h>
using namespace std;


int digitsToInteger(int numOfDigits){
	int num=0;
	int digit;
	for(int i=0;i<numOfDigits;i++){
		cout<<"Enter The Digit: ";
		cin>>digit;
		num = 10*num + digit;
	}
	return num;
}

int main() {
    int numOfDigits;
    cin>>numOfDigits;
    int num = digitsToInteger(numOfDigits);
    cout<<"Integer Created is : "<<num;
}
