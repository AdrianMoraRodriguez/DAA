/**
 * @file load.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Declara la operación LOAD
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "alu.h"

class LOAD : public ALU {
 public:
  LOAD(DataMemory* data_memory) {data_memory_ = data_memory;}
  ~LOAD() {}
  void operate() const override;
  void isValid() const override;
};