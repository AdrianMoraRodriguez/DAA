
#include "DivideAndConquer.h"

#pragma once


template <class P, class S>
class QuickSort : public DivideAndConquer<P, S> {
 public:
  QuickSort() : DivideAndConquer<P, S>(2) {}

  bool isSmall(const BaseProblem<P>* problem, int length) override {
    return length <= 1;
  }
  std::vector<BaseProblem<P>*> divide(const BaseProblem<P>* problem, int length, int how_many) override {
    if (how_many != 2) {
      throw std::invalid_argument("Quick sort must be divided by 2");
    }
    std::vector<BaseProblem<P>*> divided;
    BaseProblem<P>* left = new Problem<P>(); 
    BaseProblem<P>* right = new Problem<P>();
    int pivot_index = length / 2;
    const P& pivot = {(*problem)[pivot_index]};
    for (int i = 0; i < length; i++) {
      if (i == pivot_index) {
        continue;
      }
      if ((*problem)[i] < pivot[0]) {
        left->push_back((*problem)[i]);
      } else {
        right->push_back((*problem)[i]);
      }
    }
    if (left->size() < right->size()) {
      left->push_back(pivot[0]);
    } else {
      right->push_back(pivot[0]);
    }
    divided.push_back(left); 
    divided.push_back(right); 
    return divided;
  }

  Solution<S>* combine(const std::vector<Solution<S>*>& solutions, const BaseProblem<P>* problem) override {
    Solution<S>* combined = new Solution<S>();
    for (int i = 0; i < solutions[0]->size(); i++) {
      combined->push_back((*solutions[0])[i]);
    }
    for (int i = 0; i < solutions[1]->size(); i++) {
      combined->push_back((*solutions[1])[i]); 
    }
    return combined;
  }

  Solution<S>* makeSolution(const BaseProblem<P>* problem, int length) override {
    Solution<S>* solution = new Solution<S>();
    solution->setSolution(problem->getProblem());
    return solution;
  }

  std::string get_recursivity() override {
    return std::to_string(how_many_);
  }

  std::string get_factor() override {
    return "2";
  }

  std::string get_combine_complex() override {
    return "n";
  }
 private:
  int how_many_;
};
