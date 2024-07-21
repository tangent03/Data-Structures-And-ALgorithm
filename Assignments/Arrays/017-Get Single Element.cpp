#include <bits/stdc++.h>

using namespace std;

// Function to find the element that appears only once
int getSingleElement(vector<int>& arr) {
    int xorr = 0;
    for (int i = 0; i < arr.size(); i++) {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}

int main() {
    // Sample input
    vector<int> arr = {2, 3, 5, 4, 5, 3, 4};  // 2 is the unique element

    // Call the function and get the result
    int singleElement = getSingleElement(arr);

    // Output the result
    cout << "The element that appears only once is: " << singleElement << endl;

    return 0;
}