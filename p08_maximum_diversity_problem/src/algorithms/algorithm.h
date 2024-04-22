#include "problem.h"
#include "solution.h"

#pragma once

class Algorithm {
 public:
  Algorithm() {}
  Algorithm(Problem problem) {
    problem_ = problem;
  }
  virtual Solution run() = 0;
  Problem get_problem() {
    return problem_;
  }
  std::vector<Point> get_unused_points() {
    return problem_.get_points_not_in_solution();
  }
  void set_problem(Problem problem) {
    problem_ = problem;
  }
  Solution get_solution() {
    return solution_;
  }
 protected:
  Problem problem_;
  Solution solution_;
};