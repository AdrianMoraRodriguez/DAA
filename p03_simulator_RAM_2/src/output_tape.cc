
#include "output_tape.h"

OutputTape::OutputTape(const std::string& kFileName) {
  loadTape(kFileName);
}

void OutputTape::loadTape(const std::string& kFileName) {
  file_name_ = kFileName;
  file_.open(file_name_, std::ios::out);
  file_.close();
}

void OutputTape::writeOutput(const std::string& output) {
  file_.open(file_name_, std::ios::app);
  file_ << output;
  file_ << " ";
  file_.close();
}

std::string OutputTape::printTape() {
  std::string result = "";
  std::ifstream file(file_name_);
  std::string line;
  while (std::getline(file, line)) {
    result += line + "\n";
  }
  file.close();
  return result;
}