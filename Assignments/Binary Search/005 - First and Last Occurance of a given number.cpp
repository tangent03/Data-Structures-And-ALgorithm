#include <bits/stdc++.h>
using namespace std;

/*
 * Function to find the last occurrence of a key in a sorted vector
 * Time Complexity: O(log N) where N is the size of the vector
 * Space Complexity: O(1)
 */
int lastOccurance(int n, int key, vector<int> &v) {
    int start = 0;
    int end = n - 1;
    int res = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2; // Calculate mid to prevent overflow

        if (v[mid] == key) {
            res = mid; // Update the result to the current mid
            start = mid + 1; // Move to the right half to find the last occurrence
        } else if (key < v[mid]) {
            end = mid - 1; // Move to the left half
        } else {
            start = mid + 1; // Move to the right half
        }
    }
    return res;
}

/*
 * Function to find the first occurrence of a key in a sorted vector
 * Time Complexity: O(log N) where N is the size of the vector
 * Space Complexity: O(1)
 */
int firstOccurance(int n, int key, vector<int> &v) {
    int start = 0;
    int end = n - 1;
    int res = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2; // Calculate mid to prevent overflow

        if (v[mid] == key) {
            res = mid; // Update the result to the current mid
            end = mid - 1; // Move to the left half to find the first occurrence
        } else if (key < v[mid]) {
            end = mid - 1; // Move to the left half
        } else {
            start = mid + 1; // Move to the right half
        }
    }
    return res;
}

int main() {
    vector<int> v = {1, 2, 2, 2, 3, 4, 5}; // Sample sorted vector
    int n = v.size();
    int key = 2; // Key to find the first and last occurrence

    int first = firstOccurance(n, key, v); // Find first occurrence
    int last = lastOccurance(n, key, v);   // Find last occurrence

    cout << "First Occurrence of " << key << " is at index: " << first << endl;
    cout << "Last Occurrence of " << key << " is at index: " << last << endl;

    return 0;
}
