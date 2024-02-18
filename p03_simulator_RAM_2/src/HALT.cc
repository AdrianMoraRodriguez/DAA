/**
 * @file HALT.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la operación Halt
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "HALT.h"

void HALT::operate() const {
  if (lines_executed_ != nullptr) {
    (*lines_executed_)++;
    std::cout << "Se han ejecutado " << *lines_executed_ << " líneas\n";
  }
  exit(EXIT_SUCCESS);
}

void HALT::isValid() const {
  //everything is valid in the halt
}