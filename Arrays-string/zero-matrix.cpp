#include <bits/stdc++.h>
using namespace std;

void convert_to_zero_matrix(vector<vector<int>> &mat, int m, int n) {
    bool col0 = false;
    for (int i = 0; i < m; i++) {
        if (mat[i][0] == 0) col0 = true;
        for (int j = 1; j < n; j++) {
            if (mat[i][j] == 0) {
                mat[i][0] = mat[0][j] = 0;
            }
        }
    }
    for (int i = m-1; i >=0; i--) {
        for (int j = n-1; j >=1; j--) {
            if (mat[i][0] == 0 || mat[0][j] == 0) mat[i][j] = 0;
        }
        if(col0) mat[i][0]=0;
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for (vector<int> &row : mat) {
        for (int &col : row) {
            cin >> col;
        }
    }
    convert_to_zero_matrix(mat, m, n);
    for (vector<int> &row : mat) {
        for (int &col : row) {
            cout << col << " ";
        }
        cout << "\n";
    }
    return 0;
}