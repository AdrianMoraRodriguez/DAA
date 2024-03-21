/**
 * @file write.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2024-02-15
 */
#include "write.h"

/**
 * @brief Realiza la operación de escritura
 * 
 */
void WRITE::operate() const {
  try {
    isValid();
    int vector_postion = data_reader_in_vector_->ReadPosition(position_in_vector_, data_memory_->getRegisters());
    output_tape_->writeOutput(std::to_string(data_reader_->Read(operand_, vector_postion,data_memory_->getRegisters())));
  } catch (const char* e) {
    throw e;
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
}

/**
 * @brief Devuelve la instrucción en formato string
 * 
 * @return std::string 
 */
std::string WRITE::printInstruction() const {
  std::string instruction = "WRITE ";
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