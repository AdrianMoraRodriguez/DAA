/**
 * @file read.cc 
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la operación de lectura 
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "read.h"

/**
 * @brief Realiza la operación de lectura
 * 
 */
void READ::operate() const {
  try {
    isValid();
    int vector_postion = data_reader_in_vector_->ReadPosition(position_in_vector_, data_memory_->getRegisters());
    int operand = data_reader_->ReadPosition(operand_, data_memory_->getRegisters());
    data_memory_->modifyMemory(operand,vector_postion ,input_tape_->getNextInput());
  } catch (const char* e) {
    throw e;
  }
}

/**
 * @brief Comprueba que los datos son válidos
 * 
 */
void READ::isValid() const {
  if (operand_ < 0 ) {
    throw "No se puede escribir en una posición negativa";
  }
  if (operand_ == 0) {
    throw "No se puede escribir a el acumulador (R0)";
  }
}

/**
 * @brief Devuelve la instrucción en formato string
 * 
 * @return std::string 
 */
std::string READ::printInstruction() const {
  std::string instruction = "READ ";
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