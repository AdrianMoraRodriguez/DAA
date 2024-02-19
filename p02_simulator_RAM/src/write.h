/**
 * @file write.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la operación WRITE
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "alu.h"

#pragma once

class WRITE : public ALU {
 public:
  WRITE(DataMemory* data_memory) {data_memory_ = data_memory;}
  ~WRITE() {}
  void operate() const override;
  void isValid() const override;
};