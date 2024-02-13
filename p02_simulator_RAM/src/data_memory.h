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
  DataMemory(int number_of_registers = 40) : registers_(number_of_registers, 0) {}
  DataMemory(DataMemory& data_memory) : registers_(data_memory.registers_) {}
  ~DataMemory() {}
  void modifyMemory(int address, int value);
  void load(int address);
  int Read(int address);
  void SetNewDataReader(std::string data_reader_type);
  void SetNewDataWritter(std::string data_writter_type);
  int getr0() {return registers_[0];}
 private:
  std::vector<int> registers_;
  DataReader* data_reader_ = new DirectDataReader();
  DataWritter* data_writter_ = new DirectDataWritter();
};