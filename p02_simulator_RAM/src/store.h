#include "alu.h"

#pragma once

class STORE : public ALU {
 public:
  STORE(DataMemory* data_memory) {data_memory_ = data_memory;}
  ~STORE() {}
  void operate() const override;
  void isValid() const override;
};