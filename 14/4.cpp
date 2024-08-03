#include <iostream>

void multiplyMatrices(int mat1[2][2], int mat2[2][2], int result[2][2]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void printMatrix(int mat[2][2]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int mat1[2][2] = { {1, 2}, {3, 4} };
    int mat2[2][2] = { {5, 6}, {7, 8} };
    int result[2][2];
    
    multiplyMatrices(mat1, mat2, result);
    
    std::cout << "Product of matrices:\n";
    printMatrix(result);
    
    return 0;
}
