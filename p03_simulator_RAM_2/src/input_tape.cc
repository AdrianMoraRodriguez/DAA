/**
 * @file input_tape.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la cinta de entrada
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include <algorithm>

#include "input_tape.h"

/**
 * @brief Vectoriza una línea de texto
 * 
 * @param kLine 
 * @param kDelimiter 
 * @return std::vector<int> 
 */
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

/**
 * @brief Consigue el siguiente dato de la cinta de entrada
 * 
 * @return int 
 */
int InputTape::getNextInput() {
  if (head_ < tape_.size()) {
    return tape_[head_++];
  } else {
    throw "No hay más datos en la cinta de entrada";
  }
}

/**
 * @brief Carga la cinta de entrada
 * 
 * @param kFileName 
 */
void InputTape::loadTape(const std::string& kFileName) {
  std::ifstream file(kFileName);
  std::string line;
  std::vector<std::string> tokens;
  std::vector<int> numbers;
  while (std::getline(file, line)) {
    tape_ = vectorize(line, ' ');
  }
}

/**
 * @brief Construye un nuevo objeto de Input Tape
 * 
 * @param kFileName 
 */
InputTape::InputTape(const std::string& kFileName) {
  loadTape(kFileName);
}

/**
 * @brief Imprime la cinta de entrada
 * 
 * @return std::string 
 */
std::string InputTape::printTape() {
  std::string result = "";
  for (int i = 0; i < tape_.size(); i++) {
    result += std::to_string(tape_[i]) + " ";
  }
  result += "\n";
  result += "Head: ";
  result += std::to_string(head_);
  return result;
}