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

#pragma once

/**
 * @brief Clase ProgramMemory
 * 
 */
class ProgramMemory {
 public:
  ProgramMemory() {}
  ~ProgramMemory() {}
  void createLabel(const std::string& kLabel, int line_number);
  void loadProgram(const std::string& kFilename);
  std::string getInstruction(int line_number) const { return program_[line_number]; };
  int getLablePosition(const std::string& kLabel) const { return labels_.at(kLabel); };
  int getProgramSize() const { return program_.size(); };
  void checkOperation(const std::vector<std::string>& kOperation, const std::string& type_of_access);
 private:
  std::vector<std::string> program_;
  std::map<std::string, int> labels_;
};