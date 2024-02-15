#include "alu.h"
#pragma once

class UNKNOW : public ALU {
 public:
  UNKNOW(DataMemory* data_memory) {data_memory_ = data_memory;}
  ~UNKNOW() {}
  void operate() const override;
  void isValid() const override;
};