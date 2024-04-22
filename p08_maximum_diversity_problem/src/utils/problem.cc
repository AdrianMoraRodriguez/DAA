#include "problem.h"
#include <fstream>
#include <sstream>

void Problem::Initialize(std::string file_name) {
  std::ifstream file(file_name);
  std::vector<Point> points;
  if (!file.is_open()) {
    std::cerr << "Error: could not open file " << file_name << std::endl;
    exit(1);
  }
  file >> n_ >> k_;
  points_.resize(n_, Point(k_));
  std::string line;
  std::getline(file, line);
  while(getline(file,line)) {
    if (line.empty() || line[0] == '\n' || line[0] == '\r' || line[0] == '\0') {
      continue;
    }
    std::vector<double> point;
    std::replace(line.begin(), line.end(), ',', '.');
    std::istringstream stream(line);
    std::string value;
    while (getline(stream, value, '\t')) {
      point.push_back(std::stod(value));
    }
    Point point_to_push(point);
    points.push_back(point_to_push);
  }
  points_ = points;
  file.close();
}

void Problem::print() {
  std::cout << "n: " << n_ << std::endl;
  std::cout << "k: " << k_ << std::endl;
  for (int i = 0; i < n_; i++) {
    points_[i].print();
    std::cout << std::endl;
  }
}

double Problem::distance(int i, int j) const {
  double distance = 0.0;
  for (int l = 0; l < k_; l++) {
    distance += (points_[i].get_coordinate(l) - points_[j].get_coordinate(l)) * (points_[i].get_coordinate(l) - points_[j].get_coordinate(l));
  }
  distance = sqrt(distance);
  return distance;
}

double Problem::distance(int i, const Point &point) const {
  double distance = 0.0;
  for (int l = 0; l < k_; l++) {
    distance += (points_[i].get_coordinate(l) - point.get_coordinate(l)) * (points_[i].get_coordinate(l) - point.get_coordinate(l));
  }
  distance = sqrt(distance);
  return distance;
}

double Problem::distance(const Point &point1, const Point &point2) const {
  double distance = 0.0;
  for (int l = 0; l < k_; l++) {
    distance += (point1.get_coordinate(l) - point2.get_coordinate(l)) * (point1.get_coordinate(l) - point2.get_coordinate(l));
  }
  distance = sqrt(distance);
  return distance;
}