/**
 * @file SUB.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la resta
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "alu.h"

#pragma once

/**
 * @brief Clase SUB que hereda de ALU
 * 
 */
class SUB : public ALU {
 public:
  SUB() {}
  ~SUB() {}
  int operate(int r0, int operand) const override;
};