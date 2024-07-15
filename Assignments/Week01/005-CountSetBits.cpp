								//JAI SHREE RAM
								//JAI BAJRANGBALI
								//OM NAMAH SHIVAYE
								
			
			
			
//QUESTION : - Count All Set Bits --set bits mtlab binary me 1;

 
// 1.Brute Force -- 
//TO CONVERT DECIMAL TO BINARY - 
//NUMBER KO 2 SE DIVIDE KRO JO REMAINDER AAYA VO LIKHTE JAO 
//JABTK NUMBER 0 NA HOJAYE
//FIR REMAINDER WALO KO ULTA KRLO TO BINARY ME CONVERT HOJAEGA.



// 2. BITWISE Method

#include <bits/stdc++.h>
using namespace std;


// int countSetBits(int n){
	// int count=0;
	// while(n>0){
		// int bit = n%2;
		// if(bit==1){
			// count++;
		// }
		// n=n/2;
	// }
	// return count;
// }


	int countSetBits(int n){
		int count=0;
		while(n>0){
			int bit = (n & 1); //number ko & krenge 1 se to LSD dega
			if(bit==1){
				count++;
			}
			n = n >> 1;  //rightshift by 1
		}
		return count;
	}

int main() {
	int n;
	cin>>n;
	cout<<countSetBits(n)<<" is the Count Of Set Bits";
    
}
