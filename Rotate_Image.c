// Time: O(n^2)
// Space: O(1)

// void rotate(int** matrix, int matrixSize, int* matrixColSize) {
//     int n = matrixSize;
//     for (int i = 0; i < (n + 1) / 2; i++) {
//         for (int j = 0; j < n / 2; j++) {
//             int temp = matrix[n - 1 - j][i];
//             matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
//             matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i];
//             matrix[j][n - 1 - i] = matrix[i][j];
//             matrix[i][j] = temp;
//         }
//     }
// }

// // matrix[i][j]                           -> Top-left
// // matrix[j][n-1-i]                       -> Top-right
// // matrix[n-1-i][n-1-j]                   -> Bottom-right
// // matrix[n-1-j][i]                       -> Bottom-left



// 2nd method
// Time: O(n^2)
// Space: O(1)

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int temp, n = matrixSize;
    
    // Transpose
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Reverse Matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - j - 1];
            matrix[i][n - j - 1] = temp;
        }
    }
}