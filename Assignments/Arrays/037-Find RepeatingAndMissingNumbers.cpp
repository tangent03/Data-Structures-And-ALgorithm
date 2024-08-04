#include <bits/stdc++.h>
using namespace std;

/* Optimal Solution */

/*
Time Complexity: O(N), where N is the size of the array.
Reason: We traverse the array once to build the hash table and once to find the missing and repeating numbers.

Space Complexity: O(N), where N is the size of the array.
Reason: We use an additional hash table of size N+1.
*/

vector<int> findMissingRepeatingNumbersOptimal(vector<int> &a) {
    int n = a.size();
    vector<int> hash(n + 1, 0); // Initialize hash table with zeros
    for (int i = 0; i < n; i++) {
        hash[a[i]]++;
    }
    int repeating = -1;
    int missing = -1;
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 2) {
            repeating = i;
        } else if (hash[i] == 0) {
            missing = i;
        }
        if (repeating != -1 && missing != -1) {
            break;
        }
    }
    return {repeating, missing};
}

/* Brute Force Solution */

/*
Time Complexity: O(N^2), where N is the size of the array.
Reason: We use a nested loop to count occurrences of each number.

Space Complexity: O(1), as we are not using any extra space.
*/

vector<int> findMissingRepeatingNumbersBruteForce(vector<int> &a) {
    int n = a.size(); // size of the array
    int repeating = -1, missing = -1;

    // Find the repeating and missing number:
    for (int i = 1; i <= n; i++) {
        // Count the occurrences:
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == i) cnt++;
        }

        if (cnt == 2) repeating = i;
        else if (cnt == 0) missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};
}

int main() {
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};

    // Optimal Solution
    vector<int> ansOptimal = findMissingRepeatingNumbersOptimal(a);
    cout << "The repeating and missing numbers (Optimal) are: {"
         << ansOptimal[0] << ", " << ansOptimal[1] << "}\n";

    // Brute Force Solution
    vector<int> ansBruteForce = findMissingRepeatingNumbersBruteForce(a);
    cout << "The repeating and missing numbers (Brute Force) are: {"
         << ansBruteForce[0] << ", " << ansBruteForce[1] << "}\n";

    return 0;
}
