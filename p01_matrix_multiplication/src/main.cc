#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>

#include "matrix.cc"
#include "matrix_row_multiply.cc"
#include "matrix_column_multiply.cc"


int main() {
  srand(time(NULL));
  int rows = 0;
  int cols = 0;
  int rows_2 = 0;
  int cols_2 = 0;
  std::cout << "Introduce the number of rows for matrix 1: ";
  std::cin >> rows;
  std::cout << "Introduce the number of columns for matrix 1: ";
  std::cin >> cols;
  std::cout << "Introduce the number of rows for matrix 2: ";
  std::cin >> rows_2;
  std::cout << "Introduce the number of columns for matrix 2: ";
  std::cin >> cols_2;
  //two threads for multiplication by rows or columns
  Matrix* matrix_a = new MatrixRowMultiply(rows, cols);
  Matrix* matrix_b = new MatrixColumnMultiply(rows_2, cols_2);
  Matrix* matrix_c = new MatrixColumnMultiply(rows, cols);
  Matrix* matrix_d = new MatrixRowMultiply(rows_2, cols_2);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; j++) {
      int value_a = rand() % 10;
      (*matrix_a)(i, j) = value_a;
      (*matrix_c)(i, j) = value_a;
    }
  }

  for (int i = 0; i < rows_2; ++i) {
    for (int j = 0; j < cols_2; j++) {
      int value_b = rand() % 10;
      (*matrix_b)(i, j) = value_b;
      (*matrix_d)(i, j) = value_b;
    }
  }
  
  //make the threads
  std::thread thread_1([&matrix_a, &matrix_b, &matrix_c, &matrix_d](){
    Matrix* result = (*matrix_a) * (*matrix_b);
  });
}