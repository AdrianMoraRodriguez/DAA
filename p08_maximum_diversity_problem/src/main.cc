#include <iostream>
#include <vector>

#include "problem.h"
#include "algorithm.h"
#include "greedy.h"
#include "local_search.h"

int main() {
  Problem problem;
  std::cout << "Introduce el nombre del archivo: ";
  std::string file_name;
  std::cin >> file_name;
  problem.Initialize(file_name);
  std::cout << "Introduce el valor de m: ";
  int m;
  std::cin >> m;
  Algorithm* algorithm = new Greedy(problem, m);
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
  return 0;
}