/**
 * @file BinSearch.h
 * @author Adrián Mora Rodríguez (alu0101465883@ull.edu.es)
 * @brief Implementación de la clase BinSearch
 * @version 0.1
 * @date 2024-03-04
 * 
 */

#include "DivideAndConquer.h"

#pragma once
template <class P, class S>
class BinSearch : public DivideAndConquer<P,S> { // Explicación para mi yo del futuro: el problema tiene tamaño m dónde m-1 es el final del vector actual respecto al vector original y m-2 es el inicio del vector actual respecto al vector original
 public:
  BinSearch(int how_many = 1) : DivideAndConquer<P, S>(how_many) {}
  
  bool isSmall(const Problem<P>& problem, int length, int search) override {
    int middle = (length - 2) / 2;
    return problem[(length - 2) / 2] == search || length <= 3;
  }
  
  std::vector<Problem<P>> divide(const Problem<P>& problem, int length, int search, int how_many) override {
    std::vector<Problem<P>> subproblems;
    Problem<P> subproblem;
    if (problem[(length - 2) / 2] > search) {
      for (int i = 0; i < (length - 2) / 2; i++) {
        subproblem.push_back(problem[i]);
      }
      subproblem.push_back(problem[(length - 2)]);
      subproblem.push_back((length - 2) / 2);
    } else {
      for (int i = (length - 2) / 2; i < (length - 2); i++) {
        subproblem.push_back(problem[i]);
      }
      subproblem.push_back((length - 2) / 2);
      subproblem.push_back(problem[length - 1]);
    }
    subproblems.push_back(subproblem);
    return subproblems;
  }

  Solution<S> makeSolution(const Problem<P>& problem, int search = 0) override {
    if (problem.size() == 3) {
      Solution<S> solution;
      if (problem[0] == search) {
        solution.setSolution({problem[1]});
      } else {
        solution.setSolution({-1});
      }
      return solution;
    }
    if (problem[(problem.size() - 2) / 2] == search) {
      Solution<S> solution;
      std::vector<int> sol;
      sol.push_back(problem[(problem.size() - 2)] + ((problem.size() - 2) / 2));
      solution.setSolution(sol);
      return solution;
    } else {
      Solution<S> solution;
      solution.setSolution({-1});
      return solution;
    }
  } 
  
  Solution<S> combine(const std::vector<Solution<S>>& solutions) override {
    Solution<S> combined;
    std::vector<int> solution;
    bool found = false;
    for (int i = 0; i < solutions.size(); i++) {
      if (solutions[i][0] != -1) {
        combined.push_back(solutions[i][0]);
        found = true;
        break;
      }
    }
    if (!found) {
      combined.setSolution({-1});
    }
    return combined;
  }
  
  /**
 * @brief Get the recursivity object
 * 
 * @return std::string 
 */
  std::string get_recursivity() override {
    return std::to_string(1);
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
    return "O(1)";
  }
};