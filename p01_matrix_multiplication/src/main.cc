#include <iostream>
#include <cstdlib>
#include <ctime>

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
  Matrix* matrix_a;
  Matrix* matrix_b;
  std::cout << "Introduce the number of rows for matrix 2: ";
  std::cin >> rows_2;
  std::cout << "Introduce the number of columns for matrix 2: ";
  std::cin >> cols_2;
  std::cout << "Want multiply matrix by rows or by columns? (r/c): ";
  char option;
  std::cin >> option;
  if (option == 'c') {
    matrix_a = new MatrixColumnMultiply(rows, cols);
    matrix_b = new MatrixColumnMultiply(rows_2, cols_2);
  } else {
    matrix_a = new MatrixRowMultiply(rows, cols);
    matrix_b = new MatrixRowMultiply(rows_2, cols_2);
  }

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; j++) {
      int value_a = rand() % 10;
      (*matrix_a)(i, j) = value_a;
    }
  }

  for (int i = 0; i < rows_2; ++i) {
    for (int j = 0; j < cols_2; j++) {
      int value_b = rand() % 10;
      (*matrix_b)(i, j) = value_b;
    }
  }


  // std::cout << "Matrix A:" << std::endl;
  // for (int i = 0; i < matrix_a.getRows(); ++i) {
  //   for (int j = 0; j < matrix_a.getCols(); ++j) {
  //     std::cout << matrix_a(i, j) << " ";
  //   }
  //   std::cout << std::endl;
  // }
  
  // std::cout << "Matrix B:" << std::endl;
  // for (int i = 0; i < matrix_b.getRows(); ++i) {
  //   for (int j = 0; j < matrix_b.getCols(); ++j) {
  //     std::cout << matrix_b(i, j) << " ";
  //   }
  //   std::cout << std::endl;
  // }

  // std::cout << "Matrix C:" << std::endl;
  // for (int i = 0; i < matrix_c.getRows(); ++i) {
  //   for (int j = 0; j < matrix_c.getCols(); ++j) {
  //     std::cout << matrix_c(i, j) << " ";
  //   }
  //   std::cout << std::endl;
  // }

  // std::cout << "Matrix D:" << std::endl;
  // for (int i = 0; i < matrix_d.getRows(); ++i) {
  //   for (int j = 0; j < matrix_d.getCols(); ++j) {
  //     std::cout << matrix_d(i, j) << " ";
  //   }
  //   std::cout << std::endl;
  // }
  //Cuenta el tiempo que tarda en hacer la multiplicacion por filas
  try {
    clock_t start = clock();
    Matrix* matrix_a_result = &((*matrix_a) * (*matrix_b));
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "Tiempo filas: " << time << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  // std::cout << "Matrix A * Matrix B rows:" << std::endl;
  // for (int i = 0; i < matrix_a_result.getRows(); ++i) {
  //   for (int j = 0; j < matrix_a_result.getCols(); ++j) {
  //     std::cout << matrix_a_result(i, j) << " ";
  //   }
  //   std::cout << std::endl;
  // }
  // std::cout << "Matrix A * Matrix B column:" << std::endl;
  // for (int i = 0; i < matrix_c_result.getRows(); ++i) {
  //   for (int j = 0; j < matrix_c_result.getCols(); ++j) {
  //     std::cout << matrix_c_result(i, j) << " ";
  //   }
  //   std::cout << std::endl;
  // }
}