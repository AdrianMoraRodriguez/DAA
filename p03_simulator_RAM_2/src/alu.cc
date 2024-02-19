/**
 * @file alu.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la ALU
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "alu.h"

/**
 * @brief Construye un nuevo objeto de la clase ALU
 * 
 * @param data_memory 
 */
ALU::ALU(DataMemory* data_memory) {
  data_memory_ = data_memory;
}