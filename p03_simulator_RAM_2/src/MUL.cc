/**
 * @file MUL.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la multiplicación
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "MUL.h"


void MUL::operate() const {
  try {
    isValid();
    int vector_postion = data_reader_in_vector_->ReadPosition(position_in_vector_, data_memory_->getRegisters());
    int result = data_memory_->getr0() * data_reader_->Read(operand_, vector_postion, data_memory_->getRegisters());
    data_memory_->load(result);
  } catch (const char* e) {
    throw e;
  }
}

void MUL::isValid() const {
  //everything is valid in the multiplication
}