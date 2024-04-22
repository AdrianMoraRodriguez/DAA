#include "algorithm.h"
#include "solution.h"
#include <algorithm>

#pragma once

class Grasp: public Algorithm {
 public:
  Grasp(Problem& problem, int lrc_size, int tries): Algorithm(problem) {
    lrc_size_ = lrc_size;
    tries_ = tries;
  }
  Solution run();
  virtual Solution localSearch(Solution solution) = 0;
 private:
  int lrc_size_;
  int tries_ = 5;
};