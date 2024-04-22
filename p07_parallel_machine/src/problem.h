#include "machine.h"

#include <algorithm>

#pragma once

class Problem {
 public:
  Problem() {}
  Problem(std::string file_name);
  void push_machine(Machine machine) {
    machines_.push_back(machine);
  }

  void change_machine(std::vector<Machine> machines) {
    machines_ = machines;
  }

  std::vector<Machine> get_machines() const { return machines_; }

  int get_number_of_machines() const { return machines_.size(); }

  int get_number_of_tasks() const { return tasks_.size(); }

  int get_total_tct() const { return total_tct_; }

  int get_cost_of_change(int previous_task, int new_task) {
    return change_task_times_[previous_task][new_task];
  }

  int get_initial_setup_time(int task) {
    return initial_setup_time_[task];
  }

  int get_task_time(int task) {
    return tasks_[task];
  }

  void push_task_to_machine(int machine, int task, int time) {
    machines_[machine].push_task(task, time);
  }

  void push_vector_of_tasks_to_machine(int machine, std::vector<int> tasks, int tct) {
    machines_[machine].change_task(tasks, tct);
  }

  Machine get_machine(int i) {
    return machines_[i];
  }

  void print_tasks() {
    for (int i = 0; i < number_of_tasks_; i++) {
      std::cout << tasks_[i] << " ";
    }
    std::cout << std::endl;
  }

  void print_initial_setup_time() {
    for (int i = 0; i < number_of_tasks_; i++) {
      std::cout << initial_setup_time_[i] << " ";
    }
    std::cout << std::endl;
  }

  void print_change_task_times() {
    for (int i = 0; i < number_of_tasks_; i++) {
      for (int j = 0; j < number_of_tasks_; j++) {
        std::cout << change_task_times_[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }

  void used_task(std::vector<int> tasks) {
    tasks_already_assigned_ = tasks;
  }

  void push_task_to_used_tasks(int task) {
    tasks_already_assigned_.push_back(task);
  }

  std::vector<int> get_tasks_already_assigned() {
    return tasks_already_assigned_;
  }

  int get_random_not_assigned_task() {
    std::vector<int> tasks_not_assigned = {};
    for (int i = 0; i < number_of_tasks_; i++) {
      if (find(tasks_already_assigned_.begin(), tasks_already_assigned_.end(), i) == tasks_already_assigned_.end()) {
        tasks_not_assigned.push_back(i);
      }
    }
    return tasks_not_assigned[rand() % tasks_not_assigned.size()];
  }
  void recalculate_total_tct();
  int calculate_tct(std::vector<int> tasks);
 protected:
  std::vector<Machine> machines_;
  std::vector<int> tasks_;
  std::vector<int> initial_setup_time_;
  std::vector<std::vector<int>> change_task_times_;
  std::vector<int> tasks_already_assigned_ = {};
  int number_of_machines_;
  int number_of_tasks_;
  int total_tct_ = 0;
  void create_machines(int number_of_machines);
};