/**
 * @file indirect_data_writter.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la escritura de datos
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "data_writter.h"

#pragma once

class IndirectDataWritter : public DataWritter {
 public:
  void Write(int address, int value, std::vector<int>& vector) override;
};