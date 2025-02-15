/**
 * @file JZERO.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la operación JUMP
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "alu.h"
#pragma once

class JZERO : public ALU {
 public:
  JZERO(DataMemory* data_memory) {data_memory_ = data_memory;}
  ~JZERO() {}
  void operate() const override;
  void isValid() const override;
};