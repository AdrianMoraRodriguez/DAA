/**
 * @file program_memory.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la memoria de programa
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "program_memory.h"

/**
 * @brief Load the program from a file.
 * 
 * @param kFilename 
 */
void ProgramMemory::loadProgram(const std::string& kFilename) {
  std::ifstream file(kFilename);
  if (!file.is_open()) {
    std::cerr << "Error al abrir el fichero " << kFilename << std::endl;
  }
  std::string line;
  while (std::getline(file, line)) {
    if (line.size() == 0) continue;
    if (line[0] == '#') continue;
    program_.push_back(line);
  }
  file.close();
}

/**
 * @brief Create a label.
 * 
 * @param kLabel 
 * @param line_number 
 */
void ProgramMemory::createLabel(const std::string& kLabel, int line_number) {
  labels_[kLabel] = line_number;
}

void ProgramMemory::printProgram() const {
  for (int i = 0; i < program_.size(); i++) {
    std::cout << program_[i] << std::endl;
  }
}