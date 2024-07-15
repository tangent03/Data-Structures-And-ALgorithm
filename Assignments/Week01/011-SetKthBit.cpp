								//JAI SHREE RAM
								//JAI BAJRANGBALI
								//OM NAMAH SHIVAYE
								
			
			

#include <bits/stdc++.h>
using namespace std;
//---------------------------------------

// QUESTION - SET THE KTH BIT 

//ISME PHELE  1 ko LEFT SHIFT KRENGE K SE TO MASK AAEGA IS MASK KO OR KRDO.

int setKthBit(int n ,int k){
	int mask = 1 << k;
	int ans= n | mask;
	return ans;
}



int main(){
	int n,k;
	cin>>n>>k;
	int answer = setKthBit(n,k);
	cout<<answer;
	
}