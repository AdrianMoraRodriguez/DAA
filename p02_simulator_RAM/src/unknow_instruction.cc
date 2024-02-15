

#include "unknow_instruction.h"


void UNKNOW::operate() const {
  try {
    isValid();
  } catch (const char* e) {
    throw e;
  }
}

void UNKNOW::isValid() const {
  throw "Instrucción no válida";
}