/**
 * @file DIV.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la división
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "DIV.h"

void DIV::operate() const {
  try {
    isValid();
    int result = data_memory_->getr0() / data_reader_->Read(operand_, data_memory_->getRegisters());
    data_memory_->modifyMemory(0, result);
  } catch (const char* e) {
    throw e;
  }
}

void DIV::isValid() const {
  if (data_reader_->Read(operand_, data_memory_->getRegisters()) == 0 || data_memory_->getr0() == 0) {
    throw "No se puede dividir entre 0";
  }
}