/**
 * @file MergeSort.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la clase MergeSort
 * @version 0.1
 * @date 2024-03-04
 * 
 */
#include <algorithm>
#include "DivideAndConquer.h"

#pragma once

/**
 * @brief Clase MergeSort
 * 
 * @tparam P 
 * @tparam S 
 */
template <class P, class S>
class MergeSort : public DivideAndConquer<P, S> {
 public:
  MergeSort(int how_many = 2) : DivideAndConquer<P, S>(how_many) {}

/**
 * @brief Función isSmall
 * 
 * @param problem 
 * @param length 
 * @return true 
 * @return false 
 */
  bool isSmall(const Problem<P>& problem, int length) override {
    return length <= 1;
  }

  /**
   * @brief Función divide
   * 
   * @param problem 
   * @param length 
   * @param how_many 
   * @return std::vector<Problem<P>> 
   */
  std::vector<Problem<P>> divide(const Problem<P>& problem, int length, int how_many) override {
    std::vector<Problem<P>> subproblems;
    for (int i = 0; i < how_many; i++) {
      Problem<P> subproblem;
      for (int j = i * length / how_many; j < (i + 1) * length / how_many; j++) {
        subproblem.push_back(problem[j]);
      }
      subproblems.push_back(subproblem);
    }
    return subproblems;
  }

  /**
   * @brief Función combine
   * 
   * @param solutions 
   * @return Solution<S> 
   */
  Solution<S> combine(const std::vector<Solution<S>>& solutions) override {
    Solution<S> combined;
    bool done = false;
    std::vector<int> indexes = std::vector<int>(solutions.size(), 0);
    int auxiliar = 10000;
    int actual_index = -1;
    while (!done) { // como mucho se ejecutará n veces (suma de los tamaños de los vectores de soluciones)
      done = true;
      for (int i = 0; i < solutions.size(); i++) {
        if (indexes[i] < solutions[i].size()) {
          if (solutions[i][indexes[i]] < auxiliar) {
            auxiliar = solutions[i][indexes[i]];
            if (actual_index != -1) {
              indexes[actual_index]--;
            }
            actual_index = i;
            indexes[i]++;
            done = false;
          }
        }
      }
      if (!done) {
        combined.push_back(auxiliar);
        auxiliar = 10000;
        actual_index = -1;
      }
    }
    return combined;
  }

/**
 * @brief Get the recursivity object
 * 
 * @return std::string 
 */
  std::string get_recursivity() override {
    return std::to_string(how_many_);
  }

  /**
   * @brief Get the factor object
   * 
   * @return std::string 
   */
  std::string get_factor() override {
    return "2";
  }

  /**
   * @brief Get the combine complex object
   * 
   * @return std::string 
   */
  std::string get_combine_complex() override {
    return "O(n)";
  }
 private:
  int how_many_;
};


