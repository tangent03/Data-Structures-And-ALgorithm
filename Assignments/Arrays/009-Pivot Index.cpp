								//JAI SHREE RAM
								//JAI BAJRANGBALI
								//OM NAMAH SHIVAYE
								
			
			
			
//QUESTION : - 
// Given an array of integers nums, calculate the pivot index of this array.
// 
// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
// 
// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
// 
// Return the leftmost pivot index. If no such index exists, return -1.
// 
//  
// 
// Example 1:
// 
// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11
// Example 2:
// 
// Input: nums = [1,2,3]
// Output: -1
// Explanation:
// There is no index that satisfies the conditions in the problem statement.
// Example 3:
// 
// Input: nums = [2,1,-1]
// Output: 0
// Explanation:
// The pivot index is 0.
// Left sum = 0 (no elements to the left of index 0)
// Right sum = nums[1] + nums[2] = 1 + -1 = 0
//  
// 
// Constraints:
// 
// 1 <= nums.length <= 104
// -1000 <= nums[i] <= 1000
//  
// 
// Note: This question is the same as 1991:
#include <bits/stdc++.h>
using namespace std;

//brute force //O(N2)

int bruteForce(int arr[],int n){
	
	for(int i=0;i<n;i++){
		int lsum=0;
		int rsum=0;		
		for(int j=0;j<i;j++){
			lsum=lsum+arr[j];
		}
		for(int j=i+1;j<n;j++){
			rsum=rsum+arr[j];
		}
		
		if(lsum==rsum){
			return i;
		}
	}
	return -1;
} 

//optimisised //o(n)
int prefixSumApproach(int arr[], int n){
	vector<int>lsum(n,0);
	vector<int>rsum(n,0);
	for(int i=1;i<n;i++){
		lsum[i]=lsum[i-1]+arr[i-1];
	}
	for(int i=n-2;i>=0;i--){
		rsum[i]=rsum[i+1] + arr[i+1];
	}
	
	for(int i=0;i<n;i++){
		if(lsum[i]==rsum[i]){
			return i;
		}
	}
	return -1;
}



int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	 cout<<"Brute Force "<<bruteForce(arr,n)<<endl;
	cout<<"Optimised Method "<<prefixSumApproach(arr,n)<<endl;
    
}

