#include "grasp.h"

#include <algorithm>


Solution GRASP::run() {
  srand(time(NULL));
  std::vector<Solution> final_solutions = {};
  for (int i = 0; i < iterations_; i++) {
    std::vector<Point> lrc_points = {};
     Solution proto_solution= Solution(problem_.get_points());
    Solution solution;
    Point centroid = proto_solution.calculate_centroid();
    std::vector<Point> points_left = proto_solution.get_solution();
    do {
      double max_distance = 0.0;
      for (int i = 0; i < points_left.size(); i++) {
        double distance = 0.0;
        distance = centroid.distance(points_left[i]);
        if (distance > max_distance) {
          if (lrc_points.size() < lrc_) {
            lrc_points.push_back(points_left[i]);
            max_distance = distance;
          } else {
            double min_distance = lrc_points[0].distance(centroid);
            int min_index = 0;
            for (int i = 1; i < lrc_points.size(); i++) {
              double distance = lrc_points[i].distance(centroid);
              if (distance < min_distance) {
                min_distance = distance;
                min_index = i;
              }
            }
            if (distance > min_distance) {
              lrc_points.erase(lrc_points.begin() + min_index);
              lrc_points.push_back(points_left[i]);
              max_distance = distance;
            }
          }
        }
      }
      int random_index = rand() % lrc_points.size();
      Point max_point = lrc_points[random_index];
      solution.add_point(max_point);
      points_left.erase(std::remove(points_left.begin(), points_left.end(), max_point), points_left.end());
      centroid = solution.calculate_centroid();
    } while(solution.size() < m_);
    local_search_.set_solution(solution);
    solution = local_search_.run();
    final_solutions.push_back(solution);
  }
  Solution best_solution = final_solutions[0];
  for (int i = 1; i < final_solutions.size(); i++) {
    if (final_solutions[i].get_diversity() > best_solution.get_diversity()) {
      best_solution = final_solutions[i];
    }
  }
  // Hacer un vector con todos los puntos que no estan en la solucion
  std::vector<Point> points_not_in_solution = problem_.get_points();
  for (int i = 0; i < best_solution.size(); i++) {
    points_not_in_solution.erase(std::remove(points_not_in_solution.begin(), points_not_in_solution.end(), best_solution.get_solution()[i]), points_not_in_solution.end());
  }
  problem_.set_points_not_in_solution(points_not_in_solution);
  return best_solution;
}