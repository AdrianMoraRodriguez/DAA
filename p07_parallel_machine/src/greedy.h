#include "problem.h"
#include "solution.h"
#include "algorithm.h"

#pragma once

class Greedy : public Algorithm {
 public:
  Greedy(Problem problem) : Algorithm(problem) {}
  Solution run() override;
  Solution localSearch(Solution solution) override {return solution;};
};