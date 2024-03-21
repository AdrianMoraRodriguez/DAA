#include <fstream>
#include <map>
#include "tsp.h"

TSP::TSP(std::vector<Ciudad> ciudades) {
  ciudades_ = ciudades;
  mejorDistancia_ = 0;
}

void TSP::leerInstancia(std::string nombreArchivo) {
  ciudades_.clear();
  mejorCamino_.clear();
  mejorDistancia_ = 0;
  std::ifstream archivo(nombreArchivo);
  if (!archivo) {
    std::cout << "No se pudo abrir el archivo" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::string ciudad1, ciudad2;
  double distancia;
  int numCiudades;
  archivo >> numCiudades;
  std::map<std::string, int> aristas_por_ciudad;
  std::map<std::string, int> ciudades_en_vector;
  int num_ciudades_actuales = 0;
  for (int i = 0; i < numCiudades * (numCiudades - 1) / 2; i++) {
    archivo >> ciudad1 >> ciudad2 >> distancia;
    Arista arista1(ciudad1, ciudad2, distancia);
    if (aristas_por_ciudad.find(ciudad1) == aristas_por_ciudad.end()) {
      aristas_por_ciudad[ciudad1] = 0;
      ciudades_en_vector[ciudad1] = num_ciudades_actuales;
      num_ciudades_actuales++;
      ciudades_.push_back(Ciudad(ciudad1, std::vector<Arista>()));
    }
    if (aristas_por_ciudad.find(ciudad2) == aristas_por_ciudad.end()) {
      aristas_por_ciudad[ciudad2] = 0;
      ciudades_en_vector[ciudad2] = num_ciudades_actuales;
      num_ciudades_actuales++;
      ciudades_.push_back(Ciudad(ciudad2, std::vector<Arista>()));
    }
    ciudades_[ciudades_en_vector[ciudad1]].agregarArista(arista1);
    ciudades_[ciudades_en_vector[ciudad2]].agregarArista(arista1);
  }
  archivo.close();
  if (ciudades_.size() != numCiudades) {
    std::cout << "Error en el archivo, el número de ciudades no coincide con el especificado" << std::endl;
    exit(EXIT_FAILURE);
  }
  for (Ciudad ciudad : ciudades_) {
    if (ciudad.getAristas().size() != numCiudades - 1) {
      std::cout << "Error en el archivo, el grafo indicado no es completo" << std::endl;
      exit(EXIT_FAILURE);
    }
  }
  ciudades_en_vector_ = ciudades_en_vector;
}

void TSP::imprimir() {
  for (Ciudad ciudad : ciudades_) {
    ciudad.imprimir();
  }
}