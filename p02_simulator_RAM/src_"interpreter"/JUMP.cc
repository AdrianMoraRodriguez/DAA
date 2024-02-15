/**
 * @file JUMP.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la operación JUMP
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "JUMP.h"

void JUMP::jump(int& pc, int new_position, int operand) const {
  if (new_position < 0) {
    throw "Error: Se ha intentado saltar a una posición negativa.";
  }
  pc = new_position - 1;
}