/**
 * @file UNKNOW.h 
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la operación UNKNOW 
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "alu.h"
#pragma once

class UNKNOW : public ALU {
 public:
  UNKNOW(DataMemory* data_memory) {data_memory_ = data_memory;}
  ~UNKNOW() {}
  void operate() const override;
  void isValid() const override;
  std::string printInstruction() const override;
};