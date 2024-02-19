/**
 * @file unknow_instruction.cc 
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la operación UNKNOW 
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "unknow_instruction.h"

/**
 * @brief Realiza la operación UNKNOW
 * 
 */
void UNKNOW::operate() const {
  try {
    isValid();
  } catch (const char* e) {
    throw e;
  }
}

/**
 * @brief Comprueba si la operación es válida
 
 * 
 */
void UNKNOW::isValid() const {
  throw "Instrucción no válida";
}

/**
 * @brief Imprime la operación UNKNOW
 * 
 * @return std::string 
 */
std::string UNKNOW::printInstruction() const {
  return "UNKNOW\n";
}