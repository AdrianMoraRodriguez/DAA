#include "matrix_column_multiply.h"


MatrixColumnMultiply::MatrixColumnMultiply(int rows, int cols) : Matrix(rows, cols) {}


MatrixColumnMultiply::MatrixColumnMultiply(int rows, int cols, int value) : Matrix(rows, cols, value) {}


MatrixColumnMultiply::MatrixColumnMultiply(const MatrixColumnMultiply& kMatrix) : Matrix(kMatrix) {}


MatrixColumnMultiply& MatrixColumnMultiply::operator*(const Matrix& kMatrix) const {
  if (getCols() != kMatrix.getRows()) {
    throw std::invalid_argument("The number of columns of the first matrix must be equal to the number of rows of the second matrix.");
  }
  MatrixColumnMultiply* result = new MatrixColumnMultiply(getCols(), kMatrix.getRows());
  for (int column = 0; column < getCols(); column++) {
    for (int row = 0; row < kMatrix.getRows(); row++) {
      int sum = 0;
      for (int row_2 = 0; row_2 < kMatrix.getRows(); row_2++) {
        sum += (*this)(row, row_2) * kMatrix(column, row_2);
      }
      (*result)(row, column) = sum;
    }
  }
  return *result;
}