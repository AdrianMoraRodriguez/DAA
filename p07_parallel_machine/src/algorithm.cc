#include "algorithm.h"

#include <algorithm>

void Algorithm::set_up() {
  std::vector<std::pair<int, int>> best_tasks;
  int best_tct = 0;
  for (int i = 0; i < problem_.get_number_of_machines(); i++) {
    std::pair<int, int> best_task;
    best_task.first = i;
    best_task.second = problem_.get_initial_setup_time(i) + problem_.get_task_time(i) * problem_.get_number_of_tasks();
    best_tasks.push_back(best_task);
  }
  std::sort(best_tasks.begin(), best_tasks.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
    return a.second > b.second;
  });
  for (int i = problem_.get_number_of_machines(); i < problem_.get_number_of_tasks(); i++) {
    int actual_tct = problem_.get_initial_setup_time(i) + problem_.get_task_time(i) * problem_.get_number_of_tasks();
    for (int j = 0; j < problem_.get_number_of_machines(); j++) {
      if (best_tasks[j].second > actual_tct) {
        best_tasks[j].first = i;
        best_tasks[j].second = actual_tct;
        std::sort(best_tasks.begin(), best_tasks.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
          return a.second > b.second;
        });
        break;
      }
    }
  }
  std::vector<int> used_tasks;
  for (int i = 0; i < problem_.get_number_of_machines(); i++) {
    problem_.push_task_to_machine(i, best_tasks[i].first, best_tasks[i].second);
    used_tasks.push_back(best_tasks[i].first);
  }
  problem_.used_task(used_tasks);
}