#include "grasp.h"

Solution Grasp::run() {
  srand(time(NULL));
  set_up();
  Problem problem = problem_;
  std::vector<int> task_to_evaluate;
  problem_ = problem;
  for (int iteration = problem_.get_number_of_machines(); iteration < problem_.get_number_of_tasks(); iteration++) { // Recorrer todas las tareas
    int task = problem_.get_random_not_assigned_task();
    std::vector<int> best_machine = {0};
    std::vector<int> best_task = {task};
    Machine first_machine = problem_.get_machines()[0];
    std::vector<int> best_tct = {problem_.get_cost_of_change(first_machine.get_last_task(), task) + problem_.get_task_time(task) * first_machine.get_number_of_tasks()};
    std::vector<std::vector<int>> best_vector_of_tasks = {first_machine.get_tasks()};
    best_vector_of_tasks[0].push_back(task);
    for (int i = 0; i < problem_.get_number_of_tasks(); i++) { // Recorrer todas las tareas
      std::vector<int> already_assigned = problem_.get_tasks_already_assigned();
      if (find(already_assigned.begin(), already_assigned.end(), i) != already_assigned.end()) {
        continue;
      }
      for (int j = 0; j < problem_.get_number_of_machines(); j++) { // Recorrer todas las máquinas
        Machine machine = problem_.get_machines()[j];
        for (int z = 0; z < machine.get_number_of_tasks() + 1; z++) { // Recorrer todas las posiciones de la máquina
          task_to_evaluate = machine.get_tasks();
          task_to_evaluate.insert(task_to_evaluate.begin() + z, i);
          int tct = problem_.calculate_tct(task_to_evaluate);
          tct -= machine.get_tct();
          if (best_machine.size() < lrc_size_) {
            best_machine.push_back(j);
            best_tct.push_back(tct);
            best_vector_of_tasks.push_back(task_to_evaluate);
            best_task.push_back(i);
          } else {
            int max_tct = *std::max_element(best_tct.begin(), best_tct.end());
            if (tct < max_tct) {
              int max_index = std::distance(best_tct.begin(), std::max_element(best_tct.begin(), best_tct.end()));
              best_machine[max_index] = j;
              best_tct[max_index] = tct;
              best_vector_of_tasks[max_index] = task_to_evaluate;
              best_task[max_index] = i;
            }
          }
        }
      }
    }
    int random_index = rand() % lrc_size_;
    int best_machine_to_push = best_machine[random_index];
    std::vector<int> best_vector_of_tasks_to_push = best_vector_of_tasks[random_index];
    int best_task_to_push = best_task[random_index];
    int tct_to_push = problem_.calculate_tct(best_vector_of_tasks_to_push);
    problem_.push_vector_of_tasks_to_machine(best_machine_to_push, best_vector_of_tasks_to_push, tct_to_push);
    problem_.push_task_to_used_tasks(best_task_to_push);
  }
  problem_.recalculate_total_tct();
  Solution best_solution = Solution(problem_.get_machines(), problem_.get_total_tct());
  best_solution_ = best_solution;
  return best_solution;
}

