#include "problem.h"


Problem::Problem(std::string file_name) {
  std::ifstream file(file_name);
  if (!file.is_open()) {
    std::cerr << "Error: could not open file " << file_name << std::endl;
    exit(1);
  }
  std::string line;
  file >> line;
  file >> number_of_tasks_;
  file >> line;
  file >> number_of_machines_;
  create_machines(number_of_machines_);
  file >> line;
  for (int i = 0; i < number_of_tasks_; i++) {
    int time;
    file >> time;
    tasks_.push_back(time);
  }
  file >> line;
  file >> line;
  for (int i = 0; i < number_of_tasks_; i++) {
    int time;
    file >> time;
    initial_setup_time_.push_back(time);
  }
  for (int i = 0; i < number_of_tasks_; i++) {
    file >> line;
    std::vector<int> task;
    change_task_times_.push_back(task);
    for (int j = 0; j < number_of_tasks_; j++) {
      int time;
      file >> time;
      change_task_times_[i].push_back(time);
    }
  }
  file.close();
}

void Problem::create_machines(int number_of_machines) {
  for (int i = 0; i < number_of_machines; i++) {
    Machine machine;
    machines_.push_back(machine);
  }
}

void Problem::recalculate_total_tct() {
  total_tct_ = 0;
  for (int i = 0; i < number_of_machines_; i++) {
    total_tct_ += machines_[i].get_tct();
  }
}

int Problem::calculate_tct(std::vector<int> tasks) {
  if (tasks.size() == 0) {
    return 0;
  }
  int tct = initial_setup_time_[tasks[0]];
  tct += tasks_[tasks[0]];
  tct *= tasks.size();
  for (int i = 1; i < tasks.size(); i++) {
    int t = change_task_times_[tasks[i - 1]][tasks[i]] + tasks_[tasks[i]];
    tct += t * (tasks.size() - i);
  }
  return tct;
}