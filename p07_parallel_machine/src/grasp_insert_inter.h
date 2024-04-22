#include "grasp.h"

#pragma once

class GraspInsertInter: public Grasp {
 public:
  GraspInsertInter(Problem& problem, int lrc_size, int tries): Grasp(problem, lrc_size, tries) {}
  Solution localSearch(Solution solution);
};