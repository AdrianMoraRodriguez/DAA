/**
 * @file JZERO.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la operación JUMP
 * @version 0.1
 * @date 2024-01-30
 * 
 */


#include "JZERO.h"

void JZERO::jump(int& pc, int new_position, int operand) const { //TODO Tener en cuenta que operand es siempre R0
  if (operand == 0) {
    pc = new_position - 1;
  }
}