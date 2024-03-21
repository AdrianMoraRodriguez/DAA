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
#include "hanoiTowers.h"
#include "fib.h"

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
  file << "| Tamaño | Tiempo |" << std::endl;
  file << "|--------|-----------|" << std::endl;
  file.close();
}


int main() {
  std::string file_name = "results.md";
  generate_markdown_file(file_name);
  std::vector<int> vector_problem;
  BaseProblem<std::vector<int>>* problem;
  srand(time(NULL));
  bool debug = false;
  std::cout << "¿Desea activar el modo debug? (1 para sí, 0 para no): ";
  std::cin >> debug;
  std::cout << "¿Qué algoritmo desea ejecutar? (1 para MergeSort, 2 para QuickSort, 3 para búsqueda binaria, 4 Hannoi, 5 fib): ";
  int algorithm;
  std::cin >> algorithm;
  int lenght = 1;
  if (algorithm != 4 && algorithm != 5) {
    std::cout << "Introduzca el tamaño del problema: ";
    std::cin >> lenght;
  }
  int starting_size = lenght;
  DivideAndConquer<std::vector<int>, std::vector<int>>* algorithm_to_use;
  bool binary_search = false;
  bool hanoi = false;
  int how_many = 2;
  switch (algorithm) {
    case 1:
      algorithm_to_use = new MergeSort<std::vector<int>, std::vector<int>>();
      problem = new Problem<std::vector<int>>(vector_problem);
      break;
    case 2:
      algorithm_to_use = new QuickSort<std::vector<int>, std::vector<int>>();
      problem = new Problem<std::vector<int>>(vector_problem);
      break;
    case 3:
      algorithm_to_use = new BinSearch<std::vector<int>, std::vector<int>>();
      problem = new ProblemBin<std::vector<int>>(vector_problem, 0, 0, vector_problem.size());
      binary_search = true;
      how_many = 1;
      break;
    case 4:
      algorithm_to_use = new HanoiTowers<std::vector<int>, std::vector<int>>();
      hanoi = true;
      how_many = 2;
      break;
    case 5:
      algorithm_to_use = new Fibonacci<std::vector<int>, std::vector<int>>();
      problem = new Problem<std::vector<int>>({0});
      break;
    default:
      std::cout << "Algoritmo no válido" << std::endl;
      return 0;
  }
  int search = 0;
  for (int i = 0; i < 10; i++) {
    vector_problem.clear();
    for (int j = 0; j < starting_size; j++) {
      vector_problem.push_back(rand() % 1000);
    }
    if ((debug && !hanoi && algorithm != 5)|| binary_search) {
      if (binary_search) {
        std::sort(vector_problem.begin(), vector_problem.end());
      }
      std::cout << "Problema: ";
      for (int j = 0; j < starting_size; j++) {
        std::cout << vector_problem[j] << " ";
      }
      std::cout << std::endl;
    }
    std::clock_t start;
    double duration;
    if (hanoi) {
      std::cout << "Introduzca el número de discos: ";
      int discs;
      std::cin >> discs;
      problem = new ProblemHanoi<std::vector<int>>(discs, 'A', 'C', 'B');
      lenght = discs;
    } else {
      problem->setProblem(vector_problem);
      if (binary_search) {
        std::cout << "Introduzca el número que desea buscar: ";
        std::cin >> search;
        problem->setSearch(search);
        problem->setIni(0);
        problem->setFin(vector_problem.size());
      }
      if (algorithm == 5) {
        std::cout << "Introduzca el número de Fibonacci que desea calcular: ";
        int fib;
        std::cin >> fib;
        problem->setFib(fib);
      }
      lenght = vector_problem.size();
    }
    start = std::clock();
    Solution<std::vector<int>>* result = algorithm_to_use->Solve(problem, lenght, how_many);
    if (debug) {
      std::cout << "Solución: ";
      if (hanoi) {
        std::cout << "Movimientos: " << result->size() / 3 << std::endl;
        result->printHanoi();
      } else if (algorithm == 5) {
        std::cout << "Fibonacci: " << result->getSolution()[0] << std::endl;
      } else {
        for (int j = 0; j < result->size(); j++) {
          std::cout << result->getSolution()[j] << " ";
        }
        std::cout << std::endl;
      }
    }
    std::ofstream file(file_name, std::ios::app);
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    file << "|" << starting_size << "|" << duration << "|" << std::endl;
    std::cout << "Tiempo de ejecución: " << duration << " segundos" << std::endl;
    starting_size *= 2;
  }
}
