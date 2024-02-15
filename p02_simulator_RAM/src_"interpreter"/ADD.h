#include "alu.h"

#pragma once

class ADD : public ALU {
 public:
  ADD() {}
  ~ADD() {}
  int operate(int r0, int operand) const override;
};