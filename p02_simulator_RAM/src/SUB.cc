/**
 * @file SUB.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la resta
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "SUB.h"

/**
 * @brief Realiza la operación de resta
 * 
 */
void SUB::operate() const {
  try {
    isValid();
    int result = data_memory_->getr0() - data_reader_->Read(operand_, data_memory_->getRegisters());
    data_memory_->modifyMemory(0, result);
  } catch (const char* e) {
    throw e;
  } catch (...) {
    throw "Error desconocido en SUB";
  }
}

/**
 * @brief Comprueba que los datos son válidos
 * 
 */
void SUB::isValid() const {
  if (data_reader_name_ == "error") {
    throw "Error: data_reader_name_ is error";
  }
}