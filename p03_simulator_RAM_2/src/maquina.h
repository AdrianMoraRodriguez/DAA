/**
 * @file maquina_ram.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la maquina RAM
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include <iostream>
#include <string>
#include <vector>

#include "data_memory.h"
#include "indirect_data_writter.h"
#include "direct_data_writter.h"
#include "indirect_data_reader.h"
#include "direct_data_reader.h"
#include "constant_data_writter.h"
#include "program_memory.h"
#include "alu.h"
#include "HALT.h"
#include "DIV.h"
#include "MUL.h"
#include "ADD.h"
#include "SUB.h"
#include "JUMP.h"
#include "JZERO.h"
#include "JGTZ.h"
#include "input_tape.h"
#include "output_tape.h"

#pragma once

class Maquina {
 public:
  Maquina() {}
  Maquina(const std::string& kFileName, const std::string& kInputFileName, const std::string& kOutputFile,int vector_length = 10,int number_of_registers = 40);
  ~Maquina() {}
  virtual void Run() = 0;
 protected:
  void printState();
  DataMemory data_memory_;
  ProgramMemory program_memory_;
  ALU* alu_;
  InputTape input_tape_;
  OutputTape output_tape_;
  std::string input_file_;
  std::string output_file_;
  int pc_ = 0;
};