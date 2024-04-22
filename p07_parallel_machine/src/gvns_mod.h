#include "algorithm.h"
#include "grasp_swap_intra.h"
#include "grasp_swap_inter.h"
#include "grasp_insert_intra.h"
#include "vnd.h"

#pragma once

class GVNSMod{ // MODIFICACION
 public:
  GVNSMod(Problem& problem, std::vector<Algorithm*> algorithms, int kmax, int itermax) {
    problem_ = problem;
    algorithms_ = algorithms;
    vnd_ = new VND(algorithms);
    kmax_ = kmax;
    itermax_ = itermax;
    grasp_ = algorithms[0];
  }
  Solution run();
  Solution get_initial_solution() { return initial_solution_; }
 private:
  Algorithm* grasp_;
  Solution modification(Solution solution); // MODIFICACION
  Solution shake(Solution solution, int k);
  std::vector<Algorithm*> algorithms_;
  Problem problem_;
  VND* vnd_;
  int kmax_;
  int itermax_;
  Solution initial_solution_;
};