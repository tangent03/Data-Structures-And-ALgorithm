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
     

void sortNegPos(int arr[],int n){
	int i=0;
	int j=n-1;
	
	while(i<j){
		if(arr[i]<0){
			i++;
		}
		else if(arr[j]>0){
			j--;
		}
		else{
			swap(arr[i],arr[j]);
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
   sortNegPos(arr,n);
   cout<<"Sorted Array is "<<endl;
   for(int i=0;i<n;i++){
   	cout<<arr[i]<<" ";
   }
   
    
}

















