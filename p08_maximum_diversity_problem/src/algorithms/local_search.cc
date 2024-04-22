#include "local_search.h"

double LocalSearch::evaluate_change(const std::vector<Point>& actual_solution, double actual_distance ,const Point& point_to_add, int position) {
  double new_distance = actual_distance;
  for (int i = 0; i < actual_solution.size(); i++) {
    if (i != position) {
      new_distance += point_to_add.distance(actual_solution[i]);
      new_distance -= actual_solution[position].distance(actual_solution[i]);
    }
  }
  return new_distance;
}

Solution LocalSearch::run() {
  Solution best_solution = solution_;
  double best_distance = best_solution.get_diversity();
  std::vector<Point> points_not_in_solution = problem_.get_points_not_in_solution();
  bool improvement = true;
  while(improvement) {
    Solution actual_best_solution = best_solution;
    improvement = false;
    for (int i = 0; i < points_not_in_solution.size(); i++) {
      for (int j = 0; j < best_solution.size(); j++) {
        double new_distance = evaluate_change(best_solution.get_solution(), best_distance, points_not_in_solution[i], j);
        if (new_distance > best_distance) {
          actual_best_solution = best_solution;
          actual_best_solution.remove_point(actual_best_solution.get_solution()[j], new_distance);
          actual_best_solution.add_point(points_not_in_solution[i], new_distance);
          best_distance = new_distance;
          improvement = true;
        }
      }
    }
    if (improvement) {
      best_solution.set_solution(actual_best_solution.get_solution(), best_distance);
    }
  }
  return best_solution;
}