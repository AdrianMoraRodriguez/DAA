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
  SUB(DataMemory* data_memory) {data_memory_ = data_memory;}
  ~SUB() {}
  void operate() const override;
  void isValid() const override;
  std::string printInstruction() const override;
};