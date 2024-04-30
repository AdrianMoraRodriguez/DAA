#include <map>
#include "problem.h"
#include "solution.h"

#pragma once

class TabuSearch {
 public:
  TabuSearch(const Problem &problem, const Solution &solution, int tabu_tenure, int max_iterations) : problem_(problem), solution_(solution) {
    problem_.set_points_not_in_solution(problem.get_points_not_in_solution());
    tabu_tenure_ = tabu_tenure;
    tabu_list_.resize(problem.get_points().size(), std::vector<int>(problem.get_points().size(), 0));
    max_iterations_without_improvement_ = max_iterations;
  }
  TabuSearch() {}
  TabuSearch(const Problem &problem) : problem_(problem) {}
  void set_solution(const Solution &solution) { solution_ = solution; }
  void set_problem(const Problem &problem) { problem_ = problem; }
  Solution run();
 private:
 void decreaseTabuTenure();
  bool tabuTenure(int i, int j);
  double evaluate_change(const std::vector<Point>& actual_solution, double actual_distance ,const Point& point_to_add, int position);
  Problem problem_;
  Solution solution_;
  std::vector<std::vector<int>> tabu_list_;
  int tabu_tenure_ = 10;
  int max_iterations_without_improvement_ = 10;
};