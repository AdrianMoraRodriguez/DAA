#include <iostream>
#include <cstdlib>
#include <ctime>

#include "matrix_multiply.h"

#pragma once

class MatrixRowMultiply : public MatrixMultiply {
 public:
   Matrix multiplication(const Matrix& kMatrix_1, const Matrix& kMatrix_2) const override;
};