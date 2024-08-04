#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size();  // Get the size of the input array.
    
    // Sort the intervals based on the starting times.
    sort(arr.begin(), arr.end());
    
    vector<vector<int>> ans;  // This will store the merged intervals.
    
    for (int i = 0; i < n; i++) {
        // If the answer array is empty or the current interval does not overlap
        // with the last interval in the answer array, add it to the answer array.
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        } else {
            // If the current interval overlaps with the last interval in the answer array,
            // merge them by updating the end time of the last interval.
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    
    return ans;  // Return the merged intervals.
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> mergedIntervals = mergeOverlappingIntervals(intervals);
    
    cout << "Merged Intervals: ";
    for (const auto &interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    
    return 0;
}

/*
 * Time Complexity: O(n log n)
 *   - Sorting the intervals takes O(n log n).
 *   - Merging the intervals takes O(n).
 *   - Overall time complexity is O(n log n).
 *
 * Space Complexity: O(n)
 *   - The space complexity is O(n) for storing the merged intervals in `ans`.
 */
