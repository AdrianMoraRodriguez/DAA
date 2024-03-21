#include "ciudad.h"

Ciudad::Ciudad(std::string nombre, std::vector<Arista> aristas) {
  nombre_ = nombre;
  aristas_ = aristas;
}

void Ciudad::agregarArista(Arista arista) {
  aristas_.push_back(arista);
}

std::string Ciudad::getNombre() {
  return nombre_;
}

std::vector<Arista> Ciudad::getAristas() {
  return aristas_;
}

Arista Ciudad::getAristaConCiudad(std::string ciudad) {
  for (Arista arista : aristas_) {
    if (arista.getOtraCiudad(nombre_) == ciudad) {
      return arista;
    }
  }
  return Arista("", "", 0);
}

void Ciudad::imprimir() {
  std::cout << nombre_ << std::endl;
  for (Arista arista : aristas_) {
    arista.imprimir();
  }
}

bool Ciudad::operator<(const Ciudad &ciudad) const {
  return nombre_ < ciudad.nombre_;
}