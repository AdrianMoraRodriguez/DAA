
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