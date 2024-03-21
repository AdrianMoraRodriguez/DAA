/**
 * @file solution.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la clase Solution
 * @version 0.1
 * @date 2024-03-04
 * 
 */
#include <iostream>

#pragma once

/**
 * @brief Clase Solution
 * 
 * @tparam T
 */
template <typename T>
class Solution {
 public:
  Solution(const T& kSolutionGiven): solution_(kSolutionGiven) {}
  Solution() {}
  T getSolution() const { return solution_; }
  void setSolution(const T& kSolutionGiven) { solution_ = kSolutionGiven; }
  void push_back(const int& kSolutionGiven) { solution_.push_back(kSolutionGiven); }
  int operator[](const int& kIndex) const { return solution_[kIndex]; } const
  int size() const { return solution_.size(); }
  void add_level() { max_level_++; }
  int get_level() const { return max_level_; }
  void set_level(const int& kLevel) { max_level_ = kLevel; }
  void addMove(int disk, int from ,int to) {
    solution_.push_back({disk, from, to});
  }
 private:
  T solution_;
  int max_level_;
};