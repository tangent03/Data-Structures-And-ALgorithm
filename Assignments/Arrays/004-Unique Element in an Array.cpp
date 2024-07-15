								//JAI SHREE RAM
								//JAI BAJRANGBALI
								//OM NAMAH SHIVAYE
	

#include <bits/stdc++.h>
using namespace std;


// 
// 
// ### Explanation:
// 
// 
// XOR Operation: The XOR operation has the property that ( a xor a = 0 )
// and ( a xor 0 = a ). This means that when you XOR all elements of the 
// array together, the elements that appear in pairs will cancel each other out, 
// leaving only the unique element.
// 
// 
// ### Conclusion:
// 
// This approach efficiently finds the unique element with a time complexity
 // of ( O(n) ) and a space complexity of ( O(1) ). This makes it both 
 // time-efficient and space-efficient for large arrays.


int getUniqueElement(int arr[],int n){
	int ans=0;
	for(int i=0;i<n;i++){
		ans=ans^arr[i];
	}
	return ans;
}


int main(){
	
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
   	cin>>arr[i];
   }
   
   int uniqueElement = getUniqueElement(arr,n);
   cout<<"Unique Element is  "<<uniqueElement<<endl;
    
    
}

















