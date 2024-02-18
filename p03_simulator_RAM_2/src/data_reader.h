/**
 * @file data_reader.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la lectura de datos
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include <vector>
#pragma once

/**
 * @brief Clase abstracta que representa la lectura de datos
 * 
 */
class DataReader {
 public:
  virtual int Read(int address, int vector_address ,const std::vector<std::vector<int>>& kVector) = 0;
  virtual int ReadPosition(int address ,const std::vector<std::vector<int>>& kVector) = 0;
};