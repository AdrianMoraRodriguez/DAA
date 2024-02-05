/**
 * @file alu.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la Unidad Aritmético-Lógica y control de flujo
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include <iostream>
#include <string>
#include <vector>

#pragma once

class ALU {
 public:
  ALU() {}
  ~ALU() {}
  virtual int operate(int r0, int operand) const = 0;
};