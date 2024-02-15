/**
 * @file DIV.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la división
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "alu.h"

#pragma once

/**
 * @brief Clase DIV que hereda de ALU
 * 
 */
class DIV : public ALU {
 public:
  DIV() {}
  ~DIV() {}
  int operate(int r0, int operand) const override;
};