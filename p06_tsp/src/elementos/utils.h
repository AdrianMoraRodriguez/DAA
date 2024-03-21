#include <vector>
#include <string>

#include "ciudad.h"
#pragma once

inline bool estaEnCamino(std::vector<Ciudad> camino, std::string ciudad) {
  for (Ciudad ciudad_camino : camino) {
    if (ciudad_camino.getNombre() == ciudad) {
      return true;
    }
  }
  return false;
}