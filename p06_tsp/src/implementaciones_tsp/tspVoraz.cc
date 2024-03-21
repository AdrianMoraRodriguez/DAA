#include <chrono>
#include "tspVoraz.h"
#include "../elementos/utils.h"

double TSPVoraz::resolver(std::string ciudad_de_inicio, int tiempo_maximo) {
  auto start = std::chrono::high_resolution_clock::now();
  std::vector<Ciudad> ciudades = ciudades_;
  std::vector<Ciudad> camino;
  double distancia = 0;
  Ciudad ciudad_actual = ciudades[getPosicionCiudad(ciudad_de_inicio)];
  camino.push_back(ciudad_actual);
  for (int i = 1; i < ciudades.size(); i++) {
    std::vector<Arista> aristas = ciudad_actual.getAristas();
    Arista arista_mas_corta;
    double distancia_mas_corta = 9999999;
    for (Arista arista : aristas) {
      if (arista.getDistancia() < distancia_mas_corta) {
        if (estaEnCamino(camino, arista.getOtraCiudad(ciudad_actual.getNombre()))) {
          continue;
        }
        arista_mas_corta = arista;
        distancia_mas_corta = arista.getDistancia();
      }
    }
    ciudad_actual = ciudades[getPosicionCiudad(arista_mas_corta.getOtraCiudad(ciudad_actual.getNombre()))];
    camino.push_back(ciudad_actual);
    distancia += distancia_mas_corta;
    auto current = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::minutes>(current - start);
    if (duration.count() > tiempo_maximo) {
      if (duration.count() < 10) {
        continue;
      }
      mejorCamino_ = camino;
      mejorDistancia_ = distancia;
      return distancia;
    }
  }
  mejorCamino_ = camino;
  mejorCamino_.push_back(mejorCamino_[0]);
  mejorDistancia_ = distancia + camino[0].getAristaConCiudad(camino[camino.size() - 1].getNombre()).getDistancia();
  mejorDistancia_ = distancia;
  distancia += camino[0].getAristaConCiudad(camino[camino.size() - 1].getNombre()).getDistancia();
  return distancia;
}