#include <bits/stdc++.h>
using namespace std;

/*
Brute Force Solution

Time Complexity: O(N^2), where N is the size of the array.
Reason: We are using two nested loops, each running approximately N times.

Space Complexity: O(1) as we are not using any extra space.
*/

int numberOfInversionsBruteForce(vector<int>& a, int n) {
    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) cnt++;
        }
    }
    return cnt;
}

/*
Optimal Solution using Merge Sort

Time Complexity: O(N log N), where N is the size of the array.
Reason: We are using merge sort which divides the array and processes each part in logarithmic time.

Space Complexity: O(N) due to the temporary arrays used during merge sort.
*/

int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // Temporary array
    int left = low;   // Starting index of the left half of arr
    int right = mid + 1; // Starting index of the right half of arr
    int cnt = 0; // Count of inversions

    // Storing elements in the temporary array in sorted manner
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); // Counting inversions
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

    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);      // Left half
    cnt += mergeSort(arr, mid + 1, high); // Right half
    cnt += merge(arr, low, mid, high);    // Merging sorted halves
    return cnt;
}

int numberOfInversions(vector<int> &a, int n) {
    return mergeSort(a, 0, n - 1);
}

int main() {
    vector<int> a = {5, 4, 3, 2, 1};
    int n = a.size();

    // Brute force solution
    int bruteForceCnt = numberOfInversionsBruteForce(a, n);
    cout << "The number of inversions (Brute Force) is: " << bruteForceCnt << endl;

    // Optimal solution
    vector<int> b = {5, 4, 3, 2, 1}; // Re-initialize the array as it was modified by the brute force function
    int optimalCnt = numberOfInversions(b, n);
    cout << "The number of inversions (Optimal) is: " << optimalCnt << endl;

    return 0;
}
