/**
 * @file JUMP.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la operación JUMP
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "JUMP.h"

void JUMP::operate() const {
  try {
    isValid();
    *pc_ = new_position_ - 1;
  } catch (const char* e) {
    throw e;
  }
}

void JUMP::isValid() const {
  if (new_position_ < 0) {
    throw "Error: Se ha intentado saltar a una posición negativa.";
  }
}