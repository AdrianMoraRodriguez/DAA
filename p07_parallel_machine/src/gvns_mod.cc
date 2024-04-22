#include "gvns_mod.h"
#include <map>

Solution GVNSMod::run() {
  grasp_->set_problem(problem_);
  Solution best_solution = grasp_->run();
  Solution s = best_solution;
  std::cout << "Solucion inicial: " << s.get_total_tct() << "\n";
  initial_solution_ = s;
  int upgrades = 0;
  int k = 1;
  int iter = 0;
  while (iter < itermax_) {
    while (k <= kmax_) {
      Solution current_solution = shake(s, k);
      current_solution = modification(current_solution); // MODIFICACION
      if (current_solution.get_total_tct() < s.get_total_tct()) {
        s = current_solution;
        k = 1;
      } else {
        k++;
      }
    }
    iter++;
    k = 1;
    if (s.get_total_tct() < best_solution.get_total_tct()) {
      best_solution = s;
      upgrades = 0;
    } else {
      upgrades++;
    }
    if (upgrades >= itermax_ / 3) {
      std::cout << "Se han realizado " << upgrades << " iteraciones sin mejora\n";
      return best_solution;
    }
  }
  return best_solution;
}

Solution GVNSMod::shake(Solution solution, int k) {
  srand(time(NULL));
  int n = problem_.get_number_of_machines();
  std::map<std::pair<int, int>, std::pair<int, int>> moves_alredy_done;
  int random_number = 0;
  for (int i = 0; i < k; i++) {
    random_number = rand();
    int machine1 = random_number % n;
    random_number = rand();
    int machine2 = random_number % n;
    while (machine1 == machine2) {
      random_number = rand();
      machine2 = random_number % n;
    }
    std::vector<int> tasks1 = solution.get_tasks(machine1);
    std::vector<int> tasks2 = solution.get_tasks(machine2);
    random_number = rand();
    if (tasks1.size() == 0) {
      i--;
      continue;
    }
    int task1 = random_number % tasks1.size();
    random_number = rand();
    if (tasks2.size() == 0) {
      i--;
      continue;
    }
    int task2 = random_number % tasks2.size();
    if (moves_alredy_done.find(std::pair<int, int>(machine1, task1)) != moves_alredy_done.end() || moves_alredy_done[std::pair<int, int>(machine1, task1)] == std::pair<int, int>(machine2, task2)) {
      i--;
      continue;
    }
    int task1_value = tasks1[task1];
    tasks1.erase(tasks1.begin() + task1);
    tasks2.insert(tasks2.begin() + task2, task1_value);
    int tct1 = problem_.calculate_tct(tasks1);
    int tct2 = problem_.calculate_tct(tasks2);
    solution.set_machine(machine1, tasks1, tct1);
    solution.set_machine(machine2, tasks2, tct2);
    moves_alredy_done[std::pair<int, int>(machine2, task2)] = std::pair<int, int>(machine1, task1);
  }
  return solution;
}


Solution GVNSMod::modification(Solution solution) { // MODIFICACION (FUNCIÓN NUEVA)
  for (int i = 0; i < algorithms_.size(); i++) {
    solution = algorithms_[i]->localSearch(solution);
  }
  return solution;
}