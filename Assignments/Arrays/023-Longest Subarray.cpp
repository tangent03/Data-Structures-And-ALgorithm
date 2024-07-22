#include <bits/stdc++.h>
using namespace std;

/*
Brute Force Approach:

Time Complexity: O(N^2) approx., where N = size of the array.
Reason: We are using two nested loops, each running approximately N times.

Space Complexity: O(1) as we are not using any extra space.
*/

int getLongestSubarrayBruteForce(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.
    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        long long s = 0; // Sum variable
        for (int j = i; j < n; j++) { // ending index
            s += a[j]; // add the current element to the subarray a[i...j]
            if (s == k)
                len = max(len, j - i + 1); // update the max length
        }
    }
    return len;
}

/*
Optimized Approach using Two Pointers (for positive numbers):

Time Complexity: O(N), where N = size of the array.
Reason: We are using a single loop to traverse the array with two pointers.

Space Complexity: O(1) as we are not using any extra space.
*/

int getLongestSubarrayTwoPointers(vector<int>& a, long long k) {
    int n = a.size();
    int left = 0; // left pointer
    int right = 0; // right pointer
    int maxLen = 0; // variable to store the maximum length of subarray
    long long sum = a[0]; // initialize sum with the first element

    while (right < n) {
        // if sum > k, reduce the subarray from the left
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }
        // if sum = k, update the maxLen i.e. answer
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        // Move forward the right pointer
        right++;
        if (right < n) sum += a[right];
    }
    return maxLen;
}

/*
Optimized Approach using HashMap (for both positive and negative numbers):

Time Complexity: O(N), where N = size of the array.
Reason: We are using a single loop to traverse the array and a hashmap to store prefix sums.

Space Complexity: O(N) due to the hashmap used to store prefix sums.
*/

int getLongestSubarrayHashMap(vector<int>& a, long long k) {
    map<long long, int> preSumMap; // hashmap to store prefix sums and their indices
    long long sum = 0;
    int maxLen = 0; // variable to store the maximum length of subarray
    for (int i = 0; i < a.size(); i++) {
        sum = sum + a[i]; // update the prefix sum
        if (sum == k) {
            maxLen = max(maxLen, i + 1); // if sum equals k, update maxLen
        }
        long long rem = sum - k; // calculate the remaining sum
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem]; // calculate the length of subarray
            maxLen = max(maxLen, len); // update maxLen if needed
        }
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i; // store the prefix sum and its index
        }
    }
    return maxLen;
}

int main() {
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    
    // Using Brute Force Approach
    int lenBruteForce = getLongestSubarrayBruteForce(a, k);
    cout << "The length of the longest subarray (Brute Force) is: " << lenBruteForce << "\n";
    
    // Using Two Pointers Approach
    int lenTwoPointers = getLongestSubarrayTwoPointers(a, k);
    cout << "The length of the longest subarray (Two Pointers) is: " << lenTwoPointers << "\n";
    
    // Using HashMap Approach
    int lenHashMap = getLongestSubarrayHashMap(a, k);
    cout << "The length of the longest subarray (HashMap) is: " << lenHashMap << "\n";
    
    return 0;
}
