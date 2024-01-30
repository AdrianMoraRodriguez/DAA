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
  virtual int Read(int address, const std::vector<int>& kVector) = 0;
};