#include <bits/stdc++.h>
using namespace std;

/*
Brute Force Approach

Time Complexity: O(N^3 * log(unique_triplets)), where N = size of the array.
Reason: We are using 3 nested loops to check all possible triplets.
Inserting triplets into the set takes O(log(unique_triplets)) time complexity.
But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.

Space Complexity: O(2 * unique_triplets) as we are using a set data structure and a list to store the triplets.
*/

vector<vector<int>> tripletBruteForce(int n, vector<int> &arr) {
    set<vector<int>> st;

    // Check all possible triplets
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end()); // Sort the triplet
                    st.insert(temp); // Insert the sorted triplet into the set
                }
            }
        }
    }

    // Store the set elements in the answer
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

/*
Optimal Solution using Two Pointers

Time Complexity: O(N^2), where N = size of the array.
Reason: Sorting the array takes O(N log N) and we are using a nested loop with two pointers, each running in O(N) time.

Space Complexity: O(unique_triplets) to store the result.
*/

vector<vector<int>> tripletOptimal(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end()); // Sort the array

    for (int i = 0; i < n; i++) {
        // Skip duplicates for the first element
        if (i != 0 && arr[i] == arr[i - 1]) {
            continue;
        }

        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            } else if (sum > 0) {
                k--;
            } else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp); // Add the triplet to the result
                j++;
                k--;

                // Skip duplicates for the second and third elements
                while (j < k && arr[j] == arr[j - 1]) {
                    j++;
                }
                while (j < k && arr[k] == arr[k + 1]) {
                    k--;
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();

    cout << "Brute Force Approach: ";
    vector<vector<int>> ansBruteForce = tripletBruteForce(n, arr);
    for (auto it : ansBruteForce) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";

    cout << "Optimal Approach: ";
    vector<vector<int>> ansOptimal = tripletOptimal(n, arr);
    for (auto it : ansOptimal) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";

    return 0;
}
