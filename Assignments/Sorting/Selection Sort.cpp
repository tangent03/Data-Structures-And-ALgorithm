#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity of Selection SOrt is O(N^2)
- For Best , Average And Worst



It Selects the Minimum and swaps with the iterator

ex i loop till n-2 and j till n-1
	assumes i to be minimum and if arr[j]<arr[min] swaps



*/


void selection_sort(int arr[], int n){
	for(int i=0;i<=n-2;i++){
		int minimum = i;
		for(int j=i;j<=n-1;j++){
			if(arr[j]<arr[minimum]){
				minimum=j;
			}
		}
		int temp = arr[minimum];
		arr[minimum]= arr[i];
		arr[i]=temp;
	}
}


int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	selection_sort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}