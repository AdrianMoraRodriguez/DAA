#include <string>
#include <vector>
#include <fstream>

#pragma once

class InputTape {
 public:
  InputTape() {}
  InputTape(const std::string& kFileName);
  ~InputTape() {}
  std::string getNextInput();
 private:
  void loadTape(const std::string& kFileName);
  std::vector<std::string> tape_;
  int head_ = 0;
};