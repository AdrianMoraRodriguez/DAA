/**
 * @file HALT.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la operación Halt
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "HALT.h"

void HALT::jump(int& pc, int new_position, int operand)  const {
  exit(EXIT_SUCCESS);
}