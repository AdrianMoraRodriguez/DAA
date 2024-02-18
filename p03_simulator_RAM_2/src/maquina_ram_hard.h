/**
 * @file maquina_ram_hard.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la maquina RAM con debugger mostrando líneas al final y el estado de la máquina tras cada instrucción
 * @version 0.1
 * @date 2024-01-30
 * 
 */

#include <iostream>
#include <string>
#include <vector>

#include "maquina.h"

#pragma once

class MaquinaRAMHard: public Maquina {
 public:
  MaquinaRAMHard() {}
  MaquinaRAMHard(const std::string& kFileName, const std::string& kInputFileName, const std::string& kOutputFile,int vector_length = 10,int number_of_registers = 40);
  ~MaquinaRAMHard() {}
  void Run() override;
 private:
  int lines_executed_ = 0;
};