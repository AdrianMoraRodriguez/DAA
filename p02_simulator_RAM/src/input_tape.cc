#include <algorithm>

#include "input_tape.h"


std::vector<int> vectorize(const std::string& kLine, char kDelimiter) {
  std::vector<int> result;
  std::string token = "";
  for (int i = 0; i < kLine.size(); i++) {
    if (kLine[i] == kDelimiter) {
      result.push_back(std::stoi(token));
      token = "";
    } else {
      token += kLine[i];
    }
  }
  result.push_back(std::stoi(token));
  return result;
}

int InputTape::getNextInput() {
  if (head_ < tape_.size()) {
    return tape_[head_++];
  } else {
    throw "No hay más datos en la cinta de entrada";
  }
}

void InputTape::loadTape(const std::string& kFileName) {
  std::ifstream file(kFileName);
  std::string line;
  std::vector<std::string> tokens;
  std::vector<int> numbers;
  while (std::getline(file, line)) {
    tape_ = vectorize(line, ' ');
  }
}

InputTape::InputTape(const std::string& kFileName) {
  loadTape(kFileName);
}