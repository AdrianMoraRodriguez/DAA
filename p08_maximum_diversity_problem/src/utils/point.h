#include <vector>
#include <string>
#include <math.h>

#pragma once

class Point {
 public:
  Point() {}
  Point(int n) : point_(n), n_(n) {}
  Point(std::vector<double> point) : point_(point) {
    n_ = point.size();
  }
  std::vector<double> get_point() const { return point_; }
  void set_point(std::vector<double> &point) { point_ = point; }
  double get_coordinate(int index) const { return point_[index]; }
  void print() {
    std::cout << "(";
    for (int i = 0; i < n_; i++) {
      std::cout << point_[i];
      if (i != n_ - 1) {
        std::cout << ", ";
      }
    }
    std::cout << ")";
  }

  double distance(const Point &point) const {
    double distance = 0.0;
    for (int i = 0; i < n_; i++) {
      distance += (point_[i] - point.get_coordinate(i)) * (point_[i] - point.get_coordinate(i));
    }
    distance = sqrt(distance);
    return distance;
  }

  bool operator==(const Point &point) const {
    if (n_ != point.get_point().size()) {
      return false;
    }
    for (int i = 0; i < n_; i++) {
      if (point_[i] != point.get_coordinate(i)) {
        return false;
      }
    }
    return true;
  }

 private:
  std::vector<double> point_;
  int n_;
};