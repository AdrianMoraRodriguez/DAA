/**
 * @file data_memory.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la memoria de datos
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include <iostream>
#include <string>
#include <vector>

#pragma once

class DataMemory {
 public: 
  DataMemory(int number_of_registers = 40) : registers_(number_of_registers, 0) {}
  ~DataMemory() {}
  void Load(int address, int value); //TODO Cambiar esta función cuando tenga implementado el data_writter
  int Read(int address); //TODO Cambiar esta función cuando tenga implementado el data_reader
 private:
  std::vector<int> registers_;
  //TODO Añadir como atributos el data_reader y el data_writter
};

// [ ] Hacer un main básico para probar la lectura de un fichero y ver si se parsea bien