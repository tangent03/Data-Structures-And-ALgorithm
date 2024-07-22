#include <bits/stdc++.h>
using namespace std;

/*
Brute Force Approach:

Time Complexity: O(N^2) approx., where N = size of the array.
Reason: We are using two nested loops, each running approximately N times.

Space Complexity: O(1) as we are not using any extra space.
*/

int maxSubarraySumBruteForce(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) { // starting index
        long long s = 0; // Sum variable
        for (int j = i; j < n; j++) { // ending index
            s += arr[j]; // add the current element to the subarray a[i...j]
            if (s == k)
                maxi = max(maxi, j - i + 1); // update the max length
        }
    }
    return maxi;
}

/*
Optimized Approach using Kadane's Algorithm:

Time Complexity: O(N), where N = size of the array.
Reason: We are using a single loop to traverse the array.

Space Complexity: O(1) as we are not using any extra space.
*/

long long maxSubarraySumKadane(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    return maxi;
}

/*
Kadane's Algorithm with Subarray Printing:

Time Complexity: O(N), where N = size of the array.
Reason: We are using a single loop to traverse the array.

Space Complexity: O(1) as we are not using any extra space.
*/

long long maxSubarraySumWithPrinting(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0; // start index of the subarray
    int ansStart = -1, ansEnd = -1; // to store the final start and end indices

    for (int i = 0; i < n; i++) {
        if (sum == 0) start = i; // update the start index when sum is reset

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    // Printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;

    return maxi;
}

int main() {
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Call Brute Force Method
    int maxSumBruteForce = maxSubarraySumBruteForce(arr, n);
    cout << "The maximum subarray sum (Brute Force) is: " << maxSumBruteForce << endl;
    
    // Call Kadane's Algorithm
    long long maxSumKadane = maxSubarraySumKadane(arr, n);
    cout << "The maximum subarray sum (Kadane's Algorithm) is: " << maxSumKadane << endl;

    // Call Kadane's Algorithm with Subarray Printing
    long long maxSumWithPrinting = maxSubarraySumWithPrinting(arr, n);
    cout << "The maximum subarray sum (with printing) is: " << maxSumWithPrinting << endl;

    return 0;
}
