
#include "input_tape.h"

std::string InputTape::getNextInput() {
  if (head_ < tape_.size()) {
    return tape_[head_++];
  } else {
    return "";
  }
}

void InputTape::loadTape(const std::string& kFileName) {
  std::ifstream file(kFileName);
  std::string line;
  while (std::getline(file, line)) {
    //one by one
    for (int i = 0; i < line.size(); i++) {
      tape_.push_back(std::string(1, line[i]));
    }
  }
}

InputTape::InputTape(const std::string& kFileName) {
  loadTape(kFileName);
}