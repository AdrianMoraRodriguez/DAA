#include <iostream>
#include <cstdlib>
#include <ctime>

#include "matrix.h"

#pragma once

class MatrixRowMultiply : public Matrix {
 public:
  MatrixRowMultiply(int rows, int cols);
  MatrixRowMultiply(int rows, int cols, int value);
  MatrixRowMultiply(const MatrixRowMultiply& kMatrix);
  virtual MatrixRowMultiply& operator*(const Matrix& kMatrix) const;
};