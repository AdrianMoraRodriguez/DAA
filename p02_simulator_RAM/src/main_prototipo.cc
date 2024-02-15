#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "maquina_ram.h"


int main(int argc, char* argv[]) {
  if (argc != 4) {
    std::cerr << "Error en el número de argumentos" << std::endl;
    std::cerr << "Uso: " << argv[0] << " <fichero_ensamblador> <fichero_entrada>" << std::endl;
    return 1;
  }
  std::string kFileName = argv[1];
  std::string kInputFileName = argv[2];
  std::string kOutputFileName = argv[3];
  MaquinaRAM maquina_ram(kFileName, kInputFileName, kOutputFileName);
  maquina_ram.Run();
  return 0;
}

//TODO OPERACIONES QUE DEBEN FALLAR: Write 0, READ =, 