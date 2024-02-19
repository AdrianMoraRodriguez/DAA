/**
 * @file JGTZ.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la operación JUMP
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "JGTZ.h"

/**
 * @brief Ejecuta la operación JUMP
 * 
 */
void JGTZ::operate() const {
  try {
    isValid();
    if (data_memory_->getr0() > 0) {
      *pc_ = new_position_ - 1;
    }
  } catch (const char* e) {
    throw e;
  } catch (...) {
    throw "Error desconocido en JGTZ";
  }
}

/**
 * @brief Comprueba que los datos son válidos
 * 
 */
void JGTZ::isValid() const {
  if (new_position_ < 0) {
    throw "Error: Se ha intentado saltar a una posición negativa.";
  }
  if (data_reader_name_ == "error") {
    throw "Error: data_reader_name_ is error";
  }
  if (data_reader_name_ == "error") {
    throw "Error: data_reader_name_ is error";
  }
}