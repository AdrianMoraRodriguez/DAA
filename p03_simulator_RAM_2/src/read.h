#include "alu.h"

#pragma once

class READ : public ALU {
 public:
  READ(DataMemory* data_memory) {data_memory_ = data_memory;}
  ~READ() {}
  void operate() const override;
  void isValid() const override;
};