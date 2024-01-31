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
    if (line.size() == 0) continue; //A lo mejor no hay que quitarla, si es así va a ser más fácil añadir otro vector con el programa entero, comentarios incluidos
    if (line[0] == '#') continue;
    program_.push_back(line);
  }
  file.close();
  //si encontramos una palabra al principio de la línea con dos puntos, es una etiqueta, por lo que se guarda
  for (int i = 0; i < program_.size(); i++) {
    //Primero, hacemos un split de la línea con separador " "
    std::string delimiter = ":";
    std::string label = program_[i].substr(0, program_[i].find(delimiter));
    if (label.size() == program_[i].size()) continue;
    createLabel(label, i);
  }
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
  //Imprimir las etiquetas
  std::cout << "Etiquetas:" << std::endl;
  for (auto it = labels_.begin(); it != labels_.end(); it++) {
    std::cout << it->first << " " << it->second << std::endl;
  }
}