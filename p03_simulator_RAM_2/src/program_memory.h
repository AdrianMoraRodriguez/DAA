/**
 * @file program_memory.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la memoria de programa
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "alu.h"
#include "JUMP.h"
#include "JGTZ.h"
#include "JZERO.h"
#include "HALT.h"
#include "ADD.h"
#include "SUB.h"
#include "MUL.h"
#include "DIV.h"
#include "ADV.h"
#include "store.h"
#include "load.h"
#include "read.h"
#include "write.h"
#include "HALT.h"
#include "unknow_instruction.h"
#pragma once

class ProgramMemory {
 public:
  ProgramMemory() {}
  ~ProgramMemory() {}
  void createLabel(const std::string& kLabel, int line_number);
  void loadProgram(const std::string& kFilename, int* pc, DataMemory* data_memory, OutputTape* output_tape, InputTape* input_tape, int* lines_executed = nullptr);
  ALU* getInstruction(int line_number) const { return instructions_[line_number]; };
  int getLablePosition(const std::string& kLabel) const { return labels_.at(kLabel); };
  int getProgramSize() const { return program_.size(); };
  void checkOperation(const std::vector<std::string>& kOperation, const std::string& type_of_access);
  void makeInstructions(int* pc, DataMemory* data_memory, OutputTape* output_tape, InputTape* input_tape, int* lines_executed);
 private:
  std::vector<std::string> program_;
  std::vector<ALU*> instructions_;
  std::map<std::string, int> labels_;
};