								//JAI SHREE RAM
								//JAI BAJRANGBALI
								//OM NAMAH SHIVAYE
								
			
			
			
//QUESTION - CHECK NUMBER IS A PALINDROME OR NOT. -09

//WEE WILL REVERSE THAT NUMBER AND CHECK IF SAME OR NOT.


// Given an integer x, return true if x is a 
// palindrome
// , and false otherwise.
// 
//  
// 
// Example 1:
// 
// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.
// Example 2:
// 
// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:
// 
// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
//  
// 
// Constraints:
// 
// -231 <= x <= 231 - 1
// 

#include <bits/stdc++.h>
using namespace std;

void numberPalindrome(int n){
		int digit=0;
		int duplicate=n;
		int revNumber=0;
	while(n>0){
		if(revNumber>INT_MAX/10){
			cout<<"NOT PALINDROME";
		}
		digit=n%10;
		revNumber= 10*revNumber + digit;
		n=n/10;
	}
	if(duplicate==revNumber){
		cout<<"Yes It Is Palindrome";
	}
	else{
		cout<<"Not Palindrome";
	}
}



int main() {
	int n;
	cin>>n;
	numberPalindrome(n);
    
}
