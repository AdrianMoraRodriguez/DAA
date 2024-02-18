#include "alu.h"

#pragma once

class ADD : public ALU {
 public:
  ADD(DataMemory* data_memory) {data_memory_ = data_memory;}
  ~ADD() {}
  void operate() const override;
  void isValid() const override;
};