/**
 * @file indirect_data_reader.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la lectura de datos indirecta
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "indirect_data_reader.h"

int IndirectDataReader::Read(int address, int vector_address ,const std::vector<std::vector<int>>& kVector) {
    try {
      return kVector[kVector[address][vector_address]][0]; //desición de diseño: El direccionamiento indirecto te devuelve la primera posición del vector
    } catch (const std::exception& e) {
      throw "Error en la lectura de datos indirecta en la posición: " + address;
    }
}

int IndirectDataReader::ReadPosition(int address ,const std::vector<std::vector<int>>& kVector) {
    try {
      return kVector[address][0];
    } catch (const std::exception& e) {
      throw "Error en la lectura de datos indirecta en la posición: " + address;
    }
}