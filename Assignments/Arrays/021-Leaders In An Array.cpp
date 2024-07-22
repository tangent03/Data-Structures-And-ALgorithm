#include <bits/stdc++.h>
using namespace std;

/*
 * Function to find the superior elements in an array.
 * A superior element is defined as an element that is greater than 
 * all elements to its right.
 * 
 * Time Complexity: O(N), where N is the size of the array. The array 
 * is traversed once from right to left.
 * 
 * Space Complexity: O(N) due to the use of the ans vector to store 
 * the superior elements.
 */
vector<int> superiorElements(vector<int>& arr) {
    vector<int> ans; // Vector to store superior elements.
    int maxi = INT_MIN; // Initialize the maximum value to a very small number.
    int n = arr.size(); // Get the size of the array.

    // Traverse the array from right to left.
    for (int i = n - 1; i >= 0; i--) {
        // If the current element is greater than the maximum 
        //value seen so far,
        // it is a superior element.
        if (arr[i] > maxi) {
            ans.push_back(arr[i]);
        }
        // Update the maximum value seen so far.
        maxi = max(maxi, arr[i]);
    }

    // Sort the resulting superior elements.
    sort(ans.begin(), ans.end());
    
    return ans;
}

int main() {
    vector<int> arr = {2, 3, 1, 4, 5};
    vector<int> result = superiorElements(arr);
    
    cout << "Superior elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
