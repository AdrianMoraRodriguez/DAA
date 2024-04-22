#include "grasp.h"

#pragma once

class GraspSwapInterVNS: public Grasp {
 public:
  GraspSwapInterVNS(Problem& problem, int lrc_size, int tries): Grasp(problem, lrc_size, tries) {}
  std::pair<int, int> tct_inter(int tct_i, int tct_j, const std::vector<int>& tasks_i, const std::vector<int>& tasks_j, int k, int l, Problem& problem);
  Solution localSearch(Solution solution);
};