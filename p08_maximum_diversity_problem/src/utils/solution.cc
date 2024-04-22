#include "solution.h"

void Solution::calculate_diversity() {
  diversity_ = 0.0;
  for (int i = 0; i < solution_.size(); i++) {
    for (int j = i + 1; j < solution_.size(); j++) {
      diversity_ += solution_[i].distance(solution_[j]);
    }
  }
}

Point Solution::calculate_centroid() const {
    std::vector<double> point_coordinates(solution_[0].get_point().size(), 0.0);
    std::vector<double> actual_point_coordinates = {};
    for (int i = 0; i < solution_.size(); i++) {
      actual_point_coordinates = solution_[i].get_point();
      for (int j = 0; j < actual_point_coordinates.size(); j++) {
        point_coordinates[j] += actual_point_coordinates[j];
      }
    }
    for (int i = 0; i < point_coordinates.size(); i++) {
      point_coordinates[i] /= solution_.size();
    }
    return Point(point_coordinates);
  }