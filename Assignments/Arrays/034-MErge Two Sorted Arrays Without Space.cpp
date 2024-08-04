#include <vector>
#include <iostream>
using namespace std;


/*

Time Complexity: O(m + n)

Each element from nums1 and nums2 is processed exactly once.
Hence, the total time complexity is O(m + n).



Space Complexity: O(1)

The function does not use any extra space apart from a few integer variables.
It merges nums2 into nums1 in-place.

*/


class solution {
public:
    // Function to merge nums2 into nums1 without using extra space
    void mergeWithoutSpace(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = m - 1; // Last index of the meaningful elements in nums1
        int j = n - 1; // Last index of nums2
        int k = m + n - 1; // Last index of nums1 including the extra space
        
        // Merge nums1 and nums2 from the end to the beginning
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i]; // If current element in nums1 is greater, place it at the end
                i--;
            } else {
                nums1[k] = nums2[j]; // If current element in nums2 is greater or equal, place it at the end
                j--;
            }
            k--;
        }
        
        // If there are remaining elements in nums1, no need to move them as they are already in place
        while (i >= 0) {
            nums1[k--] = nums1[i--];
        }
        
        // If there are remaining elements in nums2, move them to nums1
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    solution sol;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0}; // Example nums1 with extra space
    vector<int> nums2 = {2, 5, 6}; // Example nums2
    int m = 3; // Number of meaningful elements in nums1
    int n = 3; // Number of elements in nums2

    sol.mergeWithoutSpace(nums1, m, nums2, n);

    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
