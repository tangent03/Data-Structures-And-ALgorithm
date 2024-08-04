#include <bits/stdc++.h>
using namespace std;

/*
 * Function to check if we can place the cows with at least 'dist' distance apart
 * Time Complexity: O(N), where N is the size of the stalls vector
 * Space Complexity: O(1)
 */
bool canWePlace(vector<int>& stalls, int dist, int cows) {
    int cntCows = 1; // Start by placing the first cow at the first stall
    int last = stalls[0]; // The position of the last placed cow

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last >= dist) {
            cntCows++; // Place another cow
            last = stalls[i]; // Update the position of the last placed cow
        }
    }
    return cntCows >= cows; // Check if we could place all cows
}

/*
 * Function to find the largest minimum distance between the cows
 * Time Complexity: O(N log (max - min)), where N is the size of the stalls vector
 * Space Complexity: O(1)
 */
int aggresiveCows(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end()); // Sort the stalls
    int n = stalls.size();
    int low = 1; // Minimum possible distance
    int high = stalls[n - 1] - stalls[0]; // Maximum possible distance

    while (low <= high) {
        int mid = low + (high - low) / 2; // Try the middle distance
        if (canWePlace(stalls, mid, k)) {
            low = mid + 1; // If we can place the cows, try for a larger distance
        } else {
            high = mid - 1; // If we cannot place the cows, try for a smaller distance
        }
    }
    return high; // The largest minimum distance where cows can be placed
}

int main() {
    vector<int> stalls = {1, 2, 8, 4, 9};
    int k = 3; // Number of cows
    int result = aggresiveCows(stalls, k);
    cout << "The largest minimum distance is: " << result << endl;
    return 0;
}
