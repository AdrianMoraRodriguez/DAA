#include <iostream>
#include <vector>
#include <string>

#include "machine.h"

#pragma once

class Solution {
 public:
  Solution() {}
  Solution(std::vector<Machine> machines, int total_tct) {
    machines_ = machines;
    total_tct_ = total_tct;
  }
  Solution(const Solution& solution) {
    machines_ = solution.get_machines();
    total_tct_ = solution.get_total_tct();
  }
  void set_machines(std::vector<Machine> machines) {
    machines_ = machines;
  }
  void set_total_tct(int total_tct) {
    total_tct_ = total_tct;
  }
  std::vector<Machine> get_machines() const {
    return machines_;
  }
  Machine get_machine(int i) {
    return machines_[i];
  }

  void set_machine(int i, Machine machine) {
    machines_[i] = machine;
    total_tct_ = 0;
    for (int i = 0; i < machines_.size(); i++) {
      total_tct_ += machines_[i].get_tct();
    }
  }

  void set_machine(int i, std::vector<int> tasks, int tct) {
    machines_[i].set_tasks(tasks, tct);
    total_tct_ = 0;
    for (int i = 0; i < machines_.size(); i++) {
      total_tct_ += machines_[i].get_tct();
    }
  }

  std::vector<int> get_tasks(int i) {
    return machines_[i].get_tasks();
  }

  int get_tct_of_machine(int i) {
    return machines_[i].get_tct();
  }

  int get_total_tct() const {
    return total_tct_;
  }
  void print() {
    std::cout << "Total TCT: " << total_tct_ << std::endl;
    for (int i = 0; i < machines_.size(); i++) {
      std::cout << "Machine " << i << ": ";
      machines_[i].print();
    }
  }
 private:
  std::vector<Machine> machines_;
  int total_tct_;
};