


#include <bits/stdc++.h>
using namespace std;


/*
Brute Force Approach


Time Complexity: O(N), N = size of the given array.
Reason: We are traversing the entire array.

Space Complexity: O(1) as we are not using any extra space.

*/
int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); //size of the array.
    if (n == 1) return arr[0];

    for (int i = 0; i < n; i++) {

        //Check for first index:
        if (i == 0) {
            if (arr[i] != arr[i + 1])
                return arr[i];
        }
        //Check for last index:
        else if (i == n - 1) {
            if (arr[i] != arr[i - 1])
                return arr[i];
        }
        else {
            if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
                return arr[i];
        }
    }

    // dummy return statement:
    return -1;
}

/*

XOR METHOD
Time Complexity: O(N), N = size of the given array.
Reason: We are traversing the entire array.

Space Complexity: O(1) as we are not using any extra space.

*/
int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); //size of the array.
    int ans = 0;
    // XOR all the elements:
    for (int i = 0; i < n; i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}


/*
 Optimal Solution - Binary Search

*/

int singleNonDuplicate(vector<int &arr){
	
	int n = arr.size();
	
	//edge cases
	if(n==1){
		return arr[0];
	}
	if(arr[0] != arr[1]){
		return arr[0];
	}
	if(arr[n-1] != arr[n-2]){
		return arr[n-1];
	}
	
	int low = 1;
	int high = n-2;
	
	while(low<=high){
		int mid = low + (high - low)/2;
		
		
		//if arr[mid] is the single element
		if(arr[mid] != arr[mid + 1] && arr[mid] != arr[mid-1]){
			return arr[mid];
		}
		
		//we are int the left
		if((mid % 2 == 1 && arr[mid] == arr[mid - 1]) 
			|| (mid % 2 == 0 && arr[mid] == arr[mid+1])){
				//eliminate the left half
				low = mid + 1;
		}
		// we are in right
		else{
			high = mid - 1;
		}
			
	}
	return -1;
	
}
#include <bits/stdc++.h>
using namespace std;

/*
Brute Force Approach
Time Complexity: O(N), N = size of the given array.
Reason: We are traversing the entire array.
Space Complexity: O(1) as we are not using any extra space.
*/
int singleNonDuplicateBruteForce(vector<int>& arr) {
    int n = arr.size(); // size of the array.
    if (n == 1) return arr[0];

    for (int i = 0; i < n; i++) {
        // Check for the first index:
        if (i == 0) {
            if (arr[i] != arr[i + 1])
                return arr[i];
        }
        // Check for the last index:
        else if (i == n - 1) {
            if (arr[i] != arr[i - 1])
                return arr[i];
        }
        // Check for middle indices:
        else {
            if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
                return arr[i];
        }
    }
    return -1; // Should never reach here
}

/*
XOR Method
Time Complexity: O(N), N = size of the given array.
Reason: We are traversing the entire array.
Space Complexity: O(1) as we are not using any extra space.
*/
int singleNonDuplicateXOR(vector<int>& arr) {
    int n = arr.size(); // size of the array.
    int ans = 0;
    // XOR all the elements:
    for (int i = 0; i < n; i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}

/*
Optimal Solution - Binary Search
Time Complexity: O(log N), N = size of the given array.
Reason: We are using binary search to find the single element.
Space Complexity: O(1) as we are not using any extra space.
*/
int singleNonDuplicateBinarySearch(vector<int>& arr) {
    int n = arr.size();
    
    // Edge cases
    if (n == 1) {
        return arr[0];
    }
    if (arr[0] != arr[1]) {
        return arr[0];
    }
    if (arr[n - 1] != arr[n - 2]) {
        return arr[n - 1];
    }
    
    int low = 1;
    int high = n - 2;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // If arr[mid] is the single element
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid];
        }
        
        // We are in the left side
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || 
            (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            low = mid + 1;
        } 
        // We are in the right side
        else {
            high = mid - 1;
        }
    }
    return -1; // Should never reach here
}

int main() {
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};

    // Using Brute Force Approach
    int ansBruteForce = singleNonDuplicateBruteForce(arr);
    cout << "The single element using Brute Force is: " << ansBruteForce << "\n";

    // Using XOR Method
    int ansXOR = singleNonDuplicateXOR(arr);
    cout << "The single element using XOR is: " << ansXOR << "\n";

    // Using Binary Search
    int ansBinarySearch = singleNonDuplicateBinarySearch(arr);
    cout << "The single element using Binary Search is: " << ansBinarySearch << "\n";

    return 0;
}


int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = singleNonDuplicate(arr);
    cout << "The single element is: " << ans << "\n";
    return 0;
}

