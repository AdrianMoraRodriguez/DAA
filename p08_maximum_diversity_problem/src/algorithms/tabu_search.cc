#include "tabu_search.h"
#include <iostream>
#include <algorithm>


double TabuSearch::evaluate_change(const std::vector<Point>& actual_solution, double actual_distance, const Point& point_to_add, int position) {
  double new_distance = actual_distance;
  for (int i = 0; i < actual_solution.size(); i++) {
    if (i != position) {
      new_distance += point_to_add.distance(actual_solution[i]);
      new_distance -= actual_solution[position].distance(actual_solution[i]);
    }
  }
  return new_distance;
}


Solution TabuSearch::run() {
  Solution best_solution = solution_;
  double best_distance = best_solution.get_diversity();
  std::vector<Point> points_not_in_solution = problem_.get_points_not_in_solution();
  int iterations_without_improvement = 0;
  bool improvement = true;
  while(iterations_without_improvement < max_iterations_without_improvement_) {
    int best_i = -1;
    int best_j = -1;
    Solution actual_best_solution = best_solution;
    Solution relative_best_solution = best_solution;
    improvement = false;
    double distance_to_compare = best_distance;
    double relative_best = 0;
    for (int i = 0; i < points_not_in_solution.size(); i++) {
      for (int j = 0; j < best_solution.size(); j++) {
        double new_distance = evaluate_change(best_solution.get_solution(), distance_to_compare, points_not_in_solution[i], j);
        if (new_distance > best_distance) {
          best_i = i;
          best_j = j;
          actual_best_solution = best_solution;
          relative_best = new_distance;
          actual_best_solution.remove_point(actual_best_solution.get_solution()[j], new_distance);
          actual_best_solution.add_point(points_not_in_solution[i], new_distance);
          relative_best_solution.remove_point(actual_best_solution.get_solution()[j], new_distance);
          relative_best_solution.add_point(points_not_in_solution[i], new_distance);
          best_distance = new_distance;
          improvement = true;
        } else {
          if (new_distance > relative_best && !tabuTenure(i, j)) {
            best_i = i;
            best_j = j;
            relative_best_solution = best_solution;
            relative_best_solution.remove_point(actual_best_solution.get_solution()[j], new_distance);
            relative_best_solution.add_point(points_not_in_solution[i], new_distance);
            relative_best = new_distance;
            improvement = true;
          }
        }
      }
    }
    if (improvement) {
      if (actual_best_solution.get_diversity() == best_solution.get_diversity()) {
        best_solution.set_solution(relative_best_solution.get_solution(), relative_best);
      } else {
        best_solution = actual_best_solution;
      }
      best_solution.set_solution(actual_best_solution.get_solution(), best_distance);
      tabu_list_[best_i][best_j] = tabu_tenure_;
      tabu_list_[best_j][best_i] = tabu_tenure_;
      iterations_without_improvement = 0;
    } else {
      iterations_without_improvement++;
    }
  }
  return best_solution;
}


bool TabuSearch::tabuTenure(int i, int j) {
  if (tabu_list_[i][j] > 0) {
    return true;
  }
  return false;
}

void TabuSearch::decreaseTabuTenure() {
  for (int i = 0; i < tabu_list_.size(); i++) {
    for (int j = 0; j < tabu_list_[i].size(); j++) {
      if (tabu_list_[i][j] > 0) {
        tabu_list_[i][j]--;
      }
    }
  }
}