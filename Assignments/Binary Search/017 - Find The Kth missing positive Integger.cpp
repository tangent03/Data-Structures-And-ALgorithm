#include <bits/stdc++.h>
using namespace std;

/*
 * Brute Force Solution
 *
 * Time Complexity: O(N), where N is the size of the vector.
 * Reason: We are iterating through the entire vector and adjusting the value of k accordingly.
 *
 * Space Complexity: O(1) as we are not using any extra space.
 */
int missingKBruteForce(vector<int> vec, int n, int k) {
    for (int i = 0; i < n; i++) {
        if (vec[i] <= k) {
            k++; // Increment k when vec[i] is less than or equal to k
        } else {
            break; // Break the loop if vec[i] is greater than k
        }
    }
    return k;
}

/*
 * Optimal Solution using Binary Search
 *
 * Time Complexity: O(log N), where N is the size of the vector.
 * Reason: We are using binary search to find the correct position.
 *
 * Space Complexity: O(1) as we are not using any extra space.
 */
int missingKOptimal(vector<int> vec, int n, int k) {
    int low = 0, high = n - 1;
    
    // Apply binary search to find the correct position
    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        
        // If missing numbers until mid are less than k, move right
        if (missing < k) {
            low = mid + 1;
        } else { // Otherwise, move left
            high = mid - 1;
        }
    }
    // Return the k-th missing number
    return k + high + 1;
}

int main() {
    vector<int> vec = {4, 7, 9, 10};
    int n = vec.size(); // Size of the vector
    int k = 4; // k-th missing number to find

    // Using the optimal solution
    int ansOptimal = missingKOptimal(vec, n, k);
    cout << "The missing number using the optimal solution is: " << ansOptimal << "\n";

    // Using the brute force solution
    int ansBruteForce = missingKBruteForce(vec, n, k);
    cout << "The missing number using the brute force solution is: " << ansBruteForce << "\n";

    return 0;
}
