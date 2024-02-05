/**
 * @file JZERO.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la operación JUMP
 * @version 0.1
 * @date 2024-01-30
 * 
 */


#include "program_flow.h"
#pragma once

class JZERO : public ProgramFlow {
 public:
  JZERO() {}
  ~JZERO() {}
  void jump(int& pc, int new_position, int operand = 0) const override;
};