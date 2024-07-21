


#include <bits/stdc++.h>
using namespace std;


/*
Brute force 

Isme Hum ek temp array banaenge aur non zero values ko 
daal denge fir duabra temp ko arr me copy kr denge aur baaki ke
 values ko zero krdenge 
 
 
 
  
 
 Time Complexity: O(N) + O(X) + O(N-X) ~ O(2*N), where N = total no. 
 of elements,
 
 
X = no. of non-zero elements, and N-X = total no. of zeros.
Reason: O(N) for copying non-zero elements from the original 
to the temporary array. O(X) for again copying it back from the temporary to the original array. O(N-X) for filling zeros in the original array. So, the total time complexity will be O(2*N).



Space Complexity: O(N), as we are using a temporary array to solve
 this problem and the maximum size of the array can be N in the 
 worst case.
 
 
Reason: The temporary array stores the non-zero elements. In the
 worst case, all the given array elements will be non-zero.




*/
vector<int> moveZeros(int n, vector<int> a){
	vector<int>temp;
	
	for(int i=0;i<n;i++){
		if(a[i] != 0){
			temp.push_back(a[i]);	
		}
	}
	
	int tempSize = temp.size();
	for(int i=0;i<tempSize;i++){
		a[i]=temp[i];
	}
	for(int i=tempSize ; i<n;i++){
		a[i]=0;
	}
	return a;
	
}

//Optimal Solution

/*

Time Complexity: O(N), N = size of the array.
Reason: We have used 2 loops and using those loops, we are basically 
traversing the array once.

Space Complexity: O(1) as we are not using any extra space to 
solve this problem.


*/


vector<int> moveZeroes(int n,vector<int>& nums) {
       int j=0;
       
       for(int i=0;i<n;i++){
        if(nums[i] != 0){
            swap(nums[i],nums[j]);
            j++;
        }
       }
        return nums;
    }



int main()
{
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = 10;
     for (auto &it : arr) {
        cout << it << " ";
    }
    cout << '\n';
    vector<int> ans = moveZeroes(n, arr);
    for (auto &it : ans) {
        cout << it << " ";
    }
    cout << '\n';
    return 0;
}


