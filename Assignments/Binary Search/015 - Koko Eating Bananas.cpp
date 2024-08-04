#include <bits/stdc++.h>
using namespace std;

/*
 * Function to find the maximum value in a vector
 * Time Complexity: O(N), where N is the size of the vector
 * Space Complexity: O(1)
 */
int findMax(const vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    // Find the maximum element in the vector
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

/*
 * Function to calculate the total hours needed to eat all bananas at a given hourly rate
 * Time Complexity: O(N), where N is the size of the vector
 * Space Complexity: O(1)
 */
int calculateTotalHours(const vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    // Calculate the total hours needed to eat all bananas
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

/*
 * Brute Force Approach to find the minimum rate at which Koko should eat bananas to finish within h hours
 * Time Complexity: O(N * max(a[])), where N is the size of the vector and max(a[]) is the maximum element in the vector
 * Space Complexity: O(1)
 */
int minimumRateToEatBananasBruteForce(vector<int> &v, int h) {
    int maxi = findMax(v);  // Find the maximum number
    // Find the minimum value of k
    for (int i = 1; i <= maxi; i++) {
        int reqTime = calculateTotalHours(v, i);
        if (reqTime <= h) {
            return i;
        }
    }
    // Dummy return statement
    return maxi;
}

/*
 * Optimal Solution using Binary Search to find the minimum rate at which Koko should eat bananas to finish within h hours
 * Time Complexity: O(N log M), where N is the size of the vector and M is the maximum element in the vector
 * Space Complexity: O(1)
 */
int minimumRateToEatBananas(vector<int> &v, int h) {
    int low = 1;
    int high = findMax(v);

    // Apply binary search to find the minimum rate
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int totalH = calculateTotalHours(v, mid);
        if (totalH <= h) {
            high = mid - 1; // Try to find a lower rate
        } else {
            low = mid + 1; // Increase the rate
        }
    }
    return low; // The lowest rate that allows Koko to eat all bananas within h hours
}

int main() {
    vector<int> v = {7, 15, 6, 3}; // Piles of bananas
    int h = 8; // Total hours available
    
    // Brute Force Approach
    int ansBruteForce = minimumRateToEatBananasBruteForce(v, h);
    cout << "Koko should eat at least " << ansBruteForce << " bananas/hr using brute force.\n";
    
    // Optimal Solution using Binary Search
    int ansOptimal = minimumRateToEatBananas(v, h);
    cout << "Koko should eat at least " << ansOptimal << " bananas/hr using binary search.\n";
    
    return 0;
}
