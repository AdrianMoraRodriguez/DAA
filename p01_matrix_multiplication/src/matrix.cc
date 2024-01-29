#include <iostream>
#include <vector>

#include "matrix.h"

/**
 * @brief Construct a new Matrix:: Matrix object
 * 
 * @param rows 
 * @param cols 
 */
Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  data_ = new int*[rows];
  for (int i = 0; i < rows; ++i) {
    data_[i] = new int[cols];
  }
}

/**
 * @brief Construct a new Matrix:: Matrix object and fill it with value.
 * 
 * @param rows 
 * @param cols 
 * @param value 
 */
Matrix::Matrix(int rows, int cols, int value) : rows_(rows), cols_(cols) {
  data_ = new int*[rows];
  for (int i = 0; i < rows; ++i) {
    data_[i] = new int[0];
  }
}

/**
 * @brief Construct a new Matrix:: Matrix object from a copy of other Matrix object.
 * 
 * @param kMatrix 
 */
Matrix::Matrix(const Matrix& kMatrix) : rows_(kMatrix.rows_), cols_(kMatrix.cols_) {
  data_ = new int*[rows_];
  for (int i = 0; i < rows_; ++i) {
    data_[i] = new int[cols_];
    for (int j = 0; j < cols_; ++j) {
      data_[i][j] = kMatrix(i, j);
    }
  }
}

/**
 * @brief Returns the number of rows in the matrix container.
 * 
 * @return int 
 */
int Matrix::getRows() const {
  return rows_;
}

/**
 * @brief Returns the number of columns in the matrix container.
 * 
 * @return int 
 */
int Matrix::getCols() const {
  return cols_;
}

/**
 * @brief Returns a copy of the element at position (row, colum) in the matrix container.
 * 
 * @param row 
 * @param colum 
 * @return int 
 */
int Matrix::operator()(int row, int colum) const {
  return data_[row][colum];
}

/**
 * @brief Returns a reference to the element at position (row, colum) in the matrix container.
 * 
 * @param row 
 * @param colum 
 * @return int& 
 */
int& Matrix::operator()(int row, int colum)  {
  return data_[row][colum];
}

/**
 * @brief Destroy the Matrix:: Matrix object
 * 
 */
Matrix::~Matrix() {
  for (int i = 0; i < rows_; ++i) {
    delete[] data_[i];
  }
  delete[] data_;
}