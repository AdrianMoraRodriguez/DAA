#include <iostream>
#include <vector>

#pragma once

class Matrix {
 public:
  Matrix(int rows, int cols);
  Matrix(int rows, int cols, int value);
  Matrix(const Matrix& kMatrix);
  virtual Matrix& operator*(const Matrix& kMatrix) const = 0;
  int getRows() const;
  int getCols() const;
  int operator()(int row, int column) const;
  int& operator()(int row, int column);
  void print() const;
 private:
  int rows_;
  int cols_;
  std::vector<std::vector<int>> data_;
};