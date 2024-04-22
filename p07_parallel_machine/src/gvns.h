#include "algorithm.h"
#include "grasp_swap_intra_VNS.h"
#include "grasp_swap_inter_VNS.h"
#include "grasp_insert_intra_VNS.h"
#include "vnd.h"

#pragma once

class GVNS{
 public:
  GVNS(Problem& problem, std::vector<Algorithm*> algorithms, int kmax, int itermax) {
    problem_ = problem;
    vnd_ = new VND(algorithms);
    kmax_ = kmax;
    itermax_ = itermax;
    grasp_ = algorithms[0];
  }
  Solution run();
  Solution get_initial_solution() { return initial_solution_; }
 private:
  Algorithm* grasp_;
  Solution shake(Solution solution, int k);
  Problem problem_;
  VND* vnd_;
  int kmax_;
  int itermax_;
  Solution initial_solution_;
};