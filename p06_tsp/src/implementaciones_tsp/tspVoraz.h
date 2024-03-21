#include "tsp.h"
#pragma once

class TSPVoraz : public TSP {
 public:
  TSPVoraz(std::vector<Ciudad> ciudades = {}) : TSP(ciudades) {}
  double resolver(std::string ciudad_de_inicio, int tiempo_maximo = 5) override;
};