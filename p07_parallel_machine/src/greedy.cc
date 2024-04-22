#include "greedy.h"
#include <algorithm>

Solution Greedy::run() {
  set_up();
  int best_machine = 0;
  int best_tct;
  int best_task;
  std::vector<int> best_vector_of_tasks;
  std::vector<int> task_to_evaluate;
  for (int iteration = problem_.get_number_of_machines(); iteration < problem_.get_number_of_tasks(); iteration++) {
    int task = problem_.get_random_not_assigned_task();
    best_machine = 0;
    best_tct = problem_.get_cost_of_change(problem_.get_machines()[0].get_last_task(), task) + problem_.get_task_time(task) * problem_.get_machines()[0].get_number_of_tasks();
    best_vector_of_tasks = problem_.get_machines()[0].get_tasks();
    best_vector_of_tasks.push_back(task);
    best_task = task;
    for (int i = 0; i < problem_.get_number_of_tasks(); i++) {
      std::vector<int> already_assigned = problem_.get_tasks_already_assigned();
      if (find(already_assigned.begin(), already_assigned.end(), i) != already_assigned.end()) {
        continue;
      }
      for (int j = 0; j < problem_.get_number_of_machines(); j++) {
        for (int z = 0; z < problem_.get_machines()[j].get_number_of_tasks() + 1; z++) {
          task_to_evaluate = problem_.get_machines()[j].get_tasks();
          task_to_evaluate.insert(task_to_evaluate.begin() + z, i);
          int tct = problem_.calculate_tct(task_to_evaluate);
          tct -= problem_.get_machines()[j].get_tct();
          if (tct < best_tct) {
            best_machine = j;
            best_tct = tct;
            best_vector_of_tasks = task_to_evaluate;
            best_task = i;
          }
        }
      }
    }
    int tct_to_push = problem_.calculate_tct(best_vector_of_tasks);
    problem_.push_vector_of_tasks_to_machine(best_machine, best_vector_of_tasks, tct_to_push);
    problem_.push_task_to_used_tasks(best_task);
  }
  problem_.recalculate_total_tct();
  return Solution(problem_.get_machines(), problem_.get_total_tct());
}