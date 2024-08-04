#include <bits/stdc++.h>
using namespace std;

/*
 * Brute Force Approach
 * Time Complexity: O(N), where N is the size of the array.
 * Reason: We traverse the entire array once to find a peak element.
 * Space Complexity: O(1)
 */
int findPeakElementBruteForce(vector<int> &arr) {
    int n = arr.size(); // Size of the array.

    for (int i = 0; i < n; i++) {
        // Check if the current element is a peak.
        if ((i == 0 || arr[i - 1] < arr[i])
                && (i == n - 1 || arr[i] > arr[i + 1])) {
            return i;
        }
    }
    // Dummy return statement
    return -1;
}

/*
 * Optimal Solution using Binary Search
 * Time Complexity: O(log N), where N is the size of the array.
 * Reason: We are using binary search to find the peak element.
 * Space Complexity: O(1)
 */
int findPeakElementOptimal(vector<int> &arr) {
    int n = arr.size();
    // Edge cases for single element and boundary elements.
    if (n == 1) {
        return 0;
    }
    if (arr[0] > arr[1]) {
        return 0;
    }
    if (arr[n - 1] > arr[n - 2]) {
        return n - 1;
    }

    int low = 1;
    int high = n - 2;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if arr[mid] is the peak.
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
            return mid;
        }

        // If the left neighbor is less, the peak must be on the right side.
        if (arr[mid] > arr[mid - 1]) {
            low = mid + 1;
        }
        // If the left neighbor is greater, the peak must be on the left side.
        else {
            high = mid - 1;
        }
    }
    return -1; // Dummy return statement.
}

int main() {
    vector<int> arr = {1, 2, 1, 3, 5, 6, 4};

    // Using Brute Force Approach
    int peakIndexBruteForce = findPeakElementBruteForce(arr);
    cout << "Peak element index using Brute Force is: " << peakIndexBruteForce << "\n";

    // Using Optimal Solution
    int peakIndexOptimal = findPeakElementOptimal(arr);
    cout << "Peak element index using Optimal Solution is: " << peakIndexOptimal << "\n";

    return 0;
}
