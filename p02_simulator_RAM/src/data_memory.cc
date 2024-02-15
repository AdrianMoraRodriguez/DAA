/**
 * @file data_memory.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la memoria de datos
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "data_memory.h"

void DataMemory::modifyMemory(int address, int value) {
  try {
    registers_[address] = value;
  } catch (const std::exception& e) {
    throw "Error en la escritura de datos";
  }
}

void DataMemory::load(int value) {
  registers_[0] = value;
}

int DataMemory::Read(int value) {
  try {
    return registers_[value];
  } catch (const std::exception& e) {
    throw "Error en la lectura de datos";
  }
}