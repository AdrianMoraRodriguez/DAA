/**
 * @file program_flow.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <string>
#include <vector>

#pragma once

class ProgramFlow {
 public:
  ProgramFlow() {}
  ~ProgramFlow() {}
  virtual void jump(int& pc, int new_position, int operand = 0) const = 0;
};