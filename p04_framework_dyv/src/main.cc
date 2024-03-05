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
  Problem<std::vector<int>> problem;
  int instances;
  std::cout << "Introduzca el numero de instancias que desea: ";
  std::cin >> instances;
  int lenght;
  std::cout << "Introduzca los pasos que desea (si pone 10 las instancias serán 10, 100, 1000,...): ";
  int steps;
  std::cin >> steps;
  int starting_size = steps;
  bool debug = false;
  std::cout << "¿Desea activar el modo debug? (1 para sí, 0 para no): ";
  std::cin >> debug;
  generate_markdown_file("comparation.md");
  std::ofstream file("comparation.md", std::ios::app);
  DivideAndConquer<std::vector<int>, std::vector<int>>* merge_sort = new MergeSort<std::vector<int>, std::vector<int>>();
  DivideAndConquer<std::vector<int>, std::vector<int>>* quick_sort = new QuickSort<std::vector<int>, std::vector<int>>();
  for (int i = 0; i < instances; i++) {
    for (int j = 0; j < starting_size; j++) {
      problem.push_back(rand() % 1000);
    }
    if (debug) {
      std::cout << "Problema: ";
      for (int j = 0; j < starting_size; j++) {
        std::cout << problem.getProblem()[j] << " ";
      }
      std::cout << std::endl;
    }
    file << "| " << starting_size << " | ";
    lenght = problem.getProblem().size();
    std::clock_t start;
    double duration;
    start = std::clock();
    Solution<std::vector<int>> result = merge_sort->Solve(problem, lenght);
    if (debug) {
      std::cout << "MergeSort: ";
      for (int j = 0; j < starting_size; j++) {
        std::cout << result.getSolution()[j] << " ";
      }
      std::cout << std::endl;
    }
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    file << duration << " | ";
    file << result.get_level() << " | ";
    start = std::clock();
    result = quick_sort->Solve(problem, lenght);
    if (debug) {
      std::cout << "QuickSort: ";
      for (int j = 0; j < starting_size; j++) {
        std::cout << result.getSolution()[j] << " ";
      }
      std::cout << std::endl;
    }
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    file << duration << " |";
    file << result.get_level() << " |" << std::endl;
    starting_size *= steps;
  }
}