#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "program_memory.h"


int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Error en el número de argumentos" << std::endl;
    std::cerr << "Uso: " << argv[0] << " <fichero_ensamblador>" << std::endl;
    return 1;
  }
  ProgramMemory program_memory;
  program_memory.loadProgram(argv[1]);
  program_memory.printProgram();
  return 0;
}