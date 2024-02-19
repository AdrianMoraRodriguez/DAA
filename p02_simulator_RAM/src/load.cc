/**
 * @file load.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la operación load
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "load.h"

/**
 * @brief Operación de load
 * 
 */
void LOAD::operate() const {
  try {
    isValid();
    data_memory_->load(data_reader_->Read(operand_, data_memory_->getRegisters()));
  } catch (const char* e) {
    throw e;
  } catch (...) {
    throw "Error desconocido en LOAD";
  }
}

/**
 * @brief Comprueba que los datos son válidos
 * 
 */
void LOAD::isValid() const {
  if (operand_ == 0 && data_reader_name_ != "constant") {
    throw "No se puede hacer un load desde el propio acumulador (R0)";
  }
  if (data_reader_name_ == "error") {
    throw "Error: data_reader_name_ is error";
  }
  if (data_reader_name_ == "error") {
    throw "Error: data_reader_name_ is error";
  }
}
