#include <iostream>
#include <string>
#include <vector>

#pragma once

class DataMemory {
 public: 
  DataMemory(int number_of_registers = 40) : registers_(number_of_registers, 0) {}
  ~DataMemory() {}
  void Load(int address, int value);
  int ReadDirect(int address) const;
  int ReadIndirect(int address) const;
 private:
  std::vector<int> registers_;
};