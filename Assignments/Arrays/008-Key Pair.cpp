#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

// Function to calculate GCD of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to find the sum of GCDs of all subsets
int sumOfGcdOfSubsets(vector<int>& arr) {
    int n = arr.size();
    int totalSum = 0;
    
    // Loop over all possible subsets
    for (int i = 1; i < (1 << n); i++) {
        int subsetGcd = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subsetGcd = __gcd(subsetGcd, arr[j]);
            }
        }
        totalSum = (totalSum + subsetGcd) % MOD;
    }
    
    return totalSum;
}

int main() {
    vector<int> arr = {2,3,4};
    cout << sumOfGcdOfSubsets(arr) << endl; // Output for the provided input
    return 0;
}
