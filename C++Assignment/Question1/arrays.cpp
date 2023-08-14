#include <iostream>

// Function to dynamically allocate memory for a 2D array
int** createMatrix(int rows, int columns) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    }
    return matrix;
}

// Function to fill the elements of a matrix based on user input
void inputMatrix(int** matrix, int rows, int columns) {
    std::cout << "Enter the elements of the matrix:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << "Enter element at position (" << i << ", " << j << "): ";
            std::cin >> matrix[i][j];
        }
    }
}

// Function to display the elements of a matrix
void displayMatrix(int** matrix, int rows, int columns) {
    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to perform matrix addition
void addMatrices(int** matrix1, int** matrix2, int** result, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to perform matrix subtraction
void subtractMatrices(int** matrix1, int** matrix2, int** result, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to perform matrix multiplication
void multiplyMatrices(int** matrix1, int** matrix2, int** result, int rows1, int columns1, int columns2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < columns1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to deallocate memory for a 2D array
void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int rows1, columns1, rows2, columns2;

    std::cout << "Enter the number of rows and columns for Matrix 1: ";
    std::cin >> rows1 >> columns1;

    std::cout << "Enter the number of rows and columns for Matrix 2: ";
    std::cin >> rows2 >> columns2;

    if (columns1 != rows2) {
        std::cout << "Matrix multiplication is not possible with the given dimensions." << std::endl;
        return 0;
    }

    // Dynamically allocate memory for matrices
    int** matrix1 = createMatrix(rows1, columns1);
    int** matrix2 = createMatrix(rows2, columns2);
    int** resultMatrix = createMatrix(rows1, columns2);

    // Input matrices
    std::cout << "Matrix 1:" << std::endl;
    inputMatrix(matrix1, rows1, columns1);

    std::cout << "Matrix 2:" << std::endl;
    inputMatrix(matrix2, rows2, columns2);

    // Display matrices
    std::cout << "Matrix 1:" << std::endl;
    displayMatrix(matrix1, rows1, columns1);

    std::cout << "Matrix 2:" << std::endl;
    displayMatrix(matrix2, rows2, columns2);

    // Perform matrix addition
    addMatrices(matrix1, matrix2, resultMatrix, rows1, columns1);
    std::cout << "Result of matrix addition:" << std::endl;
    displayMatrix(resultMatrix, rows1, columns1);

    // Perform matrix subtraction
    subtractMatrices(matrix1, matrix2, resultMatrix, rows1, columns1);
    std::cout << "Result of matrix subtraction:" << std::endl;
    displayMatrix(resultMatrix, rows1, columns1);

    // Perform matrix multiplication
    multiplyMatrices(matrix1, matrix2, resultMatrix, rows1, columns1, columns2);
    std::cout << "Result of matrix multiplication:" << std::endl;
    displayMatrix(resultMatrix, rows1, columns2);

    // Deallocate memory for matrices
    deleteMatrix(matrix1, rows1);
    deleteMatrix(matrix2, rows2);
    deleteMatrix(resultMatrix, rows1);

    return 0;
}

