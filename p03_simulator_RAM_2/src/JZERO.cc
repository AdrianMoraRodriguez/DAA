/**
 * @file JZERO.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la operación JUMP
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "JZERO.h"

/**
 * @brief Ejecuta la operación JUMP
 * 
 */
void JZERO::operate() const {
  try {
    isValid();
    if (data_memory_->getr0() == 0) {
      *pc_ = new_position_ - 1;
    }
  } catch (const char* e) {
    throw e;
  }
}

/**
 * @brief Comprueba si la operación es válida
 * 
 */
void JZERO::isValid() const {
  if (new_position_ < 0) {
    throw "Error: Se ha intentado saltar a una posición negativa.";
  }
}

/**
 * @brief Devuelve la instrucción en formato string
 * 
 * @return std::string 
 */
std::string JZERO::printInstruction() const {
  std::string instruction = "JZERO ";
  instruction += data_reader_name_ + "\n";
  return instruction;
}