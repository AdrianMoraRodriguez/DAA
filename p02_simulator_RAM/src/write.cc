/**
 * @file write.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2024-02-15
 */
#include "write.h"

/**
 * @brief implementación de la operación WRITE
 * 
 */
void WRITE::operate() const {
  try {
    isValid();
    output_tape_->writeOutput(std::to_string(data_reader_->Read(operand_, data_memory_->getRegisters())));
  } catch (const char* e) {
    throw e;
  } catch (...) {
    throw "Error desconocido en WRITE";
  }
}

/**
 * @brief Comprueba que los datos son válidos
 * 
 */
void WRITE::isValid() const {
  if (operand_ < 0 ) {
    throw "No se puede escribir desde una posición negativa";
  }
  if (operand_ == 0 && data_reader_name_ != "constant") {
    throw "No se puede escribir desde el acumulador (R0)";
  }
  if (data_reader_name_ == "error") {
    throw "Error: data_reader_name_ is error";
  }
  if (data_reader_name_ == "error") {
    throw "Error: data_reader_name_ is error";
  }
}