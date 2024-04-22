#include <iostream>
#include <vector>

#include "algorithm.h"

#pragma once

class Greedy : public Algorithm {
 public:
  Greedy() {}
  Greedy(Problem problem, int m) {
    problem_ = problem;
    m_ = m;
  }
  Solution run() override;
 private:
  int m_;
};