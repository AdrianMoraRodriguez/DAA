#include "problem.h"
#include "solution.h"

#pragma once

class LocalSearch {
 public:
  LocalSearch(const Problem &problem, const Solution &solution) : problem_(problem), solution_(solution) {
    problem_.set_points_not_in_solution(problem.get_points_not_in_solution());
  }
  Solution run();
 private:
  double evaluate_change(const std::vector<Point>& actual_solution, double actual_distance ,const Point& point_to_add, int position);
  Problem problem_;
  Solution solution_;
};