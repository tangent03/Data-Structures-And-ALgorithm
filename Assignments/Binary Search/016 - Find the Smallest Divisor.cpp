#include <bits/stdc++.h>
using namespace std;

/*
 * Brute Force Solution
 *
 * Time Complexity: O(max(arr) * N), where N is the size 
 of the array.
 * Reason: We are iterating over all possible divisors
  from 1 to the maximum element in the array, 
 * and for each divisor, we are summing up the ceiling
  values for all elements in the array.
 *
 * Space Complexity: O(1) as we are not using any extra space.
 */
int smallestDivisorBruteForce(vector<int>& arr, int limit) {
    int n = arr.size(); // size of the array
    int maxi = *max_element(arr.begin(), arr.end()); // Find the maximum element in the array

    // Iterate over all possible divisors from 1 to the maximum element
    for (int d = 1; d <= maxi; d++) {
        int sum = 0;
        // Calculate the sum of the ceilings for the current divisor
        for (int i = 0; i < n; i++) {
            sum += ceil((double)(arr[i]) / (double)(d));
        }
        // If the sum is within the limit, return the current divisor
        if (sum <= limit)
            return d;
    }
    return -1; // Return -1 if no divisor satisfies the condition
}

/*
 * Function to calculate the sum of the ceilings of elements 
 divided by a given divisor
 
 * Time Complexity: O(N), where N is the size of the array.
 * Space Complexity: O(1)
 */
int sumByD(vector<int> &arr, int div) {
    int n = arr.size();
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += ceil((double)(arr[i]) / (double)(div)); // Sum the ceilings of the divisions
    }
    return sum;
}

/*
 * Optimal Solution using Binary Search
 *
 * Time Complexity: O(N * log(max(arr))), where N is the size of the array.
 * Reason: We are using binary search over the range of possible 
 divisors, and for each 
 * midpoint in the search, we are calculating the sum using the 
 sumByD function.
 *
 * Space Complexity: O(1) as we are not using any extra space.
 */
int smallestDivisorOptimal(vector<int> &arr, int limit) {
    int n = arr.size();
    if (n > limit) {
        return -1; // Impossible case, if the number of elements is greater than the limit
    }

    int low = 1;
    int high = *max_element(arr.begin(), arr.end()); // Find the maximum element in the array

    // Apply binary search over the range of possible divisors
    while (low <= high) {
        int mid = (low + high) / 2;
        if (sumByD(arr, mid) <= limit) {
            high = mid - 1; // Try to find a smaller valid divisor
        } else {
            low = mid + 1; // Increase the divisor
        }
    }
    return low; // The smallest divisor that satisfies the condition
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5}; // Sample array
    int limit = 8; // Sum limit
    int ans = smallestDivisorOptimal(arr, limit); // Find the smallest divisor
    cout << "The minimum divisor is: " << ans << "\n"; // Print the result
    return 0;
}
