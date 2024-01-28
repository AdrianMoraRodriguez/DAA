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
  Matrix* matrix_c;
  Matrix* matrix_d;
  std::cout << "Introduce the number of rows for matrix 2: ";
  std::cin >> rows_2;
  std::cout << "Introduce the number of columns for matrix 2: ";
  std::cin >> cols_2;
  std::cout << "Want to print result? (y/n): ";
  char option;
  std::cin >> option;
  matrix_a = new MatrixRowMultiply(rows, cols);
  matrix_b = new MatrixRowMultiply(rows_2, cols_2);
  matrix_c = new MatrixColumnMultiply(rows, cols);
  matrix_d = new MatrixColumnMultiply(rows_2, cols_2);

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
  //Cuenta el tiempo que tarda en hacer la multiplicacion por filas
  try {
    clock_t start = clock();
    Matrix* matrix_a_result = &((*matrix_a) * (*matrix_b));
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "Tiempo filas: " << time << std::endl;
    if (option == 'y') {
      std::cout << "Matriz resultado: " << std::endl;
      matrix_a_result->print();
    }
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  //Misma multiplicacion pero con columnas
  try {
    clock_t start = clock();
    Matrix* matrix_b_result = &((*matrix_c) * (*matrix_d));
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "Tiempo columnas: " << time << std::endl;
    if (option == 'y') {
      std::cout << "Matriz resultado: " << std::endl;
      matrix_b_result->print();
    }
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  
}