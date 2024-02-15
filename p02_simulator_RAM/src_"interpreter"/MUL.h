/**
 * @file MUL.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la multiplicación
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "alu.h"

#pragma once

class MUL : public ALU {
 public:
  MUL() {}
  ~MUL() {}
  int operate(int r0, int operand) const override;
};