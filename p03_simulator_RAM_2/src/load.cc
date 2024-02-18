#include "load.h"

void LOAD::operate() const {
  try {
    isValid();
    int vector_postion = data_reader_in_vector_->ReadPosition(position_in_vector_, data_memory_->getRegisters());
    data_memory_->load(data_reader_->Read(operand_, vector_postion, data_memory_->getRegisters()));
  } catch (const char* e) {
    throw e;
  }
}

void LOAD::isValid() const {
  if (operand_ == 0 && data_reader_name_ != "constant") {
    throw "No se puede hacer un load desde el propio acumulador (R0)";
  }
}
