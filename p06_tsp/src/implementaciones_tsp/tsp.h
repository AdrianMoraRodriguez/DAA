#include <iostream>
#include <map>
#pragma once
#include "../elementos/ciudad.h"

class TSP {
 public:
  TSP(std::vector<Ciudad> ciudades = {});
  void leerInstancia(std::string nombreArchivo);
  virtual double resolver(std::string ciudad_de_inicio, int tiempo_maximo = 5) = 0;
  int getNumeroCiudades() { return ciudades_.size(); }
  void imprimir();
  std::string getNombreCiudad(int i) { return ciudades_[i].getNombre(); }
  int getPosicionCiudad(std::string nombre_ciudad) {
    return ciudades_en_vector_[nombre_ciudad];
  }
  void startFromAnother(TSP *tsp) {
    ciudades_ = tsp->ciudades_;
    ciudades_en_vector_ = tsp->ciudades_en_vector_;
  }
  void realese() {
    ciudades_.clear();
    ciudades_en_vector_.clear();
    mejorCamino_.clear();
  }
 protected:
  std::vector<Ciudad> ciudades_;
  std::vector<Ciudad> mejorCamino_;
  std::map<std::string, int> ciudades_en_vector_;
  double mejorDistancia_;
};