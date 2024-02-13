/**
 * @file DIV.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la división
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "DIV.h"

int DIV::operate(int r0, int operand) const {
  if (operand == 0) {
    throw std::invalid_argument("No se puede dividir por 0");
  }
  return r0 / operand;
}