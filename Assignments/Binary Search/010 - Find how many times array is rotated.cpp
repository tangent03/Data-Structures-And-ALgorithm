#include <bits/stdc++.h>
using namespace std;

/*
 * Function to determine the number of times a sorted array is rotated
 * Time Complexity: O(log N) where N is the size of the array
 * Space Complexity: O(1)
 */
int timesArrayIsRotated(vector<int> &arr) {
    int low = 0;
    int n = arr.size();
    int high = n - 1;
    int ans = INT_MAX;
    int index = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If the array is already sorted, the minimum element is at index `low`
        if (arr[low] <= arr[high]) {
            if (arr[low] <= ans) {
                index = low;
                ans = arr[low];
            }
            break;
        }

        // Check if the left half is sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= ans) {
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        } else { // Otherwise, the right half is sorted
            if (arr[mid] <= ans) {
                index = mid;
                ans = arr[mid];
            }
            high = mid - 1;
        }
    }
    // Return the index of the minimum element, which is the number of rotations
    return index;
}

int main() {
    vector<int> arr = {15, 18, 2, 3, 6, 12};
    int rotations = timesArrayIsRotated(arr);
    cout << "The array is rotated " << rotations << " times." << endl;
    return 0;
}
