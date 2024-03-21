/**
 * @file DivideAndConquer.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la clase DivideAndConquer
 * @version 0.1
 * @date 2024-03-04
 * 
 */
#include <iostream>
#include <vector>

#include "problem.h"
#include "solution.h"

#pragma once

/**
 * @brief Clase DivideAndConquer
 * 
 * @tparam P 
 * @tparam S 
 */
template <class P, class S>
class DivideAndConquer {
 public:
  DivideAndConquer(int how_many = 2) { how_many_ = how_many; }
  /**
   * @brief Función Solve
   * 
   * @param problem 
   * @param length 
   * @param how_many 
   * @return Solution<S> 
   */
  Solution<S> Solve(const Problem<P>& problem, int length, int search = 0 ,int how_many = 2) {
    try {
      if (isSmall(problem, length, search)) {
        return makeSolution(problem, search);
      } else {
        std::vector<Problem<P>> subproblems;
        std::vector<Solution<S>> solutions;
        subproblems = divide(problem, length, search ,how_many);
        for (int i = 0; i < how_many; i++) {
          solutions.push_back(Solve(subproblems[i], subproblems[i].getProblem().size(), search ,how_many));
        }
        Solution<S> solution = combine(solutions);
        return solution;
      }
    } catch (const std::invalid_argument& e) {
      throw e;
    }
  }
  /**
   * @brief Get the algorithm recurrence object
   * 
   * @return std::string 
   */
  std::string get_algorithm_recurrence() {
    std::string algorithm_recursivity = get_recursivity();
    std::string algorithm_reduce_factor = get_factor();
    std::string algorithm_base_case = get_combine_complex();
    return "T(n) <= " + algorithm_recursivity + "T(" + algorithm_reduce_factor + ") + " + algorithm_base_case;
  }
  virtual bool isSmall(const Problem<P>&, int length, int search) = 0;
  virtual std::string get_recursivity() = 0;
  virtual std::string get_factor() = 0;
  virtual std::string get_combine_complex() = 0;
  virtual std::vector<Problem<P>> divide(const Problem<P>&, int length, int search = 0 ,int how_many = 2) = 0;
  virtual Solution<S> combine(const std::vector<Solution<S>>& solutions) = 0;
  virtual Solution<S> makeSolution(const Problem<P>& problem, int search = 0) = 0;
 protected:
  int how_many_;
};
