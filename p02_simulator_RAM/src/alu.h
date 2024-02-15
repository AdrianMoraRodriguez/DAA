/**
 * @file alu.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la Unidad Aritmético-Lógica y control de flujo
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include <iostream>
#include <string>
#include <vector>

#include "data_memory.h"
#include "direct_data_reader.h"
#include "indirect_data_reader.h"
#include "constant_data_reader.h"
#include "output_tape.h"
#include "input_tape.h"

#pragma once


class ALU { //TODO En todas las operaciones comprobar si data_reader_name_ es error, si es así, lanzar excepción
 public:
  ALU() {}
  ALU(DataMemory* data_memory);
  ~ALU() {}
  virtual void operate() const = 0;
  virtual void isValid() const = 0;
  void loadPC(int* pc) { pc_ = pc; }
  void loadNewPosition(int new_position) { new_position_ = new_position;}
  void loadOperand(int operand) { operand_ = operand; }
  void loadOperationName(std::string operation_name) { operation_name_ = operation_name; }
  void loadDataReader(std::string data_reader) { 
    data_reader_name_ = data_reader;
    if (data_reader == "direct") {
      data_reader_ = new DirectDataReader();
    } else if (data_reader == "indirect") {
      data_reader_ = new IndirectDataReader();
    } else if (data_reader == "constant") {
      data_reader_ = new ConstantDataReader();
    }
  }
  void loadOutputTape(OutputTape* output_tape) { output_tape_ = output_tape; }
  void loadInputTape(InputTape* input_tape) { input_tape_ = input_tape; }
 protected:
  int operand_;
  DataMemory* data_memory_;
  DataReader* data_reader_ = new DirectDataReader();
  int new_position_;
  int* pc_;
  OutputTape* output_tape_;
  InputTape* input_tape_;
  std::string data_reader_name_;
  std::string operation_name_;
};