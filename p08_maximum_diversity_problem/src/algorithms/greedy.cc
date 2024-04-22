#include "greedy.h"
#include "point.h"

Solution Greedy::run() {
  Solution proto_solution= Solution(problem_.get_points());
  Solution solution;
  Point centroid = proto_solution.calculate_centroid();
  std::vector<Point> points_left = proto_solution.get_solution();
  do {
    double max_distance = 0.0;
    Point max_point;
    for (int i = 0; i < points_left.size(); i++) {
      double distance = 0.0;
      distance = centroid.distance(points_left[i]);
      if (distance > max_distance) {
        max_distance = distance;
        max_point = points_left[i];
      }
    }
    solution.add_point(max_point);
    points_left.erase(std::remove(points_left.begin(), points_left.end(), max_point), points_left.end());
    centroid = solution.calculate_centroid();
  } while(solution.size() < m_);
  problem_.set_points_not_in_solution(points_left);
  return solution;
}