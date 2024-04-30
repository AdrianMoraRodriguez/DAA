#include <iostream>
#include <vector>

#include "problem.h"
#include "algorithm.h"
#include "greedy.h"
#include "local_search.h"
#include "grasp.h"
#include "tabu_search.h"

int main() {
  Problem problem;
  std::cout << "Introduce el nombre del archivo: ";
  std::string file_name;
  std::cin >> file_name;
  problem.Initialize(file_name);
  std::cout << "Introduce el valor de m: ";
  int m;
  std::cin >> m;
  std::cout << "Introduce el algoritmo a utilizar (1: Greedy y busqueda local, 2: GRASP, 3: GRASP con busqueda tabú): ";
  int algorithm_option;
  std::cin >> algorithm_option;
  Algorithm* algorithm;
  if (algorithm_option == 1) {
    algorithm = new Greedy(problem, m);
    Solution solution = algorithm->run();
    std::cout << "Greedy:\n";
    solution.print();
    std::cout << "\n";
    problem.set_points_not_in_solution(algorithm->get_unused_points());
    LocalSearch local_search = LocalSearch(problem, solution);
    solution = local_search.run();
    std::cout << "Local Search:\n";
    solution.print();
    std::cout << "\n";
  } else if (algorithm_option == 2) {
    std::cout << "Introduce el valor de lrc: ";
    int lrc;
    std::cin >> lrc;
    std::cout << "Introduce el valor de iteraciones: ";
    int iterations;
    std::cin >> iterations;
    algorithm = new GRASP(problem, lrc, m, iterations);
    Solution solution = algorithm->run();
    std::cout << "GRASP:\n";
    solution.print();
    std::cout << "\n";
  } else if (algorithm_option == 3) {
    std::cout << "Introduce el valor de tabu_tenure: ";
    int tabu_tenure;
    std::cin >> tabu_tenure;
    std::cout << "Introduce el máximo de iteraciones sin mejora: ";
    int max_iterations;
    std::cin >> max_iterations;
    std::cout <<"Introduce el valor de lrc: ";
    int lrc;
    std::cin >> lrc;
    std::cout << "Introduce el valor de iteraciones: ";
    int iterations;
    std::cin >> iterations;
    algorithm = new GRASP(problem, lrc, m, iterations);
    Solution solution = algorithm->run();
    problem.set_points_not_in_solution(algorithm->get_unused_points());
    std::cout << "GRASP:\n";
    solution.print();
    std::cout << "\n";
    TabuSearch tabu_search = TabuSearch(problem, solution, tabu_tenure, max_iterations);
    solution = tabu_search.run();
    std::cout << "Tabu Search:\n";
    solution.print();
    std::cout << "\n";
  }
  return 0;
}