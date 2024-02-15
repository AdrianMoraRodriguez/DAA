
#include <string>
#include <vector>
#include <fstream>

#pragma once

class OutputTape {
 public:
  OutputTape() {}
  OutputTape(const std::string& kFileName);
  void loadTape(const std::string& kFileName);
  ~OutputTape() {}
  void writeOutput(const std::string& output);
 private:
  std::string file_name_;
  std::ofstream file_;
};