#include <bits/stdc++.h>
using namespace std;

/*
 * Function to find the length of the longest consecutive
  sequence in an array.
 * 
 * Time Complexity: O(N), where N is the size of
  the array.
 * Space Complexity: O(N) due to the use of the 
 unordered_set.
 */
int longestConsecutiveSequence(vector<int> &nums) {
    unordered_set<int> s; // Set to store unique elements from the array.
    
    // Insert all elements of the array into the set.
    for (int i = 0; i < nums.size(); i++) {
        s.insert(nums[i]);
    }
    
    int ans = 0; // Variable to store the length of the longest consecutive sequence.
    
    // Iterate through all elements in the array.
    for (int i = 0; i < nums.size(); i++) {
        // Check if the current element is the start of a new sequence.
        if (s.find(nums[i] - 1) != s.end()) {
            continue; // If the previous element exists, 
            //this is not the start of a sequence.
        } else {
            int count = 0; // Variable to count the length
            // of the current sequence.
            int current = nums[i]; // Current element to
            
            // check the sequence.
            
            // Count the length of the sequence starting
            // from the current element.
            while (s.find(current) != s.end()) {
                count++;
                current++;
            }
            
            // Update the maximum length found so far.
            ans = max(ans, count);
        }
    }
    
    return ans; // Return the length of the longest consecutive sequence.
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Length of the longest consecutive sequence: " << 
    longestConsecutiveSequence(nums) << endl;
    return 0;
}
