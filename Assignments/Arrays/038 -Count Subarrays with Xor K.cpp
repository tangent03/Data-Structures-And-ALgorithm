#include <bits/stdc++.h>
using namespace std;

/* 
Brute Force Solution:

Time Complexity: O(N^2), where N is the size of the array.
Reason: We use two nested loops to generate all possible subarrays and calculate their XOR.

Space Complexity: O(1) as we are not using any extra space.
*/

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); // size of the given array
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        int xorr = 0;
        for (int j = i; j < n; j++) {
            // Step 2: Calculate XOR of all elements:
            xorr = xorr ^ a[j];

            // Step 3: Check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}

/*
Optimal Solution:

Time Complexity: O(N), where N is the size of the array.
Reason: We traverse the array once, and each operation (insertion, lookup) in the map takes O(1) on average.

Space Complexity: O(N) due to the hashmap used to store XOR values.

*/

int subarraysWithXorK(vector<int>& A, int B) {
    int n = A.size();
    unordered_map<int, int> freq;
    int xorSum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        xorSum ^= A[i];

        // If the current xorSum is equal to B, increment count
        if (xorSum == B) {
            count++;
        }

        // Calculate the value of xorSum ^ B
        int y = xorSum ^ B;

        // If y exists in the map, add its frequency to the count
        if (freq.find(y) != freq.end()) {
            count += freq[y];
        }

        // Increment the frequency of the current xorSum in the map
        freq[xorSum]++;
    }

    return count;
}

int main() {
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;

    // Brute Force Solution:
    int ansBrute = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k (Brute Force) is: " << ansBrute << "\n";

    // Optimal Solution:
    int ansOptimal = subarraysWithSumK(a, k);
    cout << "The number of subarrays with XOR k (Optimal) is: " << ansOptimal << "\n";

    return 0;
}
