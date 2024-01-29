#include "matrix_row_multiply.h"


Matrix MatrixRowMultiply::multiplication(const Matrix& kMatrix_1, const Matrix& kMatrix_2) const {
  if (kMatrix_1.getCols() != kMatrix_2.getRows()) {
    throw std::invalid_argument("The number of columns of the first matrix must be equal to the number of rows of the second matrix.");
  }
  Matrix result = Matrix(kMatrix_1.getRows(), kMatrix_2.getCols());
  for (int row = 0; row < kMatrix_1.getRows(); ++row) {
    for (int column = 0; column < kMatrix_2.getCols(); ++column) {
      int sum = 0;
      for (int row_2 = 0; row_2 < kMatrix_2.getRows(); ++row_2) {
        sum += kMatrix_1(row, row_2) * kMatrix_2(row_2, column);
      }
      result(row, column) = sum;
    }
  }
  return result;
}