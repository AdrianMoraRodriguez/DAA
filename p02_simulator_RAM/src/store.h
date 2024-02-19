/**
 * @file store.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la operación STORE
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "alu.h"

#pragma once

class STORE : public ALU {
 public:
  STORE(DataMemory* data_memory) {data_memory_ = data_memory;}
  ~STORE() {}
  void operate() const override;
  void isValid() const override;
};