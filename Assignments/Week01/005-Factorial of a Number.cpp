								//JAI SHREE RAM
								//JAI BAJRANGBALI
								//OM NAMAH SHIVAYE
								
			
			
			
//QUESTION : - Factorial Of A Nummber (smaller number)

#include <bits/stdc++.h>
using namespace std;
//---------------------------------------




long long int factorial(long long int num){
	long long int factorial =1;
	for(int i=1;i<=num;i++){
		factorial=factorial*i;
	}
	return factorial;
}

int main(){
	
	int num;
	cin>>num;
	long long int ans = factorial(num);
	cout<<"Factorial Of a Number "<<num<<" is : - "<<ans<<endl;
	
}