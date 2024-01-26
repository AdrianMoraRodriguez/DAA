#include "matrix_column_multiply.h"


MatrixColumnMultiply::MatrixColumnMultiply(int rows, int cols) : Matrix(rows, cols) {}


MatrixColumnMultiply::MatrixColumnMultiply(int rows, int cols, int value) : Matrix(rows, cols, value) {}


MatrixColumnMultiply::MatrixColumnMultiply(const MatrixColumnMultiply& kMatrix) : Matrix(kMatrix) {}


MatrixColumnMultiply& MatrixColumnMultiply::operator*(const Matrix& kMatrix) const {
  MatrixColumnMultiply* result = new MatrixColumnMultiply(getRows(), kMatrix.getCols());
  for (int columns = 0; columns < getCols(); ++columns) {
    for (int rows = 0; rows < kMatrix.getRows(); ++rows) {
      for (int rows2 = 0; rows2 < getRows(); ++rows2) {
        (*result)(columns, rows) += (*this)(columns, rows2) * kMatrix(rows2, rows);
      }
    }
  }
  return *result;
}