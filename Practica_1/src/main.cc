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
  std::cout << "Introduce the number of rows: ";
  std::cin >> rows;
  std::cout << "Introduce the number of columns: ";
  std::cin >> cols;
  Matrix* matrix_a = new MatrixRowMultiply(rows, cols);
  Matrix* matrix_b = new MatrixRowMultiply(rows, cols);

  Matrix* matrix_c = new MatrixColumnMultiply(rows, cols);
  Matrix* matrix_d = new MatrixColumnMultiply(rows, cols);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; j++) {
      int value_a = rand() % 10;
      int value_b = rand() % 10;
      (*matrix_a)(i, j) = value_a;
      (*matrix_c)(i, j) = value_a;
      (*matrix_b)(i, j) = value_b;
      (*matrix_d)(i, j) = value_b;
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
  clock_t start = clock();
  Matrix* matrix_a_result = &((*matrix_a) * (*matrix_b));
  clock_t end = clock();
  double time = (double)(end - start) / CLOCKS_PER_SEC;
  std::cout << "Tiempo filas: " << time << std::endl;
  clock_t start2 = clock();
  Matrix* matrix_c_result = &((*matrix_c) * (*matrix_d));
  clock_t end2 = clock();
  double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
  std::cout << "Tiempo columnas: " << time2 << std::endl;

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