#include "grasp.h"

#pragma once

class GraspSwapIntra: public Grasp {
 public:
  GraspSwapIntra(Problem& problem, int lrc_size, int tries): Grasp(problem, lrc_size, tries) {}
  int tct_intra(int base_tct, const std::vector<int>& tasks, int j, int k, Problem& problem);
  Solution localSearch(Solution solution);
};