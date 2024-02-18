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
  MUL(DataMemory* data_memory) {data_memory_ = data_memory;}
  ~MUL() {}
  void operate() const override;
  void isValid() const override;
};