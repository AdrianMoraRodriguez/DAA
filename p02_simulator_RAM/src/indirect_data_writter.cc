/**
 * @file indirect_data_writter.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la escritura de datos
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "indirect_data_writter.h"


void IndirectDataWritter::Write(int address, int value, std::vector<int>& vector) { //TODO Saber diferenciar entre read, load y store
  try {
    vector[vector[address]] = value;
  } catch (const std::exception& e) {
    throw "Error en la escritura de datos indirecta en la posición: " + address;
  }
}