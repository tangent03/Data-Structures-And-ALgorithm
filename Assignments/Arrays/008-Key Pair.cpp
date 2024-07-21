								//JAI SHREE RAM
								//JAI BAJRANGBALI
								//OM NAMAH SHIVAYE
								
			//TIME COMPLEXITY - O(N)
			//SPACE COMPLEXITY - O(1)
			
			
//QUESTION : - Find The Union And Intersection Of Two SORTED arrays.

//IN INTERVIEWS - GO FROM BRUTE FORCE SOLUTION -> BETTER SOLUTION -> OPTIMAL SOLUTION


//so in this we are making start as 0 and end as n-1
//and then add first and last and compare if total sum is large reduce end--
//if sum is less start++. if same return true;


//THIS IS KEY PAIR SOLUTION NOT TWO SUM
#include <bits/stdc++.h>
using namespace std;

//brute force

bool twoSumProblem(int arr[],int n,int k){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]+arr[j]==k){
				return true;
			}
		}
	}
	return false;
}

bool twoPointerSolution(int arr[],int n,int k){
	//isse phele sort krlena O(NlogN);
	int start=0;
	int end=n-1;
	sort(arr,arr+n);
	while(start<end){
		if(arr[start] + arr[end] == k){
			return true;
		}
		else if(arr[start] + arr[end] > k){
			end--;
		}
		else{
			start++;
		}
	
	}
	return false;
}

int main() {
	int n;
	cin>>n;
	int k;
	cin>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	bool answer = twoPointerSolution(arr,n,k);
	
	
	cout<<" Do Two Sum Pair Exist? "<<answer<<endl;
	return 0;
    
}

