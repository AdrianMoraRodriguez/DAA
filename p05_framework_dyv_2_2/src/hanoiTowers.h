#include "DivideAndConquer.h"

#include "problemHanoi.h"

#pragma once

template <class P, class S>
class HanoiTowers : public DivideAndConquer<P, S> {
 public:
  HanoiTowers() {}

  bool isSmall(const BaseProblem<P>* problem, int length) override {
    return problem->getDiscs() <= 1;
  }

  std::vector<BaseProblem<P>*> divide(const BaseProblem<P>* problem, int length, int how_many) override {
    std::vector<BaseProblem<P>*> subproblems;
    BaseProblem<P>* subproblem1 = new ProblemHanoi<P>(problem->getDiscs() - 1, problem->getOrigin(), problem->getAux(), problem->getDestiny());
    BaseProblem<P>* subproblem2 = new ProblemHanoi<P>(problem->getDiscs() - 1, problem->getAux(), problem->getDestiny(), problem->getOrigin());
    subproblems.push_back(subproblem1);
    subproblems.push_back(subproblem2);
    return subproblems;
  }

  Solution<S>* combine(const std::vector<Solution<S>*>& solutions, const BaseProblem<P>* problem) override {
    Solution<S>* combined = new Solution<S>();
    for (int i = 0; i < solutions[0]->size(); i++) {
      combined->push_back((*solutions[0])[i]);
    }
    combined->push_back(problem->getDiscs());
    combined->push_back(problem->getOrigin());
    combined->push_back(problem->getDestiny());
    for (int i = 0; i < solutions[1]->size(); i++) {
      combined->push_back((*solutions[1])[i]);
    }
    return combined;
  }

  Solution<S>* makeSolution(const BaseProblem<P>* problem, int length) override {
    Solution<S>* solution = new Solution<S>();
    solution->setSolution({problem->getDiscs(),problem->getOrigin(), problem->getDestiny()});
    return solution;
  }

  std::string get_recursivity() override {
    return "2";
  }

  std::string get_factor() override {
    return "-1";
  }

  std::string get_combine_complex() override {
    return "n";
  }
};