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
    int vector_postion = data_reader_in_vector_->ReadPosition(position_in_vector_, data_memory_->getRegisters());
    int operand = data_reader_->ReadPosition(operand_, data_memory_->getRegisters());
    data_memory_->modifyMemory(operand, vector_postion, data_memory_->getr0());
  } catch (const char* e) {
    throw e;
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
}

/**
 * @brief Devuelve la instrucción en formato string
 * 
 * @return std::string 
 */
std::string STORE::printInstruction() const {
  std::string instruction = "STORE ";
  if (data_reader_name_ == "direct") {
    instruction += std::to_string(operand_);
  } else if (data_reader_name_ == "indirect") {
    instruction += "*" + std::to_string(operand_);
  } else if (data_reader_name_ == "constant") {
    instruction += "=" + std::to_string(operand_);
  }
  if (position_in_vector_ != 0 && data_reader_in_vector_name_ != "direct") {
    if (data_reader_in_vector_name_ == "direct") {
      instruction += "[" + std::to_string(position_in_vector_) + "]";
    } else if (data_reader_in_vector_name_ == "indirect") {
      instruction += "[*" + std::to_string(position_in_vector_) + "]";
    } else if (data_reader_in_vector_name_ == "constant") {
      instruction += "[" + std::to_string(position_in_vector_) + "]";
    }
  }
  instruction += "\n";
  return instruction;
}