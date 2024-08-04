#include <bits/stdc++.h>
using namespace std;

/*
 * Function to find the floor of the square root of a given number n
 * Time Complexity: O(log n)
 * Reason: We are using binary search to find the floor square root.
 * Space Complexity: O(1)
 */
int floorSQRT(int n) {
    // If n is 0 or 1, return n as the square root of 0 and 1 is themselves
    if (n == 0 || n == 1) {
        return n;
    }
    
    int low = 1;
    int high = n;
    int ans = 0; // Variable to store the result

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long val = mid * mid; // Calculate mid squared

        if (val == n) { // If mid*mid equals n, we've found the exact square root
            return mid;
        } else if (val < n) { // If mid*mid is less than n, move to the right half
            low = mid + 1;
            ans = mid; // Update ans to mid, as mid*mid is less than n
        } else { // If mid*mid is greater than n, move to the left half
            high = mid - 1;
        }
    }

    return ans; // Return the floor of the square root
}

int main() {
    int n = 10;
    int result = floorSQRT(n);
    cout << "The floor square root of " << n << " is: " << result << endl;
    return 0;
}
