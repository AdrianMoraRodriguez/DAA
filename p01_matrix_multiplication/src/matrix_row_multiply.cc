#include "matrix_row_multiply.h"


MatrixRowMultiply::MatrixRowMultiply(int rows, int cols) : Matrix(rows, cols) {}



MatrixRowMultiply::MatrixRowMultiply(int rows, int cols, int value) : Matrix(rows, cols, value) {}



MatrixRowMultiply::MatrixRowMultiply(const MatrixRowMultiply& kMatrix) : Matrix(kMatrix) {}



MatrixRowMultiply& MatrixRowMultiply::operator*(const Matrix& kMatrix) const {
  if (getCols() != kMatrix.getRows()) {
    throw std::invalid_argument("The number of columns of the first matrix must be equal to the number of rows of the second matrix.");
  }
  MatrixRowMultiply* result = new MatrixRowMultiply(getRows(), kMatrix.getCols());
  for (int row = 0; row < getRows(); ++row) {
    for (int column = 0; column < kMatrix.getCols(); ++column) {
      int sum = 0;
      for (int row_2 = 0; row_2 < kMatrix.getRows(); ++row_2) {
        sum += (*this)(row, row_2) * kMatrix(row_2, column);
      }
      (*result)(row, column) = sum;
    }
  }
  return *result;
}