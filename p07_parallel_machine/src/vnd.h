#include "algorithm.h"

#pragma once

class VND {
 public:
  VND(std::vector<Algorithm*> algorithm) {
    algorithms_ = algorithm;
  }
  Solution run(Solution solution);

 private:
  std::vector<Algorithm*> algorithms_;
};