#include <bits/stdc++.h>
using namespace std;

/*
Brute Force Approach:

Time Complexity: O(N log N) due to the sorting step.
Space Complexity: O(N) due to the map and the list.
*/

vector<int> majorityElement2(vector<int> v) {
    vector<int> ls;
    map<int, int> mpp;
    int n = v.size();
    int mini = (int)(n / 3) + 1; // Minimum occurrences required for an element to be a majority element
    
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;
        // If an element's count reaches the threshold, add it to the list
        if (mpp[v[i]] == mini) {
            ls.push_back(v[i]);
        }
        // If we already found two majority elements, stop
        if (ls.size() == 2) {
            break;
        }
    }
    sort(ls.begin(), ls.end());
    return ls;
}

/*
Optimal Approach using Boyer-Moore Voting Algorithm:

Time Complexity: O(N) due to single traversal of the array.
Space Complexity: O(1) because we are using a constant amount of extra space.
*/

vector<int> majorityElement(vector<int>& nums) {
    int candidate1 = INT_MIN, candidate2 = INT_MIN;
    int life1 = 0, life2 = 0;
    vector<int> ans;
    int n = nums.size();

    // First pass to find potential candidates
    for (int i = 0; i < n; i++) {
        if (nums[i] == candidate1) {
            life1++;
        } else if (nums[i] == candidate2) {
            life2++;
        } else if (life1 == 0) {
            candidate1 = nums[i];
            life1 = 1;
        } else if (life2 == 0) {
            candidate2 = nums[i];
            life2 = 1;
        } else {
            life1--;
            life2--;
        }
    }

    // Second pass to verify the candidates
    int count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == candidate1) {
            count1++;
        }
        if (nums[i] == candidate2) {
            count2++;
        }
    }

    if (count1 > n / 3) {
        ans.push_back(candidate1);
    }
    if (count2 > n / 3 && candidate2 != candidate1) { // Ensure the candidates are distinct
        ans.push_back(candidate2);
    }
    
    return ans;
}

int main() {
    vector<int> v = {1, 2, 3, 1, 1};
    
    // Example usage of majorityElement2 (Brute Force)
    vector<int> result2 = majorityElement2(v);
    cout << "Majority elements using majorityElement2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    // Example usage of majorityElement (Optimal Solution)
    vector<int> result1 = majorityElement(v);
    cout << "Majority elements using majorityElement: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
