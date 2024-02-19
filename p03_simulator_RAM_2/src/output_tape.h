/**
 * @file output_tape.h 
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la cinta de salida 
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#pragma once

class OutputTape {
 public:
  OutputTape() {}
  OutputTape(const std::string& kFileName);
  void loadTape(const std::string& kFileName);
  void writeOutput(const std::string& output);
  std::string printTape();
 private:
  std::string file_name_;
  std::ofstream file_;
};