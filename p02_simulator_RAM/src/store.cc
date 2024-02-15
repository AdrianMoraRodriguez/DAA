#include "store.h"

void STORE::operate() const {
  try {
    isValid();
    if (data_reader_name_ == "direct") {
      data_memory_->modifyMemory(operand_, data_memory_->getr0());
    } else {
      data_memory_->modifyMemory(data_memory_->getRegisters()[operand_], data_memory_->getr0());
    }
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
