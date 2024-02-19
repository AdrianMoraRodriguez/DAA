/**
 * @file indirect_data_reader.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la lectura de datos indirecta
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "indirect_data_reader.h"

/**
 * @brief Lee un valor de la memoria de datos
 * 
 * @param address 
 * @param kVector 
 * @return int 
 */
int IndirectDataReader::Read(int address, const std::vector<int>& kVector) {
  try {
    return kVector[kVector[address]];
  } catch (const std::exception& e) {
    throw "Error en la lectura de datos indirecta en la posición: " + address;
  }
}