#include <iostream>

#pragma once

class Arista {
 public:
  Arista(std::string ciudad1, std::string ciudad2, double distancia);
  Arista();
  std::string getCiudad1();
  std::string getCiudad2();
  std::string getOtraCiudad(std::string ciudad);
  double getDistancia();
  void imprimir();
 private:
  std::string ciudad1_;
  std::string ciudad2_;
  double distancia_;
};