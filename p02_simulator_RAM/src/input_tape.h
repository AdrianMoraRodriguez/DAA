/**
 * @file input_tape.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la cinta de entrada
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include <string>
#include <vector>
#include <fstream>

#pragma once

class InputTape {
 public:
  InputTape() {}
  InputTape(const std::string& kFileName);
  InputTape(InputTape& input_tape) : head_(input_tape.head_), tape_(input_tape.tape_) {}
  int getNextInput();
  void loadTape(const std::string& kFileName);
 private:
  std::vector<int> tape_;
  int head_ = 0;
};