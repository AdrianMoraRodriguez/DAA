#include <algorithm>
#include "grasp_swap_intra_VNS.h"

Solution GraspSwapIntraVNS::localSearch(Solution solution) {
  int n = problem_.get_number_of_machines();
  Problem new_problem = problem_;
  Solution new_solution = solution;
    for (int i = 0; i < n; i++) {
      std::vector<int> tasks = solution.get_tasks(i);
      int base_tct = solution.get_tct_of_machine(i);
      int best_tct = solution.get_tct_of_machine(i);
      for (int j = 0; j < tasks.size(); j++) {
        for (int k = j + 1; k < tasks.size(); k++) {
          int new_tct = tct_intra(base_tct, tasks, j, k, problem_);
          if (new_tct < best_tct) {
            std::vector<int> posible_new_solution = tasks;
            std::swap(posible_new_solution[j], posible_new_solution[k]);
            new_problem.push_vector_of_tasks_to_machine(i, posible_new_solution, new_tct);
            new_solution.set_machine(i, new_problem.get_machine(i));
            best_tct = new_tct;
          }
        }
      }
    }
  return new_solution;
}

int GraspSwapIntraVNS::tct_intra(int base_tct, const std::vector<int>& tasks, int j, int k, Problem& problem) {
  int new_tct = base_tct;
  int task_j = tasks[j];
  int task_k = tasks[k];
  int task_j_time = problem.get_task_time(task_j);
  int task_k_time = problem.get_task_time(task_k);
  int initial_setup_time_j = problem.get_initial_setup_time(task_j);
  int initial_setup_time_k = problem.get_initial_setup_time(task_k);
  int tasks_size = tasks.size();
  if (j == 0) {
    new_tct -= ((initial_setup_time_j + task_j_time) * tasks_size);
    new_tct += ((initial_setup_time_k + task_k_time) * tasks_size);
  } else {
    new_tct -= ((problem_.get_cost_of_change(tasks[j - 1], task_j) + task_j_time) * (tasks_size - j));
    new_tct += ((problem_.get_cost_of_change(tasks[j - 1], task_k) + task_k_time) * (tasks_size - j));
  }
  if (j != tasks_size - 1) {
    new_tct -= ((problem_.get_cost_of_change(task_j, tasks[j + 1]) + problem_.get_task_time(tasks[j + 1])) * (tasks_size - j - 1));
    if (k == j + 1) {
      new_tct += ((problem_.get_cost_of_change(task_k, task_j) + task_k_time) * (tasks_size - j - 1));
    } else {
      new_tct += ((problem_.get_cost_of_change(task_k, tasks[j + 1]) + problem_.get_task_time(tasks[j + 1])) * (tasks_size - j - 1));
    }
  }
  if (k == 0) {
    new_tct -= ((initial_setup_time_k + task_k_time) * tasks_size);
    new_tct += ((initial_setup_time_j + task_j_time) * tasks_size);
  } else {
    new_tct -= ((problem_.get_cost_of_change(tasks[k - 1], task_k) + task_k_time) * (tasks_size - k));
    if (k == j + 1) {
      new_tct += ((problem_.get_cost_of_change(task_j, task_k) + task_j_time) * (tasks_size - k));
    } else {
      new_tct += ((problem_.get_cost_of_change(tasks[k - 1], task_j) + task_j_time) * (tasks_size - k));
    }
  }
  if (k != tasks_size - 1) {
    new_tct -= ((problem_.get_cost_of_change(task_k, tasks[k + 1]) + problem_.get_task_time(tasks[k + 1])) * (tasks_size - k - 1));
    new_tct += ((problem_.get_cost_of_change(task_j, tasks[k + 1]) + problem_.get_task_time(tasks[k + 1])) * (tasks_size - k - 1));
  }
  return new_tct;
}