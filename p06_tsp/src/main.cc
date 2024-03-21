#include "./implementaciones_tsp/tsp.h"
#include "./implementaciones_tsp/tspVoraz.h"
#include "./implementaciones_tsp/tspFuerzaBruta.h"
#include "./implementaciones_tsp/tspPD.h"

#include <iostream>
#include <filesystem>
#include <fstream>
#include <chrono>
#include <ctime>

namespace fs = std::filesystem;

void makeMarkdownFile() {
  std::ofstream archivo("resultados.md", std::ios::app);
  if (archivo.tellp() != 0) {
    return;
  }
  archivo << "# Resultados de los algoritmos\n";
  archivo << "Todos los tiempos están en milisegundos\n";
  archivo << "| Archivo | Voraz | Tiempo Voraz | Fuerza Bruta | Tiempo Fuerza Bruta | Programación Dinámica | Tiempo Programación Dinámica |\n";
  archivo << "|---------|-------|--------------|--------------|---------------------|-----------------------|-----------------------------|\n";
}

int main() {
  std::string ruta = "/home/usuario/DAA/p06_tsp/test/";
  std::vector<std::string> archivos;
  for (const auto & entry : fs::directory_iterator(ruta)) {
    std::string nombre_archivo = entry.path();
    archivos.push_back(nombre_archivo);
  }
  TSP* tspVoraz = new TSPVoraz();
  TSP* tspFuerzaBruta = new TSPFuerzaBruta();
  TSP* tspPD = new TSPPD();
  std::cout << "Introduce el tiempo máximo para la ejecución de los algoritmos: ";
  int tiempo_maximo;
  std::cin >> tiempo_maximo;
  std::cout << "Introduzca el número de la ciudad de inicio: ";
  std::string ciudad_de_inicio;
  std::cin >> ciudad_de_inicio;
  int posicionCiudad = std::stoi(ciudad_de_inicio);
  std::vector<double> distancia_voraz;
  std::vector<double> distancia_fuerza_bruta;
  std::vector<double> distancia_programacion_dinamica;
  std::vector<double> tiempo_voraz;
  std::vector<double> tiempo_fuerza_bruta;
  std::vector<double> tiempo_programacion_dinamica;
  double tiempo = 0;
  makeMarkdownFile();
  double solucion;
  for (auto archivo : archivos) {
    std::ofstream archivoResultados("resultados.md", std::ios::app);
    std::cout << "Ejecutando " << archivo << std::endl;
    tspVoraz->leerInstancia(archivo);
    archivoResultados << "| " << archivo << " | ";
    std::cout << "Ejecutando Voraz" << std::endl;
    ciudad_de_inicio = tspVoraz->getNombreCiudad(posicionCiudad);
    auto start = std::chrono::high_resolution_clock::now();
    std::clock_t start_clock = std::clock();
    solucion = tspVoraz->resolver(ciudad_de_inicio, tiempo_maximo);
    distancia_voraz.push_back(solucion);
    auto end = std::chrono::high_resolution_clock::now();
    std::string string_to_push = std::to_string(solucion) + " | ";
    archivoResultados << string_to_push;
    tiempo_voraz.push_back((std::clock() - start_clock) / (double)CLOCKS_PER_SEC);
   auto duration = std::chrono::duration_cast<std::chrono::minutes>(end - start);
    if (duration.count() > tiempo_maximo) {
      archivoResultados << "EXCESIVO | ";
    } else {
      tiempo = (std::clock() - start_clock) / (double)CLOCKS_PER_SEC;
      std::string formatted_string = std::to_string(tiempo) + " | ";
      archivoResultados << formatted_string;
    }
    tspFuerzaBruta->startFromAnother(tspVoraz);
    tspVoraz->realese();
    std::cout << "Ejecutando Fuerza Bruta" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    start_clock = std::clock();
    solucion = tspFuerzaBruta->resolver(ciudad_de_inicio, tiempo_maximo);
    end = std::chrono::high_resolution_clock::now();
    distancia_fuerza_bruta.push_back(solucion);
    duration = std::chrono::duration_cast<std::chrono::minutes>(end - start);
    string_to_push = std::to_string(solucion) + " | ";
    archivoResultados << string_to_push;
    tiempo_fuerza_bruta.push_back((std::clock() - start_clock) / (double)CLOCKS_PER_SEC);
    if (duration.count() > tiempo_maximo) {
      archivoResultados << "EXCESIVO | ";
    } else {
      tiempo = (std::clock() - start_clock) / (double)CLOCKS_PER_SEC;
      std::string formatted_string = std::to_string(tiempo) + " | ";
      archivoResultados << formatted_string;
    }
    tspPD->startFromAnother(tspFuerzaBruta);
    tspFuerzaBruta->realese();
    std::cout << "Ejecutando Programación Dinámica" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    start_clock = std::clock();
    solucion = tspPD->resolver(ciudad_de_inicio, tiempo_maximo);
    end = std::chrono::high_resolution_clock::now();
    distancia_programacion_dinamica.push_back(solucion);
    duration = std::chrono::duration_cast<std::chrono::minutes>(end - start);
    string_to_push = std::to_string(solucion) + " | ";
    archivoResultados << string_to_push;
    tiempo_programacion_dinamica.push_back((std::clock() - start_clock) / (double)CLOCKS_PER_SEC);
    if (duration.count() > tiempo_maximo) {
      archivoResultados << "EXCESIVO | ";
    } else {
      tiempo = (std::clock() - start_clock) / (double)CLOCKS_PER_SEC;
      std::string formatted_string = std::to_string(tiempo) + " | ";
      archivoResultados << formatted_string;
    }
    archivoResultados << "\n";
    tspVoraz->realese();
    archivoResultados.close();
  }
  std::ofstream archivoResultados("resultados.md", std::ios::app);
  double suma_voraz = 0;
  double suma_fuerza_bruta = 0;
  double suma_programacion_dinamica = 0;
  double suma_tiempo_voraz = 0;
  double suma_tiempo_fuerza_bruta = 0;
  double suma_tiempo_programacion_dinamica = 0;
  for (int i = 0; i < distancia_voraz.size(); i++) {
    suma_voraz += distancia_voraz[i];
    suma_fuerza_bruta += distancia_fuerza_bruta[i];
    suma_programacion_dinamica += distancia_programacion_dinamica[i];
    suma_tiempo_voraz += tiempo_voraz[i];
    suma_tiempo_fuerza_bruta += tiempo_fuerza_bruta[i];
    suma_tiempo_programacion_dinamica += tiempo_programacion_dinamica[i];
  }
  archivoResultados << "| Media | " << suma_voraz / distancia_voraz.size() << " | " << suma_tiempo_voraz / distancia_voraz.size() << " | " << suma_fuerza_bruta / distancia_voraz.size() << " | " << suma_tiempo_fuerza_bruta / distancia_voraz.size() << " | " << suma_programacion_dinamica / distancia_voraz.size() << " | " << suma_tiempo_programacion_dinamica / distancia_voraz.size() << " |\n";
}