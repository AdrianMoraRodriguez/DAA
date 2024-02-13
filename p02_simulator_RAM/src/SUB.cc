/**
 * @file SUB.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la resta
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "SUB.h"

/**
 * @brief Operación de resta
 * 
 * @param operand 
 * @param r0 
 * @return int 
 */
int SUB::operate(int r0, int operand) const {
  return r0 - operand;
}