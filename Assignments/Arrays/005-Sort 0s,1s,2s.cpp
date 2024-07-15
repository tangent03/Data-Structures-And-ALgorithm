								//JAI SHREE RAM
								//JAI BAJRANGBALI
								//OM NAMAH SHIVAYE
	

#include <bits/stdc++.h>
using namespace std;

//QUESTION - SORT THR 0s,1s,2s IN AND ARRAY.

//TWO POINTER APPROCH-  HERE WE TAKE 2 POINTERS(I.E - J,K AND INDEX I FOR LOOPING)


//The code provided is an implementation of the Dutch National Flag algorithm 
//by Edsger Dijkstra, which sorts an array containing only the values 0, 1,
 //and 2. This algorithm uses a two-pointer approach to sort the array in a
  //single pass with a time complexity of \(O(n)\). Here's an explanation of
  // how the code works:

// 
    // Initialization 
        // - `i = 0`: The current element being examined.
        // - `j = 0`: The index where the next `0` should be placed.
        // - `k = n - 1`: The index where the next `2` should be placed.
    // Loop (`while (i <= k)`)**:
        // - If `arr[i] == 0`, swap `arr[i]` with `arr[j]`, 
      //  and increment both `i` and `j`.
        // - If `arr[i] == 2`, swap `arr[i]` with `arr[k]`,
       //  and decrement only k ass we dont know that was there at k position.
// 


//same as SORT COLORS

//O(N)

void sort012(int arr[],int n){
	int i=0;
	int j=0;
	int k=n-1;
	
	while(i<=k){
		if(arr[i]==0){
			swap(arr[i],arr[j]);
			i++;
			j++;
		}
		else if(arr[i]==2){
			swap(arr[i],arr[k]);
			k--;
		}
		else{
			i++;
		}
	}
	
}


int main(){
	
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
   	cin>>arr[i];
   }
   sort012(arr,n);
   cout<<"Sorted Array is "<<endl;
   for(int i=0;i<n;i++){
   	cout<<arr[i]<<" ";
   }
   
    
}
