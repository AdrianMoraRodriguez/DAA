#include "store.h"

void STORE::operate() const {
  try {
    isValid();
    int vector_postion = data_reader_in_vector_->ReadPosition(position_in_vector_, data_memory_->getRegisters());
    int operand = data_reader_->ReadPosition(operand_, data_memory_->getRegisters());
    data_memory_->modifyMemory(operand, vector_postion, data_memory_->getr0());
  } catch (const char* e) {
    throw e;
  }
}

void STORE::isValid() const {
  if (operand_ == 0) {
    throw "No se puede guardar el acumulador en el propio acumulador (R0)";
  }
  if (data_reader_name_ == "constant") {
    throw "No se puede hacer store en una constante";
  }
}
