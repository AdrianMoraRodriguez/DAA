/**
 * @file main.cc
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la función main
 * @version 0.1
 * @date 2024-03-04
 * 
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "DivideAndConquer.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "BinSearch.h"
#include "HanoiTowers.h"

void generate_markdown_file(const std::string& kFileName) {
  std::ofstream file(kFileName, std::ios::app);
  if (file.tellp() != 0) {
    return;
  }
  file << "# Comparación de algoritmos de ordenación" << std::endl;
  file << "## Introducción" << std::endl;
  file << "En este documento se compararán los algoritmos de ordenación MergeSort y QuickSort." << std::endl;
  file << "## Metodología" << std::endl;
  file << "Se han generado instancias aleatorias de distintos tamaños" << std::endl;
  file << "## Resultados" << std::endl;
  file << "| Tamaño | MergeSort | Nivel M | Quicksort | Nivel Q |" << std::endl;
  file << "|--------|-----------|-----------|-----------|-----------|" << std::endl;
  file.close();
}


int main() {
  // modo normal donde se elige algorimo y se ejecuta con distiontos tamaños y se muestra el tiempo de ejecución y modo debug donde se elige algoritmo y tamaño y se muestra por pantalla la instancia y la solución
  std::vector<int> problem;
  srand(time(NULL));
  int lenght;
  std::cout << "Introduzca el tamaño del problema: ";
  std::cin >> lenght;
  int starting_size = lenght;
  bool debug = false;
  std::cout << "¿Desea activar el modo debug? (1 para sí, 0 para no): ";
  std::cin >> debug;
  //preguntar por el algoritmo
  std::cout << "¿Qué algoritmo desea ejecutar? (1 para MergeSort, 2 para QuickSort, 3 para búsqueda binaria, 4 Hannoi): ";
  int algorithm;
  std::cin >> algorithm;
  DivideAndConquer<std::vector<int>, std::vector<int>>* algorithm_to_use;
  bool binary_search = false;
  bool hanoi = false;
  int how_many = 2;
  switch (algorithm) {
    case 1:
      algorithm_to_use = new MergeSort<std::vector<int>, std::vector<int>>();
      break;
    case 2:
      algorithm_to_use = new QuickSort<std::vector<int>, std::vector<int>>();
      break;
    case 3:
      algorithm_to_use = new BinSearch<std::vector<int>, std::vector<int>>();
      binary_search = true;
      how_many = 1;
      break;
    case 4:
      hanoi = true;
      how_many = 2;
      break;
    default:
      std::cout << "Algoritmo no válido" << std::endl;
      return 0;
  }
  int search = 0;
  //genera varios tamños de instancia aleatorias y ejecuta el algoritmo
  for (int i = 0; i < 10; i++) {
    problem.clear();
    for (int j = 0; j < starting_size; j++) {
      problem.push_back(rand() % 1000);
    }
    if (debug || binary_search) {
      if (binary_search) {
        std::sort(problem.begin(), problem.end());
      }
      std::cout << "Problema: ";
      for (int j = 0; j < starting_size; j++) {
        std::cout << problem[j] << " ";
      }
      std::cout << std::endl;
    }
    std::clock_t start;
    double duration;
    if (hanoi) {
      std::cout << "Cambiando problema a 1 2 3\n";
      problem.clear();
      problem.push_back(3);
      problem.push_back(2);
      problem.push_back(3);
      problem.push_back(4);
    }
    if (binary_search) {
      std::cout << "Introduzca el número que desea buscar: ";
      std::cin >> search;
      problem.push_back(0);
      problem.push_back(starting_size);
      lenght = problem.size();
    }
    if (hanoi) {
       DivideAndConquer<std::vector<int>, std::vector<std::vector<int>>>* hanoi_towers = new HanoiTowers<std::vector<int>, std::vector<std::vector<int>>>();
      start = std::clock();
      Solution<std::vector<std::vector<int>>> result = hanoi_towers->Solve(problem, lenght, search, how_many);
      if (debug) {
        std::cout << "Solución: ";
        for (int j = 0; j < result.size(); j++) {
          std::cout << "Pieza: " << result.getSolution()[j][0] << " desde " << result.getSolution()[j][1] << " hasta " << result.getSolution()[j][2] << "\n";
        }
      } else {
        duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
        std::cout << "Tiempo de ejecución: " << duration << " segundos" << std::endl;
      }
    } else {
      start = std::clock();
      Solution<std::vector<int>> result = algorithm_to_use->Solve(problem, lenght, search, how_many);
      if (debug) {
        std::cout << "Solución: ";
        for (int j = 0; j < result.size(); j++) {
          std::cout << result.getSolution()[j] << " ";
        }
        std::cout << std::endl;
      }
      duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
      std::cout << "Tiempo de ejecución: " << duration << " segundos" << std::endl;
      starting_size *= 2;
    }
  }
}