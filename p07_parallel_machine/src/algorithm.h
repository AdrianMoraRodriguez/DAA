#include "problem.h"
#include "solution.h"

#pragma once

class Algorithm {
 public:
  Algorithm(Problem problem) {
    problem_ = problem;
  }
  virtual Solution run() = 0;
  void set_up();
  void set_problem(Problem problem) {
    problem_ = problem;
  }
  virtual Solution localSearch(Solution solution) = 0;
 protected:
  Problem problem_;
  Solution best_solution_;
};