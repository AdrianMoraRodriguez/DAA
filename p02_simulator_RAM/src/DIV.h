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

class DIV : public ALU {
 public:
  DIV(DataMemory* data_memory) {data_memory_ = data_memory;}
  ~DIV() {}
  void operate() const override;
  void isValid() const override;
};