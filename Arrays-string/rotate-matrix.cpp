// Rotating the matrix by 90 degrees inplace
#include <bits/stdc++.h>
using namespace std;

void transpose_matrix(vector<vector<int>> &mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
}

void reverse_matrix(vector<vector<int>> &mat, int n) {
    for (int i = 0; i < n; i++) {
        int low = 0, high = n - 1;
        while (low < high) {
            swap(mat[i][low++], mat[i][high--]);
        }
    }
}

void rotate_matrix_clock(vector<vector<int>> &mat, int n) {
    transpose_matrix(mat, n);
    // reverse each row;
    reverse_matrix(mat, n);
}

void rotate_matrix_anti(vector<vector<int>> &mat, int n) {
    // reverse each row;
    reverse_matrix(mat, n);
    transpose_matrix(mat, n);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (vector<int> &row : mat) {
        for (int &col : row) {
            cin >> col;
        }
    }
    rotate_matrix_anti(mat, n);
    for (vector<int> &row : mat) {
        for (int &col : row) {
            cout << col << " ";
        }
        cout << "\n";
    }
    return 0;
}