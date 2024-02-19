/**
 * @file direct_data_reader.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la lectura de datos directa
 * @version 0.1
 * @date 2024-01-30
 * 
 */
#include "data_reader.h"

#pragma once

class DirectDataReader : public DataReader {
 public:
  int Read(int address, const std::vector<int>& kVector) override;
};