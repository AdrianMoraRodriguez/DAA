#include <chrono>
#include <algorithm>

#include "tspFuerzaBruta.h"

double TSPFuerzaBruta::resolver(std::string ciudad_de_inicio, int tiempo_maximo) {
  auto start = std::chrono::high_resolution_clock::now();
  int n = ciudades_.size();
  std::vector<Ciudad> recorrido = {};
  int mejor_distancia = 0;
  recorrido.push_back(ciudades_[getPosicionCiudad(ciudad_de_inicio)]);
  for (int i = 1; i < n; i++) {
    recorrido.push_back(ciudades_[i]);
    mejor_distancia += ciudades_[i].getAristaConCiudad(ciudades_[i - 1].getNombre()).getDistancia();
  }
  std::vector<Ciudad> mejor_recorrido = recorrido;
  do {
    int distancia = 0;
    for (int i = 1; i < n; i++) {
      distancia += recorrido[i].getAristaConCiudad(recorrido[i - 1].getNombre()).getDistancia();
    }
    distancia += recorrido[0].getAristaConCiudad(recorrido[n - 1].getNombre()).getDistancia();
    if (distancia < mejor_distancia) {
      mejor_distancia = distancia;
      mejor_recorrido = recorrido;
    }
    auto current = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::minutes>(current - start);
    if (duration.count() > tiempo_maximo) {
      if (duration.count() < 10) {
        continue;
      }
      mejorCamino_ = mejor_recorrido;
      mejorDistancia_ = mejor_distancia;
      return mejor_distancia;
    }
  } while (next_permutation(recorrido.begin() + 1, recorrido.end()));
  mejorDistancia_ = mejor_distancia;
  mejorCamino_ = mejor_recorrido;
  mejorCamino_.push_back(mejorCamino_[0]);
  return mejor_distancia;
}