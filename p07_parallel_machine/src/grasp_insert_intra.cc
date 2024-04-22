#include "grasp_insert_intra.h"

Solution GraspInsertIntra::localSearch(Solution solution) {
  int n = problem_.get_number_of_machines();
  bool improved = true;
  Problem new_problem = problem_;
  Solution new_solution = solution;
  bool debug = true;
  while (improved) {
    improved = false;
    for (int i = 0; i < n; i++) {
      std::vector<int> tasks = solution.get_tasks(i);
      int best_tct = solution.get_tct_of_machine(i);
      for (int j = 0; j < tasks.size(); j++) {
        for (int k = 0; k < tasks.size(); k++) {
          if (j == k) {
            continue;
          }
          std::vector<int> posible_new_solution = tasks;
          int element = posible_new_solution[j];
          posible_new_solution.erase(posible_new_solution.begin() + j);
          posible_new_solution.insert(posible_new_solution.begin() + k, element);
          int new_tct = new_problem.calculate_tct(posible_new_solution); // Can be optimized
          // int my_new_tct = tct_intra(best_tct, tasks, j, k, element, new_problem);
          // if (new_tct != my_new_tct) {
          //   std::cout << "ERROR: " << new_tct << " != " << my_new_tct << std::endl;
          // }
          if (new_tct < best_tct) {
            new_problem.push_vector_of_tasks_to_machine(i, posible_new_solution, new_tct);
            new_solution.set_machine(i, new_problem.get_machine(i));
            best_tct = new_tct;
            improved = true;
          }
        }
      }
    }
    if (improved) {
      solution = new_solution;
    }
  }
  return solution;
}


int GraspInsertIntra::tct_intra(int base_tct, const std::vector<int>& tasks, int position, int new_position, int element, Problem& problem) {
  int new_tct = base_tct;
  int task = tasks[position];
  int task_time = problem.get_task_time(task);
  int tasks_size = tasks.size();
  int total_to_subtract = 0;
  int start_to_operate = position < new_position ? position : new_position;
  for (int i = start_to_operate; i < tasks_size; i++) {
    int task = tasks[i];
    int what_to_subtract = 0;
    if (i == 0) {
      what_to_subtract = problem.get_initial_setup_time(task) + problem.get_task_time(task);
    } else {
      what_to_subtract = problem.get_cost_of_change(tasks[i - 1], task) + problem.get_task_time(task);
    }
    what_to_subtract *= (tasks_size - i);
    total_to_subtract += what_to_subtract;
  }
  new_tct -= total_to_subtract;
  int total_to_add = 0;
  std::vector<int> new_tasks = tasks;
  new_tasks.erase(new_tasks.begin() + position);
  new_tasks.insert(new_tasks.begin() + new_position, element);
  for (int i = start_to_operate; i < tasks_size; i++) {
    int task = new_tasks[i];
    int what_to_add = 0;
    if (i == 0) {
      what_to_add = problem.get_initial_setup_time(task) + problem.get_task_time(task);
    } else {
      what_to_add = problem.get_cost_of_change(new_tasks[i - 1], task) + problem.get_task_time(task);
    }
    what_to_add *= (tasks_size - i);
    total_to_add += what_to_add;
  }
  return new_tct;
}
