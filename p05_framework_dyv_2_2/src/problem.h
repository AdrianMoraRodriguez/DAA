#include <iostream>

#include "baseProblem.h"

#pragma once

/**
 * @brief Clase Problem
 * 
 * @tparam T 
 */
template <typename T>
class Problem: public BaseProblem<T> {
 public:
  Problem(const T& kProblemGiven): BaseProblem<T>(kProblemGiven) {}
  Problem() {}
  void push_back(const int& kProblemGiven) { this->problem_.push_back(kProblemGiven); }
  int operator[](const int& kIndex) const { return this->problem_[kIndex]; }
  int size() const { return this->problem_.size(); }
  void setProblem(const T& kProblemGiven) { this->problem_ = kProblemGiven; }
};