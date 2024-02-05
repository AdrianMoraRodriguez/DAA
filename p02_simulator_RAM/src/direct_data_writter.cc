/**
 * @file direct_data_writter.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la escritura de datos
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "direct_data_writter.h"


void DirectDataWritter::Write(int address, int value, std::vector<int>& vector) {
  try {
    vector[address] = value;
  } catch (const std::exception& e) {
    throw "Error en la escritura de datos directa en la posición: " + address;
  }
}