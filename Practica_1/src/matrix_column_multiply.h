#include "matrix.h"

#pragma once

class MatrixColumnMultiply : public Matrix {
 public:
  MatrixColumnMultiply(int rows, int cols);
  MatrixColumnMultiply(int rows, int cols, int value);
  MatrixColumnMultiply(const MatrixColumnMultiply& kMatrix);
  virtual MatrixColumnMultiply& operator*(const Matrix& kMatrix) const;
};