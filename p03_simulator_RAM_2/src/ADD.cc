/**
 * @file ADD.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la suma
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "ADD.h"

/**
 * @brief Realiza la operación de suma
 * 
 */
void ADD::operate() const {
  try {
    isValid();
    int vector_postion = data_reader_in_vector_->ReadPosition(position_in_vector_, data_memory_->getRegisters());
    int result = data_memory_->getr0() + data_reader_->Read(operand_, vector_postion ,data_memory_->getRegisters());
    data_memory_->load(result);
  } catch (const char* e) {
    throw e;
  }
}

/**
 * @brief Comprueba que los datos son válidos
 * 
 */
void ADD::isValid() const {
}

/**
 * @brief Devuelve la instrucción en formato string
 * 
 * @return std::string 
 */
std::string ADD::printInstruction() const {
  std::string instruction = "ADD ";
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