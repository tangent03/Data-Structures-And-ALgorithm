								//JAI SHREE RAM
								//JAI BAJRANGBALI
								//OM NAMAH SHIVAYE
								
			//TIME COMPLEXITY - O(N)
			//SPACE COMPLEXITY - O(1)
			
			
//QUESTION : - LARGEST And Minimum  ELEMENT IN AN ARRAY 

//IN INTERVIEWS - GO FROM BRUTE FORCE SOLUTION -> BETTER SOLUTION -> OPTIMAL SOLUTION

//HERE BRUTE FORCE IS SORT THE ARRAY AND PRINT THE LAST ELEMENT. T(c)-o(nLogN)

//OPTIMAL SOLUTION IS MAKE THE FIRST INDEX AS LARGEST AND THEN COMPARE IT ITERATIVELY.



//VALUE AT AN INDEC = (VALUE AT BASE ADDRESS + (DATATYPE SIZE* INDEX))


#include <bits/stdc++.h>
using namespace std;

int largestInAnArray(int arr[],int n){
	int largest=arr[0];
	for(int i=0;i<n;i++){
		if(largest<arr[i]){
			largest=arr[i];
		}
	}
	return largest;
}

int minimumInAnArray(int arr[], int n){
	int minimum=arr[0];
	for(int i=0;i<n;i++){
		if(minimum>arr[i]){
			minimum=arr[i];
		}
	}
	return minimum;
}


int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int largestElement=largestInAnArray(arr,n);
	int minimumElement=minimumInAnArray(arr,n);
	cout<<"Largest element in an Array is "<<largestElement<<endl;
	cout<<"Minimum element in an Array is "<<minimumElement<<endl;
	
    
}
