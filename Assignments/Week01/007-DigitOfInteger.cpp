								//JAI SHREE RAM
								//JAI BAJRANGBALI
								//OM NAMAH SHIVAYE
								
			
			
			
//QUESTION : - Print all digits of a Integer

//
// 

#include <bits/stdc++.h>
using namespace std;

void digitsOfInteger(int num){
	while(num){
		int digit = num % 10;
		cout<<"Digit is : "<<digit<<endl;
		num=num/10;
	}
	
}

int main() {
    int num;
    cin>>num;
    digitsOfInteger(num);
}
