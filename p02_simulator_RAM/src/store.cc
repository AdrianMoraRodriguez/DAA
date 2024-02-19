/**
 * @file store.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la operación STORE
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "store.h"

/**
 * @brief Ejecuta la operación STORE
 * 
 */
void STORE::operate() const {
  try {
    isValid();
    if (data_reader_name_ == "direct") {
      data_memory_->modifyMemory(operand_, data_memory_->getr0());
    } else {
      data_memory_->modifyMemory(data_memory_->getRegisters()[operand_], data_memory_->getr0());
    }
  } catch (const char* e) {
    throw e;
  } catch (...) {
    throw "Error desconocido en STORE";
  }
}

/**
 * @brief Comprueba que los datos son válidos
 * 
 */
void STORE::isValid() const {
  if (operand_ == 0) {
    throw "No se puede guardar el acumulador en el propio acumulador (R0)";
  }
  if (data_reader_name_ == "constant") {
    throw "No se puede hacer store en una constante";
  }
  if (data_reader_name_ == "error") {
    throw "Error: data_reader_name_ is error";
  }
  if (data_reader_name_ == "error") {
    throw "Error: data_reader_name_ is error";
  }
}
