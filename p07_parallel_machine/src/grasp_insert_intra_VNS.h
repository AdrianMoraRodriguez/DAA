#include "grasp.h"

#pragma once

class GraspInsertIntraVNS: public Grasp {
 public:
  GraspInsertIntraVNS(Problem& problem, int lrc_size, int tries): Grasp(problem, lrc_size, tries) {}
  int tct_intra(int base_tct, const std::vector<int>& tasks, int position,int new_position, int element, Problem& problem);
  Solution localSearch(Solution solution);
};