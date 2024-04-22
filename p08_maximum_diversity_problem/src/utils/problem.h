#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

#include "point.h"
#include "solution.h"

#pragma once

class Problem {
 public:
  Problem() {}
  Problem(const Problem &problem) : n_(problem.get_n()), k_(problem.get_k()), points_(problem.get_points()) {}
  Problem(int n, int k, std::vector<Point> &points) : n_(n), k_(k), points_(points) {}
  void Initialize(std::string file_name);
  int get_n() const { return n_; }
  int get_k() const { return k_; }
  std::vector<Point> get_points() const { return points_; }
  double distance(int i, int j) const;
  double distance(int i, const Point &point) const;
  double distance(const Point &point1, const Point &point2) const;
  void set_points_not_in_solution(std::vector<Point> points_not_in_solution) { points_not_in_solution_ = points_not_in_solution; }
  std::vector<Point> get_points_not_in_solution() const { return points_not_in_solution_; }
  void print();
 private:
  int n_;
  int k_;
  std::vector<Point> points_;
  std::vector<Point> points_not_in_solution_;
};