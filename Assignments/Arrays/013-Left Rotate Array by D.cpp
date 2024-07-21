#include <bits/stdc++.h>
using namespace std;

/*

Time Complexity: O(n), as we iterate through
 the array only once.

Space Complexity: O(n) as we are using another
 array of size, same as the given array.


*/

void rotateArrayLeftByOne(int arr[],int n){
	int temp = arr[0];
	for(int i=1;i<n;i++){
		arr[i-1]=arr[i];
	}
	arr[n-1]=temp;
}






/*

best Solution Time Complexity is O(N);

*/

void leftRotate(int arr[], int n, int d){
	reverse(arr,arr+d);
	reverse(arr+d,arr+n);
	reverse(arr,arr+n);
}


/* 
Nichew wale me Space bhi extra lagegi islie upar wala best
TC- O(N)

*/

void leftRotate1(int arr[],int n,int d){
	d=d%n;
	
	int temp[d];
	for(int i=0;i<d;i++){
		temp[i] = arr[i];
	}
	for(int i=d;i<n;i++){
		arr[i-d] = arr[i];
	}
	for(int i=n-d;i<n;i++){
		arr[i] = temp[i-(n-d)];
	}
}



int main(){
	
	 int n=5;
  
  int arr[]= {1,2,3,4,5};
  // rotateArrayLeftByOne(arr, n);
  rotateArrayRight(arr,n,3);
  for(int i=0;i<n;i++){
  	cout<<arr[i]<<" ";
  }
	
	return 0;
}