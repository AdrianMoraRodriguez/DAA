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

class DataReader {
 public:
  virtual int Read(int address, const std::vector<int>& kVector) = 0;
};
//TODO lo que voy a hacer es encontrar si está el caracter * o =, cambiar al modo respectivo y al poner la operación, como entrada a la función se le pasa la salida de la lectura