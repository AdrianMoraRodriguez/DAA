
#include "read.h"

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

void READ::isValid() const {
  if (operand_ < 0 ) {
    throw "No se puede escribir en una posición negativa";
  }
  if (operand_ == 0) {
    throw "No se puede escribir a el acumulador (R0)";
  }
}