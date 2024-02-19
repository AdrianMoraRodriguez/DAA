/**
 * @file alu.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación del constructor de la clase ALU
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "alu.h"

ALU::ALU(DataMemory* data_memory) {
  data_memory_ = data_memory;
}