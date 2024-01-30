#include <iostream>
#include <cstdlib>
#include <ctime>

#include "matrix.h"
#include "matrix_row_multiply.h"
#include "matrix_column_multiply.h"

double getMultiplicationTime(const MatrixMultiply& kMatrixMultiply, const Matrix& kMatrix_1, const Matrix& kMatrix_2) {
  int start_time = clock();
  kMatrixMultiply.multiplication(kMatrix_1, kMatrix_2);
  int end_time = clock();
  return double(end_time - start_time) / CLOCKS_PER_SEC;
}

Matrix getRandomMatrix(int rows, int cols) {
  Matrix matrix(rows, cols);
  for (int row = 0; row < rows; row++) {
    for (int column = 0; column < cols; column++) {
      matrix(row, column) = rand() % 100;
    }
  }
  return matrix;
}

int main() {
  srand(time(NULL));
  int rows = 0;
  int cols = 0;
  int rows_2 = 0;
  int cols_2 = 0;

  std::cout << "Introduce the number of rows for matrix 1: ";
  std::cin >> rows;
  std::cout << "Introduce the number of columns for matrix 1: ";
  std::cin >> cols;
  Matrix matrix_1 = getRandomMatrix(rows, cols);
  std::cout << "Introduce the number of rows for matrix 2: ";
  std::cin >> rows_2;
  std::cout << "Introduce the number of columns for matrix 2: ";
  std::cin >> cols_2;
  Matrix matrix_2 = getRandomMatrix(rows_2, cols_2);
  MatrixMultiply* row_multiply = new MatrixRowMultiply();
  MatrixMultiply* column_multiply = new MatrixColumnMultiply();
  try {
    double row_multiply_time = (getMultiplicationTime(*row_multiply, matrix_1, matrix_2) + getMultiplicationTime(*row_multiply, matrix_1, matrix_2) + getMultiplicationTime(*row_multiply, matrix_1, matrix_2)) / 3.0;
    double column_multiply_time = (getMultiplicationTime(*column_multiply, matrix_1, matrix_2) + getMultiplicationTime(*column_multiply, matrix_1, matrix_2) + getMultiplicationTime(*column_multiply, matrix_1, matrix_2)) / 3.0;
    std::cout << "The time for row multiplication is: " << row_multiply_time << std::endl;
    std::cout << "The time for column multiplication is: " << column_multiply_time << std::endl;
  } catch (std::invalid_argument& e) {
    std::cout << e.what() << std::endl;
  }
}