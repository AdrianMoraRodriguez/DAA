#include <iostream>
#include <vector>

#pragma once

#include "arista.h"

class Ciudad {
 public:
  Ciudad(std::string nombre, std::vector<Arista> aristas = {});
  Ciudad() {}
  void agregarArista(Arista arista);
  std::string getNombre();
  std::vector<Arista> getAristas();
  Arista getAristaConCiudad(std::string ciudad);
  void imprimir();
  bool operator<(const Ciudad &ciudad) const;
 private:
  std::string nombre_;
  std::vector<Arista> aristas_;
};