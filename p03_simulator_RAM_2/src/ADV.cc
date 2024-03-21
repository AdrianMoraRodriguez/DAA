/**
 * @file ADDV.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la operación ADV
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "ADV.h"

/**
 * @brief Implementación de la operación ADV
 * 
 */
void ADV::operate() const {
  try {
    isValid();
    int iterator_vector;
    int max = vector_size_;
    int sum = 0;
    for (iterator_vector = 0; iterator_vector < max; iterator_vector++) {
      sum += data_reader_->Read(operand_, iterator_vector ,data_memory_->getRegisters());
    }
    data_memory_->load(sum);
  } catch (const char* e) {
    throw e;
  }
}

/**
 * @brief Comprueba si el direccionamiento es válido
 * 
 */
void ADV::isValid() const {
  if (position_in_vector_ != 0) {
    throw "En ADV se ha encontrado un direccionamiento de vectores";
  }
}

/**
 * @brief Imprime la instrucción
 * 
 * @return std::string 
 */
std::string ADV::printInstruction() const {
  std::string instruction = "ADV ";
  if (data_reader_name_ == "direct") {
    instruction += std::to_string(operand_);
  } else if (data_reader_name_ == "indirect") {
    instruction += "*" + std::to_string(operand_);
  } else if (data_reader_name_ == "constant") {
    instruction += "=" + std::to_string(operand_);
  }
  instruction += "\n";
  return instruction;
}