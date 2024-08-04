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

    // Binary search loop
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If the middle element is the target, return its index
        if (arr[mid] == k) {
            return mid;
        }

        // Edge case: all elements in the current range are equal
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low + 1;
            high = high - 1;
            continue;
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

    // If the element is not found, return -1
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

// Time complexity: O(log n) in the average case, O(n) in the worst case (due to edge case handling)
// Space complexity: O(1)