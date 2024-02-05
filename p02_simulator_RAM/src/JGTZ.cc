/**
 * @file JGTZ.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la operación JUMP
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "JGTZ.h"

void JGTZ::jump(int& pc, int new_position, int operand) const {
  if (operand > 0) {
    pc = new_position - 1;
  }
}