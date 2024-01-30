/**
 * @file data_memory.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la memoria de datos
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "data_memory.h"

void DataMemory::Load(int address, int value) {
  registers_[address] = value;
}