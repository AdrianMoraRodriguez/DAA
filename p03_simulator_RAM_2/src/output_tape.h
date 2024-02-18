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