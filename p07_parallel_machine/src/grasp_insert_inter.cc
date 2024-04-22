#include "grasp_insert_inter.h"

Solution GraspInsertInter::localSearch(Solution solution) {
  int n = problem_.get_number_of_machines();
  bool improved = true;
  Solution new_solution = solution;
  bool repeated = false;
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
            int element_1 = new_tasks_i[k];
            int element_2 = new_tasks_j[l];
            new_tasks_i.erase(new_tasks_i.begin() + k);
            new_tasks_j.erase(new_tasks_j.begin() + l);
            new_tasks_i.insert(new_tasks_i.begin() + k, element_2);
            new_tasks_j.insert(new_tasks_j.begin() + l, element_1);
            int new_tct_i = problem_.calculate_tct(new_tasks_i); 
            int new_tct_j = problem_.calculate_tct(new_tasks_j); 
            int new_total_tct = new_tct_i + new_tct_j;
            if (new_total_tct < best_total_tct) {
              if (new_solution.get_total_tct() < new_total_tct) {
                continue;
              }
              if (first_modify == false) {
                new_solution.set_machine(previous_modify_machine_i, previous_modify_vector_i, problem_.calculate_tct(previous_modify_vector_i));
                new_solution.set_machine(previous_modify_machine_j, previous_modify_vector_j, problem_.calculate_tct(previous_modify_vector_j));
              } else {
                first_modify = false;
              }
              new_solution.set_machine(i, new_tasks_i, new_tct_i);
              new_solution.set_machine(j, new_tasks_j, new_tct_j);
              best_total_tct = new_total_tct;
              improved = true;
              previous_modify_vector_i = tasks_i;
              previous_modify_vector_j = tasks_j;
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