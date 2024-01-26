#include "matrix_row_multiply.h"


MatrixRowMultiply::MatrixRowMultiply(int rows, int cols) : Matrix(rows, cols) {}



MatrixRowMultiply::MatrixRowMultiply(int rows, int cols, int value) : Matrix(rows, cols, value) {}



MatrixRowMultiply::MatrixRowMultiply(const MatrixRowMultiply& kMatrix) : Matrix(kMatrix) {}



MatrixRowMultiply& MatrixRowMultiply::operator*(const Matrix& kMatrix) const {
  MatrixRowMultiply* result = new MatrixRowMultiply(getRows(), kMatrix.getCols());
  for (int row = 0; row < getRows(); ++row) {
    for (int column = 0; column < kMatrix.getCols(); ++column) {
      for (int column2 = 0; column2 < getCols(); ++column2) {
        (*result)(row, column) += (*this)(row, column2) * kMatrix(column2, column);
      }
    }
  }
  return *result;
}