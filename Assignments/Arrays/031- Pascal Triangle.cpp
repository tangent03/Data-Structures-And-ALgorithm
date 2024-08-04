#include <bits/stdc++.h>
using namespace std;

/*
Pascal Triangle

Variation 1: Given row number r and column number c.
 Print the element at position (r, c) in Pascal’s triangle.
 
 Variation 2: Given the row number n. Print the n-th row of 
 Pascal’s triangle.
 
 Variation 3: Print the entire Pascal's triangle up to the n-th row.
*/

// Function to calculate nCr (binomial coefficient)
int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

// Variation 1: Function to find the element at (r, c) in Pascal's triangle
int pascalTriangle(int r, int c) {
    int element = nCr(r - 1, c - 1);
    return element;
}

// Variation 2: Function to print the n-th row of Pascal's triangle
void pascalTrianglePrintRow(int n) {
    for (int c = 1; c <= n; c++) {
        cout << nCr(n - 1, c - 1) << " ";
    }
    cout << endl;
}

// Variation 3: Function to generate the entire Pascal's triangle up to n rows
vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    // store the entire Pascal's triangle
    for (int row = 1; row <= n; row++) {
        vector<int> tempLst;
        for (int col = 1; col <= row; col++) {
            tempLst.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}

int main() {
    int r, c, n;

    // Example usage of Variation 1
    cout << "Enter row and column to find the element in Pascal's triangle: ";
    cin >> r >> c;
    cout << "Element at position (" << r << ", " << c << ") is: " << pascalTriangle(r, c) << endl;

    // Example usage of Variation 2
    cout << "Enter row number to print the row of Pascal's triangle: ";
    cin >> n;
    cout << "Row " << n << " of Pascal's triangle: ";
    pascalTrianglePrintRow(n);

    // Example usage of Variation 3
    cout << "Enter number of rows to print the Pascal's triangle: ";
    cin >> n;
    vector<vector<int>> result = pascalTriangle(n);
    cout << "Pascal's triangle up to row " << n << ":" << endl;
    for (const auto& row : result) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
