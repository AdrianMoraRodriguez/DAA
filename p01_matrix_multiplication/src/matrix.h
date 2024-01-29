#include <iostream>
#include <array>

#pragma once

class Matrix {
 public:
  Matrix(int rows, int cols);
  Matrix(int rows, int cols, int value);
  Matrix(const Matrix& kMatrix);
  int getRows() const;
  int getCols() const;
  int operator()(int row, int column) const;
  int& operator()(int row, int column);
  ~Matrix();
 private:
  int rows_;
  int cols_;
  int** data_;
};