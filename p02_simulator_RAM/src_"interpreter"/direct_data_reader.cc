/**
 * @file direct_data_reader.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la lectura de datos directa
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "direct_data_reader.h"

int DirectDataReader::Read(int address, const std::vector<int>& kVector) {
  try {
    return kVector[address];
  } catch (const std::exception& e) {
    throw "Error en la lectura de datos directa en la posición: " + address;
  }
}