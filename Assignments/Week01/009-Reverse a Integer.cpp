								//JAI SHREE RAM
								//JAI BAJRANGBALI
								//OM NAMAH SHIVAYE
								
			
			
			
//QUESTION : - Reverse a Integer (Leetcode) - 07


// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
// 
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
// 
//  
// 
// Example 1:
// 
// Input: x = 123
// Output: 321
// Example 2:
// 
// Input: x = -123
// Output: -321
// Example 3:
// 
// Input: x = 120
// Output: 21
//  
// 
// Constraints:
// 
// {-231 <= x <= 231 - 1}








//32-bit integer mtlab integer 4byte ka hota hai matlab 32 bit

//isme negetive aur 32 bit signed ke range me hai

//ans INT_MAX /10 se zyada nai aur Number INT_MIN se kam nai honi chaiye




#include <bits/stdc++.h>
using namespace std;
//---------------------------------------

int reverseInteger(int num){
		
		int digit=0,ans=0;
		
		bool isNeg=false;
		
		if(num<=INT_MIN){
			return 0;
		}
		
		if(num<0){
			isNeg=true;
			num=-num;
		}
	
	while(num>0){
		if(ans>INT_MAX / 10){
			return 0;
		}
		digit=num%10;
		ans= ans*10 + digit;
		num=num / 10;
	}
	
	if(isNeg){
		return -ans;
	}
	else{
		return ans;
	}
}

int main(){
	
	int num;
	cin>>num;
	int answer = reverseInteger(num);
	cout<<"Reverse of Number"<<num<<" is : "<<answer;
	
}