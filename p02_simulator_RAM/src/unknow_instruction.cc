/**
 * @file unknow_instruction.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la operación UNKNOW
 * @version 0.1
 * @date 2024-01-30
 * 
 */
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