/**
 * @file data_memory.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la memoria de datos
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include <iostream>
#include <string>
#include <vector>

#include "data_reader.h"
#include "direct_data_reader.h"
#include "indirect_data_reader.h"
#include "constant_data_reader.h"

#include "data_writter.h"
#include "direct_data_writter.h"
#include "indirect_data_writter.h"
#include "constant_data_writter.h"

#pragma once

class DataMemory {
 public: 
  DataMemory(int number_of_registers = 40, int vector_length = 10) : registers_(number_of_registers, std::vector<int>(vector_length, 0)) {}
  DataMemory(DataMemory& data_memory) : registers_(data_memory.registers_) {}
  ~DataMemory() {}
  void modifyMemory(int address, int vector_address ,int value);
  void load(int value);
  int Read(int value, int vector_address);
  int getr0() {return registers_[0][0];}
  std::vector<std::vector<int>>& getRegisters() {return registers_;}
  std::string printMemory();
 private:
  std::vector<std::vector<int>> registers_;
};
