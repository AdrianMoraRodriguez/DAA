#include "grasp_swap_inter.h"

Solution GraspSwapInter::localSearch(Solution solution) {
  int n = problem_.get_number_of_machines();
  bool improved = true;
  Solution new_solution = solution;
  while (improved) {
    improved = false;
    std::vector<int> previous_modify_vector_i;
    std::vector<int> previous_modify_vector_j;
    int previous_modify_machine_i;
    int previous_modify_machine_j;
    bool first_modify = true;
    for (int i = 0; i < n; i++) {
      std::vector<int> tasks_i = solution.get_tasks(i);
      int tct_i = solution.get_tct_of_machine(i);
      for (int j = 0; j < n; j++) {
        if (i == j) {
          continue;
        }
        std::vector<int> tasks_j = solution.get_tasks(j);
        int tct_j = solution.get_tct_of_machine(j);
        int best_total_tct = tct_i + tct_j;
        for (int k = 0; k < tasks_i.size(); k++) {
          for (int l = 0; l < tasks_j.size(); l++) {
            std::vector<int> new_tasks_i = tasks_i;
            std::vector<int> new_tasks_j = tasks_j;
            std::pair new_tcts = tct_inter(tct_i, tct_j, tasks_i, tasks_j, k, l, problem_);
            int new_total_tct = new_tcts.first + new_tcts.second;
            if (new_total_tct < best_total_tct) {
              std::swap(new_tasks_i[k], new_tasks_j[l]);
              if (new_solution.get_total_tct() < new_total_tct) {
                continue;
              }
              if (first_modify == false) {
                new_solution.set_machine(previous_modify_machine_i, previous_modify_vector_i, problem_.calculate_tct(previous_modify_vector_i));
                new_solution.set_machine(previous_modify_machine_j, previous_modify_vector_j, problem_.calculate_tct(previous_modify_vector_j));
              } else {
                first_modify = false;
              }
              new_solution.set_machine(i, new_tasks_i, new_tcts.first);
              new_solution.set_machine(j, new_tasks_j, new_tcts.second);
              best_total_tct = new_total_tct;
              improved = true;
              previous_modify_vector_i = solution.get_tasks(i);
              previous_modify_vector_j = solution.get_tasks(j);
              previous_modify_machine_i = i;
              previous_modify_machine_j = j;
            }
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

std::pair<int,int> GraspSwapInter::tct_inter(int tct_i, int tct_j, const std::vector<int>& tasks_i, const std::vector<int>& tasks_j, int k, int l, Problem& problem) {
  int new_tct_i = tct_i;
  int new_tct_j = tct_j;
  int task_k = tasks_i[k];
  int task_l = tasks_j[l];
  int task_k_time = problem.get_task_time(task_k);
  int task_l_time = problem.get_task_time(task_l);
  int initial_setup_time_k = problem.get_initial_setup_time(task_k);
  int initial_setup_time_l = problem.get_initial_setup_time(task_l);
  int tasks_i_size = tasks_i.size();
  int tasks_j_size = tasks_j.size();
  if ( k == 0 ) {
    new_tct_i -= ((initial_setup_time_k + task_k_time) * tasks_i_size);
    new_tct_i += ((initial_setup_time_l + task_l_time) * tasks_i_size);
  } else {
    new_tct_i -= ((problem.get_cost_of_change(tasks_i[k - 1], task_k) + task_k_time) * (tasks_i_size - k));
    new_tct_i += ((problem.get_cost_of_change(tasks_i[k - 1], task_l) + task_l_time) * (tasks_i_size - k));
  }
  if ( k != tasks_i_size - 1 ) {
    new_tct_i -= ((problem.get_cost_of_change(task_k, tasks_i[k + 1]) + problem.get_task_time(tasks_i[k + 1])) * (tasks_i_size - k - 1));
    new_tct_i += ((problem.get_cost_of_change(task_l, tasks_i[k + 1]) + problem.get_task_time(tasks_i[k + 1])) * (tasks_i_size - k - 1));
  }
  if ( l == 0 ) {
    new_tct_j -= ((initial_setup_time_l + task_l_time) * tasks_j_size);
    new_tct_j += ((initial_setup_time_k + task_k_time) * tasks_j_size);
  } else {
    new_tct_j -= ((problem.get_cost_of_change(tasks_j[l - 1], task_l) + task_l_time) * (tasks_j_size - l));
    new_tct_j += ((problem.get_cost_of_change(tasks_j[l - 1], task_k) + task_k_time) * (tasks_j_size - l));
  }
  if ( l != tasks_j_size - 1 ) {
    new_tct_j -= ((problem.get_cost_of_change(task_l, tasks_j[l + 1]) + problem.get_task_time(tasks_j[l + 1])) * (tasks_j_size - l - 1));
    new_tct_j += ((problem.get_cost_of_change(task_k, tasks_j[l + 1]) + problem.get_task_time(tasks_j[l + 1])) * (tasks_j_size - l - 1));
  }
  return std::make_pair(new_tct_i, new_tct_j);
}