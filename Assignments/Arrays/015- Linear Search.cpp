#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int num){
	for(int i=0;i<n;i++){
		if(arr[i] == num){
			return i;
		}
	}
	return -1;
}


int main(){
	int arr[] = {1,2,3,4,5};
	int num = 4;
	int n = sizeof(arr)/sizeof(arr[0]);
	int val = linearSearch(arr,n,num);
	cout<<" Index is : "<<val;
	
	
	
	return 0;
}