/**
 * @file data_writter.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la escritura de datos
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include <vector>
#pragma once


/**
 * @brief Clase abstracta que representa la escritura de datos
 * 
 */
class DataWritter {
 public:
  virtual void Write(int address, int value, std::vector<int>& vector) = 0;
};