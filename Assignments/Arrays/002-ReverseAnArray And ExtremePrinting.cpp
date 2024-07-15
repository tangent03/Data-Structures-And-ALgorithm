								//JAI SHREE RAM
								//JAI BAJRANGBALI
								//OM NAMAH SHIVAYE
								
			//TIME COMPLEXITY - O(N)
			//SPACE COMPLEXITY - O(1)
			
			
//QUESTION : - REVERSE AN ARRAY 

//IN INTERVIEWS - GO FROM BRUTE FORCE SOLUTION -> BETTER SOLUTION -> OPTIMAL SOLUTION


//TWO POINTER METHOD - MAKE 2 POINTERS START AND END IN THIS QUESTION AND 
//JUST SWAP THE START AND END UNTIL START>END.



//VALUE AT AN INDEX = (VALUE AT BASE ADDRESS + (DATATYPE SIZE* INDEX))


#include <bits/stdc++.h>
using namespace std;



void reverseAnArray(int arr[],int n){
	int start=0;
	int end=n-1;
	
	while(start<=end){
		swap(arr[start],arr[end]);
		start++;
		end--;
	}
	
}

void printArray(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}




//SIMILAR QUESTION 

//QUESTION :- EXTREME PRINT IN AN ARRAY

void extremePrintArray(int arr[],int n){
	int start=0;
	int end=n-1;
	while(start<=end){
		if(start==end){
			cout<<arr[start]<<" ";
		}
		else{
			cout<<arr[start]<<" ";
			cout<<arr[end]<<" ";
			
		}
		
		start++;
		end--;
	}
}

int main(){
	
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    cout<<"Before Reversing : "<<endl;
    printArray(arr,n);
    cout<<endl;
    reverseAnArray(arr,n);
    cout<<"After Reversing : "<<endl;
    printArray(arr,n);
    cout<<endl<<"Extereme Printing of an Array : "<<endl;
    extremePrintArray(arr,n);
   
    
    
}

















