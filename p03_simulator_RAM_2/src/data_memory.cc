/**
 * @file data_memory.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la memoria de datos
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "data_memory.h"

void DataMemory::modifyMemory(int address, int vector_address ,int value) {
  if (address >= registers_.size() || address < 0 || vector_address >= registers_[address].size()) {
      std::string error = "Error en la lectura de datos, no se puede acceder a la posición de memoria (No existe): [" + std::to_string(address) + "," + std::to_string(vector_address) + "]";
      throw error;
    }
  try {
    registers_[address][vector_address] = value;
  } catch (const std::exception& e) {
    throw "Error en la escritura de datos";
  } catch (...) {
    throw "Error desconocido en la escritura de datos";
  }
}

void DataMemory::load(int value) {
  registers_[0][0] = value;
}

int DataMemory::Read(int value, int vector_address) {
  if (value >= registers_.size() || value < 0 || vector_address >= registers_[value].size()) {
    std::string error = "Error en la lectura de datos, no se puede acceder a la posición de memoria (No existe): [" + std::to_string(value) + "," + std::to_string(vector_address) + "]";
    throw error;
  }
  try {
    return registers_[value][vector_address];
  } catch (const std::exception& e) {
    throw "Error en la lectura de datos";
  } catch (...) {
    throw "Error desconocido en la lectura de datos";
  }
}

std::string DataMemory::printMemory() {
  std::string result = "";
  for (int i = 0; i < registers_.size(); i++) {
    result += "R" + std::to_string(i) + ": ";
    for (int j = 0; j < registers_[i].size(); j++) {
      result += std::to_string(registers_[i][j]) + " ";
    }
    result += "\n";
  }
  return result;
}