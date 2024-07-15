								//JAI SHREE RAM
								//JAI BAJRANGBALI
								//OM NAMAH SHIVAYE
								
			
			
			
//QUESTION : - Armstrong Number :-
//Summation of  Digit ki Power CountOfDigit in Integer == Number itself;

//not the optimal way but theek hai :)
// 

#include <bits/stdc++.h>
using namespace std;

void armstrongNumber(int n){
	int digit=0;
	int sum=0;
	int duplicate=n;
	int count =0;
	while(n>0){
		digit=n%10;
		count++;
		n=n/10;
	}
	n=duplicate;
	while(n>0){
		digit= n%10;
		sum=sum + pow(digit,count);
		n=n/10;
	}
	if(sum==duplicate){
		cout<<"YES Armstrong Number";
	}
	else{
		cout<<"Not Armstrong Number";
	}
}

int main() {
    int n;
    cin>>n;
	armstrongNumber(n);
}
