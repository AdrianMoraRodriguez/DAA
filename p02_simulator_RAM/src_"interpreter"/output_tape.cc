
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
  file_.close();
}