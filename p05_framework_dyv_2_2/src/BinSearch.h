#include "DivideAndConquer.h"
#include "problemBin.h"

#pragma once

template <class P, class S>
class BinSearch : public DivideAndConquer<P, S> {
 public:
  BinSearch() {}
  bool isSmall(const BaseProblem<P>* problem, int length) override {
    int mid = (problem->getIni() + problem->getFin()) / 2;
    if (problem->getIni() == problem->getFin()) {
      return true;
    }
    if (problem->getIni() >= problem->getFin()) {
      return true;
    }
    return false;
  }

  std::vector<BaseProblem<P>*> divide(const BaseProblem<P>* problem, int length, int how_many) {
    std::vector<BaseProblem<P>*> subproblems;
    int start = problem->getIni();
    int end = problem->getFin();
    int search = problem->getSearch();
    int mid = (start + end) / 2;
    BaseProblem<P>* subproblem;
    if (search < (*problem)[mid]) {
      subproblem = new ProblemBin<P>((*problem).getProblem(), search, start, mid - 1);
      subproblems.push_back(subproblem);
    } else if (search > (*problem)[mid]) {
      subproblem = new ProblemBin<P>((*problem).getProblem(), search, mid + 1, end);
      subproblems.push_back(subproblem);
    } else {
      subproblem = new ProblemBin<P>((*problem).getProblem(), search, mid, mid);
      subproblems.push_back(subproblem);
    }
    return subproblems;
  }

  Solution<S>* makeSolution(const BaseProblem<P>* problem, int length) {
    Solution<S>* solution = new Solution<S>();
    int mid = (problem->getIni() + problem->getFin()) / 2;
    if ((*problem)[mid] == problem->getSearch()) {
      solution->setSolution({mid});
    } else {
      solution->setSolution({-1});
    }
    return solution;
  }

  Solution<S>* combine(const std::vector<Solution<S>*>& solutions, const BaseProblem<P>* problem) {
    Solution<S>* combined = new Solution<S>();
    for (int i = 0; i < solutions.size(); i++) {
      if (solutions[i]->getSolution()[0] != -1) {
        combined->setSolution(solutions[i]->getSolution());
      }
    }
    if (combined->getSolution().size() == 0) {
      combined->setSolution({-1});
    }
    return combined;
  }

  std::string get_recursivity() {
    return "1";
  }

  std::string get_factor() {
    return "2";
  }

  std::string get_combine_complex() {
    return "1";
  }

};