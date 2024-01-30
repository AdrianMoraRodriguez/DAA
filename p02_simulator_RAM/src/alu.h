#include <iostream>
#include <string>
#include <vector>

#pragma once

class ALU {
 public:
  ALU() {}
  ~ALU() {}
  virtual int operate(int r0, int operand) const = 0;
};