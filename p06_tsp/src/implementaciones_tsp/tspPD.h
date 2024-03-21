#include "tsp.h"

class TSPPD : public TSP {
 public:
  TSPPD(std::vector<Ciudad> ciudades = {}) : TSP(ciudades) {}
  double resolver(std::string ciudad_de_inicio, int tiempo_maximo = 5) override;
  double resolverRecursivo(int pos, int bitmask, std::vector<std::vector<double>>& dp, std::vector<std::vector<double>>& dist, int tiempo_maximo);
};