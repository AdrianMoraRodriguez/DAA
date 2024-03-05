
#include <iostream>

#pragma once

/**
 * @brief Clase Problem
 * 
 * @tparam T 
 */
template <typename T>
class Problem {
 public:
  Problem(const T& kProblemGiven): problem_(kProblemGiven) {}
  Problem() {}
  T getProblem() const { return problem_; }
  void setProblem(const T& kProblemGiven) { problem_ = kProblemGiven; }
  void push_back(const int& kProblemGiven) { problem_.push_back(kProblemGiven); }
  int operator[](const int& kIndex) const { return problem_[kIndex]; } const
  int size() const { return problem_.size(); }
 private:
  T problem_;
};