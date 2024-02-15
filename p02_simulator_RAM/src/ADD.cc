#include "ADD.h"

void ADD::operate() const {
  try {
    isValid();
    int result = data_memory_->getr0() + data_reader_->Read(operand_, data_memory_->getRegisters());
    data_memory_->modifyMemory(0, result);
  } catch (const char* e) {
    throw e;
  }
}

void ADD::isValid() const {
  //everything is valid in the sum
}