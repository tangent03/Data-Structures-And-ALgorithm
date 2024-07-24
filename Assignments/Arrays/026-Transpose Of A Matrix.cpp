#include <bits/stdc++.h>
using namespace std;

void transpose(int arr[][4], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = i; j < col; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

void printMatrix(int arr[][4], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    int row = 4, col = 4;
    
    cout << "Original Matrix:" << endl;
    printMatrix(arr, row, col);
    
    transpose(arr, row, col);
    
    cout << "Transposed Matrix:" << endl;
    printMatrix(arr, row, col);
    
    return 0;
}
 