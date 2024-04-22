#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

#include "point.h"

#pragma once

class Solution {
 public:
  Solution() {}
  Solution(int size) : solution_(size), diversity_(0.0) {}
  Solution(std::vector<Point> points,double diversity = 0.0) : solution_(points), diversity_(diversity) {
    if (diversity == 0.0 && points.size() > 0) {
      calculate_diversity();
    }
  }
  Solution(const Solution& other) : solution_(other.get_solution()), diversity_(other.get_diversity()) {}
  std::vector<Point> get_solution() const { return solution_; }
  double get_diversity() const { return diversity_; }
  void print() const {
    std::ios_base::fmtflags f(std::cout.flags());
    std::streamsize p(std::cout.precision());
    std::cout << "Diversity: " << diversity_ << std::endl;
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    for (int i = 0; i < solution_.size(); i++) {
      std::vector<double> point = solution_[i].get_point();
      std::string point_str = "";
      point_str += "( ";
      for (int j = 0; j < point.size(); j++) {
        point_str += std::to_string(point[j]) + ",";
      }
      point_str = point_str.substr(0, point_str.size() - 1);
      point_str += " )";
      std::cout << point_str << ", ";
    }
    std::cout.flags(f);
    std::cout.precision(p);
  }
  void set_solution(std::vector<Point> solution, double diversity = -1.0) { 
    solution_ = solution;
    if (diversity != -1.0) {
      diversity_ = diversity;
    } else {
      calculate_diversity();
    }
  }

  void add_point(Point point, double diversity = -1.0) {
    solution_.push_back(point);
    if (diversity != -1.0) {
      diversity_ = diversity;
    } else {
      calculate_diversity();
    }
  }

  void remove_point(Point point, double diversity = -1.0) {
    for (int i = 0; i < solution_.size(); i++) {
      if (solution_[i].get_point() == point.get_point()) {
        solution_.erase(solution_.begin() + i);
        break;
      }
    }
    if (diversity != -1.0) {
      diversity_ -= diversity;
    } else {
      calculate_diversity();
    }
  }

  Point calculate_centroid() const;

  int size() const { return solution_.size(); }

 private:
  void calculate_diversity();
  std::vector<Point> solution_;
  double diversity_;
};