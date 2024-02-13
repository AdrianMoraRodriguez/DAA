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
#include "program_flow.h"
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

class MaquinaRAM {
 public:
  MaquinaRAM() {}
  MaquinaRAM(const std::string& kFileName, const std::string& kInputFileName, const std::string& kOutputFile,int number_of_registers = 40);
  MaquinaRAM(MaquinaRAM& maquina_ram) : data_memory_(maquina_ram.data_memory_) {}
  ~MaquinaRAM() {}
  void Run();
  void changeMode(std::vector<std::string>& instruction_parts);
 private:
  DataMemory data_memory_;
  ProgramMemory program_memory_;
  ALU* alu_;
  ProgramFlow* program_flow_;
  InputTape input_tape_;
  OutputTape output_tape_;
  int pc_ = 0;
};