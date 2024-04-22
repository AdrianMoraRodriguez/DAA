#include <iostream>
#include <vector>
#include <fstream>

#pragma once

class Machine {
 public:
  Machine() {}
  int get_tct() const { return tct_;}
  void push_task(int task, int time) {
    tasks_.push_back(task);
    tct_ += time;
  }
  void change_task(std::vector<int> tasks, int new_tct) {
    tasks_ = tasks;
    tct_ = new_tct;
  }
  int get_last_task() {
    return tasks_[tasks_.size() - 1];
  }
  int get_number_of_tasks() {
    return tasks_.size();
  }
  void set_tasks(std::vector<int> tasks, int tct) {
    tasks_ = tasks;
    tct_ = tct;
  }
  std::vector<int> get_tasks() {
    std::vector<int> tasks = tasks_;
    return tasks;
  }
  void print() {
    std::cout << "TCT: " << tct_ << " Tasks: ";
    for (int i = 0; i < tasks_.size(); i++) {
      std::cout << tasks_[i] << " ";
    }
    std::cout << std::endl;
  }
 private:
  int tct_ = 0;
  std::vector<int> tasks_;
};