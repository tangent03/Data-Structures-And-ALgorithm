#include <bits/stdc++.h>
using namespace std;

/*
Function to rotate the matrix 90 degrees clockwise

Time Complexity: O(N^2), where N is the number
 of rows (or columns) in the matrix.
 
Space Complexity: O(1), as we are doing
 in-place rotation.
*/
void rotate(vector<vector<int>> &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    // Transpose the matrix
    for (int i = 0; i < row; i++) {
        for (int j = i; j < col; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row to get the rotated matrix
    for (int i = 0; i < row; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// Function to print the matrix
void printMatrix(const vector<vector<int>> &matrix) {
    for (const auto &row : matrix) {
        for (const auto &elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    // Rotate the matrix
    rotate(matrix);

    cout << "Rotated Matrix:" << endl;
    printMatrix(matrix);

    return 0;
}
