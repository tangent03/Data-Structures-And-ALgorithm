#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int maxLenSubarrayWithSumZero(vector<int>& arr) {
    unordered_map<int, int> sumMap;  // To store (cumulative sum, index) pairs
    int sum = 0;  // Initialize cumulative sum
    int maxLen = 0;  // Initialize maximum length of subarray with sum 0

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];  // Update cumulative sum

        if (sum == 0) {
            maxLen = i + 1;  // If sum is 0, update maxLen
        } else {
            if (sumMap.find(sum) != sumMap.end()) {
                maxLen = max(maxLen, i - sumMap[sum]);  // Update maxLen if sum is found in map
            } else {
                sumMap[sum] = i;  // Store sum with index in map
            }
        }
    }

    return maxLen;  // Return maximum length of subarray with sum 0
}

int main() {
    vector<int> arr = {1, -1, 3, 2, -2, -3, 3, -3};
    int maxLength = maxLenSubarrayWithSumZero(arr);
    cout << "Length of the largest subarray with sum 0 is: " << maxLength << endl;
    return 0;
}

/*
 * Time Complexity: O(n)
 *   - We iterate through the array once, making the time complexity O(n).
 * 
 * Space Complexity: O(n)
 *   - In the worst case, we might store all n cumulative sums in the hash map, making the space complexity O(n).
 */
