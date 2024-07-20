#include <bits/stdc++.h>
using namespace std;


/*


Takes an element and place it in corrrect Place

Worst and Average Case  Time Complexity is O(N^2)
Best Case Time Complexity is O(N)

isme iteration n-1 tak jaate hai aur us index
 ko pichle wale se compare 
krte hai jahan sahi position udr put kr dete hai

*/
void insertion_sort(int arr[], int n){
	for(int i=0;i<=n-1;i++){
		int j=i;
		while(j>0 && arr[j-1] > arr[j]){
			int temp = arr[j-1];
			arr[j-1]=arr[j];
			arr[j] = temp;
			j--;
		}
	}
	
	
	
}

void insertion_sort_recursive(int arr[], int i, int n) {

    // Base Case: i == n.
    if (i == n) return;

    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        j--;
    }

    insertion_sort_recursive(arr, i + 1, n);
}



int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	insertion_sort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	
	return 0;
}