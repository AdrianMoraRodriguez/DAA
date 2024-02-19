/**
 * @file output_tape.cc 
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la cinta de salida 
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "output_tape.h"

/**
 * @brief Constructor de OutputTape
 * 
 * @param kFileName 
 */
OutputTape::OutputTape(const std::string& kFileName) {
  loadTape(kFileName);
}

/**
 * @brief Carga la cinta de salida
 * 
 * @param kFileName 
 */
void OutputTape::loadTape(const std::string& kFileName) {
  file_name_ = kFileName;
  file_.open(file_name_, std::ios::out);
  file_.close();
}

/**
 * @brief Escribe en la cinta de salida
 * 
 * @param output 
 */
void OutputTape::writeOutput(const std::string& output) {
  file_.open(file_name_, std::ios::app);
  file_ << output;
  file_ << " ";
  file_.close();
}

/**
 * @brief Imprime la cinta de salida
 * 
 * @return std::string 
 */
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