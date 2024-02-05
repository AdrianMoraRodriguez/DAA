/**
 * @file constast_data_writter.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la escritura de datos
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include "constant_data_writter.h"

void ContastDataWritter::Write(int address, int value, std::vector<int>& vector) {
  vector[address] = value;
}