#include <iostream>
#include <vector>

#include "matrix.h"


Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols), data_(rows * cols) {}


Matrix::Matrix(int rows, int cols, int value) : rows_(rows), cols_(cols), data_(rows * cols, value) {}


Matrix::Matrix(const Matrix& kMatrix) : rows_(kMatrix.rows_), cols_(kMatrix.cols_), data_(kMatrix.data_) {}


int Matrix::getRows() const {
  return rows_;
}


int Matrix::getCols() const {
  return cols_;
}


int Matrix::operator()(int row, int colum) const {
  return data_[row * cols_ + colum];
}

int& Matrix::operator()(int row, int colum)  {
  return data_[row * cols_ + colum];
}