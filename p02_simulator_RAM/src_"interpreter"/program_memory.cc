/**
 * @file program_memory.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la memoria de programa
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "program_memory.h"
std::string preProcessInstruction(std::string instruction) {
  std::string auxiliar;
  for (int i = 0; i < instruction.size(); i++) {
    if (instruction[i] == ' ' || instruction[i] == '\r' || instruction[i] == '\n' || instruction[i] =='\t') continue;
    auxiliar += instruction[i];
  }
  return auxiliar;
}
/**
 * @brief Load the program from a file.
 * 
 * @param kFilename 
 */
void ProgramMemory::loadProgram(const std::string& kFilename) {
  std::ifstream file(kFilename);
  if (!file.is_open()) {
    std::cerr << "Error al abrir el fichero " << kFilename << std::endl;
    exit(1);
  }
  std::string line;
  while (std::getline(file, line)) {
    std::string aux = preProcessInstruction(line);
    if (aux.size() == 0) continue; 
    if (aux[0] == '#') continue;
    if (aux[0] == '\r') continue;
    if (aux[0] == '\n') continue;
    if (aux == "\t") continue;
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
    //quitar la etiqueta de la línea y dejar la instrucción como pirmiera palabra
    program_[i] = program_[i].substr(program_[i].find(delimiter) + 1, program_[i].size());
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


void ProgramMemory::checkOperation(const std::vector<std::string>& kOperation, const std::string& type_of_access) {
  if (kOperation[0] == "store" && type_of_access == "constant") {
    throw "No se puede almacenar en una dirección de memoria constante";
  } else if (kOperation[0] == "read" && type_of_access == "constant") {
    throw "No se puede cargar a una dirección de memoria constante";
  } else if (kOperation[0] == "jump" && type_of_access == "constant") {
    throw "No se puede saltar a una dirección de memoria constante";
  } else if (kOperation[0] == "write" && kOperation[1] == "0" && type_of_access == "direct") {
    throw "No se puede escribir desde la dirección 0";
  }
}