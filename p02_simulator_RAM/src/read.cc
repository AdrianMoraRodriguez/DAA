
#include "read.h"

void READ::operate() const {
  try {
    isValid();
    if (data_reader_name_ == "direct") {
      data_memory_->modifyMemory(operand_, input_tape_->getNextInput());
    } else {
      data_memory_->modifyMemory(data_memory_->getRegisters()[operand_], input_tape_->getNextInput());
    }
  } catch (const char* e) {
    throw e;
  } catch (...) {
    throw "Error desconocido en READ";
  }
}

void READ::isValid() const {
  if (operand_ < 0 ) {
    throw "No se puede escribir en una posición negativa";
  }
  if (operand_ == 0) {
    throw "No se puede escribir a el acumulador (R0)";
  }
  if (data_reader_name_ == "error") {
    throw "Error: data_reader_name_ is error";
  }
  if (data_reader_name_ == "error") {
    throw "Error: data_reader_name_ is error";
  }
}