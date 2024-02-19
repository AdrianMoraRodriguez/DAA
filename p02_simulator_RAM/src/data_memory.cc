/**
 * @file data_memory.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la memoria de datos
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "data_memory.h"

/**
 * @brief Construct a new Data Memory:: Data Memory object
 * 
 * @param address 
 * @param value 
 */
void DataMemory::modifyMemory(int address, int value) {
  if (address < 0 || address >= registers_.size()) {
    throw "No se puede acceder a la dirección de memoria:" + std::to_string(address);
  }
  try {
    registers_[address] = value;
  } catch (const std::exception& e) {
    throw "Error en la escritura de datos";
  } catch (...) {
    throw "Error desconocido en la escritura de datos";
  }
}

/**
 * @brief Carga un valor en la memoria de datos
 * 
 * @param value 
 */
void DataMemory::load(int value) {
  registers_[0] = value;
}

/**
 * @brief Lee un valor de la memoria de datos
 * 
 * @param value 
 * @return int 
 */
int DataMemory::Read(int value) {
  if (value < 0 || value >= registers_.size()) {
    throw "No se puede acceder a la dirección de memoria:" + std::to_string(value);
  }
  try {
    return registers_[value];
  } catch (const std::exception& e) {
    throw "Error en la lectura de datos";
  } catch (...) {
    throw "Error desconocido en la lectura de datos";
  }
}