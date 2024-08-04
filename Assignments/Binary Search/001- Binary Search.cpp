#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity:
In the algorithm, in every step, we are basically
dividing the search space into 2 equal halves. This is
actually equivalent to dividing the size of the array by 2,
every time. After a certain number of divisions, the size
will reduce to such an extent that we will not be able to
divide that anymore and the process will stop. The number
of total divisions will be equal to the time complexity.

Let’s derive the number of divisions mathematically,

If a number n can be divided by 2 for x times:
2^x = n

Therefore, x = log(n) (base 2)

So the overall time complexity is O(logN), where N = size of the given array.
*/

// Iterative binary search function
int binarySearch(vector<int> &nums, int target) {
    int n = nums.size(); // Get the size of the array
    int low = 0;         // Initialize the low pointer
    int high = n - 1;    // Initialize the high pointer

    // Perform the binary search
    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate the mid index to prevent overflow
        if (nums[mid] == target) {
            return mid; // Target found at index mid
        } else if (target > nums[mid]) {
            low = mid + 1; // Target is on the right half
        } else {
            high = mid - 1; // Target is on the left half
        }
    }
    return -1; // Target not found
}

//------------------------------------------------------

/*
Now recursive code
*/

// Recursive binary search function
int binarySearchRecursive(vector<int> &nums, int low, int high, int target) {
    if (low > high) {
        return -1; // Base case: target not found
    }

    int mid = low + (high - low) / 2; // Calculate the mid index to prevent overflow

    if (nums[mid] == target) {
        return mid; // Target found at index mid
    } else if (target > nums[mid]) {
        return binarySearchRecursive(nums, mid + 1, high, target); // Search in the right half
    }
    return binarySearchRecursive(nums, low, mid - 1, target); // Search in the left half
}

// Helper function to call recursive binary search
int search(vector<int> &nums, int target) {
    return binarySearchRecursive(nums, 0, nums.size() - 1, target);
}

int main() {
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17}; // Sample sorted array
    int target = 6; // Target element to search
    int ind = binarySearch(a, target); // Call the iterative binary search
    if (ind == -1) {
        cout << "The target is not present." << endl; // Target not found
    } else {
        cout << "The target is at index: " << ind << endl; // Target found at index ind
    }

    // Test the recursive binary search
    ind = search(a, target);
    if (ind == -1) {
        cout << "The target is not present." << endl; // Target not found
    } else {
        cout << "The target is at index: " << ind << endl; // Target found at index ind
    }
    return 0;
}
