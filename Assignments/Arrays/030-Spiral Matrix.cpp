#include <bits/stdc++.h>
using namespace std;

/*
Function to return the spiral order of a given matrix
Time Complexity: O(N * M), where N is the number of rows and M is the number of columns in the matrix.
Space Complexity: O(N * M), for storing the spiral order in the result vector.
*/

vector<int> spiralMatrix(vector<vector<int>> &mat) {
    int row = mat.size();
    int col = mat[0].size();
    int left = 0;
    int right = col - 1;
    int top = 0;
    int bottom = row - 1;
    vector<int> ans;

    while (top <= bottom && left <= right) {
        // Traverse from left to right on the top row
        for (int i = left; i <= right; i++) {
            ans.push_back(mat[top][i]);
        }
        top++;

        // Traverse from top to bottom on the right column
        for (int i = top; i <= bottom; i++) {
            ans.push_back(mat[i][right]);
        }
        right--;

        // Traverse from right to left on the bottom row, if there's still rows left to process
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        // Traverse from bottom to top on the left column, if there's still columns left to process
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }

    return ans;
}

// Function to print a vector
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Example matrix
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<int> result = spiralMatrix(mat);

    cout << "Spiral Order of the matrix is: " << endl;
    printVector(result);

    return 0;
}
