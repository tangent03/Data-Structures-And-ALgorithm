#include <bits/stdc++.h>
using namespace std;


/*
Time Complexity of Bubble Sort is O(N^2) - Worst And Average

For Best Case it is O(N);

In this We Push the Maximum elemnt at last
 after every iteration
Number of Iteration - (N-1)



*/



void bubble_sort(int arr[],int n){
	for(int i=n-1;i>=0;i--){
		int didSwap=0;
		for(int j=0;j<=i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j+1];
				arr[j+1] = arr[j];
				arr[j]=temp;
				didSwap=1;
			}
		}
		if(didSwap == 0){
			break;
		}
		cout<<"runs\n";
	}
}


int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	bubble_sort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	
	return 0;
}