
#include "DivideAndConquer.h"

#pragma once


template <class P, class S>
class QuickSort : public DivideAndConquer<P, S> {
 public:
  QuickSort() : DivideAndConquer<P, S>(2) {}

  bool isSmall(const Problem<P>& problem, int length, int search) override {
    return length <= 1;
  }

  std::vector<Problem<P>> divide(const Problem<P>& problem, int length, int search, int how_many) override {
    if (how_many != 2) {
      throw std::invalid_argument("Quick sort must be divided by 2");
    }
    std::vector<Problem<P>> divided;
    Problem<P> left;
    Problem<P> right;
    int pivot = problem[length / how_many];
    for (int i = 0; i < length; i++) {
      if (problem[i] < pivot) {
        left.push_back(problem[i]);
      } else if (problem[i] >= pivot && i != length / how_many) {
        right.push_back(problem[i]);
      }
    }
    if (left.getProblem().size() < right.getProblem().size()) {
      left.push_back(pivot);
    } else {
      right.push_back(pivot);
    }
    divided.push_back(left);
    divided.push_back(right);
    return divided;
  }

  Solution<S> combine(const std::vector<Solution<S>>& solutions) override {
    Solution<S> combined;
    for (int i = 0; i < solutions[0].size(); i++) {
      combined.push_back(solutions[0][i]);
    }
    for (int i = 0; i < solutions[1].size(); i++) {
      combined.push_back(solutions[1][i]);
    }
    return combined;
  }

  Solution<S> makeSolution(const Problem<P>& problem, int search = 0) override {
    Solution<S> solution;
    solution.setSolution(problem.getProblem());
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
