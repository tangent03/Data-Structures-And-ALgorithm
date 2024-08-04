#include <bits/stdc++.h>
using namespace std;

/**
 * Searches for an element in a rotated sorted array using binary search.
 *
 * @param arr The input array.
 * @param n The size of the array.
 * @param k The element to search for.
 * @return The index of the element if found, -1 otherwise.
 */
int searchElementInRotatedSortedArray(vector<int> &arr, int n, int k) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == k) {
            return mid;
        }

        // Check if the left half is sorted
        if (arr[low] <= arr[mid]) {
            // If k is in the range of the left half, update high
            if (arr[low] <= k && k < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            // If k is in the range of the right half, update low
            if (arr[mid] < k && k <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    // Example usage:
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int n = arr.size();
    int k = 0;

    int result = searchElementInRotatedSortedArray(arr, n, k);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}