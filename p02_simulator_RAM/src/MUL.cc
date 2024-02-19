/**
 * @file MUL.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la multiplicación
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "MUL.h"

/**
 * @brief Realiza la operación de multiplicación
 * 
 */
void MUL::operate() const {
  try {
    isValid();
    int result = data_memory_->getr0() * data_reader_->Read(operand_, data_memory_->getRegisters());
    data_memory_->modifyMemory(0, result);
  } catch (const char* e) {
    throw e;
  } catch (...) {
    throw "Error desconocido en MUL";
  }
}

/**
 * @brief Comprueba que los datos son válidos
 * 
 */
void MUL::isValid() const {
  if (data_reader_name_ == "error") {
    throw "Error: data_reader_name_ is error";
  }
  if (data_reader_name_ == "error") {
    throw "Error: data_reader_name_ is error";
  }
}