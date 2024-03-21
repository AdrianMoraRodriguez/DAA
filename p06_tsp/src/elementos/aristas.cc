#include "arista.h"

Arista::Arista() {
  ciudad1_ = "";
  ciudad2_ = "";
  distancia_ = 0;
}

Arista::Arista(std::string ciudad1, std::string ciudad2, double distancia) {
  ciudad1_ = ciudad1;
  ciudad2_ = ciudad2;
  distancia_ = distancia;
}

std::string Arista::getCiudad1() {
  return ciudad1_;
}

std::string Arista::getCiudad2() {
  return ciudad2_;
}

std::string Arista::getOtraCiudad(std::string ciudad) {
  if (ciudad == ciudad1_) {
    return ciudad2_;
  } else if (ciudad == ciudad2_) {
    return ciudad1_;
  } else {
    return "";
  }
}

double Arista::getDistancia() {
  return distancia_;
}

void Arista::imprimir() {
  std::cout << ciudad1_ << " - " << ciudad2_ << " : " << distancia_ << std::endl;
}