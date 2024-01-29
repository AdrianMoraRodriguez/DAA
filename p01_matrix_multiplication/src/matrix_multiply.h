#include <iostream>
#include <array>

#include "matrix.h"
#pragma once

class MatrixMultiply {
 public:
  virtual Matrix multiplication(const Matrix& kMatrix_1, const Matrix& kMatrix_2) const = 0;
};