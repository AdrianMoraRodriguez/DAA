#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "maquina.h"
#include "maquina_ram.h"
#include "maquina_ram_soft.h"
#include "maquina_ram_hard.h"


int main(int argc, char* argv[]) {
  if (argc == 2) {
    std::string arg = argv[1];
    if (arg == "-h" || arg == "--help") {
      std::cout << "Programa que simula la ejecución de una máquina RAM, además de distintos modos de debug" << std::endl;
      std::cout << "Uso: " << argv[0] << " <fichero_ensamblador> <fichero_entrada> <fichero_salida>" << std::endl;
      return 0;
    } else {
      std::cerr << "Argumento no válido" << std::endl;
      std::cerr << "Uso: " << argv[0] << " <fichero_ensamblador> <fichero_entrada> <fichero_salida>" << std::endl;
      return 1;
    }
  } else if (argc != 4) {
    std::cerr << "Error en el número de argumentos" << std::endl;
    std::cerr << "Uso: " << argv[0] << " <fichero_ensamblador> <fichero_entrada> <fichero_salida>" << std::endl;
    return 1;
  }
  int mode = 0;
  std::cout << "Seleccione el modo de ejecución (0: sin debug, 1 soft debug, 2: hard debug):";
  std::cin >> mode;
  Maquina* maquina_ram;
  std::string kFileName = argv[1];
  std::string kInputFileName = argv[2];
  std::string kOutputFileName = argv[3];
  int vector_size = 0;
  std::cout << "Introduzca el tamaño del vector (recomendado 10 a no ser que se necesite más (1 si no se usan vectores)): ";
  std::cin >> vector_size;
  if (mode == 0) {
    maquina_ram = new MaquinaRAM(kFileName, kInputFileName, kOutputFileName, vector_size);
  } else if (mode == 1) {
    maquina_ram = new MaquinaRAMSoft(kFileName, kInputFileName, kOutputFileName,vector_size);
  } else if (mode == 2) {
    maquina_ram = new MaquinaRAMHard(kFileName, kInputFileName, kOutputFileName,vector_size);
    std::cout << "Datos de depuración guardados en debug_info.txt" << std::endl;
  } else {
    std::cerr << "Modo no válido" << std::endl;
    return 1;
  }
  maquina_ram->Run();
  return 0;
}
