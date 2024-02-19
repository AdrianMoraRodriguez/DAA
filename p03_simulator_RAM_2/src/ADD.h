/**
 * @file ADD.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la operación ADD
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "alu.h"

#pragma once

class ADD : public ALU {
 public:
  ADD(DataMemory* data_memory) {data_memory_ = data_memory;}
  ~ADD() {}
  void operate() const override;
  void isValid() const override;
  std::string printInstruction() const override;
};