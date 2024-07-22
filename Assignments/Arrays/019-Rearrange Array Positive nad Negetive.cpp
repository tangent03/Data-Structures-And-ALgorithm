#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int posIndex = 0;
        int negIndex = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                ans[negIndex] = nums[i];
                negIndex += 2;
            } else {
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
        }
        return ans;
    }
};

vector<int> alternateNumbers(vector<int> &a) {
    vector<int> pos, neg;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            pos.push_back(a[i]);
        } else {
            neg.push_back(a[i]);
        }
    }
    if (pos.size() > neg.size()) {
        for (int i = 0; i < neg.size(); i++) {
            a[2 * i] = pos[i];
            a[2 * i + 1] = neg[i];
        }
        int index = 2 * neg.size();
        for (int i = neg.size(); i < pos.size(); i++) {
            a[index] = pos[i];
            index++;
        }
    } else {
        for (int i = 0; i < pos.size(); i++) {
            a[2 * i] = pos[i];
            a[2 * i + 1] = neg[i];
        }
        int index = 2 * pos.size();
        for (int i = pos.size(); i < neg.size(); i++) {
            a[index] = neg[i];
            index++;
        }
    }
    return a;
}

int main() {
    vector<int> nums1 = {3, 1, -2, -5, 2, -4};
    Solution sol;
    vector<int> rearranged = sol.rearrangeArray(nums1);
    
    cout << "Rearranged array with equal positive and negative numbers: ";
    for (int num : rearranged) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {3, 1, -2, -5, 2, -4, 7};
    vector<int> alternated = alternateNumbers(nums2);
    
    cout << "Rearranged array with unequal positive and negative numbers: ";
    for (int num : alternated) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
