#include "alu.h"

#pragma once

class WRITE : public ALU {
 public:
  WRITE(DataMemory* data_memory) {data_memory_ = data_memory;}
  ~WRITE() {}
  void operate() const override;
  void isValid() const override;
};