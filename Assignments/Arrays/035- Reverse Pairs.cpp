#include <bits/stdc++.h>
using namespace std;

/*
Brute Force Solution

Time Complexity: O(N^2), where N is the size of the array.
Reason: We are using two nested loops, each running approximately N times.

Space Complexity: O(1) as we are not using any extra space.
*/

int countPairs(vector<int>& a, int n) {
    // Count the number of reverse pairs
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > 2 * a[j]) cnt++;
        }
    }
    return cnt;
}

int team(vector<int> &skill, int n) {
    return countPairs(skill, n);
}

/*
Optimal Solution using Merge Sort

Time Complexity: O(N log N), where N is the size of the array.
Reason: We are using merge sort which divides the array and processes each part in logarithmic time.

Space Complexity: O(N) due to the temporary arrays used during merge sort.
*/

class Solution {
public:
    // Function to merge two halves of the array
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; // Temporary array
        int left = low;   // Starting index of the left half of arr
        int right = mid + 1; // Starting index of the right half of arr

        // Storing elements in the temporary array in sorted manner
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // If elements on the left half are still left
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // If elements on the right half are still left
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // Transferring all elements from temporary array to arr
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    // Function to count the important reverse pairs
    int countPairs(vector<int> &arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > 2LL * arr[right]) {  // 2LL to avoid overflow
                right++;
            }
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    // Function to perform merge sort and count reverse pairs
    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);      // Left half
        cnt += mergeSort(arr, mid + 1, high); // Right half
        cnt += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);  // Merging sorted halves
        return cnt;
    }

    // Main function to count reverse pairs
    int reversePairs(vector<int> &nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};

int main() {
    vector<int> a = {4, 1, 2, 3, 1};
    int n = a.size();

    // Brute force solution
    int cnt = team(a, n);
    cout << "The number of reverse pairs (Brute Force): " << cnt << endl;

    // Optimal solution
    Solution sol;
    int optimalCnt = sol.reversePairs(a);
    cout << "The number of reverse pairs (Optimal): " << optimalCnt << endl;

    return 0;
}
