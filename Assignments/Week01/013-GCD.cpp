								//JAI SHREE RAM
								//JAI BAJRANGBALI
								//OM NAMAH SHIVAYE
								
			
			
			
//QUESTION : - GCD of a number BEST OPTIMAL SOLUTION

//
// 

#include <bits/stdc++.h>
using namespace std;


int gcdOfTwoNumbers(int a, int b){
	while(a>0 && b>0){
		
		if(a>b){
			a=a%b;
		}
		else{
			b=b%a;
		}
	}
	if(a==0){
		return b;
	}
	else{
		return a;
	}
}

int main() {
    int a,b;
    cin>>a>>b;
    cout<<"Greated Common Divisior of Two Numbers "<<a<<" "<<b<<" is "<<gcdOfTwoNumbers(a,b);
    
}
