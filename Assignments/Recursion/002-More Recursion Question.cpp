#include <bits/stdc++.h>
using namespace std;

void sumOfNumbers(int i, int sum){
	
	//base case
	if(i<1){
		cout<<sum<<endl;
		return;
	}
	
	//1 case hum
	
	sumOfNumbers(i-1,sum+i);
}

int factorial(int n){
	
	//base case
	
	if(n==0){
		return 1;
	}
	
	//1 case hum karenge
	return n*factorial(n-1);
}

void reverseArray(int i, int arr[], int n){
	if(i>=n/2){
		return;
	}
	
	swap(arr[i], arr[n-i-1]);
	reverseArray(i+1,arr,n);
}

int main(){
	int n =4;
	int arr[4] = {1,2,3,4};
	sumOfNumbers(n,0);
	cout<<factorial(n)<<endl;
	reverseArray(0,arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}