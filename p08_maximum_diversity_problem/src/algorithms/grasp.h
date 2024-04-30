#include "algorithm.h"
#include "local_search.h"

#pragma once

class GRASP : public Algorithm {
 public:
  GRASP() {}
  GRASP(Problem problem, int lrc, int m, int iterations) {
    problem_ = problem;
    lrc_ = lrc;
    m_ = m;
    iterations_ = iterations;
    local_search_.set_problem(problem);
  }
  Solution run() override;
 private:
  int lrc_;
  int iterations_;
  int m_;
  LocalSearch local_search_;
};