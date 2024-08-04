#include <bits/stdc++.h>
using namespace std;

/*
 * Function to find the nth root of a number m using binary search
 * Time Complexity: O(log m * n)
 * Reason: We are using binary search to find the nth root, and for each mid, we calculate the power which takes O(n) time.
 * Space Complexity: O(1)
 */
int nthRoot(int n, int m) {
    int low = 1;
    int high = m;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Calculate mid^n (mid to the power of n)
        long long power = 1;
        for (int i = 0; i < n; i++) {
            power *= mid;
            if (power > m) break; // No need to continue if power exceeds m
        }

        if (power == m) {
            return mid;
        }
        if (power > m) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1; // If no integer nth root found
}

int main() {
    int n = 3;
    int m = 27;
    int result = nthRoot(n, m);
    cout << "The " << n << "th root of " << m << " is: " << result << endl;
    return 0;
}
