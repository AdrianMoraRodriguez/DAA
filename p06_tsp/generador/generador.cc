#include <iostream>
#include <fstream>
#include <map>

void generador (int numeroArchivos, int maximos_nodos) {
  for (int i = 0; i < numeroArchivos; i++) {
    int n = rand() % maximos_nodos + 1;
    std::string nombre = "grafo" + std::to_string(i);
    std::string ruta = "/home/usuario/DAA/p06_tsp/test/";
    std::string ruta_archivo = ruta + nombre + ".txt";
    std::ofstream archivo(ruta_archivo);
    archivo << n << std::endl;
    std::map<std::pair<int, int>, bool> aristas;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (aristas[{i, j}] == false) {
          archivo << i << " " << j << " " << rand() % 1000 << std::endl;
          aristas[{i, j}] = true;
          aristas[{j, i}] = true;
        }
      }
    }
    archivo.close();
  }
}

int main() {
  std::cout << "Introduce el número de nodos máximo: ";
  int n;
  std::cin >> n;
  std::cout << "Introduce el número de archivos que quieres: ";
  int numeroArchivos;
  std::cin >> numeroArchivos;
  generador(numeroArchivos, n);
}
